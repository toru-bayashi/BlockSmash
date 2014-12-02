//
//  IngameView.h
//  testGUI
//
//  Created by toru-bayashi on 2014/12/01.
//
//

#ifndef __testGUI__IngameView__
#define __testGUI__IngameView__

#include "Ingame.h"

class Paddle {
private:
    PointXY paddlePoint;
    SizeWH paddleSize;
public:
    Paddle();
    Paddle(int, int);
    ~Paddle();
    SizeWH getSize() const;
};

#endif /* defined(__testGUI__IngameView__) */