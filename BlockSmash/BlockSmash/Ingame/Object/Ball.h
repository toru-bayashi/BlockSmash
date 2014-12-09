//
//  Ball.h
//  BlockSmash
//
//  Created by toru-bayashi on 2014/12/07.
//  Copyright (c) 2014年 toru-wakabayashi. All rights reserved.
//

#ifndef __BlockSmash__Ball__
#define __BlockSmash__Ball__

#include "IngameObject.h"

class Ball : virtual public IngameObject
{
public:
    Ball();
private:
    int m_speed;
    int m_power;
};

#endif /* defined(__BlockSmash__Ball__) */
