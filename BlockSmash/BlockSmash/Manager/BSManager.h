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

namespace BSManager
{
    void management()
    {
        const GameManager *gameMan = new GameManager();
        const SoundManager *soundMan = new SoundManager();
        const GraphicsManager *graphicsMan = new GraphicsManager();
        const TimeManager *timeMan = new TimeManager();
        std::cout << "BSManager::management()" << std::endl;
    }
}

#endif /* defined(__BlockSmash__BSManager__) */
