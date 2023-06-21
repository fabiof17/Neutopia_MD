#include <genesis.h>

#include "structures.h"
#include "variables.h"

#include "tables_DONJONS.h"
#include "tables_ENTREES.h"
#include "tables_JOUEUR.h"
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
		cam_X = pos_X_CAM;
		cam_Y = pos_Y_CAM;
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

    VDP_setTileMapEx(BG_A, image_MENU.tilemap, TILE_ATTR_FULL(PAL0, TRUE, FALSE, FALSE, adr_VRAM_MENU), 32 + (cam_X >> 3), 5 + (cam_Y >> 3) + 32, 0, 5, 32, 23, CPU);


	//******************************************************//
	//                                                      //
	//                      BOUSSOLE                        //
	//                                                      //
	//******************************************************//

	VDP_setTileMapEx(BG_A, image_BOUSSOLE.tilemap, TILE_ATTR_FULL(PAL3, TRUE, FALSE, FALSE, adr_VRAM_BOUSSOLE), 18 + 32 + (cam_X >> 3), 10 + (cam_Y >> 3) + 32, 0, 0, 4, 4, CPU);


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
				VDP_setTileMapEx(BG_A, image_OBJET.tilemap, TILE_ATTR_FULL(TABLE_PAL_OBJETS_BAS[y][x], TRUE, FALSE, FALSE, TABLE_ADR_VRAM_OBJETS_BAS[y][x]), 		32 + 3 + (x*3) + (cam_X >> 3),		19 + (y*3) + (cam_Y >> 3) + 32,		0, 0, 2, 2, CPU);
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
				VDP_setTileMapEx(BG_A, image_OBJET.tilemap, TILE_ATTR_FULL(TABLE_PAL_OBJETS_HAUT[y][x], TRUE, FALSE, FALSE, TABLE_ADR_VRAM_OBJETS_HAUT[y][x]), 		32 + 3 + (x*3) + (cam_X >> 3),		10 + (y*3) + (cam_Y >> 3) + 32,		0, 0, 2, 2, CPU);
			}
		}
		
	}
	


	//SYS_doVBlankProcess();
}




//******************************************************//
//                                                      //
//                        NIVEAU                        //
//                                                      //
//******************************************************//

void maj_PALETTES( u8 index , u8 type )
{
    //index -= 1;
	
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
		PAL_setPalette(PAL1, TABLE_ADR_PAL_ENTREES[id_TILE3 + offset_TABLES_ENTREES]->data, DMA);
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
	JOUEUR.pt1_X_COLL_DECOR = JOUEUR.pos_X_JOUEUR + 4;
	JOUEUR.pt1_Y_COLL_DECOR = JOUEUR.pos_Y_JOUEUR + 21;

	JOUEUR.pt2_X_COLL_DECOR = JOUEUR.pos_X_JOUEUR + 19;
	JOUEUR.pt2_Y_COLL_DECOR = JOUEUR.pos_Y_JOUEUR + 21;

	JOUEUR.pt3_X_COLL_DECOR = JOUEUR.pos_X_JOUEUR + 4;
	JOUEUR.pt3_Y_COLL_DECOR = JOUEUR.pos_Y_JOUEUR + 32;

	JOUEUR.pt4_X_COLL_DECOR = JOUEUR.pos_X_JOUEUR + 19;
	JOUEUR.pt4_Y_COLL_DECOR = JOUEUR.pos_Y_JOUEUR + 32;
}




void afficher_ENTREE()
{
	if(num_NIVEAU == 0)
	{
		VDP_loadTileSet(ptr_TABLE_ENTREES[id_TILE3].adr_Image->tileset, adr_VRAM_ENTREE, DMA);
		VDP_drawImageEx( ptr_TABLE_ENTREES[id_TILE3].bg , ptr_TABLE_ENTREES[id_TILE3].adr_Image , TILE_ATTR_FULL(ptr_TABLE_ENTREES[id_TILE3].pal, ptr_TABLE_ENTREES[id_TILE3].priorite, FALSE, FALSE, adr_VRAM_ENTREE) , ptr_TABLE_ENTREES[id_TILE3].pos_X + TABLE_OFFSET_COLLISION[0][index_X_CARTE] , ptr_TABLE_ENTREES[id_TILE3].pos_Y + TABLE_OFFSET_COLLISION[1][index_Y_CARTE] , FALSE , FALSE );
	}

}

