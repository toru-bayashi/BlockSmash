//
//  Utility.h
//  BlockSmash
//
//  Created by toru-bayashi on 2014/12/07.
//  Copyright (c) 2014年 toru-wakabayashi. All rights reserved.
//

#ifndef __BlockSmash__Utility__
#define __BlockSmash__Utility__

//const char *g_sceneTitleName = "Title";
//const char *g_sceneIngameName = "BlockSmash";
//const char *g_sceneGameoverName = "Gameover";
//const char *g_sceneStageClearName = "StageClear";

// ブロックの最大個数
#define G_BLOCK_COLUMN   15
#define G_BLOCK_ROW      20

// ブロックのサイズ
#define G_BLOCK_WIDTH    64
#define G_BLOCK_HEIGHT   16

// パドルのサイズ
#define G_PADDLE_WIDTH    96
#define G_PADDLE_HEIGHT   16

// ステージ数
#define G_STAGE_COUNT    1

// ウィンドウサイズ
#define G_WINDOW_WIDTH   480
#define G_WINDOW_HEIGHT  640

// 円周率
#define Pai 3.1415926

namespace Utility
{
    enum SE_SYSTEM
    {
        SS_NONE,
        SS_OK,
        SS_CANSEL,
        SS_SELECT,
        SS_GAMESTART,
    };
    
    enum SE_INGAME
    {
        SI_NONE,
        SI_COLLISION_BALL2BLOCK,
        SI_COLLISION_BALL2PADDLE,
        SI_DESTROY,
        SI_GETITEM,
        SI_GAMECLEAR,
        SI_GAMEOVER,
        SI_MISS,
    };
    
    enum SCENE_TYPE
    {
        SCENE_TITLE,
        SCENE_INGAME,
        SCENE_STAGECLEAR,
        SCENE_GAMEOVER,
    };
    
    enum BLOCK_TYPE
    {
        BLOCK_NORMAL,
        BLOCK_TOUGH,
        BLOCK_UNBREAKABLE,
    };

    void textureLoad();
    unsigned char** stageLoad();
}

#endif /* defined(__BlockSmash__Utility__) */
