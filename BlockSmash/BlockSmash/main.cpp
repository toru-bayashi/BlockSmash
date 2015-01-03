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
#include <glm/gtx/transform.hpp>
using namespace glm;
#endif

#endif

#include <iostream>
#include <math.h>
#include "BSManager.h"
#include "Utility.h"
#include "Common/shader.hpp"

#define G_NORMALIZED_BLOCK_WIDTHSIZE    ((2.0f/G_WINDOW_WIDTH)*G_BLOCK_WIDTH)
#define G_NORMALIZED_BLOCK_HEIGHTSIZE   ((2.0f/G_WINDOW_HEIGHT)*G_BLOCK_HEIGHT)

//using namespace std;
//using namespace BSManager;

GLFWwindow* window;

// パドルの移動量用
glm::vec3 position(0,0,0);
float speed = 1.5f; // 3 units / second

// ボールの移動量用
glm::vec3 ballmoved(0,0,0);
float ballspeed = 1.2f;

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

bool keyboardControl()
{
    bool isKeyPressed = false;
	// glfwGetTime is called only once, the first time this function is called
	static double lastTime = glfwGetTime();
    
	// Compute time difference between current and last frame
	double currentTime = glfwGetTime();
	float deltaTime = float(currentTime - lastTime);

    // パドルを右へ
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS){
        position += glm::vec3(1,0,0) * deltaTime * speed;
        isKeyPressed = true;
    }
    
    // パドルを左へ
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS){
        position -= glm::vec3(1,0,0) * deltaTime * speed;
        isKeyPressed = true;
    }

	// For the next frame, the "last time" will be "now"
	lastTime = currentTime;
    
    return isKeyPressed;
}

