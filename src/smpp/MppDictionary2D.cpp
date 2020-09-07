/// \file MppDictionary2D.cpp
/// \brief MppDictionary2D class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2018

#include "MppDictionary2D.h"


MppDictionary2D::MppDictionary2D(){
    m_dictionary = nullptr;
}

MppDictionary2D::~MppDictionary2D(){
    if (m_dictionary){
        for (int i = 0 ; i < m_dictionary->size() ; i++){
            delete (*m_dictionary)[i];
        }
        delete m_dictionary;
    }
}

std::vector<MppShape2D*>* MppDictionary2D::dictionary(){
    return m_dictionary;
}
