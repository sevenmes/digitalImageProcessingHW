//
//  main.cpp
//  L10_1_mouse
//
//  Created by 舒子琪 on 2020/5/8.
//  Copyright © 2020 舒子琪. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;
using std::string;

std::vector<Point>  mousePoints;
Point points;

//鼠标响应函数
void on_mouse(int EVENT, int x, int y, int flags, void* userdata)
{

    Mat hh;
    hh = *(Mat*)userdata;
    Point p(x, y);
    switch (EVENT)
    {
    case EVENT_LBUTTONDOWN:
    {
        points.x = x;
        points.y = y;
        mousePoints.push_back(points);
        circle(hh, points, 4, cvScalar(255, 255, 255), -1);
        imshow("mouseCallback", hh);
    }
    break;
    }

}

int selectPolygon(cv::Mat srcMat, cv::Mat &dstMat)
{
    
    vector<vector<Point>> contours;
    cv::Mat selectMat;

    cv::Mat m = cv::Mat::zeros(srcMat.size(), CV_32F);

    m = 1;

    if (!srcMat.empty()) {
        srcMat.copyTo(selectMat);
        srcMat.copyTo(dstMat);
    }
    else {
        std::cout << "failed to read image!:" << std::endl;
        return -1;
    }

    namedWindow("mouseCallback");
    imshow("mouseCallback", selectMat);
    setMouseCallback("mouseCallback", on_mouse, &selectMat);
    waitKey(0);
    destroyAllWindows();
    //计算roi
    contours.push_back(mousePoints);
    if (contours[0].size() < 3) {
        std::cout << "failed to read image!:" << std::endl;
        return -1;
    }

    drawContours(m, contours, 0, Scalar(0), -1);

    m.copyTo(dstMat);

    return 0;
}


int main()
{
    cv::Mat srcMat = imread("/Users/shuziqi/Desktop/test.png");
    cv::Mat dstMat;

    selectPolygon(srcMat, dstMat);

    imshow("srcMat", srcMat);
    imshow("select Area", dstMat);
    waitKey(0);

    return 0;
}
