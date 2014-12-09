//
//  BSManager.h
//  BlockSmash
//
//  Created by toru-bayashi on 2014/12/07.
//  Copyright (c) 2014年 toru-wakabayashi. All rights reserved.
//

#ifndef __BlockSmash__BSManager__
#define __BlockSmash__BSManager__

#include <iostream>

#include "GameManager.h"
#include "SoundManager.h"
#include "GraphicsManager.h"
#include "TimeManager.h"

class BSManager {
public:
    BSManager();
    void management();
    GameManager *m_gameMan;
    SoundManager *m_soundMan;
    GraphicsManager *m_graphicsMan;
    TimeManager *m_timeMan;
};

#endif /* defined(__BlockSmash__BSManager__) */
