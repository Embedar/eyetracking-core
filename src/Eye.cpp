#include "Eye.hpp"

Eye::Eye() : pupilX(0.0f), pupilY(0.0f), open(true){}

bool Eye::isOpen() const{
    return open;
}

void Eye::setPupilPosition(float x, float y){
    pupilX = x;
    pupilY = y;
}

