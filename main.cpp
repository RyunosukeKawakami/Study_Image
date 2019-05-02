#include<iostream>
#include<opencv2/opencv.hpp>

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

Mat Histogram(Mat*);

int main(){

//input image
    Mat image = imread("../lena.png");
    if(!image.data){
        printf("can not open file.");
        return -1;
    }
    Mat mono;
    cvtColor(image,mono,COLOR_BGR2GRAY);

  //  Histogram(&image);
    imshow("Image",image);
    imshow("GrayColor",mono);
    waitKey(0);
    return 0;
}

Mat Histogram(Mat* image){
    int r[256],g[256],b[256];
    for(int i = 0;  i < 256; i++){
        r[i] = 0;
        g[i] = 0;
        b[i] = 0;
    }
    
    for(int y = 0; y < image->rows ;y++){
        for(int y = 0; y < image->rows ;y++){
            
        }
    }

}