void ballMover()
{
    static double lastTime_ball = glfwGetTime();
    
	double currentTime_ball = glfwGetTime();
	float deltaTime_ball = float(currentTime_ball - lastTime_ball);

    ballmoved = glm::vec3(0,1,0) * deltaTime_ball * ballspeed;
	lastTime_ball = currentTime_ball;
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

	// Get a handle for our "MVP" uniform
	GLuint diffMat4ID = glGetUniformLocation(programID, "diffMat4");

	// Get a handle for our "drawColor" uniform
//	GLuint drawColorID = glGetUniformLocation(programID, "drawColor");
    
    // Get a handle for our buffers
	GLuint vertexPosition_modelspaceID = glGetAttribLocation(programID, "vertexPosition_modelspace");
	GLuint vertexColorID = glGetAttribLocation(programID, "vertexColor");
	GLuint vertexPaddleTransrateID = glGetAttribLocation(programID, "vertexPaddleTransrate");
	GLuint vertexPaddleColorID = glGetAttribLocation(programID, "vertexPaddleColor");
    
//    // モニタとの同期
//    glfwSwapInterval(1);
    
    // ブロック崩し管理オブジェクトを実体化------------------
//    static BSManager *bsMan;
//    bsMan = new BSManager();
    
//    glViewport(0, 0, (GLsizei)G_WINDOW_WIDTH, (GLsizei)G_WINDOW_HEIGHT);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    glOrtho(0.0f, G_WINDOW_WIDTH, 0.0f, G_WINDOW_HEIGHT, -1.0f, 1.0f);

//    gluOrtho2D(0, G_WINDOW_WIDTH, 0, G_WINDOW_HEIGHT);
    
    // VAO 頂点配列オブジェクトを作成->バインド
    GLuint VertexArrayID[3];
    glGenVertexArrays(3, VertexArrayID);

    // VAO--ブロック-------------------------------------------------------
    glBindVertexArray(VertexArrayID[0]);
    
    // ブロックの頂点位置のバッファ-------------------------位置----
//    GLfloat g_block_vertex_buffer_data[G_BLOCK_COLUMN*G_BLOCK_ROW];
//    for (int i=0;i<G_BLOCK_COLUMN*G_BLOCK_ROW;++i)
//    {
//        g_block_vertex_buffer_data[i] = {
//        -1.0f, (1.0f-((2.0f/G_WINDOW_HEIGHT)*G_BLOCK_HEIGHT)), 0.0f,
//        (-1.0f+((2.0f/G_WINDOW_WIDTH)*G_BLOCK_WIDTH)), (1.0f-((2.0f/G_WINDOW_HEIGHT)*G_BLOCK_HEIGHT)),                                 0.0f,
//        -1.0f,                                1.0f, 0.0f,
//        (-1.0f+((2.0f/G_WINDOW_WIDTH)*G_BLOCK_WIDTH)), 1.0f, 0.0f,
//        (-1.0f+((2.0f/G_WINDOW_WIDTH)*G_BLOCK_WIDTH)), (1.0f-((2.0f/G_WINDOW_HEIGHT)*G_BLOCK_HEIGHT)),                                 0.0f,
//        -1.0f,                                1.0f, 0.0f,
//    };

    GLfloat g_block_vertex_buffer_data[(G_BLOCK_COLUMN)*(G_BLOCK_ROW)*18];
//    GLfloat g_block_vertex_buffer_data[2*2*18];
    for (int i=0;i<G_BLOCK_ROW;++i)
    {
        for (int j=0;j<G_BLOCK_COLUMN;++j)
        {
            // 左下
            g_block_vertex_buffer_data[(j+(G_BLOCK_COLUMN*i))*18+0] = -1.0f;
            g_block_vertex_buffer_data[(j+(G_BLOCK_COLUMN*i))*18+1] =  1.0f - G_NORMALIZED_BLOCK_HEIGHTSIZE;
            g_block_vertex_buffer_data[(j+(G_BLOCK_COLUMN*i))*18+2] =  0.0f;

            g_block_vertex_buffer_data[(j+(G_BLOCK_COLUMN*i))*18+0] += j*G_NORMALIZED_BLOCK_WIDTHSIZE;
            g_block_vertex_buffer_data[(j+(G_BLOCK_COLUMN*i))*18+1] -= i*G_NORMALIZED_BLOCK_HEIGHTSIZE;
            
            // 右下
            g_block_vertex_buffer_data[(j+(G_BLOCK_COLUMN*i))*18+3] = -1.0f + G_NORMALIZED_BLOCK_WIDTHSIZE;
            g_block_vertex_buffer_data[(j+(G_BLOCK_COLUMN*i))*18+4] =  1.0f - G_NORMALIZED_BLOCK_HEIGHTSIZE;
            g_block_vertex_buffer_data[(j+(G_BLOCK_COLUMN*i))*18+5] =  0.0f;

            g_block_vertex_buffer_data[(j+(G_BLOCK_COLUMN*i))*18+3] += j*G_NORMALIZED_BLOCK_WIDTHSIZE;
            g_block_vertex_buffer_data[(j+(G_BLOCK_COLUMN*i))*18+4] -= i*G_NORMALIZED_BLOCK_HEIGHTSIZE;
            
            // 左上
            g_block_vertex_buffer_data[(j+(G_BLOCK_COLUMN*i))*18+6] = -1.0f;
            g_block_vertex_buffer_data[(j+(G_BLOCK_COLUMN*i))*18+7] =  1.0f;
            g_block_vertex_buffer_data[(j+(G_BLOCK_COLUMN*i))*18+8] =  0.0f;

            g_block_vertex_buffer_data[(j+(G_BLOCK_COLUMN*i))*18+7] += j*G_NORMALIZED_BLOCK_WIDTHSIZE;
            g_block_vertex_buffer_data[(j+(G_BLOCK_COLUMN*i))*18+8] -= i*G_NORMALIZED_BLOCK_HEIGHTSIZE;

            // 右上
            g_block_vertex_buffer_data[(j+(G_BLOCK_COLUMN*i))*18+9]  = -1.0f + G_NORMALIZED_BLOCK_WIDTHSIZE;
            g_block_vertex_buffer_data[(j+(G_BLOCK_COLUMN*i))*18+10] =  1.0f;
            g_block_vertex_buffer_data[(j+(G_BLOCK_COLUMN*i))*18+11] =  0.0f;

            g_block_vertex_buffer_data[(j+(G_BLOCK_COLUMN*i))*18+9]  += j*G_NORMALIZED_BLOCK_WIDTHSIZE;
            g_block_vertex_buffer_data[(j+(G_BLOCK_COLUMN*i))*18+10] -= i*G_NORMALIZED_BLOCK_HEIGHTSIZE;

            // 右下コピー
            g_block_vertex_buffer_data[(j+(G_BLOCK_COLUMN*i))*18+12] = g_block_vertex_buffer_data[(j+(G_BLOCK_COLUMN*i))*18+3];
            g_block_vertex_buffer_data[(j+(G_BLOCK_COLUMN*i))*18+13] = g_block_vertex_buffer_data[(j+(G_BLOCK_COLUMN*i))*18+4];
            g_block_vertex_buffer_data[(j+(G_BLOCK_COLUMN*i))*18+14] = g_block_vertex_buffer_data[(j+(G_BLOCK_COLUMN*i))*18+5];

            // 左上コピー
            g_block_vertex_buffer_data[(j+(G_BLOCK_COLUMN*i))*18+15] = g_block_vertex_buffer_data[(j+(G_BLOCK_COLUMN*i))*18+6];
            g_block_vertex_buffer_data[(j+(G_BLOCK_COLUMN*i))*18+16] = g_block_vertex_buffer_data[(j+(G_BLOCK_COLUMN*i))*18+7];
            g_block_vertex_buffer_data[(j+(G_BLOCK_COLUMN*i))*18+17] = g_block_vertex_buffer_data[(j+(G_BLOCK_COLUMN*i))*18+8];
        }
    };

    // バッファオブジェクトへのハンドル
    GLuint block_position_buffer;
    // 頂点バッファオブジェクトを作成->頂点位置をバッファオブジェクト(OpenGL)に転送
    glGenBuffers(1, &block_position_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, block_position_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_block_vertex_buffer_data), g_block_vertex_buffer_data, GL_STATIC_DRAW);

    // ブロックの色を指定------------------------色----
    GLfloat g_block_color_buffer_data[3][G_BLOCK_COLUMN*G_BLOCK_ROW*18];
    for (int i=0; i<3; ++i)
    {
        switch (i)
        {
        // 色１（耐久力３）
        case 0:
            for (int j=0; j<G_BLOCK_COLUMN*G_BLOCK_ROW*18; ++j)
            {
                g_block_color_buffer_data[i][j] = 1.0f;
                g_block_color_buffer_data[i][++j] = 0.0f;
                g_block_color_buffer_data[i][++j] = 0.0f;
            }
            break;
        // 色２（耐久力２）
        case 1:
            for (int j=0; j<G_BLOCK_COLUMN*G_BLOCK_ROW*18; ++j)
            {
                g_block_color_buffer_data[i][j] = 0.5f;
                g_block_color_buffer_data[i][++j] = 0.0f;
                g_block_color_buffer_data[i][++j] = 0.2f;
            }
            break;
        // 色３（耐久力１）
        case 2:
            for (int j=0; j<G_BLOCK_COLUMN*G_BLOCK_ROW*18; ++j)
            {
                g_block_color_buffer_data[i][j] = 0.3f;
                g_block_color_buffer_data[i][++j] = 0.0f;
                g_block_color_buffer_data[i][++j] = 0.3f;
            }
            break;
        }
    }

    // バッファオブジェクトへのハンドル
    GLuint block_color_buffer[3];

    // 頂点色バッファオブジェクトを作成->頂点色をバッファオブジェクト(OpenGL)に転送
    for(int i=0;i<3;++i)
    {
        glGenBuffers(1, &block_color_buffer[i]);
        glBindBuffer(GL_ARRAY_BUFFER, block_color_buffer[i]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(g_block_color_buffer_data[i]), g_block_color_buffer_data[i], GL_STATIC_DRAW);
    }

    // VAOを解除
    glBindVertexArray(0);
    // VAO--ブロック-------------------------------------------------------

    
    
    // VAO--パドル-------------------------------------------------------
    glBindVertexArray(VertexArrayID[1]);
    // パドルの頂点位置のバッファ---------------------------位置----
    GLfloat g_paddle_vertex_buffer_data[] = {
        -0.2f, -0.9f,                                           0.0f,   // 左下
         0.2f, -0.9f,                                           0.0f,   // 右下
        -0.2f,(-0.9f+((2.0f/G_WINDOW_HEIGHT)*G_PADDLE_HEIGHT)), 0.0f,
         0.2f, -0.9f,                                           0.0f,
         0.2f,(-0.9f+((2.0f/G_WINDOW_HEIGHT)*G_PADDLE_HEIGHT)), 0.0f,
        -0.2f,(-0.9f+((2.0f/G_WINDOW_HEIGHT)*G_PADDLE_HEIGHT)), 0.0f,
    };
    
    // バッファオブジェクトへのハンドル
    GLuint paddle_position_buffer;
    // 頂点バッファオブジェクトを作成->頂点位置をバッファオブジェクト(OpenGL)に転送
    glGenBuffers(1, &paddle_position_buffer);
    
    glBindBuffer(GL_ARRAY_BUFFER, paddle_position_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_paddle_vertex_buffer_data), g_paddle_vertex_buffer_data, GL_STATIC_DRAW);


    // パドルの色を指定------------------------色----
    GLfloat g_paddle_color_buffer_data[] = {
        0.6f,0.6f,0.6f,
        0.6f,0.6f,0.6f,
        0.6f,0.6f,0.6f,
        0.6f,0.6f,0.6f,
        0.6f,0.6f,0.6f,
        0.6f,0.6f,0.6f,
    };
    
    // バッファオブジェクトへのハンドル
    GLuint paddle_color_buffer;
    // 頂点色バッファオブジェクトを２個作成->頂点色をバッファオブジェクト(OpenGL)に転送
    glGenBuffers(1, &paddle_color_buffer);
    
    glBindBuffer(GL_ARRAY_BUFFER, paddle_color_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_paddle_color_buffer_data), g_paddle_color_buffer_data, GL_STATIC_DRAW);

    // VAOを解除
    glBindVertexArray(0);
    // VAO--パドル-------------------------------------------------------


    // VAO--ボール-------------------------------------------------------
    glBindVertexArray(VertexArrayID[2]);
    // ボールの頂点位置のバッファ---------------------------位置----
