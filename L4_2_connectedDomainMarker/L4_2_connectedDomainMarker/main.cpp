//
//  main.cpp
//  L4_2_connectedDomainMarker
//
//  Created by 舒子琪 on 2020/3/20.
//  Copyright © 2020 舒子琪. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>
#include <math.h>
#include <stdlib.h>
using namespace cv;
using std::string;


int main() {
    cv::Mat binaryMat;
    cv::Mat labelMat;
    cv::Mat statsMat;
    cv::Mat centrMat;

    cv::Mat srcMat = imread("/Users/shuziqi/Desktop/coin.png",0);
    int nComps;
    threshold(srcMat, binaryMat, 0, 255, THRESH_OTSU);
    
    nComps = cv::connectedComponentsWithStats (binaryMat,
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
        rectangle(binaryMat, bndbox, CV_RGB(255,255,255),1,8,0);
    }

    std::cout << "the total of connected Components = " << nComps - 1 << std::endl;
    imshow("结果图", binaryMat);
    waitKey(0);
}