/*
void collision_ENTREE()
{
	id_TILE3 = MAP_getTile( map_COLLISION , (JOUEUR.pt3_X_COLL_DECOR>>3) + TABLE_OFFSET_COLLISION[0][index_X_CARTE] , ((JOUEUR.pt3_Y_COLL_DECOR-1)>>3) + TABLE_OFFSET_COLLISION[1][index_Y_CARTE] );
	id_TILE4 = MAP_getTile( map_COLLISION , (JOUEUR.pt4_X_COLL_DECOR>>3) + TABLE_OFFSET_COLLISION[0][index_X_CARTE] , ((JOUEUR.pt4_Y_COLL_DECOR-1)>>3) + TABLE_OFFSET_COLLISION[1][index_Y_CARTE] );


	//////////////////////////////////////////////////////////
	//			 	  TEST COLLISION ENTREE					//
	//////////////////////////////////////////////////////////

	if(id_TILE3 < 43)
	{
		if(id_TILE4 == id_TILE3)
		{
			// TYPE D'ENTREE
			// 1 = ESCALIER
			// 2 = DONJON
			// 3 = CAVE
			id_ENTREE = ptr_TABLE_ENTREES[id_TILE3].id;

			// DONJON OU CAVE
			if(id_ENTREE != 0)
			{
				afficher_ENTREE();

				// TYPE DE DECOR
				// 0 = NIVEAU
				// 1 = SALLE OU DONJON
				type_DECOR = 1;

				// SEQUENCE ENTREE CAVE
				etat_JEU = ENTREE_CAVE;
				//
				return;
			}

			// ESCALIER
			else
			{
				// PAS ENTREE SECRETE
				if(ptr_TABLE_ENTREES[id_TILE3].secret == 0)
				{
					// TYPE DE DECOR
					// 0 = NIVEAU
					// 1 = SALLE OU DONJON
					type_DECOR = 1;

					// SEQUENCE ENTREE CAVE
					etat_JEU = ENTREE_CAVE;
					//
					return;
				}

				// ENTREE SECRETE
				else
				{
					// ENTREE REVELEE
					if(entree_SECRET_OK == 1)
					{
						// TYPE DE DECOR
						// 0 = NIVEAU
						// 1 = SALLE OU DONJON
						type_DECOR = 1;

						// SEQUENCE ENTREE CAVE
						etat_JEU = ENTREE_CAVE;
						//
						return;
					}

					// ENTREE PAS REVELEE
					else
					{
						// ON DEPLACE LE JOUEUR
						JOUEUR.pos_X_JOUEUR += aligner_JOUEUR(JOUEUR.pos_X_JOUEUR + 4);
						JOUEUR.pos_Y_JOUEUR -= 1;
						axe_JOUEUR = HAUT;
					}
				}
			}
		}
	}
}
*/



void scrolling_ECRAN()
{
	//////////////////////////////////////////////////////////
    //                         BAS                          //
    //////////////////////////////////////////////////////////
	if(axe_JOUEUR == BAS)
	{
		pos_Y_CAM += 4;
		JOUEUR.pos_Y_JOUEUR -= 4;
	}

	//////////////////////////////////////////////////////////
    //                         HAUT                         //
    //////////////////////////////////////////////////////////
	else if(axe_JOUEUR == HAUT)
	{
		pos_Y_CAM -= 4;
		JOUEUR.pos_Y_JOUEUR += 4;
	}

	//////////////////////////////////////////////////////////
    //                        DROITE                        //
    //////////////////////////////////////////////////////////
	else if(axe_JOUEUR == DROITE)
	{
		pos_X_CAM += 4;
		JOUEUR.pos_X_JOUEUR -= 4;
	}

	//////////////////////////////////////////////////////////
    //                        GAUCHE                        //
    //////////////////////////////////////////////////////////
	else if(axe_JOUEUR == GAUCHE)
	{
		pos_X_CAM -= 4;
		JOUEUR.pos_X_JOUEUR += 4;
	}


	MAP_scrollTo(map_NIVEAU_BG_B, pos_X_CAM, pos_Y_CAM);
	MAP_scrollTo(map_NIVEAU_BG_A, pos_X_CAM, pos_Y_CAM);


	SPR_setPosition(JOUEUR.sprite_JOUEUR, JOUEUR.pos_X_JOUEUR, JOUEUR.pos_Y_JOUEUR);


	compteur_SCROLLING += 1;

	if(compteur_SCROLLING > duree_SCROLLING)
	{		
		compteur_SCROLLING = 0;
		etat_JEU = FIN_SCROLLING_NIVEAU;
	}
}


