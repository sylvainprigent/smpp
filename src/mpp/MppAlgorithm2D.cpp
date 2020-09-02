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

/*
    std::cout << "dictionary size: " << m_dictionary->size() << std::endl;
    std::cout << "ref shape box: " << m_dictionary->at(0)->bounding_box()[0] << std::endl;
    std::cout << "ref shape box: " << m_dictionary->at(0)->bounding_box()[1] << std::endl;
    std::cout << "ref shape box: " << m_dictionary->at(0)->bounding_box()[2] << std::endl;
    std::cout << "ref shape box: " << m_dictionary->at(0)->bounding_box()[3] << std::endl;
    std::cout << "ref shape contour size: " << m_dictionary->at(0)->contour()->size() << std::endl;
    */
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