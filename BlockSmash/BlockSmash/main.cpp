//
//  main.cpp
//  BlockSmash
//
//  Created by toru-bayashi on 2014/12/07.
//  Copyright (c) 2014年 toru-wakabayashi. All rights reserved.
//
#include "BSManager.h"
#include "Utility.h"
#include "UtilityGL.h"

void systemInitialize()
{
    std::cout << "systemInitialize()" << std::endl;
}

void gameInitialize()
{
    std::cout << "gameInitialize()" << std::endl;
}

bool gameMainLoop()
{
    std::cout << "gameMainLoop()" << std::endl;
    return true;
}

void gameFinalize()
{
    std::cout << "gameFinalize()" << std::endl;
}

void systemFinalize()
{
    std::cout << "systemFinalize()" << std::endl;
}

int main()
{
//    return UtilityGL::dummyMain();
    return UtilityGL::createWindow(G_WINDOW_WIDTH, G_WINDOW_HEIGHT);
}