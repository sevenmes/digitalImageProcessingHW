//
//  main.cpp
//  L12_1_absdiff
//
//  Created by 舒子琪 on 2020/5/22.
//  Copyright © 2020 舒子琪. All rights reserved.
//


#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;
using std::string;
cv::Point vP;

//鼠标响应函数
void on_mouse(int EVENT, int x, int y, int flags, void* userdata)
{

    Mat a;
    a = *(Mat*)userdata;
    switch (EVENT)
    {
    case EVENT_LBUTTONDOWN:
    {
        vP.x = x;
        vP.y = y;
        drawMarker(a,vP,Scalar(255,255,255));
        imshow("mouseCallback", a);
        return;
    }
    break;
    }

}

//绘制直方图
int drawHist(cv::Mat & histMat, float * srcHist, int bin_width, int bin_heght)
{
    histMat.create(bin_heght, 256 * bin_width, CV_8UC3);
    histMat = Scalar(255, 255, 255);
    float maxVal = *std::max_element(srcHist, srcHist + 256);

    for (int i = 0; i < 256; i++) {
        Rect binRect;
        binRect.x = i*bin_width;
        float height_i = (float)bin_heght*srcHist[i] / maxVal;
        binRect.height = (int)height_i;
        binRect.y = bin_heght - binRect.height;
        binRect.width = bin_width;
        rectangle(histMat, binRect, CV_RGB(255, 0, 0), -1);
    }
    return 0;
}


int main()
{
    VideoCapture capVideo("/Users/shuziqi/Desktop/俯卧撑.MOV");

    int cnt = 0;
    int bin_width = 3;
    int bin_heght = 50;
    float histgram[256] = {0};
    Mat histMat;

    while (1) {

        Mat frame;
        Mat grayMat;
        capVideo >> frame;

        if (frame.empty()) {
            std::cout << "Unable to read frame!" << std::endl;
            return -1;
        }

        //第一帧选取像素
        if (cnt == 0) {
            Mat selectMat;
            frame.copyTo(selectMat);
            namedWindow("mouseCallback");
            imshow("mouseCallback", selectMat);
            setMouseCallback("mouseCallback", on_mouse, &selectMat);
            waitKey(0);
            destroyAllWindows();
        }

        cvtColor(frame,grayMat,COLOR_BGR2GRAY);
        int index = grayMat.at<uchar>(vP.y,vP.x);
        //直方图相应的bin加1
        histgram[index]++;
        //绘制直方图
        drawHist(histMat, histgram, bin_width,bin_heght);
        drawMarker(frame, vP, Scalar(255, 255, 255));
        imshow("frame",frame);
        imshow("histMat",histMat);

        waitKey(30);
        cnt++;
    }

    return 0;
}
