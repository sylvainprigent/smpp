/// \file MppAlgorithm2D.h
/// \brief MppAlgorithm2D class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2020

#pragma once

#include <vector>

#include "smppExport.h"
#include "MppShape2D.h"

/// \class MppAlgorithm2D
/// \brief Interface for MPP algorithm 2D case
class SMPP_EXPORT MppAlgorithm2D{

public:
    MppAlgorithm2D();
    ~MppAlgorithm2D();

public:
    virtual void run() = 0;
    std::vector<MppShape2D*> shapes();

protected:
    std::vector<MppShape2D*> m_shapes;

};