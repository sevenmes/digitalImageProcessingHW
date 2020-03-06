//
//  main.cpp
//  L2_2_videocap
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
    VideoCapture cap;
    
    cap.open(0);
    
    if(!cap.isOpened())
    {
        std::cout<<"不能打开视频文件"<< std::endl;
        return-1;
    }
    
    double fps = cap.get(CAP_PROP_FPS);
    std::cout<<"fps"<< fps << std::endl;
    while(1)
    {
        cv::Mat frame;
        bool rSucess = cap.read(frame);
        if(!rSucess)
        {
            std::cout << "不能从视频文件中读取帧" << std::endl;
            break;
        }
        else{
            cv::imshow("frame",frame);
        }
        waitKey(30);
    }
}
