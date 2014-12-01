//
//  Ingame.cpp
//  testGUI
//
//  Created by toru-bayashi on 2014/12/01.
//
//

#include "Ingame.h"

XYPoint::XYPoint()
{
	posi_x = 0;
	posi_y = 0;
}

void XYPoint::setPosition(int xp, int yp)
{
	posi_x = xp;
	posi_y = yp;
}

int XYPoint::getPosX() const
{
	return posi_x;
}

int XYPoint::getPosY() const
{
	return posi_y;
}
