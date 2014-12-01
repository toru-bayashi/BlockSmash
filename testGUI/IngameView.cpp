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
    size_w = 100;
    size_h = 20;
    left.setPosition(250, 100);
    right.setPosition(350, 100);
}

Paddle::Paddle(int ws, int hs)
{
    size_w = ws;
    size_h = hs;
}

Paddle::~Paddle()
{
}

int Paddle::getSizeW() const
{
    return size_w;
}

int Paddle::getSizeH() const
{
    return size_h;
}
