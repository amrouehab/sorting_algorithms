#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deck.h"

/**
 * card_value - Converts card value to an integer for comparison
 * @value: The value of the card
 * Return: The integer value of the card
 */
int card_value(const char *value)
{
    if (strcmp(value, "Ace") == 0) return 1;
    if (strcmp(value, "2") == 0) return 2;
    if (strcmp(value, "3") == 0) return 3;
    if (strcmp(value, "4") == 0) return 4;
    if (strcmp(value, "5") == 0) return 5;
    if (strcmp(value, "6") == 0) return 6;
    if (strcmp(value, "7") == 0) return 7;
    if (strcmp(value, "8") == 0) return 8;
    if (strcmp(value, "9") == 0) return 9;
    if (strcmp(value, "10") == 0) return 10;
    if (strcmp(value, "Jack") == 0) return 11;
    if (strcmp(value, "Queen") == 0) return 12;
    if (strcmp(value, "King") == 0) return 13;
    return 0;
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @deck: Pointer to the head of the deck
 * @node1: First node to swap
 * @node2: Second node to swap
 */
void swap_nodes(deck_node_t **deck, deck_node_t *node1, deck_node_t *node2)
{
    if (node1->prev)
        node1->prev->next = node2;
    if (node2->next)
        node2->next->prev = node1;

    node1->next = node2->next;
    node2->prev = node1->prev;

    node1->prev = node2;
    node2->next = node1;

    if (*deck == node1)
        *deck = node2;
}

/**
 * sort_deck - Sorts a deck of cards
 * @deck: Pointer to the head of the deck
 */
void sort_deck(deck_node_t **deck)
{
    deck_node_t *current, *next;

    if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
        return;

    current = *deck;
    while (current)
    {
        next = current->next;
        while (next)
        {
            if (current->card->kind > next->card->kind ||
                (current->card->kind == next->card->kind &&
                 card_value(current->card->value) > card_value(next->card->value)))
            {
                swap_nodes(deck, current, next);
                next = current->next;
            }
            else
            {
                next = next->next;
            }
        }
        current = current->next;
    }
}
