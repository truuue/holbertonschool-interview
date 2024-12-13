#include "regex.h"

static int match_star(char c, char const *pattern, char const *str);

/**
 * match_here - Verifie si pattern correspond à str
 * @str: Chaine a analyser
 * @pattern: Expression reguliere
 * Return: 1 si correspond, 0 sinon
 */
static int match_here(char const *str, char const *pattern)
{
	if (!*pattern)
		return (!*str);

	if (pattern[1] == '*')
	{
		return match_star(pattern[0], pattern + 2, str);
	}

	if (*str && (pattern[0] == '.' || pattern[0] == *str))
		return match_here(str + 1, pattern + 1);

	return 0;
}

/**
 * match_star - Gere le caractere * dans le pattern
 * @c: Caractere precede par *
 * @pattern: Reste du pattern apres *
 * @str: Chaine a analyser
 * Return: 1 si correspond, 0 sinon
 */
static int match_star(char c, char const *pattern, char const *str)
{
	if (match_here(str, pattern))
		return 1;

	while (*str && (c == '.' || c == *str))
	{
		str++;
		if (match_here(str, pattern))
			return 1;
	}

	return 0;
}

/**
 * regex_match - Verifie si un pattern correspond à une chaine
 * @str: Chaine a analyser
 * @pattern: Expression reguliere
 * Return: 1 si correspond, 0 sinon
 */
int regex_match(char const *str, char const *pattern)
{
	if (pattern[0] == '*')
		return 0;  /* Pattern invalide */

	return match_here(str, pattern);
}
