//
//  main.cpp
//  L3_2_binaryImage
//
//  Created by 舒子琪 on 2020/3/13.
//  Copyright © 2020 舒子琪. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using std::string;


int main() {
    cv::Mat result1;
    cv::Mat result2;
    cv::Mat srcMat = imread("/Users/shuziqi/Desktop/test.jpg",0);
    
    threshold(srcMat, result1, 100, 255, THRESH_BINARY);
    namedWindow("全局二值化");
    
    adaptiveThreshold(srcMat, result2, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, 15, 10);
    namedWindow("区域自适应二值化");
    
    imshow("全局二值化", result1);
    waitKey(0);
    
    imshow("区域自适应二值化", result2);
    waitKey(0);
    

    return 0;

}
