#include <genesis.h>

#include "variables.h"
#include "tableaux.h"
#include "outils.h"

#include "sprites_JEU.h"
#include "sprites_MENU.h"

#include "maps_GLOBAL.h"
#include "maps_TITRE.h"
#include "maps_MENU.h"
#include "maps_NIVEAUX.h"
#include "maps_SALLES.h"

#include "palettes.h"


//******************************************************//
//                                                      //
//                        SYSTEME                       //
//                                                      //
//******************************************************//

void init_SYSTEME()
{  
    PAL_setColors(0, (u16*) palette_black, 64, CPU);
	
	VDP_setScreenWidth256();
    VDP_setScreenHeight224();

	VDP_setPlaneSize(64, 64, TRUE);

	VDP_setScrollingMode(HSCROLL_PLANE, VSCROLL_PLANE);
}


void init_VARIABLES_GENERALES()
{

	//******************************************************//
	//                                                      //
	//                        GLOBALES                      //
	//                                                      //
	//******************************************************//

	scene_JEU = 2;				// 0: TITRE  -  1: INTRO  -  2: JEU
	etat_JEU = 0;

	type_DECOR = 0;

	PAUSE = 0;
	GAMEOVER = 0;

	nb_BOMBES = 10;
	nb_GOLD = 20;

	niveau_EPEE = 0;
	niveau_BOUCLIER = 0;

	id_TILE = 0;

	map_BG_A_OK = 0;


	//******************************************************//
	//                                                      //
	//                         TITRE                        //
	//                                                      //
	//******************************************************//

	titre_OK = 0;
	phase_TITRE = 0;


	//******************************************************//
	//                                                      //
	//                         INTRO                        //
	//                                                      //
	//******************************************************//

	intro_OK = 0;


	//******************************************************//
	//                                                      //
	//                         MENU                         //
	//                                                      //
	//******************************************************//

	menu_OK = 0;

	index_X_MENU = 0;
	index_Y_MENU = 0;

	pos_X_CURSEUR = -24;
	pos_Y_CURSEUR = -24;

	index_X_CARTE_MENU = 0;
	index_Y_CARTE_MENU = 0;

	cle_OK = 0;
	crystal_OK = 0;

	adr_VRAM_MENU = 0;
	adr_VRAM_BOUSSOLE = 0;

	adr_VRAM_ENERGIE_PLEIN = 0;
	adr_VRAM_ENERGIE_MOITIE = 0;
	adr_VRAM_ENERGIE_VIDE = 0;

	adr_VRAM_VIDE = 0;
	adr_VRAM_AILES = 0;
	adr_VRAM_ANNEAU = 0;
	adr_VRAM_ARMURE = 0;
	adr_VRAM_BOMBE = 0;
	adr_VRAM_BOTTES = 0;
	adr_VRAM_BOUCLIER = 0;
	adr_VRAM_CLE = 0;
	adr_VRAM_CLOCHE = 0;
	adr_VRAM_CRYSTAL = 0;
	adr_VRAM_EPEE = 0;
	adr_VRAM_FIOLE = 0;
	adr_VRAM_GOUTTE = 0;
	adr_VRAM_LIVRE = 0;
	adr_VRAM_POTION = 0;
	adr_VRAM_SCEPTRE = 0;

	adr_VRAM_CHIFFRES = 0;

	nb_ENERGIE = 5;


	//////////////////////////////////////////////////////////
    //                      OBJETS HAUT                     //
    //////////////////////////////////////////////////////////

	TABLE_OBJETS_HAUT[0][0] = 1;
	TABLE_OBJETS_HAUT[0][1] = 1;
	TABLE_OBJETS_HAUT[0][2] = 1;
	TABLE_OBJETS_HAUT[0][3] = 1;

	TABLE_OBJETS_HAUT[1][0] = 1;
	TABLE_OBJETS_HAUT[1][1] = 1;
	TABLE_OBJETS_HAUT[1][2] = 1;
	TABLE_OBJETS_HAUT[1][3] = 1;


	//////////////////////////////////////////////////////////
    //                       OBJETS BAS                     //
    //////////////////////////////////////////////////////////

	TABLE_OBJETS_BAS[0][0] = 1;
	TABLE_OBJETS_BAS[0][1] = 1;
	TABLE_OBJETS_BAS[0][2] = 1;
	TABLE_OBJETS_BAS[0][3] = 1;
	TABLE_OBJETS_BAS[1][0] = 1;
	TABLE_OBJETS_BAS[1][1] = 1;


	//******************************************************//
	//                                                      //
	//                        NIVEAUX                       //
	//                                                      //
	//******************************************************//

	niveau_OK = 0;
	num_NIVEAU = 1;

	index_X_CARTE_NIVEAU = TABLE_INIT_INDEX_NIVEAUX[0][num_NIVEAU - 1];
	index_Y_CARTE_NIVEAU = TABLE_INIT_INDEX_NIVEAUX[1][num_NIVEAU - 1];

	adr_VRAM_BG_A = 0;
	adr_VRAM_BG_B = 0;


	//******************************************************//
	//                                                      //
	//                        DONJONS                       //
	//                                                      //
	//******************************************************//
	/*
	pos_X_CAM_DONJON = TABLE_INIT_CAM_DONJONS[0][num_NIVEAU - 1];
	pos_Y_CAM_DONJON = TABLE_INIT_CAM_DONJONS[1][num_NIVEAU - 1] - 40;

	index_X_CARTE_DONJONS = TABLE_INIT_INDEX_DONJONS[0][num_NIVEAU - 1];
	index_X_CARTE_DONJONS = TABLE_INIT_INDEX_DONJONS[1][num_NIVEAU - 1];
	*/



	//******************************************************//
	//                                                      //
	//                         SALLES                       //
	//                                                      //
	//******************************************************//

}


