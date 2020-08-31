/// \file MppAlgorithm.cpp
/// \brief MppAlgorithm class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2020

#include "MppAlgorithm2D.h"


MppAlgorithm2D::MppAlgorithm2D(MppDataTerm2D* data_term, MppInteraction2D* interaction, MppDictionary2D* dictionary)
{
    m_data_term = data_term;
    m_interaction = interaction;
    dictionary->run();
    m_dictionary = dictionary->dictionary();
}

MppAlgorithm2D::MppAlgorithm2D(MppDataTerm2D* data_term, MppInteraction2D* interaction, std::vector<MppShape2D*>* dictionary)
{
    m_data_term = data_term;
    m_interaction = interaction;
    m_dictionary = dictionary;
}

MppAlgorithm2D::~MppAlgorithm2D()
{

}

std::vector<MppShape2D*> MppAlgorithm2D::shapes()
{
    return m_shapes;
}
