//
//  main.cpp
//  L2_RGBchannel
//
//  Created by 舒子琪 on 2020/3/6.
//  Copyright © 2020 舒子琪. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using std::string;


int main() {
    
    cv::Mat src_color = imread("/Users/shuziqi/Desktop/test.png");
    std::vector<cv::Mat> channels;
    cv::split(src_color, channels);

    cv::Mat B =channels.at(0);
    cv::Mat G =channels.at(1);
    cv::Mat R =channels.at(2);
    
    cv::imshow("red",R);
    cv::imshow("blue",B);
    cv::imshow("green",G);
    cv::imshow("original Mat",src_color);
    
    waitKey(0);
    
}
