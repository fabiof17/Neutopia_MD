#ifndef _VARIABLES_H
#define _VARIABLES_H


//******************************************************//
//                                                      //
//                       CONSTANTES                     //
//                                                      //
//******************************************************//

//#define H_ECRAN         184




//******************************************************//
//                                                      //
//                        GLOBALES                      //
//                                                      //
//******************************************************//

extern u8 scene_JEU;
extern u8 etat_JEU;

extern u32 pos_X_CAM;
extern u32 pos_Y_CAM;

//extern u8 index_X_CARTE;
//extern u8 index_Y_CARTE;

extern u32 pos_X_CAM_DONJON;
extern u32 pos_Y_CAM_DONJON;


extern bool PAUSE;
extern bool GAMEOVER;

extern u16 nb_BOMBES;
extern u16 nb_GOLD;

extern u8 niveau_EPEE;
extern u8 niveau_BOUCLIER;


//******************************************************//
//                                                      //
//                         TITRE                        //
//                                                      //
//******************************************************//

extern bool titre_OK;
extern u8 phase_TITRE;



//******************************************************//
//                                                      //
//                         INTRO                        //
//                                                      //
//******************************************************//

extern bool intro_OK;




//******************************************************//
//                                                      //
//                         MENU                         //
//                                                      //
//******************************************************//

bool menu_OK;

extern u8 index_X_MENU;
extern u8 index_Y_MENU;

extern u16 pos_X_CURSEUR;
extern u16 pos_Y_CURSEUR;

extern bool cle_OK;
extern bool crystal_OK;

extern u16 adr_VRAM_MENU;
extern u16 adr_VRAM_BOUSSOLE;

extern u16 adr_VRAM_ENERGIE_PLEIN;
extern u16 adr_VRAM_ENERGIE_MOITIE;
extern u16 adr_VRAM_ENERGIE_VIDE ;

extern u16 adr_VRAM_VIDE;
extern u16 adr_VRAM_AILES;
extern u16 adr_VRAM_ANNEAU;
extern u16 adr_VRAM_ARMURE;
extern u16 adr_VRAM_BOMBE;
extern u16 adr_VRAM_BOTTES;
extern u16 adr_VRAM_BOUCLIER;
extern u16 adr_VRAM_CLE;
extern u16 adr_VRAM_CLOCHE;
extern u16 adr_VRAM_CRYSTAL;
extern u16 adr_VRAM_EPEE;
extern u16 adr_VRAM_FIOLE;
extern u16 adr_VRAM_GOUTTE;
extern u16 adr_VRAM_LIVRE;
extern u16 adr_VRAM_POTION;
extern u16 adr_VRAM_SCEPTRE;

extern u16 adr_VRAM_CHIFFRES;

extern u8 nb_ENERGIE;




//******************************************************//
//                                                      //
//                        NIVEAUX                       //
//                                                      //
//******************************************************//

extern bool niveau_OK;
extern u8 num_NIVEAU;

extern u16 adr_VRAM_BG_A;
extern u16 adr_VRAM_BG_B;

extern Map *map_NIVEAU_BG_A;
extern Map *map_NIVEAU_BG_B;
extern Map *map_COLLISION;






















#endif // _MAIN