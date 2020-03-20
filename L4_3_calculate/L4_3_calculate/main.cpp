//
//  main.cpp
//  L4_3_calculate
//
//  Created by 舒子琪 on 2020/3/20.
//  Copyright © 2020 舒子琪. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>
#include <stdlib.h>
using namespace cv;
using std::string;


int main() {
    cv::Mat binaryMat;
    cv::Mat labelMat;
    cv::Mat statsMat;
    cv::Mat centrMat;
    cv::Mat openMat;

    cv::Mat srcMat = imread("/Users/shuziqi/Desktop/IMG_1989.JPG",0);
    int nComps;
    threshold(srcMat, binaryMat, 100, 255, THRESH_BINARY_INV);
    
    Mat kernel = getStructuringElement(MORPH_ELLIPSE,Size(10,10));
    morphologyEx(binaryMat,openMat,MORPH_OPEN,kernel);
    
    nComps = cv::connectedComponentsWithStats (openMat,
                                               labelMat,
                                               statsMat,
                                               centrMat,
                                               8,
                                               CV_32S);

    for( int i = 1; i < nComps; i++ ) {
    
        Rect bndbox;
        bndbox.x = statsMat.at<int>(i,0);
        bndbox.y = statsMat.at<int>(i,1);
        bndbox.width = statsMat.at<int>(i,2);
        bndbox.height = statsMat.at<int>(i,3);
        rectangle(openMat, bndbox, CV_RGB(255,255,255),1,8,0);
        
    }

    std::cout << "the total of connected Components = " << nComps - 1 << std::endl;
    imshow("结果图", openMat);
    waitKey(0);
}

