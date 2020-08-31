/// \file MppShape.h
/// \brief MppShape class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2020

#pragma once

#include "smppExport.h"

/// \class MppPoint
/// \brief Abstract point container
class SMPP_EXPORT MppPoint{

public:
    MppPoint();
    virtual ~MppPoint();
};

/// \class MppPoint2D
/// \brief 2D point container
class SMPP_EXPORT MppPoint2D : public MppPoint{

public:
    MppPoint2D(); 
    MppPoint2D(const int & x, const int & y);
    virtual ~MppPoint2D();

public:
    void setX(const int & x);
    void setY(const int & y);
    int x();
    int y();

protected:
    int m_x;
    int m_y;    

};

/// \class MppPoint3D
/// \brief 3D point container
class SMPP_EXPORT MppPoint3D : public MppPoint{

public:
    MppPoint3D(); 
    MppPoint3D(const int& x, const int& y, const int& z);
    virtual ~MppPoint3D();

public:
    void setX(const int& x);
    void setY(const int& y);
    void setZ(const int& z);
    int x();
    int y();
    int z();

protected:
    int m_x;
    int m_y;
    int m_z;    

};
