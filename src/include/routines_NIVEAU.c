#include <genesis.h>

#include "structures.h"
#include "variables.h"

//#include "tables_DONJONS.h"
#include "tables_ENTREES.h"
#include "tables_JOUEUR.h"
#include "tables_MENU.h"
#include "tables_NIVEAUX.h"
#include "tables_OBJETS_DECOR.h"
//#include "tables_SALLES.h"

#include "boutons_MANETTE.h"
#include "outils.h"

#include "sprites_JEU.h"
#include "sprites_JOUEUR.h"
#include "sprites_MENU.h"

#include "maps_GLOBAL.h"
#include "maps_MENU.h"
#include "maps_NIVEAUX.h"

#include "palettes.h"


//******************************************************//
//                                                      //
//                     OBJET DECOR                      //
//                                                      //
//******************************************************//

inline static void afficher_ENTREE(u16 num)
{
	VDP_loadTileSet(ptr_TABLE_ENTREES[num].adr_Image_ENTREE->tileset, adr_VRAM_ENTREE, DMA);
	VDP_drawImageEx(ptr_TABLE_ENTREES[num].bg , ptr_TABLE_ENTREES[num].adr_Image_ENTREE , TILE_ATTR_FULL(ptr_TABLE_ENTREES[num].pal, ptr_TABLE_ENTREES[num].priorite, FALSE, FALSE, adr_VRAM_ENTREE) , ptr_TABLE_ENTREES[num].pos_X + TABLE_OFFSET_COLLISION[0][index_X_CARTE] , ptr_TABLE_ENTREES[num].pos_Y + TABLE_OFFSET_COLLISION[1][index_Y_CARTE] , FALSE , FALSE );
}




inline static void crea_ROCHER_DECOR()
{
	if(ptr_TABLE_OBJETS_DECOR[index_X_CARTE + ( index_Y_CARTE <<3 )].type == ROCHER)
	{

		s16 offset_POS_X = 0;
		s16 offset_POS_Y = 0;

		if(axe_JOUEUR == BAS)
		{
			offset_POS_Y = 184;
		}
		else if(axe_JOUEUR == HAUT)
		{
			offset_POS_Y = -184;
		}
		else if(axe_JOUEUR == DROITE || axe_JOUEUR == GAUCHE)
		{
			offset_POS_X = 256;
		}


		u8 i = 0;

		for(i=0 ; i<MAX_OBJET_DECOR ; i++)
		{
			if(LISTE_OBJETS_DECOR[i].type != NULL)
			{
				LISTE_OBJETS_DECOR[i].type = ptr_TABLE_OBJETS_DECOR[index_X_CARTE + ( index_Y_CARTE <<3 )].type;


				LISTE_OBJETS_DECOR[i].pos_X = ptr_TABLE_OBJETS_DECOR[index_X_CARTE + ( index_Y_CARTE <<3 )].pos_X + offset_POS_X;
				LISTE_OBJETS_DECOR[i].pos_Y = ptr_TABLE_OBJETS_DECOR[index_X_CARTE + ( index_Y_CARTE <<3 )].pos_Y + offset_POS_Y;

				LISTE_OBJETS_DECOR[i].etat = ptr_TABLE_OBJETS_DECOR[index_X_CARTE + ( index_Y_CARTE <<3 )].etat;
				LISTE_OBJETS_DECOR[i].axe = ptr_TABLE_OBJETS_DECOR[index_X_CARTE + ( index_Y_CARTE <<3 )].axe;


				LISTE_OBJETS_DECOR[i].compteur_ANIM = ptr_TABLE_OBJETS_DECOR[index_X_CARTE + ( index_Y_CARTE <<3 )].compteur_ANIM;
				LISTE_OBJETS_DECOR[i].index_ANIM = ptr_TABLE_OBJETS_DECOR[index_X_CARTE + ( index_Y_CARTE <<3 )].index_ANIM;

				LISTE_OBJETS_DECOR[i].adr_TILES = ptr_TABLE_OBJETS_DECOR[index_X_CARTE + ( index_Y_CARTE <<3 )].adr_TILES;
				
				LISTE_OBJETS_DECOR[i].sprite_OBJET = SPR_addSprite(LISTE_OBJETS_DECOR[i].adr_TILES, LISTE_OBJETS_DECOR[i].pos_X, LISTE_OBJETS_DECOR[i].pos_Y, TILE_ATTR(PAL1, FALSE, FALSE, FALSE));

				nb_OBJET_DECOR += 1;

				objet_ECRAN = ROCHER;

				return;
			}
		}
	}
}


inline static void crea_ARBRE_BRULE()
{
	LISTE_OBJETS_DECOR[0].type = ARBRE;
	LISTE_OBJETS_DECOR[0].pos_X = ptr_TABLE_OBJETS_DECOR[index_X_CARTE + ( index_Y_CARTE <<3 )].pos_X;
	LISTE_OBJETS_DECOR[0].pos_Y = ptr_TABLE_OBJETS_DECOR[index_X_CARTE + ( index_Y_CARTE <<3 )].pos_Y;

	LISTE_OBJETS_DECOR[0].etat = NULL;  // POUR LE ROCHER
	LISTE_OBJETS_DECOR[0].axe = NULL;	// POUR LE ROCHER

	LISTE_OBJETS_DECOR[0].compteur_ANIM = 0;
	LISTE_OBJETS_DECOR[0].index_ANIM = 0;

	LISTE_OBJETS_DECOR[0].adr_TILES = ptr_TABLE_OBJETS_DECOR[index_X_CARTE + ( index_Y_CARTE <<3 )].adr_TILES;

	LISTE_OBJETS_DECOR[0].pal = ptr_TABLE_OBJETS_DECOR[index_X_CARTE + ( index_Y_CARTE <<3 )].pal;


	LISTE_OBJETS_DECOR[0].sprite_OBJET = SPR_addSprite(LISTE_OBJETS_DECOR[0].adr_TILES , LISTE_OBJETS_DECOR[0].pos_X , LISTE_OBJETS_DECOR[0].pos_Y , TILE_ATTR(LISTE_OBJETS_DECOR[0].pal, FALSE, FALSE, FALSE));
	
	nb_OBJET_DECOR += 1;
}


inline static void effacer_OBJET_DECOR_SCROLLING()
{
	if(nb_OBJET_DECOR != 0)
	{
		u8 i = 0;

		for(i=0;i<MAX_OBJET_DECOR;i++)
		{
			if(LISTE_OBJETS_DECOR[i].type != NULL)
			{
				if(LISTE_OBJETS_DECOR[i].pos_X > 255 || LISTE_OBJETS_DECOR[i].pos_X < -15 || LISTE_OBJETS_DECOR[i].pos_Y > 223 || LISTE_OBJETS_DECOR[i].pos_Y < 9)
				{
					SPR_releaseSprite(LISTE_OBJETS_DECOR[i].sprite_OBJET);
					LISTE_OBJETS_DECOR[i].type = NULL;
					nb_OBJET_DECOR -= 1;
					return;
				}
			}
		}
	}
}


inline static void scrolling_OBJET_DECOR(s16 x , s16 y)
{
	if(nb_OBJET_DECOR != 0)
	{
		u8 i = 0;

		for(i=0;i<MAX_OBJET_DECOR;i++)
		{
			if(LISTE_OBJETS_DECOR[i].type != NULL)
			{
				LISTE_OBJETS_DECOR[i].pos_X += x;
				LISTE_OBJETS_DECOR[i].pos_Y += y;

				SPR_setPosition(LISTE_OBJETS_DECOR[i].sprite_OBJET,LISTE_OBJETS_DECOR[i].pos_X,LISTE_OBJETS_DECOR[i].pos_Y);
			}
		}
	}
}




