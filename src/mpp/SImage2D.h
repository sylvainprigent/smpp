/// \file SImage2D.h
/// \brief SImage2D class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2020

#pragma once

class SImage2D{

public:
    SImage2D();
    SImage2D(float* buffer, unsigned int sx, unsigned int sy);

public:
    void set_sx(const unsigned int & value);
    void set_sy(const unsigned int & value);
    void set_buffer(float* buffer);
public:
    unsigned int sx();
    unsigned int sy();
    float* buffer();

protected:
    unsigned int m_sx;
    unsigned int m_sy;
    float* m_buffer;        
};