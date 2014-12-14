//
//  Scene.h
//  BlockSmash
//
//  Created by toru-bayashi on 2014/12/07.
//  Copyright (c) 2014年 toru-wakabayashi. All rights reserved.
//

#ifndef __BlockSmash__Scene__
#define __BlockSmash__Scene__

class Scene
{
public:
    void initialize();
    void finalize();
    Scene();
    virtual void sceneMake() = 0;
    virtual void sceneRemove() = 0;
protected:
    char *m_sceneName;
};

#endif /* defined(__BlockSmash__Scene__) */
