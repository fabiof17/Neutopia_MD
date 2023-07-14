#ifndef _VARIABLES_H
#define _VARIABLES_H

#define NON                     0
#define OUI                     1


#define ARRET                   0
#define MARCHE                  1
#define ATTAQUE                 2
#define TIR_BAGUETTE            3
#define TOUCHE                  4

#define BAS                     0
#define HAUT                    1
#define DROITE                  2
#define GAUCHE                  3




#define DUREE_SCROLL_H          63
#define DUREE_SCROLL_V          45



#define DECOR_NIVEAU            0
#define DECOR_SALLE             1
#define DECOR_DONJON            2
#define DECOR_SANCTUAIRE        9




#define NIVEAU                  0
#define SCROLLING_NIVEAU        1
#define FIN_SCROLLING_NIVEAU    2
#define ENTREE_CAVE             3
#define ENTREE_NIVEAU           5


#define SALLE                   10
#define ENTREE_SALLE            11
#define FIN_ENTREE_SALLE        12
#define SCROLLING_SALLE         13
#define FIN_SCROLLING_SALLE     14
#define SORTIE_SALLE            15


#define DONJON                  20
#define SCROLLING_DONJON        21
#define FIN_SCROLLING_DONJON    22
#define SORTIE_DONJON           23




#define TILE_VIDE               44
#define TILE_MUR                45

#define VEL_TIR                 2
#define MARGE_TIR               6




#define		MAX_OBJET_DECOR     2
#define		MAX_TIR             2

#define     ARBRE               1
#define     ROCHER              2



#define     BOMBE               0
#define     FIOLE               1
#define     BAGUETTE            2
#define     CLOCHE              3
#define     AILES               4
#define     POTION              5
#define     ANNEAU              6


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

extern u16 palette_64[64];

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
extern u8 niveau_BAGUETTE;

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

extern u8 nb_ENNEMIS;
extern u8 nb_TIR;

extern bool surcharge_OK;



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

extern u8 id_OBJET_MENU;

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
extern u8 energie_MAX;




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

extern u16 adr_VRAM_ENTREE;




extern Map *map_NIVEAU_BG_A;
extern Map *map_NIVEAU_BG_B;
extern Map *map_COLLISION;




extern u8 type_ENTREE;
extern u8 num_ENTREE;
extern u16 offset_TABLES_ENTREES;
extern bool entree_SECRET_OK;
extern const Image *ptr_TABLE_EAU;
extern const Image *ptr_TABLE_CASCADE;
extern const u8 *ptr_TABLE_ID_ENTREES;



extern u8 compteur_EAU;
extern u8 compteur_CASCADE;

extern u8 nb_OBJET_DECOR;
extern bool arbre_BRULE_OK;
extern bool objet_ECRAN;




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

extern u16 adr_VRAM_PNJ;






















#endif // _MAIN