#include "Blending.h"

Blending::Blending(const Mat& image):rows(image.rows),cols(image.cols){
    original[0] = image;
    original[1] = imread("../sample/Mandrill512.png");

    average = Mat::zeros(Size(rows,cols),CV_8UC3);
      alpha = Mat::zeros(Size(rows,cols),CV_8UC3);
     emboss = Mat::zeros(Size(rows,cols),CV_8UC3);
}

void Blending::DrawAverage(){
    for(int y = 0; y < cols; y++){
       for(int x = 0; x < rows;x++){
           average.at<Vec3b>(y,x)[0] = (original[0].at<Vec3b>(y,x)[0] + original[1].at<Vec3b>(y,x)[0])/2;
           average.at<Vec3b>(y,x)[1] = (original[0].at<Vec3b>(y,x)[1] + original[1].at<Vec3b>(y,x)[1])/2;
           average.at<Vec3b>(y,x)[2] = (original[0].at<Vec3b>(y,x)[2] + original[1].at<Vec3b>(y,x)[2])/2;
        }   
    }
    imshow("ave",average);
}

void Blending::DrawAlpha(float a){
    if(!(0 <= a <= 1)){
        printf("range of alpha is not correct\n");
        return;
    }

    for(int y = 0; y < cols; y++){
       for(int x = 0; x < rows;x++){
           alpha.at<Vec3b>(y,x)[0] = a * original[0].at<Vec3b>(y,x)[0] + (1 - a) * original[1].at<Vec3b>(y,x)[0];
           alpha.at<Vec3b>(y,x)[1] = a * original[0].at<Vec3b>(y,x)[1] + (1 - a) * original[1].at<Vec3b>(y,x)[1];
           alpha.at<Vec3b>(y,x)[2] = a * original[0].at<Vec3b>(y,x)[2] + (1 - a) * original[1].at<Vec3b>(y,x)[2];
        }   
    }
    imshow("alpha",alpha);
}

void Blending::DrawEmboss(){

}
