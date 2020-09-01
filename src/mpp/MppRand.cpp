
/// \file MppRand.cpp
/// \brief MppRand class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2020

#include "MppRand.h"

#define IA 16807 ///< IA
#define IM 2147483647 ///< IM
#define AM (1.0/IM) ///< AM
#define IQ 127773 ///< IQ
#define IR 2836 ///< IR
#define MASK 123459876 ///< MASK

long MppRandPM::m_seed;

float MppRandPM::rand(){

    long k;
    float ans;
    m_seed ^= MASK;               // XORing with MASK allows use of zero and other
    k=(m_seed)/IQ;                //simple bit patterns for idum.
    m_seed=IA*(m_seed-k*IQ)-IR*k; // Compute idum=(IA*idum) % IM without overif
    if (m_seed < 0) m_seed += IM; // flows by Schrage’s method.
    ans=float(AM)*float(m_seed);              // Convert idum to a floating result.
    m_seed ^= MASK;               // Unmask before return.
    return ans;

}

void MppRandPM::srand(long seed){
    m_seed = seed;
}