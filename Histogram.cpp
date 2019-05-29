#include "Histogram.h"

Histogram::Histogram(const Mat& image){
    mono = Mat::zeros(Size(image.cols,image.rows),CV_8UC3);
    graph = Mat::zeros(Size(256,300),CV_8UC3);

    hist.assign(255,0);
    luminance.assign(image.rows, vector<int>(image.cols,0));

    TrancerateGrayScale(image);
    MakeGraph();
}

void Histogram::TrancerateGrayScale(const Mat& image){
    for(int y = 0; y < image.rows ;y++){
        for(int x = 0; x < image.cols ;x++){
            luminance[y][x] = (int)0.114*image.at<Vec3b>(y,x)[0] + 
                             0.587*image.at<Vec3b>(y,x)[1] +
                             0.299*image.at<Vec3b>(y,x)[2];
            hist[luminance[y][x]]++;
            mono.at<Vec3b>(y,x)[0] = luminance[y][x];
            mono.at<Vec3b>(y,x)[1] = luminance[y][x];
            mono.at<Vec3b>(y,x)[2] = luminance[y][x];
        }
    }
}

void Histogram::MakeGraph(){
    rectangle(graph, Point(0,20), Point(300,300), Scalar(50,50,50), -1, CV_AA);
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
}

void Histogram::Draw(){
    imshow("graph",graph);
    imshow("Mono",mono);
    moveWindow("graph",100,50);
    moveWindow("Mono",100,400);
}