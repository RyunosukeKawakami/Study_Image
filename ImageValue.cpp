#include "ImageValue.h"

ImageValue::ImageValue(const Mat& image){
    luminance.assign(image.rows, vector<int>(image.cols,0)); 
    average = 0;
    dispersion = 0;

    CalLuminance(image);    
    CalAverage(image);   
    CalDispersion(image); 
}

void ImageValue::CalLuminance(const Mat& image){
    for(int y = 0; y < image.rows ;y++){
        for(int x = 0; x < image.cols ;x++){
            luminance[y][x] = (int)0.114*image.at<Vec3b>(y,x)[0] + 
                             0.587*image.at<Vec3b>(y,x)[1] +
                             0.299*image.at<Vec3b>(y,x)[2];
        }
    }
}

void ImageValue::CalAverage(const Mat& image){
    for(int y = 0; y < image.rows; y++){
        for(int x = 0; x < image.cols; x++){
            average += luminance[y][x];
        }
    }
    average = average * 1 / (image.rows * image.cols);
}

void ImageValue::CalDispersion(const Mat& image){
    for(int y = 0; y < image.rows; y++){
        for(int x = 0; x < image.cols; x++){
            dispersion += pow((luminance[y][x] - average),2);
        }
    }
    dispersion = dispersion * 1 / (image.rows * image.cols);
}

void ImageValue::Draw(){
    printf("average is %f\n",average);
    printf("dispersion is %f\n",dispersion);
}