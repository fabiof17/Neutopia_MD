#include <genesis.h>

#include "palettes.h"
#include "sprites_DECOR.h"
#include "sprites_ENNEMIS.h"

#include "maps_ENTREES.h"
#include "maps_NIVEAUX.h"
#include "maps_SALLES.h"


//******************************************************//
//                                                      //
//                    TABLES NIVEAUX                    //
//                                                      //
//******************************************************//

//////////////////////////////////////////////////////////
//                   PALETTES NIVEAUX                   //
//////////////////////////////////////////////////////////

const Palette				*TABLE_ADR_PAL_NIVEAUX[2][4]		=	{ {&palette_NIVEAU1_BG_B,&palette_NIVEAU1_BG_B,&palette_NIVEAU1_BG_B,&palette_NIVEAU1_BG_B},
														  		  	  {&palette_NIVEAU1_BG_A,&palette_NIVEAU1_BG_A,&palette_NIVEAU1_BG_A,&palette_NIVEAU1_BG_A}
																	};




//////////////////////////////////////////////////////////
//                    SPRITES NIVEAU 1                  //
//////////////////////////////////////////////////////////

const u8					TABLE_NB_SPRITES_NIVEAU1[8][8]  	=   { {0,0,0,1,0,1,0,1},
														  	 	      {0,0,0,0,0,0,1,0},
														  		      {0,1,1,0,0,0,0,0},
														  		      {0,1,0,0,1,0,0,0},
														  		      {0,0,0,0,0,0,0,1},
														  		      {0,0,0,0,0,1,1,1},
														  		      {1,0,0,0,0,0,1,0},
														  		      {0,0,0,0,0,0,0,1}
																	};

const SpriteDefinition		*TABLE_ADR_SPRITES_NIVEAU1[4]		= 	{ &tiles_SPR_ARBRE_VERT , &tiles_SPR_ARBRE_MARRON , &tiles_SPR_ROCHER , &tiles_SPR_STATUE };

const u8					TABLE_ID_SPRITES_NIVEAU1[8][8]  	= 	{ {NULL,NULL,NULL,0   ,NULL,1   ,NULL,2   },
														  		      {NULL,NULL,NULL,NULL,NULL,NULL,2   ,NULL},
														  		      {NULL,3   ,0   ,NULL,NULL,NULL,NULL,NULL},
														  		      {NULL,3   ,NULL,NULL,0   ,NULL,NULL,NULL},
														  		      {NULL,NULL,NULL,NULL,NULL,NULL,NULL,0   },
														  		      {NULL,NULL,NULL,NULL,NULL,0   ,0   ,2   },
														  		      {1   ,NULL,NULL,NULL,NULL,NULL,2   ,NULL},
														  		      {NULL,NULL,NULL,NULL,NULL,NULL,NULL,0   }
																  	};

const u8					TABLE_POSX_SPRITES_NIVEAU1[8][8]	=	{ {NULL,NULL,NULL,112 ,NULL,64  ,NULL,144 },
														  		      {NULL,NULL,NULL,NULL,NULL,NULL,192 ,NULL},
														  		      {NULL,128 ,80  ,NULL,NULL,NULL,NULL,NULL},
														  		      {NULL,16  ,NULL,NULL,128 ,NULL,NULL,NULL},
														  		      {NULL,NULL,NULL,NULL,NULL,NULL,NULL,112 },
														  		      {NULL,NULL,NULL,NULL,NULL,80  ,96  ,144 },
														  		      {224 ,NULL,NULL,NULL,NULL,NULL,96  ,NULL},
														  		      {NULL,NULL,NULL,NULL,NULL,NULL,NULL,128 }
																	};

