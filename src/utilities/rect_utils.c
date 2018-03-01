/*
** EPITECH PROJECT, 2018
** my_cook_2017
** File description:
** rect_utils functions
*/

# include "cook.h"

void reset_sliders_rect(cook_t *cook)
{
	slider_t *tmp = cook->slides;
	sfSprite *sprite = NULL;
	sfIntRect rec;

	while (tmp->next != NULL) {
		if (tmp->next->state == cook->state) {
			sprite = tmp->next->sprite;
			rec = tmp->next->normal_rect;
			sfSprite_setTextureRect(sprite, rec);
		}
		tmp = tmp->next;
	}
}

void reset_to_normal_rect(cook_t *cook)
{
	button_t *tmp = cook->btn;
	sfSprite *sprite = NULL;
	sfIntRect rec;

	while (tmp->next != NULL) {
		if (tmp->next->state == cook->state) {
			sprite = tmp->next->sprite;
			rec = tmp->next->normal_rect;
			sfSprite_setTextureRect(sprite, rec);
		}
		tmp = tmp->next;
	}

	reset_sliders_rect(cook);
}
