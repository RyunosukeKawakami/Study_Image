#ifndef _BLENDING_
#define _BLENDING_

#include <opencv2/opencv.hpp>
#include <cmath>
#include <vector>
using namespace cv;
using namespace std;

class Blending{
private:
    const int rows;
    const int cols;
    Mat original[2];
    Mat average;
    Mat alpha;
    Mat emboss;
public:
    Blending(const Mat&);
    void DrawAverage();
    void DrawAlpha();
    void DrawEmboss();
};

#endif