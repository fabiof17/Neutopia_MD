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
//                    TABLES DONJONS                    //
//                                                      //
//******************************************************//

const s16					TABLE_INIT_CAM_DONJONS[2][8]		=	{ {256,1024,768,768,768,1024,1024,768},
																	  {1288,1104,1288,1288,1288,1288,1288,920}
																	};

const u8					TABLE_INIT_INDEX_DONJONS[2][8]		=	{ {1,4,3,3,3,4,4,3},
																	  {7,6,7,7,7,7,7,5}
																	};

