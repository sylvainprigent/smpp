/// \file MppShape2D.h
/// \brief MppShape2D class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2020

#pragma once

#include <string>
#include <vector>

#include "smppExport.h"

#include "MppPoint.h"
#include "MppSilhouette2D.h"

/// \class MppShape2D
/// \brief Container for a 2D shape
class SMPP_EXPORT MppShape2D{

public:
    /// \brief Constructor
    MppShape2D();
    /// \brief Destructor
    virtual ~MppShape2D();

public:
    /// \brief Create a copy of the shape
    /// \returns a pointer to the shape copy
    virtual MppShape2D* copy() = 0;
    /// \brief Translate the shape in x and y direction
    /// \param[in] x Value of translation in the X direction
    /// \param[in] y Value of translation in the Y direction
    virtual void translate(int x, int y) = 0;

public:
    /// \brief Getter for the shape bounding box
    /// \param[in] forceComputation Force the computation if true. Otherwise returns the previously computed value
    /// \returns int[4] containing the 4 corners of the box [top left, top right, bottom left, bottom right]
    int* bounding_box(bool forceComputation=false);
    /// \brief Getter for the shape size (number of pixels inside the shape)
    /// \param[in] forceComputation Force the computation if true. Otherwise returns the previously computed value
    /// \return the size of the shape
    int size(bool forceComputation=false);
    /// \brief Getter for the shape contour
    /// \param[in] forceComputation Force the computation if true. Otherwise returns the previously computed value
    /// \returns a pointer to the list of points located in the shape contour
    std::vector<MppPoint2D*>* contour(bool forceComputation=false);
    /// \brief Getter for the points coordinates inside the shape
    /// \param[in] forceComputation Force the computation if true. Otherwise returns the previously computed value
    /// \returns a pointer to the list of points inside the shape
    std::vector<MppPoint2D*>* fill(bool forceComputation=false);
    /// \brief Getter for the silhouette representation of the shape
    /// \param[in] forceComputation Force the computation if true. Otherwise returns the previously computed value
    /// \returns a pointer to the silhouette
    MppSilhouette2D* silhouette(bool forceComputation=false);

protected:
    /// \brief Do the computation of the counding box
    /// \returns the bounding box
    virtual int* computeBoundingBox();
    /// \brief Do the size computation
    /// \returns the shape size
    virtual int computeSize();
    /// \brief Do the contour computation
    /// \param[in] pointer to the list of contour points
    virtual std::vector<MppPoint2D*>* computeContour();
    /// \brief Compute the points inside the shape
    /// \return a pointer to the list of points inside the shape
    virtual std::vector<MppPoint2D*>* computeFill();
    /// \brief Compute a silhouette representation of the shape
    /// \returns a pointer to the silhouette
    virtual MppSilhouette2D* computeSilhouette() = 0;        

protected:
    int* m_bounding_box; ///< Shape bounding box
    int m_size; ///< Shape size
    std::vector<MppPoint2D*>* m_contour; ///< Pointer to the list of points in the shape contour
    std::vector<MppPoint2D*>* m_fill; ///< Pointer to the list of points inside the shape
    MppSilhouette2D* m_silhouette; ///< Pointer to the silhouette representation of the shape

};
