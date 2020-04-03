//
//  main.cpp
//  L6_4_projectionTransformation
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
    
    const cv::Point2f pts1[] = {
        cv::Point2f(150, 150),
        cv::Point2f(150, 300),
        cv::Point2f(350, 300),
        cv::Point2f(350, 150)};
    
    const cv::Point2f pts2[] = {
        cv::Point2f(200, 150),
        cv::Point2f(200, 300),
        cv::Point2f(340, 270),
        cv::Point2f(340, 180)};
    
    const cv::Mat perspective_matrix = cv::getAffineTransform(pts1, pts2);
    
    cv::warpAffine(srcMat, dstMat, perspective_matrix, srcMat.size());
    
    cv::imshow("src",srcMat);
    cv::imshow("dst",dstMat);
    
    cv::waitKey(0);
    
}
