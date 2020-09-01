/// \file MppAlgorithm2D.h
/// \brief MppAlgorithm2D class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2020

#pragma once

#include <vector>

#include "smppExport.h"
#include "MppShape2D.h"
#include "MppDataTerm2D.h"
#include "MppInteraction2D.h"
#include "MppDictionary2D.h"


/// \class MppAlgorithm2D
/// \brief Interface for MPP algorithm 2D case
class SMPP_EXPORT MppAlgorithm2D{

public:
    MppAlgorithm2D(MppDataTerm2D* data_term, MppInteraction2D* interaction, MppDictionary2D* dictionary);
    MppAlgorithm2D(MppDataTerm2D* data_term, MppInteraction2D* interaction, std::vector<MppShape2D*>* dictionary);
    ~MppAlgorithm2D();

public:
    virtual void run() = 0;

public:
    std::vector<MppShape2D*> shapes();

protected:
    // inputs
    MppDataTerm2D* m_data_term;
    MppInteraction2D* m_interaction;
    std::vector<MppShape2D*>* m_dictionary;

    // output
    std::vector<MppShape2D*> m_shapes;

};