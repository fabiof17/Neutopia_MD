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
																					{ARBRE,112,104,NULL,NULL,0,0,&tiles_SPR_ARBRE_BRULE,NULL,PAL3},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{ARBRE,64,88,NULL,NULL,0,0,&tiles_SPR_ARBRE_BRULE,NULL,PAL3},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{ROCHER,144,120,0,NULL,NULL,NULL,&tiles_SPR_ROCHER_NIVEAU1,NULL,PAL1}},

																				   {{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{ROCHER,192,120,0,NULL,NULL,NULL,&tiles_SPR_ROCHER_NIVEAU1,NULL,PAL3},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL}},
																					
																				   {{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{ARBRE,80,120,NULL,NULL,0,0,&tiles_SPR_ARBRE_BRULE,NULL,PAL3},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL}},
																															
																				   {{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{ARBRE,128,152,NULL,NULL,0,0,&tiles_SPR_ARBRE_BRULE,NULL,PAL3},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL}},
																															
																				   {{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{ARBRE,112,88,NULL,NULL,0,0,&tiles_SPR_ARBRE_BRULE,NULL,PAL3}},

																				   {{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,PAL3},
																					{ARBRE,80,120,NULL,NULL,0,0,&tiles_SPR_ARBRE_BRULE,NULL,PAL3},
																					{ARBRE,96,120,NULL,NULL,0,0,&tiles_SPR_ARBRE_BRULE,NULL,PAL3},
																					{ROCHER,144,120,0,NULL,NULL,NULL,&tiles_SPR_ROCHER_NIVEAU1,NULL,PAL3}},

																				   {{ARBRE,224,136,NULL,NULL,0,0,&tiles_SPR_ARBRE_BRULE,NULL,PAL3},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{ROCHER,96,120,0,NULL,NULL,NULL,&tiles_SPR_ROCHER_NIVEAU1,NULL,PAL3},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL}},

																				   {{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
																					{ARBRE,128,104,NULL,NULL,0,0,&tiles_SPR_ROCHER_NIVEAU1,NULL,PAL3}}
																				};