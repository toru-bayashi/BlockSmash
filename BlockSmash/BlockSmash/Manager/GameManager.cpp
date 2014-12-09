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
    // ゲーム全体の各シーンオブジェクトを実体化
    m_sceneID = Utility::SCENE_TITLE;
    m_sceneTtl = new SceneTitle();
    m_sceneIngm = new SceneIngame();
    m_sceneStCl = new SceneStageClear();
    m_sceneGmOv = new SceneGameOver();
    
    // 最初はタイトル画面を設定
    setScene(m_sceneID);
}

void GameManager::setScene(Utility::SCENE_TYPE sceneID)
{
    switch (sceneID) {
        case Utility::SCENE_TITLE:
            break;
        case Utility::SCENE_INGAME:
            break;
        case Utility::SCENE_GAMEOVER:
            break;
        case Utility::SCENE_STAGECLEAR:
            break;
        default:
            // exception error
            break;
    }
}
