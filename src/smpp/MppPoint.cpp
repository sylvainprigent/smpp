/// \file MppPoint.cpp
/// \brief MppPoint class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2020

#include "MppPoint.h"

MppPoint::MppPoint(){

}

MppPoint::~MppPoint(){

}

MppPoint2D::MppPoint2D() : MppPoint(){

}
MppPoint2D::MppPoint2D(const int& x, const int& y) : MppPoint(){
    m_x = x;
    m_y = y;
}

MppPoint2D::~MppPoint2D(){

}

void MppPoint2D::setX(const int& x){
    m_x = x;
}

void MppPoint2D::setY(const int& y){
    m_y = y;
}

int MppPoint2D::x(){
    return m_x;
}

int MppPoint2D::y(){
    return m_y;
}  

MppPoint3D::MppPoint3D() : MppPoint(){

}

MppPoint3D::MppPoint3D(const int& x, const int& y, const int& z): MppPoint(){
    m_x = x;
    m_y = y;
    m_z = z;
}

MppPoint3D::~MppPoint3D(){

}

void MppPoint3D::setX(const int& x){
    m_x = x;
}

void MppPoint3D::setY(const int& y){
    m_y = y;
}

void MppPoint3D::setZ(const int& z){
    m_z = z;
}

int MppPoint3D::x(){
    return m_x;
}

int MppPoint3D::y(){
    return m_y;
}

int MppPoint3D::z(){
    return m_z;
}
