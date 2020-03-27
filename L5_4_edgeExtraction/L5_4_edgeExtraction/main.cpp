//
//  main.cpp
//  L5_4_edgeExtraction
//
//  Created by 舒子琪 on 2020/3/27.
//  Copyright © 2020 舒子琪. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using std::string;


int main()
{
    VideoCapture cap;

    cap.open("/Users/shuziqi/Desktop/test.mp4");
    
    while(1)
    {
        cv::Mat frame;
        cv::Mat rframe1, rframe2;
        cv::Mat result1, result2;
        
        cap >> frame;
        
        Sobel(frame, rframe1, CV_16SC1, 0, 1, 3);
        Sobel(frame, rframe2, CV_16SC1, 1, 0, 3);
        convertScaleAbs(rframe1, result1);
        convertScaleAbs(rframe2, result2);
        imshow("x", result1);
        imshow("y", result2);
    
        waitKey(30);
    }
}

