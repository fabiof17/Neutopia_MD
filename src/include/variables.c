#include <genesis.h>

//******************************************************//
//                                                      //
//                        GLOBALES                      //
//                                                      //
//******************************************************//

char texteSortie[3];

u8 scene_JEU = 0;                       //  init -->  init_VARIABLES_GENERALES()
u8 etat_JEU = 0;                        //  init -->  init_VARIABLES_GENERALES()

u8 type_DECOR = 0;                      //  init -->  init_VARIABLES_GENERALES()

bool PAUSE = 0;                         //  init -->  init_VARIABLES_GENERALES()
bool GAMEOVER = 0;                      //  init -->  init_VARIABLES_GENERALES()

u16 nb_BOMBES = 0;                      //  init -->  init_VARIABLES_GENERALES()
u16 nb_GOLD = 0;                        //  init -->  init_VARIABLES_GENERALES()

u8 niveau_EPEE = 0;                     //  init -->  init_VARIABLES_GENERALES()
u8 niveau_BOUCLIER = 0;                 //  init -->  init_VARIABLES_GENERALES()
u8 niveau_ARMURE = 0;

//bool tiles_ARRET_OK = 0;
//bool tiles_ATTAQUE_OK = 0;

u16 id_TILE1 = 0;                       //  init -->  init_VARIABLES_GENERALES()
u16 id_TILE2 = 0;                       //  init -->  init_VARIABLES_GENERALES()
u16 id_TILE3 = 0;                       //  init -->  init_VARIABLES_GENERALES()
u16 id_TILE4 = 0;                       //  init -->  init_VARIABLES_GENERALES()



u8 etat_JOUEUR = 0;                     //  init -->  init_JOUEUR()
u8 axe_JOUEUR = 0;                      //  init -->  init_JOUEUR()

u8 compteur_SCROLLING = 0;              //  init -->  init_VARIABLES_GENERALES()
u8 duree_SCROLLING = 0;                 //  init -->  init_VARIABLES_GENERALES()

u8 index_X_CARTE = 0;
u8 index_Y_CARTE = 0;

u8 nb_ENNEMIS = 0;




//******************************************************//
//                                                      //
//                         TITRE                        //
//                                                      //
//******************************************************//

bool titre_OK = 0;                      //  init -->  init_VARIABLES_GENERALES()
u8 phase_TITRE = 0;                     //  init -->  init_VARIABLES_GENERALES()


//******************************************************//
//                                                      //
//                         INTRO                        //
//                                                      //
//******************************************************//

bool intro_OK = 0;


//******************************************************//
//                                                      //
//                         MENU                         //
//                                                      //
//******************************************************//

bool menu_OK = 0;

u8 index_X_MENU = 0;
u8 index_Y_MENU = 0;

u16 pos_X_CURSEUR = 0;
u16 pos_Y_CURSEUR = 0;

u8 index_X_CARTE_MENU = 0;
u8 index_Y_CARTE_MENU = 0;

u8 id_OBJET_MENU = 0;

bool cle_OK = 0;
bool crystal_OK = 0;

u16 adr_VRAM_MENU = 0;
u16 adr_VRAM_BOUSSOLE = 0;

u16 adr_VRAM_ENERGIE_PLEIN = 0;
u16 adr_VRAM_ENERGIE_MOITIE = 0;
u16 adr_VRAM_ENERGIE_VIDE = 0;

u16 adr_VRAM_VIDE = 0;
u16 adr_VRAM_AILES = 0;
u16 adr_VRAM_ANNEAU = 0;
u16 adr_VRAM_ARMURE = 0;
u16 adr_VRAM_BOMBE = 0;
u16 adr_VRAM_BOTTES = 0;
u16 adr_VRAM_BOUCLIER = 0;
u16 adr_VRAM_CLE = 0;
u16 adr_VRAM_CLOCHE = 0;
u16 adr_VRAM_CRYSTAL = 0;
u16 adr_VRAM_EPEE = 0;
u16 adr_VRAM_FIOLE = 0;
u16 adr_VRAM_GOUTTE = 0;
u16 adr_VRAM_LIVRE = 0;
u16 adr_VRAM_POTION = 0;
u16 adr_VRAM_SCEPTRE = 0;

u16 adr_VRAM_CHIFFRES = 0;

u8 nb_ENERGIE = 5;
u8 energie_MAX = 5;




//******************************************************//
//                                                      //
//                        NIVEAUX                       //
//                                                      //
//******************************************************//

bool niveau_OK = 0;
u8 num_NIVEAU = 0;

u32 pos_X_CAM = 0;
u32 pos_Y_CAM = 0;

u32 pos_X_CAM_NIVEAU = 0;
u32 pos_Y_CAM_NIVEAU = 0;

u32 pos_X_ENTREE = 0;
u32 pos_Y_ENTREE = 0;

u8 index_X_CARTE_NIVEAU = 0;
u8 index_Y_CARTE_NIVEAU = 0;




u16 adr_VRAM_BG_A = 0;
u16 adr_VRAM_BG_B = 0;

u16 adr_VRAM_ENTREE = 0;




Map *map_NIVEAU_BG_A;
Map *map_NIVEAU_BG_B;
Map *map_COLLISION;




u8 id_ENTREE = 0;
u8 num_ENTREE = 0;
u16 offset_TABLES_ENTREES = 0;          //  init -->  init_VARIABLES_GENERALES()
bool entree_SECRET_OK = 0;
const Image *ptr_TABLE_EAU = NULL;
const Image *ptr_TABLE_CASCADE = NULL;
const u8 *ptr_TABLE_ID_ENTREES = NULL;




u8 compteur_EAU = 0;
u8 compteur_CASCADE = 0;

u8 nb_OBJET_DECOR = 0;
bool arbre_BRULE_OK = 0;
bool objet_ECRAN = NULL;




//******************************************************//
//                                                      //
//                        DONJONS                       //
//                                                      //
//******************************************************//

u32 pos_X_CAM_DONJON = 0;
u32 pos_Y_CAM_DONJON = 0;

u8 index_X_CARTE_DONJONS = 0;
u8 index_Y_CARTE_DONJONS = 0;




//******************************************************//
//                                                      //
//                         SALLES                       //
//                                                      //
//******************************************************//

u32 pos_X_CAM_SALLE = 0;
u32 pos_Y_CAM_SALLE = 0;
