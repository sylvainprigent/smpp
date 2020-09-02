/// \file MppDataTerm2DBhattacharyya.cpp
/// \brief MppDataTerm2DBhattacharyya class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2020

#include "math.h"
#include "MppDataTerm2DBhattacharyya.h"

#include <iostream>

MppDataTerm2DBhattacharyya::MppDataTerm2DBhattacharyya(float threshold) : MppDataTerm2D(threshold){
    m_max_distance = 100.0;
    m_width = 1;
}

MppDataTerm2DBhattacharyya::MppDataTerm2DBhattacharyya(SImageFloat* image, float threshold) : MppDataTerm2D(image, threshold){
    m_max_distance = 100.0; 
    m_width = 1;    
}

MppDataTerm2DBhattacharyya::~MppDataTerm2DBhattacharyya(){

}

float MppDataTerm2DBhattacharyya::run(MppShape2D* shape, int x, int y){


    //std::cout << "calculate dataterm:" << x << ", " << y << std::endl;

    int* box = shape->bounding_box();
    if (box[0] - m_width + x < 0){
        //std::cout << "dataterm out of bound:" << x << ", " << y << ", 1:" << box[0] - m_width + x << std::endl;
        return 1;
    }
    if (x + box[1] + m_width >= m_image->sx()){
        //std::cout << "dataterm out of bound:" << x << ", " << y << ", 2:" << x + box[1] + m_width << std::endl;
        return 1;
    }
    if (box[2] - m_width + y < 0){
        //std::cout << "dataterm out of bound:" << x << ", " << y << ", 3:" << box[2] - m_width + y << std::endl;
        return 1;
    }
    if (y + box[3] + m_width >= m_image->sy()){
        //std::cout << "dataterm out of bound:" << x << ", " << y << ", 4:" << y + box[3] + m_width << std::endl;
        return 1;
    }

    // in stats
    //MppSilhouette2D* silhouette = shape->silhouette();
    std::vector<MppPoint2D*>* fill = shape->fill();
    float val;
    float mean_fill = 0.0;
    float var_fill = 0.0;
    int fill_size = fill->size();
    float * buffer = m_image->buffer();
    for (int i = 0 ; i < fill_size ; i++){
        val = buffer[ m_image->sx()*((*fill)[i]->x() + x) + ((*fill)[i]->y() + y)];
        mean_fill += val;
        var_fill += val*val;
    }
    mean_fill /= float(fill_size);
    var_fill = (var_fill-mean_fill*mean_fill/float(fill_size))/(float(fill_size)-1);

    // contour stats
    std::vector<MppPoint2D*>* contour = shape->contour(m_width);
    float mean_contour = 0.0;
    float var_contour = 0.0;
    int size_contour = contour->size();
    for (int i = 0 ; i < size_contour ; i++){
        val = buffer[m_image->sx()*((*contour)[i]->x() + x) + (*contour)[i]->y() + y];
        mean_contour += val;
        var_contour += val*val;
    }
    mean_contour /= float(size_contour);
    var_contour = (var_contour-mean_contour*mean_contour/float(size_contour))/(float(size_contour)-1);

    //std::cout << "size_contour :" << size_contour << std::endl;
    //std::cout << "mean_contour :" << mean_contour << std::endl;
    //std::cout << "mean_fill :" << mean_fill << std::endl;
    if (mean_fill <= mean_contour){
        return 0.8;
    }

    float db = pow(mean_fill - mean_contour, 2) / ( 4 * sqrt(var_fill + var_contour)) + 
               0.5 * log((var_fill + var_contour) / (2 * sqrt(sqrt(var_fill) * sqrt(var_contour))));

    if (db < m_threshold){
       return 1 - db / m_threshold;
    }
    else{
        return exp(-(db - m_threshold) / m_max_distance) - 1;
    }
}