//
//  Ingame.h
//  testGUI
//
//  Created by toru-bayashi on 2014/12/01.
//
//

#ifndef __testGUI__Ingame__
#define __testGUI__Ingame__

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

#endif /* defined(__testGUI__Ingame__) */