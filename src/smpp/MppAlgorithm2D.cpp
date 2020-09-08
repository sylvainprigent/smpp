/// \file MppAlgorithm.cpp
/// \brief MppAlgorithm class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2020

#include "MppAlgorithm2D.h"
#include <iostream>


MppAlgorithm2D::MppAlgorithm2D(MppDataTerm2D* data_term, MppInteraction2D* interaction, MppDictionary2D* dictionary)
{
    m_data_term = data_term;
    m_interaction = interaction;
    dictionary->run();
    m_dictionary = dictionary->dictionary();
    m_use_mask = false;
    m_data_term->init();
}

MppAlgorithm2D::MppAlgorithm2D(MppDataTerm2D* data_term, MppInteraction2D* interaction, std::vector<MppShape2D*>* dictionary)
{
    m_data_term = data_term;
    m_interaction = interaction;
    m_dictionary = dictionary;
    m_use_mask = false;
    m_data_term->init();
}

MppAlgorithm2D::~MppAlgorithm2D()
{
    for (int i = 0 ; i < m_birth_mask.size() ; i++){
        delete m_birth_mask[i];
    }
}

void MppAlgorithm2D::set_birth_mask(SImageUInt* mask){
    m_use_mask = true;
    unsigned int* buffer = mask->getBuffer();
    m_birth_mask.clear();
    for (int x = 0 ; x < mask->getSizeX() ; x++){
        for (int y = 0 ; y < mask->getSizeY() ; y++){
            if (buffer[mask->getSizeY()*x+y] == 255){
                m_birth_mask.push_back(new MppPoint2D(x, y));        
            }
        }
    }
}

std::vector<MppShape2D*> MppAlgorithm2D::shapes()
{
    return m_shapes;
}