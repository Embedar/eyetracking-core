#include "Camera.hpp"

Camera::Camera(int id) : deviceId(id), capturing(false), capture() {}

bool Camera::isCapturing() const{
    return capturing;
}

bool Camera::startCapture(){
    capture.open(deviceId);
    capturing = capture.isOpened();
    return capturing;
}

void Camera::stopCapture(){
    capture.release();
    capturing = false;
}

Image Camera::getFrame(){
    cv::Mat frame;
    capture >> frame;
    double timestamp = capture.get(cv::CAP_PROP_POS_MSEC);
    return Image(frame, timestamp);
}