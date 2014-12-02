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

#define WINDOWSIZE_W 640
#define WINDOWSIZE_H 640

void display(void);
void resize(int, int);
void keyboard(unsigned char, int, int);
void draw();
void init(void);

#endif /* defined(__testGUI__window_top__) */