/// \file MppColor.cpp
/// \brief MppColor class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2020

#include <MppColor.h>
#include <stdlib.h>
#include <iostream>
#include "MppRand.h"

using namespace std;

vector<int> MppColor::rand_rgb(){
    float golden_ratio_conjugate = float(0.618033988749895);
    float h = MppRandPM::rand();
    h += golden_ratio_conjugate;
    if (h>=1){
        h-=1;
    }
    return hsv_to_rgb(h, float(0.95), float(0.95));
}

vector<int> MppColor::hsv_to_rgb(float h, float s, float v){
    vector<float> rgb; rgb.resize(3);

    int h_i = int(h*6);
    float f = h*6 - h_i;
    float p = v * (1 - s);
    float q = v * (1 - f*s);
    float t = v * (1 - (1 - f) * s);
    if (h_i==0){
        rgb[0] = v;
        rgb[1] = t;
        rgb[2] = p;
    }
    if (h_i==1){
        rgb[0] = q;
        rgb[1] = v;
        rgb[2] = p;
    }
    if (h_i==2){
        rgb[0] = p;
        rgb[1] = v;
        rgb[2] = t;
    }
    if (h_i==3){
        rgb[0] = p;
        rgb[1] = q;
        rgb[2] = v;
    }
    if (h_i==4){
        rgb[0] = t;
        rgb[1] = p;
        rgb[2] = v;
    }
    if (h_i==5){
        rgb[0] = v;
        rgb[1] = p;
        rgb[2] = q;
    }

    vector<int> rgb256; rgb256.resize(3);
    rgb256[0] = int(256*rgb[0]);
    rgb256[1] = int(256*rgb[1]);
    rgb256[2] = int(256*rgb[2]);
    return rgb256;
}
