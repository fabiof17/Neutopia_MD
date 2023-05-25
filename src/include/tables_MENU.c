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

