/*
 *  window_top.cpp
 *  testGUI
 *
 *  Created by toru-bayashi on 12/11/05.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */
#include "window_top.h"
#include "IngameView.h"
#include <stdlib.h>

#ifdef _WIN32
    #pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
    #include <GL/glut.h>
#elif defined __APPLE__
    #include "TargetConditionals.h"
    #ifdef TARGET_OS_MAC
        #include <GLUT/GLUT.h>
    #endif
#endif

void display(void){
    // ウィンドウを塗りつぶす　カラー、デプス、ステンシル、オーバーレイ等
    glClear(GL_COLOR_BUFFER_BIT);
    
    // 図形描画開始　図形タイプ
    glBegin(GL_POLYGON);
    
    glColor3d(0.5, 0.5, 0.5);
    glVertex2d(-0.9, -0.9);
    
    glColor3d(1.0, 0.0, 0.0); /* red */
    glVertex2d(-0.9, -0.9);
    
    glColor3d(0.0, 1.0, 0.0); /* green */
    glVertex2d(0.9, -0.9);
    
    glColor3d(0.0, 0.0, 1.0); /* blue */
    glVertex2d(0.9, 0.9);
    
    glColor3d(1.0, 1.0, 0.0); /* yellow */
    glVertex2d(-0.9, 0.9);
    
    // 図形描画終了
    glEnd();
    
    // 未実行のOpenGLの命令を全部実行
    glFlush();
}

void resize(int w, int h)
{
    // ウィンドウ全体をビューポートにする
    glViewport(0, 0, w, h);
    
    // 変換行列の初期化
    glLoadIdentity();
    
    // スクリーン上の表示領域をビューポートの大きさに比例させる　左、右、下、上、前、後
    glOrtho(-w / 200.0, w / 200.0, -h / 200.0, h / 200.0, -1.0, 1.0);
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
        case 'q':
        case 'Q':
        case '\033': // '¥033' はESCのASCIIコード
            exit(0);
        default:
            break;
    }
}

void draw(){
    
}

void init(void)
{
//    static int padSizeW, padSizeH;
    // GL_COLOR_BUFFER_BITで塗りつぶす色を指定 1〜0
    glClearColor(0.0, 0.0, 0.0, 0.0);
    
    // パドルのインスタンス化／描画
    Paddle* paddle = new Paddle(100, 20);
//    padSizeH = paddle->getSizeH();
//    padSizeW = paddle->getSizeW();
    
    // ボールのインスタンス化／描画
    
    // プロックの読み込み
}

int main (int argc, char * argv[]) {
    // 新たに開くウィンドウの位置、サイズを指定
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(WINDOWSIZE_W, WINDOWSIZE_H);
    
    // GLUT,OpenGL環境の初期化
    glutInit(&argc, argv);
    
    // ディスプレイ表示モード　赤青黄α
    glutInitDisplayMode(GLUT_RGBA);
    
    // ウィンドウを開く　引数はタイトルバー等に表示される文字列
    glutCreateWindow("title");
    
    // ウィンドウ内に描画／再描画を行われるときに実行する関数へのポインタを指定
    glutDisplayFunc(display);

    // ウィンドウがリサイズされたときに実行する関数へのポインタを指定
    glutReshapeFunc(resize);
    
    // キーがタイプされたときに実行する関数へのポインタを指定
    glutKeyboardFunc(keyboard);
    
    // 初期化処理
    init();
    
    // イベントの待ち受け状態
    glutMainLoop();
	
    return 0;
}