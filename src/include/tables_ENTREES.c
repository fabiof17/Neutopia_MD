#include <genesis.h>


#include "palettes.h"
#include "structures.h"

#include "sprites_DECOR.h"
#include "sprites_ENNEMIS.h"

#include "maps_NIVEAUX.h"
#include "maps_ENTREES.h"
#include "maps_SALLES.h"
//#include "maps_DONJONS.h"

#include "tables_ENTREES.h"


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

																	  {88,16},
																	  {152,16},
																	  {80,144},
																	  {120,16},
																	  {40,16},
																	  {80,128},
																	  {112,104},

																	  {8,40},
																	  {128,168},
																	  {200,16},

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
/*
const SpriteDefinition		*TABLE_ADR_SPR_ENTREES_NIVEAU1[43]	=	{ NULL , &tiles_SPR_DONJON_NIVEAU1 , NULL , NULL , NULL , &tiles_SPR_CAVE1_NIVEAU1 , NULL , 
																	  &tiles_SPR_CAVE1_NIVEAU1 , &tiles_SPR_CAVE1_NIVEAU1 , &tiles_SPR_CAVE1_NIVEAU1 , &tiles_SPR_CAVE1_NIVEAU1 , NULL , &tiles_SPR_CAVE1_NIVEAU1 ,
																	  &tiles_SPR_CAVE1_NIVEAU1 , &tiles_SPR_CAVE1_NIVEAU1 , NULL , &tiles_SPR_CAVE1_NIVEAU1 , &tiles_SPR_CAVE1_NIVEAU1 , &tiles_SPR_CAVE3_NIVEAU1 , &tiles_SPR_DONJON_NIVEAU1 ,
																	  &tiles_SPR_CAVE2_NIVEAU1 , NULL , &tiles_SPR_CAVE1_NIVEAU1 ,
																	  &tiles_SPR_CAVERNE_NIVEAU1 , &tiles_SPR_CAVE2_NIVEAU1 , NULL ,
																	  NULL , NULL , NULL , NULL , NULL , NULL ,
																	  NULL , NULL , &tiles_SPR_SANCTUAIRE , NULL , NULL , NULL ,
																	  &tiles_SPR_CAVE2_NIVEAU1 , &tiles_SPR_CAVE2_NIVEAU1 , NULL , &tiles_SPR_CAVE2_NIVEAU1 , NULL
																	};
*/

// PALETTES DES SPRITES DES ENTREES
// UTILISENT LA TABLE
// TABLE_ID_ENTREES_NIVEAU1[43]
const u8					TABLE_PAL_SPRITES_ENTREES[4]		=	{ PAL1,PAL2,PAL1,PAL2};

// DECLENCHEMENT DE L'OUVERTURE DES ENTREES CACHEES
// NULL = AUCUNE OUVERTURE A DECLENCHER
// 0 = OUVERTURE NON DECLENCHEE
/*
bool				TABLE_CONDITION_ENTREES_NIVEUA1[8][8]		=	{ {0    , NULL , NULL , 0    , NULL , NULL , NULL , 0   },
																	  {NULL , NULL , NULL , NULL , NULL , NULL , NULL , NULL},
																	  {NULL , NULL , NULL , NULL , NULL , NULL , NULL , NULL},
																	  {NULL , NULL , NULL , NULL , NULL , NULL , NULL , NULL},
																	  {NULL , NULL , NULL , NULL , NULL , NULL , NULL , NULL},
																	  {NULL , NULL , NULL , NULL , NULL , NULL , NULL , NULL},
																	  {NULL , NULL , NULL , NULL , NULL , NULL , NULL , NULL},
																	  {NULL , NULL , NULL , NULL , NULL , NULL , NULL , NULL}
																	};
*/

/*
const TileMap				*TABLE_TILESET_ENTREES_NIVEAU1[43]	=	{ &tileset_SALLE_0_0,  };
*/


