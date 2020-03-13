//
//  main.cpp
//  L3_1_pixelExtraction
//
//  Created by 舒子琪 on 2020/3/13.
//  Copyright © 2020 舒子琪. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
    VideoCapture cap;
    cap.open("/Users/shuziqi/Desktop/test.mp4");
    
    double scale=0.5;
    
    //0-180
    //肤色
    double i_minH = 0;
    double i_maxH = 20;
    //0-255
    double i_minS = 43;
    double i_maxS = 255;
    //0-255
    double i_minV = 55;
    double i_maxV = 255;
    
    while (1)
    {
        Mat frame;
        Mat hsvMat;
        Mat detectMat;
        
        cap >> frame;
        Size ResImgSiz = Size(frame.cols*scale, frame.rows*scale);
        Mat rFrame = Mat(ResImgSiz, frame.type());
        resize(frame, rFrame, ResImgSiz, INTER_LINEAR);
        
        cvtColor(rFrame, hsvMat, COLOR_BGR2HSV);
        
        rFrame.copyTo(detectMat);
        
        cv::inRange(hsvMat, Scalar(i_minH, i_minS, i_minV),Scalar(i_maxH, i_maxS, i_maxV),detectMat);
        
        imshow("while: in the range", detectMat);
        imshow("frame", rFrame);
        
        waitKey(30);
    }
}
