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

const u8					TABLE_ID_ENTREES_NIVEAU1[43]		=	{ 1,2,1,1,1,1,1,
																	  1,1,1,1,1,1,
																	  1,1,1,1,1,1,2,
																	  1,1,1,
																	  1,1,1,
																	  1,1,1,1,1,1,
																	  1,1,1,1,1,1,
																	  1,1,1,1,1
																	};

const u8					TABLE_POS_ENTREES_NIVEAU1[4][2]		=	{ {1,0},
																	  {2,7},
																	  {1,4},
																	  {3,6}
																	};

const SpriteDefinition		*TABLE_ADR_ENTREES_NIVEAU1[4]		=	{ &tiles_SPR_DONJON_NIVEAU1 , &tiles_SPR_DONJON_NIVEAU1 , &tiles_SPR_ENTREE_NIVEAU1 , &tiles_SPR_SANCTUAIRE };
/*
const TileMap				*TABLE_TILESET_ENTREES_NIVEAU1[43]	=	{ &tileset_SALLE_0_0,  };
*/

