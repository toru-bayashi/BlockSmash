//
//  Utility.cpp
//  BlockSmash
//
//  Created by toru-bayashi on 2014/12/07.
//  Copyright (c) 2014年 toru-wakabayashi. All rights reserved.
//

#include "Utility.h"

void Utility::textureLoad()
{
    
}

unsigned char **Utility::stageLoad()
{
    unsigned char **blockMap = nullptr;
    
    // ステージのブロック配列を読み込む
    for (int i=0; i<G_STAGE_COUNT; ++i) {
        for (int j=0; i<G_BLOCK_WIDTH*G_BLOCK_HEIGHT; ++j) {
            blockMap[i][j] = (unsigned char)Utility::BLOCK_NORMAL;
        }
    }
    
    return blockMap;
}
