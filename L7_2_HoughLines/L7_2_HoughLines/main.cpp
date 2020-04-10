//
//  main.cpp
//  L7_2_HoughLines
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
    cv::Mat srcMat = cv::imread("/Users/shuziqi/Desktop/metal-part-distorted-03.png");
    if(srcMat.empty()) return -1;
    
    Canny(srcMat, dstMat,50, 200, 3);
    
    std::vector<cv::Vec2f> lines;
    cv::HoughLines(dstMat, lines, 1, CV_PI/180, 100, 0, 0);
    std::vector<cv::Vec2f>::iterator it = lines.begin();
    for (; it != lines.end(); ++it){
        float rho = (*it)[0], theta = (*it)[1];
        cv::Point pt1, pt2;
        double a = cos(theta);
        double b = sin(theta);
        double x0 = a*rho;
        double y0 = b*rho;
        pt1.x = cv::saturate_cast<int>(x0 + 1000 * (-b));
        pt1.y = cv::saturate_cast<int>(y0 + 1000 * (a));
        pt2.x = cv::saturate_cast<int>(x0 - 1000 * (-b));
        pt2.y = cv::saturate_cast<int>(y0 - 1000 * (a));
        cv::line(srcMat, pt1, pt2, cv::Scalar(0, 0, 255),1 ,CV_AA);
    }
    
    imshow("canny",dstMat);
    imshow("结果", srcMat);
    waitKey(0);
    return 0;

}
