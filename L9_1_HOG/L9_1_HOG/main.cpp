//
//  main.cpp
//  L9_1_HOG
//
//  Created by 舒子琪 on 2020/4/24.
//  Copyright © 2020 舒子琪. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>
#include <math.h>
using namespace cv;
using namespace std;
using std::string;

float *hog(Mat srcMat) {
    int cellSize = 16;
    int nX = srcMat.cols / cellSize;
    int nY = srcMat.rows / cellSize;
    
    int cellnum = nX * nY;
    int bins = cellnum * 8;
    int binnum = 0;
    
    float* ref_hist = new float[bins];
    memset(ref_hist, 0, sizeof(float) * bins);

    //计算梯度及角度
    Mat gx, gy;
    Mat mag, angle;

    Sobel(srcMat, gx, CV_32F, 1, 0, 1);
    Sobel(srcMat, gy, CV_32F, 0, 1, 1);
    
    cartToPolar(gx, gy, mag, angle, true);

    for (int i = 0; i < nX; i++){
        for (int j = 0; j < nY; j++) {
            
            for (int a = j * cellSize; a < (j + 1)*cellSize; a++) {
                for (int b = i * cellSize; b < (i + 1)*cellSize; b++) {
                    int n = angle.at<float>(a, b) / 45;
                    float m = mag.at<float>(a, b);
                    ref_hist[n + binnum * 8] += m;
                }
                }
            binnum++;
            
            }
        }
    return ref_hist;
}

float distance(Mat& srcMat, Mat& img)
{
    int cellSize = 16;
    int nX = srcMat.cols / cellSize;
    int nY = srcMat.rows / cellSize;
    int cellnum = nX * nY;
    int bins = cellnum * 8;

    float a;
    float d1 = 0;
    float dis;
    
    for (int i = 0; i < bins; i++)
    {
        a = hog(srcMat)[i] - hog(img)[i];
        d1 += a * a;
    }
    dis = sqrt(d1);

    return dis;
}

int main() {
    Mat srcMat = imread("/Users/shuziqi/Desktop/hogTemplate.jpg");
    Mat img1 = imread("/Users/shuziqi/Desktop/img1.jpg");
    Mat img2 = imread("/Users/shuziqi/Desktop/img2.jpg");
    
    float dis1, dis2;
    dis1 = distance(srcMat, img1);
    dis2 = distance(srcMat, img2);
    
    cout << dis1 << endl;
    cout << dis2 << endl;
    
    if (dis1 < dis2)
    {
        cout << "img1" << endl;
    }
    else
        cout << "img2" << endl;

    return 0;
}
