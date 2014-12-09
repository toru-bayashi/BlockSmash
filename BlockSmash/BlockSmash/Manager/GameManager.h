//
//  GamaManager.h
//  BlockSmash
//
//  Created by toru-bayashi on 2014/12/07.
//  Copyright (c) 2014年 toru-wakabayashi. All rights reserved.
//

#ifndef __BlockSmash__GamaManager__
#define __BlockSmash__GamaManager__
#include "Utility.h"
#include "SceneTitle.h"
#include "SceneIngame.h"
#include "SceneStageClear.h"
#include "SceneGameOver.h"

class GameManager
{
public:
    GameManager();
    void setScene(Utility::SCENE_TYPE sceneID);
    SceneTitle *m_sceneTtl;
    SceneIngame *m_sceneIngm;
    SceneStageClear *m_sceneStCl;
    SceneGameOver *m_sceneGmOv;
private:
    Utility::SCENE_TYPE m_sceneID;
};

#endif /* defined(__BlockSmash__GamaManager__) */
