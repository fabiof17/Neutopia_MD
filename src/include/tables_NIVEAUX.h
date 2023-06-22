#ifndef _TABLES_NIVEAUX_H
#define _TABLES_NIVEAUX_H


//******************************************************//
//                                                      //
//                    TABLES NIVEAUX                    //
//                                                      //
//******************************************************//

//////////////////////////////////////////////////////////
//                   PALETTES NIVEAUX                   //
//////////////////////////////////////////////////////////

extern const Palette				*TABLE_ADR_PAL_NIVEAUX[2][4];

//////////////////////////////////////////////////////////
//                    SPRITES NIVEAU 1                  //
//////////////////////////////////////////////////////////

extern const u8					    TABLE_NB_SPRITES_NIVEAU1[8][8];

extern const SpriteDefinition		*TABLE_ADR_SPRITES_NIVEAU1[4];

extern const u8					    TABLE_ID_SPRITES_NIVEAU1[8][8];

extern const u8					    TABLE_POSX_SPRITES_NIVEAU1[8][8];

extern const u8					    TABLE_POSY_SPRITES_NIVEAU1[8][8];

extern const u8					    TABLE_PAL_SPRITES_NIVEAU1[8][8];




//******************************************************//
//                                                      //
//                   TABLES ENNEMIS                     //
//                                                      //
//******************************************************//

//////////////////////////////////////////////////////////
//                    ENNEMIS NIVEAU 1                  //
//////////////////////////////////////////////////////////

extern const u8                 	TABLE_NB_ENNEMIS_NIVEAU1[8][8];

extern const u8                 	TABLE_INDEX_ENNEMIS_NIVEAU1[8][8];

extern const SpriteDefinition		*TABLE_ID_ENNEMIS_NIVEAU1[9];

extern const u8					    TABLE_ADR_ENNEMIS_NIVEAU1[169];




//******************************************************//
//                                                      //
//                    TABLES NIVEAUX                    //
//                                                      //
//******************************************************//

extern const s16                    TABLE_INIT_CAM_NIVEAUX[2][4];

extern const u8                     TABLE_INIT_INDEX_NIVEAUX[2][4];

extern const TileSet		        *TABLE_TILESET_NIVEAUX[2][4];

extern const MapDefinition          *TABLE_MAPDEF_NIVEAUX[2][4];

extern const MapDefinition			*TABLE_MAPCOLL_NIVEAUX[4];

extern const u16                    TABLE_OFFSET_COLLISION[8][8];

extern const Image					*TABLE_ADR_EAU_NIVEAUX[4][4];

extern const Image					*TABLE_ADR_CASCADE_NIVEAUX[4][4];




























#endif // _MAIN