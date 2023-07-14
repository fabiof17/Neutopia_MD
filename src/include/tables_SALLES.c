#include <genesis.h>

#include "palettes.h"
#include "structures.h"

#include "sprites_DECOR.h"
#include "sprites_ENNEMIS.h"

#include "maps_NIVEAUX.h"
#include "maps_PNJ.h"
#include "maps_SALLES.h"


//******************************************************//
//                                                      //
//                     TABLES SALLES                    //
//                                                      //
//******************************************************//

//////////////////////////////////////////////////////////
//                     SALLES NIVEAU 1                  //
//////////////////////////////////////////////////////////

const struct_SALLE_					TABLE_SALLES_NIVEAU1[44]		=	{
																			{&image_SALLE_1 , &tiles_PNJ1},
																			{NULL , NULL},
																			{&image_SALLE_2 , &tiles_PNJ2},
																			{&image_SALLE_3 , &tiles_PNJ3},
																			{&image_SALLE_4 , &tiles_PNJ4},
																			{&image_SALLE_2 , &tiles_PNJ5},
																			{&image_SALLE_5 , &tiles_PNJ6},

																		   	{&image_SALLE_6 , NULL},
																			{&image_SALLE_7 , NULL},
																			{&image_SALLE_8 , NULL},
																			{&image_SALLE_7 , NULL},
																			{&image_SALLE_2 , NULL},
																			{&image_SALLE_7 , NULL},

																		   	{&image_SALLE_7 , NULL},
																			{&image_SALLE_5 , NULL},
																			{NULL , NULL},
																			{&image_SALLE_2 , NULL},
																			{&image_SALLE_5 , NULL},
																			{&image_SALLE_7 , NULL},
																			{NULL , NULL},

																		   	{&image_SALLE_2 , NULL},
																			{&image_SALLE_2 , NULL},
																			{&image_SALLE_6 , NULL},

																		   	{&image_SALLE_5 , NULL},
																			{&image_SALLE_1 , NULL},
																			{&image_SALLE_1 , NULL},

																		  	{&image_SALLE_2 , NULL},
																			{&image_SALLE_7 , NULL},
																			{NULL , NULL},
																			{NULL , NULL},
																			{&image_SALLE_4, NULL},
																			{&image_SALLE_3 , NULL},

																		   	{&image_SALLE_4 , NULL},
																			{&image_SALLE_3 , NULL},
																			{&image_SANCTUAIRE, NULL},
																			{&image_SALLE_2 , NULL},
																			{&image_SALLE_7 , NULL},
																			{&image_SALLE_5 , NULL},

																		   	{&image_SALLE_4 , NULL},
																			{&image_SALLE_2 , NULL},
																			{&image_SALLE_7 , NULL},
																			{&image_SALLE_7 , NULL},
																			{&image_SALLE_1 , NULL}
																		};
																		
//******************************************************//
//                                                      //
//                     TABLES SALLES                    //
//                                                      //
//******************************************************//

const struct_JOYAU_                 TABLE_JOYAUX[8];





