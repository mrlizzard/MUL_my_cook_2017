/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** cook functions (header file)
*/

# ifndef COOK_H
# define COOK_H

# include <SFML/Graphics.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

# include "my.h"

typedef enum state_e {
		gameWait,
		gameRun,
		gameEnd,
		gamePause
}		state_e;

typedef enum btnType_e {
		btnPlay,
		btnPause,
		btnCredits,
		btnQuit,
		btnOptions
} 		btnType_e;

typedef struct pos_t {
		int 			start;
		int 			heigth;
		int 			width;
} 		pos_t;

typedef struct button_t {
		btnType_e 		type;
		pos_t 			pos;
		void 			(*callback)(struct cook_t);
		button_t 		*next;
} 		button_t;

typedef struct texture_t {
		int 			id;
		sfTexture 		*texture;
		sfSprite 		*sp;
} 		texture_t;

typedef struct assets_t {
		assets_t 		*prev;
		sfTexture 		*texture;
		sfSprite 		*sp;
		assets_t 		*next;
} 		assets_t;

typedef struct cook_t {
		sfRenderWindow	*win;
		state_e 		state;
		assets_t 		*assets;
		button_t 		*btn;
}		cook_t;

// cook.c
void 	exit_game(cook_t *cook);
int		cook_game(cook_t *cook);
int 	cook_main(int ac, char **av);

// utilities/args_handling.c
int 	check_arguments(int ac, char **av);

// utilities/struct_utils.c
int 	new_asset(cook_t *cook, texture_t texture);
void 	destroy_assets(cook_t *cook);
cook_t 	*configure_struct(void);

// events/event_manager.c
void 	poll_event(cook_t *cook, sfEvent *event);

// assets/assets_manager.c
int 	load_assets(cook_t *cook);

# endif