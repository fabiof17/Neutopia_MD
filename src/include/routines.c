#include <genesis.h>

#include "variables.h"
#include "structures.h"

#include "tables_JOUEUR.h"
#include "tables_DONJONS.h"
#include "tables_ENTREES.h"
#include "tables_MENU.h"
#include "tables_NIVEAUX.h"
#include "tables_SALLES.h"

#include "boutons_MANETTE.h"
#include "outils.h"

#include "sprites_JEU.h"
#include "sprites_MENU.h"

#include "maps_GLOBAL.h"
#include "maps_MENU.h"
#include "maps_NIVEAUX.h"
#include "maps_ENTREES.h"

#include "palettes.h"


//******************************************************//
//                                                      //
//                        TITRE                         //
//                                                      //
//******************************************************//

void anim_TITRE()
{
	//





	SYS_doVBlankProcess();
}


void boucle_TITRE()
{
	//




	SYS_doVBlankProcess();
}




//******************************************************//
//                                                      //
//                         MENU                         //
//                                                      //
//******************************************************//

void afficher_MENU(u8 type)
{
	s16 cam_X = 0;
	s16 cam_Y = 0;

	if(type == 0)
	{
		cam_X = pos_X_CAM_NIVEAU;
		cam_Y = pos_Y_CAM_NIVEAU;
	}

	else if(type == 1)
	{
		cam_X = pos_X_CAM_SALLE;
		cam_Y = pos_Y_CAM_SALLE;
	}
	
	//******************************************************//
	//                                                      //
	//                        BG_A                          //
	//                                                      //
	//******************************************************//

    VDP_setTileMapEx(BG_A, image_MENU.tilemap, TILE_ATTR_FULL(PAL0, TRUE, FALSE, FALSE, adr_VRAM_MENU), 32 + (cam_X >> 3), 5 + (cam_Y >> 3), 0, 5, 32, 23, CPU);


	//******************************************************//
	//                                                      //
	//                      BOUSSOLE                        //
	//                                                      //
	//******************************************************//

	VDP_setTileMapEx(BG_A, image_BOUSSOLE.tilemap, TILE_ATTR_FULL(PAL3, TRUE, FALSE, FALSE, adr_VRAM_BOUSSOLE), 18 + 32 + (cam_X >> 3), 10 + (cam_Y >> 3), 0, 0, 4, 4, CPU);


	//******************************************************//
	//                                                      //
	//                       OBJETS                         //
	//                                                      //
	//******************************************************//

	u8 x = 0;
	u8 y = 0;

	//////////////////////////////////////////////////////////
    //                      OBJETS BAS                      //
    //////////////////////////////////////////////////////////

	for(x=0 ; x<4 ; x++)
	{
		for(y=0 ; y<2 ; y++)
		{
			if(TABLE_OBJETS_BAS[y][x] != NULL)
			{
				VDP_setTileMapEx(BG_A, image_OBJET.tilemap, TILE_ATTR_FULL(TABLE_PAL_OBJETS_BAS[y][x], TRUE, FALSE, FALSE, TABLE_ADR_VRAM_OBJETS_BAS[y][x]), 		32 + 3 + (x*3) + (cam_X >> 3),		19 + (y*3) + (cam_Y >> 3),		0, 0, 2, 2, CPU);
			}
		}
		
	}

	//////////////////////////////////////////////////////////
    //                      OBJETS HAUT                     //
    //////////////////////////////////////////////////////////
	
	for(x=0 ; x<4 ; x++)
	{
		for(y=0 ; y<2 ; y++)
		{
			if(TABLE_OBJETS_HAUT[y][x] != NULL)
			{
				VDP_setTileMapEx(BG_A, image_OBJET.tilemap, TILE_ATTR_FULL(TABLE_PAL_OBJETS_HAUT[y][x], TRUE, FALSE, FALSE, TABLE_ADR_VRAM_OBJETS_HAUT[y][x]), 		32 + 3 + (x*3) + (cam_X >> 3),		10 + (y*3) + (cam_Y >> 3),		0, 0, 2, 2, CPU);
			}
		}
		
	}
	


	SYS_doVBlankProcess();
}



//******************************************************//
//                                                      //
//                        NIVEAU                        //
//                                                      //
//******************************************************//

void maj_PALETTES( u8 index , u8 type )
{
    index -= 1;
	
	//////////////////////////////////////////////////////////
    //                        NIVEAU                        //
    //////////////////////////////////////////////////////////
	if(type == 0)
	{
		PAL_setPalette(PAL1, TABLE_ADR_PAL_NIVEAUX[0][index]->data, DMA);
		PAL_setPalette(PAL2, TABLE_ADR_PAL_NIVEAUX[1][index]->data, DMA);
	}


	//////////////////////////////////////////////////////////
    //                         SALLE                        //
    //////////////////////////////////////////////////////////
	else if(type == 1)
	{
		PAL_setPalette(PAL1, TABLE_ADR_PAL_SALLES[id_TILE + offset_TABLES_SALLES]->data, DMA);
		//PAL_setPalette(PAL2, TABLE_ADR_PAL_NIVEAUX[1][index]->data, DMA);
	}


	//////////////////////////////////////////////////////////
    //                        DONJON                        //
    //////////////////////////////////////////////////////////
	else if(type == 2)
	{
		//
	}
}