//******************************************************//
//                                                      //
//                        GLOBAL                        //
//                                                      //
//******************************************************//

inline static void maj_SURCHARGE()
{
	if(energie_MAX - nb_ENERGIE > 2)
	{
		surcharge_OK = 0;
	}
	else
	{
		surcharge_OK = 1;
	}
}


inline static void maj_ENERGIE()
{
	u8 i = 0;

	if(nb_ENERGIE %2 == 0)
	{
		for(i=0 ; i<energie_MAX ; i++)
		{
			VDP_setTileMapEx(WINDOW , image_ENERGIE_PLEIN.tilemap, TILE_ATTR_FULL(PAL0, TRUE, FALSE, FALSE, adr_VRAM_ENERGIE_PLEIN), 13 + i, 3, 0, 0, 1, 1, CPU);
		}
	}

	else
	{
		u8 entier = 0;
		//u8 reste = 0;

		entier = nb_ENERGIE >>1<<1;
		//reste = nb_ENERGIE - entier;

		for(i=0 ; i<entier ; i++)
		{
			VDP_setTileMapEx(WINDOW , image_ENERGIE_PLEIN.tilemap, TILE_ATTR_FULL(PAL0, TRUE, FALSE, FALSE, adr_VRAM_ENERGIE_PLEIN), 13 + i, 3, 0, 0, 1, 1, CPU);
		}

		VDP_setTileMapEx(WINDOW , image_ENERGIE_PLEIN.tilemap, TILE_ATTR_FULL(PAL0, TRUE, FALSE, FALSE, adr_VRAM_ENERGIE_MOITIE), 13 + entier, 3, 0, 0, 1, 1, CPU);
	}

}




//******************************************************//
//                                                      //
//                         TIR                          //
//                                                      //
//******************************************************//

void crea_TIR()
{
	u8 i = 0;

	for(i=0 ; i<MAX_TIR ; i++)
	{
		if(LISTE_TIR[i].etat == 0)
		{
			if(axe_JOUEUR == BAS)
			{
				LISTE_TIR[i].pos_X = JOUEUR.pos_X_JOUEUR + 4;
				LISTE_TIR[i].pos_Y = JOUEUR.pos_Y_JOUEUR + 38;

				LISTE_TIR[i].vel_X = 0;
				LISTE_TIR[i].vel_Y = VEL_TIR;
			}

			else if(axe_JOUEUR == HAUT)
			{
				LISTE_TIR[i].pos_X = JOUEUR.pos_X_JOUEUR + 5;
				LISTE_TIR[i].pos_Y = JOUEUR.pos_Y_JOUEUR + 8;

				LISTE_TIR[i].vel_X = 0;
				LISTE_TIR[i].vel_Y = -VEL_TIR;
			}	

			else if(axe_JOUEUR == DROITE)
			{
				LISTE_TIR[i].pos_X = JOUEUR.pos_X_JOUEUR + 22;
				LISTE_TIR[i].pos_Y = JOUEUR.pos_Y_JOUEUR + 19;

				LISTE_TIR[i].vel_X = VEL_TIR;
				LISTE_TIR[i].vel_Y = 0;
			}

			else if(axe_JOUEUR == GAUCHE)
			{
				LISTE_TIR[i].pos_X = JOUEUR.pos_X_JOUEUR - 12;
				LISTE_TIR[i].pos_Y = JOUEUR.pos_Y_JOUEUR + 19;

				LISTE_TIR[i].vel_X = -VEL_TIR;
				LISTE_TIR[i].vel_Y = 0;
			}

			if(LISTE_TIR[i].pos_X > -16 || LISTE_TIR[i].pos_X < 255 || LISTE_TIR[i].pos_Y > 24 || LISTE_TIR[i].pos_Y < 224)
			{

				LISTE_TIR[i].etat = 1;

				LISTE_TIR[i].marge_X = 0;
				LISTE_TIR[i].marge_Y = 0;

				LISTE_TIR[i].compteur_ANIM = 0;
				LISTE_TIR[i].index_ANIM = 0;



				LISTE_TIR[i].sprite_TIR = SPR_addSprite(&tiles_Sprite_TIR, LISTE_TIR[i].pos_X, LISTE_TIR[i].pos_Y, TILE_ATTR(PAL3, FALSE, FALSE, FALSE));
				SPR_setAnim(LISTE_TIR[i].sprite_TIR,0);
				SPR_setFrame(LISTE_TIR[i].sprite_TIR,0);

				nb_TIR += 1;
			}

			return;
		}
	}
}


