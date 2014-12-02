//
//  Ingame.cpp
//  testGUI
//
//  Created by toru-bayashi on 2014/12/01.
//
//

#include "Ingame.h"

Square::Square()
{
	size.w = 0;
	size.h = 0;
}

Square::Square(int w, int h)
{
	size.w = w;
	size.h = h;
}

void Square::set2Size(int w, int h)
{
	size.w = w;
	size.h = h;
}

SizeWH Square::get2Size() const
{
	return size;
}