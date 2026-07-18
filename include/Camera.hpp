#pragma once
#include <opencv2/opencv.hpp>
#include "Image.hpp"

class Camera{
    public:
        Camera(int deviceId);

        bool isCapturing() const;
        bool startCapture();
        void stopCapture();
        Image getFrame();

    private:
        int devideId;
        bool capturing;
        cv::VideoCapture capture;

}