#include <genesis.h>

#include "include/outils.h"
#include "include/structures.h"
#include "include/variables.h"
#include "include/init.h"
#include "include/routines_NIVEAU.h"
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
                //init_SPRITE_ENTREE();
                init_JOUEUR();

                menu_OK = 1;
            }    

            else
            {                   
                while(GAMEOVER == 0)
                {
                    ///////////////////////////////////////////////////////////////////////////////////////
                    //                                     INIT DECOR                                    //
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
                        ///////////////////////////////////////////////////////////////////////////////////////
                        //                                      NIVEAU                                       //
                        ///////////////////////////////////////////////////////////////////////////////////////
                        while(etat_JEU == NIVEAU)
                        {
                            if(PAUSE == NON)
                            {
                                JOY_setEventHandler(niveau_Callback);

                                manette_JOUEUR_NIVEAU();

                                collision_TIR();
                                anim_TIR();
                                tiles_TIR();

                                

                                tiles_JOUEUR();
                                tiles_EAU_NIVEAU();
                                tiles_CASCADE_NIVEAU();
                                tiles_ARBRE_BRULE();
                            }

                            else
                            {
                                JOY_setEventHandler(menu_Callback);
                            }

                            //debug_JEU();
                            //VDP_drawInt( nb_OBJET_DECOR , 2 , 0 , 0 );
                            //SYS_showFrameLoad(TRUE);

                            SPR_update();
                            SYS_doVBlankProcess();  
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////
                        //                                 SCROLLING NIVEAU                                  //
                        ///////////////////////////////////////////////////////////////////////////////////////
                        while(etat_JEU == SCROLLING_NIVEAU)
                        {
                            JOY_setEventHandler(desactiver_Callback);

                            scrolling_ECRAN_NIVEAU();
                            
                            tiles_EAU_NIVEAU();
                            tiles_CASCADE_NIVEAU();

                            //debug_JEU();
                            //SYS_showFrameLoad(TRUE);

                            SPR_update();
                            SYS_doVBlankProcess();  
                        }
                        
                        ///////////////////////////////////////////////////////////////////////////////////////
                        //                               FIN SCROLLING NIVEAU                                //
                        ///////////////////////////////////////////////////////////////////////////////////////
                        while(etat_JEU == FIN_SCROLLING_NIVEAU)
                        {
                            JOY_setEventHandler(desactiver_Callback);

                            sortie_SCROLLING_NIVEAU();

                            tiles_JOUEUR();
                            tiles_EAU_NIVEAU();
                            tiles_CASCADE_NIVEAU();

                            //debug_JEU();
                            //SYS_showFrameLoad(TRUE);

                            SPR_update();
                            SYS_doVBlankProcess();  
                        }                       

                        ///////////////////////////////////////////////////////////////////////////////////////
                        //                                   ENTREE CAVE                                     //
                        ///////////////////////////////////////////////////////////////////////////////////////
                        while(etat_JEU == ENTREE_CAVE)
                        {
                            JOY_setEventHandler(desactiver_Callback);
                            entree_ENTREE();
                            //VDP_drawInt( id_ENTREE , 2 , 0 , 0 );

                            //debug_JEU();
                            //SYS_showFrameLoad(TRUE);

                            SPR_update();
                            SYS_doVBlankProcess();  
                        }  




                        ///////////////////////////////////////////////////////////////////////////////////////
                        //                                      SALLE                                        //
                        ///////////////////////////////////////////////////////////////////////////////////////
                        while(etat_JEU == SORTIE_SALLE)
                        {
                            JOY_setEventHandler(desactiver_Callback);

                            //debug_JEU();

                            SPR_update();
                            SYS_doVBlankProcess();  
                        }





                        ///////////////////////////////////////////////////////////////////////////////////////
                        //                                      DONJON                                       //
                        ///////////////////////////////////////////////////////////////////////////////////////

                        ////SYS_showFrameLoad(TRUE);

                        //SPR_update();
                        //SYS_doVBlankProcess();

                        
                    }
                }
            }
        }
    }
    
    return 0;
}