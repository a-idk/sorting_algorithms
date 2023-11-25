#ifndef _DECK_H
#define _DECK_H

/* Standard libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Provided Data Structure */
/**
 * enum kind_e - shape of card
 * @SPADE: spade shape
 * @HEART: heart shape
 * @CLUB: club shape
 * @DIAMOND: shape of diamond
 */

typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Playing card
 *
 * @value: Value of the card
 * From "Ace" to "King"
 * @kind: Kind of the card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Deck of card
 *
 * @card: Pointer to the card of the node
 * @prev: Pointer to the previous node of the list
 * @next: Pointer to the next node of the list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

/* Prototypes */
int str_cmp(const char *str1, const char *str2);
void sort_shape(deck_node_t **deck);
char card_num(deck_node_t *card);
void sort_value(deck_node_t **deck);
void sort_deck(deck_node_t **deck);

#endif /* "deck.h" */
