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

#include "simage/SImageUInt.h"


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
    /// \brief Setter for birth mask optional parameter.
    ///  if the birth mask is set, objects can be created only at locations where mask=255
    /// \param[in] mask Pointer to the mask image
    void set_birth_mask(SImageUInt* mask);

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

    // optional input
    std::vector<MppPoint2D*> m_birth_mask;
    bool m_use_mask;

    // output
    std::vector<MppShape2D*> m_shapes; ///< List of detected shapes

};