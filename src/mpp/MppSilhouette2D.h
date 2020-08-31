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
/// \brief Container for 1D silhouette
class SMPP_EXPORT MppSilhouette1D{

public:
    MppSilhouette1D();
    MppSilhouette1D(const int & x );

public:
    void add_pair(const int & y_in, const int & y_out);
    int pairs();

public:
    int x(); 
    int pair_in_y(int idx);
    int pair_out_y(int idx);    

protected:
    int m_x;
    std::vector<int> m_in_y;
    std::vector<int> m_out_y;
};


/// \class MppSilhouette2D
/// \brief Container for 2D silhouette
class SMPP_EXPORT MppSilhouette2D{

public:
    MppSilhouette2D();
    ~MppSilhouette2D();

public:
    void add_line(const int & x, const int & y_in, const int & y_out);
    void add_line(MppSilhouette1D* line);
    int count_lines();
    MppSilhouette1D* line(int idx);

public:
    int size(bool force_computation=false);
    int* bounding_box(bool force_computation=false);
    std::vector<MppPoint2D*>* contour(int width=1, bool force_computation=false);
    std::vector<MppPoint2D*>* fill(bool force_computation=false);

public:
    void set_size(int value);

public:
    void print();    

protected:
    std::vector<MppSilhouette1D*> m_lines;

protected:
    int* m_bounding_box;
    int m_size;
    std::vector<MppPoint2D*>* m_contour;
    std::vector<MppPoint2D*>* m_fill;
};
