#include "Face.hpp"

Face::Face() : LeftEye(), RightEye(), detected(false){}

bool Face::isDetected() const{
    return detected;
}

const Eye& Face::getLeftEye() const{
    return LeftEye;
}

const Eye& Face::getRightEye() const{
    return RightEye;
}

void Face::setDetected(bool value){
    detected = value;
}


