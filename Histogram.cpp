#include "Histogram.h"
using namespace cv;
using namespace std;

void Histogram(const Mat& image){
    vector<int> hist(256,0);
    vector<vector<int>> luminance;
    Mat mono = Mat::zeros(Size(image.cols,image.rows),CV_8UC3);
    Mat graph = Mat::zeros(Size(256,300),CV_8UC3);

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
    rectangle(graph, cv::Point(0,20), cv::Point(300,300), cv::Scalar(50,50,50), -1, CV_AA);
    for(int i = 0; i < 256; i++){
        line(graph, Point(i,20), Point(i,(hist[i]/15)+20), Scalar(255,255,255), 1, 8, 0);             
    }
    for(int y = 0; y < 20; y++){
        for(int x = 0; x < 256; x++){
            graph.at<Vec3b>(y,x)[0] = x;
            graph.at<Vec3b>(y,x)[1] = x;
            graph.at<Vec3b>(y,x)[2] = x;
        }
    }

    flip(graph,graph,0);

    imshow("graph",graph);
    //imshow("Mono",mono);
}