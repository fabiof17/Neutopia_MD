#ifndef _VARIABLES_H
#define _VARIABLES_H


#define ARRET                   0
#define MARCHE                  1
#define ATTAQUE                 2
#define TOUCHE                  3

#define BAS                     0
#define HAUT                    1
#define DROITE                  2
#define GAUCHE                  3

#define DUREE_SCROLL_H          63
#define DUREE_SCROLL_V          45


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

extern char texteSortie[3];

extern u8 scene_JEU;
extern u8 etat_JEU;
extern u8 etat_JOUEUR;

extern u8 type_DECOR;

extern bool PAUSE;
extern bool GAMEOVER;

extern u16 nb_BOMBES;
extern u16 nb_GOLD;

extern u8 niveau_EPEE;
extern u8 niveau_BOUCLIER;
extern u8 niveau_ARMURE;

//extern bool tiles_ARRET_OK;
//extern bool tiles_ATTAQUE_OK ;

extern u16 id_TILE1;
extern u16 id_TILE2;
extern u16 id_TILE3;
extern u16 id_TILE4;




extern u8 axe_JOUEUR;

extern u8 compteur_SCROLLING;
extern u8 duree_SCROLLING;

extern u8 index_X_CARTE;
extern u8 index_Y_CARTE;



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

extern u8 index_X_CARTE_MENU;
extern u8 index_Y_CARTE_MENU;

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

extern u32 pos_X_CAM;
extern u32 pos_Y_CAM;

extern u32 pos_X_CAM_NIVEAU;
extern u32 pos_Y_CAM_NIVEAU;

extern u32 pos_X_ENTREE;
extern u32 pos_Y_ENTREE;

extern u8 index_X_CARTE_NIVEAU;
extern u8 index_Y_CARTE_NIVEAU;

extern u16 adr_VRAM_BG_A;
extern u16 adr_VRAM_BG_B;

extern Map *map_NIVEAU_BG_A;
extern Map *map_NIVEAU_BG_B;
extern Map *map_COLLISION;

extern u8 id_ENTREE;
extern u16 offset_TABLES_ENTREES;

extern bool spr_ENTREE_OK;

//extern u8 z_ORDER;


//******************************************************//
//                                                      //
//                        DONJON                        //
//                                                      //
//******************************************************//

extern u32 pos_X_CAM_DONJON;
extern u32 pos_Y_CAM_DONJON;

extern u8 index_X_CARTE_DONJONS;
extern u8 index_Y_CARTE_DONJONS;




//******************************************************//
//                                                      //
//                         SALLES                       //
//                                                      //
//******************************************************//

extern u32 pos_X_CAM_SALLE;
extern u32 pos_Y_CAM_SALLE;






















#endif // _MAIN