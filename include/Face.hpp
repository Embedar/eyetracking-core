#pragma once
#include "Eye.hpp"

class Face {
    public:
        Face();

        bool isDetected() const;
        const Eye& getLeftEye() const;
        const Eye& getRightEye() const;
        void setDetected(bool value);

    private:
        Eye LeftEye;
        Eye RightEye;
        bool detected;
};