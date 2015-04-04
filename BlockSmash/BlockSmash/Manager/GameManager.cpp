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
//    m_sceneState = Utility::SCENE_TITLE;
    m_sceneState = Utility::SCENE_INGAME;
    m_stageMap = nullptr;

    // ステージ情報をロード
    m_stageMap = Utility::stageLoad();
    
    // シーンを設定（最初はタイトル画面）
    standbyScene();
}

void GameManager::standbyScene()
{
    switch (m_sceneState) {
//        case Utility::SCENE_TITLE:
//            m_sceneTtl = new SceneTitle();
//            break;
            
            // Ingameシーンの準備
        case Utility::SCENE_INGAME:
            m_sceneIngm = new SceneIngame();
            m_sceneIngm->setStage(m_stageMap);
            m_sceneIngm->sceneMake();
            break;
//        case Utility::SCENE_GAMEOVER:
//            m_sceneGmOv = new SceneGameOver();
//            break;
//        case Utility::SCENE_STAGECLEAR:
//            m_sceneStCl = new SceneStageClear();
//            break;
        default:
            // exception error
            break;
    }
}

void GameManager::breakScene()
{
    switch (m_sceneState) {
//        case Utility::SCENE_TITLE:
//            delete m_sceneTtl;
//            break;
        case Utility::SCENE_INGAME:
            delete m_sceneIngm;
            break;
//        case Utility::SCENE_GAMEOVER:
//            delete m_sceneGmOv;
//            break;
//        case Utility::SCENE_STAGECLEAR:
//            delete m_sceneStCl;
//            break;
        default:
            // exception error
            break;
    }
}