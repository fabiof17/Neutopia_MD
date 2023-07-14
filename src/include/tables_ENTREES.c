#include <genesis.h>


#include "palettes.h"
#include "structures.h"

//#include "sprites_DECOR.h"
//#include "sprites_ENNEMIS.h"

#include "maps_ENTREES.h"
#include "maps_NIVEAUX.h"
//#include "maps_SALLES.h"

//#include "tables_ENTREES.h"


//******************************************************//
//                                                      //
//                    TABLES ENTREES                    //
//                                                      //
//******************************************************//

//////////////////////////////////////////////////////////
//                    ENTREES NIVEAU 1                  //
//////////////////////////////////////////////////////////

// 43 ENTREES + 1 TILE (ENTREE) CACHEE

// TYPE D'ENTREE : 0 = ESCALIER | 1 = DONJON | 2 = CAVE | 9 = SANCTUAIRE
// POSITION X (EN TILE)
// POSITION Y (EN TILE)
// ADRESSE TILES ENTREES
// ADRESSE TILES CACHES
// PALETTE
// PLAN
// PRIORITE : 0 = FALSE | 1 = TRUE
// SECRET : 0 = NON | 1 = OUI
// CONDITION : 0 = TUER ENNEMIS | 1 = POUSSER ROCHER - POSER BOMBE - BRULER ARBRE
// BLOQUANT : 0 = NON | 1 = OUI
const struct_ENTREE_			TABLE_ENTREES_NIVEAU1[44]	=	{	// 0 - 6
																	{0, 24,15, &image_ESCALIER1_NIVEAU1 , &image_CACHE1_ESCALIER_NIVEAU1,	PAL1,BG_B,FALSE, 1,0 , 0},
																	{1, 15,15, &image_DONJON_NIVEAU1    , &image_DONJON_NIVEAU1,			PAL2,BG_A,TRUE , 0,0 , 0},
																	{0, 14,13, &image_ESCALIER2_NIVEAU1 , &image_CACHE2_ESCALIER_NIVEAU1, 	PAL1,BG_B,FALSE, 1,1 , 1},
																	{0, 20,19, &image_ESCALIER1_NIVEAU1 , NULL,								PAL1,BG_B,FALSE, 1,0 , 1},
																	{0, 8 ,11, &image_ESCALIER3_NIVEAU1 , &image_CACHE4_ESCALIER_NIVEAU1, 	PAL1,BG_B,FALSE, 1,1 , 1},
																	{2, 13,7 , &image_CAVE4_NIVEAU1     , &image_CACHE2_CAVE_NIVEAU1,		PAL1,BG_B,TRUE , 1,1 , 1},
																	{0, 10,16, &image_ESCALIER1_NIVEAU1 , &image_CACHE1_ESCALIER_NIVEAU1,	PAL1,BG_B,FALSE, 1,1 , 0},

																	// 7 - 12
																	{2, 7 ,3 , &image_CAVE1_NIVEAU1		, &image_CAVE1_NIVEAU1,				PAL1,BG_B,TRUE , 0,0 , 0},
																	{2, 15,3 , &image_CAVE4_NIVEAU1		, &image_CACHE1_CAVE_NIVEAU1,		PAL1,BG_B,TRUE , 1,1 , 1},
																	{2, 5 ,5 , &image_CAVE4_NIVEAU1		, &image_CACHE1_CAVE_NIVEAU1,		PAL1,BG_B,TRUE , 1,1 , 1},
																	{2, 5 ,3 , &image_CAVE3_NIVEAU1		, &image_CAVE3_NIVEAU1,				PAL1,BG_B,TRUE , 0,0 , 0},
																	{0, 16,15, &image_ESCALIER1_NIVEAU1 , &image_CACHE1_ESCALIER_NIVEAU1,	PAL1,BG_B,FALSE, 1,1 , 0},
																	{2, 17,7 , &image_CAVE4_NIVEAU1		, &image_CACHE1_CAVE_NIVEAU1,		PAL1,BG_B,TRUE , 1,1 , 1},

																	// 13 - 19
																	{2, 11,3 , &image_CAVE1_NIVEAU1		, &image_CAVE1_NIVEAU1,				PAL1,BG_B,TRUE , 0,0 , 0},
																	{2, 19,3 , &image_CAVE4_NIVEAU1		, &image_CACHE1_CAVE_NIVEAU1,		PAL1,BG_B,TRUE , 1,1 , 1},
																	{0, 10,15, &image_ESCALIER2_NIVEAU1 , &image_CACHE2_ESCALIER_NIVEAU1,	PAL1,BG_B,FALSE, 1,1 , 1},
																	{2, 15,3 , &image_CAVE1_NIVEAU1		, &image_CAVE1_NIVEAU1,				PAL1,BG_B,TRUE , 0,0 , 0},
																	{2, 5, 3 , &image_CAVE3_NIVEAU1		, &image_CAVE3_NIVEAU1,				PAL1,BG_B,TRUE , 0,0 , 0},
																	{0, 10,16, &image_ESCALIER1_NIVEAU1 , &image_CACHE5_ESCALIER_NIVEAU1,	PAL1,BG_B,FALSE, 1,0 , 0},
																	{1, 15,13, &image_DONJON_NIVEAU1	, &image_DONJON_NIVEAU1,			PAL2,BG_A,TRUE , 0,0 , 0},

																	// 20 - 22
																	{2, 1 ,5 , &image_CAVE2_NIVEAU1		, &image_CACHE2_CAVE_NIVEAU1,		PAL1,BG_B,TRUE , 1,1 , 1},
																	{0, 16,19, &image_ESCALIER4_NIVEAU1 , &image_CACHE3_ESCALIER_NIVEAU1,	PAL1,BG_B,FALSE, 1,1 , 1},
																	{2, 25,3 , &image_CAVE5_NIVEAU1		, &image_CAVE5_NIVEAU1,				PAL1,BG_B,TRUE , 0,0 , 0},

																	// 23 - 25
																	{2, 15,11, &image_CAVERNE_NIVEAU1	, &image_CAVERNE_NIVEAU1,			PAL2,BG_A,TRUE , 0,0 , 0},
																	{2, 21,5 , &image_CAVE7_NIVEAU1		, &image_CAVE2_NIVEAU1,				PAL1,BG_B,TRUE , 0,0 , 0},
																	{0, 14,11, &image_ESCALIER2_NIVEAU1 , &image_CACHE2_ESCALIER_NIVEAU1,	PAL1,BG_B,FALSE, 1,1 , 1},

																	// 26 - 31
																	{0, 16,15, &image_ESCALIER1_NIVEAU1 , NULL,								PAL1,BG_B,FALSE, 0,0 , 0},
																	{0, 18,17, &image_ESCALIER1_NIVEAU1 , NULL,								PAL1,BG_B,FALSE, 0,0 , 0},
																	{0, 18,15, &image_ESCALIER1_NIVEAU1 , &image_CACHE2_ESCALIER_NIVEAU1,	PAL1,BG_B,FALSE, 0,0 , 0},
																	{0, 10,15, &image_ESCALIER2_NIVEAU1 , &image_CACHE2_ESCALIER_NIVEAU1,	PAL1,BG_B,FALSE, 1,1 , 1},
																	{0, 12,15, &image_ESCALIER2_NIVEAU1 , &image_CACHE2_ESCALIER_NIVEAU1,	PAL1,BG_B,FALSE, 1,1 , 1},
																	{0, 14,19, &image_ESCALIER1_NIVEAU1 , &image_CACHE5_ESCALIER_NIVEAU1,	PAL1,BG_B,FALSE, 1,1 , 0},

																	// 32 - 37
																	{0, 28,17, &image_ESCALIER3_NIVEAU1 , &image_CACHE4_ESCALIER_NIVEAU1,	PAL1,BG_B,FALSE, 1,1 , 1},
																	{0, 8 ,15, &image_ESCALIER1_NIVEAU1 , NULL,								PAL1,BG_B,FALSE, 0,0 , 0},
																	{9, 15,13, &image_ENTREE_SANCTUAIRE	, &image_ENTREE_SANCTUAIRE,			PAL2,BG_A,TRUE , 0,0 , 0},
																	{0, 24,17, &image_ESCALIER1_NIVEAU1 , NULL,								PAL1,BG_B,FALSE, 0,0 , 0},
																	{0, 6 ,9 , &image_ESCALIER1_NIVEAU1 , &image_CACHE5_ESCALIER_NIVEAU1, 	PAL1,BG_B,FALSE, 1,1 , 0},
																	{0, 24,9 , &image_ESCALIER1_NIVEAU1 , NULL,								PAL1,BG_B,FALSE, 0,0 , 0},

																	// 38 - 42
																	{2, 5 ,5 , &image_CAVE7_NIVEAU1		, &image_CAVE7_NIVEAU1,				PAL1,BG_B,TRUE , 0,0 , 0},
																	{2, 5 ,5 , &image_CAVE7_NIVEAU1		, &image_CAVE7_NIVEAU1,				PAL1,BG_B,TRUE , 0,0 , 0},
																	{0, 18,13, &image_ESCALIER1_NIVEAU1 , NULL,								PAL1,BG_B,FALSE, 0,0 , 0},
																	{2, 25,5 , &image_CAVE6_NIVEAU1		, &image_CAVE6_NIVEAU1,				PAL1,BG_B,TRUE , 0,0 , 0},
																	{0, 16,13, &image_ESCALIER2_NIVEAU1 , &image_CACHE2_ESCALIER_NIVEAU1,	PAL1,BG_B,FALSE, 1,1 , 1},

																	// 43 - TILE CACHEE															
																	{2, NULL ,NULL , NULL, NULL , NULL , NULL , NULL , 1 , 1 , 1}
																	};


const u8					TABLE_ID_ENTREES_NIVEAU1[8][8]	=	{	{0,1,NULL,2,3,4,5,6},
																	{7,8,9,NULL,10,NULL,11,12},
																	{13,14,15,NULL,16,17,18,19},
																	{NULL,20,NULL,NULL,21,NULL,22,NULL},
																	{NULL,23,24,NULL,NULL,NULL,NULL,25},
																	{NULL,NULL,NULL,NULL,28,29,30,31},
																	{32,NULL,NULL,34,NULL,NULL,35,NULL},
																	{NULL,38,39,40,41,NULL,NULL,42}
																};
