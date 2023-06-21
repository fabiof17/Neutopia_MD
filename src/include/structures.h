#ifndef _STRUCTURES_H
#define _STRUCTURES_H



//******************************************************//
//                                                      //
//                     SPRITE DECOR                     //
//                                                      //
//******************************************************//

typedef struct
{
    Sprite* sprite_DECOR;
 
    s16 pos_X;
    s16 pos_Y;

    u8 taille_H;                // 16
    u8 taille_V;                // ID=2 : 16 - sinon 32

    s16 pt_Coll_HG_X;
    s16 pt_Coll_HG_Y;
    s16 pt_Coll_BD_X;
    s16 pt_Coll_BD_Y;

    u8 ID;						// Type de sprite : arbre, rocher, statue, etc...
    
    u8 compteur_ANIM;		// compteur frame d'animation

} struct_ELEMENT_DECOR_;

extern struct_ELEMENT_DECOR_ ELEMENT_DECOR;




//******************************************************//
//                                                      //
//                     SPRITE JOUEUR                    //
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
//                   STRUCTURE ENTREE                   //
//                                                      //
//******************************************************//

typedef struct
{
	const u8				id;			    // 0 = ESCALIER  |  1 = DONJON  |  2 = CAVE

	const u8				pos_X;			// EN TILES
	const u8				pos_Y;			// EN TILES

    //const u16				w;
	//const u16				h;
	
	const Image             *adr_Image;     // adresse de la structure IMAGE
    //const u8                adr_VRAM;

	const u8				pal;
	VDPPlane				bg;
	bool					priorite;

	bool					secret;			// 0 = ENTREE NORMALE  |  1 = ENTREE SECRETE
	u8                      condition;		// 0 = TUER ENNEMIS  |  1 = POUSSER ROCHER  |  2 = BOMBE MUR

} struct_ENTREE_;

extern const struct_ENTREE_ *ptr_TABLE_ENTREES;






#endif // _MAIN