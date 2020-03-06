//
//  main.cpp
//  L2_3_paint
//
//  Created by 舒子琪 on 2020/3/6.
//  Copyright © 2020 舒子琪. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using std::string;


int main()
{
    cv::Point pt;
    Mat dispMat = imread("/Users/shuziqi/Desktop/test.png", 3);
    pt.x = 10;
    pt.y = 10;
    circle(dispMat,pt,5,CV_RGB(255,0,0),1,8,0);
    
    
    line(dispMat,pt,pt,CV_RGB(255,0,0),1,8,0);

    
    cv::Rect rect;
    rect.x = 10;
    rect.y = 10;
    rect.width=50;
    rect.height=50;
    rectangle(dispMat, rect, CV_RGB(255,0,0),1,8,0);

    
    imshow("dispMat", dispMat);
    
    waitKey(0);
    return 0;

}