void maj_PT_COLL_DECOR()
{
	JOUEUR.pt1_X_COLL_DECOR = JOUEUR.pos_X_JOUEUR + TABLE_POS_PT1_COLL_DECOR[0][axe_JOUEUR];
	JOUEUR.pt1_Y_COLL_DECOR = JOUEUR.pos_Y_JOUEUR + TABLE_POS_PT1_COLL_DECOR[1][axe_JOUEUR];

	JOUEUR.pt2_X_COLL_DECOR = JOUEUR.pos_X_JOUEUR + TABLE_POS_PT2_COLL_DECOR[0][axe_JOUEUR];
	JOUEUR.pt2_Y_COLL_DECOR = JOUEUR.pos_Y_JOUEUR + TABLE_POS_PT2_COLL_DECOR[1][axe_JOUEUR];
}


void manette_JOUEUR()
{
	u16 value=JOY_readJoypad(JOY_1);

	//////////////////////////////////////////////////////////
	//                  SI PAS TIR OU TOUCHE                //
	//////////////////////////////////////////////////////////
	if(etat_JOUEUR != ATTAQUE && etat_JOUEUR != TOUCHE)
	{
		
		//////////////////////////////////////////////////////////
		//                         ARRET                        //
		//////////////////////////////////////////////////////////
		if((value & BUTTON_DIR) == 0)
		{
			maj_PT_COLL_DECOR();
			
			etat_JOUEUR = ARRET;
			return;
		}

		//////////////////////////////////////////////////////////
		//                          BAS                        //
		//////////////////////////////////////////////////////////		
		else if(value & BUTTON_DOWN)
		{			
			JOUEUR.pos_X_JOUEUR += aligner_JOUEUR(JOUEUR.pos_X_JOUEUR + 4);
			JOUEUR.pos_Y_JOUEUR += 1;

			maj_PT_COLL_DECOR();
			id_TILE = MAP_getTile( map_COLLISION , (JOUEUR.pos_X_JOUEUR)>>3 , (JOUEUR.pos_Y_JOUEUR>>3) + (pos_Y_CAM_NIVEAU>>3) );

			SPR_setPosition(JOUEUR.sprite_JOUEUR, JOUEUR.pos_X_JOUEUR, JOUEUR.pos_Y_JOUEUR);
			SPR_setPosition(sprite_POINT1, JOUEUR.pt1_X_COLL_DECOR, JOUEUR.pt1_Y_COLL_DECOR);
			SPR_setPosition(sprite_POINT2, JOUEUR.pt2_X_COLL_DECOR, JOUEUR.pt2_Y_COLL_DECOR);
			
			etat_JOUEUR = MARCHE;
			axe_JOUEUR = BAS;
			return;
		}

		//////////////////////////////////////////////////////////
		//                          HAUT                        //
		//////////////////////////////////////////////////////////		
		else if(value & BUTTON_UP)
		{
			JOUEUR.pos_X_JOUEUR += aligner_JOUEUR(JOUEUR.pos_X_JOUEUR + 4);
			JOUEUR.pos_Y_JOUEUR -= 1;

			maj_PT_COLL_DECOR();
			id_TILE = MAP_getTile( map_COLLISION , (JOUEUR.pos_X_JOUEUR)>>3 , (JOUEUR.pos_Y_JOUEUR>>3) + (pos_Y_CAM_NIVEAU>>3) );

			SPR_setPosition(JOUEUR.sprite_JOUEUR, JOUEUR.pos_X_JOUEUR, JOUEUR.pos_Y_JOUEUR);
			SPR_setPosition(sprite_POINT1, JOUEUR.pt1_X_COLL_DECOR, JOUEUR.pt1_Y_COLL_DECOR);
			SPR_setPosition(sprite_POINT2, JOUEUR.pt2_X_COLL_DECOR, JOUEUR.pt2_Y_COLL_DECOR);
			
			etat_JOUEUR = MARCHE;
			axe_JOUEUR = HAUT;
			return;
		}

		//////////////////////////////////////////////////////////
		//                         DROITE                       //
		//////////////////////////////////////////////////////////		
		else if(value & BUTTON_RIGHT)
		{
			JOUEUR.pos_Y_JOUEUR += aligner_JOUEUR(JOUEUR.pos_Y_JOUEUR + 4);
			JOUEUR.pos_X_JOUEUR += 1;

			maj_PT_COLL_DECOR();
			id_TILE = MAP_getTile( map_COLLISION , (JOUEUR.pos_X_JOUEUR)>>3 , (JOUEUR.pos_Y_JOUEUR>>3) + (pos_Y_CAM_NIVEAU>>3) );

			SPR_setPosition(JOUEUR.sprite_JOUEUR, JOUEUR.pos_X_JOUEUR, JOUEUR.pos_Y_JOUEUR);
			SPR_setPosition(sprite_POINT1, JOUEUR.pt1_X_COLL_DECOR, JOUEUR.pt1_Y_COLL_DECOR);
			SPR_setPosition(sprite_POINT2, JOUEUR.pt2_X_COLL_DECOR, JOUEUR.pt2_Y_COLL_DECOR);

			etat_JOUEUR = MARCHE;
			axe_JOUEUR = DROITE;
			return;
		}

		//////////////////////////////////////////////////////////
		//                         GAUCHE                       //
		//////////////////////////////////////////////////////////		
		else if(value & BUTTON_LEFT)
		{
			JOUEUR.pos_Y_JOUEUR += aligner_JOUEUR(JOUEUR.pos_Y_JOUEUR + 4);
			JOUEUR.pos_X_JOUEUR -= 1;

			maj_PT_COLL_DECOR();
			id_TILE = MAP_getTile( map_COLLISION , (JOUEUR.pos_X_JOUEUR)>>3 , (JOUEUR.pos_Y_JOUEUR>>3) + (pos_Y_CAM_NIVEAU>>3) );

			SPR_setPosition(JOUEUR.sprite_JOUEUR, JOUEUR.pos_X_JOUEUR, JOUEUR.pos_Y_JOUEUR);
			SPR_setPosition(sprite_POINT1, JOUEUR.pt1_X_COLL_DECOR, JOUEUR.pt1_Y_COLL_DECOR);
			SPR_setPosition(sprite_POINT2, JOUEUR.pt2_X_COLL_DECOR, JOUEUR.pt2_Y_COLL_DECOR);

			etat_JOUEUR = MARCHE;
			axe_JOUEUR = GAUCHE;
			return;
		}
	}
}


