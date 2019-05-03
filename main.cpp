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

void Histogram(const Mat&);

int main(){

/***input image***/
    Mat image = imread("../lena.png");
    if(!image.data){
        printf("can not open file.");
        return -1;
    }

    Histogram(image);
    imshow("Image",image);
    waitKey(0);
    destroyAllWindows();
    return 0;
}

void Histogram(const Mat& image){
    int hist[256];
    int luminance = 0;
    Mat mono = Mat::zeros(Size(image.cols,image.rows),CV_8UC1);
    Mat graph = Mat::zeros(Size(300,300),CV_8UC1);
    for(int i = 0; i < 256; i++)
        hist[i] = 0;

    for(int y = 0; y < image.rows ;y++){
        for(int x = 0; x < image.cols ;x++){
            luminance = (int)0.114*image.at<Vec3b>(y,x)[0] + 
                             0.587*image.at<Vec3b>(y,x)[1] +
                             0.299*image.at<Vec3b>(y,x)[2];
            hist[luminance]++;
            mono.at<Vec3b>(y,x) = luminance;
            line(graph,Point(luminance,0),Point(luminance,hist[luminance]/50),Scalar(255),1,1);
           // line(graph,Point(x+1,0),Point(255,255),Scalar(0),1,1);
            
        }
    }

    imshow("graph",graph);
    imshow("Mono",mono);
}