/* Title: sort_deck.c */
#include "deck.h"

/**
 * str_cmp - function that does string comparisons
 * @str1: first string
 * @str2: second string
 * @a_idk scripting
 *
 * Return: 0 on success (Always!), else diff (str1 - str2)
 */

int str_cmp(const char *str1, const char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
		str1 = str1 + 1, str2 = str2 + 1;

	if (*str1 != *str2)
		return (*str1 - *str2);

	return (0);
}



/**
 * sort_shape - function that sort shape "spades, heart, club, and diamonds"
 * @deck: deck linked list pointer
 * @a_idk scripting
 *
 * Return: NADA!
 */

void sort_shape(deck_node_t **deck)
{
	/* declaring variable */
	deck_node_t *shuffle;
	deck_node_t *fix;
	deck_node_t *temp;

	for (shuffle = (*deck)->next; shuffle != NULL; shuffle = temp)
	{
		temp = shuffle->next, fix = shuffle->prev;
		while (fix != NULL && fix->card->kind > shuffle->card->kind)
		{
			fix->next = shuffle->next;
			if (shuffle->next != NULL)
				shuffle->next->prev = fix;
			shuffle->prev = fix->prev, shuffle->next = fix;
			if (fix->prev != NULL)
				fix->prev->next = shuffle;
			else
				*deck = shuffle;
			fix->prev = shuffle, fix = shuffle->prev;
		}
	}
}



/**
 * card_num - Get the numerical value of a card.
 * @card: card pointer
 * @a_idk scripting
 *
 * Return: corresponding Card number
 */

char card_num(deck_node_t *card)
{
	/* declaring variables*/
	int index;
	const char *val;

	const char *cd_values[14] = {
		"King", "Queen", "Jack", "10", "9", "8", "7", "6", "5",
		"4", "3", "2", "1", "Ace"
	};

	val = card->card->value;
	for (index = 13; index >= 0; index -= 1)
	{
		if (str_cmp(val, cd_values[index]) == 0)
			return (index);
	}
	return (-1);
}



/**
 * sort_value - function that sorts from spade to diamonds & ace to king
 * @deck: deck linked list pointer
 * @a_idk scripting
 *
 * Return: NADA!
 */

void sort_value(deck_node_t **deck)
{
	/* declaring variable */
	deck_node_t *shuffle;
	deck_node_t *fix;
	deck_node_t *temp;

	for (shuffle = (*deck)->next; shuffle != NULL; shuffle = temp)
	{
		temp = shuffle->next, fix = shuffle->prev;
		while (fix != NULL &&
		       fix->card->kind == shuffle->card->kind &&
		       card_num(fix) > card_num(shuffle))
		{
			fix->next = shuffle->next;
			if (shuffle->next != NULL)
				shuffle->next->prev = fix;
			shuffle->prev = fix->prev, shuffle->next = fix;
			if (fix->prev != NULL)
				fix->prev->next = shuffle;
			else
				*deck = shuffle;
			fix->prev = shuffle, fix = shuffle->prev;
		}
	}
}

/**
 * sort_deck - function that calls for shape and value sorting
 * @deck: deck linked list pointer
 * @a_idk scripting
 *
 * Return: NADA!
 */

void sort_deck(deck_node_t **deck)
{
	/* checking for NULL value */
	if (*deck == NULL || (*deck)->next == NULL || deck == NULL)
	{
		return;
	}
	sort_shape(deck), sort_value(deck);
}
