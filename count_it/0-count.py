#!/usr/bin/python3
"""Count it module"""
from requests import get


def count_words(subreddit, word_list, after='', count={}):
    """Count words"""

    response = get("https://www.reddit.com/r/{}/hot.json".format(subreddit),
                   headers={'user-agent': 'my-app/0.0.1'},
                   params={'limit': '100', 'after': after},
                   allow_redirects=False)

    if response.status_code != 200:
        return

    resp = response.json().get('data')

    for child in resp.get('children'):
        title = child.get('data').get('title')

        for word in word_list:
            oc_number = title.lower().split().count(word.lower())

            if oc_number > 0:
                if word not in count:
                    count[word] = oc_number
                else:
                    count[word] += oc_number

    if resp.get('after') is None:
        if not len(count) > 0:
            return

        for k, v in sorted(count.items(),
                           key=lambda kv: (-kv[1], kv[0])):
            print('{}: {}'.format(k.lower(), v))
    else:
        return count_words(subreddit, word_list, resp.get('after'), count)
