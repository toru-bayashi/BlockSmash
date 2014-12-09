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

    void textureLoad();
    void stageLoad();
}

#endif /* defined(__BlockSmash__Utility__) */
