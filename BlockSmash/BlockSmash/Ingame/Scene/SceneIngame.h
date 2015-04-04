//
//  SceneIngame.h
//  BlockSmash
//
//  Created by toru-bayashi on 2014/12/07.
//  Copyright (c) 2014年 toru-wakabayashi. All rights reserved.
//

#ifndef __BlockSmash__SceneIngame__
#define __BlockSmash__SceneIngame__

#include <vector>

#include "Scene.h"
#include "Utility.h"
#include "IngameObject.h"
#include "Player.h"

class SceneIngame : virtual public Scene
{
public:
    SceneIngame();
    ~SceneIngame();
    void sceneMake();
    void sceneRemove();
    void setStage(unsigned char **&stageMap);

private:
    Player *m_player;
    Paddle *m_paddle;
    Ball *m_ball;
    Block *m_block;
    
    std::vector<Ball> m_someBalls;
    std::vector<Block> m_someBlocks;
    Stage *m_stage;
};

#endif /* defined(__BlockSmash__SceneIngame__) */
