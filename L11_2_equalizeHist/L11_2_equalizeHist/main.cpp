//
//  main.cpp
//  L11_2_equalizeHist
//
//  Created by 舒子琪 on 2020/5/15.
//  Copyright © 2020 舒子琪. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;
using std::string;

int main()
{
    cv::Mat srcMat = imread("/Users/shuziqi/Desktop/etest.jpg",0);
    cv::Mat dstMat;

    //0.输入图像，类型是 8位单通道
    //1.输出图像，与输入同样尺寸同样类型
    if (srcMat.type() == CV_8UC1) {
        equalizeHist(srcMat, dstMat);
    }
    else if (srcMat.type() == CV_8UC3) {
        Mat channel[3];
        Mat out[3];
        split(srcMat, channel);

        for (int i = 0; i < 3; i++) {
            equalizeHist(channel[i], out[i]);
        }

        merge(out,3,dstMat);

    }

    imshow("srcMat", srcMat);
    imshow("dstMat", dstMat);

    waitKey(0);

    destroyAllWindows();

    return 0;

}
