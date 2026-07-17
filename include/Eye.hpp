#pragma once
class Eye{
    public:
        Eye();
        
        bool isOpen() const;
        void setPupilPosition(float x, float y);
    private:
        float pupilX;
        float pupilY;
        bool open;
};