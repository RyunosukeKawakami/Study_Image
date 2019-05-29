#include "Blending.h"

Blending::Blending(const Mat& image):rows(image.rows),cols(image.cols),trackbar_max(100){
    original[0] = image;
    original[1] = imread("../sample/Mandrill512.png");
    track_num = 0;
    alpha_num = 1;

    average = Mat::zeros(Size(rows,cols),CV_8UC3);
      alpha = Mat::zeros(Size(rows,cols),CV_8UC3);
     emboss = Mat::zeros(Size(rows,cols),CV_8UC3);
    
    namedWindow("alpha");
    createTrackbar("Alpha","alpha",&track_num,trackbar_max);

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

void Blending::DrawAlpha(){
    if(!(0 <= alpha_num <= 1)){
        printf("range of alpha is not correct\n");
        return;
    }
     alpha_num = (float)track_num / trackbar_max;

    for(int y = 0; y < cols; y++){
       for(int x = 0; x < rows;x++){
           alpha.at<Vec3b>(y,x)[0] = alpha_num * original[0].at<Vec3b>(y,x)[0] + (1 - alpha_num) * original[1].at<Vec3b>(y,x)[0];
           alpha.at<Vec3b>(y,x)[1] = alpha_num * original[0].at<Vec3b>(y,x)[1] + (1 - alpha_num) * original[1].at<Vec3b>(y,x)[1];
           alpha.at<Vec3b>(y,x)[2] = alpha_num * original[0].at<Vec3b>(y,x)[2] + (1 - alpha_num) * original[1].at<Vec3b>(y,x)[2];
        }   
    }
    imshow("alpha",alpha);
}

void Blending::DrawEmboss(const Mat& image){
    Mat negaposi = ~image;
    imshow("negaposi",negaposi);
}
