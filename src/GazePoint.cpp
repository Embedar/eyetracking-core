#include "GazePoint.hpp"

GazePoint::GazePoint(float x, float y, float timestamp) 
    : x(x), y(y), timestamp(timestamp) {}

float GazePoint::getX() const{
    return x;
}

void GazePoint::setX(float value){
    x=value;
}

float GazePoint::getY() const{
    return y;
}

void GazePoint::setY(float value){
    y=value;
}

float GazePoint::getTimeStamp()const{
    return timestamp;
}

void GazePoint::setTimeStamp(float value){
    timestamp= value;
}