#include "TrancerateGrayscale.h"

Mat& TrancerateGrayscale::Trancerate(const Mat& image){
    result = Mat::zeros(Size(image.cols,image.rows),CV_8UC3);

    for(int y = 0; y < image.rows ;y++){
        for(int x = 0; x < image.cols ;x++){
            luminance[y][x] = (int)0.114*image.at<Vec3b>(y,x)[0] + 
                             0.587*image.at<Vec3b>(y,x)[1] +
                             0.299*image.at<Vec3b>(y,x)[2];
            result.at<Vec3b>(y,x)[0] = luminance[y][x];
            result.at<Vec3b>(y,x)[1] = luminance[y][x];
            result.at<Vec3b>(y,x)[2] = luminance[y][x];
        }
    }
    return result;
}
