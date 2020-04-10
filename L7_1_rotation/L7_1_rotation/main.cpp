//
//  main.cpp
//  L7_1_rotation
//
//  Created by 舒子琪 on 2020/4/10.
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
    
    float angle = -10.0, scale = 1;

    cv::Point2f center(srcMat.cols*0.5, srcMat.rows*0.5);
    cv::Mat rot = cv::getRotationMatrix2D(center, angle, scale);
    
    cv::Rect bbox = cv::RotatedRect(center, srcMat.size(), angle).boundingRect();
    
    rot.at<double>(0,2) += bbox.width*0.5 - center.x;
    rot.at<double>(1,2) += bbox.height*0.5 - center.y;
    
    cv::warpAffine(srcMat, dstMat, rot, bbox.size());
    
    cv::imshow("src", srcMat);
    cv::imshow("dst", dstMat);
    cv::waitKey(0);
}