void collision_TIR()
{
	u8 i = 0;
	
	//**************************************//
	//										//
	//				SORTIE ECRAN			//
	//										//
	//**************************************// 

	// LE JOUEUR A TIRÉ // 
	if(nb_TIR != 0)
	{
		// POUR CHAQUE TIR //
		for(i=0 ; i<MAX_TIR ; i++)
		{
			if(LISTE_TIR[i].etat != 0 && LISTE_TIR[i].etat != 9)
			{
				if(LISTE_TIR[i].pos_X < -16 || LISTE_TIR[i].pos_X > 255 || LISTE_TIR[i].pos_Y < 24 || LISTE_TIR[i].pos_Y > 224)
				{
					LISTE_TIR[i].etat = 0;
					SPR_releaseSprite(LISTE_TIR[i].sprite_TIR);
					nb_TIR -= 1;
				}
			}
		}
	}


	//**************************************//
	//										//
	//			  COLLISION ARBRE			//
	//										//
	//**************************************// 

	// LE JOUEUR A TIRÉ
	if(nb_TIR != 0)
	{
		// L'OBJET DE L'ÉCRAN EN COURS EST UN ARBRE
		if(objet_ECRAN == ARBRE)
		{
			// ENTRÉE SECRETE PAS ENCORE DÉCOUVERTE
			if(entree_SECRET_OK == 0)
			{
				if(arbre_BRULE_OK == 0)
				{
					u16 id_TILE;

					// POUR CHAQUE TIR
					for(i=0 ; i<MAX_TIR ; i++)
					{
						if(LISTE_TIR[i].etat == 1 || LISTE_TIR[i].etat == 2)
						{				
							
							//////////////////////////////////////////////////////////
							//					POINT HAUT GAUCHE					//
							//////////////////////////////////////////////////////////

							// ID DE LA TILE
							id_TILE = MAP_getTile(map_COLLISION , TABLE_OFFSET_COLLISION[0][index_X_CARTE] + ((LISTE_TIR[i].pos_X + MARGE_TIR) >>3) , ( TABLE_OFFSET_COLLISION[1][index_Y_CARTE] + ( (LISTE_TIR[i].pos_Y + MARGE_TIR) >>3 ) ));
						
							// TOUCHE ENTRÉE
							if(id_TILE < TILE_VIDE -1)
							{
								// ENTRÉE SECRETE QUI SE DÉBLOQUE EN BRULANT UN ARBRE
								if( ( ptr_TABLE_ENTREES[id_TILE].secret == 1 && ptr_TABLE_ENTREES[id_TILE].condition == 1  ) )
								{
									// ENTRÉE SECRETE DÉCOUVERTE
									//entree_SECRET_OK = 1;

									num_ENTREE = id_TILE;

									//afficher_ENTREE(num_ENTREE);

									// CREATION SPRITE ARBRE BRULE
									crea_ARBRE_BRULE();

									// L'ARBRE BRULE
									arbre_BRULE_OK = 1;

									return;
								}
							}


							//////////////////////////////////////////////////////////
							//					POINT HAUT DROITE					//
							//////////////////////////////////////////////////////////

							if(LISTE_TIR[i].etat == 1 || LISTE_TIR[i].etat == 2)
							{	
								// ID DE LA TILE
								id_TILE = MAP_getTile(map_COLLISION , TABLE_OFFSET_COLLISION[0][index_X_CARTE] + ((LISTE_TIR[i].pos_X + 16 - MARGE_TIR) >>3) , ( TABLE_OFFSET_COLLISION[1][index_Y_CARTE] + ( (LISTE_TIR[i].pos_Y + MARGE_TIR) >>3 ) ));
							
								// TOUCHE ENTRÉE
								if(id_TILE < TILE_VIDE -1)
								{
									// ENTRÉE SECRETE QUI SE DÉBLOQUE EN BRULANT UN ARBRE
									if( ( ptr_TABLE_ENTREES[id_TILE].secret == 1 && ptr_TABLE_ENTREES[id_TILE].condition == 1  ) )
									{
										// ENTRÉE SECRETE DÉCOUVERTE
										//entree_SECRET_OK = 1;

										num_ENTREE = id_TILE;

										//afficher_ENTREE(num_ENTREE);

										// CREATION SPRITE ARBRE BRULE
										crea_ARBRE_BRULE();

										// L'ARBRE BRULE
										arbre_BRULE_OK = 1;

										return;
									}
								}
							}


								//////////////////////////////////////////////////////////
								//					POINT BAS GAUCHE					//
								//////////////////////////////////////////////////////////

							if(LISTE_TIR[i].etat == 1 || LISTE_TIR[i].etat == 2)
							{	
								// ID DE LA TILE
								id_TILE = MAP_getTile(map_COLLISION , TABLE_OFFSET_COLLISION[0][index_X_CARTE] + ((LISTE_TIR[i].pos_X + MARGE_TIR) >>3) , ( TABLE_OFFSET_COLLISION[1][index_Y_CARTE] + ( (LISTE_TIR[i].pos_Y + 16 - MARGE_TIR) >>3 ) ));
							
								// TOUCHE ENTRÉE
								if(id_TILE < TILE_VIDE -1)
								{
									// ENTRÉE SECRETE QUI SE DÉBLOQUE EN BRULANT UN ARBRE
									if( ( ptr_TABLE_ENTREES[id_TILE].secret == 1 && ptr_TABLE_ENTREES[id_TILE].condition == 1  ) )
									{
										// ENTRÉE SECRETE DÉCOUVERTE
										//entree_SECRET_OK = 1;

										num_ENTREE = id_TILE;

										//afficher_ENTREE(num_ENTREE);

										// CREATION SPRITE ARBRE BRULE
										crea_ARBRE_BRULE();

										// L'ARBRE BRULE
										arbre_BRULE_OK = 1;

										return;
									}
								}
							}


								//////////////////////////////////////////////////////////
								//					POINT BAS DROITE					//
								//////////////////////////////////////////////////////////

							if(LISTE_TIR[i].etat == 1 || LISTE_TIR[i].etat == 2)
							{	
								// ID DE LA TILE
								id_TILE = MAP_getTile(map_COLLISION , TABLE_OFFSET_COLLISION[0][index_X_CARTE] + ((LISTE_TIR[i].pos_X + 16 - MARGE_TIR) >>3) , ( TABLE_OFFSET_COLLISION[1][index_Y_CARTE] + ( (LISTE_TIR[i].pos_Y + 16 - MARGE_TIR) >>3 ) ));
							
								// TOUCHE ENTRÉE
								if(id_TILE < TILE_VIDE -1)
								{
									// ENTRÉE SECRETE QUI SE DÉBLOQUE EN BRULANT UN ARBRE
									if( ( ptr_TABLE_ENTREES[id_TILE].secret == 1 && ptr_TABLE_ENTREES[id_TILE].condition == 1  ) )
									{
										// ENTRÉE SECRETE DÉCOUVERTE
										//entree_SECRET_OK = 1;

										num_ENTREE = id_TILE;

										//afficher_ENTREE(num_ENTREE);

										// CREATION SPRITE ARBRE BRULE
										crea_ARBRE_BRULE();

										// L'ARBRE BRULE
										arbre_BRULE_OK = 1;

										return;
									}
								}
							}
						}
					}
				}
			}
		}
	}




	//**************************************//
	//										//
	//			  COLLISION DECOR			//
	//										//
	//**************************************// 





	//**************************************//
	//										//
	//			  COLLISION JOUEUR			//
	//										//
	//**************************************// 





	//**************************************//
	//										//
	//			  COLLISION ENEMIS			//
	//										//
	//**************************************// 	
	/*
	// COLLISION ENNEMIS
	if(nb_ENNEMIS != 0)
	{
		
	}
	*/
	


}


void anim_TIR()
{
	if(nb_TIR != 0)
	{
		u8 i = 0;

		for(i=0 ; i<MAX_TIR ; i++)
		{
			if(LISTE_TIR[i].etat == 1 || LISTE_TIR[i].etat == 2)
			{
				LISTE_TIR[i].pos_X += LISTE_TIR[i].vel_X;
				LISTE_TIR[i].pos_Y += LISTE_TIR[i].vel_Y;

				SPR_setPosition(LISTE_TIR[i].sprite_TIR , LISTE_TIR[i].pos_X , LISTE_TIR[i].pos_Y );
			}
		}
	}
}


inline static void scrolling_TIR(s16 x , s16 y)
{
	if(nb_TIR != 0)
	{
		u8 i = 0;

		for(i=0;i<MAX_TIR;i++)
		{
			if(LISTE_TIR[i].etat != 0)
			{
				LISTE_TIR[i].pos_X += x;
				LISTE_TIR[i].pos_Y += y;

				SPR_setPosition(LISTE_TIR[i].sprite_TIR,LISTE_TIR[i].pos_X,LISTE_TIR[i].pos_Y);
			}
		}
	}
}


void tiles_TIR()
{
	if(nb_TIR != 0)
	{
		u8 i = 0;

		for(i=0 ; i<MAX_TIR ; i++)
		{
			if(LISTE_TIR[i].etat == 1 ||  LISTE_TIR[i].etat == 2)
			{				
				LISTE_TIR[i].compteur_ANIM += 1;

				if(LISTE_TIR[i].compteur_ANIM == 5)
				{
					LISTE_TIR[i].index_ANIM += 1;
					SPR_setFrame(LISTE_TIR[i].sprite_TIR , LISTE_TIR[i].index_ANIM);
					return;
				}

				else if(LISTE_TIR[i].compteur_ANIM == 10)
				{
					LISTE_TIR[i].index_ANIM += 1;
					SPR_setFrame(LISTE_TIR[i].sprite_TIR , LISTE_TIR[i].index_ANIM);
					return;
				}

				else if(LISTE_TIR[i].compteur_ANIM == 15)
				{
					LISTE_TIR[i].index_ANIM += 1;
					SPR_setFrame(LISTE_TIR[i].sprite_TIR , LISTE_TIR[i].index_ANIM);
					return;
				}

				else if(LISTE_TIR[i].compteur_ANIM == 20)
				{
					LISTE_TIR[i].index_ANIM += 1;
					SPR_setFrame(LISTE_TIR[i].sprite_TIR , LISTE_TIR[i].index_ANIM);
					return;
				}
				
				else if(LISTE_TIR[i].compteur_ANIM == 26)
				{
					LISTE_TIR[i].etat = 9;
					LISTE_TIR[i].compteur_ANIM = 0;
					LISTE_TIR[i].index_ANIM = 0;
					SPR_setAnim(LISTE_TIR[i].sprite_TIR , 1);
					SPR_setFrame(LISTE_TIR[i].sprite_TIR , LISTE_TIR[i].index_ANIM);
					return;
				}
			}
			
			else if(LISTE_TIR[i].etat == 9)
			{
				LISTE_TIR[i].compteur_ANIM += 1;

				if(LISTE_TIR[i].compteur_ANIM == 5)
				{
					LISTE_TIR[i].index_ANIM += 1;
					SPR_setFrame(LISTE_TIR[i].sprite_TIR , LISTE_TIR[i].index_ANIM);
					return;
				}

				else if(LISTE_TIR[i].compteur_ANIM == 10)
				{
					LISTE_TIR[i].index_ANIM += 1;
					SPR_setFrame(LISTE_TIR[i].sprite_TIR , LISTE_TIR[i].index_ANIM);
					return;
				}

				else if(LISTE_TIR[i].compteur_ANIM == 15)
				{
					LISTE_TIR[i].etat = 0;
					SPR_releaseSprite(LISTE_TIR[i].sprite_TIR);
					nb_TIR -= 1;
					return;
				}				//
			}
		}
	}
}


