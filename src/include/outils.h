#ifndef _OUTILS_H
#define _OUTILS_H


//******************************************************//
//                                                      //
//                        GLOBALES                      //
//                                                      //
//******************************************************//

extern int calcul_DIGITS(u16 nombre);
extern void effacer_SCORE(u8 nb_TILES , u16 pos_X , u16 pos_Y);
extern void maj_SCORE(u16 nombre , u8 nb_TILES , u16 pos_X , u16 pos_Y);
extern u16 maj_ID_TILE(const TileMap *maTilemap , s16 x , s16 y);











#endif // _MAIN