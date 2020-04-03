//
//  main.cpp
//  L6_2_rotationAndScaling
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
    cv::Mat srcMat = cv::imread("/Users/shuziqi/Desktop/lena.jpg");
    if(srcMat.empty()) return -1;
    
    //旋转-40，缩放尺度为
    float angle = -10.0, scale = 0.8;
    //旋转中心为图像中心
    cv::Point2f center(srcMat.cols*0.5, srcMat.rows*0.5);
    //获得变换矩阵
    const cv::Mat affine_matrix = cv::getRotationMatrix2D(center, angle, scale);
    
    cv::warpAffine(srcMat, dstMat, affine_matrix, srcMat.size());
    
    cv::imshow("src", srcMat);
    cv::imshow("dst", dstMat);
    cv::waitKey(0);
}
