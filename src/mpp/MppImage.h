/// \file MppImage.h
/// \brief MppImage class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2020

#pragma once

#include "smppExport.h"
#include <string>


/// \class MppImage
/// \brief Abstract container for an image
class SMPP_EXPORT MppImage{

public:
    /// \brief Constructor
    MppImage();
    /// \brief Destructor
    virtual ~MppImage();

public:
    /// \brief Allocate memory for the image
    virtual void allocate() = 0;

public:
    /// \brief Setter for the size of the image in the x direction
    /// \param[in] value The image size in the x direction
    void set_sx(unsigned int value);
    /// \brief Setter for the size of the image in the y direction
    /// \param[in] value The image size in the y direction
    void set_sy(unsigned int value);
    /// \brief Setter for the size of the image in the z direction
    /// \param[in] value The image size in the z direction
    void set_sz(unsigned int value);
    /// \brief Setter for the number of time frames in the image
    /// \param[in] value The number of time frames
    void set_st(unsigned int value);
    /// \brief Setter for the number of channels in the image
    /// \param[in] value The number of channels   
    void set_sc(unsigned int value);

public:
    /// \brief Getter for the size of the image in the x direction
    /// \returns the image size in the x direction
    unsigned int sx();
    /// \brief Getter for the size of the image in the y direction
    /// \returns the image size in the y direction
    unsigned int sy();
    /// \brief Getter for the size of the image in the z direction
    /// \returns the image size in the z direction
    unsigned int sz();
    /// \brief Getter for the number of time frames in the image
    /// \returns the number of time frames
    unsigned int st();
    /// \brief Getter for the number of channels in the image
    /// \returns the number of channels  
    unsigned int sc();

public:
    // metadata
    /// \brief Getter for the X resolution
    /// \returns the value of the resolution in the x direction
    float rx();
    /// \brief Getter for the Y resolution
    /// \returns the value of the resolution in the y direction
    float ry();
    /// \brief Getter for the Z resolution
    /// \returns the value of the resolution in the z direction
    float rz();
    /// \brief Getter for the time resolution
    /// \returns the value of the time resolution
    float rt();
    /// \brief Getter for the resolution unit
    /// \returns a string containing the resolution unit name
    std::string unit();
    /// \brief Getter for the image precision (8, 16, 32)
    /// \returns the image precision
    char precision();
    /// \brief Setter for the resolution
    /// \param[in] rx X resolution
    /// \param[in] ry Y resolution
    /// \param[in] rz Z resolution
    /// \param[in] rt Time resolution
    void set_res(float rx, float ry, float rz, float rt);
    /// \brief Setter for the X resolution
    /// \param[in] value Value of the X resolution
    void set_rx(float value);
    /// \brief Setter for the Y resolution
    /// \param[in] value Value of the Y resolution
    void set_ry(float value);
    /// \brief Setter for the Z resolution
    /// \param[in] value Value of the Z resolution    
    void set_rz(float value);
    /// \brief Setter for the time resolution
    /// \param[in] value Value of the time resolution    
    void set_rt(float value);
    /// \brief Setter for the resolution unit
    /// \param[in] value Value of the resolution unit
    void set_unit(std::string value);

protected:
    unsigned int m_sx; ///< size x
    unsigned int m_sy; ///< size y
    unsigned int m_sz; ///< size z
    unsigned int m_st; ///< size t
    unsigned int m_sc; ///< size c
    float m_rx; ///< resolutionX
    float m_ry; ///< resolutionY
    float m_rz; ///< resolutionZ
    float m_rt; ///< resolutionT
    std::string m_unit; ///< resolution unit
    char m_precision; ///< precision
};


/// \class MppImage
/// \brief Container for a char image
class SMPP_EXPORT MppImageChar : public MppImage{

public:
    /// \brief Constructor
    MppImageChar();
    /// \brief Constructor
    /// \param[in] buffer Pointer to the array containinf the data
    /// \param[in] sx Size in the X direction
    /// \param[in] sy Size in the Y direction
    /// \param[in] sz Size in the Z direction
    /// \param[in] st Number of time frames
    /// \param[in] sc Number of channels
    MppImageChar(char* buffer, const unsigned int & sx, const unsigned int & sy, const unsigned int & sz=1, const unsigned int & st=1, const unsigned int & sc=1);
    /// \brief Destructor
    ~MppImageChar();

public:
    /// \brief Allocate the memory
    void allocate();

public:
    /// \brief Setter for the data buffer
    /// \param[in] buffer Pointer to the data array
    void set_buffer(char* buffer);

public:
    /// \brief Getter for the buffer
    /// \returns a pointer to the data array
    char* buffer();

protected:
    char* m_buffer; ///< Data array
};


/// \class MppImage
/// \brief Container for a char image
class SMPP_EXPORT MppImageFloat : public MppImage{

public:
    /// \brief Contructor
    MppImageFloat();
    /// \brief Constructor
    /// \param[in] buffer Pointer to the array containinf the data
    /// \param[in] sx Size in the X direction
    /// \param[in] sy Size in the Y direction
    /// \param[in] sz Size in the Z direction
    /// \param[in] st Number of time frames
    /// \param[in] sc Number of channels
    MppImageFloat(float* buffer, const unsigned int & sx, const unsigned int & sy,const unsigned int & sz=1, const unsigned int & st=1, const unsigned int & sc=1);
    /// \brief Destructor
    ~MppImageFloat();

public:
    /// \brief Allocate the buffer memory
    void allocate();

public:
    /// \brief Setter for the buffer
    /// \param[in] buffer Pointer to the buffer data array
    void set_buffer(float* buffer);

public:
    /// \brief Getter fot the buffer
    /// \returns a Pointer to the data buffer
    float* buffer();

protected:
    float* m_buffer; ///< Pointer to the data buffer
};


class SMPP_EXPORT MppImageInt : public MppImage{

public:
    /// \brief Contructor
    MppImageInt();
    /// \brief Constructor
    /// \param[in] buffer Pointer to the array containinf the data
    /// \param[in] sx Size in the X direction
    /// \param[in] sy Size in the Y direction
    /// \param[in] sz Size in the Z direction
    /// \param[in] st Number of time frames
    /// \param[in] sc Number of channels
    MppImageInt(unsigned int* buffer, const unsigned int & sx, const unsigned int & sy, const unsigned int & sz=1, const unsigned int & st=1, const unsigned int & sc=1);
    /// \brief Destructor    
    ~MppImageInt();

public:
    /// \brief Allocate the buffer memory
    void allocate();

public:
    /// \brief Setter for the buffer
    /// \param[in] buffer Pointer to the buffer data array
    void set_buffer(unsigned int* buffer);

public:
    /// \brief Getter fot the buffer
    /// \returns a Pointer to the data buffer
    unsigned int* buffer();

protected:
    unsigned int* m_buffer; ///< Pointer to the data buffer

};
