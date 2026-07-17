#pragma once
#include <opencv2/opencv.hpp>

class Image{
    public:
        Image();
        Image(const cv::Mat& frame, double timestamp);

        int getWidth() const;
        int getHeight() const;
        double getTimestamp() const;
        bool isValid() const;

        const cv::Mat& getMat() const;
        void toGrayscale();

    private:
        cv::Mat data;
        double timestamp;

};