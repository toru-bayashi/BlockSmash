//
//  Ball.cpp
//  BlockSmash
//
//  Created by toru-bayashi on 2014/12/07.
//  Copyright (c) 2014年 toru-wakabayashi. All rights reserved.
//

#include "Ball.h"

Ball::Ball()
{
    m_graphicsComp = new GraphicsComponent();
    m_physicsComp = new PhysicsComponent();
    m_soundComp = new SoundComponent();
    
    m_speed = 1;
    m_power = 1;
}