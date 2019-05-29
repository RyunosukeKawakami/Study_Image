#include<iostream>
#include<opencv2/opencv.hpp>
#include"Histogram.h"
#include"ImageValue.h"
#include"Blending.h"

using namespace cv;

int main(){
/***input image***/
    Mat image = imread("../sample/lena.png");
    if(!image.data){
        printf("can not open image file.");
        return -1;
    }

    char key = 0;

//    Histogram hist(image);
//    ImageValue value(image);
    Blending blend(image);

    while(key != 0x1b){     //ESCキーを押すまでループ
        //hist.Draw();
        //value.Draw();
        //blend.DrawAverage();
        blend.DrawAlpha();
        //blend.DrawEmboss(image);
        //imshow("Image",image);
        key = waitKey(1);
    }
    destroyAllWindows();
    return 0;
}