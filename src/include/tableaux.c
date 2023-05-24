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
//                   TABLES GLOBALES                    //
//                                                      //
//******************************************************//

const u16					TABLE_OFFSET_SALLES[4]				=	{0,43,NULL,NULL};




//******************************************************//
//                                                      //
//                    TABLES DECOR                      //
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
//                 TABLES OBJETS MENU                   //
//                                                      //
//******************************************************//

bool						TABLE_OBJETS_HAUT[2][4]				=	{ {NULL,NULL,NULL,NULL},
																	  {NULL,NULL,NULL,NULL}
																	};


u16							TABLE_ADR_VRAM_OBJETS_HAUT[2][4]	=	{ {NULL,NULL,NULL,NULL},
																	  {NULL,NULL,NULL,NULL}
																	};

const u8					TABLE_PAL_OBJETS_HAUT[2][4]			=	{ {PAL3,PAL3,PAL0,PAL0},
																	  {PAL0,PAL0,PAL0,PAL0}
																	};




bool						TABLE_OBJETS_BAS[2][4]				=	{ {NULL,NULL,NULL,NULL},
																	  {NULL,NULL,NULL,NULL}
																	};

u16							TABLE_ADR_VRAM_OBJETS_BAS[2][4]		=	{ {NULL,NULL,NULL,NULL},
																	  {NULL,NULL,NULL,NULL}
																	};

const u8					TABLE_PAL_OBJETS_BAS[2][4]			=	{ {PAL0,PAL3,PAL0,PAL0},
																	  {PAL3,PAL0,PAL0,PAL0}
																	};




//******************************************************//
//                                                      //
//                    TABLES NIVEAUX                    //
//                                                      //
//******************************************************//

const s16					TABLE_INIT_CAM_NIVEAUX[2][4]		=	{ {768,512,1536,256},
																	  {1104,1104,736,184}
																	};

const u8					TABLE_INIT_INDEX_NIVEAUX[2][4]		=	{ {3,2,6,1},
																	  {6,6,4,1}
																	};

const TileSet				*TABLE_TILESET_NIVEAUX[2][4]		=	{ {&tileset_NIVEAU1_BG_B,&tileset_NIVEAU2_BG_B,&tileset_NIVEAU3_BG_B,&tileset_NIVEAU4_BG_B},
																      {&tileset_NIVEAU1_BG_A,&tileset_NIVEAU2_BG_A,&tileset_NIVEAU3_BG_A,&tileset_NIVEAU4_BG_A}
																	};
														
const MapDefinition			*TABLE_MAPDEF_NIVEAUX[2][4]			=	{ {&map_NIVEAU1_BG_B,&map_NIVEAU2_BG_B,&map_NIVEAU3_BG_B,&map_NIVEAU4_BG_B},
																	  {&map_NIVEAU1_BG_A,&map_NIVEAU2_BG_A,&map_NIVEAU3_BG_A,&map_NIVEAU4_BG_A}
																	};




//******************************************************//
//                                                      //
//                    TABLES ENTREES                    //
//                                                      //
//******************************************************//

//////////////////////////////////////////////////////////
//                    ENTREES NIVEAU 1                  //
//////////////////////////////////////////////////////////

const u16					TABLE_OFFSET_TILE_NIVEAUX[8][8]		=	{ {0,32,64,96,128,160,192,224},
																	  {0,6144,12288,18432,24576,30720,36864,43008}
																	};

const u8					TABLE_ID_ENTREES_NIVEAU1[43]		=	{ 1,2,1,1,1,1,1,
																	  1,1,1,1,1,1,
																	  1,1,1,1,1,1,2,
																	  1,1,1,
																	  1,1,1,
																	  1,1,1,1,1,1,
																	  1,1,1,1,1,1,
																	  1,1,1,1,1
																	};
/*
const TileMap				*TABLE_TILESET_ENTREES_NIVEAU1[43]	=	{ &tileset_SALLE_0_0,  };
*/




//******************************************************//
//                                                      //
//                     TABLES SALLES                    //
//                                                      //
//******************************************************//

