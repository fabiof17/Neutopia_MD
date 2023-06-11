#include <genesis.h>

#include "include/outils.h"
#include "include/structures.h"
#include "include/variables.h"
#include "include/init.h"
#include "include/routines.h"
#include "include/boutons_MANETTE.h"




int main(bool resetType)
{
    if (!resetType) SYS_hardReset();

	init_SYSTEME();

    init_VARIABLES_GENERALES();

    JOY_init();


    //******************************************************************************************//
    //******************************************************************************************//
    //                                                                                          //
    //                                   BOUCLE PRINCIPALE                                      //
    //                                                                                          //
    //******************************************************************************************//
    //******************************************************************************************//
    
    while(TRUE)
    {
        //**************************************************************************************//
        //                                                                                      //
        //                                     TITRE                                            //
        //                                                                                      //
        //**************************************************************************************// 

        if(scene_JEU == 0)
        {
            //JOY_setEventHandler(titre_Callback);
            
            //////////////////////////////////////////////////////////////////////////////////////
            //                            CHARGEMENT ECRAN TITRE                                //
            //////////////////////////////////////////////////////////////////////////////////////         
            if(titre_OK == 0)
            {
                // init TITRE //
                //init_TITRE();
            }

            ///////////////////////////////////////////////////////////////////////////////////////
            //                                   ANIM TITRE                                      //
            /////////////////////////////////////////////////////////////////////////////////////// 
            else
            {
                // anim TITRE //
                //anim_TITRE();
            }
        }


        //**************************************************************************************//
        //                                                                                      //
        //                                     INTRO                                            //
        //                                                                                      //
        //**************************************************************************************// 

        else if(scene_JEU == 1)
        {
            //JOY_setEventHandler(intro_Callback);
            
            ///////////////////////////////////////////////////////////////////////////////////////
            //                                CHARGEMENT INTRO                                   //
            ///////////////////////////////////////////////////////////////////////////////////////
            if(intro_OK==0)
            {
                // init INTRO //
                //init_INTRO();

            }
            ///////////////////////////////////////////////////////////////////////////////////////
            //                                   ANIM INTRO                                      //
            ///////////////////////////////////////////////////////////////////////////////////////
            else
            {
                // anim  INTRO //
                //anim_INTRO();
            }
        }


        //**************************************************************************************//
        //                                                                                      //
        //                                    NIVEAUX                                           //
        //                                                                                      //
        //**************************************************************************************// 

        else if(scene_JEU == 2)
        {
            if(menu_OK == 0)
            {
                ///////////////////////////////////////////////////////////////////////////////////////
                //                                 INIT MENU + WINDOW                                //
                ///////////////////////////////////////////////////////////////////////////////////////

                init_MENU();
                init_WINDOW();
                init_SPRITE_ENTREE();
                init_JOUEUR();

                menu_OK = 1;
            }    

            else
            {                   
                while(GAMEOVER == 0)
                {
                    ///////////////////////////////////////////////////////////////////////////////////////
                    //                                    INIT NIVEAU                                    //
                    ///////////////////////////////////////////////////////////////////////////////////////
                    if(niveau_OK == 0)
                    {
                        // Init NIVEAU //
                        init_DECOR(num_NIVEAU , type_DECOR);
                        afficher_MENU(type_DECOR);
                        //init_JOUEUR();

                        init_PALETTES_MENU();
                        maj_PALETTES(num_NIVEAU , type_DECOR);

                        niveau_OK = 1;
                    }

                    ///////////////////////////////////////////////////////////////////////////////////////
                    //                                        JEU                                        //
                    ///////////////////////////////////////////////////////////////////////////////////////
                    else
                    {
                        // JEU //
                        if(etat_JEU == 0)
                        {
                            if(PAUSE == 0)
                            {
                                JOY_setEventHandler(niveau_Callback);
                                manette_JOUEUR();
                                tiles_JOUEUR();
                            }

                            else
                            {
                                JOY_setEventHandler(menu_Callback);
                            }
                        }

                        // SCROLLING ECRAN SUIVANT //
                        else if(etat_JEU == 1)
                        {
                            JOY_setEventHandler(desactiver_Callback);
                            scrolling_ECRAN();
                        }
                        
                        // POSITIONNEMENT JOUEUR FIN SCROLLING //
                        else if(etat_JEU == 2)
                        {
                            JOY_setEventHandler(desactiver_Callback);
                            sortie_SCROLLING();
                            tiles_JOUEUR();
                        }                       

                        // ENTREE CAVE - DONJON - NIVEAU //
                        else if(etat_JEU == 3)
                        {
                            JOY_setEventHandler(desactiver_Callback);
                            entree_ENTREE();
                        }  

                        // SORTIE CAVE - DONJON - NIVEAU //
                        else if(etat_JEU == 3)
                        {
                            JOY_setEventHandler(desactiver_Callback);
                        }

                        //VDP_drawInt( etat_JOUEUR , 3 , 0 , 0 );
                        //SYS_showFrameLoad(TRUE);

                        SPR_update();
                        SYS_doVBlankProcess();

                        
                    }
                }
            }
        }
    }
    
    return 0;
}