//
// Created by amanda on 12/12/18.
//

#ifndef PROJECT_1_BOSSTEXTURE_H
#define PROJECT_1_BOSSTEXTURE_H


#include "ElementTexture.h"
#include "Boss.h"

class BossTexture: public ElementTexture {
public:
    Boss *getBoss() const;

    void setBoss(Boss *boss);

private:
    Boss *boss;
};


#endif //PROJECT_1_BOSSTEXTURE_H
