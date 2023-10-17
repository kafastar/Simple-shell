#include "shell.h"

/**
 * _strlen - Calculate the length of a string.
 * @s: The string to measure.
 * Return: Length of string.
 */
int _strlen(const char *s)
{
	int length = 0;

	while (s[length])
		length++;
	return (length);
}

/**
 * _strcpy - Copy one string to another.
 * @dest: Destination string.
 * @src: Source string.
 * Return: Pointer to the destination string.
 */
char *_strcpy(char *dest, const char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcmp - Compare two strings.
 * @s1: First string.
 * @s2: Second string.
 * Return: Difference between s1 and s2.
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

/**
 * _strcat - Concatenate two strings.
 * @dest: Destination string.
 * @src: Source string.
 * Return: Pointer to the destination string.
 */
char *_strcat(char *dest, const char *src)
{
	int dest_len = _strlen(dest);
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[dest_len + i] = src[i];
	dest[dest_len + i] = '\0';

	return (dest);
}

/**
 * _strdup - Duplicate a string.
 * @str: String to duplicate.
 * Return: Pointer to the duplicated string or NULL if memory allocation fails.
 */
char *_strdup(const char *str)
{
	char *duplicate;
	int i, len = _strlen(str);

	duplicate = malloc((len + 1) * sizeof(char));
	if (duplicate == NULL)
		return (NULL);

	for (i = 0; str[i]; i++)
		duplicate[i] = str[i];
	duplicate[i] = '\0';

	return (duplicate);
}
