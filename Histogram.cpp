#include "Histogram.h"
using namespace cv;
using namespace std;

void Histogram(const Mat& image){
    vector<int> hist(256,0);
    vector<vector<int>> luminance;
    Mat mono = Mat::zeros(Size(image.cols,image.rows),CV_8UC1);
    Mat graph = Mat::zeros(Size(300,300),CV_8UC3);

/** initialize **/
    hist.assign(255,0);
    luminance.assign(image.rows, vector<int>(image.cols,0));

/** trancerate a gray-sale **/
    for(int y = 0; y < image.rows ;y++){
        for(int x = 0; x < image.cols ;x++){
            luminance[y][x] = (int)0.114*image.at<Vec3b>(y,x)[0] + 
                             0.587*image.at<Vec3b>(y,x)[1] +
                             0.299*image.at<Vec3b>(y,x)[2];
            hist[luminance[y][x]]++;
            mono.at<Vec3b>(y,x) = luminance[y][x];
        }
    }

/** make a graph **/
    for(int i = 0; i < 256; i++){
        line(graph,Point(i,0),Point(i,hist[i]/10),Scalar(255,255,255),1,8,0);
     //   line(graph,Point(255,0),Point(255,255),Scalar(255,0,0),1,3);                  
    }

    imshow("graph",graph);
    //imshow("Mono",mono);
}