//
//  main.cpp
//  L12_2_bgSub
//
//  Created by 舒子琪 on 2020/5/22.
//  Copyright © 2020 舒子琪. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;
using std::string;

int main()
{
    VideoCapture capVideo("/Users/shuziqi/Desktop/俯卧撑.MOV");
    if (!capVideo.isOpened()) {
        std::cout << "Unable to open video!" << std::endl;
        return -1;
    }

    //计数器
    int cnt = 0;

    Mat frame;
    Mat bgMat;
    Mat subMat;
    Mat bny_subMat;

    while (1) {

        capVideo >> frame;
        cvtColor(frame,frame,COLOR_BGR2GRAY);

        if (cnt== 0) {
            //第一帧，获得背景图像
            frame.copyTo(bgMat);
        }
        else {
            //第二帧开始背景差分
            //背景图像和当前图像相减
            absdiff(frame, bgMat, subMat);
            //差分结果二值化
            threshold(subMat, bny_subMat,20, 255, CV_THRESH_BINARY);

            imshow("b_subMat",bny_subMat);
            imshow("frame",frame);
            waitKey(30);
        }

        cnt++;
    }

    return 0;
}
