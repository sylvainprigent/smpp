/// \file MppSilhouette.h
/// \brief MppSilhouette class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2020

#pragma once

#include <string>
#include <vector>
#include "smppExport.h"

#include "MppPoint.h"

/// \class MppSilhouette1D
/// \brief Silhouette representation of a line shape in 2D
class SMPP_EXPORT MppSilhouette1D{

public:
    /// \brief Constructor
    MppSilhouette1D();
    /// \brief Constructor
    /// \param[in] x X coordinate of the line
    MppSilhouette1D(const int & x );

public:
    /// \brief Add a pair of points in the line
    /// \param[in] y_in Y coordinate of the starting point
    /// \param[in] y_out Y coordinate of the ending point
    void add_pair(const int & y_in, const int & y_out);
    /// \brief Getter fot the number of points pairs in the silhouette
    /// \returns the number of points pairs
    int pairs();

public:
    /// \brief Getter for the x coordinate of the line
    /// \returns the x coordinate of the line
    int x(); 
    /// \brief Getter for the y starting point
    /// \param[in] idx Index of the point in the pair list
    int pair_in_y(int idx);
    /// \brief Getter for the y ending point
    /// \param[in] idx Index of the point in the pair list
    int pair_out_y(int idx);    

protected:
    int m_x; ///< line index in the x direction of a 2D plane
    std::vector<int> m_in_y; ///< list of in y coordinates of the line
    std::vector<int> m_out_y; ///< list of out y coordinates of the line
};


/// \class MppSilhouette2D
/// \brief Silhouette representation fo a 2D shape
class SMPP_EXPORT MppSilhouette2D{

public:
    /// \brief Constructor
    MppSilhouette2D();
    /// \brief Destructor
    ~MppSilhouette2D();

public:
    /// \brief Add a new line to the silhouette
    /// \param[in] x X coordinate of the line
    /// \param[in] y_in Y coordinate of the starting point of the line
    /// \param[in] y_out Y coordinate of the ending point of the line
    void add_line(const int & x, const int & y_in, const int & y_out);
    /// \brief Add a new line to the silhouette
    /// \param[in] Pointer to the 1D silhouette representation of the line
    void add_line(MppSilhouette1D* line);
    /// \brief Getter for the numer of lines in the silhouette
    /// \returns the number of lines in the silhouette
    int count_lines();
    /// \brief Getter for a single line in the silhouette
    /// \param[in] idx Index of the line to get
    /// \returns a pointer to the 1D silhouette representation of the line
    MppSilhouette1D* line(int idx);

public:
    /// \brief Getter for the size of the silhouette (number of points inside the shape)
    /// \param[in] forceComputation Force the computation if true. Otherwise returns the previously computed value
    /// \returns the size of the silhouette
    int size(bool force_computation=false);
    /// \brief Getter for the shape bounding box
    /// \param[in] forceComputation Force the computation if true. Otherwise returns the previously computed value
    /// \returns int[4] containing the 4 corners of the box [top left, top right, bottom left, bottom right]
    int* bounding_box(bool force_computation=false);
    /// \brief Getter for the shape contour
    /// \param[in] forceComputation Force the computation if true. Otherwise returns the previously computed value
    /// \returns a pointer to the list of points located in the shape contour
    std::vector<MppPoint2D*>* contour(int width=1, bool force_computation=false);
    /// \brief Getter for the points coordinates inside the shape
    /// \param[in] forceComputation Force the computation if true. Otherwise returns the previously computed value
    /// \returns a pointer to the list of points inside the shape
    std::vector<MppPoint2D*>* fill(bool force_computation=false);
    /// \brief Getter for the normal vectors to the contour
    /// \param[in] forceComputation Force the computation if true. Otherwise returns the previously computed value
    /// \returns a pointer to the list of normal vectors
    std::vector<MppPoint2D*>* normals(bool force_computation=false);

public:
    bool is_inside(const int & x, const int & y);
    bool is_in_border(const int & x, const int & y);
    void find_closest_pixels(int pos, std::vector<MppPoint2D> &neighboors);

public:
    /// \brief Setter for the silhouette size
    /// \param[in] value Size of the silhouette
    void set_size(int value);

public:
    /// \brief Print the silhouette point coordinates in the concole
    void print();    

protected:
    std::vector<MppSilhouette1D*> m_lines; ///< List of lines in the silhouette

protected:
    int* m_bounding_box; ///< Silhouette bounding box
    int m_size; ///< Silhouette size
    std::vector<MppPoint2D*>* m_contour; ///< Pointer to the list of points in the silhouette contour
    std::vector<MppPoint2D*>* m_fill; ///< Pointer to the list of points inside the silhouette
    std::vector<MppPoint2D*>* m_normals; ///< Pointer to the list of normals to the contour
    
};
