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
    std::vector<Ball> m_ball;
    std::vector<Block> m_block;
    Stage *m_stage;
};

#endif /* defined(__BlockSmash__SceneIngame__) */
