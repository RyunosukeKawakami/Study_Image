#include "Filtering.h"

Filtering::Filtering(){

}

Mat& Filtering::Calcurate(const Mat& image, int al,int am, int ar,
            int ml,int mm,int mr,int ul, int um, int ur){
    result = Mat::zeros(Size(image.cols,image.rows),CV_8UC3);
    for(int color = 0; color < 3; color++){
        for(int y = 0; y < image.cols; y++){
            for(int x = 0; x < image.rows; x++){
                if(y-1 >= 0 && x-1 >= 0) filter[color][0][0] = al * image.at<Vec3b>(y-1,x-1)[color];
                else                     filter[color][0][0] = 0;
                if(y-1 >= 0 && x >= 0)   filter[color][0][1] = am * image.at<Vec3b>(y-1,x)[color];
                else                     filter[color][0][1] = 0;
                if(y >= 0 && x-1 >= 0)   filter[color][1][0] = mr * image.at<Vec3b>(y,x-1)[color];
                else                     filter[color][1][0] = 0;

                if(y >= 0 && x >= 0)     filter[color][1][1] = mr * image.at<Vec3b>(y,x)[color];
                else                     filter[color][1][1] = 0;
                if(y+1 >= 0 && x-1 >= 0) filter[color][2][0] = ul * image.at<Vec3b>(y+1,x-1)[color];
                else                     filter[color][2][0] = 0;
                if(y+1 >= 0 && x >= 0)   filter[color][2][1] = um * image.at<Vec3b>(y+1,x)[color];
                else                     filter[color][2][1] = 0;

                if(y-1 >= 0 && x+1 <= image.rows) filter[color][0][2] = ar * image.at<Vec3b>(y-1,x+1)[color];
                else                     filter[color][0][2] = 0;
                if(y >= 0 && x+1 <= image.cols)   filter[color][1][2] = mr * image.at<Vec3b>(y,x+1)[color];
                else                     filter[color][1][2] = 0;
                if(y+1 <= image.rows && x+1 >= image.cols) filter[color][2][2] = ur * image.at<Vec3b>(y+1,x+1)[color];
                else                     filter[color][2][2] = 0;

                result.at<Vec3b>(x,y)[color] = Addfilter(color);
            }
        }
    }
    return result;
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