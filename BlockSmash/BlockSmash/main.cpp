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
#include <glm/glm.hpp>
using namespace glm;
#endif

#endif

#include <iostream>
#include "BSManager.h"
#include "Utility.h"
#include "Common/shader.hpp"

//using namespace std;
//using namespace BSManager;

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

void drawSquare()
{
    static const GLfloat vtx4[] = {
        -50.0f,  50.0f,
        -50.0f, -50.0f,
        50.0f, -50.0f,
        50.0f,  50.0f,
    };
    
    glVertexPointer(2, GL_FLOAT, 0, vtx4);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    
    glEnableClientState(GL_VERTEX_ARRAY);
    glDrawArrays(GL_QUADS, 0, 4);
    glDisableClientState(GL_VERTEX_ARRAY);
}

void render()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glPushMatrix();
    glTranslatef( 320.0f, 240.0f, 0.0f );
    drawSquare();
    glPopMatrix();
}

int main()
{
    if( !glfwInit() ){
        std::cout << "GLFWの初期化に失敗しました。n" << std::endl;
        return -1;
    }
    
    glfwWindowHint(GLFW_SAMPLES, 4); // 4x アンチエイリアス
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // OpenGL3.3を使います。
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // MacOS用：必ずしも必要ではありません。
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // 古いOpenGLは使いません。

    // Windowを開き、OpenGLコンテキストを作ります
    GLFWwindow* window; // (ソースコードではこの変数はグローバルです。)
    window = glfwCreateWindow(G_WINDOW_WIDTH, G_WINDOW_HEIGHT, "BlockSmash!", NULL, NULL);
    if( window == NULL ){
        std::cout << "GLFWウィンドウのオープンに失敗しました。 もしIntelのGPUならば, 3.3に対応していません。チュートリアルのバージョン2.1を試してください。n" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window); // GLEWを初期化する

    glewExperimental=true; // コアプロファイルで必要となります。
    if (glewInit() != GLEW_OK) {
        std::cout << "GLEWの初期化に失敗しました。n" << std::endl;
        return -1;
    }
    
    // 下でエスケープキーが押されるのを捉えるのを保証します。
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    
    glClearColor(0.2f, 0.2f, 0.2f, 0.0f);
    
    // シェーダからGLSLプログラムを作りコンパイルする。
    GLuint programID = LoadShaders( "/Users/wakabayashitooru/BlockSmash/BlockSmash/BlockSmash/SimpleVertexShader.vertexshader", "/Users/wakabayashitooru/BlockSmash/BlockSmash/BlockSmash/SimpleFragmentShader.fragmentshader" );
    
    // Get a handle for our buffers
	GLuint vertexPosition_modelspaceID = glGetAttribLocation(programID, "vertexPosition_modelspace");

//    // モニタとの同期
//    glfwSwapInterval(1);
    
    // ブロック崩し管理オブジェクトを実体化------------------
//    static BSManager *bsMan;
//    bsMan = new BSManager();
    
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    glOrtho(0.0f, G_WINDOW_WIDTH, 0.0f, G_WINDOW_HEIGHT, -1.0f, 1.0f);
    
    // VAO
    GLuint VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);
    
    // 3頂点を表す3つのベクトルの配列
    static const GLfloat g_vertex_buffer_data[] = {
        -1.0f, -1.0f, 0.0f,
        1.0f, -1.0f, 0.0f,
        0.0f,  1.0f, 0.0f,
    };
    
    // これが頂点バッファを指し示すものとなります。
    GLuint vertexbuffer;
    // バッファを1つ作り、vertexbufferに結果IDを入れます。
    glGenBuffers(1, &vertexbuffer);
    // 次のコマンドは'vertexbuffer'バッファについてです。
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    // 頂点をOpenGLに渡します。
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
    
    
    do{
        // ウィンドウ背景色を塗りつぶし
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // シェーダを使う
        glUseProgram(programID);
        
//        render();
        
        // 最初の属性バッファ：頂点
        glEnableVertexAttribArray(vertexPosition_modelspaceID);
        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
        glVertexAttribPointer(
                              vertexPosition_modelspaceID,                  // シェーダ内のlayoutとあわせないといけません。
                              3,                  // サイズ
                              GL_FLOAT,           // タイプ
                              GL_FALSE,           // 正規化？
                              0,                  // ストライド
                              (void*)0            // 配列バッファオフセット
                              );
        
        // 三角形を描きます！
        glDrawArrays(GL_TRIANGLES, 0, 3); // 頂点0から始まります。合計3つの頂点です。→1つの三角形です。
        glDisableVertexAttribArray(vertexPosition_modelspaceID);
        
        // バッファをスワップする。
        glfwSwapBuffers(window);
        glfwPollEvents();
        
    } // ESCキーが押されたかウィンドウが閉じたかをチェックする。
    while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
          glfwWindowShouldClose(window) == 0 );
    
	// Cleanup VBO
	glDeleteBuffers(1, &vertexbuffer);
	glDeleteProgram(programID);

    //    systemInitialize();
//    gameInitialize();
//    
//    do{
//        if (gameMainLoop())
//            break;
//    } while (0);
//    
//    gameFinalize();
//    systemFinalize();

    glfwTerminate();
    
    return 0;
}