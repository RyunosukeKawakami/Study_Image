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
    const int trackbar_max;
    float alpha_num;
    int track_num;
    Mat original[2];
    Mat average;
    Mat alpha;
    Mat emboss;
    Mat mono;

public:
    Blending(const Mat&);
    void DrawAverage();
    void DrawAlpha();
    void DrawEmboss(const Mat&);

private:
    void onTrackbarChanged(int, void*);
};

#endif