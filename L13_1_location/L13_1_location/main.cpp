//
//  main.cpp
//  L13_1_location
//
//  Created by 舒子琪 on 2020/5/29.
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


int main()
{
    Mat srcMat = imread("/Users/shuziqi/Desktop/template.png");
    Mat img = imread("/Users/shuziqi/Desktop/img.png");

    float dis1 = 0;
    float dis = 0;
    float *hist;
    float *hist1;

    Rect rect;
    hist = hog(srcMat);
    
    int row = srcMat.rows;
    int col = srcMat.cols;
    int row1 = img.rows;
    int col1 = img.cols;

    for(int i=0; i<col1-col; i++)
    {
        for(int j=0; j < row1 - row; j++)
        {
            Mat ROI = img(Rect(i, j, col, row));
            hist1 = hog(ROI);
            
            //float distance(Mat& srcMat, Mat& img)
            //{
            //    int cellSize = 16;
            //    int nX = srcMat.cols / cellSize;
            //    int nY = srcMat.rows / cellSize;
            //    int cellnum = nX * nY;
            //    int bins = cellnum * 8;
            //
            //    float a;
            //    float d1 = 0;
            //    float dis;
            //
            //    for (int i = 0; i < bins; i++)
            //    {
            //        a = hog(srcMat)[i] - hog(img)[i];
            //        d1 += a * a;
            //    }
            //    dis = sqrt(d1);
            //
            //    return dis;
            //}

            for(int n = 0; n < 16; n++)
            {
                dis1 += (hist[n] - hist1[n]) * (hist[n] - hist1[n]);
            }
            dis1 = sqrt(dis1);

            if(i == 0 & j == 0)
            {
                dis = dis1;
            }

            if(dis1 < dis)
            {
                dis = dis1;
                rect = Rect(i, j, col, row);
            }

        }
    }


    rectangle(img, rect, CV_RGB(255,0,0), 1, 8, 0);
    imshow("result", img);
    waitKey(0);
    
    return 0;
}
