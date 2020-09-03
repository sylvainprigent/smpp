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
    /// \brief Constructor
    MppPoint();
    /// \brief Destructor
    virtual ~MppPoint();
};


/// \class MppPoint2D
/// \brief 2D point container
class SMPP_EXPORT MppPoint2D : public MppPoint{

public:
    /// \brief Constructor
    MppPoint2D(); 
    //// \brief Constructor
    /// \param[in] x X coordinate of the point
    /// \param[in] y Y coordinate of the point
    MppPoint2D(const int & x, const int & y);
    /// \brief Destructor
    virtual ~MppPoint2D();

public:
    /// \brief Setter for the x coordinate
    /// \param[in] x X coordinate of the point
    void setX(const int & x);
    /// \brief Setter for the y coordinate
    /// \param[in] y Y coordinate of the point
    void setY(const int & y);
    /// \brief Getter for the x coordinate
    /// \return the x coordinate of the point
    int x();
    /// \brief Getter for the y coordinate
    /// \return the y coordinate of the point
    int y();

protected:
    int m_x; ///< X coordinate of the point
    int m_y; ///< Y coordinate of the point    

};


/// \class MppPoint3D
/// \brief 3D point container
class SMPP_EXPORT MppPoint3D : public MppPoint{

public:
    /// \brief Constructor
    MppPoint3D(); 
    //// \brief Constructor
    /// \param[in] x X coordinate of the point
    /// \param[in] y Y coordinate of the point
    MppPoint3D(const int& x, const int& y, const int& z);
    /// \brief Destructor
    virtual ~MppPoint3D();

public:
    /// \brief Setter for the x coordinate
    /// \param[in] x X coordinate of the point
    void setX(const int & x);
    /// \brief Setter for the y coordinate
    /// \param[in] y Y coordinate of the point    
    void setY(const int & y);
    /// \brief Setter for the z coordinate
    /// \param[in] z Z coordinate of the point     
    void setZ(const int & z);
    /// \brief Getter for the x coordinate
    /// \return the x coordinate of the point
    int x();
    /// \brief Getter for the y coordinate
    /// \return the y coordinate of the point
    int y();
    /// \brief Getter for the z coordinate
    /// \return the z coordinate of the point
    int z();

protected:
    int m_x; ///< X coordinate of the point
    int m_y; ///< Y coordinate of the point
    int m_z; ///< Z coordinate of the point   

};
