/// \file SImage.h
/// \brief SImage class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2020

#pragma once

#include "simageioExport.h"
#include <string>


class SIMAGEIO_EXPORT SImage{

public:
    SImage();
    virtual ~SImage();

public:
    virtual void allocate() = 0;
public:
    void set_sx(unsigned int value);
    void set_sy(unsigned int value);
    void set_sz(unsigned int value);
    void set_st(unsigned int value);
    void set_sc(unsigned int value);

public:
    unsigned int sx();
    unsigned int sy();
    unsigned int sz();
    unsigned int st();
    unsigned int sc();

public:
public:
    // metadata
    float rx();
    float ry();
    float rz();
    float rt();
    std::string unit();
    char precision();
    void set_res(float rx, float ry, float rz, float rt);
    void set_rx(float value);
    void set_ry(float value);
    void set_rz(float value);
    void set_rt(float value);
    void set_unit(std::string value);

protected:
    unsigned int m_sx;
    unsigned int m_sy;
    unsigned int m_sz;
    unsigned int m_st;
    unsigned int m_sc;
    float m_rx; // resolutionX
    float m_ry; // resolutionY
    float m_rz; // resolutionZ
    float m_rt; // resolutionT
    std::string m_unit; // resolution unit
    char m_precision; // precision
};


class SIMAGEIO_EXPORT SImageChar : public SImage{

public:
    SImageChar();
    SImageChar(char* buffer, const unsigned int & sx, const unsigned int & sy, const unsigned int & sz=1, const unsigned int & st=1, const unsigned int & sc=1);
    ~SImageChar();
public:
    void allocate();
public:
    void set_buffer(char* buffer);
public:
    char* buffer();
protected:
    char* m_buffer;
};


class SIMAGEIO_EXPORT SImageFloat : public SImage{

public:
    SImageFloat();
    SImageFloat(float* buffer, const unsigned int & sx, const unsigned int & sy,const unsigned int & sz=1, const unsigned int & st=1, const unsigned int & sc=1);
    ~SImageFloat();
public:
    void allocate();
public:
    void set_buffer(float* buffer);
public:
    float* buffer();
protected:
    float* m_buffer;
};


class SIMAGEIO_EXPORT SImageInt : public SImage{

public:
    SImageInt();
    SImageInt(unsigned int* buffer, const unsigned int & sx, const unsigned int & sy, const unsigned int & sz=1, const unsigned int & st=1, const unsigned int & sc=1);
    ~SImageInt();
public:
    void allocate();
public:
    void set_buffer(unsigned int* buffer);
public:
    unsigned int* buffer();
protected:
    unsigned int* m_buffer;
};
