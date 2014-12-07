//
//  SoundComponent.h
//  BlockSmash
//
//  Created by toru-bayashi on 2014/12/07.
//  Copyright (c) 2014年 toru-wakabayashi. All rights reserved.
//

#ifndef __BlockSmash__SoundComponent__
#define __BlockSmash__SoundComponent__

class SoundComponent
{
public:
    void playSE(int seID);
    void playBGM(int bgmID);
    SoundComponent();
    
private:
//    int *bgmList[];
    int *seList[];
};

#endif /* defined(__BlockSmash__SoundComponent__) */
