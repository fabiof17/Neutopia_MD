#include <genesis.h>

#include "palettes.h"
#include "sprites_DECOR.h"
#include "sprites_ENNEMIS.h"

#include "maps_NIVEAUX.h"
#include "maps_ENTREES.h"
#include "maps_SALLES.h"
#include "maps_DONJONS.h"


//******************************************************//
//                                                      //
//                     TABLES SALLES                    //
//                                                      //
//******************************************************//

// OFFSET POUR LIRE LES TABLEAUX SUIVANTS
// NIVEAU 1 : 43 ENTREES
// NIVEAU 2 :
// NIVEAU 3 : 
const u16					TABLE_OFFSET_ENTREES[4]					=	{0,43,NULL,NULL};


// TILESET DES SALLES + DONJONS
const TileSet				*TABLE_TILESET_ENTREES[43]				=	{ &tileset_SALLE_1 , NULL , &tileset_SALLE_2 , &tileset_SALLE_3 , &tileset_SALLE_4 , &tileset_SALLE_2 , &tileset_SALLE_5 ,
																		  &tileset_SALLE_6 , &tileset_SALLE_7 , &tileset_SALLE_8 , &tileset_SALLE_7 , &tileset_SALLE_2 , &tileset_SALLE_7 ,
																		  &tileset_SALLE_7 , &tileset_SALLE_5 , NULL , &tileset_SALLE_2 , &tileset_SALLE_5 , &tileset_SALLE_7 , NULL ,
																		  &tileset_SALLE_2 , &tileset_SALLE_2 , &tileset_SALLE_6 ,
																		  &tileset_SALLE_5 , &tileset_SALLE_1 , &tileset_SALLE_1 ,
																		  &tileset_SALLE_2 , &tileset_SALLE_7 , NULL , NULL , &tileset_SALLE_4 , &tileset_SALLE_3 ,
																		  NULL , &tileset_SALLE_3 , &tileset_SALLE_9 , &tileset_SALLE_2 , &tileset_SALLE_7 , &tileset_SALLE_5 ,
																		  &tileset_SALLE_4 , &tileset_SALLE_2 , &tileset_SALLE_7 , &tileset_SALLE_7 , NULL
																		};


// MAP DES SALLES + DONJONS
const MapDefinition			*TABLE_MAPDEF_ENTREES[43]				=	{ &map_SALLE_1 , NULL , &map_SALLE_2 , &map_SALLE_3 , &map_SALLE_4 , &map_SALLE_2 , &map_SALLE_5 ,
																		  &map_SALLE_6 , &map_SALLE_7 , &map_SALLE_8 , &map_SALLE_7 , &map_SALLE_2 , &map_SALLE_7 ,
																		  &map_SALLE_7 , &map_SALLE_5 , NULL , &map_SALLE_2 , &map_SALLE_5 , &map_SALLE_7 , NULL ,
																		  &map_SALLE_2 , &map_SALLE_2 , &map_SALLE_6 ,
																		  &map_SALLE_5 , &map_SALLE_1 , &map_SALLE_1 ,
																		  &map_SALLE_2 , &map_SALLE_7 , NULL , NULL , &map_SALLE_4 , &map_SALLE_3 ,
																		  NULL , &map_SALLE_3 , &map_SALLE_9 , &map_SALLE_2 , &map_SALLE_7 , &map_SALLE_5 ,
																		  &map_SALLE_4 , &map_SALLE_2 , &map_SALLE_7 , &map_SALLE_7 , NULL
																		};


// PALETTES DES SALLES + DONJONS
const Palette				*TABLE_ADR_PAL_ENTREES[43]				=	{ &palette_SALLE_1,NULL,&palette_SALLE_2,&palette_SALLE_3,&palette_SALLE_4,&palette_SALLE_2,&palette_SALLE_5,
																		  &palette_SALLE_6,&palette_SALLE_7,&palette_SALLE_8,&palette_SALLE_7,&palette_SALLE_2,&palette_SALLE_7,
																		  &palette_SALLE_7,&palette_SALLE_5,NULL,&palette_SALLE_2,&palette_SALLE_5,&palette_SALLE_7,NULL,
																		  &palette_SALLE_2,&palette_SALLE_2,&palette_SALLE_6,
																		  &palette_SALLE_5,&palette_SALLE_1,&palette_SALLE_1,
																		  &palette_SALLE_2,&palette_SALLE_7,NULL,NULL,&palette_SALLE_4,&palette_SALLE_3,
																		  NULL,&palette_SALLE_3,&palette_SALLE_9,&palette_SALLE_2,&palette_SALLE_7,&palette_SALLE_5,
																		  &palette_SALLE_4,&palette_SALLE_2,&palette_SALLE_7,&palette_SALLE_7,NULL
																		};





