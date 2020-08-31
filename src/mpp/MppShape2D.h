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
/// \brief Interface for shape container
class SMPP_EXPORT MppShape2D{

public:
    MppShape2D();
    virtual ~MppShape2D();

public:
    virtual MppShape2D* copy() = 0;
    virtual void translate(int x, int y) = 0;

public:
    int* bounding_box(bool forceComputation=false);
    int size(bool forceComputation=false);
    std::vector<MppPoint2D*>* contour(bool forceComputation=false);
    std::vector<MppPoint2D*>* fill(bool forceComputation=false);
    MppSilhouette2D* silhouette(bool forceComputation=false);

protected:
    virtual int* computeBoundingBox();
    virtual int computeSize();
    virtual std::vector<MppPoint2D*>* computeContour();
    virtual std::vector<MppPoint2D*>* computeFill();
    virtual MppSilhouette2D* computeSilhouette() = 0;        

protected:
    std::string m_name;
    int* m_bounding_box;
    int m_size;
    std::vector<MppPoint2D*>* m_contour;
    std::vector<MppPoint2D*>* m_fill;
    MppSilhouette2D* m_silhouette;

};
