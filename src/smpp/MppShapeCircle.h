/// \file MppShapeCircle.h
/// \brief MppShapeCircle class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2020

#pragma once

#include "smppExport.h"

#include "MppShape2D.h"

std::vector<MppPoint2D> compute_circle_coordinates(int x_center, int y_center, int radius);

/// \class MppShapeCircle
/// \brief Define a circle shape in 2D
class SMPP_EXPORT MppShapeCircle : public MppShape2D{

public:
    /// \brief Constructor
    MppShapeCircle();
    /// \brief Constructor
    /// \param[in] x X coordinate of the circle center
    /// \param[in] y Y coordinate of the circle center
    /// \param[in] r Radius of the circle
    MppShapeCircle(int x, int y, int r);
    /// \brief Destructor
    virtual ~MppShapeCircle();

public:
    /// \brief Setter for the center X coordinate
    /// \param[in] x X coordinate of the circle center
    void set_x(const int & x);
    /// \brief Setter for the center Y coordinate
    /// \param[in] y Y coordinate of the circle center
    void set_y(const int & y);
    /// \brief Setter for the radius
    /// \param[in] r Radius of the circle
    void set_r(const int & r);
    /// \brief Getter for the center X coordinate
    /// \returns the value of the X center coordinate
    int x();
    /// \brief Getter for the center Y coordinate
    /// \returns the value of the Y center coordinate
    int y();
    /// \brief Getter for the circle radius
    /// \return the value of the radius
    int r();

public:
    /// \brief Create a copy of the shape
    /// \returns a pointer to the shape copy
    MppShape2D* copy();
    /// \brief Translate the shape in x and y direction
    /// \param[in] x Value of translation in the X direction
    /// \param[in] y Value of translation in the Y direction
    void translate(int x, int y); 

public:
    /// \brief Compute a silhouette representation of the shape
    /// \returns a pointer to the silhouette
    MppSilhouette2D* computeSilhouette(); 

protected:
    int m_x; ///< X coordinate of the circle center
    int m_y; ///< Y coordinate of the circle center 
    int m_r; ///< Radius of the circle

};
