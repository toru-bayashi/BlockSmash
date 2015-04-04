//
//  main.cpp
//  BlockSmash
//
//  Created by toru-bayashi on 2014/12/07.
//  Copyright (c) 2014年 toru-wakabayashi. All rights reserved.
//
#include "IncludeGLLib.h"
#include "Utility/IncludeStandard.h"
#include "BSManager.h"
#include "Utility.h"
#include "Common/shader.hpp"

static float G_NORMALIZED_BLOCK_WIDTHSIZE   =    ((2.0f/G_WINDOW_WIDTH)*G_BLOCK_WIDTH);
static float G_NORMALIZED_BLOCK_HEIGHTSIZE  =   ((2.0f/G_WINDOW_HEIGHT)*G_BLOCK_HEIGHT);

static float G_NORMALIZED_PADDLE_HEIGHTSIZE  =   ((2.0f/G_WINDOW_HEIGHT)*G_PADDLE_HEIGHT);

static int G_CONFIGURED_TRIANGLE_BLOCK_VERTEXNUM = 3*2;
static int G_COORDINATENUM_XYZ = 3;
//static int G_BLOCK_VERTEXNUM = 4;

//using namespace std;
//using namespace BSManager;

GLFWwindow* window = NULL;

// パドルの移動量用
glm::vec3 position(0,0,0);
float speed = 1.5f; // 3 units / second

// ボールの移動量用
glm::vec3 ballmoved(0,0,0);
float ballspeed = 0.5f;

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

GLuint arrayBufferHandling (const GLfloat *bufferData, unsigned int size)
{
    // バッファオブジェクトへのハンドル
    GLuint bufferHandle;
    // 頂点バッファオブジェクトを作成->頂点位置をバッファオブジェクト(OpenGL)に転送
    glGenBuffers(1, &bufferHandle);
    glBindBuffer(GL_ARRAY_BUFFER, bufferHandle);
    glBufferData(GL_ARRAY_BUFFER, size, bufferData, GL_STATIC_DRAW);
    
    return bufferHandle;
}

int createWindow(int window_width, int window_height)
{
    if( !glfwInit() ){
        std::cout << "GLFWの初期化に失敗しました。n" << std::endl;
        return EXIT_FAILURE;
    }
    
    glfwWindowHint(GLFW_SAMPLES, 4); // 4x アンチエイリアス
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // OpenGL3.3を使います。
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // MacOS用：必ずしも必要ではありません。
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // 古いOpenGLは使いません。
    
    // Windowを開き、OpenGLコンテキストを作ります
    window = glfwCreateWindow(window_width, window_height, "BlockSmash!", NULL, NULL);
    if( window == NULL ){
        std::cout << "GLFWウィンドウのオープンに失敗しました。 もしIntelのGPUならば, 3.3に対応していません。チュートリアルのバージョン2.1を試してください。n" << std::endl;
        glfwTerminate();
        return EXIT_FAILURE;
    }
    glfwMakeContextCurrent(window); // GLEWを初期化する
    
    glewExperimental=true; // コアプロファイルで必要となります。
    if (glewInit() != GLEW_OK) {
        std::cout << "GLEWの初期化に失敗しました。n" << std::endl;
        return EXIT_FAILURE;
    }
    
    // 下でエスケープキーが押されるのを捉えるのを保証します。
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    
    glClearColor(0.2f, 0.2f, 0.2f, 0.0f);
    
    return 0;
}

