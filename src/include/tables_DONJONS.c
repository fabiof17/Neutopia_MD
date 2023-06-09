#include <genesis.h>

#include "palettes.h"
#include "sprites_DECOR.h"
#include "sprites_ENNEMIS.h"

#include "maps_NIVEAUX.h"
#include "maps_SALLES.h"


//******************************************************//
//                                                      //
//                    TABLES DONJONS                    //
//                                                      //
//******************************************************//

// POSITION DE DEPART DE LA CAMERA POUR LES DONJONS
// X
// Y
const s16					TABLE_INIT_CAM_DONJONS[2][8]		=	{ {256,1024,768,768,768,1024,1024,768},
																	  {1288,1104,1288,1288,1288,1288,1288,920}
																	};


// INDEX DE DEPART POUR LE CARTE DES DONJONS
// X
// Y
const u8					TABLE_INIT_INDEX_DONJONS[2][8]		=	{ {1,4,3,3,3,4,4,3},
																	  {7,6,7,7,7,7,7,5}
																	};

