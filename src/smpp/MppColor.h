/// \file MppColor.h
/// \brief MppColor class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2020

#pragma once

#include <vector>
#include "smppExport.h"

/// \class MppColor
/// \brief class allowing to get a random color
class SMPP_EXPORT MppColor{

public:
    /// \brief Generate a random RGB color
    /// \return a random RGB color
    static std::vector<int> rand_rgb();
    /// \brief Convert an HSV color into an RGB color
    /// \param[in] h H value
    /// \param[in] s S value
    /// \param[in] v V value
    /// \returns the vector containing the 3 RGB components
    static std::vector<int> hsv_to_rgb(float h, float s, float v);
};
