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

class GameManager
{
public:
    GameManager();
    void setScene(SCENE_TYPE sceneID);
private:
    SCENE_TYPE m_sceneID;
};

#endif /* defined(__BlockSmash__GamaManager__) */
