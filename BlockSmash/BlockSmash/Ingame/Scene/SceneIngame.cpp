//
//  SceneIngame.cpp
//  BlockSmash
//
//  Created by toru-bayashi on 2014/12/07.
//  Copyright (c) 2014年 toru-wakabayashi. All rights reserved.
//

#include "SceneIngame.h"

SceneIngame::SceneIngame()
{
    m_sceneName = (char *)"BlockSmash";
    m_player = new Player();
    m_paddle = new Paddle();
//    m_ball = new Ball();
//    m_block = new Block();
    m_someBalls.resize(1);
    m_someBlocks.resize(G_BLOCK_COLUMN*G_BLOCK_ROW);
}

SceneIngame::~SceneIngame()
{
    sceneRemove();
}

// Ingameシーンを生成
void SceneIngame::sceneMake()
{
    
}

void SceneIngame::sceneRemove()
{
    
}

void SceneIngame::setStage(unsigned char **&stageMap)
{
    m_stage = new Stage();
    m_stage->setStage(stageMap);
}