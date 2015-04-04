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

class Ball : virtual public IngameObject
{
public:
    Ball();
    
private:
    int m_x,m_y;
    int m_width,m_height;
    int m_dx,m_dy;

    int m_speed;
    int m_power;
};

class Paddle : virtual public IngameObject
{
public:
    Paddle();
private:
    int m_x,m_y;
    int m_width,m_height;

    int m_grade;
};

class Block : virtual public IngameObject
{
public:
    Block();
private:
    int m_x,m_y;
    int m_width,m_height;

    int m_endurance;
    bool m_fItem;
};

class Stage : virtual public IngameObject
{
public:
    Stage();
//    Stage(unsigned char **&stageMap);
    void setStage(unsigned char **&stageMap);
private:
    unsigned char ***m_stageMap; // stageMapのリファレンス
    unsigned char m_stageID;
};

class Item : virtual public IngameObject
{
public:
    Item();
    double powerUp();
    void speedUp();
    void speedDown();
    void paddleUpgrade();
    void paddleDowngrade();
    void none();
};

#endif /* defined(__BlockSmash__IngameObject__) */
