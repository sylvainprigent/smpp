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
    /// \brief Constructor
    /// \param[in] min_r Minimum radius of the circles in the dictionary
    /// \param[in] max_r Maximim radius of the circles in the dicitonary
    /// \param[in] step Step of possible radii between min_r and max_r 
    MppDictionary2DCircle(unsigned int min_r, unsigned int max_r, unsigned int step = 1);
    /// \brief Destructor
    virtual ~MppDictionary2DCircle();

public:
    /// \brief Method that implement dictionary build
    void run();

protected:
    unsigned int m_min_r; ///< Minimum radius of the circles in the dictionary
    unsigned int m_max_r; ///< Maximim radius of the circles in the dictionary
    unsigned int m_step; ///< Step of possible radii between min_r and max_r 

};
