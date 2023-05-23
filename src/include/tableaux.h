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
//                    SPRITES NIVEAU 1                  //
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
//                    ENNEMIS NIVEAU 1                  //
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

extern const s16                    TABLE_INIT_CAM_NIVEAUX[2][4];

extern const u8                     TABLE_INIT_INDEX_NIVEAUX[2][4];

extern const TileSet		        *TABLE_TILESET_NIVEAUX[2][4];

extern const MapDefinition          *TABLE_MAPDEF_NIVEAUX[2][4];

//extern const TileSet*				(*TABLE_TILESET[3])[2][4];




//******************************************************//
//                                                      //
//                    TABLES ENTREES                    //
//                                                      //
//******************************************************//

//////////////////////////////////////////////////////////
//                    ENTREES NIVEAU 1                  //
//////////////////////////////////////////////////////////

extern const u16                    TABLE_OFFSET_TILE_NIVEAUX[8][8];




//******************************************************//
//                                                      //
//                     TABLES SALLES                    //
//                                                      //
//******************************************************//

extern const TileSet				*TABLE_TILESET_SALLES_NIVEAUX[4][43];

extern const MapDefinition			*TABLE_MAPDEF_SALLES_NIVEAUX[4][43];




//******************************************************//
//                                                      //
//                    TABLES DONJONS                    //
//                                                      //
//******************************************************//

extern const s16                    TABLE_INIT_CAM_DONJONS[2][8];

extern const u8                     TABLE_INIT_INDEX_DONJONS[2][8];




























#endif // _MAIN