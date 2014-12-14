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
#include <GL/glfw.h>

#elif defined __APPLE__
#include "TargetConditionals.h"

#ifdef TARGET_OS_MAC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GLUT/GLUT.h>
//#include "glm/glm.hpp"
//using namespace glm;
#endif

#endif

#include <iostream>
#include "BSManager.h"
#include "Utility.h"

using namespace std;
//using namespace BSManager;

void systemInitialize()
{
    cout << "systemInitialize()" << endl;

    // ブロック崩し管理オブジェクトを実体化
    BSManager *bsMan;
    bsMan = new BSManager();
}

void gameInitialize()
{
    cout << "gameInitialize()" << endl;
}

bool gameMainLoop()
{
    cout << "gameMainLoop()" << endl;
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

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//ラインを描く
	glColor3f(0,0,0);
	glLineWidth(3);//線幅の指定。省略可。指定しなければ1。
	glBegin(GL_LINES);
	for(int i=0;i<9;i++){
		glVertex2i(80+80*i,720);//縦線上端
		glVertex2i(80+80*i,80);//縦線下端
		glVertex2i(80,80+80*i);//横線左端
		glVertex2i(720,80+80*i);//横線右端
	}
	glEnd();
    
	//点を4箇所描く
	glColor3f(0,0,0);
	glPointSize(10);
	glBegin(GL_POINTS);
    glVertex2i(240,240);
    glVertex2i(240,560);
    glVertex2i(560,240);
    glVertex2i(560,560);
	glEnd();
	glutSwapBuffers();
}

int main()
{
    if( !glfwInit() ){
        return -1;
    }
    
    systemInitialize();
    gameInitialize();
    
    do{
        if (gameMainLoop())
            break;
    } while (0);
    
    gameFinalize();
    systemFinalize();
}