//
//  main.cpp
//  L6_1_canny
//
//  Created by 舒子琪 on 2020/4/3.
//  Copyright © 2020 舒子琪. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using std::string;


int main()
{
    cv::Mat dstMat;
    cv::Mat x, y, result1, result2;
    cv::Mat srcMat = cv::imread("/Users/shuziqi/Desktop/lena.jpg");
    if(srcMat.empty()) return -1;
    cvtColor(srcMat, result1, CV_BGR2GRAY);
    GaussianBlur(result1, result1, Size(7, 7), 1.5, 1.5);
    Canny(result1, result1, 0, 30, 3);
    
    cvtColor(srcMat, dstMat, CV_BGR2GRAY);
    Sobel(dstMat, x, CV_16SC1, 1, 0);
    Sobel(dstMat, y, CV_16SC1, 0, 1);
    Canny(x, y, result2, 0, 30);
    
    imshow("result1", result1);
    imshow("result2", result2);
    waitKey(0);
}
