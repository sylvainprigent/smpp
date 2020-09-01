/// \file MppDraw2D.cpp
/// \brief MppDraw2D class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2020

#include "MppDraw2D.h"
#include "MppColor.h"

MppDraw2D::MppDraw2D(SImage2D* image){
    m_image = image;
}

SImage2D* MppDraw2D::run(std::vector<MppShape2D*>* shapes){

    // create a 3D image
    float* in_buffer = m_image->buffer();
    float* out_buffer = new float[m_image->sx()*m_image->sy()*3];
    for (int i = 0 ; i < m_image->sx()*m_image->sy() ; i++){
        out_buffer[3*i+0] = in_buffer[i]; 
        out_buffer[3*i+1] = in_buffer[i]; 
        out_buffer[3*i+2] = in_buffer[i];    
    }
    int pos;
    for (int s = 0 ; s < shapes->size() ; s++){
        std::vector<MppPoint2D*>* coords = (*shapes)[s]->contour();
        std::vector<int> color = MppColor::rand_rgb();
        for (int c = 0 ; c < coords->size() ; c++){
            pos = m_image->sy()*(*coords)[c]->x()+(*coords)[c]->y();
            out_buffer[3*pos+0] = color[0];
            out_buffer[3*pos+2] = color[1];
            out_buffer[3*pos+2] = color[2];
        }
    }
    SImage2D* out_image = new SImage2D(out_buffer, m_image->sx(), m_image->sy());
    out_image->set_color(true);
    return out_image;
}
