#include <iostream>
#include <chrono>
#include "Camera.hpp"

int main() {
    Camera camera(0);

    if (!camera.startCapture()) {
        std::cout << "No se pudo abrir la camara." << std::endl;
        return 1;
    }

    std::cout << "Camara abierta. Presiona ESC para salir." << std::endl;

    auto lastTime = std::chrono::steady_clock::now();
    int frameCount = 0;
    double fps = 0.0;

    while (true) {
        Image frame = camera.getFrame();

        if (!frame.isValid()) {
            std::cout << "Frame invalido, saliendo." << std::endl;
            break;
        }

        frameCount++;
        auto now = std::chrono::steady_clock::now();
        double elapsed = std::chrono::duration<double>(now - lastTime).count();

        if (elapsed >= 1.0) {
            fps = frameCount / elapsed;
            frameCount = 0;
            lastTime = now;
        }

        cv::Mat displayFrame = frame.getMat().clone();
        std::string fpsText = "FPS: " + std::to_string(static_cast<int>(fps));
        cv::putText(displayFrame, fpsText, cv::Point(10, 30),
                    cv::FONT_HERSHEY_SIMPLEX, 1.0, cv::Scalar(0, 255, 0), 2);

        cv::imshow("Eye Tracking - Camera Feed", displayFrame);

        if (cv::waitKey(1) == 27) {  // 27 = tecla ESC
            break;
        }
    }

    camera.stopCapture();
    cv::destroyAllWindows();
    return 0;
}