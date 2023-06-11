#include <genesis.h>

#include "palettes.h"
#include "sprites_DECOR.h"
#include "sprites_ENNEMIS.h"

#include "maps_NIVEAUX.h"
#include "maps_ENTREES.h"
#include "maps_SALLES.h"
//#include "maps_DONJONS.h"


//******************************************************//
//                                                      //
//                    TABLES ENTREES                    //
//                                                      //
//******************************************************//

//////////////////////////////////////////////////////////
//                    ENTREES NIVEAU 1                  //
//////////////////////////////////////////////////////////

// ID DES ENTREES
// 0 = ESCALIER
// 1 = DONJON
// 2 = CAVE
// 3 = ENTREE SURFACE
const u8					TABLE_ID_ENTREES_NIVEAU1[43]		=	{ 0,1,0,0,0,2,0,
																	  2,2,2,2,0,2,
																	  2,2,0,2,2,0,1,
																	  2,0,2,
																	  3,2,0,
																	  0,0,0,0,0,0,
																	  0,0,2,0,0,0,
																	  2,2,0,2,0
																	};

// POSITION (EN PIXELS) DES SPRITES DES ENTREES
// QUI VIENNENT PAR-DESSUS LE JOUEUR
// LORSQU'IL RENTRE OU SORT D'UNE ENTREE
const u8					TABLE_POS_ENTREES_NIVEAU1[43][2]	=	{ {192,128},
																	  {120,120},
																	  {112,120},
																	  {160,160},
																	  {64,112},
																	  {104,56},
																	  {80,128},

																	  {56,24},
																	  {120,24},
																	  {48,40},
																	  {40,24},
																	  {128,120},
																	  {136,56},

																	  {NULL,NULL},
																	  {NULL,NULL},
																	  {NULL,NULL},
																	  {NULL,NULL},
																	  {NULL,NULL},
																	  {NULL,NULL},
																	  {NULL,NULL},

																	  {NULL,NULL},
																	  {NULL,NULL},
																	  {NULL,NULL},

																	  {120,88},
																	  {168,40},
																	  {112,104},
																	  
																	  {NULL,NULL},
																	  {NULL,NULL},
																	  {NULL,NULL},
																	  {NULL,NULL},
																	  {NULL,NULL},
																	  {NULL,NULL},

																	  {NULL,NULL},
																	  {NULL,NULL},
																	  {NULL,NULL},
																	  {NULL,NULL},
																	  {NULL,NULL},
																	  {NULL,NULL},

																	  {NULL,NULL},
																	  {NULL,NULL},
																	  {NULL,NULL},
																	  {NULL,NULL},
																	  {NULL,NULL}
																	};

// TILES DES SPRITES DES ENTREES
const SpriteDefinition		*TABLE_ADR_SPR_ENTREES_NIVEAU1[43]	=	{ NULL , &tiles_SPR_DONJON_NIVEAU1 , NULL , NULL , NULL , &tiles_SPR_CAVE_NIVEAU1 , NULL , 
																	  &tiles_SPR_CAVE_NIVEAU1 , &tiles_SPR_CAVE_NIVEAU1 , &tiles_SPR_CAVE_NIVEAU1 , &tiles_SPR_CAVE_NIVEAU1 , NULL , &tiles_SPR_CAVE_NIVEAU1 ,
																	  &tiles_SPR_CAVE_NIVEAU1 , &tiles_SPR_CAVE_NIVEAU1 , NULL , &tiles_SPR_CAVE_NIVEAU1 , &tiles_SPR_CAVE_NIVEAU1 , NULL , &tiles_SPR_DONJON_NIVEAU1 ,
																	  &tiles_SPR_CAVE_NIVEAU1 , NULL , &tiles_SPR_CAVE_NIVEAU1 ,
																	  &tiles_SPR_CAVERNE_NIVEAU1 , &tiles_SPR_CAVE_NIVEAU1 , NULL ,
																	  NULL , NULL , NULL , NULL , NULL , NULL ,
																	  NULL , NULL , &tiles_SPR_SANCTUAIRE , NULL , NULL , NULL ,
																	  &tiles_SPR_CAVE_NIVEAU1 , &tiles_SPR_CAVE_NIVEAU1 , NULL , &tiles_SPR_CAVE_NIVEAU1 , NULL
																	};

// PALETTES DES SPRITES DES ENTREES
// UTILISENT LA TABLE /
// TABLE_ID_ENTREES_NIVEAU1[43]
const u8					TABLE_PAL_SPRITES_ENTREES[4]		=	{ PAL1,PAL2,PAL1,PAL2};

/*
const TileMap				*TABLE_TILESET_ENTREES_NIVEAU1[43]	=	{ &tileset_SALLE_0_0,  };
*/