const TileSet				*TABLE_TILESET_SALLES[43]				=	{ &tileset_NIVEAU1_SALLE_1 , NULL , &tileset_NIVEAU1_SALLE_40 , NULL , NULL , NULL , NULL ,
																		  NULL , &tileset_NIVEAU1_SALLE_14 , &tileset_NIVEAU1_SALLE_10 , &tileset_NIVEAU1_SALLE_14 , NULL , NULL ,
																		  &tileset_NIVEAU1_SALLE_14 , &tileset_NIVEAU1_SALLE_24 , NULL , &tileset_NIVEAU1_SALLE_40 , &tileset_NIVEAU1_SALLE_24 , &tileset_NIVEAU1_SALLE_14 , NULL ,
																		  NULL , NULL , NULL ,
																		  &tileset_NIVEAU1_SALLE_24 , &tileset_NIVEAU1_SALLE_1 , NULL ,
																		  &tileset_NIVEAU1_SALLE_40 , &tileset_NIVEAU1_SALLE_14 , NULL , NULL , &tileset_NIVEAU1_SALLE_39 , &tileset_NIVEAU1_SALLE_32 ,
																		  NULL , &tileset_NIVEAU1_SALLE_32 , &tileset_NIVEAU1_SALLE_35 , &tileset_NIVEAU1_SALLE_40 , &tileset_NIVEAU1_SALLE_14 , &tileset_NIVEAU1_SALLE_24 ,
																		  &tileset_NIVEAU1_SALLE_39 , &tileset_NIVEAU1_SALLE_40 , &tileset_NIVEAU1_SALLE_14 , &tileset_NIVEAU1_SALLE_14 , NULL
																		};

const MapDefinition			*TABLE_MAPDEF_SALLES[43]				=	{ &map_NIVEAU1_SALLE_1 , NULL , &map_NIVEAU1_SALLE_40 , NULL , NULL , NULL , NULL ,
																		  NULL , &map_NIVEAU1_SALLE_14 , &map_NIVEAU1_SALLE_10 , &map_NIVEAU1_SALLE_14 , NULL , NULL ,
																		  &map_NIVEAU1_SALLE_14 , &map_NIVEAU1_SALLE_24 , NULL , &map_NIVEAU1_SALLE_40 , &map_NIVEAU1_SALLE_24 , &map_NIVEAU1_SALLE_14 , NULL ,
																		  NULL , NULL , NULL ,
																		  &map_NIVEAU1_SALLE_24 , &map_NIVEAU1_SALLE_1 , NULL ,
																		  &map_NIVEAU1_SALLE_40 , &map_NIVEAU1_SALLE_14 , NULL , NULL , &map_NIVEAU1_SALLE_39 , &map_NIVEAU1_SALLE_32 ,
																		  NULL , &map_NIVEAU1_SALLE_32 , &map_NIVEAU1_SALLE_35 , &map_NIVEAU1_SALLE_40 , &map_NIVEAU1_SALLE_14 , &map_NIVEAU1_SALLE_24 ,
																		  &map_NIVEAU1_SALLE_39 , &map_NIVEAU1_SALLE_40 , &map_NIVEAU1_SALLE_14 , &map_NIVEAU1_SALLE_14 , NULL
																		};

const Palette				*TABLE_ADR_PAL_SALLES[43]				=	{ &palette_NIVEAU1_SALLE_1 ,NULL,NULL,NULL,NULL,NULL,NULL,
																		  NULL,NULL,NULL,NULL,NULL,NULL,
																		  NULL,NULL,NULL,NULL,NULL,NULL,NULL,
																		  NULL,NULL,NULL,
																		  NULL,NULL,NULL,
																		  NULL,NULL,NULL,NULL,NULL,NULL,
																		  NULL,NULL,NULL,NULL,NULL,NULL,
																		  NULL,NULL,NULL,NULL,NULL
																		};





//******************************************************//
//                                                      //
//                    TABLES DONJONS                    //
//                                                      //
//******************************************************//

const s16					TABLE_INIT_CAM_DONJONS[2][8]		=	{ {256,1024,768,768,768,1024,1024,768},
																	  {1288,1104,1288,1288,1288,1288,1288,920}
																	};

const u8					TABLE_INIT_INDEX_DONJONS[2][8]		=	{ {1,4,3,3,3,4,4,3},
																	  {7,6,7,7,7,7,7,5}
																	};

