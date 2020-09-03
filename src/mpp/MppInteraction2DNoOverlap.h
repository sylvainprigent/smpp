/// \file MppInteraction2D.h
/// \brief MppInteraction2D class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2018

#pragma once

#include "smppExport.h"
#include "MppInteraction2D.h"

void findFirstCommonLine(MppSilhouette2D* silhouette1, int x1, MppSilhouette2D* silhouette2, int x2, int &m, int &n);
bool is_overlapping_2d(MppSilhouette2D* silhouette1, int x1, int y1, MppSilhouette2D* silhouette2, int x2, int y2, float allowedPurcentage=0);
float percentage_overlapping_2d(MppSilhouette2D* silhouette1, int x1, int y1, MppSilhouette2D* silhouette2, int x2, int y2);

/// \class MppInteraction2DNoOverlap
/// \brief Calculates if two 2D shapes are overlaping 
class SMPP_EXPORT MppInteraction2DNoOverlap : public MppInteraction2D{

public:
    /// \brief Constructor
    MppInteraction2DNoOverlap();
    /// \brief Constructor
    /// \param[in] percentage Percentage of allowed overlap between shapes
    MppInteraction2DNoOverlap(float percentage);
    /// \brief Destructor
    ~MppInteraction2DNoOverlap();

public:
    /// \brief Calculates the interaction
    /// \param[in] shape1 Reference centerd shape for the first shape candidate
    /// \param[in] x1 X position of the shape center 
    /// \param[in] y1 Y position of the shape center
    /// \param[in] shape2 Reference centerd shape for the second shape candidate
    /// \param[in] x2 X position of the shape center 
    /// \param[in] y2 Y position of the shape center
    float run(MppShape2D* shape1, int x1, int y1, MppShape2D* shape2, int x2, int y2);
    
protected:
    float m_percentage; ///< Percentage Percentage of allowed overlap between shapes
    
};
