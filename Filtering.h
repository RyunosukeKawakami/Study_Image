#ifndef _FILTERING_
#define _FILTERING_

#include <opencv2/opencv.hpp>
#include <cmath>
#include <vector>
using namespace cv;
using namespace std;

class Filtering{
private:
    //first　array is color(e.g. Blue Green Red)
    //second and therd array are cols and rows.
    float filter[3][3][3];
    Mat result;
public:
    Filtering();
    Mat& Calcurate(const Mat& ,int ,int ,int, 
            int ,int ,int ,int ,int ,int);

private:
    float Addfilter(int color);
};

#endif