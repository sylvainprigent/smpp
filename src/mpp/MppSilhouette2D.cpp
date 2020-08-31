/// \file MppSilhouette2D.cpp
/// \brief MppSilhouette2D class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2020

#include "MppSilhouette2D.h"

#include <iostream>


MppSilhouette1D::MppSilhouette1D(){

}

MppSilhouette1D::MppSilhouette1D(const int & x ){
    m_x = x;
}

int MppSilhouette1D::pair_in_y(int idx){
    return m_in_y[idx];
}

int MppSilhouette1D::pair_out_y(int idx){
    return m_out_y[idx];
}  

void MppSilhouette1D::add_pair(const int & y_in, const int & y_out){
    m_in_y.push_back(y_in);
    m_out_y.push_back(y_out);
}

int MppSilhouette1D::pairs(){
    return m_in_y.size();
}

int MppSilhouette1D::x(){
    return m_x;
}

MppSilhouette2D::MppSilhouette2D(){
    m_bounding_box = nullptr;
    m_size = -1;
    m_contour = nullptr;
    m_fill = nullptr;
}

MppSilhouette2D::~MppSilhouette2D(){
    for (int i = 0 ; i < m_lines.size() ; i++){
        delete m_lines[i];
    }

    if (m_bounding_box){
        delete m_bounding_box;
    }
    if (m_contour){
        for (int i = 0 ; i < m_contour->size() ; i++){
            delete (*m_contour)[i];
        }
        delete m_contour;
    }
    if (m_fill){
        for (int i = 0 ; i < m_fill->size() ; i++){
            delete (*m_fill)[i];
        }
        delete m_fill;
    }
}

void MppSilhouette2D::set_size(int value){
    m_size = value;
}

int MppSilhouette2D::count_lines(){
    return m_lines.size();
}

MppSilhouette1D* MppSilhouette2D::line(int idx){
    return m_lines[idx];
}

void MppSilhouette2D::add_line(const int & x, const int & y_in, const int & y_out){

    MppSilhouette1D *silhouette1d = new MppSilhouette1D(x);
    silhouette1d->add_pair(y_in, y_out);
    m_lines.push_back(silhouette1d);
}

void MppSilhouette2D::add_line(MppSilhouette1D* line){
    m_lines.push_back(line);
}

int MppSilhouette2D::size(bool force_computation){

    if (m_size == -1 || force_computation){
        m_size = 0;
        MppSilhouette1D *line_ptr;
        for (int i = 0 ; i < m_lines.size() ; i++){
            line_ptr = m_lines[i];
            for (int j = 0 ; j < line_ptr->pairs() ; j++){
                m_size += abs(line_ptr->pair_out_y(j) - line_ptr->pair_in_y(j) +1);
            }
        }                              
    }
    return m_size;
}

int* MppSilhouette2D::bounding_box(bool force_computation){

    if ( m_bounding_box != nullptr && !force_computation){
        return m_bounding_box;
    }    

    int x_min = m_lines[0]->x();
    int x_max = m_lines[m_lines.size()-1]->x();
    int y_min = 999999;
    int y_max = -999999;
    int mini, maxi;

    MppSilhouette1D *sil_ptr;
    for (int i = 0 ; i < m_lines.size() ; i++){
        sil_ptr = m_lines[i];
        mini = sil_ptr->pair_in_y(0);
        if (mini < y_min){
            y_min = mini;        
        }
        maxi = sil_ptr->pair_out_y(sil_ptr->pairs()-1);
        if (maxi > y_max){
            y_max = maxi;
        }
    }   
    m_bounding_box = new int[4];
    m_bounding_box[0] = x_min;
    m_bounding_box[1] = x_max;
    m_bounding_box[2] = y_min;
    m_bounding_box[3] = y_max;    
    return m_bounding_box;
}

std::vector<MppPoint2D*>* MppSilhouette2D::contour(int width, bool force_computation){

    if (m_contour != nullptr && !force_computation){
        return m_contour;
    }

    // Generate an image from the inside coordinates list
    std::vector<MppPoint2D*>* inside = this->fill();
    int x_min = 9999999;
    int y_min = 9999999;
    int x_size = 0;
    int y_size = 0;
    int v0;
    int v1;
    MppPoint2D* point;
    for (int i = 0 ; i < m_size ; i++){
        point = static_cast<MppPoint2D*>((*inside)[i]);
        v0 = point->x();
        v1 = point->y();
        if (v0 < x_min){
            x_min = v0;
        }
        if (v1 < y_min){
            y_min = v1;
        }
        if (v0 > x_size){
            x_size = v0; 
        }     
        if (v1 > y_size){
            y_size = v1; 
        }    
    }                      
    x_size = x_size - x_min + 1;
    y_size = y_size - y_min + 1;

    int nl = x_size+2*width;
    int nc = y_size+2*width;
    int* im = new int[nl*nc];
    for (int i = 0 ; i < nl*nc ; i++){
        im[i] = 0;
    }

    for (int i = 0 ; i < m_size ; i++){
        point = static_cast<MppPoint2D*>((*inside)[i]);
        im[nc*(point->x()-x_min + width)+(point->y()-y_min + width)] = 1;
    }        

    //get the border as image dilate
    m_contour = new std::vector<MppPoint2D*>();
    int a, b, c, d;
    for (int i = 0 ; i < nl ; i++){
        for (int j = 0 ; j < nc ; j++){
            if (im[nc*i+j] == 0){
                if (i == 0){
                    a = 0;
                }    
                else{         
                    a = im[nc*(i-1) + j]; 
                }    
                if (i == nl-1){
                    b = 0;    
                }
                else{
                    b = im[nc*(i+1) + j];
                }    
                if (j == 0){
                    c = 0;
                }    
                else{
                   c = im[nc*i + (j-1)];
                }   
                if (j == nc -1){
                    d = 0;
                }
                else{
                    d = im[nc*i + (j+1)];
                }         
                if (a > 0 || b > 0 || c > 0 || d > 0){
                    m_contour->push_back(new MppPoint2D(i + x_min - width, j + y_min - width));
                }    
            }
        }
    }                
    return m_contour;

}

std::vector<MppPoint2D*>* MppSilhouette2D::fill(bool force_computation){

    if ( m_fill != nullptr && !force_computation){
        return m_fill;
    }

    m_fill = new std::vector<MppPoint2D*>(this->size(), nullptr);
    int row = -1;
    MppSilhouette1D *line_ptr;
    int y_in, y_out;
    for (int i = 0 ; i < m_lines.size() ; i++){
        line_ptr = m_lines[i];
        for (int j = 0 ; j < line_ptr->pairs() ; j++){
            y_in = line_ptr->pair_in_y(j);
            y_out = line_ptr->pair_out_y(j);
            if (y_in == y_out){
                row ++;
                (*m_fill)[row] = new MppPoint2D(line_ptr->x(), y_in);
            }    
            else{
                for (int y = y_in ; y <= y_out ; y++ ){
                    row ++;   
                    (*m_fill)[row] = new MppPoint2D(line_ptr->x(), y); 
                }
            }
        }
    }
    return m_fill;
}

void MppSilhouette2D::print(){
    MppSilhouette1D *line;
    for (int i = 0 ; i < m_lines.size() ; i++){
        line = m_lines[i];
        std::cout << "x:" << line->x();
        for (int j = 0 ; j < line->pairs() ; j++){
            std::cout << " (" << line->pair_in_y(j) << "," << line->pair_out_y(j) << ")";
        }
        std::cout << std::endl;
    }
}