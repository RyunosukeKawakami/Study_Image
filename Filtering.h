#ifndef _FILTERING_
#define _FILTERING_

#include <opencv2/opencv.hpp>
#include <cmath>
#include <vector>
#include "TrancerateGrayscale.h"
using namespace cv;
using namespace std;

class Filtering{
private:
    //first　array is color(e.g. Blue Green Red)
    //second and therd array are cols and rows.
    int filter[3][3][3];
    bool term[3][3];
    Mat result;
    Mat mono;
    TrancerateGrayscale grayscale;
public:
    Filtering(const Mat&);
    Mat& Calcurate(int ,int ,int, int ,int ,int ,int ,int ,int);

private:
    float Addfilter(int color);
     void SetTerm(int x,int y);
     void TestTerm();
};

#endif