//    // 円の頂点を作る
//    GLfloat g_ball_vertex_buffer_data[32*2];
//    const float radius = 0.05f;
//    for(int i = 0; i < 32; ++i){
//        GLfloat angle = static_cast<GLfloat>((M_PI*2.0*i)/32);
//        g_ball_vertex_buffer_data[i*2]   = radius * std::sin(angle) + 2.0f/G_WINDOW_HEIGHT;
//        g_ball_vertex_buffer_data[i*2+1] = radius * std::cos(angle) + 2.0f/G_WINDOW_HEIGHT;
//    }

//    int div = 32;
    int div = 8;
    GLfloat g_ball_vertex_buffer_data[div*3*3];
    int count = 0;
    float x = 0, y = -0.8, z = 0, radius = 0.03f;
    for (int i = 0; i < div; i++) {
        float theta1 = (float) (2.0f /div*i*Pai);
        float theta2 = (float) (2.0f /div*(i+1)*Pai);
        g_ball_vertex_buffer_data[count++] = x*G_BALL_CIRCULARITY_RATIO;
        g_ball_vertex_buffer_data[count++] = y;
        g_ball_vertex_buffer_data[count++] = z;
        g_ball_vertex_buffer_data[count++] = ((float)cos((double)theta1)*radius+x)*G_BALL_CIRCULARITY_RATIO;
        g_ball_vertex_buffer_data[count++] = (float)sin((double)theta1)*radius+y;
        g_ball_vertex_buffer_data[count++] = z;
        g_ball_vertex_buffer_data[count++] = ((float)cos((double)theta2)*radius+x)*G_BALL_CIRCULARITY_RATIO;
        g_ball_vertex_buffer_data[count++] = (float)sin((double)theta2)*radius+y;
        g_ball_vertex_buffer_data[count++] = z;
    }

    // バッファオブジェクトへのハンドル
    GLuint ball_position_buffer;
    // 頂点色バッファオブジェクトを２個作成->頂点色をバッファオブジェクト(OpenGL)に転送
    glGenBuffers(1, &ball_position_buffer);
    
    glBindBuffer(GL_ARRAY_BUFFER, ball_position_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_ball_vertex_buffer_data), g_ball_vertex_buffer_data, GL_STATIC_DRAW);

    // ボールの色を指定------------------------色----
    GLfloat g_ball_color_buffer_data[div*3*3];
    for (int i=0; i<div*3*3; ++i)
    {
        g_ball_color_buffer_data[i] = 0.8f;
    }
    
    // バッファオブジェクトへのハンドル
    GLuint ball_color_buffer;
    // 頂点色バッファオブジェクトを２個作成->頂点色をバッファオブジェクト(OpenGL)に転送
    glGenBuffers(1, &ball_color_buffer);
    
    glBindBuffer(GL_ARRAY_BUFFER, ball_color_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_ball_color_buffer_data), g_ball_color_buffer_data, GL_STATIC_DRAW);

    // VAOを解除
    glBindVertexArray(0);
    // VAO--ボール-------------------------------------------------------
    
    // モニタとの同期
    glfwSwapInterval(1);

    do{
        // ウィンドウ背景色を塗りつぶし
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // シェーダを使う
        glUseProgram(programID);

        // 最初の属性バッファ：頂点：ブロック-------------------------------
        glBindVertexArray(VertexArrayID[0]);

        glEnableVertexAttribArray(vertexPosition_modelspaceID);
        glBindBuffer(GL_ARRAY_BUFFER, block_position_buffer);
        glVertexAttribPointer(
                              vertexPosition_modelspaceID,  // シェーダ内のlayoutと同じID
                              3,                            // サイズ
                              GL_FLOAT,                     // タイプ
                              GL_FALSE,                     // 正規化？
                              0,                            // 属性間を何個飛ばしするかバイトオフセット
                              (void*)0                      // 配列バッファオフセット
                              );


        // 最初の属性バッファ：色：ブロック----------
        glEnableVertexAttribArray(vertexColorID);
        glBindBuffer(GL_ARRAY_BUFFER, block_color_buffer[0]);
        glVertexAttribPointer(
                              vertexColorID,  // シェーダ内のlayoutと同じID
                              3,                            // サイズ
                              GL_FLOAT,                     // タイプ
                              GL_FALSE,                     // 正規化？
                              0,                            // 属性間を何個飛ばしするかバイトオフセット
                              (void*)0                      // 配列バッファオフセット
                              );
        // 三角形を描きます！
        glDrawArrays(GL_TRIANGLES, 0, 3*2*G_BLOCK_COLUMN*G_BLOCK_ROW); // 頂点0から始まります。合計4つの頂点です。→1つの四角形です。
        glDisableVertexAttribArray(vertexPosition_modelspaceID);
        glDisableVertexAttribArray(vertexColorID);
        glBindVertexArray(0);

        
        // 次の属性バッファ：頂点：パドル------------------------------------
        glBindVertexArray(VertexArrayID[1]);

        // キー入力->座標を変更
		if(keyboardControl())
        {
//            glm::mat4 diffMat4 = glm::translate(position);
            glBindBuffer(GL_ARRAY_BUFFER, paddle_position_buffer);
            GLfloat *ptr_paddle = (GLfloat*)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
            if(ptr_paddle)
            {
                // 画面端で止まるようにする
                // -1.xxx 〜 1.xxxがありえるので、めり込まないようにしたい…
                if(ptr_paddle[0]+position.x >= -1 && ptr_paddle[3]+position.x <= 1)
                {
                    for(int i=0; i<sizeof(ptr_paddle); ++i)
                    {
                        ptr_paddle[3*i] += position.x;
                    }
                }
                position.x = 0;
                glUnmapBuffer(GL_ARRAY_BUFFER);
            }
            glBindBuffer(GL_ARRAY_BUFFER, 0);
        }
        
//        glUniformMatrix4fv(diffMat4ID, 1, GL_FALSE, &diffMat4[0][0]);

        glEnableVertexAttribArray(vertexPosition_modelspaceID);
        glBindBuffer(GL_ARRAY_BUFFER, paddle_position_buffer);
        glVertexAttribPointer(
                              vertexPosition_modelspaceID,                  // シェーダ内のlayoutとあわせないといけません。
                              3,                  // サイズ
                              GL_FLOAT,           // タイプ
                              GL_FALSE,           // 正規化？
                              0,                  // ストライド
                              (void*)0            // 配列バッファオフセット
                              );

        // 次の属性バッファ：色：パドル-------------
        glEnableVertexAttribArray(vertexColorID);
        glBindBuffer(GL_ARRAY_BUFFER, paddle_color_buffer);
        glVertexAttribPointer(
                              vertexColorID,  // シェーダ内のlayoutと同じID
                              3,                            // サイズ
                              GL_FLOAT,                     // タイプ
                              GL_FALSE,                     // 正規化？
                              0,                            // 属性間を何個飛ばしするかバイトオフセット
                              (void*)0                      // 配列バッファオフセット
                              );
        // 三角形を描きます！
        glDrawArrays(GL_TRIANGLES, 0, 3*2);
        glDisableVertexAttribArray(vertexPosition_modelspaceID);
        glDisableVertexAttribArray(vertexColorID);
        glBindVertexArray(0);
        
        // 次の属性バッファ：頂点：ボール------------------------------------
        glBindVertexArray(VertexArrayID[2]);

        // ボールを動かす
        ballMover();
        glBindBuffer(GL_ARRAY_BUFFER, ball_position_buffer);
        GLfloat *ptr_ball = (GLfloat*)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
        if(ptr_ball)
        {
//            int size_ball = sizeof(ptr_ball);
            for(int i=0; i<sizeof(ptr_ball); ++i)
            {
                ptr_ball[3*i+0] += ballmoved.x;
                ptr_ball[3*i+1] += ballmoved.y;
                ptr_ball[3*i+2] += ballmoved.z;
            }
            glUnmapBuffer(GL_ARRAY_BUFFER);
        }
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        glEnableVertexAttribArray(vertexPosition_modelspaceID);
        glBindBuffer(GL_ARRAY_BUFFER, ball_position_buffer);
        glVertexAttribPointer(
                              vertexPosition_modelspaceID,                  // シェーダ内のlayoutとあわせないといけません。
                              3,                  // サイズ
                              GL_FLOAT,           // タイプ
                              GL_FALSE,           // 正規化？
                              0,                  // ストライド
                              (void*)0            // 配列バッファオフセット
                              );
        
        // 次の属性バッファ：色：ボール---------------
        glEnableVertexAttribArray(vertexColorID);
        glBindBuffer(GL_ARRAY_BUFFER, ball_color_buffer);
        glVertexAttribPointer(
                              vertexColorID,  // シェーダ内のlayoutと同じID
                              3,                            // サイズ
                              GL_FLOAT,                     // タイプ
                              GL_FALSE,                     // 正規化？
                              0,                            // 属性間を何個飛ばしするかバイトオフセット
                              (void*)0                      // 配列バッファオフセット
                              );
        // 三角形を描きます！
        glDrawArrays(GL_TRIANGLES, 0, 32*3);
        glDisableVertexAttribArray(vertexPosition_modelspaceID);
        glDisableVertexAttribArray(vertexColorID);
        glBindVertexArray(0);

        
        
        
        // バッファをスワップする。
        glfwSwapBuffers(window);
        glfwPollEvents();
        
    } // ESCキーが押されたかウィンドウが閉じたかをチェックする。
    while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
          glfwWindowShouldClose(window) == 0 );
    
	// Cleanup VBO
	glDeleteBuffers(1, &block_position_buffer);
	glDeleteBuffers(3, block_color_buffer);
	glDeleteBuffers(1, &paddle_position_buffer);
	glDeleteBuffers(1, &paddle_color_buffer);
	glDeleteBuffers(1, &ball_position_buffer);
	glDeleteBuffers(1, &ball_color_buffer);
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