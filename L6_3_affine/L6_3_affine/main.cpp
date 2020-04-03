//
//  main.cpp
//  L6_3_affine
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
    cv::Mat srcMat = cv::imread("/Users/shuziqi/Desktop/lena.jpg",1);
    if(srcMat.empty()) return -1;
    
    const cv::Point2f src_pt[] = {
        cv::Point2f(200, 200),
        cv::Point2f(250, 200),
        cv::Point2f(200, 100)};
    
    const cv::Point2f dst_pt[] = {
    cv::Point2f(300, 100),
    cv::Point2f(300, 50),
    cv::Point2f(200, 100)};
    
    const cv::Mat affine_matrix = cv::getAffineTransform(src_pt, dst_pt);
    
    cv::warpAffine(srcMat, dstMat, affine_matrix, srcMat.size());
    
    cv::imshow("src",srcMat);
    cv::imshow("dst",dstMat);
    
    cv::waitKey(0);
    
}
