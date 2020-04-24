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

float *hog(Mat srcMat)
{
    int cellSize = 16;
    int nX = srcMat.cols / cellSize;
    int nY = srcMat.rows / cellSize;
    
    int cellnums = nX * nY;
    int bins = cellnums * 8;
    int binnumber = 0;
    
    float* ref_hist = new float[bins];
    memset(ref_hist, 0, sizeof(float) * bins);
    
    for(int i = 0; i < nX; ++i)
    {
        for(int j = 0; j < nY; ++j)
        {
            //计算梯度及角度
            Mat gx, gy;
            Mat mag, angle;
            
            Sobel(srcMat, gx, CV_32F, 1, 0, 1);
            Sobel(srcMat, gy, CV_32F, 0, 1, 1);
            
            cartToPolar(gx, gy, mag, angle, true);
            
            for (int a = j * cellSize; a < (j + 1)*cellSize; a++)
            {
                for (int b = i * cellSize; b < (i + 1)*cellSize; b++)
                {
                    int n = angle.at<float>(a, b) / 45;
                    float m = mag.at<float>(a, b);
                    ref_hist[n + binnumber * 8] += m;
                }
            }
            binnumber++;
        }
    }
    return ref_hist;
}

int main() {
    cv::Mat srcMat = cv::imread("/Users/shuziqi/Desktop/hogTemplate.jpg");
    cv::Mat img1 = cv::imread("/Users/shuziqi/Desktop/img1");
    cv::Mat img2 = cv::imread("/Users/shuziqi/Desktop/img2");

    int cellSize = 16;
    int nX = srcMat.cols / cellSize;
    int nY = srcMat.rows / cellSize;
    
    int cellnums = nX * nY;
    int bins = cellnums * 8;
    
    double n, m, dis1, dis2;
    double d1 = 0, d2 = 0;
    
    for (int i = 0; i < bins; i++)
    {
        n = (hog(srcMat)[i] - hog(img1)[i]);
        m = (hog(srcMat)[i] - hog(img2)[i]);
        d1 += n * n;
        d2 += m * m;
    }
    dis1 = sqrt(d1);
    dis2 = sqrt(d2);
    
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
