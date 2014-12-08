//
//  GamaManager.cpp
//  BlockSmash
//
//  Created by toru-bayashi on 2014/12/07.
//  Copyright (c) 2014年 toru-wakabayashi. All rights reserved.
//
#include "GameManager.h"

GameManager::GameManager()
{
    m_sceneID = SCENE_TITLE;
    setScene(m_sceneID);
}

void GameManager::setScene(SCENE_TYPE sceneID)
{
    switch (sceneID) {
        case SCENE_TITLE:
            break;
        case SCENE_INGAME:
            break;
        case SCENE_GAMEOVER:
            break;
        case SCENE_STAGECLEAR:
            break;
        default:
            // exception error
            break;
    }
}
