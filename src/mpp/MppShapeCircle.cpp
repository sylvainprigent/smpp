/// \file MppShapeCircle.cpp
/// \brief MppShapeCircle class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2020

#include "MppShapeCircle.h"
#include <iostream>
#include <algorithm>

MppShapeCircle::MppShapeCircle(){

}

MppShapeCircle::MppShapeCircle(int x, int y, int r){
    m_x = x;
    m_y = y;
    m_r = r;
}

MppShapeCircle::~MppShapeCircle(){
    delete m_silhouette;
}

void MppShapeCircle::set_x(const int & x){
    m_x = x;
}

void MppShapeCircle::set_y(const int & y){
    m_y = y;
}

void MppShapeCircle::set_r(const int & r){
    m_r = r;
}

int MppShapeCircle::x(){
    return m_x;
}

int MppShapeCircle::y(){
    return m_y;
}

int MppShapeCircle::r(){
    return m_r;
}

MppShape2D* MppShapeCircle::copy(){
    return new MppShapeCircle(m_x, m_y, m_r);
}

void MppShapeCircle::translate(int x, int y){
    m_x += x;
    m_y += y;
}

bool mppShapeCircleSortPixels(MppPoint2D i, MppPoint2D j){
    return ( i.x() < j.x() );
}

MppSilhouette2D* MppShapeCircle::computeSilhouette(){

    std::vector<MppPoint2D> contour = compute_circle_coordinates(m_x, m_y, m_r);
    std::sort(contour.begin(), contour.end(), mppShapeCircleSortPixels);

    int area = 0;
    m_silhouette = new MppSilhouette2D();
    std::vector<bool> alreadyUse; alreadyUse.resize(contour.size());
    for (int i = 0 ; i < alreadyUse.size() ; ++i){
        alreadyUse[i] = false;
    }
    std::vector<int> pos;
    int x; int y1, y2, yt;
    for (int i = 0 ; i < contour.size() ; ++i){
        if (!alreadyUse[i]){
            x = contour[i].x();
            pos.clear();
            for (int j = i ; j < contour.size() ; ++j){
                if (contour[j].x() == x){
                    pos.push_back(j);
                }
            }
            y1 = contour[pos[0]].y();
            y2 = contour[pos[0]].y();
            for (int m = 1 ; m < pos.size() ; ++m){
                if (contour[pos[m] ].y() > y2){
                    y2 = contour[pos[m] ].y();
                }
                if (contour[pos[m] ].y() < y1){
                    y1 = contour[pos[m] ].y();
                }
            }
            if (pos.size() > 1){
                if (y1 > y2){
                    yt = y2;
                    y2 = y1;
                    y1 = yt;
                }
                m_silhouette->add_line(x, y1, y2);
                area += abs(y1 - y2) +1;
                for (int k = 0 ; k < pos.size() ; ++k){
                    alreadyUse[ pos[k] ] = true;
                }
            }
            else{
                m_silhouette->add_line(x, contour[i].y(), contour[i].y());
                area++;
            }
            alreadyUse[i] = true;
        }
    }
    m_size = area;
    m_silhouette->set_size(area);
    return m_silhouette;
}

std::vector<MppPoint2D> compute_circle_coordinates(int x_center, int y_center, int radius){

    std::vector<MppPoint2D> coords;
    int x = 0;
    int y = radius;
    int d = radius - 1;
    while (y >= x){
        if (x == 0){
            coords.push_back(MppPoint2D(x_center + x, y_center + y));
            coords.push_back(MppPoint2D(x_center + y, y_center + x));
            coords.push_back(MppPoint2D(x_center - y, y_center + x));
            coords.push_back(MppPoint2D(x_center + x, y_center - y));
        }
        else if (y == 0){
            coords.push_back(MppPoint2D(x_center + x, y_center));
            coords.push_back(MppPoint2D(x_center, y_center + x));
            coords.push_back(MppPoint2D(x_center - x, y_center));
            coords.push_back(MppPoint2D(x_center, y_center - x));
        }
        else if (x == y){
            coords.push_back(MppPoint2D(x_center + x, y_center + x));
            coords.push_back(MppPoint2D(x_center - x, y_center + x));
            coords.push_back(MppPoint2D(x_center + x, y_center - x));
            coords.push_back(MppPoint2D(x_center - x, y_center - x));
        }
        else{
            coords.push_back(MppPoint2D(x_center + x, y_center + y));
            coords.push_back(MppPoint2D(x_center + y, y_center + x));
            coords.push_back(MppPoint2D(x_center - x, y_center + y));
            coords.push_back(MppPoint2D(x_center - y, y_center + x));
            coords.push_back(MppPoint2D(x_center + x, y_center - y));
            coords.push_back(MppPoint2D(x_center + y, y_center - x));
            coords.push_back(MppPoint2D(x_center - x, y_center - y));
            coords.push_back(MppPoint2D(x_center - y, y_center - x));
        }

        if (d >= 2 * x){
            d = d-2 * x-1;
            x = x+1;
        }   
        else if (d <= 2 * (radius-y)){
            d = d+2 * y-1;
            y = y-1;
        }
        else{
            d = d+2 * (y-x-1);
            y = y-1;
            x = x+1;
        }
    }
    return coords;
}
