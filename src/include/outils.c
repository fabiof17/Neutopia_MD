#include <genesis.h>

#include "structures.h"
#include "variables.h"

#include "tables_DONJONS.h"
#include "tables_ENTREES.h"
#include "tables_MENU.h"
#include "tables_NIVEAUX.h"
#include "tables_OBJETS_DECOR.h"
#include "tables_SALLES.h"

#include "variables.h"

#include "maps_MENU.h"


//******************************************************//
//                                                      //
//                        GLOBALES                      //
//                                                      //
//******************************************************//


void init_POINTEURS_TABLES()
{
	if(num_NIVEAU == 0)
	{
		ptr_TABLE_ENTREES = TABLE_ENTREES_NIVEAU1;
		ptr_TABLE_ID_ENTREES = &TABLE_ID_ENTREES_NIVEAU1[0][0];
		ptr_TABLE_OBJETS_DECOR = &TABLE_OBJETS_DECOR_NIVEAU1[0][0];
		ptr_TABLE_SALLES = &TABLE_SALLES_NIVEAU1[0];
	}
	else if(num_NIVEAU == 1)
	{
		//ptr_TABLE_ENTREES = TABLE_ENTREES_NIVEAU2;
		//ptr_TABLE_ID_ENTREES = &TABLE_ID_ENTREES_NIVEAU2[0][0];
		//ptr_TABLE_OBJETS_DECOR = &TABLE_OBJETS_DECOR_NIVEAU2[0][0];
		//ptr_TABLE_SALLES = &TABLE_SALLES_NIVEAU2;
	}
	else if(num_NIVEAU == 2)
	{
		//ptr_TABLE_ENTREES = TABLE_ENTREES_NIVEAU3;
		//ptr_TABLE_ID_ENTREES = &TABLE_ID_ENTREES_NIVEAU3[0][0];
		//ptr_TABLE_OBJETS_DECOR = &TABLE_OBJETS_DECOR_NIVEAU3[0][0];
		//ptr_TABLE_SALLES = &TABLE_SALLES_NIVEAU3;
	}		
	else if(num_NIVEAU == 3)
	{
		//ptr_TABLE_ENTREES = TABLE_ENTREES_NIVEAU4;
		//ptr_TABLE_ID_ENTREES = &TABLE_ID_ENTREES_NIVEAU4[0][0];
		//ptr_TABLE_OBJETS_DECOR = &TABLE_OBJETS_DECOR_NIVEAU4[0][0];
		//ptr_TABLE_SALLES = &TABLE_SALLES_NIVEAU4;
	}

	ptr_TABLE_EAU = TABLE_ADR_EAU_NIVEAUX[num_NIVEAU][0];
	ptr_TABLE_CASCADE = TABLE_ADR_CASCADE_NIVEAUX[num_NIVEAU][0];	
}


void maj_ENERGIE()
{
	u8 i = 0;

	u8 entier = nb_ENERGIE >>1;
	
	
	for(i=0 ; i< entier ; i++)
	{
		VDP_setTileMapEx(WINDOW , image_ENERGIE_PLEIN.tilemap, TILE_ATTR_FULL(PAL0, TRUE, FALSE, FALSE, adr_VRAM_ENERGIE_PLEIN), 13 + i, 3, 0, 0, 1, 1, CPU);
	}

	if(nb_ENERGIE %2 != 0)
	{
		VDP_setTileMapEx(WINDOW , image_ENERGIE_MOITIE.tilemap, TILE_ATTR_FULL(PAL0, TRUE, FALSE, FALSE, adr_VRAM_ENERGIE_MOITIE), 13 + entier, 3, 0, 0, 1, 1, CPU);
	}
}


void VDP_drawInt(u16 valeur,u8 zeros,s16 x, s16 y)
{
	intToStr(valeur,texteSortie,zeros); //MIN -500.000.000 - MAX 500.000.000
	VDP_drawTextBG(WINDOW,texteSortie,x,y);
}


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


void effacer_ENERGIE()
{
	u8 i = 0;

	for(i=0 ; i<energie_MAX ; i++)
	{
		VDP_setTileMapEx(WINDOW, image_ENERGIE_VIDE.tilemap, TILE_ATTR_FULL(PAL0, TRUE, FALSE, FALSE, adr_VRAM_ENERGIE_VIDE), 13 + i, 3, 0, 0, 1, 1, CPU);
	}	
}




void maj_SCORE(u16 nombre , u8 nb_TILES , u16 pos_X , u16 pos_Y)
{
	//effacer gold
	effacer_SCORE(nb_TILES , pos_X , pos_Y);

	u8 i = 0;
	u8 digit = 0;

	if(nombre == 0)
	{
		VDP_setTileMapEx(WINDOW , image_ENERGIE_VIDE.tilemap, TILE_ATTR_FULL(PAL0, TRUE, FALSE, FALSE, adr_VRAM_CHIFFRES), pos_X - i , pos_Y, 0, 0, 1, 1, CPU);
		return;
	}

	// afficher gold
	while(nombre > 0)
	{
		digit = nombre % 10;
		VDP_setTileMapEx(WINDOW , image_ENERGIE_VIDE.tilemap, TILE_ATTR_FULL(PAL0, TRUE, FALSE, FALSE, adr_VRAM_CHIFFRES + digit), pos_X - i , pos_Y, 0, 0, 1, 1, CPU);
		i ++;
		nombre /= 10;
	}
}






s16 aligner_JOUEUR(u16 x)
{
	s16 reste = x % 8; // retourne un nommbre entre 0 et 7
	s16 milieu	= 4;		// 7/2 = 3.5 = 3
	s16 resultat = 0;

	//VDP_drawInt( reste , 1 , 0 , 0 );

	if(reste !=0)
	{
		if(reste < milieu)
		{
			resultat = -1;
		}

		else if(reste > milieu)
		{
			resultat = 1;
		}
	}

	else
	{
		resultat = reste;
	}

	return resultat;
}