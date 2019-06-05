#include<iostream>
#include<opencv2/opencv.hpp>
#include"Histogram.h"
#include"ImageValue.h"
#include"Blending.h"
#include"Filtering.h"

using namespace cv;

int main(){
/***input image***/
    Mat image = imread("../sample/jet.jpg");
    if(!image.data){
        printf("can not open image file.");
        return -1;
    }

    Filtering bibun(image);
    Mat result;
    char key = 0;

    result = bibun.Calcurate(0,-1,0,0,1,0,0,0,0);
    imshow("original",image);   
    imshow("filter",result);
    waitKey(0);

    return 0;
}