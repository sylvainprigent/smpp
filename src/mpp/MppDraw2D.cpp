/// \file MppDraw2D.cpp
/// \brief MppDraw2D class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2020

#include <float.h>

#include "MppDraw2D.h"
#include "MppColor.h"

#include <iostream>

MppDraw2D::MppDraw2D(MppImageFloat* image){
    m_image = image;
}

MppImageChar* MppDraw2D::run(const std::vector<MppShape2D*>& shapes){

    std::cout << "draw shapes starts" << std::endl;
    // create a 3D image
    float* in_buffer = m_image->buffer();
    char* out_buffer = new char[m_image->sx()*m_image->sy()*3];
    float min = FLT_MAX;
    float max = -FLT_MAX;
    for (int i = 0 ; i < m_image->sx()*m_image->sy() ; i++){
        if (in_buffer[i] < min){
            min = in_buffer[i];
        }
        if (in_buffer[i] > max){
            max = in_buffer[i];
        }
    }   
    char val;
    for (int i = 0 ; i < m_image->sx()*m_image->sy() ; i++){
        val = char( 255*(in_buffer[i] - min) / (max-min) );
        out_buffer[3*i+0] = val; 
        out_buffer[3*i+1] = val; 
        out_buffer[3*i+2] = val;    
    }
    std::cout << "draw shapes loop" << std::endl;
    int pos;
    for (int s = 0 ; s < shapes.size() ; s++){
        std::vector<MppPoint2D*>* coords = shapes[s]->contour();
        std::vector<int> color = MppColor::rand_rgb();
        for (int c = 0 ; c < coords->size() ; c++){
            pos = m_image->sy()*(*coords)[c]->x()+(*coords)[c]->y();
            out_buffer[3*pos+0] = color[0];
            out_buffer[3*pos+1] = color[1];
            out_buffer[3*pos+2] = color[2];
        }
    }
    MppImageChar* out_image = new MppImageChar(out_buffer, m_image->sx(), m_image->sy(), 1, 1, 3);
    std::cout << "draw shapes end" << std::endl;
    return out_image;
}
