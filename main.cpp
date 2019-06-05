#include<iostream>
#include<opencv2/opencv.hpp>
#include"Histogram.h"
#include"ImageValue.h"
#include"Blending.h"
#include"Filtering.h"

using namespace cv;

int main(){
/***input image***/
    Mat image = imread("../sample/lena.png");
    if(!image.data){
        printf("can not open image file.");
        return -1;
    }
    
    Filtering sorvel;
    Mat result;
    char key = 0;

    result = sorvel.Calcurate(image,0,-1,0,0,1,0,0,0,0);
    imshow("filter",result);
    imshow("original",image);   
    waitKey(0);

    return 0;
}