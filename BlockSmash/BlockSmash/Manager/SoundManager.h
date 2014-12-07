//
//  SoundManager.h
//  BlockSmash
//
//  Created by toru-bayashi on 2014/12/07.
//  Copyright (c) 2014年 toru-wakabayashi. All rights reserved.
//

#ifndef __BlockSmash__SoundManager__
#define __BlockSmash__SoundManager__

class SoundManager
{
public:
    enum SE_SYSTEM
    {
        none_system,
        ok,
        cansel,
        select,
        gamestart,
    };
    
    enum SE_INGAME
    {
        none_ingame,
        collision_ball2block,
        collision_ball2paddle,
        destroy,
        getitem,
        gameclear,
        gameover,
        miss,
    };
    SoundManager();
};

#endif /* defined(__BlockSmash__SoundManager__) */
