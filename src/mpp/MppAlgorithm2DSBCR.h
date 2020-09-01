/// \file MppAlgorithm2DSBCR.h
/// \brief MppAlgorithm2DSBCR class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2020

#pragma once

#include <vector>

#include "smppExport.h"
#include "MppAlgorithm2D.h"
#include "MppShape2D.h"
#include "MppDataTerm2D.h"
#include "MppInteraction2D.h"
#include "MppDictionary2D.h"


/// \class MppAlgorithm2DSBCR
/// \brief Single birth and cut algorithm
class SMPP_EXPORT MppAlgorithm2DSBCR : public MppAlgorithm2D{

public:
    MppAlgorithm2DSBCR(MppDataTerm2D* data_term, MppInteraction2D* interaction, MppDictionary2D* dictionary);
    MppAlgorithm2DSBCR(MppDataTerm2D* data_term, MppInteraction2D* interaction, std::vector<MppShape2D*>* dictionary);
    ~MppAlgorithm2DSBCR();

public:
    void set_n_iter(int n_iter);

public:
    void run();

protected:
    void generate_candidate(int& cx, int & cy, int & cd);

protected:
    int m_n_iter;
    int m_image_sx;
    int m_image_sy;
    std::vector<int*> m_config;
    std::vector<float> m_config_dataterm;
};
