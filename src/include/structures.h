#ifndef _STRUCTURES_H
#define _STRUCTURES_H



//******************************************************//
//                                                      //
//                       GLOBALES                       //
//                                                      //
//******************************************************//

typedef struct
{
    Sprite* SpriteDecor;
 
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

} Struct_SpriteDecor_;

extern Struct_SpriteDecor_ SpriteDecor;








#endif // _MAIN


























#endif // _MAIN