void sortie_SCROLLING()
{
	if(axe_JOUEUR == BAS)
	{
		if(JOUEUR.pos_Y_JOUEUR < 35)
		{
			JOUEUR.pos_Y_JOUEUR += 1;
			maj_PT_COLL_DECOR();


			SPR_setPosition(JOUEUR.sprite_JOUEUR, JOUEUR.pos_X_JOUEUR, JOUEUR.pos_Y_JOUEUR);

			SPR_setPosition(sprite_POINT1, JOUEUR.pt1_X_COLL_DECOR, JOUEUR.pt1_Y_COLL_DECOR);
			SPR_setPosition(sprite_POINT2, JOUEUR.pt2_X_COLL_DECOR, JOUEUR.pt2_Y_COLL_DECOR);			
			SPR_setPosition(sprite_POINT3, JOUEUR.pt3_X_COLL_DECOR, JOUEUR.pt3_Y_COLL_DECOR);
			SPR_setPosition(sprite_POINT4, JOUEUR.pt4_X_COLL_DECOR, JOUEUR.pt4_Y_COLL_DECOR);

			etat_JOUEUR = MARCHE;
			return;			
		}

		else
		{
			afficher_MENU(type_DECOR);
			maj_PT_COLL_DECOR();

			etat_JOUEUR = MARCHE;
			etat_JEU = NIVEAU;
			return;	
		}
	}


	else if(axe_JOUEUR == HAUT)
	{
		if(JOUEUR.pos_Y_JOUEUR > 192)
		{
			JOUEUR.pos_Y_JOUEUR -= 1;
			maj_PT_COLL_DECOR();


			SPR_setPosition(JOUEUR.sprite_JOUEUR, JOUEUR.pos_X_JOUEUR, JOUEUR.pos_Y_JOUEUR);

			SPR_setPosition(sprite_POINT1, JOUEUR.pt1_X_COLL_DECOR, JOUEUR.pt1_Y_COLL_DECOR);
			SPR_setPosition(sprite_POINT2, JOUEUR.pt2_X_COLL_DECOR, JOUEUR.pt2_Y_COLL_DECOR);			
			SPR_setPosition(sprite_POINT3, JOUEUR.pt3_X_COLL_DECOR, JOUEUR.pt3_Y_COLL_DECOR);
			SPR_setPosition(sprite_POINT4, JOUEUR.pt4_X_COLL_DECOR, JOUEUR.pt4_Y_COLL_DECOR);

			etat_JOUEUR = MARCHE;
			return;				
		}

		else
		{
			afficher_MENU(type_DECOR);
			maj_PT_COLL_DECOR();

			etat_JOUEUR = MARCHE;
			etat_JEU = NIVEAU;
			return;	
		}
	}


	else if(axe_JOUEUR == DROITE)
	{
		if(JOUEUR.pos_X_JOUEUR < -4)
		{
			JOUEUR.pos_X_JOUEUR += 1;
			maj_PT_COLL_DECOR();


			SPR_setPosition(JOUEUR.sprite_JOUEUR, JOUEUR.pos_X_JOUEUR, JOUEUR.pos_Y_JOUEUR);

			SPR_setPosition(sprite_POINT1, JOUEUR.pt1_X_COLL_DECOR, JOUEUR.pt1_Y_COLL_DECOR);
			SPR_setPosition(sprite_POINT2, JOUEUR.pt2_X_COLL_DECOR, JOUEUR.pt2_Y_COLL_DECOR);			
			SPR_setPosition(sprite_POINT3, JOUEUR.pt3_X_COLL_DECOR, JOUEUR.pt3_Y_COLL_DECOR);
			SPR_setPosition(sprite_POINT4, JOUEUR.pt4_X_COLL_DECOR, JOUEUR.pt4_Y_COLL_DECOR);

			etat_JOUEUR = MARCHE;
			return;				
		}

		else
		{
			afficher_MENU(type_DECOR);
			maj_PT_COLL_DECOR();

			etat_JOUEUR = MARCHE;
			etat_JEU = NIVEAU;
			return;	
		}
	}


	else if(axe_JOUEUR == GAUCHE)
	{
		if(JOUEUR.pos_X_JOUEUR > 236)
		{
			JOUEUR.pos_X_JOUEUR -= 1;
			maj_PT_COLL_DECOR();


			SPR_setPosition(JOUEUR.sprite_JOUEUR, JOUEUR.pos_X_JOUEUR, JOUEUR.pos_Y_JOUEUR);

			SPR_setPosition(sprite_POINT1, JOUEUR.pt1_X_COLL_DECOR, JOUEUR.pt1_Y_COLL_DECOR);
			SPR_setPosition(sprite_POINT2, JOUEUR.pt2_X_COLL_DECOR, JOUEUR.pt2_Y_COLL_DECOR);			
			SPR_setPosition(sprite_POINT3, JOUEUR.pt3_X_COLL_DECOR, JOUEUR.pt3_Y_COLL_DECOR);
			SPR_setPosition(sprite_POINT4, JOUEUR.pt4_X_COLL_DECOR, JOUEUR.pt4_Y_COLL_DECOR);

			etat_JOUEUR = MARCHE;
			return;				
		}

		else
		{
			afficher_MENU(type_DECOR);
			maj_PT_COLL_DECOR();
			
			etat_JOUEUR = MARCHE;
			etat_JEU = NIVEAU;
			return;	
		}
	}

}




void entree_ENTREE()
{
	// ESCALIER
	if(id_ENTREE == 0)
	{
		PAL_fadeOutAll(14,FALSE);
	}

	// CAVE OU DONJON
	else
	{
		if(PAL_isDoingFade() == FALSE)
		{
			PAL_fadeOutAll(14,TRUE);
		}
		
		if(PAL_isDoingFade() == TRUE)
		{
			if(JOUEUR.pos_Y_JOUEUR == (ptr_TABLE_ENTREES[id_TILE3].pos_Y<<3) )
			{
				// effacer_NIVEAU();
				// init SALLE OU DONJON
			}
			
			JOUEUR.pos_Y_JOUEUR -= 1;
			SPR_setPosition(JOUEUR.sprite_JOUEUR,JOUEUR.pos_X_JOUEUR,JOUEUR.pos_Y_JOUEUR);
		}

		//PAL_waitFadeCompletion();
		
	}
}




