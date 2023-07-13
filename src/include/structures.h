#ifndef _STRUCTURES_H
#define _STRUCTURES_H




//******************************************************//
//                                                      //
//                    STRUCTURE JOUEUR                  //
//                                                      //
//******************************************************//

typedef struct
{
    Sprite* sprite_JOUEUR;
    Sprite* sprite_EPEE;



 
    s16 pos_X_JOUEUR;
    s16 pos_Y_JOUEUR;

    s16 pos_X_EPEE;
    s16 pos_Y_EPEE;




    s16 pt1_X_COLL_DECOR;
    s16 pt1_Y_COLL_DECOR;

    s16 pt2_X_COLL_DECOR;
    s16 pt2_Y_COLL_DECOR;


    s16 pt3_X_COLL_DECOR;
    s16 pt3_Y_COLL_DECOR;

    s16 pt4_X_COLL_DECOR;
    s16 pt4_Y_COLL_DECOR;



    
    u8 compteur_ANIM;		// compteur frame d'animation
    u8 index_ANIM;          // index frame d'animation

    u8 compteur_ATTAQUE;    // durée de l'attaque

} struct_JOUEUR_;

extern struct_JOUEUR_ JOUEUR;




//******************************************************//
//                                                      //
//                      STRUCTURE TIR                   //
//                                                      //
//******************************************************//

typedef struct
{
	u8 etat;				// 0 = NON CREE  |  1 = NORMAL  |  2 = BOOMERANG  |  9 = DESTRUCTION

    s16 pos_X;
    s16 pos_Y;

	s16 vel_X;				// vélocité en X
	s16 vel_Y;				// vélocité en Y

	u8 marge_X;
	u8 marge_Y;

    u8 compteur_ANIM;		// compteur frame d'animation
    u8 index_ANIM;          // index frame d'animation

    //SpriteDefinition *adr_TILES;
	Sprite* sprite_TIR;

} struct_TIR_;

//extern struct_TIR_ TIR;

// LISTE DES TIRS
extern struct_TIR_						LISTE_TIR[2];



//******************************************************//
//                                                      //
//                   STRUCTURE ENTREE                   //
//                                                      //
//******************************************************//

typedef struct
{
	const u8				type;			    // 0 = ESCALIER  |  1 = DONJON  |  2 = CAVE

	const u8				pos_X;			// EN TILES
	const u8				pos_Y;			// EN TILES
	
	const Image             *adr_Image_ENTREE;     // adresse des TILES des entrées
	const Image             *adr_Image_CACHE;      // adresse des TILES des caches

	const u8				pal;
	VDPPlane				bg;
	bool					priorite;

	bool					secret;			// 0 = ENTREE NORMALE  |  1 = ENTREE SECRETE
	u8                      condition;		// 0 = TUER ENNEMIS  |  1 = POUSSER ROCHER  |  2 = BOMBE MUR

    bool                    bloque;         // 0 = ON PEUT MARCHER DESSUS | 1 = PASSAGE BLOQUE

} struct_ENTREE_;


// POINTEUR SUR LA TABLE DES ENTREES DU NIVEAU EN COURS
extern const struct_ENTREE_ *ptr_TABLE_ENTREES;




//******************************************************//
//                                                      //
//                  STRUCTURE ENNEMI                    //
//                                                      //
//******************************************************//

typedef struct
{
	u8 type;
	
	u8 pos_X;
	u8 pos_Y;
	
	u8 etat;
	u8 axe;
	bool destructible;

	u8 pts_VIE;

	u8 w;
	u8 h;

	u8 compteur;
	u8 compteur_ANIM;
	u8 index_ANIM;
	u8 offset_ANIM;
	
	SpriteDefinition *adr_TILES;
	
	Sprite *sprite_ENNEMI;
	Sprite *sprite_OMBRE;
	Sprite *sprite_PROJECTILE;
	
} struct_ENNEMI_;




//******************************************************//
//                                                      //
//                 STRUCTURE OBJET DECOR                //
//                                                      //
//******************************************************//

typedef struct
{
	bool type;
	
	s16 pos_X;
	s16 pos_Y;
	
	u8 etat;
	u8 axe;
	
	u8 compteur_ANIM;
	u8 index_ANIM;
	
	const SpriteDefinition *adr_TILES;	
	Sprite *sprite_OBJET;

	u8 pal;
	
} struct_OBJET_DECOR_;


// LISTE DES OBJETS DANS LE NIVEAU EN COURS
extern struct_OBJET_DECOR_						LISTE_OBJETS_DECOR[2];

// POINTEUR SUR LA TABLE DES OBJETS DU NIVEAU EN COURS
extern const struct_OBJET_DECOR_				*ptr_TABLE_OBJETS_DECOR;




//******************************************************//
//                                                      //
//                    STRUCTURE SALLE                   //
//                                                      //
//******************************************************//

typedef struct
{
	const Image		*adr_Image_SALLE;		// ADRESSES DES TILES DES SALLES
	const Image		*adr_Image_PNJ;			// ADRESSES DES TILES DES SALLES
	
} struct_SALLE_;


// POINTEUR SUR LA TABLE DES SALLES DU NIVEAU EN COURS
extern const struct_SALLE_					*ptr_TABLE_SALLES;




//******************************************************//
//                                                      //
//                    STRUCTURE JOYAU                   //
//                                                      //
//******************************************************//

typedef struct
{
	u16 pos_X;
	u16 pos_Y;

	const Image		*adr_Image_JOYAU;		// ADRESSES DES TILES DES JOYAUX
	
} struct_JOYAU_;













#endif // _MAIN