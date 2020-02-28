//
//  main.cpp
//  L1_3_uchar
//
//  Created by 舒子琪 on 2020/2/28.
//  Copyright © 2020 舒子琪. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using std::string;


int main(int argc, const char * argv[]) {
    
    uchar threshold=100;
    
    cv::Mat srcMat = imread("/Users/shuziqi/Desktop/test.jpg");
    
    int height = srcMat.rows;//行数，即图片的高
    
    int width = srcMat.cols;//每行元素的总元素量
    
    for (int j = 0;j < height; j++)
    {
        for (int i = 0;i < width;i++)
        {
            //开始处理每个像素
            uchar average = (srcMat.at<Vec3b>(j, i)[0] +
                             srcMat.at<Vec3b>(j, i)[1] +
                             srcMat.at<Vec3b>(j, i)[2])/3;
            
            if (average > threshold)
                
                average = 255;
                
            else average = 0;
            
            srcMat.at<Vec3b>(j, i)[0] = average;
            srcMat.at<Vec3b>(j, i)[1] = average;
            srcMat.at<Vec3b>(j, i)[2] = average;
            //结束像素处理
        }//单行处理结束
    }
    
    imshow("src", srcMat);
    
    waitKey(0);
    
    return 0;
}
