//
//  IncludeGLLib.h
//  BlockSmash
//
//  Created by toru-bayashi on 2015/01/19.
//  Copyright (c) 2015年 toru-wakabayashi. All rights reserved.
//

#ifndef BlockSmash_IncludeGLLib_h
#define BlockSmash_IncludeGLLib_h

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

#include "Common/shader.hpp"

#endif

#endif


#endif
