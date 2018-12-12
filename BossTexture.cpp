//
// Created by amanda on 12/12/18.
//

#include "BossTexture.h"

Boss *BossTexture::getBoss() const {
    return boss;
}

void BossTexture::setBoss(Boss *boss) {
    BossTexture::boss = boss;
}
