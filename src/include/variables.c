#include <genesis.h>


//******************************************************//
//                                                      //
//                        GLOBALES                      //
//                                                      //
//******************************************************//

u8 scene_JEU = 0;
u8 etat_JEU = 0;

u32 pos_X_CAM = 0;
u32 pos_Y_CAM = 0;

u32 pos_X_CAM_DONJON = 0;
u32 pos_Y_CAM_DONJON = 0;

//u8 index_X_CARTE = 0;
//u8 index_Y_CARTE = 0;

bool PAUSE = 0;
bool GAMEOVER = 0;

u16 nb_BOMBES = 0;
u16 nb_GOLD = 0;

u8 niveau_EPEE = 0;
u8 niveau_BOUCLIER = 0;


//******************************************************//
//                                                      //
//                         TITRE                        //
//                                                      //
//******************************************************//

bool titre_OK = 0;
u8 phase_TITRE = 0;


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




//******************************************************//
//                                                      //
//                        NIVEAUX                       //
//                                                      //
//******************************************************//

bool niveau_OK = 0;
u8 num_NIVEAU = 1;

u16 adr_VRAM_BG_A = 0;
u16 adr_VRAM_BG_B = 0;

Map *map_NIVEAU_BG_A;
Map *map_NIVEAU_BG_B;
Map *map_COLLISION;

