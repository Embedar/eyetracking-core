#pragma once

class GazePoint{
    public:
        GazePoint();
        GazePoint(float x, float y, float timestamp);

        float getX() const;
        void setX(float value);
        float getY() const;
        void setY(float value);
        float getTimeStamp() const;
        void setTimeStamp(float value);
    private:
        float x;
        float y;
        float timestamp;
};