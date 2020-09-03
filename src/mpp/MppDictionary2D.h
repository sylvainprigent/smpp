/// \file MppDictionary2D.h
/// \brief MppDictionary2D class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2020

#pragma once

#include <vector>

#include "smppExport.h"
#include "MppShape2D.h"

/// \class MppDictionary2D
/// \brief Interface to class that create a dictionary (list) of shapes
class SMPP_EXPORT MppDictionary2D{

public:
    /// \brief Constructor
    MppDictionary2D();
    /// \brief Destructor
    virtual ~MppDictionary2D();

public:
    /// \brief Method that implement dictionary build
    virtual void run() = 0;

public:
    /// \brief Getter for the dictionary
    /// \returns a pointer to the list of shapes
    std::vector<MppShape2D*>* dictionary();

protected:
    std::vector<MppShape2D*>* m_dictionary; ///< the dictionary is a list of shapes
};
