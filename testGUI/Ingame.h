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
	virtual void set2Size(int, int) = 0;
    virtual SizeWH get2Size() const = 0;
};

class Square : public Dimention2
{
private:
public:
	Square();
	Square(int, int);
	Square(Square const &);
    ~Square(){}
	void set2Size(int, int);
    SizeWH get2Size() const;
};

#endif /* defined(__testGUI__Ingame__) */