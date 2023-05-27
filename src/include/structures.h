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
    
    u8 CompteurFrameAnim;		// Compteur frame d'animation

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

    //s16 pt_Coll_HG_X;
    //s16 pt_Coll_HG_Y;
    //s16 pt_Coll_BD_X;
    //s16 pt_Coll_BD_Y;

    
    //u8 CompteurFrameAnim;		// Compteur frame d'animation

} struct_JOUEUR_;

extern struct_JOUEUR_ JOUEUR;










#endif // _MAIN