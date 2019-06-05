#include "Filtering.h"

Filtering::Filtering(const Mat& image){
    result = Mat::zeros(Size(image.cols,image.rows),CV_8UC3);
    mono = Mat::zeros(Size(image.cols,image.rows),CV_8UC3);
    mono = grayscale.Trancerate(image);
}

Mat& Filtering::Calcurate(int al,int am, int ar,
            int ml,int mm,int mr,int ul, int um, int ur){

                printf("%d\n",mono.rows);
                printf("%d\n",mono.cols);
    for(int color = 0; color < 3; color++){
        for(int y = 0; y < result.rows; y++){
            for(int x = 0; x < result.cols; x++){
                SetTerm(x,y);
                if(color == 0 && y == 0 && x == 0) TestTerm();
                if(color == 0 && y == 0 && x == result.cols - 1) TestTerm();
                if(color == 0 && y == result.rows - 1&& x == 0) TestTerm();
                if(color == 0 && y == result.rows - 1 && x == result.cols - 1) TestTerm();

                if(term[0][0])  filter[color][0][0] = (int) al * mono.at<Vec3b>(y-1,x-1)[color];
                else            filter[color][0][0] = 0;
                if(term[0][1])  filter[color][0][1] = (int) am * mono.at<Vec3b>(y-1,x)[color];
                else            filter[color][0][1] = 0;
                if(term[0][2])  filter[color][0][2] = (int) ar * mono.at<Vec3b>(y-1,x+1)[color];
                else            filter[color][0][2] = 0;

                if(term[1][0])  filter[color][1][0] = (int) ml * mono.at<Vec3b>(y,x-1)[color];
                else            filter[color][1][0] = 0;
                if(term[1][1])  filter[color][1][1] = (int) mm * mono.at<Vec3b>(y,x)[color];
                else            filter[color][1][1] = 0;
                if(term[1][2])  filter[color][1][2] = (int) mr * mono.at<Vec3b>(y,x+1)[color];
                else            filter[color][1][2] = 0;

                if(term[2][0])  filter[color][2][0] = (int) ul * mono.at<Vec3b>(y+1,x-1)[color];
                else            filter[color][2][0] = 0;
                if(term[2][1])  filter[color][2][1] = (int) um * mono.at<Vec3b>(y+1,x)[color];
                else            filter[color][2][1] = 0;
                if(term[2][2])  filter[color][2][2] = (int) ur * mono.at<Vec3b>(y+1,x+1)[color];
                else            filter[color][2][2] = 0;

                result.at<Vec3b>(y,x)[color] = Addfilter(color);
            }
        }
    }
    return result;
}

void Filtering::TestTerm(){
    printf("%d  %d  %d\n",term[0][0],term[0][1],term[0][2]);
    printf("%d  %d  %d\n",term[1][0],term[1][1],term[1][2]);
    printf("%d  %d  %d\n\n",term[2][0],term[2][1],term[2][2]);
}

void Filtering::SetTerm(int x, int y){
    term[0][0] = y-1 >= 0 && x-1 >= 0;
    term[0][1] = y-1 >= 0;
    term[0][2] = y-1 >= 0 && x+1 <= mono.cols-1;
    term[1][0] = x-1 >= 0;
    term[1][1] = true;
    term[1][2] = x+1 <= mono.cols-1;
    term[2][0] = y+1 <= mono.rows-1 && x-1 >= 0; 
    term[2][1] = y+1 <= mono.rows-1;
    term[2][2] = y+1 <= mono.rows-1 && x+1 <= mono.cols-1; 
}

float Filtering::Addfilter(int color)
{
    float result = 0;
    for(int y = 0; y < 3; y++){
        for(int x =0; x < 3; x++){
            result += filter[color][y][x];
        }
    }
    return result;
}