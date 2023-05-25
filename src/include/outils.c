#include <genesis.h>

#include "variables.h"

#include "tables_DONJONS.h"
#include "tables_ENTREES.h"
#include "tables_MENU.h"
#include "tables_NIVEAUX.h"
#include "tables_SALLES.h"

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


u16 maj_ID_TILE(const TileMap *maTilemap , s16 x , s16 y)
{
	u16 index_TILE = TABLE_OFFSET_TILE_NIVEAUX[1][index_Y_CARTE_NIVEAU] + TABLE_OFFSET_TILE_NIVEAUX[0][index_X_CARTE_NIVEAU] + ((y >> 3) * 24) + (x >> 3);

	u16 id_TILE = maTilemap->tilemap[index_TILE]&TILE_INDEX_MASK;

	return id_TILE;
}