int main()
{
    // ウィンドウの初期化
    if(createWindow(G_WINDOW_WIDTH, G_WINDOW_HEIGHT))
        return EXIT_FAILURE;

    // ブロック崩し管理オブジェクトを実体化------------------
//    static BSManager *bsMan;
//    bsMan = new BSManager();
    
    // シェーダからGLSLプログラムを作りコンパイルする。
    GLuint programID = LoadShaders( "/Users/wakabayashitooru/BlockSmash/BlockSmash/BlockSmash/SimpleVertexShader.vertexshader", "/Users/wakabayashitooru/BlockSmash/BlockSmash/BlockSmash/SimpleFragmentShader.fragmentshader" );
//    GLuint programID = LoadShaders( "$(SRCROOT)/SimpleVertexShader.vertexshader", "$(SRCROOT)/SimpleFragmentShader.fragmentshader" );

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
    
//    glViewport(0, 0, G_WINDOW_WIDTH, G_WINDOW_HEIGHT);
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
    static const int blockVertexNum = (G_BLOCK_COLUMN)*(G_BLOCK_ROW)*(G_CONFIGURED_TRIANGLE_BLOCK_VERTEXNUM)*(G_COORDINATENUM_XYZ);
    static const float baseBlockUnderY = 1.0f - G_NORMALIZED_BLOCK_HEIGHTSIZE;
    static const float baseBlockRightX = -1.0f + G_NORMALIZED_BLOCK_WIDTHSIZE;
    GLfloat g_block_vertex_buffer_data[blockVertexNum];
    for (int i=0;i<G_BLOCK_ROW;++i)
    {
        for (int j=0;j<G_BLOCK_COLUMN;++j)
        {
            const int startIndex = (j+(G_BLOCK_COLUMN*i))*(G_CONFIGURED_TRIANGLE_BLOCK_VERTEXNUM)*(G_COORDINATENUM_XYZ);
            const float currentBlockPositonX = j*G_NORMALIZED_BLOCK_WIDTHSIZE;
            const float currentBlockPositonY = i*G_NORMALIZED_BLOCK_HEIGHTSIZE;
            
            // 左下
            g_block_vertex_buffer_data[startIndex+0] = -1.0f            + currentBlockPositonX;
            g_block_vertex_buffer_data[startIndex+1] =  baseBlockUnderY - currentBlockPositonY;
            g_block_vertex_buffer_data[startIndex+2] =  0.0f;

            // 右下
            g_block_vertex_buffer_data[startIndex+3] =  baseBlockRightX + currentBlockPositonX;
            g_block_vertex_buffer_data[startIndex+4] =  baseBlockUnderY - currentBlockPositonY;
            g_block_vertex_buffer_data[startIndex+5] =  0.0f;

            // 右上
            g_block_vertex_buffer_data[startIndex+6] =  baseBlockRightX + currentBlockPositonX;
            g_block_vertex_buffer_data[startIndex+7] =  1.0f            - currentBlockPositonY;
            g_block_vertex_buffer_data[startIndex+8] =  0.0f;

            // 左上
            g_block_vertex_buffer_data[startIndex+9]  = -1.0f + currentBlockPositonX;
            g_block_vertex_buffer_data[startIndex+10] =  1.0f - currentBlockPositonY;
            g_block_vertex_buffer_data[startIndex+11] =  0.0f;
            
            // 左下コピー
            g_block_vertex_buffer_data[startIndex+12] = -1.0f            + currentBlockPositonX;
            g_block_vertex_buffer_data[startIndex+13] =  baseBlockUnderY - currentBlockPositonY;
            g_block_vertex_buffer_data[startIndex+14] =  0.0f;

            // 右上
            g_block_vertex_buffer_data[startIndex+15] =  baseBlockRightX + currentBlockPositonX;
            g_block_vertex_buffer_data[startIndex+16] =  1.0f            - currentBlockPositonY;
            g_block_vertex_buffer_data[startIndex+17] =  0.0f;
        }
    };

    // バッファオブジェクトへのハンドル
    GLuint block_position_buffer = arrayBufferHandling(g_block_vertex_buffer_data, sizeof(g_block_vertex_buffer_data));

    // ブロックの色を指定------------------------色----
    enum BlockType
    {
        Level1,
        Level2,
        Level3,
        BlockTypeMax
    };
        
    srand((unsigned int)time(NULL));
    GLfloat g_block_color_buffer_data[blockVertexNum];
    for (int j=0; j<blockVertexNum; ++j)
    {
        float r1 = 0.f;
        float g1 = 0.f;
        float b1 = 0.f;
        float r2 = 0.f;
        float g2 = 0.f;
        float b2 = 0.f;
        float r0 = 0.7f;
        float g0 = 0.7f;
        float b0 = 0.7f;
        const int blockLevel = rand()%3;
        switch (blockLevel)
        {
                // 色１（耐久力３）
            case Level1:
                r1 = 1.f;
                r2 = r1/2;
                break;
                // 色２（耐久力２）
            case Level2:
                r1 = 0.5f;
                r2 = r1/2;
                b1 = 0.2f;
                b2 = b1/2;
                break;
                // 色３（耐久力１）
            case Level3:
                r1 = 0.3f;
                r2 = r1/2;
                b1 = 0.3f;
                b2 = b2/2;
                break;
        }
        g_block_color_buffer_data[j]   = r1;
        g_block_color_buffer_data[++j] = g1;
        g_block_color_buffer_data[++j] = b1;

        g_block_color_buffer_data[++j] = r2;
        g_block_color_buffer_data[++j] = g2;
        g_block_color_buffer_data[++j] = b2;

        g_block_color_buffer_data[++j] = r1;
        g_block_color_buffer_data[++j] = g1;
        g_block_color_buffer_data[++j] = b1;

        g_block_color_buffer_data[++j] = r0;
        g_block_color_buffer_data[++j] = g0;
        g_block_color_buffer_data[++j] = b0;

        g_block_color_buffer_data[++j] = r1;
        g_block_color_buffer_data[++j] = g1;
        g_block_color_buffer_data[++j] = b1;

        g_block_color_buffer_data[++j] = r1;
        g_block_color_buffer_data[++j] = g1;
        g_block_color_buffer_data[++j] = b1;
    }
    
    // バッファオブジェクトへのハンドル
    GLuint block_color_buffer = arrayBufferHandling(g_block_color_buffer_data, sizeof(g_block_color_buffer_data));

    // VAOを解除
    glBindVertexArray(0);
    // VAO--ブロック-------------------------------------------------------

    
    
    // VAO--パドル-------------------------------------------------------
    glBindVertexArray(VertexArrayID[1]);
    // パドルの頂点位置のバッファ---------------------------位置----
    GLfloat g_paddle_vertex_buffer_data[] = {
        -0.2f, -0.9f,                                           0.0f,   // 左下
         0.2f, -0.9f,                                           0.0f,   // 右下
        -0.2f,(-0.9f+(G_NORMALIZED_PADDLE_HEIGHTSIZE)),         0.0f,   // 左上
         0.2f,(-0.9f+(G_NORMALIZED_PADDLE_HEIGHTSIZE)),         0.0f,   // 右上
         0.2f, -0.9f,                                           0.0f,   // 右下コピー
        -0.2f,(-0.9f+(G_NORMALIZED_PADDLE_HEIGHTSIZE)),         0.0f,   // 左上コピー
    };
//    static int pdlVerBufSize = (int)sizeof(g_paddle_vertex_buffer_data)/sizeof(GLfloat);
    static int paddleVertexNum = (G_CONFIGURED_TRIANGLE_BLOCK_VERTEXNUM)*(G_COORDINATENUM_XYZ);
    
    // バッファオブジェクトへのハンドル
    GLuint paddle_position_buffer = arrayBufferHandling(g_paddle_vertex_buffer_data, sizeof(g_paddle_vertex_buffer_data));

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
    GLuint paddle_color_buffer = arrayBufferHandling(g_paddle_color_buffer_data, sizeof(g_paddle_color_buffer_data));

    // VAOを解除
    glBindVertexArray(0);
    // VAO--パドル-------------------------------------------------------


    // VAO--ボール-------------------------------------------------------
    glBindVertexArray(VertexArrayID[2]);
    // ボールの頂点位置のバッファ---------------------------位置----
    const int div = 32;
    static const int ballVertexNum = div*3*3;
    
    GLfloat g_ball_vertex_buffer_data[ballVertexNum];
    int ballVerBufSize = (int)sizeof(g_ball_vertex_buffer_data)/sizeof(GLfloat);
    int count = 0;
    float x = 0, y = -0.8, z = 0, radius = 0.03f;
    for (int i = 0; i < div; ++i) {
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
    GLuint ball_position_buffer = arrayBufferHandling(g_ball_vertex_buffer_data, sizeof(g_ball_vertex_buffer_data));

    // ボールの色を指定------------------------色----
    GLfloat g_ball_color_buffer_data[ballVertexNum];
    for (int i=0; i<ballVertexNum; ++i)
    {
        g_ball_color_buffer_data[i] = 0.8f;
    }
    
    // バッファオブジェクトへのハンドル
    GLuint ball_color_buffer = arrayBufferHandling(g_ball_color_buffer_data, sizeof(g_ball_color_buffer_data));

    // VAOを解除
    glBindVertexArray(0);
    // VAO--ボール-------------------------------------------------------
    
    // モニタとの同期
    glfwSwapInterval(1);

    do{
        // ***********************************************************
        // ウィンドウ背景色を塗りつぶし
        // ***********************************************************
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // ***********************************************************
        // 描画
        // ***********************************************************
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
        glBindBuffer(GL_ARRAY_BUFFER, block_color_buffer);
        glVertexAttribPointer(
                              vertexColorID,  // シェーダ内のlayoutと同じID
                              3,                            // サイズ
                              GL_FLOAT,                     // タイプ
                              GL_FALSE,                     // 正規化？
                              0,                            // 属性間を何個飛ばしするかバイトオフセット
                              (void*)0                      // 配列バッファオフセット
                              );
        // ブロックを描画
        glDrawArrays(GL_TRIANGLES, 0, G_CONFIGURED_TRIANGLE_BLOCK_VERTEXNUM*G_BLOCK_COLUMN*G_BLOCK_ROW); // 三角形2つからなる６つの頂点＊ブロックの個数
        glDisableVertexAttribArray(vertexPosition_modelspaceID);
        glDisableVertexAttribArray(vertexColorID);
        glBindVertexArray(0);

        
        // 次の属性バッファ：頂点：パドル------------------------------------
        glBindVertexArray(VertexArrayID[1]);

        // キー入力->座標を変更
		if(keyboardControl())
        {
//            glm::mat4 diffMat4 = glm::translate(position);
//            glUniformMatrix4fv(diffMat4ID, 1, GL_FALSE, &diffMat4[0][0]);

//            glMatrixMode(GL_MODELVIEW);
//            glLoadIdentity();
            
            glBindBuffer(GL_ARRAY_BUFFER, paddle_position_buffer);
            GLfloat *ptr_paddle = (GLfloat*)glMapBuffer(GL_ARRAY_BUFFER, GL_READ_WRITE);
//            int size_paddle = sizeof(ptr_paddle);
            if(ptr_paddle)
            {
                // 画面端で止まるようにする
                // -1.xxx 〜 1.xxxがありえるので、めり込まないようにしたい…
                const bool isScreenOver = (abs(ptr_paddle[0]+position.x) <= 1.03f) && (abs(ptr_paddle[3]+position.x) <= 1.03f);
                if(isScreenOver)
                {
                    for(int i=0; i<paddleVertexNum; ++i)
                    {
                        ptr_paddle[3*i] += position.x;
                    }
                }
                position.x = 0;
                glUnmapBuffer(GL_ARRAY_BUFFER);
            }
            glBindBuffer(GL_ARRAY_BUFFER, 0);
        }
        

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
        glDrawArrays(GL_TRIANGLES, 0, G_CONFIGURED_TRIANGLE_BLOCK_VERTEXNUM);
        glDisableVertexAttribArray(vertexPosition_modelspaceID);
        glDisableVertexAttribArray(vertexColorID);
        glBindVertexArray(0);
        
        // 次の属性バッファ：頂点：ボール------------------------------------
        glBindVertexArray(VertexArrayID[2]);

        // ボールを動かす        
        ballMover();
        glBindBuffer(GL_ARRAY_BUFFER, ball_position_buffer);
        GLfloat *ptr_ball = (GLfloat*)glMapBuffer(GL_ARRAY_BUFFER, GL_READ_WRITE);
        if(ptr_ball)
        {
//            int size_ball = sizeof(ptr_ball);
            for(int i=0; i<ballVerBufSize; ++i)
            {
                const int vertexStartIndex = 3*i;
                ptr_ball[vertexStartIndex] += ballmoved.x;
                ptr_ball[vertexStartIndex+1] += ballmoved.y;
                ptr_ball[vertexStartIndex+2] += ballmoved.z;
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
        glDrawArrays(GL_TRIANGLES, 0, 3*div);
        glDisableVertexAttribArray(vertexPosition_modelspaceID);
        glDisableVertexAttribArray(vertexColorID);
        glBindVertexArray(0);

        
        
        // ***********************************************************
        // バッファをスワップする。
        // ***********************************************************
        glfwSwapBuffers(window);

        // ***********************************************************
        // イベントを取得
        // ***********************************************************
        glfwPollEvents();
        
    } // ESCキーが押されたかウィンドウが閉じたかをチェックする。
    while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
          glfwWindowShouldClose(window) == 0 );
    
	// Cleanup VBO
	glDeleteBuffers(1, &block_position_buffer);
	glDeleteBuffers(1, &block_color_buffer);
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
    
    return EXIT_SUCCESS;
}