void manette_JOUEUR()
{
	u16 value=JOY_readJoypad(JOY_1);

	//////////////////////////////////////////////////////////
	//                  SI PAS TIR OU TOUCHE                //
	//////////////////////////////////////////////////////////
	if(etat_JOUEUR != ATTAQUE && etat_JOUEUR != TOUCHE)
	{		
		//******************************************************//
		//                                                      //
		//                        ARRET                         //
		//                                                      //
		//******************************************************//
		if((value & BUTTON_DIR) == 0)
		{
			maj_PT_COLL_DECOR();
			
			etat_JOUEUR = ARRET;
			return;
		}

		//******************************************************//
		//                                                      //
		//                         BAS                          //
		//                                                      //
		//******************************************************//	
		else if(value & BUTTON_DOWN)
		{			
			//******************************************************//
			//                                                      //
			//                   TEST SORTIE ECRAN                  //
			//                                                      //
			//******************************************************//				
			if(JOUEUR.pos_Y_JOUEUR > 194)
			{
				axe_JOUEUR = BAS;
				duree_SCROLLING = DUREE_SCROLL_V;
				index_Y_CARTE += 1;
				
				etat_JEU = SCROLLING_NIVEAU;
				return ;
			}



			
			//******************************************************//
			//                                                      //
			//			    	  TEST COLLISION					//
			//                                                      //
			//******************************************************//	
			
			id_TILE3 = MAP_getTile( map_COLLISION , (JOUEUR.pt3_X_COLL_DECOR>>3) + TABLE_OFFSET_COLLISION[0][index_X_CARTE] , ((JOUEUR.pt3_Y_COLL_DECOR+1)>>3) + TABLE_OFFSET_COLLISION[1][index_Y_CARTE] );
			id_TILE4 = MAP_getTile( map_COLLISION , (JOUEUR.pt4_X_COLL_DECOR>>3) + TABLE_OFFSET_COLLISION[0][index_X_CARTE] , ((JOUEUR.pt4_Y_COLL_DECOR+1)>>3) + TABLE_OFFSET_COLLISION[1][index_Y_CARTE] );


			//////////////////////////////////////////////////////////
			//			 	  TEST COLLISION ENTREE					//
			//////////////////////////////////////////////////////////

			if(id_TILE3 < 43)
			{
				if(id_TILE4 == id_TILE3)
				{
					
					if(ptr_TABLE_ENTREES[id_TILE3].secret == 1)
					{
						if(entree_SECRET_OK == 1)
						{
							// TYPE D'ENTREE
							// 0 = ESCALIER
							// 1 = DONJON
							// 2 = PORTE
							id_ENTREE = ptr_TABLE_ENTREES[id_TILE3].id;

							num_ENTREE = id_TILE3;

							afficher_ENTREE();

							// TYPE DE DECOR
							// 0 = NIVEAU
							// 1 = SALLE OU DONJON
							type_DECOR = 1;

							// SEQUENCE ENTREE CAVE
							etat_JEU = ENTREE_CAVE;
							//
							return;
						}
					}

					else
					{
						// TYPE D'ENTREE
						// 0 = ESCALIER
						// 1 = DONJON
						// 2 = PORTE
						id_ENTREE = ptr_TABLE_ENTREES[id_TILE3].id;

						num_ENTREE = id_TILE3;

						afficher_ENTREE();

						// TYPE DE DECOR
						// 0 = NIVEAU
						// 1 = SALLE OU DONJON
						type_DECOR = 1;

						// SEQUENCE ENTREE CAVE
						etat_JEU = ENTREE_CAVE;
						//
						return;						
					}
				}
			}
			




			//////////////////////////////////////////////////////////
			//			 	  TEST COLLISION DECOR					//
			//////////////////////////////////////////////////////////

			id_TILE3 = MAP_getTile( map_COLLISION , (JOUEUR.pt3_X_COLL_DECOR>>3) + TABLE_OFFSET_COLLISION[0][index_X_CARTE] , ((JOUEUR.pt3_Y_COLL_DECOR+1)>>3) + TABLE_OFFSET_COLLISION[1][index_Y_CARTE] );

			// TOUCHE MUR //
			if(id_TILE3 == 44)
			{
				id_TILE4 = MAP_getTile( map_COLLISION , (JOUEUR.pt4_X_COLL_DECOR>>3) + TABLE_OFFSET_COLLISION[0][index_X_CARTE] , ((JOUEUR.pt4_Y_COLL_DECOR+1)>>3) + TABLE_OFFSET_COLLISION[1][index_Y_CARTE] );

				// TOUCHE VIDE //
				if(id_TILE4 != 44)
				{
					JOUEUR.pos_X_JOUEUR += 1;
					axe_JOUEUR = DROITE;
				}
			}

			// TOUCHE VIDE //
			else if(id_TILE3 != 44)
			{
				id_TILE4 = MAP_getTile( map_COLLISION , (JOUEUR.pt4_X_COLL_DECOR>>3) + TABLE_OFFSET_COLLISION[0][index_X_CARTE] , ((JOUEUR.pt4_Y_COLL_DECOR+1)>>3) + TABLE_OFFSET_COLLISION[1][index_Y_CARTE] );

				// TOUCHE MUR //
				if(id_TILE4 == 44)
				{
					JOUEUR.pos_X_JOUEUR -= 1;
					axe_JOUEUR = GAUCHE;
				}

				// TOUCHE VIDE //
				else
				{
					JOUEUR.pos_X_JOUEUR += aligner_JOUEUR(JOUEUR.pos_X_JOUEUR + 4);
					JOUEUR.pos_Y_JOUEUR += 1;
					axe_JOUEUR = BAS;
				}
			}

			maj_PT_COLL_DECOR();

			SPR_setPosition(JOUEUR.sprite_JOUEUR, JOUEUR.pos_X_JOUEUR, JOUEUR.pos_Y_JOUEUR);

			SPR_setPosition(sprite_POINT1, JOUEUR.pt1_X_COLL_DECOR, JOUEUR.pt1_Y_COLL_DECOR);
			SPR_setPosition(sprite_POINT2, JOUEUR.pt2_X_COLL_DECOR, JOUEUR.pt2_Y_COLL_DECOR);			
			SPR_setPosition(sprite_POINT3, JOUEUR.pt3_X_COLL_DECOR, JOUEUR.pt3_Y_COLL_DECOR);
			SPR_setPosition(sprite_POINT4, JOUEUR.pt4_X_COLL_DECOR, JOUEUR.pt4_Y_COLL_DECOR);
			
			etat_JOUEUR = MARCHE;	
			
			return;
		}

		//******************************************************//
		//                                                      //
		//                         HAUT                         //
		//                                                      //
		//******************************************************//	
		else if(value & BUTTON_UP)
		{
			//******************************************************//
			//                                                      //
			//                   TEST SORTIE ECRAN                  //
			//                                                      //
			//******************************************************//			
			if(JOUEUR.pos_Y_JOUEUR < 28)
			{
				axe_JOUEUR = HAUT;
				duree_SCROLLING = DUREE_SCROLL_V;
				index_Y_CARTE -= 1;
				
				etat_JEU = SCROLLING_NIVEAU;
				return ;
			}




			//******************************************************//
			//                                                      //
			//			    	  TEST COLLISION					//
			//                                                      //
			//******************************************************//	
			
			id_TILE3 = MAP_getTile( map_COLLISION , (JOUEUR.pt3_X_COLL_DECOR>>3) + TABLE_OFFSET_COLLISION[0][index_X_CARTE] , ((JOUEUR.pt3_Y_COLL_DECOR+1)>>3) + TABLE_OFFSET_COLLISION[1][index_Y_CARTE] );
			id_TILE4 = MAP_getTile( map_COLLISION , (JOUEUR.pt4_X_COLL_DECOR>>3) + TABLE_OFFSET_COLLISION[0][index_X_CARTE] , ((JOUEUR.pt4_Y_COLL_DECOR+1)>>3) + TABLE_OFFSET_COLLISION[1][index_Y_CARTE] );


			//////////////////////////////////////////////////////////
			//			 	  TEST COLLISION ENTREE					//
			//////////////////////////////////////////////////////////

			if(id_TILE3 < 43)
			{
				if(id_TILE4 == id_TILE3)
				{
					if(ptr_TABLE_ENTREES[id_TILE3].secret == 1)
					{
						if(entree_SECRET_OK == 1)
						{
							// TYPE D'ENTREE
							// 0 = ESCALIER
							// 1 = DONJON
							// 2 = PORTE
							id_ENTREE = ptr_TABLE_ENTREES[id_TILE3].id;

							num_ENTREE = id_TILE3;

							afficher_ENTREE();

							// TYPE DE DECOR
							// 0 = NIVEAU
							// 1 = SALLE OU DONJON
							type_DECOR = 1;

							// SEQUENCE ENTREE CAVE
							etat_JEU = ENTREE_CAVE;
							//
							return;
						}
					}

					else
					{
						// TYPE D'ENTREE
						// 0 = ESCALIER
						// 1 = DONJON
						// 2 = PORTE
						id_ENTREE = ptr_TABLE_ENTREES[id_TILE3].id;

						num_ENTREE = id_TILE3;

						afficher_ENTREE();

						// TYPE DE DECOR
						// 0 = NIVEAU
						// 1 = SALLE OU DONJON
						type_DECOR = 1;

						// SEQUENCE ENTREE CAVE
						etat_JEU = ENTREE_CAVE;
						//
						return;						
					}
				}
			}
			




			//////////////////////////////////////////////////////////
			//			 	  TEST COLLISION DECOR					//
			//////////////////////////////////////////////////////////

			id_TILE1 = MAP_getTile( map_COLLISION , (JOUEUR.pt1_X_COLL_DECOR>>3) + TABLE_OFFSET_COLLISION[0][index_X_CARTE] , ((JOUEUR.pt1_Y_COLL_DECOR+1)>>3) + TABLE_OFFSET_COLLISION[1][index_Y_CARTE] );


			// TOUCHE MUR
			// TOUCHE ENTREE SECRETE PAS DECOUVERTE
			// TOUCHE PAS ESCALIER
			if(id_TILE1 == 44 || (ptr_TABLE_ENTREES[id_TILE1].secret == 1 && entree_SECRET_OK == 0 && ptr_TABLE_ENTREES[id_TILE1].id != 0 ) ) 
			{
				
				id_TILE2 = MAP_getTile( map_COLLISION , (JOUEUR.pt2_X_COLL_DECOR>>3) + TABLE_OFFSET_COLLISION[0][index_X_CARTE] , ((JOUEUR.pt2_Y_COLL_DECOR+1)>>3) + TABLE_OFFSET_COLLISION[1][index_Y_CARTE] );


				// TOUCHE VIDE
				// TOUCHE ENTREE SECRETE DECOUVERTE
				// TOUCHE ENTREE PAS SECRETE
				// TOUCHE ESCALIER
				if(id_TILE2 == 43 || (ptr_TABLE_ENTREES[id_TILE2].secret == 1 && entree_SECRET_OK == 1) || ptr_TABLE_ENTREES[id_TILE2].secret == 0 || ptr_TABLE_ENTREES[id_TILE2].id == 0 )
				{
					JOUEUR.pos_X_JOUEUR += 1;
					axe_JOUEUR = DROITE;
				}
			}

			// TOUCHE VIDE
			// TOUCHE ENTREE SECRETE DECOUVERTE
			// TOUCHE ENTREE PAS SECRETE
			// TOUCHE ESCALIER
			else if(id_TILE1 == 43 || (ptr_TABLE_ENTREES[id_TILE1].secret == 1 && entree_SECRET_OK == 1) || ptr_TABLE_ENTREES[id_TILE1].secret == 0 || ptr_TABLE_ENTREES[id_TILE1].id == 0 )
			{
				
				id_TILE2 = MAP_getTile( map_COLLISION , (JOUEUR.pt2_X_COLL_DECOR>>3) + TABLE_OFFSET_COLLISION[0][index_X_CARTE] , ((JOUEUR.pt2_Y_COLL_DECOR+1)>>3) + TABLE_OFFSET_COLLISION[1][index_Y_CARTE] );


				// TOUCHE MUR
				// TOUCHE ENTREE SECRETE PAS DECOUVERTE
				// TOUCHE PAS ESCALIER
				if(id_TILE2 == 44 || (ptr_TABLE_ENTREES[id_TILE2].secret == 1 && entree_SECRET_OK == 0 && ptr_TABLE_ENTREES[id_TILE1].id != 0 ) )
				{
					JOUEUR.pos_X_JOUEUR -= 1;
					axe_JOUEUR = GAUCHE;
				}


				// TOUCHE VIDE //
				//else if(id_TILE2 == 43 || (ptr_TABLE_ENTREES[id_TILE2].secret == 1 && entree_SECRET_OK == 1) || ptr_TABLE_ENTREES[id_TILE2].secret == 0 || ptr_TABLE_ENTREES[id_TILE2].id == 0)
				else
				{
					JOUEUR.pos_X_JOUEUR += aligner_JOUEUR(JOUEUR.pos_X_JOUEUR + 4);
					JOUEUR.pos_Y_JOUEUR -= 1;
					axe_JOUEUR = HAUT;
				}
			}




			maj_PT_COLL_DECOR();

			SPR_setPosition(JOUEUR.sprite_JOUEUR, JOUEUR.pos_X_JOUEUR, JOUEUR.pos_Y_JOUEUR);

			SPR_setPosition(sprite_POINT1, JOUEUR.pt1_X_COLL_DECOR, JOUEUR.pt1_Y_COLL_DECOR);
			SPR_setPosition(sprite_POINT2, JOUEUR.pt2_X_COLL_DECOR, JOUEUR.pt2_Y_COLL_DECOR);			
			SPR_setPosition(sprite_POINT3, JOUEUR.pt3_X_COLL_DECOR, JOUEUR.pt3_Y_COLL_DECOR);
			SPR_setPosition(sprite_POINT4, JOUEUR.pt4_X_COLL_DECOR, JOUEUR.pt4_Y_COLL_DECOR);
			
			etat_JOUEUR = MARCHE;

			return;
		}

		//******************************************************//
		//                                                      //
		//                        DROITE                        //
		//                                                      //
		//******************************************************//	
		else if(value & BUTTON_RIGHT)
		{
			//******************************************************//
			//                                                      //
			//                   TEST SORTIE ECRAN                  //
			//                                                      //
			//******************************************************//		
			if(JOUEUR.pos_X_JOUEUR > 232)
			{
				axe_JOUEUR = DROITE;
				duree_SCROLLING = DUREE_SCROLL_H;
				index_X_CARTE += 1;
				
				etat_JEU = SCROLLING_NIVEAU;
				return ;
			}




			//******************************************************//
			//                                                      //
			//			    	  TEST COLLISION					//
			//                                                      //
			//******************************************************//	
			
			id_TILE3 = MAP_getTile( map_COLLISION , (JOUEUR.pt3_X_COLL_DECOR>>3) + TABLE_OFFSET_COLLISION[0][index_X_CARTE] , ((JOUEUR.pt3_Y_COLL_DECOR+1)>>3) + TABLE_OFFSET_COLLISION[1][index_Y_CARTE] );
			id_TILE4 = MAP_getTile( map_COLLISION , (JOUEUR.pt4_X_COLL_DECOR>>3) + TABLE_OFFSET_COLLISION[0][index_X_CARTE] , ((JOUEUR.pt4_Y_COLL_DECOR+1)>>3) + TABLE_OFFSET_COLLISION[1][index_Y_CARTE] );


			//////////////////////////////////////////////////////////
			//			 	  TEST COLLISION ENTREE					//
			//////////////////////////////////////////////////////////

			if(id_TILE3 < 43)
			{
				if(id_TILE4 == id_TILE3)
				{
					if(ptr_TABLE_ENTREES[id_TILE3].secret == 1)
					{
						if(entree_SECRET_OK == 1)
						{
							// TYPE D'ENTREE
							// 0 = ESCALIER
							// 1 = DONJON
							// 2 = PORTE
							id_ENTREE = ptr_TABLE_ENTREES[id_TILE3].id;

							num_ENTREE = id_TILE3;

							afficher_ENTREE();

							// TYPE DE DECOR
							// 0 = NIVEAU
							// 1 = SALLE OU DONJON
							type_DECOR = 1;

							// SEQUENCE ENTREE CAVE
							etat_JEU = ENTREE_CAVE;
							//
							return;
						}
					}

					else
					{
						// TYPE D'ENTREE
						// 0 = ESCALIER
						// 1 = DONJON
						// 2 = PORTE
						id_ENTREE = ptr_TABLE_ENTREES[id_TILE3].id;

						num_ENTREE = id_TILE3;

						afficher_ENTREE();

						// TYPE DE DECOR
						// 0 = NIVEAU
						// 1 = SALLE OU DONJON
						type_DECOR = 1;

						// SEQUENCE ENTREE CAVE
						etat_JEU = ENTREE_CAVE;
						//
						return;						
					}
				}
			}
			
			



			//////////////////////////////////////////////////////////
			//			 	  TEST COLLISION DECOR					//
			//////////////////////////////////////////////////////////

			id_TILE4 = MAP_getTile(   map_COLLISION ,   (JOUEUR.pt4_X_COLL_DECOR>>3) + TABLE_OFFSET_COLLISION[0][index_X_CARTE]   ,   ((JOUEUR.pt4_Y_COLL_DECOR+1)>>3) + TABLE_OFFSET_COLLISION[1][index_Y_CARTE]   );

			// TOUCHE MUR //
			if(id_TILE4 == 44)
			{
				id_TILE2 = MAP_getTile(   map_COLLISION ,   (JOUEUR.pt2_X_COLL_DECOR>>3) + TABLE_OFFSET_COLLISION[0][index_X_CARTE]   ,   ((JOUEUR.pt2_Y_COLL_DECOR+1)>>3) + TABLE_OFFSET_COLLISION[1][index_Y_CARTE]   );

				// TOUCHE VIDE //
				if(id_TILE2 != 44)
				{
					JOUEUR.pos_Y_JOUEUR -= 1;
					axe_JOUEUR = HAUT;
				}
			}

			// TOUCHE VIDE //
			else if(id_TILE4 != 44)
			{
				id_TILE2 = MAP_getTile( map_COLLISION , (JOUEUR.pt2_X_COLL_DECOR>>3) + TABLE_OFFSET_COLLISION[0][index_X_CARTE] , ((JOUEUR.pt2_Y_COLL_DECOR+1)>>3) + TABLE_OFFSET_COLLISION[1][index_Y_CARTE] );

				// TOUCHE MUR //
				if(id_TILE2 == 44)
				{
					JOUEUR.pos_Y_JOUEUR += 1;
					axe_JOUEUR = BAS;
				}

				// TOUCHE VIDE //
				else
				{
					JOUEUR.pos_Y_JOUEUR += aligner_JOUEUR(JOUEUR.pos_Y_JOUEUR + 4);
					JOUEUR.pos_X_JOUEUR += 1;
					axe_JOUEUR = DROITE;
				}
			}

			maj_PT_COLL_DECOR();

			SPR_setPosition(JOUEUR.sprite_JOUEUR, JOUEUR.pos_X_JOUEUR, JOUEUR.pos_Y_JOUEUR);

			SPR_setPosition(sprite_POINT1, JOUEUR.pt1_X_COLL_DECOR, JOUEUR.pt1_Y_COLL_DECOR);
			SPR_setPosition(sprite_POINT2, JOUEUR.pt2_X_COLL_DECOR, JOUEUR.pt2_Y_COLL_DECOR);			
			SPR_setPosition(sprite_POINT3, JOUEUR.pt3_X_COLL_DECOR, JOUEUR.pt3_Y_COLL_DECOR);
			SPR_setPosition(sprite_POINT4, JOUEUR.pt4_X_COLL_DECOR, JOUEUR.pt4_Y_COLL_DECOR);
			
			etat_JOUEUR = MARCHE;

			return;

		}

		//******************************************************//
		//                                                      //
		//                        GAUCHE                        //
		//                                                      //
		//******************************************************//		
		else if(value & BUTTON_LEFT)
		{
			//******************************************************//
			//                                                      //
			//                   TEST SORTIE ECRAN                  //
			//                                                      //
			//******************************************************//			
			if(JOUEUR.pos_X_JOUEUR < -3)
			{
				axe_JOUEUR = GAUCHE;
				duree_SCROLLING = DUREE_SCROLL_H;
				index_X_CARTE -= 1;
				
				etat_JEU = SCROLLING_NIVEAU;
				return ;
			}




			//******************************************************//
			//                                                      //
			//			    	  TEST COLLISION					//
			//                                                      //
			//******************************************************//	
			
			id_TILE3 = MAP_getTile( map_COLLISION , (JOUEUR.pt3_X_COLL_DECOR>>3) + TABLE_OFFSET_COLLISION[0][index_X_CARTE] , ((JOUEUR.pt3_Y_COLL_DECOR+1)>>3) + TABLE_OFFSET_COLLISION[1][index_Y_CARTE] );
			id_TILE4 = MAP_getTile( map_COLLISION , (JOUEUR.pt4_X_COLL_DECOR>>3) + TABLE_OFFSET_COLLISION[0][index_X_CARTE] , ((JOUEUR.pt4_Y_COLL_DECOR+1)>>3) + TABLE_OFFSET_COLLISION[1][index_Y_CARTE] );


			//////////////////////////////////////////////////////////
			//			 	  TEST COLLISION ENTREE					//
			//////////////////////////////////////////////////////////

			if(id_TILE3 < 43)
			{
				if(id_TILE4 == id_TILE3)
				{
					if(ptr_TABLE_ENTREES[id_TILE3].secret == 1)
					{
						if(entree_SECRET_OK == 1)
						{
							// TYPE D'ENTREE
							// 0 = ESCALIER
							// 1 = DONJON
							// 2 = PORTE
							id_ENTREE = ptr_TABLE_ENTREES[id_TILE3].id;

							num_ENTREE = id_TILE3;

							afficher_ENTREE();

							// TYPE DE DECOR
							// 0 = NIVEAU
							// 1 = SALLE OU DONJON
							type_DECOR = 1;

							// SEQUENCE ENTREE CAVE
							etat_JEU = ENTREE_CAVE;
							//
							return;
						}
					}

					else
					{
						// TYPE D'ENTREE
						// 0 = ESCALIER
						// 1 = DONJON
						// 2 = PORTE
						id_ENTREE = ptr_TABLE_ENTREES[id_TILE3].id;

						num_ENTREE = id_TILE3;

						afficher_ENTREE();

						// TYPE DE DECOR
						// 0 = NIVEAU
						// 1 = SALLE OU DONJON
						type_DECOR = 1;

						// SEQUENCE ENTREE CAVE
						etat_JEU = ENTREE_CAVE;
						//
						return;						
					}
				}
			}
			




			//////////////////////////////////////////////////////////
			//			 	  TEST COLLISION DECOR					//
			//////////////////////////////////////////////////////////

			id_TILE3 = MAP_getTile( map_COLLISION , (JOUEUR.pt3_X_COLL_DECOR>>3) + TABLE_OFFSET_COLLISION[0][index_X_CARTE] , ((JOUEUR.pt3_Y_COLL_DECOR+1)>>3) + TABLE_OFFSET_COLLISION[1][index_Y_CARTE] );

			// TOUCHE MUR //
			if(id_TILE3 == 44)
			{
				id_TILE1 = MAP_getTile( map_COLLISION , (JOUEUR.pt1_X_COLL_DECOR>>3) + TABLE_OFFSET_COLLISION[0][index_X_CARTE] , ((JOUEUR.pt1_Y_COLL_DECOR+1)>>3) + TABLE_OFFSET_COLLISION[1][index_Y_CARTE] );

				// TOUCHE VIDE //
				if(id_TILE1 != 44)
				{
					JOUEUR.pos_Y_JOUEUR -= 1;
					axe_JOUEUR = HAUT;
				}
			}

			// TOUCHE VIDE //
			else if(id_TILE3 != 44)
			{
				id_TILE1 = MAP_getTile( map_COLLISION , (JOUEUR.pt1_X_COLL_DECOR>>3) + TABLE_OFFSET_COLLISION[0][index_X_CARTE] , ((JOUEUR.pt1_Y_COLL_DECOR+1)>>3) + TABLE_OFFSET_COLLISION[1][index_Y_CARTE] );

				// TOUCHE MUR //
				if(id_TILE1 == 44)
				{
					JOUEUR.pos_Y_JOUEUR += 1;
					axe_JOUEUR = BAS;
				}

				// TOUCHE VIDE //
				else
				{
					JOUEUR.pos_Y_JOUEUR += aligner_JOUEUR(JOUEUR.pos_Y_JOUEUR + 4);
					JOUEUR.pos_X_JOUEUR -= 1;
					axe_JOUEUR = GAUCHE;
				}
			}

			maj_PT_COLL_DECOR();

			SPR_setPosition(JOUEUR.sprite_JOUEUR, JOUEUR.pos_X_JOUEUR, JOUEUR.pos_Y_JOUEUR);

			SPR_setPosition(sprite_POINT1, JOUEUR.pt1_X_COLL_DECOR, JOUEUR.pt1_Y_COLL_DECOR);
			SPR_setPosition(sprite_POINT2, JOUEUR.pt2_X_COLL_DECOR, JOUEUR.pt2_Y_COLL_DECOR);			
			SPR_setPosition(sprite_POINT3, JOUEUR.pt3_X_COLL_DECOR, JOUEUR.pt3_Y_COLL_DECOR);
			SPR_setPosition(sprite_POINT4, JOUEUR.pt4_X_COLL_DECOR, JOUEUR.pt4_Y_COLL_DECOR);
			
			etat_JOUEUR = MARCHE;

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