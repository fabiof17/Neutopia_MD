#ifndef _TABLEAUX_H
#define _TABLEAUX_H


//******************************************************//
//                                                      //
//                    TABLES DECOR                      //
//                                                      //
//******************************************************//

//////////////////////////////////////////////////////////
//                   PALETTES NIVEAUX                   //
//////////////////////////////////////////////////////////

extern const Palette				*TABLE_PAL_NIVEAUX[2][4];

//////////////////////////////////////////////////////////
//                    SPRITES DECOR 1                   //
//////////////////////////////////////////////////////////

extern const u8					    TABLE_NB_SPRITES_DECOR_1[8][8];

extern const SpriteDefinition		*TABLE_ADR_SPRITES_DECOR_1[4];

extern const u8					    TABLE_ID_SPRITES_DECOR_1[8][8];

extern const u8					    TABLE_POSX_SPRITES_DECOR_1[8][8];

extern const u8					    TABLE_POSY_SPRITES_DECOR_1[8][8];

extern const u8					    TABLE_PAL_SPRITES_DECOR_1[8][8];




//******************************************************//
//                                                      //
//                   TABLES ENNEMIS                     //
//                                                      //
//******************************************************//

//////////////////////////////////////////////////////////
//                    ENNEMIS DECOR 1                   //
//////////////////////////////////////////////////////////

extern const u8                 	TABLE_NB_ENNEMIS_DECOR_1[8][8];

extern const u8                 	TABLE_INDEX_ENNEMIS_DECOR_1[8][8];

extern const SpriteDefinition		*TABLE_ID_ENNEMIS_DECOR_1[9];

extern const u8					    TABLE_ADR_ENNEMIS_DECOR_1[169];




//******************************************************//
//                                                      //
//                     TABLES MENU                      //
//                                                      //
//******************************************************//

//extern const u8                     TABLE_POS_Y_MENU[8];




//******************************************************//
//                                                      //
//                  TABLE OBJETS MENU                   //
//                                                      //
//******************************************************//

extern bool                         TABLE_OBJETS_HAUT[2][4];

extern u16							TABLE_ADR_VRAM_OBJETS_HAUT[2][4];

extern const u8                     TABLE_PAL_OBJETS_HAUT[2][4];

extern bool                         TABLE_OBJETS_BAS[2][4];

extern u16							TABLE_ADR_VRAM_OBJETS_BAS[2][4];

extern const u8                     TABLE_PAL_OBJETS_BAS[2][4];




//******************************************************//
//                                                      //
//                    TABLES NIVEAUX                    //
//                                                      //
//******************************************************//

extern const TileSet		        *TABLE_TILESET_NIVEAUX[2][4];

extern const MapDefinition          *TABLE_MAPDEF_NIVEAUX[2][4];

extern const TileSet*				(*TABLE_TILESET[3])[2][4];





























#endif // _MAIN