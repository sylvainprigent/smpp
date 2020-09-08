/// \file MppAlgorithm2DSBCR.cpp
/// \brief MppAlgorithm2DSBCR class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2020

#include "MppAlgorithm2DSBCR.h"
#include "MppRand.h"

#include <iostream>

MppAlgorithm2DSBCR::MppAlgorithm2DSBCR(MppDataTerm2D* data_term, MppInteraction2D* interaction, MppDictionary2D* dictionary)
: MppAlgorithm2D(data_term, interaction, dictionary)
{
    m_n_iter = 1000;
    m_image_sx = m_data_term->image()->getSizeX();
    m_image_sy = m_data_term->image()->getSizeY();
}
MppAlgorithm2DSBCR::MppAlgorithm2DSBCR(MppDataTerm2D* data_term, MppInteraction2D* interaction, std::vector<MppShape2D*>* dictionary)
: MppAlgorithm2D(data_term, interaction, dictionary)
{
    m_n_iter = 1000;
    m_image_sx = m_data_term->image()->getSizeX();
    m_image_sy = m_data_term->image()->getSizeY();
}

MppAlgorithm2DSBCR::~MppAlgorithm2DSBCR()
{

}

void MppAlgorithm2DSBCR::set_n_iter(int n_iter)
{
    m_n_iter = n_iter;
}
    
void MppAlgorithm2DSBCR::run()
{
    int n = 0;
    int cx;
    int cy;
    int cd;
    float data_term;
    float inter_val;
    float interaction_dterm;
    m_config.clear();
    m_config_dataterm.clear();
    std::vector<int> interactions_idxs;
    bool found_interaction;

    while (n < m_n_iter){

        //std::cout << "iter = " << n << std::endl;
        this->generate_candidate(cx, cy, cd);
        data_term = this->m_data_term->run((*m_dictionary)[cd], cx, cy);
        //if (data_term <= 0){
        //    std::cout << "generated shape:" << cx << ", " << cy << ", " << cd << ", data term:" << data_term << std::endl;
        //}
        interaction_dterm = 0.0;
        found_interaction = false;
        if (data_term < 0){
            // search conflicts
            interactions_idxs.clear();
            for (int s = 0 ; s < m_config.size() ; s++){
                inter_val = this->m_interaction->run((*m_dictionary)[m_config[s][0]], m_config[s][1], m_config[s][2], (*m_dictionary)[cd], cx, cy);
                if (inter_val < 0){
                    //std::cout << "found interaction " << m_config[s][1] << ", " << m_config[s][2] << " and " << cx << ", " << cy << std::endl;
                    found_interaction = true;
                    interactions_idxs.push_back(s);
                    interaction_dterm +=  m_config_dataterm[s];       
                }    
            }
            // add shape
            if (!found_interaction){
                int* shape = new int[3];
                shape[0] = cd;
                shape[1] = cx;
                shape[2] = cy;
                m_config.push_back(shape);
                m_config_dataterm.push_back(data_term);
            }
            else{
                // keep the shape if better than conflicts
                if ( data_term < interaction_dterm){
                    // remove conflicted shapes
                    for (int s = interactions_idxs.size()-1 ; s >= 0 ; s--){
                        delete[] m_config[interactions_idxs[s]];
                        m_config.erase(m_config.begin()+interactions_idxs[s]);  
                        m_config_dataterm.erase(m_config_dataterm.begin()+interactions_idxs[s]);  
                    }
                    // add new shape
                    int* shape = new int[3];
                    shape[0] = cd;
                    shape[1] = cx;
                    shape[2] = cy;
                    m_config.push_back(shape);
                    m_config_dataterm.push_back(data_term);
                }
            }
        }
        n++;
    }
    // create the final shape list
    std::cout << "found " << m_config.size() << " shapes" << std::endl;
    m_shapes.resize(m_config.size());
    for (int i = 0 ; i < m_config.size() ; i++){
        MppShape2D* shape = (*m_dictionary)[m_config[i][0]]->copy();
        shape->translate(m_config[i][1], m_config[i][2]);
        m_shapes[i] = shape;
    }
    for (int i = 0 ; i < m_config.size() ; i++){
        delete[] m_config[i];
    }
}

void MppAlgorithm2DSBCR::generate_candidate(int& cx, int & cy, int & cd){

    if (m_use_mask){
        MppPoint2D* p = m_birth_mask[int(MppRandPM::rand()*float(m_birth_mask.size()))];
        cx = p->x();
        cy = p->y();
    }
    else{
        cx = int(MppRandPM::rand()*float(m_image_sx));
        cy = int(MppRandPM::rand()*float(m_image_sy));
    }

    // index in dictionary
    cd = int (MppRandPM::rand()*float(m_dictionary->size()));
}
