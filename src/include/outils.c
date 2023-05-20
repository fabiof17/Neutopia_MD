#include <genesis.h>

#include "variables.h"

#include "maps_MENU.h"


//******************************************************//
//                                                      //
//                        GLOBALES                      //
//                                                      //
//******************************************************//

int calcul_DIGITS(u16 nombre)
{
	u8 nb_digits = 0;

	// calcul nombre de digits
	while(nombre >0)
	{
		nb_digits ++;
		nombre /= 10;
	}

	return nb_digits;

}

void effacer_SCORE(u8 nb_TILES , u16 pos_X , u16 pos_Y)
{
	u8 i = 0;

	//effacer score
	for(i=0 ; i<nb_TILES ; i++)
	{
		VDP_setTileMapEx(WINDOW , image_ENERGIE_VIDE.tilemap, TILE_ATTR_FULL(PAL0, TRUE, FALSE, FALSE, 1), pos_X - i, pos_Y, 0, 0, 1, 1, CPU);
	}
}

void maj_SCORE(u16 nombre , u8 nb_TILES , u16 pos_X , u16 pos_Y)
{
	//effacer gold
	effacer_SCORE(nb_TILES , pos_X , pos_Y);

	u8 i = 0;
	u8 digit = 0;
	
	// afficher gold
	while(nombre > 0)
	{
		digit = nombre % 10;
		VDP_setTileMapEx(WINDOW , image_ENERGIE_VIDE.tilemap, TILE_ATTR_FULL(PAL0, TRUE, FALSE, FALSE, adr_VRAM_CHIFFRES + digit), pos_X - i , pos_Y, 0, 0, 1, 1, CPU);
		i ++;
		nombre /= 10;
	}
}
