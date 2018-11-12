//
// Created by amanda on 27/10/18.
//

#ifndef PROJECT_1_POSITION_H
#define PROJECT_1_POSITION_H


class Position {
private: int x;
         int y;
public:

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

    void setX(int x) {
        Position::x = x;
        // TODO:  case x <0
    }

    void setY(int y) {
        Position::y = y;
        // TODO:  case x <0
    }

public:
    Position(){};
    Position(int _x,int _y) :x(_x), y(_y){}
};


#endif //PROJECT_1_POSITION_H
