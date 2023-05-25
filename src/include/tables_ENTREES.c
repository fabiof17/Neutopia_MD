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

