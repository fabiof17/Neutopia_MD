#ifndef _ROUTINES_H
#define _ROUTINES_H


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
//                        NIVEAU                        //
//                                                      //
//******************************************************//

extern void maj_PALETTES( u8 index , u8 type );

extern void maj_PT_COLL_DECOR();

extern void crea_SPRITE_ENTREE();

extern void test_SPRITE_ENTREE();

extern void scrolling_ECRAN();

extern void sortie_SCROLLING();

extern void manette_JOUEUR();

extern void tiles_JOUEUR();









#endif // _MAIN