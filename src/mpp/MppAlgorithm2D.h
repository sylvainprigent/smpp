/// \file MppAlgorithm2D.h
/// \brief MppAlgorithm2D class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2020

#pragma once

#include <vector>

#include "smppExport.h"
#include "MppShape2D.h"
#include "MppDataTerm2D.h"
#include "MppInteraction2D.h"
#include "MppDictionary2D.h"


/// \class MppAlgorithm2D
/// \brief Interface for MPP algorithm 2D case
class SMPP_EXPORT MppAlgorithm2D{

public:
    /// \brief Constructor
    /// \param[in] data_term Pointer to the data term class
    /// \param[in] interaction Pointer to the interaction class
    /// \param[in] dictionary Pointer to the class that generate a reference shape dictionary
    MppAlgorithm2D(MppDataTerm2D* data_term, MppInteraction2D* interaction, MppDictionary2D* dictionary);
    /// \brief Constructor
    /// \param[in] data_term Pointer to the data term class
    /// \param[in] interaction Pointer to the interaction class
    /// \param[in] dictionary Pointer to a dictionary of shapes
    MppAlgorithm2D(MppDataTerm2D* data_term, MppInteraction2D* interaction, std::vector<MppShape2D*>* dictionary);
    /// \brief Destructor
    virtual ~MppAlgorithm2D();

public:
    /// \brief Method that implement shape detection algorithm
    virtual void run() = 0;

public:
    /// \brief Getter of the shapes dictionary
    /// \returns The list of detected shapes 
    std::vector<MppShape2D*> shapes();

protected:
    // inputs
    MppDataTerm2D* m_data_term; ///< Pointer to the data term object
    MppInteraction2D* m_interaction; ///< Pointer to the interaction object 
    std::vector<MppShape2D*>* m_dictionary; ///< Pointer to the shapes dictionary

    // output
    std::vector<MppShape2D*> m_shapes; ///< List of detected shapes

};