#include "regex.h"

/**
 * match_here - Vérifie si pattern correspond à str à partir de la position actuelle
 * @str: Chaîne à analyser
 * @pattern: Expression régulière
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
 * match_star - Gère le caractère * dans le pattern
 * @c: Caractère précédant *
 * @pattern: Reste du pattern après *
 * @str: Chaîne à analyser
 * Return: 1 si correspond, 0 sinon
 */
static int match_star(char c, char const *pattern, char const *str)
{
	do {
		if (match_here(str, pattern))
			return 1;
	} while (*str && (c == '.' || c == *str++) );

	return 0;
}

/**
 * regex_match - Vérifie si un pattern correspond à une chaîne
 * @str: Chaîne à analyser
 * @pattern: Expression régulière
 * Return: 1 si correspond, 0 sinon
 */
int regex_match(char const *str, char const *pattern)
{
	if (pattern[0] == '*')
		return 0;  /* Pattern invalide */

	return match_here(str, pattern);
}
