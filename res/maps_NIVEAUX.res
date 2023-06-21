//**********************************************************************************//
//                                                                                  //
//                                   TILESET                                        //
//                                                                                  //
//**********************************************************************************//

TILESET tileset_NIVEAU1_BG_B "maps/niveaux/tiles_NIVEAU1_BG_B.png" NONE ALL
TILESET tileset_NIVEAU1_BG_A "maps/niveaux/tiles_NIVEAU1_BG_A.png" NONE ALL

TILESET tileset_NIVEAU2_BG_B "maps/niveaux/tiles_NIVEAU1_BG_B.png" NONE ALL
TILESET tileset_NIVEAU2_BG_A "maps/niveaux/tiles_NIVEAU1_BG_A.png" NONE ALL

TILESET tileset_NIVEAU3_BG_B "maps/niveaux/tiles_NIVEAU1_BG_B.png" NONE ALL
TILESET tileset_NIVEAU3_BG_A "maps/niveaux/tiles_NIVEAU1_BG_A.png" NONE ALL

TILESET tileset_NIVEAU4_BG_B "maps/niveaux/tiles_NIVEAU1_BG_B.png" NONE ALL
TILESET tileset_NIVEAU4_BG_A "maps/niveaux/tiles_NIVEAU1_BG_A.png" NONE ALL




//**********************************************************************************//
//                                                                                  //
//                                     MAP                                          //
//                                                                                  //
//**********************************************************************************//

MAP map_NIVEAU1_BG_B                        "maps/niveaux/tiles_NIVEAU1_BG_B.png"       tileset_NIVEAU1_BG_B        NONE
MAP map_NIVEAU1_BG_A                        "maps/niveaux/tiles_NIVEAU1_BG_A.png"       tileset_NIVEAU1_BG_A        NONE

MAP map_NIVEAU2_BG_B                        "maps/niveaux/tiles_NIVEAU1_BG_B.png"       tileset_NIVEAU2_BG_B        NONE
MAP map_NIVEAU2_BG_A                        "maps/niveaux/tiles_NIVEAU1_BG_A.png"       tileset_NIVEAU2_BG_A        NONE

MAP map_NIVEAU3_BG_B                        "maps/niveaux/tiles_NIVEAU1_BG_B.png"       tileset_NIVEAU3_BG_B        NONE
MAP map_NIVEAU3_BG_A                        "maps/niveaux/tiles_NIVEAU1_BG_A.png"       tileset_NIVEAU3_BG_A        NONE

MAP map_NIVEAU4_BG_B                        "maps/niveaux/tiles_NIVEAU1_BG_B.png"       tileset_NIVEAU4_BG_B        NONE
MAP map_NIVEAU4_BG_A                        "maps/niveaux/tiles_NIVEAU1_BG_A.png"       tileset_NIVEAU4_BG_A        NONE





//**********************************************************************************//
//                                                                                  //
//                                    IMAGE                                         //
//                                                                                  //
//**********************************************************************************//

IMAGE image_SANCTUAIRE                      "maps/niveaux/tiles_SANCTUAIRE.png"                     NONE ALL
IMAGE image_DONJON_NIVEAU1                  "maps/niveaux/tiles_DONJON_NIVEAU1.png"                 NONE ALL
IMAGE image_ESCALIER_NIVEAU1                "maps/niveaux/tiles_ESCALIER_NIVEAU1.png"               NONE ALL
IMAGE image_CAVE1_NIVEAU1                   "maps/niveaux/tiles_CAVE1_NIVEAU1.png"                  NONE ALL
IMAGE image_CAVE2_NIVEAU1                   "maps/niveaux/tiles_CAVE2_NIVEAU1.png"                  NONE ALL
IMAGE image_CAVE3_NIVEAU1                   "maps/niveaux/tiles_CAVE3_NIVEAU1.png"                  NONE ALL
IMAGE image_CAVE4_NIVEAU1                   "maps/niveaux/tiles_CAVE4_NIVEAU1.png"                  NONE ALL
IMAGE image_CAVE5_NIVEAU1                   "maps/niveaux/tiles_CAVE5_NIVEAU1.png"                  NONE ALL
IMAGE image_CAVERNE_NIVEAU1                 "maps/niveaux/tiles_CAVERNE_NIVEAU1.png"                NONE ALL





//**********************************************************************************//
//                                                                                  //
//                                  COLLISIONS                                      //
//                                                                                  //
//**********************************************************************************//

TILESET tileset_COLLISION_NIVEAU1               "maps/niveaux/tilemap_COLLISION_NIVEAU1.png"                                        NONE ALL
TILEMAP tilemap_COLLISION_NIVEAU1               "maps/niveaux/tilemap_COLLISION_NIVEAU1.png"        tileset_COLLISION_NIVEAU1       NONE ALL
MAP map_COLLISION_NIVEAU1                       "maps/niveaux/tilemap_COLLISION_NIVEAU1.png"        tileset_COLLISION_NIVEAU1       NONE
