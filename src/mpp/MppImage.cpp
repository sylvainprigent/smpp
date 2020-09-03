/// \file MppImage.h
/// \brief MppImage class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2020


#include "MppImage.h"

MppImage::MppImage(){
    m_sx = 0;
    m_sy = 0;
    m_sz = 0;
    m_st = 0;
    m_sc = 0;
    m_rx = 0; 
    m_ry = 1; 
    m_rz = 1; 
    m_rt = 1; 
    m_unit = "pixel";
    m_precision = 8; 
}

MppImage::~MppImage(){
    
}

void MppImage::set_sx(unsigned int value){
    m_sx = value;
}

void MppImage::set_sy(unsigned int value){
    m_sy = value;
}

void MppImage::set_sz(unsigned int value){
    m_sz = value;
}

void MppImage::set_st(unsigned int value){
    m_st = value;
}

void MppImage::set_sc(unsigned int value){
    m_sc = value;
}

unsigned int MppImage::sx(){
    return m_sx;
}

unsigned int MppImage::sy(){
    return m_sy;
}

unsigned int MppImage::sz(){
    return m_sz;
}

unsigned int MppImage::st(){
    return m_st;
}

unsigned int MppImage::sc(){
    return m_sc;
}

float MppImage::rx(){
    return m_rx;
}

float MppImage::ry(){
    return m_ry;
}

float MppImage::rz(){
    return m_rz;
}

float MppImage::rt(){
    return m_rt;    
}

std::string MppImage::unit(){
    return m_unit;
}

char MppImage::precision(){
    return m_precision;
}
void MppImage::set_res(float rx, float ry, float rz, float rt){
    m_rx = rx;
    m_ry = ry;
    m_rz = rz;
    m_rt = rt;
}

void MppImage::set_rx(float value){
    m_rx = value;
}

void MppImage::set_ry(float value){
    m_ry = value;
}

void MppImage::set_rz(float value){
    m_rz = value;
}

void MppImage::set_rt(float value){
    m_rt = value;
}

void MppImage::set_unit(std::string value){
    m_unit = value;
}


MppImageUInt::MppImageUInt() : MppImage(){
    m_buffer = nullptr;
    m_sx = 0;
    m_sy = 0;
    m_sz = 0;
    m_st = 0;
    m_sc = 0;
    m_precision = 8; 
}

MppImageUInt::MppImageUInt(unsigned int* buffer, const unsigned int & sx, const unsigned int & sy, const unsigned int & sz, const unsigned int & st, const unsigned int & sc)
 : MppImage()
 {
    m_buffer = buffer;
    m_sx = sx;
    m_sy = sy;
    m_sz = sz;
    m_st = st;
    m_sc = sc;
    m_precision = 8; 
}

MppImageUInt::~MppImageUInt(){
    if (m_buffer){
        delete[] m_buffer;
    }
}

void MppImageUInt::allocate(){
    m_buffer = new unsigned int[m_sx*m_sy*m_sz*m_st*m_sc];    
}

void MppImageUInt::set_buffer(unsigned int* buffer){
    m_buffer = buffer;
}

unsigned int* MppImageUInt::buffer(){
    return m_buffer;
}


MppImageFloat::MppImageFloat() : MppImage(){
    m_buffer = nullptr;
    m_sx = 0;
    m_sy = 0;
    m_sz = 0;
    m_st = 0;
    m_sc = 0;
    m_precision = 32; 
}

MppImageFloat::MppImageFloat(float* buffer, const unsigned int & sx, const unsigned int & sy, const unsigned int & sz, const unsigned int & st, const unsigned int & sc)
 : MppImage()
 {
    m_buffer = buffer;
    m_sx = sx;
    m_sy = sy;
    m_sz = sz;
    m_st = st;
    m_sc = sc;
    m_precision = 32; 
}

MppImageFloat::~MppImageFloat(){
    if (m_buffer){
        delete[] m_buffer;
    }
}

void MppImageFloat::allocate(){
    m_buffer = new float[m_sx*m_sy*m_sz*m_st*m_sc];    
}

void MppImageFloat::set_buffer(float* buffer){
    m_buffer = buffer;
}

float* MppImageFloat::buffer(){
    return m_buffer;
}


MppImageInt::MppImageInt() : MppImage(){
    m_buffer = nullptr;
    m_sx = 0;
    m_sy = 0;
    m_sz = 0;
    m_st = 0;
    m_sc = 0;
    m_precision = 16; 
}

MppImageInt::MppImageInt(int* buffer, const unsigned int & sx, const unsigned int & sy, const unsigned int & sz, const unsigned int & st, const unsigned int & sc)
 : MppImage()
 {
    m_buffer = buffer;
    m_sx = sx;
    m_sy = sy;
    m_sz = sz;
    m_st = st;
    m_sc = sc;
    m_precision = 16; 
}

MppImageInt::~MppImageInt(){
    if (m_buffer){
        delete[] m_buffer;
    }
}

void MppImageInt::allocate(){
    m_buffer = new int[m_sx*m_sy*m_sz*m_st*m_sc];    
}

void MppImageInt::set_buffer(int* buffer){
    m_buffer = buffer;
}

int* MppImageInt::buffer(){
    return m_buffer;
}
