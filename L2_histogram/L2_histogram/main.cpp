//
//  main.cpp
//  L2_histogram
//
//  Created by 舒子琪 on 2020/3/6.
//  Copyright © 2020 舒子琪. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using std::string;

Mat histgrampic = Mat(256, 256, CV_8UC3);

int main() {
    
    cv::Mat src = imread("/Users/shuziqi/Desktop/test.png",0);

    int height = src.rows;//行数，即图片的高
    int width = src.cols;//每行元素的总元素量
    int num = height * width;
    float histgram[256];
    int n;
    for (n = 0; n < 256; n++)
        histgram[n] = 0;//初始化
    
    for (int j = 0;j < height; j++)
    {
        for (int i = 0;i < width;i++)
        {
            //开始处理每个像素
            n = src.ptr<uchar>(i)[j];
            histgram[n]++;
            //结束像素处理
        }//单行处理结束
    }

    for (int a = 0; a < 256; a++)
    {
        //绘制直方图
        cv::Point pt1;
        cv::Point pt2;
        pt1.x = a;
        pt1.y = 0;
        pt2.x = a;
        pt2.y = histgram[a] / num;

        line(histgrampic,pt1,pt2,CV_RGB(255, 0, 0),1,8,0);

    }

    imshow("histgrampic", histgrampic);

    waitKey(0);
    
    return 0;
}



