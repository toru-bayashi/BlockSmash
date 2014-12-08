//
//  Scene.h
//  BlockSmash
//
//  Created by toru-bayashi on 2014/12/07.
//  Copyright (c) 2014年 toru-wakabayashi. All rights reserved.
//

#ifndef __BlockSmash__Scene__
#define __BlockSmash__Scene__

#include <iostream>

class Scene
{
public:
    void initialize();
    void finalize();
    Scene();
protected:
    char *m_sceneName;
};

#endif /* defined(__BlockSmash__Scene__) */
