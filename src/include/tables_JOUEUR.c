#include <genesis.h>

#include "palettes.h"

#include "sprites_JOUEUR.h"


//******************************************************//
//                                                      //
//                    TABLES JOUEUR                     //
//                                                      //
//******************************************************//

const u8					TABLE_PAL_JOUEUR[4]					=	{ PAL0,PAL0,PAL3,PAL0 };

const s16                   TABLE_POS_EPEE[4][4]                =   { {5,4,22,-14},
                                                                      {28,-10,15,15}
                                                                    };

const s16                   TABLE_POS_PT1_COLL_DECOR[2][4]      =   { {4,4,16,7},
                                                                      {31,23,31,31}
                                                                    };

const s16                   TABLE_POS_PT2_COLL_DECOR[2][4]      =   { {19,19,16,7},
                                                                      {31,23,23,23}
                                                                    };

