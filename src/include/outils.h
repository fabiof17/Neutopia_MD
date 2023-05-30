#ifndef _OUTILS_H
#define _OUTILS_H


//******************************************************//
//                                                      //
//                        GLOBALES                      //
//                                                      //
//******************************************************//

extern void VDP_drawInt(u16 valeur,u8 zeros,s16 x, s16 y);
extern int calcul_DIGITS(u16 nombre);
extern void effacer_SCORE(u8 nb_TILES , u16 pos_X , u16 pos_Y);
extern void maj_SCORE(u16 nombre , u8 nb_TILES , u16 pos_X , u16 pos_Y);
extern s16 aligner_JOUEUR(s16 x);








#endif // _MAIN