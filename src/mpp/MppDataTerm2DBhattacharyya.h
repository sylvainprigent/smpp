/// \file MppDataTerm2DBhattacharyya.h
/// \brief MppDataTerm2DBhattacharyya class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2020

#pragma once

#include "smppExport.h"
#include "MppDataTerm2D.h"

/// \class MppDataTerm2D
/// \brief Interface for MPP data term in 2D
class SMPP_EXPORT MppDataTerm2DBhattacharyya : public MppDataTerm2D{

public:
    MppDataTerm2DBhattacharyya(float threshold);
    MppDataTerm2DBhattacharyya(SImageFloat* image, float threshold);
    virtual ~MppDataTerm2DBhattacharyya();

public:
    float run(MppShape2D* shape, int x, int y);

protected:
    float m_max_distance;
    int m_width;
};
