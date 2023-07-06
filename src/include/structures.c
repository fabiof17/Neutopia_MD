#include <genesis.h>

#include "structures.h"


//******************************************************//
//                                                      //
//                    STRUCTURE JOUEUR                  //
//                                                      //
//******************************************************//

struct_JOUEUR_ JOUEUR;




//******************************************************//
//                                                      //
//                      STRUCTURE TIR                   //
//                                                      //
//******************************************************//

//struct_TIR_ TIR;

struct_TIR_						LISTE_TIR[2];


//******************************************************//
//                                                      //
//                   STRUCTURE ENTREE                   //
//                                                      //
//******************************************************//

const struct_ENTREE_					*ptr_TABLE_ENTREES;




//******************************************************//
//                                                      //
//                  STRUCTURE ENNEMI                    //
//                                                      //
//******************************************************//




//******************************************************//
//                                                      //
//                 STRUCTURE OBJET DECOR                //
//                                                      //
//******************************************************//

																				
// LISTE DES OBJETS DANS LE NIVEAU EN COURS
struct_OBJET_DECOR_						LISTE_OBJETS_DECOR[2];

// POINTEUR SUR LA TABLE DES OBJETS DU NIVEAU EN COURS
const struct_OBJET_DECOR_				*ptr_TABLE_OBJETS_DECOR;