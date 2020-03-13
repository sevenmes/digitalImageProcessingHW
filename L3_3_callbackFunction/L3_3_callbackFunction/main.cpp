//
//  main.cpp
//  L3_3_callbackFunction
//
//  Created by 舒子琪 on 2020/3/13.
//  Copyright © 2020 舒子琪. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using std::string;
string window_name = "binaryMat";

void threshod_Mat(int th, void* data)
{
    
    Mat src = *(Mat*)(data);
    
    Mat dst;
    //二值化
    threshold(src, dst, th, 255, 0);
    
    imshow(window_name, dst);
    
}

int main()
{
    Mat srcMat;
    Mat gryMat;
    int lowTh = 30;
    int maxTh = 255;
    
    srcMat = imread("/Users/shuziqi/Desktop/test.jpg");
    if (!srcMat.data) //判断图像是否载入
    {
        std::cout << "载入图像失败" << std::endl;
        return 0;
    }
    
    cvtColor(srcMat, gryMat, CV_BGR2GRAY);
    imshow(window_name, gryMat);
    createTrackbar("threshold",
                   window_name,
                   &lowTh,
                   maxTh,
                   threshod_Mat,
                   &gryMat);
    
    waitKey(0);
    
    return 0;
}
