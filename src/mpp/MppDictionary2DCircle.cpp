/// \file MppDictionary2D.cpp
/// \brief MppDictionary2D class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2018

#include "MppDictionary2DCircle.h"
#include "MppShapeCircle.h"


MppDictionary2DCircle::MppDictionary2DCircle(unsigned int min_r, unsigned int max_r){
    m_min_r = min_r;
    m_max_r = max_r;
}

MppDictionary2DCircle::~MppDictionary2DCircle(){

}

void MppDictionary2DCircle::run()
{
    m_dictionary = new std::vector<MppShape2D*>(m_max_r-m_min_r+1);
    for (int r = m_min_r ; r <= m_max_r ; r++){
        (*m_dictionary)[r-m_min_r] = new MppShapeCircle(0, 0, r);
    }
}