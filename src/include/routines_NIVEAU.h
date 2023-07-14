#ifndef _ROUTINES_NIVEAU_H
#define _ROUTINES_NIVEAU_H


//******************************************************//
//                                                      //
//                        GLOBAL                        //
//                                                      //
//******************************************************//

extern void entree_SALLE();

extern void fin_ENTREE_SALLE();

extern void entree_NIVEAU();

extern void fin_ENTREE_NIVEAU();




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

extern void entree_CAVE();




extern void manette_JOUEUR_NIVEAU();

extern void crea_TIR();

extern void collision_TIR();

extern void anim_TIR();

extern void tiles_TIR();




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