inline static void effacer_TIR()
{
	if(nb_TIR != 0)
	{
		u8 i;

		for(i=0 ; i<MAX_TIR ; i++)
		{
			if(LISTE_TIR[i].etat != 0)
			{
				LISTE_TIR[i].etat = 0;
				SPR_releaseSprite(LISTE_TIR[i].sprite_TIR);
				nb_TIR -= 1;
			}
		}
	}
}




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
//                     NIVEAU GLOBAL                    //
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
		//PAL_setPalette(PAL1, TABLE_ADR_PAL_ENTREES[id_TILE3 + offset_TABLES_ENTREES]->data, DMA);
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


inline static void maj_PT_COLL_DECOR()
{
	JOUEUR.pt1_X_COLL_DECOR = JOUEUR.pos_X_JOUEUR + 7;//4
	JOUEUR.pt1_Y_COLL_DECOR = JOUEUR.pos_Y_JOUEUR + 22;//21

	JOUEUR.pt2_X_COLL_DECOR = JOUEUR.pos_X_JOUEUR + 17;//19
	JOUEUR.pt2_Y_COLL_DECOR = JOUEUR.pos_Y_JOUEUR + 22;//21

	JOUEUR.pt3_X_COLL_DECOR = JOUEUR.pos_X_JOUEUR + 7;//4
	JOUEUR.pt3_Y_COLL_DECOR = JOUEUR.pos_Y_JOUEUR + 31;//32

	JOUEUR.pt4_X_COLL_DECOR = JOUEUR.pos_X_JOUEUR + 17;//19
	JOUEUR.pt4_Y_COLL_DECOR = JOUEUR.pos_Y_JOUEUR + 31;//32
}




//******************************************************//
//                                                      //
//                        ENTREE                        //
//                                                      //
//******************************************************//

inline static void effacer_ENTREE()
{
	u8 id = index_X_CARTE + ( index_Y_CARTE <<3 );
	
	num_ENTREE = ptr_TABLE_ID_ENTREES[id];

	if(ptr_TABLE_ENTREES[num_ENTREE].id != 0)
	{
		VDP_loadTileSet(ptr_TABLE_ENTREES[num_ENTREE].adr_Image_ENTREE->tileset, adr_VRAM_ENTREE, DMA);
		VDP_drawImageEx(ptr_TABLE_ENTREES[num_ENTREE].bg , ptr_TABLE_ENTREES[num_ENTREE].adr_Image_ENTREE , TILE_ATTR_FULL(ptr_TABLE_ENTREES[num_ENTREE].pal, FALSE, FALSE, FALSE, adr_VRAM_ENTREE) , ptr_TABLE_ENTREES[num_ENTREE].pos_X + TABLE_OFFSET_COLLISION[0][index_X_CARTE] , ptr_TABLE_ENTREES[num_ENTREE].pos_Y + TABLE_OFFSET_COLLISION[1][index_Y_CARTE] , FALSE , FALSE );
	}

	entree_SECRET_OK = 0;	
}


inline static void effacer_ENTREE_CACHEE()
{
	if(entree_SECRET_OK == 1)
	{
		s8 offset_Y_CARTE = 0;
		s16 offset_Y_TILEMAP = 0;

		if(axe_JOUEUR == BAS)
		{
			offset_Y_CARTE = -1;
			offset_Y_TILEMAP = -23;
		}
		else if(axe_JOUEUR == HAUT)
		{
			offset_Y_CARTE = 1;
			offset_Y_TILEMAP = 23;
		}

		

		if(axe_JOUEUR == BAS || axe_JOUEUR == HAUT)
		{
			u8 index = index_X_CARTE + ( (index_Y_CARTE + offset_Y_CARTE) <<3 );
			
			if( ptr_TABLE_ID_ENTREES[index] != NULL )
			{
				num_ENTREE = ptr_TABLE_ID_ENTREES[index];

				if(ptr_TABLE_ENTREES[num_ENTREE].secret == 1)
				{
					VDP_loadTileSet(ptr_TABLE_ENTREES[num_ENTREE].adr_Image_CACHE->tileset, adr_VRAM_ENTREE, DMA);
					VDP_drawImageEx(ptr_TABLE_ENTREES[num_ENTREE].bg , ptr_TABLE_ENTREES[num_ENTREE].adr_Image_CACHE , TILE_ATTR_FULL(ptr_TABLE_ENTREES[num_ENTREE].pal, FALSE, FALSE, FALSE, adr_VRAM_ENTREE) , ptr_TABLE_ENTREES[num_ENTREE].pos_X + TABLE_OFFSET_COLLISION[0][index_X_CARTE] , ptr_TABLE_ENTREES[num_ENTREE].pos_Y + TABLE_OFFSET_COLLISION[1][index_Y_CARTE] + offset_Y_TILEMAP , FALSE , FALSE );
				}
			}
		}

		entree_SECRET_OK = 0;
	}

	
}




//******************************************************//
//                                                      //
//                        NIVEAU                        //
//                                                      //
//******************************************************//

inline static void sauvegarder_VARIABLES_NIVEAU()
{
	pos_X_CAM_NIVEAU = pos_X_CAM;
	pos_Y_CAM_NIVEAU = pos_Y_CAM;

	index_X_CARTE_NIVEAU = index_X_CARTE;
	index_Y_CARTE_NIVEAU = index_Y_CARTE;
}


void scrolling_ECRAN_NIVEAU()
{
	//////////////////////////////////////////////////////////
    //                         BAS                          //
    //////////////////////////////////////////////////////////
	if(axe_JOUEUR == BAS)
	{
		pos_Y_CAM += 4;
		JOUEUR.pos_Y_JOUEUR -= 4;

		scrolling_OBJET_DECOR(0,-4);
		scrolling_TIR(0,-4);
	}

	//////////////////////////////////////////////////////////
    //                         HAUT                         //
    //////////////////////////////////////////////////////////
	else if(axe_JOUEUR == HAUT)
	{
		pos_Y_CAM -= 4;
		JOUEUR.pos_Y_JOUEUR += 4;

		scrolling_OBJET_DECOR(0,4);
		scrolling_TIR(0,4);
	}

	//////////////////////////////////////////////////////////
    //                        DROITE                        //
    //////////////////////////////////////////////////////////
	else if(axe_JOUEUR == DROITE)
	{
		pos_X_CAM += 4;
		JOUEUR.pos_X_JOUEUR -= 4;

		scrolling_OBJET_DECOR(-4,0);
		scrolling_TIR(-4,0);
	}

	//////////////////////////////////////////////////////////
    //                        GAUCHE                        //
    //////////////////////////////////////////////////////////
	else if(axe_JOUEUR == GAUCHE)
	{
		pos_X_CAM -= 4;
		JOUEUR.pos_X_JOUEUR += 4;

		scrolling_OBJET_DECOR(4,0);
		scrolling_TIR(4,0);
	}


	MAP_scrollTo(map_NIVEAU_BG_B, pos_X_CAM, pos_Y_CAM);
	MAP_scrollTo(map_NIVEAU_BG_A, pos_X_CAM, pos_Y_CAM);


	SPR_setPosition(JOUEUR.sprite_JOUEUR, JOUEUR.pos_X_JOUEUR, JOUEUR.pos_Y_JOUEUR);


	compteur_SCROLLING += 1;

	if(compteur_SCROLLING > duree_SCROLLING)
	{		
		compteur_SCROLLING = 0;
		effacer_TIR();
		effacer_OBJET_DECOR_SCROLLING();
		etat_JEU = FIN_SCROLLING_NIVEAU;
	}
}