void tiles_JOUEUR()
{
	//////////////////////////////////////////////////////////
	//                         ARRET                        //
	//////////////////////////////////////////////////////////
	if(etat_JOUEUR == ARRET)
	{
		JOUEUR.compteur_ANIM = 0;
		JOUEUR.index_ANIM = 1;

		SPR_setAnim(JOUEUR.sprite_JOUEUR,axe_JOUEUR);
		SPR_setFrame(JOUEUR.sprite_JOUEUR,0);
		return;
	}


	//////////////////////////////////////////////////////////
	//                         MARCHE                       //
	//////////////////////////////////////////////////////////	
	else if(etat_JOUEUR == MARCHE)
	{

		JOUEUR.compteur_ANIM +=1;
		if(JOUEUR.compteur_ANIM > 5)
		{
			JOUEUR.compteur_ANIM = 0;
			JOUEUR.index_ANIM += 1;

			if(JOUEUR.index_ANIM > 3)
			{
				JOUEUR.index_ANIM = 0;
			}
		}


		if(axe_JOUEUR == BAS)
		{
			SPR_setAnim(JOUEUR.sprite_JOUEUR,0);
			SPR_setFrame(JOUEUR.sprite_JOUEUR,JOUEUR.index_ANIM);
			return;
		}

		else if(axe_JOUEUR == HAUT)
		{
			SPR_setAnim(JOUEUR.sprite_JOUEUR,1);
			SPR_setFrame(JOUEUR.sprite_JOUEUR,JOUEUR.index_ANIM);
			return;
		}

		else if(axe_JOUEUR == DROITE)
		{
			SPR_setAnim(JOUEUR.sprite_JOUEUR,2);
			SPR_setFrame(JOUEUR.sprite_JOUEUR,JOUEUR.index_ANIM);
			return;
		}

		else if(axe_JOUEUR == GAUCHE)
		{
			SPR_setAnim(JOUEUR.sprite_JOUEUR,3);
			SPR_setFrame(JOUEUR.sprite_JOUEUR,JOUEUR.index_ANIM);
			return;
		}
	}


	//////////////////////////////////////////////////////////
	//                        ATTAQUE                       //
	//////////////////////////////////////////////////////////
	else if(etat_JOUEUR == ATTAQUE)
	{
		SPR_setPosition(JOUEUR.sprite_EPEE, JOUEUR.pos_X_JOUEUR + TABLE_POS_EPEE[0][axe_JOUEUR], JOUEUR.pos_Y_JOUEUR +  + TABLE_POS_EPEE[1][axe_JOUEUR]);

		SPR_setAnim(JOUEUR.sprite_EPEE,axe_JOUEUR);

		SPR_setAnim(JOUEUR.sprite_JOUEUR,axe_JOUEUR + 4);
		SPR_setFrame(JOUEUR.sprite_JOUEUR,0);

		JOUEUR.compteur_ATTAQUE += 1;

		if(JOUEUR.compteur_ATTAQUE > 7)
		{
			JOUEUR.compteur_ATTAQUE = 0;
			etat_JOUEUR = ARRET;

			SPR_setPosition(JOUEUR.sprite_EPEE, 0, -16);
		}
	}
}