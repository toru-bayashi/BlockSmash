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