// TYPE D'ENTREE : 0 = ESCALIER | 1 = DONJON | 2 = CAVE
// POSITION X (EN TILE)
// POSITION Y (EN TILE)
// ADRESSE TILES
// PALETTE
// PLAN
// PRIORITE : 0 = FALSE | 1 = TRUE
// SECRET : 0 = NON | 1 = OUI
// CONDITION : 0 = TUER ENNEMIS | 1 = POUSSER ROCHER | 2 = POSER BOMBE/BRULER ARBRE
const struct_ENTREE_			TABLE_ENTREES_NIVEAU1[43]	=	{	// 0 - 6
																	{0, 24,15, &image_ESCALIER_NIVEAU1, PAL1,BG_B,FALSE, 1,0},
																	{1, 15,15, &image_DONJON_NIVEAU1,   PAL2,BG_A,TRUE , 0,0},
																	{0, 14,16, &image_ESCALIER_NIVEAU1, PAL1,BG_B,FALSE, 0,0},
																	{0, 20,20, &image_ESCALIER_NIVEAU1, PAL1,BG_B,FALSE, 1,0},
																	{0, 8 ,14, &image_ESCALIER_NIVEAU1, PAL1,BG_B,FALSE, 0,0},
																	{2, 13,7 , &image_CAVE4_NIVEAU1,	PAL1,BG_B,TRUE , 1,2},
																	{0, 10,16, &image_ESCALIER_NIVEAU1, PAL1,BG_B,FALSE, 1,1},

																	// 7 - 12
																	{2, 7 ,3 , &image_CAVE1_NIVEAU1,	PAL1,BG_B,TRUE , 0,0},
																	{2, 15,3 , &image_CAVE4_NIVEAU1,	PAL1,BG_B,TRUE , 1,2},
																	{2, 6 ,5 , &image_CAVE4_NIVEAU1,	PAL1,BG_B,TRUE , 1,2},
																	{2, 5 ,3 , &image_CAVE3_NIVEAU1,	PAL1,BG_B,TRUE , 0,0},
																	{0, 16,15, &image_ESCALIER_NIVEAU1, PAL1,BG_B,FALSE, 1,1},
																	{2, 17,7 , &image_CAVE4_NIVEAU1,	PAL1,BG_B,TRUE , 1,2},

																	// 13 - 19
																	{2, 11,3 , &image_CAVE1_NIVEAU1,	PAL1,BG_B,TRUE , 0,0},
																	{2, 19,3 , &image_CAVE4_NIVEAU1,	PAL1,BG_B,TRUE , 1,2},
																	{0, 10,18, &image_ESCALIER_NIVEAU1,	PAL1,BG_B,TRUE , 1,1},
																	{2, 15,3 , &image_CAVE1_NIVEAU1,	PAL1,BG_B,TRUE , 0,0},
																	{2, 5, 3 , &image_CAVE3_NIVEAU1,	PAL1,BG_B,FALSE, 0,0},
																	{0, 10,16, &image_ESCALIER_NIVEAU1,	PAL1,BG_B,TRUE , 1,0},
																	{1, 14,13, &image_DONJON_NIVEAU1,	PAL2,BG_A,FALSE, 0,0},

																	// 20 - 22
																	{2, 1 ,5 , &image_CAVE2_NIVEAU1,	PAL1,BG_B,TRUE , 1,2},
																	{0, 19,21, &image_ESCALIER_NIVEAU1,	PAL1,BG_B,FALSE, 0,0},
																	{2, 23,4 , &image_CAVE1_NIVEAU1,	PAL1,BG_B,TRUE , 0,0},

																	// 23 - 25
																	{2, 15,11, &image_CAVERNE_NIVEAU1,	PAL2,BG_A,TRUE , 0,0},
																	{2, 21,5 , &image_CAVE2_NIVEAU1,	PAL1,BG_B,TRUE , 0,0},
																	{0, 10,18, &image_ESCALIER_NIVEAU1,	PAL1,BG_B,FALSE, 1,2},

																	// 7 - 12
																	{0, 16,15, &image_ESCALIER_NIVEAU1,	PAL1,BG_B,FALSE, 0,0},
																	{0, 18,17, &image_ESCALIER_NIVEAU1,	PAL1,BG_B,FALSE, 0,0},
																	{0, 18,15, &image_ESCALIER_NIVEAU1,	PAL1,BG_B,FALSE, 0,0},
																	{0, 10,17, &image_ESCALIER_NIVEAU1,	PAL1,BG_B,FALSE, 0,0},
																	{0, 12,17, &image_ESCALIER_NIVEAU1, PAL1,BG_B,FALSE, 0,0},
																	{0, 14,17, &image_ESCALIER_NIVEAU1,	PAL1,BG_B,FALSE, 1,2}

																	};



