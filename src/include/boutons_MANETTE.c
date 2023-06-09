#include <genesis.h>

#include "routines_NIVEAU.h"
#include "variables.h"

#include "tables_DONJONS.h"
#include "tables_ENTREES.h"
#include "tables_MENU.h"
#include "tables_NIVEAUX.h"
#include "tables_SALLES.h"

#include "sprites_JEU.h"

#include "maps_MENU.h"



//******************************************************//
//                                                      //
//                        TITRE                         //
//                                                      //
//******************************************************//





//******************************************************//
//                                                      //
//                         MENU                         //
//                                                      //
//******************************************************//

void menu_Callback(u16 joy, u16 changed, u16 state)
{
    if(joy == JOY_1)
    {
        // BOUTON START //
        if (changed & state & BUTTON_START)
        {
            pos_X_CURSEUR = -24;
            pos_Y_CURSEUR = -24;

            SPR_setPosition(sprite_CURSEUR, pos_X_CURSEUR, pos_Y_CURSEUR);

            VDP_setHorizontalScroll(BG_A, (s16)pos_X_CAM);
            VDP_setVerticalScroll(BG_A, (s16)pos_Y_CAM);

            PAUSE = 0;
        }

        // BOUTON DROITE //
        else if( changed & state & BUTTON_RIGHT )
        {
            if(index_X_MENU < 3)
            {
                pos_X_CURSEUR += 24;

                SPR_setPosition(sprite_CURSEUR, pos_X_CURSEUR, pos_Y_CURSEUR);

                index_X_MENU += 1;

                VDP_setTileMapEx(WINDOW, image_OBJET.tilemap, TILE_ATTR_FULL(TABLE_PAL_OBJETS_HAUT[index_Y_MENU][index_X_MENU], TRUE, FALSE, FALSE, TABLE_ADR_VRAM_OBJETS_HAUT[index_Y_MENU][index_X_MENU]), 3, 2, 0, 0, 2, 2, CPU);

                id_OBJET_MENU = (index_Y_MENU << 2) + index_X_MENU;
            }
        }

        // BOUTON GAUCHE //
        else if( changed & state & BUTTON_LEFT )
        {
            if(index_X_MENU > 0)
            {
                pos_X_CURSEUR -= 24;

                SPR_setPosition(sprite_CURSEUR, pos_X_CURSEUR, pos_Y_CURSEUR);

                index_X_MENU -= 1;

                VDP_setTileMapEx(WINDOW, image_OBJET.tilemap, TILE_ATTR_FULL(TABLE_PAL_OBJETS_HAUT[index_Y_MENU][index_X_MENU], TRUE, FALSE, FALSE, TABLE_ADR_VRAM_OBJETS_HAUT[index_Y_MENU][index_X_MENU]), 3, 2, 0, 0, 2, 2, CPU);

                id_OBJET_MENU = (index_Y_MENU << 2) + index_X_MENU;
            }
        }

        // BOUTON BAS //
        else if( changed & state & BUTTON_DOWN )
        {
            if(index_Y_MENU < 1)
            {
                pos_Y_CURSEUR += 24;

                SPR_setPosition(sprite_CURSEUR, pos_X_CURSEUR, pos_Y_CURSEUR);

                index_Y_MENU += 1;

                VDP_setTileMapEx(WINDOW, image_OBJET.tilemap, TILE_ATTR_FULL(TABLE_PAL_OBJETS_HAUT[index_Y_MENU][index_X_MENU], TRUE, FALSE, FALSE, TABLE_ADR_VRAM_OBJETS_HAUT[index_Y_MENU][index_X_MENU]), 3, 2, 0, 0, 2, 2, CPU);

                id_OBJET_MENU = (index_Y_MENU << 2) + index_X_MENU;
            }
        }

        // BOUTON HAUT //
        else if( changed & state & BUTTON_UP )
        {
            if(index_Y_MENU > 0)
            {
                pos_Y_CURSEUR -= 24;

                SPR_setPosition(sprite_CURSEUR, pos_X_CURSEUR, pos_Y_CURSEUR);

                index_Y_MENU -= 1;

                VDP_setTileMapEx(WINDOW, image_OBJET.tilemap, TILE_ATTR_FULL(TABLE_PAL_OBJETS_HAUT[index_Y_MENU][index_X_MENU], TRUE, FALSE, FALSE, TABLE_ADR_VRAM_OBJETS_HAUT[index_Y_MENU][index_X_MENU]), 3, 2, 0, 0, 2, 2, CPU);

                id_OBJET_MENU = (index_Y_MENU << 2) + index_X_MENU;
            }
        }
    }
}




//******************************************************//
//                                                      //
//                       NIVEAUX                        //
//                                                      //
//******************************************************//

void niveau_Callback(u16 joy, u16 changed, u16 state)
{
    if(joy == JOY_1)
    {
    	//////////////////////////////////////////////////////////
		//                          MENU                        //
		//////////////////////////////////////////////////////////	
        if (changed & state & BUTTON_START)
        {
            pos_X_CURSEUR = 20 + (index_X_MENU * 24);
            pos_Y_CURSEUR = 76 + (index_Y_MENU * 24);

            id_OBJET_MENU = (index_Y_MENU << 2) + index_X_MENU;

            SPR_setPosition(sprite_CURSEUR, pos_X_CURSEUR, pos_Y_CURSEUR);

            VDP_setHorizontalScroll(BG_A, (s16)pos_X_CAM + 256);
            VDP_setVerticalScroll(BG_A, (s16)pos_Y_CAM + 256);

            VDP_setTileMapEx(WINDOW, image_OBJET.tilemap, TILE_ATTR_FULL(TABLE_PAL_OBJETS_HAUT[index_Y_MENU][index_X_MENU], TRUE, FALSE, FALSE, TABLE_ADR_VRAM_OBJETS_HAUT[index_Y_MENU][index_X_MENU]), 3, 2, 0, 0, 2, 2, CPU);

            PAUSE = 1;
            //return;
        }

        //////////////////////////////////////////////////////////
		//                        ATTAQUE                       //
		//////////////////////////////////////////////////////////
        else if(changed & state & BUTTON_B)
        {
            if(etat_JOUEUR != ATTAQUE && etat_JOUEUR != TIR_BAGUETTE && etat_JOUEUR != TOUCHE)
            {
                etat_JOUEUR = ATTAQUE;
                //return;
            }
        }

        //////////////////////////////////////////////////////////
		//                      TIR BAGUETTE                    //
		//////////////////////////////////////////////////////////
        else if(changed & state & BUTTON_A)
        {
            if(id_OBJET_MENU == 2)
            {
                if(etat_JOUEUR != ATTAQUE && etat_JOUEUR != TIR_BAGUETTE && etat_JOUEUR != TOUCHE)
                {
                    if(nb_TIR < MAX_TIR)
                    {
                        etat_JOUEUR = TIR_BAGUETTE;
                        crea_TIR();
                        //return;
                    }
                }
            }
        }        
    }
}


void desactiver_Callback(u16 joy, u16 changed, u16 state)
{
    if(joy == JOY_1)
    {
        //
    }
}