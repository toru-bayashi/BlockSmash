//
//  main.cpp
//  BlockSmash
//
//  Created by toru-bayashi on 2014/12/07.
//  Copyright (c) 2014年 toru-wakabayashi. All rights reserved.
//
#ifdef _WIN32
    #pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
    #include <GL/glut.h>

#elif defined __APPLE__
    #include "TargetConditionals.h"

    #ifdef TARGET_OS_MAC
        #include <GLUT/GLUT.h>
    #endif
#endif

#include <iostream>
#include "BSManager.h"

using namespace std;
//using namespace BSManager;

void systemInitialize()
{
    cout << "systemInitialize()" << endl;
    BSManager::management();
}

void gameInitialize()
{
    cout << "gameInitialize()" << endl;
}

bool mainLoop()
{
    cout << "mainLoop()" << endl;
    return true;
}

void gameFinalize()
{
    cout << "gameFinalize()" << endl;
}

void systemFinalize()
{
    cout << "systemFinalize()" << endl;
}

int main(int argc, char *argv[])
{
    systemInitialize();
    gameInitialize();
    
    do{
        if (mainLoop())
            break;
    } while (0);
    
    gameFinalize();
    systemFinalize();
}