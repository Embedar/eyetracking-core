#ifndef CAMERA_MANAGER_HPP
#define CAMERA_MANAGER_HPP

#include <opencv2/opencv.hpp>

class CameraManager{
public:
    CameraManager(int cameraIndex = 0);
    ~CameraManager();

    bool isOpened() const;
}
#endif