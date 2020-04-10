//
//  main.cpp
//  L7_3_HoughLinesP
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
    
    std::vector<cv::Vec4i> lines;
    cv::HoughLinesP(dstMat, lines, 1, CV_PI/180, 30, 5, 20);

    for(size_t i = 0; i < lines.size(); i++)
    {
        Vec4i l = lines[i];
        line( srcMat, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(186,88,255), 1, CV_AA);
    }
    
    imshow("结果", srcMat);
    waitKey(0);
    return 0;

}
