/// \file MppShape2D.cpp
/// \brief MppShape2D class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2020

#include "MppShape2D.h"
#include <iostream>

MppShape2D::MppShape2D(){
    m_name = "MppShape2D";
    m_bounding_box = nullptr; 
    m_size = -1;
    m_contour = nullptr;
    m_fill = nullptr;
    m_silhouette = nullptr;
}

MppShape2D::~MppShape2D(){

}

int* MppShape2D::bounding_box(bool forceComputation){

    if (m_bounding_box && !forceComputation){
        return m_bounding_box;
    }
    else{
        m_bounding_box = this->computeBoundingBox();  
        return m_bounding_box;      
    }
}

int MppShape2D::size(bool forceComputation){

    if (m_size > -1 && !forceComputation){
        return m_size;
    }
    else{
        m_size = this->computeSize();  
        return m_size;      
    }
}

std::vector<MppPoint2D*>* MppShape2D::contour(bool forceComputation){

    if (m_contour && !forceComputation){
        return m_contour;
    }
    else{
        m_contour = this->computeContour();  
        return m_contour;      
    }
}

std::vector<MppPoint2D*>* MppShape2D::fill(bool forceComputation){

    if (m_fill && !forceComputation){
        return m_fill;
    }
    else{
        m_fill = this->computeFill();  
        return m_fill;      
    }
}

MppSilhouette2D* MppShape2D::silhouette(bool forceComputation){

    if (m_silhouette && !forceComputation){
        return m_silhouette;
    }
    else{
        m_silhouette = this->computeSilhouette(); 
        return m_silhouette;      
    }
}

int* MppShape2D::computeBoundingBox(){
    this->silhouette();
    return m_silhouette->bounding_box();
}

int MppShape2D::computeSize(){
    this->silhouette();
    return m_silhouette->size();
}

std::vector<MppPoint2D*>* MppShape2D::computeContour(){
    this->silhouette();
    return m_silhouette->contour();
}

std::vector<MppPoint2D*>* MppShape2D::computeFill(){
    this->silhouette();
    return m_silhouette->fill();
}
