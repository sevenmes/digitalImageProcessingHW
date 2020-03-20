//
//  main.cpp
//  L4_1_imageMorphology
//
//  Created by 舒子琪 on 2020/3/20.
//  Copyright © 2020 舒子琪. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using std::string;


int main() {
    cv::Mat binaryMat;
    cv::Mat erodeMat;
    cv::Mat dilateMat;
    cv::Mat openMat;
    cv::Mat closeMat;
    cv::Mat srcMat = imread("/Users/shuziqi/Desktop/coin.png",0);
    
    threshold(srcMat, binaryMat, 100, 255, THRESH_BINARY);
    
    Mat kernel = getStructuringElement(MORPH_RECT,Size(3,3));
    erode(binaryMat, erodeMat, kernel);
    dilate(binaryMat, dilateMat, kernel);
    morphologyEx(binaryMat,openMat,MORPH_OPEN,kernel);
    morphologyEx(binaryMat,closeMat,MORPH_CLOSE,kernel);
    
    imshow("腐蚀", erodeMat);
    waitKey(0);
    imshow("膨胀", dilateMat);
    waitKey(0);
    imshow("开运算", openMat);
    waitKey(0);
    imshow("闭运算", closeMat);
    waitKey(0);
    
    return 0;
}
