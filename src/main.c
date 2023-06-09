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
            if(titre_OK == NON)
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
            if(intro_OK == NON)
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

                //VDP_setDisable();

                init_MENU();
                init_WINDOW();
                init_JOUEUR();

                init_POINTEURS_TABLES();

                //init_PALETTES_MENU();
                //maj_PALETTES(num_NIVEAU , type_DECOR);               

                menu_OK = 1;
            }    

            else
            {                   
                while(GAMEOVER == NON)
                {
                    ///////////////////////////////////////////////////////////////////////////////////////
                    //                                     INIT DECOR                                    //
                    ///////////////////////////////////////////////////////////////////////////////////////
                    if(niveau_OK == NON)
                    {
                        // Init NIVEAU //
                        init_DECOR(num_NIVEAU , type_DECOR);
                        afficher_MENU();

                        //init_PALETTES_MENU();
                        //maj_PALETTES(num_NIVEAU , type_DECOR);

                        niveau_OK = OUI;
                    }


                    ///////////////////////////////////////////////////////////////////////////////////////
                    //                                        JEU                                        //
                    ///////////////////////////////////////////////////////////////////////////////////////

                    else
                    {
                        ///////////////////////////////////////////////////////////////////////////////////////
                        //                                  ENTREE NIVEAU                                    //
                        ///////////////////////////////////////////////////////////////////////////////////////
                        if(etat_JEU == ENTREE_NIVEAU)
                        {
                            JOY_setEventHandler(desactiver_Callback);
                            entree_NIVEAU();
                            
                            //SYS_showFrameLoad(TRUE);

                            SPR_update();
                            SYS_doVBlankProcess();

                            break;  
                        }  

                        ///////////////////////////////////////////////////////////////////////////////////////
                        //                                FIN ENTREE NIVEAU                                  //
                        ///////////////////////////////////////////////////////////////////////////////////////
                        if(etat_JEU == FIN_ENTREE_NIVEAU)
                        {
                            JOY_setEventHandler(desactiver_Callback);
                            fin_ENTREE_NIVEAU();
                            tiles_JOUEUR();
                            
                            //SYS_showFrameLoad(TRUE);

                            SPR_update();
                            SYS_doVBlankProcess();

                            break;  
                        }  

                        ///////////////////////////////////////////////////////////////////////////////////////
                        //                                      NIVEAU                                       //
                        ///////////////////////////////////////////////////////////////////////////////////////
                        else if(etat_JEU == NIVEAU)
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

                            //VDP_drawInt(type_DECOR,2,0,0);
                            //SYS_showFrameLoad(TRUE);

                            SPR_update();
                            SYS_doVBlankProcess();

                            break;
                        }

                        ///////////////////////////////////////////////////////////////////////////////////////
                        //                                 SCROLLING NIVEAU                                  //
                        ///////////////////////////////////////////////////////////////////////////////////////
                        else if(etat_JEU == SCROLLING_NIVEAU)
                        {
                            JOY_setEventHandler(desactiver_Callback);

                            scrolling_ECRAN_NIVEAU();
                            
                            tiles_EAU_NIVEAU();
                            tiles_CASCADE_NIVEAU();

                            
                            //SYS_showFrameLoad(TRUE);

                            SPR_update();
                            SYS_doVBlankProcess();

                            break;
                        }
                        
                        ///////////////////////////////////////////////////////////////////////////////////////
                        //                               FIN SCROLLING NIVEAU                                //
                        ///////////////////////////////////////////////////////////////////////////////////////
                        else if(etat_JEU == FIN_SCROLLING_NIVEAU)
                        {
                            JOY_setEventHandler(desactiver_Callback);

                            sortie_SCROLLING_NIVEAU();

                            tiles_JOUEUR();
                            tiles_EAU_NIVEAU();
                            tiles_CASCADE_NIVEAU();

                            
                            //SYS_showFrameLoad(TRUE);

                            SPR_update();
                            SYS_doVBlankProcess();

                            break;
                        }                       

                        ///////////////////////////////////////////////////////////////////////////////////////
                        //                                   ENTREE CAVE                                     //
                        ///////////////////////////////////////////////////////////////////////////////////////
                        else if(etat_JEU == ENTREE_CAVE)
                        {
                            JOY_setEventHandler(desactiver_Callback);
                            entree_CAVE();
                            
                            //SYS_showFrameLoad(TRUE);

                            SPR_update();
                            SYS_doVBlankProcess();

                            break;  
                        }  




                        ///////////////////////////////////////////////////////////////////////////////////////
                        //                                  ENTREE SALLE                                     //
                        ///////////////////////////////////////////////////////////////////////////////////////
                        else if(etat_JEU == ENTREE_SALLE)
                        {
                            JOY_setEventHandler(desactiver_Callback);
                            entree_SALLE();
                            
                            //SYS_showFrameLoad(TRUE);

                            SPR_update();
                            SYS_doVBlankProcess();

                            break;  
                        }  

                        ///////////////////////////////////////////////////////////////////////////////////////
                        //                                FIN ENTREE SALLE                                   //
                        ///////////////////////////////////////////////////////////////////////////////////////
                        else if(etat_JEU == FIN_ENTREE_SALLE)
                        {
                            JOY_setEventHandler(desactiver_Callback);
                            fin_ENTREE_SALLE();
                            tiles_JOUEUR();
                            
                            //SYS_showFrameLoad(TRUE);

                            SPR_update();
                            SYS_doVBlankProcess();

                            break;  
                        }  

                        ///////////////////////////////////////////////////////////////////////////////////////
                        //                                       SALLE                                       //
                        ///////////////////////////////////////////////////////////////////////////////////////
                        else if(etat_JEU == SALLE)
                        {
                            if(PAUSE == NON)
                            {
                                JOY_setEventHandler(niveau_Callback);

                            }

                            else
                            {
                                JOY_setEventHandler(menu_Callback);
                            }

                            SPR_update();
                            SYS_doVBlankProcess();

                            break;  
                        } 

                        ///////////////////////////////////////////////////////////////////////////////////////
                        //                                     SORTIE SALLE                                  //
                        ///////////////////////////////////////////////////////////////////////////////////////
                        else if(etat_JEU == SORTIE_SALLE)
                        {
                            JOY_setEventHandler(desactiver_Callback);

                            

                            

                            SPR_update();
                            SYS_doVBlankProcess();

                            break; 
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