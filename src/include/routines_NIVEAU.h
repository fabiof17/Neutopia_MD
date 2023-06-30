#ifndef _ROUTINES_NIVEAU_H
#define _ROUTINES_NIVEAU_H


//******************************************************//
//                                                      //
//                        GLOBAL                        //
//                                                      //
//******************************************************//

//extern void init_TIR();




//******************************************************//
//                                                      //
//                        TITRE                         //
//                                                      //
//******************************************************//

extern void anim_TITRE();
extern void boucle_TITRE();




//******************************************************//
//                                                      //
//                         MENU                         //
//                                                      //
//******************************************************//

extern void afficher_MENU(u8 type);




//******************************************************//
//                                                      //
//                     NIVEAU GLOBAL                    //
//                                                      //
//******************************************************//

extern void maj_PALETTES( u8 index , u8 type );




//******************************************************//
//                                                      //
//                        NIVEAU                        //
//                                                      //
//******************************************************//

extern void scrolling_ECRAN_NIVEAU();

extern void sortie_SCROLLING_NIVEAU();

extern void entree_ENTREE();




extern void manette_JOUEUR_NIVEAU();

extern void collision_TIR();




//******************************************************//
//                                                      //
//                         TILES                        //
//                                                      //
//******************************************************//

extern void tiles_JOUEUR();

extern void tiles_EAU_NIVEAU();

extern void tiles_CASCADE_NIVEAU();

extern void tiles_ARBRE_BRULE();






#endif // _MAIN