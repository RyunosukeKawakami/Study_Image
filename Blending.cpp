#include "Blending.h"

Blending::Blending(const Mat& image):rows(image.rows),cols(image.cols){
    original[0] = image;
    original[1] = imread("../sample/Mandrill512.png");

    average = Mat::zeros(Size(rows,cols),CV_8UC3);
      alpha = Mat::zeros(Size(rows,cols),CV_8UC3);
     emboss = Mat::zeros(Size(rows,cols),CV_8UC3);

    DrawAverage();
//    DrawAlpha();
 //   DrawEmboss();
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

