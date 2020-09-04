/// \file MppDataTerm2DGradient.cpp
/// \brief MppDataTerm2DGradient class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2020

#include "math.h"
#include "MppDataTerm2DGradient.h"

#include <iostream>

MppDataTerm2DGradient::MppDataTerm2DGradient(float threshold) : MppDataTerm2D(threshold){
    m_D = 100.0;
    m_grad_image_x = nullptr;
    m_grad_image_y = nullptr;
}

MppDataTerm2DGradient::MppDataTerm2DGradient(MppImageFloat* image, float threshold) : MppDataTerm2D(image, threshold){
    m_D = 100.0; 
    m_grad_image_x = nullptr;
    m_grad_image_y = nullptr;   
}

MppDataTerm2DGradient::~MppDataTerm2DGradient(){
    delete[] m_grad_image_x;
    delete[] m_grad_image_y;
}

void MppDataTerm2DGradient::set_D(float value){
    m_D = value;   
}

void MppDataTerm2DGradient::init(){

    unsigned int sx = m_image->sx();
    unsigned int sy = m_image->sy();
    m_grad_image_x = new float[sx*sy];
    m_grad_image_y = new float[sx*sy];

    // border conditions
    for (int x = 0 ; x < sx ; x++){
        m_grad_image_x[sy*x+0] = 0;
        m_grad_image_x[sy*x+sy-1] = 0;
        m_grad_image_y[sy*x+0] = 0;
        m_grad_image_y[sy*x+sy-1] = 0;
    }
    for (int y = 0 ; y < sy ; y++){
        m_grad_image_x[y] = 0;
        m_grad_image_x[sy*(sx-1)+y] = 0;
        m_grad_image_y[y] = 0;
        m_grad_image_y[sy*(sx-1)+y] = 0;
    }

    // gradient
    float *image_buffer = m_image->buffer();
    for (int x = 1 ; x < sx-1 ; x++){
        for (int y = 1 ; y < sy-1 ; y++){
            m_grad_image_x[sy*x+y] = pow(image_buffer[sy*(x+1)+y] - image_buffer[sy*(x-1)+y],2);
            m_grad_image_y[sy*x+y] = pow(image_buffer[sy*x+y+1] - image_buffer[sy*x+y-1],2);
        }
    }
}

float MppDataTerm2DGradient::run(MppShape2D* shape, int x, int y){

    //std::cout << "calculate dataterm:" << x << ", " << y << std::endl;

    int* box = shape->bounding_box();
    if (box[0] - 1 + x < 1){
        return 1;
    }
    if (x + box[1] + 1 >= m_image->sx()-1){
        return 1;
    }
    if (box[2] - 1 + y < 1){
        return 1;
    }
    if (y + box[3] + 1 >= m_image->sy()-1){
        return 1;
    }

    // calculate gradient
    std::vector<MppPoint2D*>* contour = shape->contour();
    std::vector<MppPoint2D*>* normals = shape->normals();
    int sy = m_image->sy();
    float U = 0;
    float grad_x, grad_y;
    float nx, ny;
    int xt, yt;
    for (int p = 0 ; p < contour->size() ; ++p){
        xt = (*contour)[p]->x() + x;
        yt = (*contour)[p]->y() + y;

        // get gradient
        grad_x = m_grad_image_x[sy*xt+yt];
        grad_y = m_grad_image_y[sy*xt+yt];

        // project gradient
        nx = (*normals)[p]->x();
        ny = (*normals)[p]->y();
        //std::cout << "nx = " << nx << "ny = " << ny << std::endl;
        float val = nx*grad_x + ny*grad_y;

        U += val;
    }
    U /= contour->size();

    // threshold
    if (U < m_threshold){
        return (1- U/m_threshold);
    }
    else{
        return exp(-(U - m_threshold)/m_D)-1;
    }
}