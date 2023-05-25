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
//                     TABLES SALLES                    //
//                                                      //
//******************************************************//

const u16					TABLE_OFFSET_SALLES[4]					=	{0,43,NULL,NULL};

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





