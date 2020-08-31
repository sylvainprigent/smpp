/// \file MppDictionary2D.cpp
/// \brief MppDictionary2D class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2018

#include "MppDictionary2D.h"


MppDictionary2D::MppDictionary2D(){
    
}

MppDictionary2D::~MppDictionary2D(){

}

std::vector<MppShape2D*>* MppDictionary2D::dictionary(){
    return m_dictionary;
}
