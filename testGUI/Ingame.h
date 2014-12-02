//
//  Ingame.h
//  testGUI
//
//  Created by toru-bayashi on 2014/12/01.
//
//

#ifndef __testGUI__Ingame__
#define __testGUI__Ingame__

typedef struct {
    int x;
    int y;
} PointXY;

typedef struct {
    int w;
    int h;
} SizeWH;

class Dimention2
{
protected:
    PointXY point;
    SizeWH size;
public:
	virtual void set2Size(int, int);
    virtual SizeWH get2Size() const;
};

class Square : Dimention2
{
private:
public:
	Square();
	Square(int, int);
	void set2Size(int, int);
    SizeWH get2Size() const;
};

#endif /* defined(__testGUI__Ingame__) */