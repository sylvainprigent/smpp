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
/// \brief Single birth and cut shape detection algorithm
class SMPP_EXPORT MppAlgorithm2DSBCR : public MppAlgorithm2D{

public:
    /// \brief Constructor
    /// \param[in] data_term Pointer to the data term class
    /// \param[in] interaction Pointer to the interaction class
    /// \param[in] dictionary Pointer to the class that generate a reference shape dictionary
    MppAlgorithm2DSBCR(MppDataTerm2D* data_term, MppInteraction2D* interaction, MppDictionary2D* dictionary);
    /// \brief Constructor
    /// \param[in] data_term Pointer to the data term class
    /// \param[in] interaction Pointer to the interaction class
    /// \param[in] dictionary Pointer to a dictionary of shapes
    MppAlgorithm2DSBCR(MppDataTerm2D* data_term, MppInteraction2D* interaction, std::vector<MppShape2D*>* dictionary);
    /// \brief Destructor
    virtual ~MppAlgorithm2DSBCR();

public:
    /// \brief Maximum number of iteration. It corresponds to the number of tested shapes
    /// \param[in] n_iter Maximum number of iteration
    void set_n_iter(int n_iter);

public:
    /// \brief Method that implement shape detection algorithm
    void run();

protected:
    /// \brief Randomly generate a new shape
    /// \param[in] cx X position of the shape center
    /// \param[in] cy Y position of the shape center
    /// \param[in] cd Position of the reference shape in the dictionary
    void generate_candidate(int& cx, int & cy, int & cd);

protected:
    int m_n_iter; ///< Maximum number of iteractions
    int m_image_sx; ///< Size of the image in the x direction
    int m_image_sy; ///< Size of the image in the y direction
    std::vector<int*> m_config; ///< Temporary config of shapes 
    std::vector<float> m_config_dataterm; ///< Temporary config shapes dataterms
};