const u8					TABLE_POSY_SPRITES_NIVEAU1[8][8]	=	{ {NULL,NULL,NULL,64  ,NULL,48  ,NULL,80  },
														  		      {NULL,NULL,NULL,NULL,NULL,NULL,80  ,NULL},
														  		      {NULL,0   ,80  ,NULL,NULL,NULL,NULL,NULL},
														  		      {NULL,16  ,NULL,NULL,112 ,NULL,NULL,NULL},
														  		      {NULL,NULL,NULL,NULL,NULL,NULL,NULL,48  },
														  		      {NULL,NULL,NULL,NULL,NULL,80  ,80  ,80  },
														  		      {224 ,NULL,NULL,NULL,NULL,NULL,80  ,NULL},
														  		      {NULL,NULL,NULL,NULL,NULL,NULL,NULL,64  }
																	};

const u8					TABLE_PAL_SPRITES_NIVEAU1[8][8]	=		{ {NULL,NULL,NULL,PAL1,NULL,PAL2,NULL,PAL1},
														  		      {NULL,NULL,NULL,NULL,NULL,NULL,PAL1,NULL},
														  		      {NULL,PAL1,PAL1,NULL,NULL,NULL,NULL,NULL},
														  		      {NULL,PAL1,NULL,NULL,PAL1,NULL,NULL,NULL},
														  		      {NULL,NULL,NULL,NULL,NULL,NULL,NULL,PAL1},
														  		      {NULL,NULL,NULL,NULL,NULL,PAL1,PAL1,PAL1},
														  		      {PAL2,NULL,NULL,NULL,NULL,NULL,PAL1,NULL},
														  		      {NULL,NULL,NULL,NULL,NULL,NULL,NULL,PAL1}
																	};




//******************************************************//
//                                                      //
//                   TABLES ENNEMIS                     //
//                                                      //
//******************************************************//

//////////////////////////////////////////////////////////
//                    ENNEMIS NIVEAU1                   //
//////////////////////////////////////////////////////////

const u8                 	TABLE_NB_ENNEMIS_NIVEAU1[8][8]		= 	{ {2,1,3,1,2,3,2,3},

														  		  	  {3,1,4,3,3,3,4,2},
														  		  	  {2,4,2,3,4,2,3,2},
														  		  	  {3,3,3,2,4,2,2,4},
														  		  	  {3,2,2,3,3,3,4,3},
														  		  	  {4,2,3,2,2,3,2,1},
														  		  	  {2,3,3,0,6,3,1,3},
														  		  	  {2,2,3,2,3,3,3,3}
																 	};

const u8                 	TABLE_INDEX_ENNEMIS_NIVEAU1[8][8]	=	{ {0,2,3,6,7,9,12,14},
														     	  	  {17,20,21,25,28,31,34,38},
														     	  	  {40,42,46,48,51,55,57,60},
														     	  	  {65,65,68,71,73,77,79,81},
														     	  	  {85,88,90,92,95,98,101,105},
														     	  	  {107,111,113,116,118,120,123,125},
														     	  	  {126,128,131,0,134,140,143,144},
														     	  	  {147,149,151,154,156,159,162,165}
														   		    };

const SpriteDefinition		*TABLE_ID_ENNEMIS_NIVEAU1[9]		=  	{ &tiles_SPR_SCORPION , &tiles_SPR_LEZARD , &tiles_SPR_GRENOUILLE , &tiles_SPR_POULPE , &tiles_SPR_SABLE , &tiles_SPR_MOUCHE , &tiles_SPR_SOLDAT_BLEU , &tiles_SPR_GOBLIN , &tiles_SPR_BLOB };

const u8					TABLE_ADR_ENNEMIS_NIVEAU1[169]		=	{ 0,0,1,1,1,1,2,2,3,4,4,4,0,0,4,4,4,
																	  4,4,4,0,4,4,4,4,5,5,5,6,6,3,6,6,3,0,0,0,0,4,4,
																	  4,4,0,0,0,0,2,2,5,5,5,7,7,7,7,7,3,6,6,6,6,6,
																	  4,4,4,0,0,0,5,5,5,7,7,1,1,1,1,5,3,6,3,6,6,6,3,
																	  4,4,4,4,4,7,7,6,6,6,0,0,0,5,5,5,8,8,7,3,7,3,3,
																	  0,0,0,0,0,8,0,0,0,8,8,5,5,2,2,2,0,0,8,
																	  0,0,0,8,8,8,8,8,8,8,0,0,8,8,2,2,2,2,0,0,3,
																	  0,0,0,8,8,8,8,8,8,8,8,8,0,0,0,8,8,8,8,8,3
																	};



