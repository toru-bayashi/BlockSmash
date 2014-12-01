/*
 *  window_top.h
 *  testGUI
 *
 *  Created by toru-bayashi on 12/11/05.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __testGUI__window_top__
#define __testGUI__window_top__

class XYPoint
{
private:
	int posi_x, posi_y;
public:
	XYPoint();
	void setPosition(int xp, int yp);
	int getPosX() const;
	int getPosY() const;
};

#endif /* defined(__testGUI__window_top__) */