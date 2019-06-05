#ifndef __TRANCERATERAYSCALE__
#define __TRANCERATERAYSCALE__

#include <opencv2/opencv.hpp>
#include <cmath>
#include <vector>
using namespace cv;
using namespace std;

class TrancerateGrayscale
{
private:
    Mat result;
    vector<vector<int>> luminance;    

public:
    Mat& Trancerate(const Mat& image);
};

#endif