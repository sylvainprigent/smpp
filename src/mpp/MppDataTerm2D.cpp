/// \file MppDataTerm2D.cpp
/// \brief MppDataTerm2D class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2020

#include "MppDataTerm2D.h"


MppDataTerm2D::MppDataTerm2D(float threshold){
    m_image = nullptr;
    m_threshold = threshold;
}

MppDataTerm2D::MppDataTerm2D(SImage2D* image, float threshold){
    m_image = image;
    m_threshold = threshold;
}

MppDataTerm2D::~MppDataTerm2D(){

}

SImage2D* MppDataTerm2D::image(){
    return m_image;
}

void MppDataTerm2D::set_image(SImage2D* image){
    m_image = image;
}