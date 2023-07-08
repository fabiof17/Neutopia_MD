#include <genesis.h>


#include "palettes.h"
#include "structures.h"
#include "variables.h"

#include "sprites_DECOR.h"


//******************************************************//
//                                                      //
//                  TABLES OBJETS DECOR                 //
//                                                      //
//******************************************************//

//////////////////////////////////////////////////////////
//                     OBJETS NIVEAU 1                  //
//////////////////////////////////////////////////////////

// TABLE PROPRIETES DES OBJETS NIVEAU 1
const struct_OBJET_DECOR_				TABLE_OBJETS_DECOR_NIVEAU1[8][8]	=	{
																				   {{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{ARBRE,NULL,NULL,0,NULL,0,0,NULL,NULL,PAL1},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{ARBRE,NULL,NULL,0,NULL,0,0,NULL,NULL,PAL1},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{ROCHER,NULL,NULL,0,NULL,NULL,NULL,NULL,NULL,PAL3}},

																				   {{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{ROCHER,NULL,NULL,0,NULL,NULL,NULL,NULL,NULL,PAL3},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL}},
																					
																				   {{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{ARBRE,NULL,NULL,0,NULL,0,0,NULL,NULL,PAL1},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL}},
																															
																				   {{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{ARBRE,NULL,NULL,0,NULL,0,0,NULL,NULL,PAL1},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL}},
																															
																				   {{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{ARBRE,NULL,NULL,0,NULL,NULL,NULL,NULL,NULL,PAL1}},

																				   {{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{ARBRE,NULL,NULL,0,NULL,0,0,NULL,NULL,PAL1},
																					{ARBRE,NULL,NULL,0,NULL,0,0,NULL,NULL,PAL1},
																					{ARBRE,NULL,NULL,0,NULL,0,0,NULL,NULL,PAL1},
																					{ROCHER,NULL,NULL,0,NULL,NULL,NULL,NULL,NULL,PAL3}},

																				   {{ARBRE,224,136,0,NULL,0,0,&tiles_SPR_ARBRE_BRULE,NULL,PAL3},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{ROCHER,NULL,NULL,0,NULL,NULL,NULL,NULL,NULL,PAL3},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL}},

																				   {{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{ARBRE,NULL,NULL,0,NULL,NULL,NULL,NULL,NULL,PAL1}}
																				};