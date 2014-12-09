//
//  IngameObject.h
//  BlockSmash
//
//  Created by toru-bayashi on 2014/12/07.
//  Copyright (c) 2014年 toru-wakabayashi. All rights reserved.
//

#ifndef __BlockSmash__IngameObject__
#define __BlockSmash__IngameObject__

#include "PhysicsComponent.h"
#include "SoundComponent.h"
#include "GraphicsComponent.h"

class IngameObject
{
public:
    IngameObject();
protected:
    PhysicsComponent *m_physicsComp;
    SoundComponent *m_soundComp;
    GraphicsComponent *m_graphicsComp;
};

#endif /* defined(__BlockSmash__IngameObject__) */