void init_PALETTES_MENU()
{
	PAL_setPalette(PAL0, palette_MENU.data, DMA);
	PAL_setPalette(PAL3, palette_OBJETS_VIOLET.data, DMA);
}


//******************************************************//
//                                                      //
//                        TITRE                         //
//                                                      //
//******************************************************//

void init_TITRE()
{
	//PAL_setColors(0, (u16*) palette_black, 64, CPU);

	//VDP_setScrollingMode(HSCROLL_PLANE, VSCROLL_PLANE);

	







	titre_OK = 1;
}




//******************************************************//
//                                                      //
//                        INTRO                         //
//                                                      //
//******************************************************//

void init_INTRO()
{
	intro_OK = 1;
}


void anim_INTRO()
{
	//
}


void boucle_INTRO()
{
	//
}




//******************************************************//
//                                                      //
//                         MENU                         //
//                                                      //
//******************************************************//

void init_MENU()
{
	u16 ind = TILE_USER_INDEX;


	//******************************************************//
	//                                                      //
	//                        BG_A                          //
	//                                                      //
	//******************************************************//

	adr_VRAM_MENU = ind;

    VDP_loadTileSet(image_MENU.tileset, ind, DMA);

    ind += image_MENU.tileset->numTile;

    SYS_doVBlankProcess();


	//******************************************************//
	//                                                      //
	//                      BOUSSOLE                        //
	//                                                      //
	//******************************************************//

	adr_VRAM_BOUSSOLE = ind;

	VDP_loadTileSet(image_BOUSSOLE.tileset, ind, DMA);

	ind += image_BOUSSOLE.tileset->numTile;

	SYS_doVBlankProcess();


	//******************************************************//
	//                                                      //
	//                       ENERGIE                        //
	//                                                      //
	//******************************************************//

	adr_VRAM_ENERGIE_PLEIN = ind;
	VDP_loadTileSet(image_ENERGIE_PLEIN.tileset, ind, DMA);
	ind += image_ENERGIE_PLEIN.tileset->numTile;

	adr_VRAM_ENERGIE_MOITIE = ind;
	VDP_loadTileSet(image_ENERGIE_MOITIE.tileset, ind, DMA);
	ind += image_ENERGIE_MOITIE.tileset->numTile;

	adr_VRAM_ENERGIE_VIDE = ind;
	VDP_loadTileSet(image_ENERGIE_VIDE.tileset, ind, DMA);
	ind += image_ENERGIE_VIDE.tileset->numTile;


	//******************************************************//
	//                                                      //
	//                       OBJETS                         //
	//                                                      //
	//******************************************************//

	adr_VRAM_VIDE = ind;
	VDP_loadTileSet(image_VIDE.tileset, ind, DMA);
	ind += image_VIDE.tileset->numTile;

	adr_VRAM_AILES = ind;
	VDP_loadTileSet(image_AILES.tileset, ind, DMA);
	ind += image_AILES.tileset->numTile;

	adr_VRAM_ANNEAU = ind;
	VDP_loadTileSet(image_ANNEAU.tileset, ind, DMA);
	ind += image_ANNEAU.tileset->numTile;

	adr_VRAM_ARMURE = ind;
	VDP_loadTileSet(image_ARMURE_GRISE.tileset, ind, DMA);
	ind += image_ARMURE_GRISE.tileset->numTile;

	adr_VRAM_BOMBE = ind;
	VDP_loadTileSet(image_BOMBE.tileset, ind, DMA);
	ind += image_BOMBE.tileset->numTile;

	adr_VRAM_BOTTES = ind;
	VDP_loadTileSet(image_BOTTES.tileset, ind, DMA);
	ind += image_BOTTES.tileset->numTile;

	adr_VRAM_BOUCLIER = ind;
	VDP_loadTileSet(image_BOUCLIER_JAUNE.tileset, ind, DMA);
	ind += image_BOUCLIER_JAUNE.tileset->numTile;

	adr_VRAM_CLE = ind;
	VDP_loadTileSet(image_CLE.tileset, ind, DMA);
	ind += image_CLE.tileset->numTile;

	adr_VRAM_CLOCHE = ind;
	VDP_loadTileSet(image_CLOCHE.tileset, ind, DMA);
	ind += image_CLOCHE.tileset->numTile;

	adr_VRAM_CRYSTAL = ind;
	VDP_loadTileSet(image_CRYSTAL.tileset, ind, DMA);
	ind += image_CRYSTAL.tileset->numTile;

	adr_VRAM_EPEE = ind;
	VDP_loadTileSet(image_EPEE_JAUNE.tileset, ind, DMA);
	ind += image_EPEE_JAUNE.tileset->numTile;

	adr_VRAM_FIOLE = ind;
	VDP_loadTileSet(image_FIOLE_VIOLETTE.tileset, ind, DMA);
	ind += image_FIOLE_VIOLETTE.tileset->numTile;

	adr_VRAM_GOUTTE = ind;
	VDP_loadTileSet(image_GOUTTE.tileset, ind, DMA);
	ind += image_GOUTTE.tileset->numTile;

	adr_VRAM_LIVRE = ind;
	VDP_loadTileSet(image_LIVRE.tileset, ind, DMA);
	ind += image_LIVRE.tileset->numTile;

	adr_VRAM_POTION = ind;
	VDP_loadTileSet(image_POTION_JAUNE.tileset, ind, DMA);
	ind += image_POTION_JAUNE.tileset->numTile;

	adr_VRAM_SCEPTRE = ind;
	VDP_loadTileSet(image_SCEPTRE.tileset, ind, DMA);
	ind += image_SCEPTRE.tileset->numTile;

	adr_VRAM_BG_B = ind;


	TABLE_ADR_VRAM_OBJETS_HAUT[0][0] = adr_VRAM_BOMBE;
	TABLE_ADR_VRAM_OBJETS_HAUT[0][1] = adr_VRAM_FIOLE;
	TABLE_ADR_VRAM_OBJETS_HAUT[0][2] = adr_VRAM_SCEPTRE;
	TABLE_ADR_VRAM_OBJETS_HAUT[0][3] = adr_VRAM_CLOCHE;

	TABLE_ADR_VRAM_OBJETS_HAUT[1][0] = adr_VRAM_AILES;
	TABLE_ADR_VRAM_OBJETS_HAUT[1][1] = adr_VRAM_POTION;
	TABLE_ADR_VRAM_OBJETS_HAUT[1][2] = adr_VRAM_ANNEAU;
	TABLE_ADR_VRAM_OBJETS_HAUT[1][3] = adr_VRAM_VIDE;

	TABLE_ADR_VRAM_OBJETS_BAS[0][0] = adr_VRAM_EPEE;
	TABLE_ADR_VRAM_OBJETS_BAS[0][1] = adr_VRAM_ARMURE;
	TABLE_ADR_VRAM_OBJETS_BAS[0][2] = adr_VRAM_BOUCLIER;
	TABLE_ADR_VRAM_OBJETS_BAS[0][3] = adr_VRAM_BOTTES;

	TABLE_ADR_VRAM_OBJETS_BAS[1][0] = adr_VRAM_GOUTTE;
	TABLE_ADR_VRAM_OBJETS_BAS[1][1] = adr_VRAM_LIVRE;
	TABLE_ADR_VRAM_OBJETS_BAS[1][2] = adr_VRAM_VIDE;
	TABLE_ADR_VRAM_OBJETS_BAS[1][3] = adr_VRAM_VIDE;

	SYS_doVBlankProcess();


	//******************************************************//
	//                                                      //
	//                        TYPO                          //
	//                                                      //
	//******************************************************//

	adr_VRAM_CHIFFRES = TILE_FONT_INDEX + 16;

	VDP_loadTileSet(image_CHIFFRES_GLOBAL.tileset, adr_VRAM_CHIFFRES, DMA);


	//******************************************************//
	//                                                      //
	//                      SPRITES                         //
	//                                                      //
	//******************************************************//

	SPR_init ();

	sprite_CURSEUR = SPR_addSprite(&tiles_SPR_CURSEUR, pos_X_CURSEUR, pos_Y_CURSEUR, TILE_ATTR(PAL0, TRUE, FALSE, FALSE));

	SPR_update();

	SYS_doVBlankProcess();

}


