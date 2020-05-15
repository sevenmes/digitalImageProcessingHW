//
//  main.cpp
//  L11_3_yincangshuiyin
//
//  Created by 舒子琪 on 2020/5/15.
//  Copyright © 2020 舒子琪. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;
using std::string;

int gammaCorrection(Mat srcMat, Mat & dstMat, float gamma)
{
    if (srcMat.channels()!=1)return -1;
    //建立查询表
    unsigned char lut[256];
    for (int i = 0; i < 256; i++)
    {
        lut[i] = saturate_cast<uchar>(pow((float)(i / 255.0), gamma) * 255.0f);
    }

    srcMat.copyTo(dstMat);

    MatIterator_<uchar> it, end;
    for (it = dstMat.begin<uchar>(), end = dstMat.end<uchar>(); it != end; it++) {
        *it = lut[(*it)];
    }
    return 0;
}


int main()
{
    cv::Mat srcMat = imread("/Users/shuziqi/Desktop/gtest.jpg", 0);
    cv::Mat dstMat;
    float gamma = 0.3;
    gammaCorrection(srcMat,dstMat,gamma);

    imshow("src",srcMat);
    imshow("dst",dstMat);
    waitKey(0);
    destroyAllWindows();
    return 0;
}

