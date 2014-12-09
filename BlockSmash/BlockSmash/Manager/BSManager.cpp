//
//  BSManager.cpp
//  BlockSmash
//
//  Created by toru-bayashi on 2014/12/07.
//  Copyright (c) 2014年 toru-wakabayashi. All rights reserved.
//

#include "BSManager.h"

BSManager::BSManager()
{
    // 各分野の管理オブジェクトを実体化
    m_gameMan = new GameManager();
    m_soundMan = new SoundManager();
    m_graphicsMan = new GraphicsManager();
    m_timeMan = new TimeManager();
}

void BSManager::management()
{
    std::cout << "BSManager::management()" << std::endl;
}