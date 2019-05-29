#ifndef _SHOWVALUE_
#define _SHOWVALUE_

#include <opencv2/opencv.hpp>
#include <cmath>
#include <vector>
using namespace cv;
using namespace std;

class ImageValue{
private:
    vector<vector<int>> luminance;
    float average;
    float dispersion;
    Mat mono;
public:
    ImageValue(const Mat& image);
    void Draw();
    
private:
    void CalLuminance(const Mat& image);
    void CalAverage(const Mat& image);
    void CalDispersion(const Mat& image);
    
};

#endif