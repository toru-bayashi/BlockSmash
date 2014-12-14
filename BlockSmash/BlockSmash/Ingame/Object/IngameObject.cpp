//
//  IngameObject.cpp
//  BlockSmash
//
//  Created by toru-bayashi on 2014/12/07.
//  Copyright (c) 2014年 toru-wakabayashi. All rights reserved.
//

#include "IngameObject.h"

IngameObject::IngameObject()
{
    
}

Ball::Ball()
{
    m_graphicsComp = new GraphicsComponent();
    m_physicsComp = new PhysicsComponent();
    m_soundComp = new SoundComponent();
    
    m_speed = 1;
    m_power = 1;
}

Paddle::Paddle()
{
    m_graphicsComp = new GraphicsComponent();
    
    m_grade = 1;
}

Block::Block()
{
    m_graphicsComp = new GraphicsComponent();
}

Stage::Stage()
{
//    m_stageMap = &stageMap;
    m_stageID = 0;
    m_graphicsComp = new GraphicsComponent();
}

void Stage::setStage(unsigned char **&stageMap)
{
    m_stageMap = &stageMap;
}

Item::Item()
{
    m_graphicsComp = new GraphicsComponent();
}

double Item::powerUp()
{
    return 1.3;
}

void Item::speedUp()
{
    
}

void Item::speedDown()
{
    
}

void Item::paddleUpgrade()
{
    
}

void Item::paddleDowngrade()
{
    
}

void Item::none()
{
    
}