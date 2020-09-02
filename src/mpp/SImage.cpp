/// \file SImage.h
/// \brief SImage class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2020

#include "SImage.h"

SImage::SImage(){
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

SImage::~SImage(){
    
}

void SImage::set_sx(unsigned int value){
    m_sx = value;
}

void SImage::set_sy(unsigned int value){
    m_sy = value;
}

void SImage::set_sz(unsigned int value){
    m_sz = value;
}

void SImage::set_st(unsigned int value){
    m_st = value;
}

void SImage::set_sc(unsigned int value){
    m_sc = value;
}

unsigned int SImage::sx(){
    return m_sx;
}

unsigned int SImage::sy(){
    return m_sy;
}

unsigned int SImage::sz(){
    return m_sz;
}

unsigned int SImage::st(){
    return m_st;
}

unsigned int SImage::sc(){
    return m_sc;
}

float SImage::rx(){
    return m_rx;
}

float SImage::ry(){
    return m_ry;
}

float SImage::rz(){
    return m_rz;
}

float SImage::rt(){
    return m_rt;    
}

std::string SImage::unit(){
    return m_unit;
}

char SImage::precision(){
    return m_precision;
}
void SImage::set_res(float rx, float ry, float rz, float rt){
    m_rx = rx;
    m_ry = ry;
    m_rz = rz;
    m_rt = rt;
}

void SImage::set_rx(float value){
    m_rx = value;
}

void SImage::set_ry(float value){
    m_ry = value;
}

void SImage::set_rz(float value){
    m_rz = value;
}

void SImage::set_rt(float value){
    m_rt = value;
}

void SImage::set_unit(std::string value){
    m_unit = value;
}


SImageChar::SImageChar() : SImage(){
    m_buffer = nullptr;
    m_sx = 0;
    m_sy = 0;
    m_sz = 0;
    m_st = 0;
    m_sc = 0;
    m_precision = 8; 
}

SImageChar::SImageChar(char* buffer, const unsigned int & sx, const unsigned int & sy, const unsigned int & sz, const unsigned int & st, const unsigned int & sc)
 : SImage()
 {
    m_buffer = buffer;
    m_sx = sx;
    m_sy = sy;
    m_sz = sz;
    m_st = st;
    m_sc = sc;
    m_precision = 8; 
}

SImageChar::~SImageChar(){
    delete m_buffer;
}

void SImageChar::allocate(){
    m_buffer = new char[m_sx*m_sy*m_sz*m_st*m_sc];    
}

void SImageChar::set_buffer(char* buffer){
    m_buffer = buffer;
}

char* SImageChar::buffer(){
    return m_buffer;
}

SImageFloat::SImageFloat() : SImage(){
    m_buffer = nullptr;
    m_sx = 0;
    m_sy = 0;
    m_sz = 0;
    m_st = 0;
    m_sc = 0;
    m_precision = 32; 
}

SImageFloat::SImageFloat(float* buffer, const unsigned int & sx, const unsigned int & sy, const unsigned int & sz, const unsigned int & st, const unsigned int & sc)
 : SImage()
 {
    m_buffer = buffer;
    m_sx = sx;
    m_sy = sy;
    m_sz = sz;
    m_st = st;
    m_sc = sc;
    m_precision = 32; 
}

SImageFloat::~SImageFloat(){
    delete m_buffer;
}

void SImageFloat::allocate(){
    m_buffer = new float[m_sx*m_sy*m_sz*m_st*m_sc];    
}

void SImageFloat::set_buffer(float* buffer){
    m_buffer = buffer;
}

float* SImageFloat::buffer(){
    return m_buffer;
}


SImageInt::SImageInt() : SImage(){
    m_buffer = nullptr;
    m_sx = 0;
    m_sy = 0;
    m_sz = 0;
    m_st = 0;
    m_sc = 0;
    m_precision = 16; 
}

SImageInt::SImageInt(unsigned int* buffer, const unsigned int & sx, const unsigned int & sy, const unsigned int & sz, const unsigned int & st, const unsigned int & sc)
 : SImage()
 {
    m_buffer = buffer;
    m_sx = sx;
    m_sy = sy;
    m_sz = sz;
    m_st = st;
    m_sc = sc;
    m_precision = 16; 
}

SImageInt::~SImageInt(){
    delete m_buffer;
}

void SImageInt::allocate(){
    m_buffer = new unsigned int[m_sx*m_sy*m_sz*m_st*m_sc];    
}

void SImageInt::set_buffer(unsigned int* buffer){
    m_buffer = buffer;
}

unsigned int* SImageInt::buffer(){
    return m_buffer;
}
