/// \file MppDataTerm2D.cpp
/// \brief MppDataTerm2D class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2020

#include "MppDataTerm2D.h"


MppDataTerm2D::MppDataTerm2D(){
    m_image = nullptr;
}

MppDataTerm2D::MppDataTerm2D(SImage2D* image){
    m_image = image;
}

MppDataTerm2D::~MppDataTerm2D(){

}

void MppDataTerm2D::set_image(SImage2D* image){
    m_image = image;
}