//
//  main.cpp
//  L5_3_gaussianMeanFilter
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
        cv::Mat rframe;
        
        cap >> frame;
        
        GaussianBlur(frame, rframe, Size(3,3), 0, 0);
        imshow("before", frame);
        imshow("after", rframe);
    
        waitKey(30);
    }
}

