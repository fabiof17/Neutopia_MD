#include <genesis.h>

#include "palettes.h"
#include "sprites_DECOR.h"
#include "sprites_ENNEMIS.h"

#include "maps_NIVEAUX.h"
#include "maps_SALLES.h"


//******************************************************//
//                                                      //
//                     TABLES SALLES                    //
//                                                      //
//******************************************************//

//////////////////////////////////////////////////////////
//                     SALLES NIVEAU 1                  //
//////////////////////////////////////////////////////////

const Image					*TABLE_SALLES_NIVEAU1[44]				=	{ &image_SALLE_1 , NULL , &image_SALLE_2 , &image_SALLE_3 , &image_SALLE_4 , &image_SALLE_2 , &image_SALLE_5 ,
																		  &image_SALLE_6 , &image_SALLE_7 , &image_SALLE_8 , &image_SALLE_7 , &image_SALLE_2 , &image_SALLE_7 ,
																		  &image_SALLE_7 , &image_SALLE_5 , NULL , &image_SALLE_2 , &image_SALLE_5 , &image_SALLE_7 , NULL ,
																		  &image_SALLE_2 , &image_SALLE_2 , &image_SALLE_6 ,
																		  &image_SALLE_5 , &image_SALLE_1 , &image_SALLE_1 ,
																		  &image_SALLE_2 , &image_SALLE_7 , NULL , NULL , &image_SALLE_4 , &image_SALLE_3 ,
																		  NULL , &image_SALLE_3 , &image_SALLE_9 , &image_SALLE_2 , &image_SALLE_7 , &image_SALLE_5 ,
																		  &image_SALLE_4 , &image_SALLE_2 , &image_SALLE_7 , &image_SALLE_7 , NULL
																		};

// POINTEUR SUR LA TABLE DES SALLESDU NIVEAU EN COURS
const Image					*ptr_TABLE_SALLES;




