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
    cv::Mat result1, result2;
    cv::Mat srcMat = cv::imread("/Users/shuziqi/Desktop/lena.jpg");
    if(srcMat.empty()) return -1;
    cvtColor(srcMat, dstMat, CV_BGR2GRAY);
    GaussianBlur(dstMat, dstMat, Size(7, 7), 1.5, 1.5);
    
    Canny(dstMat, dstMat, 0, 30, 3);
    
    imshow("1", dstMat);
    waitKey(0);
}