void init_WINDOW()
{
	//******************************************************//
	//                                                      //
	//                       WINDOW                         //
	//                                                      //
	//******************************************************//
	
	u16 ind = TILE_USER_INDEX;

	VDP_setWindowHPos(0, 0);
    VDP_setWindowVPos(0, 5);

	VDP_setTileMapEx(WINDOW, image_MENU.tilemap, TILE_ATTR_FULL(PAL0, TRUE, FALSE, FALSE, ind), 0, 0, 0, 0, 32, 5, CPU);

	VDP_setTileMapEx(WINDOW, image_OBJET.tilemap, TILE_ATTR_FULL(PAL0, TRUE, FALSE, FALSE, adr_VRAM_EPEE), 6, 2, 0, 0, 2, 2, CPU);

	SYS_doVBlankProcess();


	//******************************************************//
	//                                                      //
	//                       ENERGIE                        //
	//                                                      //
	//******************************************************//

	u8 i = 0;

	for(i=0 ; i<nb_ENERGIE ; i++)
	{
		VDP_setTileMapEx(WINDOW, image_ENERGIE_PLEIN.tilemap, TILE_ATTR_FULL(PAL0, TRUE, FALSE, FALSE, adr_VRAM_ENERGIE_PLEIN), 13 + i, 3, 0, 0, 1, 1, CPU);
	}


	//******************************************************//
	//                                                      //
	//                     GOLD + BOMBES                    //
	//                                                      //
	//******************************************************//
	maj_SCORE(nb_GOLD , 4 , 17 , 2);
	maj_SCORE(nb_BOMBES , 2 , 24 , 2);

	SYS_doVBlankProcess();

}