//******************************************************//
//                                                      //
//                    TABLES NIVEAUX                    //
//                                                      //
//******************************************************//
// 0-0
// 0
// -40+184

// 3-6
// 768
// -40+184+(184*6)
const s16					TABLE_INIT_CAM_NIVEAUX[2][4]		=	{ {768      , 512  , 1536 , 256 },
																	  {-40+184+(184*6) , 1104 , 736  , 184 }
																	};
//3
//6
const u8					TABLE_INIT_INDEX_NIVEAUX[2][4]		=	{ {3,2,6,1},
																	  {6,6,4,1}
																	};

const TileSet				*TABLE_TILESET_NIVEAUX[2][4]		=	{ {&tileset_NIVEAU1_BG_B,&tileset_NIVEAU2_BG_B,&tileset_NIVEAU3_BG_B,&tileset_NIVEAU4_BG_B},
																      {&tileset_NIVEAU1_BG_A,&tileset_NIVEAU2_BG_A,&tileset_NIVEAU3_BG_A,&tileset_NIVEAU4_BG_A}
																	};
														
const MapDefinition			*TABLE_MAPDEF_NIVEAUX[2][4]			=	{ {&map_NIVEAU1_BG_B,&map_NIVEAU2_BG_B,&map_NIVEAU3_BG_B,&map_NIVEAU4_BG_B},
																	  {&map_NIVEAU1_BG_A,&map_NIVEAU2_BG_A,&map_NIVEAU3_BG_A,&map_NIVEAU4_BG_A}
																	};

const MapDefinition			*TABLE_MAPCOLL_NIVEAUX[4]			=	{ &map_COLLISION_NIVEAU1 , &map_COLLISION_NIVEAU1 , &map_COLLISION_NIVEAU1 , &map_COLLISION_NIVEAU1 };																	

const u16					TABLE_OFFSET_COLLISION[8][8]		=	{ {0  , 32 , 64 , 96 , 128 , 160 , 192 , 224},
																	  {18 , 41 , 64 , 87 , 110 , 133 , 156 , 179}
																	};

const Image					*TABLE_ADR_EAU_NIVEAUX[4][4]		=	{ {&image_EAU1_NIVEAU1  , &image_EAU2_NIVEAU1 , &image_EAU3_NIVEAU1 , &image_EAU4_NIVEAU1},
																	  {&image_EAU1_NIVEAU1  , &image_EAU2_NIVEAU1 , &image_EAU3_NIVEAU1 , &image_EAU4_NIVEAU1},
																	  {&image_EAU1_NIVEAU1  , &image_EAU2_NIVEAU1 , &image_EAU3_NIVEAU1 , &image_EAU4_NIVEAU1},
																	  {&image_EAU1_NIVEAU1  , &image_EAU2_NIVEAU1 , &image_EAU3_NIVEAU1 , &image_EAU4_NIVEAU1}
																	};

const Image					*TABLE_ADR_CASCADE_NIVEAUX[4][4]	=	{ {&image_CASCADE1_NIVEAU1  , &image_CASCADE2_NIVEAU1 , &image_CASCADE3_NIVEAU1 , &image_CASCADE4_NIVEAU1},
																	  {&image_CASCADE1_NIVEAU1  , &image_CASCADE2_NIVEAU1 , &image_CASCADE3_NIVEAU1 , &image_CASCADE4_NIVEAU1},
																	  {&image_CASCADE1_NIVEAU1  , &image_CASCADE2_NIVEAU1 , &image_CASCADE3_NIVEAU1 , &image_CASCADE4_NIVEAU1},
																	  {&image_CASCADE1_NIVEAU1  , &image_CASCADE2_NIVEAU1 , &image_CASCADE3_NIVEAU1 , &image_CASCADE4_NIVEAU1}
																	};