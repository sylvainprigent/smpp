/// \file SImage2D.cpp
/// \brief SImage2D class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2020

#include "SImage2D.h"

SImage2D::SImage2D(){
    m_buffer = 0;
    m_sx = 0;
    m_sy = 0;
    m_is_color = false;
}

SImage2D::SImage2D(float* buffer, unsigned int sx, unsigned int sy){
    m_buffer = buffer;
    m_sx = sx;
    m_sy = sy;
    m_is_color = false;
}

void SImage2D::set_sx(const unsigned int & value){
    m_sx = value;
}
void SImage2D::set_sy(const unsigned int & value){
    m_sy = value;
}

void SImage2D::set_buffer(float* buffer){
    m_buffer = buffer;
}

void SImage2D::set_color(bool value){
    m_is_color = true;
}

unsigned int SImage2D::sx(){
    return m_sx;
}

unsigned int SImage2D::sy(){
    return m_sy;
}

float* SImage2D::buffer(){
    return m_buffer;
}

bool SImage2D::is_color(){
    return m_is_color;
}