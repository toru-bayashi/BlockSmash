//
//  PhysicsComponent.h
//  BlockSmash
//
//  Created by toru-bayashi on 2014/12/07.
//  Copyright (c) 2014年 toru-wakabayashi. All rights reserved.
//

#ifndef __BlockSmash__PhysicsComponent__
#define __BlockSmash__PhysicsComponent__

class PhysicsComponent
{
public:
    bool collisionDetection();
    void move();
    bool isColliding();
};

#endif /* defined(__BlockSmash__PhysicsComponent__) */
