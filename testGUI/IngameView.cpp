//
//  IngameView.cpp
//  testGUI
//
//  Created by toru-bayashi on 2014/12/01.
//
//

#include "IngameView.h"

Paddle::Paddle()
{
    paddleSize.w = 100;
    paddleSize.h = 20;
    paddlePoint.x = 250;
    paddlePoint.y = 100;
}

Paddle::Paddle(int w, int h)
{
    paddleSize.w = w;
    paddleSize.h = h;
}

Paddle::~Paddle()
{
}

SizeWH Paddle::getSize() const
{
    return paddleSize;
}