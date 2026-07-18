#include "Image.hpp"

Image::Image() : data(), timestamp(0.0) {}

Image::Image(const cv::Mat& frame, double ts) : data(frame), timestamp(ts) {}

int Image::getWidth() const {
    return data.cols;
}

int Image::getHeight() const {
    return data.rows;
}

double Image::getTimestamp() const{
    return timestamp;
}

bool Image::isValid() const{
    return !data.empty();
}

const cv::Mat& Image::getMat() const{
    return data;
}

void Image::toGrayscale(){
    cv::cvtColor(data, data, cv::COLOR_BGR2GRAY);
}

