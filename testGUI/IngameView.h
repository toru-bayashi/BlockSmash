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
    int size_w, size_h;
    XYPoint left, right;
public:
    Paddle();
    Paddle(int ws, int hs);
    ~Paddle();
    int getSizeW() const;
    int getSizeH() const;
};

#endif /* defined(__testGUI__IngameView__) */