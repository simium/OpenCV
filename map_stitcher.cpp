#include <iostream>	// for standard I/O

#include <opencv2/opencv.hpp>
#include <opencv2/stitching/stitcher.hpp>

using namespace cv;
using namespace std;

int main(int argc, char *argv[])
{
    vector<Mat> imgSource;
    Mat imgResult;

    imgSource.push_back(imread("./stitching_img/mat1.png"));
    imgSource.push_back(imread("./stitching_img/mat2.png"));
    imgSource.push_back(imread("./stitching_img/mat3.png"));
    imgSource.push_back(imread("./stitching_img/mat4.png"));
    imgSource.push_back(imread("./stitching_img/mat5.png"));
    imgSource.push_back(imread("./stitching_img/mat6.png"));
    imgSource.push_back(imread("./stitching_img/mat7.png"));

    Stitcher stitcher = Stitcher::createDefault(false);

    unsigned long t0, tFinal;

    // Start time
    t0 = getTickCount();

    // Actual stitching
    Stitcher::Status status = stitcher.stitch(imgSource, imgResult);

    // End time
    tFinal = getTickCount();
    std::cout << (tFinal - t0)/getTickFrequency() << std::endl;

    if (status == Stitcher::OK) {
        // Save stitched image as png
        vector<int> paramsPNG;
        paramsPNG.push_back(CV_IMWRITE_PNG_COMPRESSION);
        paramsPNG.push_back(9);

        imwrite("mat0.png", imgResult, paramsPNG);

        std::cout << "Map stitcher: OK." << std::endl;
    } else {
        std::cout << "Map stitcher: NO OK." << std::endl;
    }

    return 0;
}
