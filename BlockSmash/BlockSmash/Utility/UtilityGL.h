//
//  UtilityGL.h
//  BlockSmash
//
//  Created by toru-bayashi on 2015/04/04.
//  Copyright (c) 2015年 toru-wakabayashi. All rights reserved.
//

#ifndef __BlockSmash__UtilityGL__
#define __BlockSmash__UtilityGL__

#include "IncludeStandard.h"
#include "IncludeGLLib.h"
#include "BSManager.h"
#include "Utility.h"

namespace UtilityGL
{
    int createWindow(int window_width, int window_height);
    void render();
    void ballMover();
    GLuint arrayBufferHandling (const GLfloat *bufferData, unsigned int size);
    bool keyboardControl();
    void bufferFactory();
    int dummyMain();
};

#endif /* defined(__BlockSmash__UtilityGL__) */
