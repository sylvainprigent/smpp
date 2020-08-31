/// \file MppDictionary2DCircle.h
/// \brief MppDictionary2DCircle class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2020

#pragma once

#include "smppExport.h"
#include "MppDictionary2D.h"

/// \class MppDictionaryCircle
/// \brief Generates a dictionary of 2D circles
class SMPP_EXPORT MppDictionary2DCircle : public MppDictionary2D{

public:
    MppDictionary2DCircle(unsigned int min_r, unsigned int max_r);
    virtual ~MppDictionary2DCircle();

public:
    void run();

protected:
    unsigned int m_min_r;
    unsigned int m_max_r;

};