void sortie_SCROLLING_NIVEAU()
{
	if(axe_JOUEUR == BAS)
	{
		if(JOUEUR.pos_Y_JOUEUR < 28)
		{
			JOUEUR.pos_Y_JOUEUR += 1;
			maj_PT_COLL_DECOR();


			SPR_setPosition(JOUEUR.sprite_JOUEUR, JOUEUR.pos_X_JOUEUR, JOUEUR.pos_Y_JOUEUR);

			//SPR_setPosition(sprite_POINT1, JOUEUR.pt1_X_COLL_DECOR, JOUEUR.pt1_Y_COLL_DECOR);
			//SPR_setPosition(sprite_POINT2, JOUEUR.pt2_X_COLL_DECOR, JOUEUR.pt2_Y_COLL_DECOR);			
			//SPR_setPosition(sprite_POINT3, JOUEUR.pt3_X_COLL_DECOR, JOUEUR.pt3_Y_COLL_DECOR);
			//SPR_setPosition(sprite_POINT4, JOUEUR.pt4_X_COLL_DECOR, JOUEUR.pt4_Y_COLL_DECOR);

			etat_JOUEUR = MARCHE;
			return;			
		}

		else
		{
			afficher_MENU(type_DECOR);
			effacer_ENTREE_CACHEE();
			maj_PT_COLL_DECOR();

			etat_JOUEUR = MARCHE;
			etat_JEU = NIVEAU;
			return;	
		}
	}


	else if(axe_JOUEUR == HAUT)
	{
		if(JOUEUR.pos_Y_JOUEUR > 195)
		{
			JOUEUR.pos_Y_JOUEUR -= 1;
			maj_PT_COLL_DECOR();


			SPR_setPosition(JOUEUR.sprite_JOUEUR, JOUEUR.pos_X_JOUEUR, JOUEUR.pos_Y_JOUEUR);

			//SPR_setPosition(sprite_POINT1, JOUEUR.pt1_X_COLL_DECOR, JOUEUR.pt1_Y_COLL_DECOR);
			//SPR_setPosition(sprite_POINT2, JOUEUR.pt2_X_COLL_DECOR, JOUEUR.pt2_Y_COLL_DECOR);			
			//SPR_setPosition(sprite_POINT3, JOUEUR.pt3_X_COLL_DECOR, JOUEUR.pt3_Y_COLL_DECOR);
			//SPR_setPosition(sprite_POINT4, JOUEUR.pt4_X_COLL_DECOR, JOUEUR.pt4_Y_COLL_DECOR);

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

			//SPR_setPosition(sprite_POINT1, JOUEUR.pt1_X_COLL_DECOR, JOUEUR.pt1_Y_COLL_DECOR);
			//SPR_setPosition(sprite_POINT2, JOUEUR.pt2_X_COLL_DECOR, JOUEUR.pt2_Y_COLL_DECOR);			
			//SPR_setPosition(sprite_POINT3, JOUEUR.pt3_X_COLL_DECOR, JOUEUR.pt3_Y_COLL_DECOR);
			//SPR_setPosition(sprite_POINT4, JOUEUR.pt4_X_COLL_DECOR, JOUEUR.pt4_Y_COLL_DECOR);

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

			//SPR_setPosition(sprite_POINT1, JOUEUR.pt1_X_COLL_DECOR, JOUEUR.pt1_Y_COLL_DECOR);
			//SPR_setPosition(sprite_POINT2, JOUEUR.pt2_X_COLL_DECOR, JOUEUR.pt2_Y_COLL_DECOR);			
			//SPR_setPosition(sprite_POINT3, JOUEUR.pt3_X_COLL_DECOR, JOUEUR.pt3_Y_COLL_DECOR);
			//SPR_setPosition(sprite_POINT4, JOUEUR.pt4_X_COLL_DECOR, JOUEUR.pt4_Y_COLL_DECOR);

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




void manette_JOUEUR_NIVEAU()
{
	u16 value=JOY_readJoypad(JOY_1);

	//////////////////////////////////////////////////////////
	//                  SI PAS TIR OU TOUCHE                //
	//////////////////////////////////////////////////////////
	if(etat_JOUEUR != ATTAQUE && etat_JOUEUR != TOUCHE && etat_JOUEUR != TIR_BAGUETTE)
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
			if(JOUEUR.pos_Y_JOUEUR > 194+3)
			{
				axe_JOUEUR = BAS;
				duree_SCROLLING = DUREE_SCROLL_V;
				index_Y_CARTE += 1;
				arbre_BRULE_OK = 0;
				entree_SECRET_OK = 0;

				objet_ECRAN = ptr_TABLE_OBJETS_DECOR[index_X_CARTE + ( index_Y_CARTE <<3 )].type;

				//crea_ROCHER_DECOR();
				
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

			if(id_TILE3 < TILE_VIDE-1)
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
							// 2 = CAVE
							id_ENTREE = ptr_TABLE_ENTREES[id_TILE3].id;

							num_ENTREE = id_TILE3;

							afficher_ENTREE(num_ENTREE);

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

						afficher_ENTREE(num_ENTREE);

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

			// TOUCHE MUR
			// TOUCHE ENTREE SECRETE PAS DECOUVERTE ET BLOQUANTE
			if(id_TILE3 == TILE_MUR || (ptr_TABLE_ENTREES[id_TILE3].secret == 1 && entree_SECRET_OK == 0 && ptr_TABLE_ENTREES[id_TILE3].bloque == 1 && id_TILE3 < TILE_VIDE ))
			{
				id_TILE4 = MAP_getTile( map_COLLISION , (JOUEUR.pt4_X_COLL_DECOR>>3) + TABLE_OFFSET_COLLISION[0][index_X_CARTE] , ((JOUEUR.pt4_Y_COLL_DECOR+1)>>3) + TABLE_OFFSET_COLLISION[1][index_Y_CARTE] );

				// TOUCHE VIDE
				// TOUCHE ENTREE SECRETE DECOUVERTE
				// TOUCHE ENTREE PAS SECRETE
				// TOUCHE ENTREE PAS BLOQUANTE
				if(id_TILE4 == TILE_VIDE || (ptr_TABLE_ENTREES[id_TILE4].secret == 1 && entree_SECRET_OK == 1 && id_TILE4 < TILE_VIDE) || (ptr_TABLE_ENTREES[id_TILE4].secret == 0 && id_TILE4 < TILE_VIDE) || (ptr_TABLE_ENTREES[id_TILE4].bloque == 0 && id_TILE4 < TILE_VIDE ))
				{
					JOUEUR.pos_X_JOUEUR += 1;
					axe_JOUEUR = DROITE;
				}
			}

			// TOUCHE VIDE
			// TOUCHE ENTREE SECRETE DECOUVERTE
			// TOUCHE ENTREE PAS SECRETE
			// TOUCHE ENTREE PAS BLOQUANTE
			else if(id_TILE3 == TILE_VIDE || (ptr_TABLE_ENTREES[id_TILE3].secret == 1 && entree_SECRET_OK == 1 && id_TILE3 < TILE_VIDE) || (ptr_TABLE_ENTREES[id_TILE3].secret == 0 && id_TILE3 < TILE_VIDE) || (ptr_TABLE_ENTREES[id_TILE3].bloque == 0 && id_TILE3 < TILE_VIDE ))
			{
				id_TILE4 = MAP_getTile( map_COLLISION , (JOUEUR.pt4_X_COLL_DECOR>>3) + TABLE_OFFSET_COLLISION[0][index_X_CARTE] , ((JOUEUR.pt4_Y_COLL_DECOR+1)>>3) + TABLE_OFFSET_COLLISION[1][index_Y_CARTE] );

				// TOUCHE MUR
				// TOUCHE ENTREE SECRETE PAS DECOUVERTE ET BLOQUANTE
				if(id_TILE4 == TILE_MUR || (ptr_TABLE_ENTREES[id_TILE4].secret == 1 && entree_SECRET_OK == 0 && ptr_TABLE_ENTREES[id_TILE4].bloque == 1 && id_TILE4 < TILE_VIDE ))
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

			//SPR_setPosition(sprite_POINT1, JOUEUR.pt1_X_COLL_DECOR, JOUEUR.pt1_Y_COLL_DECOR);
			//SPR_setPosition(sprite_POINT2, JOUEUR.pt2_X_COLL_DECOR, JOUEUR.pt2_Y_COLL_DECOR);			
			//SPR_setPosition(sprite_POINT3, JOUEUR.pt3_X_COLL_DECOR, JOUEUR.pt3_Y_COLL_DECOR);
			//SPR_setPosition(sprite_POINT4, JOUEUR.pt4_X_COLL_DECOR, JOUEUR.pt4_Y_COLL_DECOR);
			
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
				arbre_BRULE_OK = 0;
				entree_SECRET_OK = 0;

				objet_ECRAN = ptr_TABLE_OBJETS_DECOR[index_X_CARTE + ( index_Y_CARTE <<3 )].type;

				//crea_ROCHER_DECOR();
				
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

			if(id_TILE3 < TILE_VIDE -1)
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

							afficher_ENTREE(num_ENTREE);

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

						afficher_ENTREE(num_ENTREE);

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
			// TOUCHE ENTREE SECRETE PAS DECOUVERTE ET BLOQUANTE
			if(id_TILE1 == TILE_MUR || (ptr_TABLE_ENTREES[id_TILE1].secret == 1 && entree_SECRET_OK == 0 && ptr_TABLE_ENTREES[id_TILE1].bloque == 1 && id_TILE1 < TILE_VIDE ) ) 
			{
				
				id_TILE2 = MAP_getTile( map_COLLISION , (JOUEUR.pt2_X_COLL_DECOR>>3) + TABLE_OFFSET_COLLISION[0][index_X_CARTE] , ((JOUEUR.pt2_Y_COLL_DECOR+1)>>3) + TABLE_OFFSET_COLLISION[1][index_Y_CARTE] );


				// TOUCHE VIDE
				// TOUCHE ENTREE SECRETE DECOUVERTE
				// TOUCHE ENTREE PAS SECRETE
				// TOUCHE ENTREE PAS BLOQUANTE
				if(id_TILE2 == TILE_VIDE || (ptr_TABLE_ENTREES[id_TILE2].secret == 1 && entree_SECRET_OK == 1 && id_TILE2 < TILE_VIDE) || (ptr_TABLE_ENTREES[id_TILE2].secret == 0 && id_TILE2 < TILE_VIDE) || (ptr_TABLE_ENTREES[id_TILE2].bloque == 0 && id_TILE2 < TILE_VIDE ))
				{
					JOUEUR.pos_X_JOUEUR += 1;
					axe_JOUEUR = DROITE;
				}
			}

			// TOUCHE VIDE
			// TOUCHE ENTREE SECRETE DECOUVERTE
			// TOUCHE ENTREE PAS SECRETE
			// TOUCHE ENTREE PAS BLOQUANTE
			else if(id_TILE1 == TILE_VIDE || (ptr_TABLE_ENTREES[id_TILE1].secret == 1 && entree_SECRET_OK == 1 && id_TILE1 < TILE_VIDE) || (ptr_TABLE_ENTREES[id_TILE1].secret == 0 && id_TILE1 < TILE_VIDE) || (ptr_TABLE_ENTREES[id_TILE1].bloque == 0 && id_TILE1 < TILE_VIDE ))
			{
				
				id_TILE2 = MAP_getTile( map_COLLISION , (JOUEUR.pt2_X_COLL_DECOR>>3) + TABLE_OFFSET_COLLISION[0][index_X_CARTE] , ((JOUEUR.pt2_Y_COLL_DECOR+1)>>3) + TABLE_OFFSET_COLLISION[1][index_Y_CARTE] );


				// TOUCHE MUR
				// TOUCHE ENTREE SECRETE PAS DECOUVERTE ET BLOQUANTE
				if(id_TILE2 == TILE_MUR || (ptr_TABLE_ENTREES[id_TILE2].secret == 1 && entree_SECRET_OK == 0 && ptr_TABLE_ENTREES[id_TILE2].bloque == 1 && id_TILE2 < TILE_VIDE ) )
				{
					JOUEUR.pos_X_JOUEUR -= 1;
					axe_JOUEUR = GAUCHE;
				}


				// TOUCHE VIDE //
				else
				{
					JOUEUR.pos_X_JOUEUR += aligner_JOUEUR(JOUEUR.pos_X_JOUEUR + 4);
					JOUEUR.pos_Y_JOUEUR -= 1;
					axe_JOUEUR = HAUT;
				}
			}




			maj_PT_COLL_DECOR();

			SPR_setPosition(JOUEUR.sprite_JOUEUR, JOUEUR.pos_X_JOUEUR, JOUEUR.pos_Y_JOUEUR);

			//SPR_setPosition(sprite_POINT1, JOUEUR.pt1_X_COLL_DECOR, JOUEUR.pt1_Y_COLL_DECOR);
			//SPR_setPosition(sprite_POINT2, JOUEUR.pt2_X_COLL_DECOR, JOUEUR.pt2_Y_COLL_DECOR);			
			//SPR_setPosition(sprite_POINT3, JOUEUR.pt3_X_COLL_DECOR, JOUEUR.pt3_Y_COLL_DECOR);
			//SPR_setPosition(sprite_POINT4, JOUEUR.pt4_X_COLL_DECOR, JOUEUR.pt4_Y_COLL_DECOR);
			
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
				arbre_BRULE_OK = 0;
				entree_SECRET_OK = 0;

				objet_ECRAN = ptr_TABLE_OBJETS_DECOR[index_X_CARTE + ( index_Y_CARTE <<3 )].type;

				//crea_ROCHER_DECOR();
				
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

			if(id_TILE3 < TILE_VIDE -1)
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

							afficher_ENTREE(num_ENTREE);

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

						afficher_ENTREE(num_ENTREE);

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
			if(id_TILE4 == TILE_MUR || (ptr_TABLE_ENTREES[id_TILE4].secret == 1 && entree_SECRET_OK == 0 && ptr_TABLE_ENTREES[id_TILE4].bloque == 1 && id_TILE4 < TILE_VIDE ) ) 
			{
				id_TILE2 = MAP_getTile(   map_COLLISION ,   (JOUEUR.pt2_X_COLL_DECOR>>3) + TABLE_OFFSET_COLLISION[0][index_X_CARTE]   ,   ((JOUEUR.pt2_Y_COLL_DECOR+1)>>3) + TABLE_OFFSET_COLLISION[1][index_Y_CARTE]   );

				// TOUCHE VIDE //
				if(id_TILE2 == TILE_VIDE || (ptr_TABLE_ENTREES[id_TILE2].secret == 1 && entree_SECRET_OK == 1 && id_TILE2 < TILE_VIDE) || (ptr_TABLE_ENTREES[id_TILE2].secret == 0 && id_TILE2 < TILE_VIDE) || (ptr_TABLE_ENTREES[id_TILE2].bloque == 0 && id_TILE2 < TILE_VIDE ))
				{
					JOUEUR.pos_Y_JOUEUR -= 1;
					axe_JOUEUR = HAUT;
				}
			}

			// TOUCHE VIDE //
			else if(id_TILE4 == TILE_VIDE || (ptr_TABLE_ENTREES[id_TILE4].secret == 1 && entree_SECRET_OK == 1 && id_TILE4 < TILE_VIDE) || (ptr_TABLE_ENTREES[id_TILE4].secret == 0 && id_TILE4 < TILE_VIDE) || (ptr_TABLE_ENTREES[id_TILE4].bloque == 0 && id_TILE4 < TILE_VIDE ))
			{
				id_TILE2 = MAP_getTile( map_COLLISION , (JOUEUR.pt2_X_COLL_DECOR>>3) + TABLE_OFFSET_COLLISION[0][index_X_CARTE] , ((JOUEUR.pt2_Y_COLL_DECOR+1)>>3) + TABLE_OFFSET_COLLISION[1][index_Y_CARTE] );

				// TOUCHE MUR //
				if(id_TILE2 == TILE_MUR || (ptr_TABLE_ENTREES[id_TILE2].secret == 1 && entree_SECRET_OK == 0 && ptr_TABLE_ENTREES[id_TILE2].bloque == 1 && id_TILE2 < TILE_VIDE ) ) 
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

			//SPR_setPosition(sprite_POINT1, JOUEUR.pt1_X_COLL_DECOR, JOUEUR.pt1_Y_COLL_DECOR);
			//SPR_setPosition(sprite_POINT2, JOUEUR.pt2_X_COLL_DECOR, JOUEUR.pt2_Y_COLL_DECOR);			
			//SPR_setPosition(sprite_POINT3, JOUEUR.pt3_X_COLL_DECOR, JOUEUR.pt3_Y_COLL_DECOR);
			//SPR_setPosition(sprite_POINT4, JOUEUR.pt4_X_COLL_DECOR, JOUEUR.pt4_Y_COLL_DECOR);
			
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
				arbre_BRULE_OK = 0;
				entree_SECRET_OK = 0;

				objet_ECRAN = ptr_TABLE_OBJETS_DECOR[index_X_CARTE + ( index_Y_CARTE <<3 )].type;

				//crea_ROCHER_DECOR();
				
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

			if(id_TILE3 < TILE_VIDE -1)
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

							afficher_ENTREE(num_ENTREE);

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

						afficher_ENTREE(num_ENTREE);

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
			if(id_TILE3 == TILE_MUR || (ptr_TABLE_ENTREES[id_TILE3].secret == 1 && entree_SECRET_OK == 0 && ptr_TABLE_ENTREES[id_TILE3].bloque == 1 && id_TILE3 < TILE_VIDE ) ) 
			{
				id_TILE1 = MAP_getTile( map_COLLISION , (JOUEUR.pt1_X_COLL_DECOR>>3) + TABLE_OFFSET_COLLISION[0][index_X_CARTE] , ((JOUEUR.pt1_Y_COLL_DECOR+1)>>3) + TABLE_OFFSET_COLLISION[1][index_Y_CARTE] );

				// TOUCHE VIDE //
				if(id_TILE1 == TILE_VIDE || (ptr_TABLE_ENTREES[id_TILE1].secret == 1 && entree_SECRET_OK == 1 && id_TILE1 < TILE_VIDE) || (ptr_TABLE_ENTREES[id_TILE1].secret == 0 && id_TILE1 < TILE_VIDE) || (ptr_TABLE_ENTREES[id_TILE1].bloque == 0 && id_TILE1 < TILE_VIDE ))
				{
					JOUEUR.pos_Y_JOUEUR -= 1;
					axe_JOUEUR = HAUT;
				}
			}

			// TOUCHE VIDE //
			else if(id_TILE3 == TILE_VIDE || (ptr_TABLE_ENTREES[id_TILE3].secret == 1 && entree_SECRET_OK == 1 && id_TILE3 < TILE_VIDE) || (ptr_TABLE_ENTREES[id_TILE3].secret == 0 && id_TILE3 < TILE_VIDE) || (ptr_TABLE_ENTREES[id_TILE3].bloque == 0 && id_TILE3 < TILE_VIDE ))
			{
				id_TILE1 = MAP_getTile( map_COLLISION , (JOUEUR.pt1_X_COLL_DECOR>>3) + TABLE_OFFSET_COLLISION[0][index_X_CARTE] , ((JOUEUR.pt1_Y_COLL_DECOR+1)>>3) + TABLE_OFFSET_COLLISION[1][index_Y_CARTE] );

				// TOUCHE MUR //
				if(id_TILE1 == TILE_MUR || (ptr_TABLE_ENTREES[id_TILE1].secret == 1 && entree_SECRET_OK == 0 && ptr_TABLE_ENTREES[id_TILE1].bloque == 1 && id_TILE1 < TILE_VIDE ) ) 
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

			//SPR_setPosition(sprite_POINT1, JOUEUR.pt1_X_COLL_DECOR, JOUEUR.pt1_Y_COLL_DECOR);
			//SPR_setPosition(sprite_POINT2, JOUEUR.pt2_X_COLL_DECOR, JOUEUR.pt2_Y_COLL_DECOR);			
			//SPR_setPosition(sprite_POINT3, JOUEUR.pt3_X_COLL_DECOR, JOUEUR.pt3_Y_COLL_DECOR);
			//SPR_setPosition(sprite_POINT4, JOUEUR.pt4_X_COLL_DECOR, JOUEUR.pt4_Y_COLL_DECOR);
			
			etat_JOUEUR = MARCHE;

			return;

		}
	}
}




//******************************************************//
//                                                      //
//                         TILES                        //
//                                                      //
//******************************************************//

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
		JOUEUR.compteur_ATTAQUE += 1;
		
		if(JOUEUR.compteur_ATTAQUE == 1)
		{
			SPR_setPosition(JOUEUR.sprite_EPEE, JOUEUR.pos_X_JOUEUR + TABLE_POS_EPEE[0][axe_JOUEUR], JOUEUR.pos_Y_JOUEUR +  + TABLE_POS_EPEE[1][axe_JOUEUR]);

			SPR_setAnim(JOUEUR.sprite_EPEE,axe_JOUEUR);

			SPR_setAnim(JOUEUR.sprite_JOUEUR,axe_JOUEUR + 4);
			SPR_setFrame(JOUEUR.sprite_JOUEUR,0);
		}	

		else if(JOUEUR.compteur_ATTAQUE == 8)
		{
			SPR_setFrame(JOUEUR.sprite_JOUEUR,1);
			SPR_setPosition(JOUEUR.sprite_EPEE, 0, -16);
		}

		else if(JOUEUR.compteur_ATTAQUE == 16)
		{
			JOUEUR.compteur_ATTAQUE = 0;
			etat_JOUEUR = ARRET;
		}		
	}

	//////////////////////////////////////////////////////////
	//                      TIR BAGUETTE                    //
	//////////////////////////////////////////////////////////
	else if(etat_JOUEUR == TIR_BAGUETTE)
	{
		JOUEUR.compteur_ATTAQUE += 1;
		
		if(JOUEUR.compteur_ATTAQUE == 1)
		{
			SPR_setAnim(JOUEUR.sprite_JOUEUR,axe_JOUEUR + 4);
			SPR_setFrame(JOUEUR.sprite_JOUEUR,2);
		}

		else if(JOUEUR.compteur_ATTAQUE == 10)
		{
			SPR_setFrame(JOUEUR.sprite_JOUEUR,3);
		}

		else if(JOUEUR.compteur_ATTAQUE == 20)
		{
			JOUEUR.compteur_ATTAQUE = 0;
			etat_JOUEUR = ARRET;
		}	
	}

}


void tiles_EAU_NIVEAU()
{
	if(compteur_EAU == 0)
	{
		ptr_TABLE_EAU = TABLE_ADR_EAU_NIVEAUX[num_NIVEAU][0];
		VDP_loadTileSet(ptr_TABLE_EAU->tileset, adr_VRAM_BG_B, CPU);
	}

	else if(compteur_EAU == 29)
	{
		ptr_TABLE_EAU = TABLE_ADR_EAU_NIVEAUX[num_NIVEAU][1];
		VDP_loadTileSet(ptr_TABLE_EAU->tileset, adr_VRAM_BG_B, CPU);
	}

	else if(compteur_EAU == 59)
	{
		ptr_TABLE_EAU = TABLE_ADR_EAU_NIVEAUX[num_NIVEAU][2];
		VDP_loadTileSet(ptr_TABLE_EAU->tileset, adr_VRAM_BG_B, CPU);
	}

	else if(compteur_EAU == 89)
	{
		ptr_TABLE_EAU = TABLE_ADR_EAU_NIVEAUX[num_NIVEAU][3];;
		VDP_loadTileSet(ptr_TABLE_EAU->tileset, adr_VRAM_BG_B, CPU);
	}

	compteur_EAU += 1;

	if(compteur_EAU == 118)
	{
		compteur_EAU = 0;
	}
}


void tiles_CASCADE_NIVEAU()
{
	// LES 4 PREMIERS TILES DU BG_B
	// SONT RESERVEES AUX TILES DE L'EAU
	// DONC ON AJOUTE 4 A L'ADRESSE VRAM
	
	if(compteur_CASCADE == 0)
	{
		ptr_TABLE_CASCADE = TABLE_ADR_CASCADE_NIVEAUX[num_NIVEAU][0];
		VDP_loadTileSet(ptr_TABLE_CASCADE->tileset, adr_VRAM_BG_B + 5, CPU);
	}

	else if(compteur_CASCADE == 9)
	{
		ptr_TABLE_CASCADE = TABLE_ADR_CASCADE_NIVEAUX[num_NIVEAU][1];
		VDP_loadTileSet(ptr_TABLE_CASCADE->tileset, adr_VRAM_BG_B + 5, CPU);
	}

	else if(compteur_CASCADE == 19)
	{
		ptr_TABLE_CASCADE = TABLE_ADR_CASCADE_NIVEAUX[num_NIVEAU][2];
		VDP_loadTileSet(ptr_TABLE_CASCADE->tileset, adr_VRAM_BG_B + 5, CPU);
	}

	else if(compteur_CASCADE == 29)
	{
		ptr_TABLE_CASCADE = TABLE_ADR_CASCADE_NIVEAUX[num_NIVEAU][3];;
		VDP_loadTileSet(ptr_TABLE_CASCADE->tileset, adr_VRAM_BG_B + 5, CPU);
	}

	compteur_CASCADE += 1;

	if(compteur_CASCADE == 38)
	{
		compteur_CASCADE = 0;
	}
}


void tiles_ARBRE_BRULE()
{
	// SI L'ARBRE BRULE
	if(arbre_BRULE_OK == 1)
	{
		if(LISTE_OBJETS_DECOR[0].compteur_ANIM == 1)
		{
			LISTE_OBJETS_DECOR[0].index_ANIM += 1;
			SPR_setFrame(LISTE_OBJETS_DECOR[0].sprite_OBJET,LISTE_OBJETS_DECOR[0].index_ANIM);
		}

		else if(LISTE_OBJETS_DECOR[0].compteur_ANIM == 6)
		{
			LISTE_OBJETS_DECOR[0].index_ANIM += 1;
			SPR_setFrame(LISTE_OBJETS_DECOR[0].sprite_OBJET,LISTE_OBJETS_DECOR[0].index_ANIM);
		}

		else if(LISTE_OBJETS_DECOR[0].compteur_ANIM == 11)
		{
			LISTE_OBJETS_DECOR[0].index_ANIM += 1;
			SPR_setFrame(LISTE_OBJETS_DECOR[0].sprite_OBJET,LISTE_OBJETS_DECOR[0].index_ANIM);
		}

		else if(LISTE_OBJETS_DECOR[0].compteur_ANIM == 16)
		{
			LISTE_OBJETS_DECOR[0].index_ANIM += 1;
			SPR_setFrame(LISTE_OBJETS_DECOR[0].sprite_OBJET,LISTE_OBJETS_DECOR[0].index_ANIM);
		}

		else if(LISTE_OBJETS_DECOR[0].compteur_ANIM == 21)
		{
			LISTE_OBJETS_DECOR[0].index_ANIM += 1;
			SPR_setFrame(LISTE_OBJETS_DECOR[0].sprite_OBJET,LISTE_OBJETS_DECOR[0].index_ANIM);
		}

		else if(LISTE_OBJETS_DECOR[0].compteur_ANIM == 26)
		{
			LISTE_OBJETS_DECOR[0].index_ANIM += 1;
			SPR_setFrame(LISTE_OBJETS_DECOR[0].sprite_OBJET,LISTE_OBJETS_DECOR[0].index_ANIM);

			entree_SECRET_OK = 1;
			afficher_ENTREE(num_ENTREE);
		}

		else if(LISTE_OBJETS_DECOR[0].compteur_ANIM == 31)
		{
			LISTE_OBJETS_DECOR[0].index_ANIM += 1;
			SPR_setFrame(LISTE_OBJETS_DECOR[0].sprite_OBJET,LISTE_OBJETS_DECOR[0].index_ANIM);
		}

		else if(LISTE_OBJETS_DECOR[0].compteur_ANIM == 36)
		{
			LISTE_OBJETS_DECOR[0].index_ANIM += 1;
			SPR_setFrame(LISTE_OBJETS_DECOR[0].sprite_OBJET,LISTE_OBJETS_DECOR[0].index_ANIM);
		}

		else if(LISTE_OBJETS_DECOR[0].compteur_ANIM == 41)
		{
			LISTE_OBJETS_DECOR[0].index_ANIM += 1;
			SPR_setFrame(LISTE_OBJETS_DECOR[0].sprite_OBJET,LISTE_OBJETS_DECOR[0].index_ANIM);
		}

		else if(LISTE_OBJETS_DECOR[0].compteur_ANIM == 46)
		{
			LISTE_OBJETS_DECOR[0].index_ANIM += 1;
			SPR_setFrame(LISTE_OBJETS_DECOR[0].sprite_OBJET,LISTE_OBJETS_DECOR[0].index_ANIM);
		}

		else if(LISTE_OBJETS_DECOR[0].compteur_ANIM == 51)
		{
			LISTE_OBJETS_DECOR[0].index_ANIM += 1;
			SPR_setFrame(LISTE_OBJETS_DECOR[0].sprite_OBJET,LISTE_OBJETS_DECOR[0].index_ANIM);
		}

		else if(LISTE_OBJETS_DECOR[0].compteur_ANIM == 56)
		{
			LISTE_OBJETS_DECOR[0].type = NULL;
			SPR_releaseSprite(LISTE_OBJETS_DECOR[0].sprite_OBJET);
			arbre_BRULE_OK = 0;
			nb_OBJET_DECOR -= 1;
			return;
		}



		LISTE_OBJETS_DECOR[0].compteur_ANIM += 1;

	}
}