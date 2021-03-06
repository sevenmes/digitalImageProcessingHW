//
//  main.cpp
//  L8_3_findContours
//
//  Created by 舒子琪 on 2020/4/17.
//  Copyright © 2020 舒子琪. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
using std::string;


int main() {
    cv::Mat dstMat, srcMat;
    cv::Mat originalMat = cv::imread("/Users/shuziqi/Desktop/topic1.jpg",0);
    if(originalMat.empty()) return -1;
    
    resize(originalMat, srcMat, cv::Size(800, 600), (0, 0), (0, 0), cv::INTER_LINEAR);
    
    std::vector<Mat>SrcMatpart(srcMat.channels());
    split(srcMat, SrcMatpart);

    threshold(SrcMatpart[0], dstMat, 150, 255, THRESH_BINARY_INV);
    
    vector<vector<Point>>contours;
    vector<Vec4i> hierarchy;
    findContours(dstMat, contours, CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE);
    
    for (int i = 0; i < contours.size(); i++){
        RotatedRect rbox = minAreaRect(contours[i]);
        float w = rbox.size.width;
        float h = rbox.size.height;
        float n = w/h;
        if (n < 1.5 && n > 0.5 && w > 10){
            drawContours(dstMat, contours, i, Scalar(0, 255, 255),1 ,8);
            cv::Point2f vtx[4];
            rbox.points(vtx);
            for (int i = 0; i<4 ; ++i){
                line(srcMat, vtx[i], vtx[i<3 ? i+1 : 0], Scalar(0, 0, 255), 2, CV_AA);
            }
        }
    }

    imshow("result", srcMat);
    waitKey(0);
    return 0;
}
