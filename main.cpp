#include<iostream>
#include<opencv2/opencv.hpp>
#include"Histogram.h"

#ifdef _DEBUG
    #pragma comment(lib."opencv_core243d.lib")
    #pragma comment(lib."opencv_highgui243d.lib")
    #pragma comment(lib."opencv_objdetect243d.lib")
#else
    #pragma comment(lib."opencv_core243.lib")
    #pragma comment(lib."opencv_highgui243.lib")
    #pragma comment(lib."opencv_objdetect243.lib")
#endif

using namespace cv;

int main(){
/***input image***/
    Mat image = imread("../lena.png");
    if(!image.data){
        printf("can not open file.");
        return -1;
    }

    Histogram(image);
    //imshow("Image",image);
    waitKey(0);
    destroyAllWindows();
    return 0;
}