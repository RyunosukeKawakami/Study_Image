#include "Blending.h"

Blending::Blending(const Mat& image){
    original[0] = image;
    original[1] = imread("../sample/Mandrill.png");

    DrawAverage();
    DrawAlpha();
    DrawEmboss();
}

void Blending::DrawAverage(){
    for(int y = 0; y < original[0]; y++){
        for(int x = 0; x < original[0].rows;x++){
            
        }   
    }

}