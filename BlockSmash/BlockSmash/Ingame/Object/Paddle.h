//
//  Paddle.h
//  BlockSmash
//
//  Created by toru-bayashi on 2014/12/07.
//  Copyright (c) 2014年 toru-wakabayashi. All rights reserved.
//

#ifndef __BlockSmash__Paddle__
#define __BlockSmash__Paddle__

#include <iostream>
#include "IngameObject.h"

class Paddle : virtual public IngameObject
{
public:
    Paddle();
private:
    int m_grade;
};

#endif /* defined(__BlockSmash__Paddle__) */
