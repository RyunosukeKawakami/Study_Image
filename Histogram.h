#ifndef __HISTGRAM__
#define __HISTGRAM__

#include<iostream>
#include<vector>
#include<algorithm>
#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;

class Histogram{
private:
    vector<int> hist;
    vector<vector<int>> luminance;
    Mat mono;
    Mat graph;
public:
    Histogram(const Mat&);
    void Draw();

private:
    void TrancerateGrayScale(const Mat&);
    void MakeGraph();

};

#endif