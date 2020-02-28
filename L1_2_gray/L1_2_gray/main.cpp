//
//  main.cpp
//  L1_2_gray
//
//  Created by 舒子琪 on 2020/2/28.
//  Copyright © 2020 舒子琪. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using std::string;


int main() {
    
    cv::Mat srcMat = imread("/Users/shuziqi/Desktop/test.jpg",0);
    
    imshow("src", srcMat);
    
    waitKey(0);
    
    return 0;
}