//******************************************************//
//                                                      //
//                       NIVEAUX                        //
//                                                      //
//******************************************************//

void init_DECOR( u8 index , u8 type )
{
	index -= 1;

	//////////////////////////////////////////////////////////
    //                        NIVEAU                        //
    //////////////////////////////////////////////////////////
	if(type == 0)
	{

		//////////////////////////////////////////////////////////
		//                CHARGEMENT TILES BG_B                 //
		//////////////////////////////////////////////////////////
		VDP_loadTileSet(TABLE_TILESET_NIVEAUX[0][index], adr_VRAM_BG_B, CPU);
		adr_VRAM_BG_A = adr_VRAM_BG_B + TABLE_TILESET_NIVEAUX[0][index]->numTile;
		SYS_doVBlankProcess();

		//////////////////////////////////////////////////////////
		//                  CREATION MAP BG_B                   //
		//////////////////////////////////////////////////////////
		map_NIVEAU_BG_B = MAP_create(TABLE_MAPDEF_NIVEAUX[0][index], BG_B, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, adr_VRAM_BG_B));
		//map_BG_B_OK = 1;
		SYS_doVBlankProcess();




		//////////////////////////////////////////////////////////
		//                CHARGEMENT TILES BG_A                 //
		//////////////////////////////////////////////////////////
		VDP_loadTileSet(TABLE_TILESET_NIVEAUX[1][index], adr_VRAM_BG_A, CPU);
		SYS_doVBlankProcess();
		
		//////////////////////////////////////////////////////////
		//                  CREATION MAP BG_A                   //
		//////////////////////////////////////////////////////////
		map_NIVEAU_BG_A = MAP_create(TABLE_MAPDEF_NIVEAUX[1][index], BG_A, TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, adr_VRAM_BG_A));
		map_BG_A_OK = 1;
		SYS_doVBlankProcess();




		//////////////////////////////////////////////////////////
		//                     INIT CAMERA                      //
		//////////////////////////////////////////////////////////
		pos_X_CAM_NIVEAU = TABLE_INIT_CAM_NIVEAUX[0][num_NIVEAU - 1];
		pos_Y_CAM_NIVEAU = TABLE_INIT_CAM_NIVEAUX[1][num_NIVEAU - 1] - 40;

		


		//////////////////////////////////////////////////////////
		//                      INIT MAPS                       //
		//////////////////////////////////////////////////////////
		MAP_scrollTo(map_NIVEAU_BG_B, pos_X_CAM_NIVEAU, pos_Y_CAM_NIVEAU);
		SYS_doVBlankProcess();
		
		MAP_scrollTo(map_NIVEAU_BG_A, pos_X_CAM_NIVEAU, pos_Y_CAM_NIVEAU);
		SYS_doVBlankProcess();
	}


	//////////////////////////////////////////////////////////
    //                         SALLE                        //
    //////////////////////////////////////////////////////////
	else if(type == 1)
	{
		offset_TABLES_SALLES = TABLE_OFFSET_SALLES[num_NIVEAU - 1];
		
		//////////////////////////////////////////////////////////
		//                CHARGEMENT TILES BG_B                 //
		//////////////////////////////////////////////////////////
		VDP_loadTileSet(TABLE_TILESET_SALLES_NIVEAUX[id_TILE + offset_TABLES_SALLES], adr_VRAM_BG_B, CPU);
		adr_VRAM_BG_A = adr_VRAM_BG_B + TABLE_TILESET_NIVEAUX[0][index]->numTile;
		SYS_doVBlankProcess();

		//////////////////////////////////////////////////////////
		//                  CREATION MAP BG_B                   //
		//////////////////////////////////////////////////////////
		map_NIVEAU_BG_B = MAP_create(TABLE_MAPDEF_SALLES_NIVEAUX[id_TILE + offset_TABLES_SALLES], BG_B, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, adr_VRAM_BG_B));
		//map_BG_B_OK = 1;
		SYS_doVBlankProcess();




		//////////////////////////////////////////////////////////
		//                     INIT CAMERA                      //
		//////////////////////////////////////////////////////////
		pos_X_CAM_SALLE = 0;
		pos_Y_CAM_SALLE = 0;




		//////////////////////////////////////////////////////////
		//                      INIT MAPS                       //
		//////////////////////////////////////////////////////////
		MAP_scrollTo(map_NIVEAU_BG_B, pos_X_CAM_SALLE, pos_Y_CAM_SALLE);
		SYS_doVBlankProcess();
		
	}

	//////////////////////////////////////////////////////////
    //                        DONJON                        //
    //////////////////////////////////////////////////////////
	else if(type == 2)
	{
		
		//
	}



	

	
}

