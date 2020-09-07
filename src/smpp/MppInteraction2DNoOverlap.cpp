/// \file MppInteraction2DNoOverlap.cpp
/// \brief MppInteraction2DNoOverlap class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2018

#include "math.h"
#include <iostream>

#include "MppInteraction2DNoOverlap.h"
#include "MppShapeCircle.h"

MppInteraction2DNoOverlap::MppInteraction2DNoOverlap(){
    m_percentage = 0.0;
}

MppInteraction2DNoOverlap::MppInteraction2DNoOverlap(float percentage){
    m_percentage = percentage;
}

MppInteraction2DNoOverlap::~MppInteraction2DNoOverlap(){
    
}

float MppInteraction2DNoOverlap::run(MppShape2D* shape1, int x1, int y1, MppShape2D* shape2, int x2, int y2){

    if (dynamic_cast<MppShapeCircle*>(shape1) && dynamic_cast<MppShapeCircle*>(shape2)){

        if (pow(x1-x2,2)+pow(y1-y2,2) <= pow(dynamic_cast<MppShapeCircle*>(shape1)->r()+dynamic_cast<MppShapeCircle*>(shape2)->r()+1,2)){
            return -10;
        }
        return 0;
    }

    std::cout << "shapes are not recoginzed as circle" << std::endl;

    if (is_overlapping_2d(shape1->silhouette(), x1, y1, shape2->silhouette(), x2, y2, m_percentage)){
        return -10;
    }
    else{
        return 0;
    }
}
    
void findFirstCommonLine(MppSilhouette2D* silhouette1, int x1, MppSilhouette2D* silhouette2, int x2, int &m, int &n)
{
    int x_min = silhouette1->line(0)->x() + x1;
    int x_max = silhouette1->line(silhouette1->count_lines()-1)->x() + x1;

    int xp_min = silhouette2->line(0)->x() + x2;
    int xp_max = silhouette2->line(silhouette1->count_lines()-1)->x() + x2;

    if (x_min >= xp_min && x_min <=xp_max){
        m = 0;
        n = x_min - xp_min;
    }
    else if (xp_min >= x_min && xp_min <=x_max){
        m = xp_min - x_min;
        n = 0;
    }
}    

bool is_overlapping_2d(MppSilhouette2D* silhouette1, int x1, int y1, MppSilhouette2D* silhouette2, int x2, int y2, float allowedPurcentage)
{
    if (allowedPurcentage == 0){
        // find the first common line x
        int m = -1; int n = -1;
        findFirstCommonLine(silhouette1, x1, silhouette2, x2, m, n);

        if (m == -1){
            return false;
        }

        // compare objects line by line
        MppSilhouette1D *s1_line;
        MppSilhouette1D *s2_line;
        while(1){
            s1_line = silhouette1->line(m);
            s2_line = silhouette2->line(n);
            for (int i = 0 ; i < s1_line->pairs() ; ++i){
                for (int j = 0 ;j < s2_line->pairs() ; ++j){
                    float y1 = s1_line->pair_in_y(i) + y1;
                    float y2 = s1_line->pair_out_y(i) + y1;
                    float yp1 = s2_line->pair_in_y(i) + y2;
                    float yp2 = s2_line->pair_out_y(i) + y2;

                    if (y2 < yp1){
                        continue;
                    }
                    if (yp2 < y1){
                        continue;
                    }
                    if ( y2 >= yp1 && y2 <= yp2){
                        return true;
                    }
                    if (yp2 >= y1 && yp2 <= y2){
                        return true;
                    }
                }
            }
            m++; if (m >= silhouette1->count_lines()){return false;}
            n++; if (n >= silhouette2->count_lines()){return false;}
            if (silhouette1->line(m)->x() + x1 != silhouette2->line(m)->x() + x2){
                return false;
            }
        }
    }
    else{
        if (percentage_overlapping_2d(silhouette1, x1, y1, silhouette2, x2, y2) > allowedPurcentage){
            return true;
        }
        else{
            return false;
        }
    }        
}

float percentage_overlapping_2d(MppSilhouette2D* silhouette1, int x1, int y1, MppSilhouette2D* silhouette2, int x2, int y2)
{
    // find the first common line x
    int m = -1; int n = -1;
    findFirstCommonLine(silhouette1, x1, silhouette2, x2, m, n);

    if (m == -1){
        return 0; 
    }

    // compare objects line by line
    int overlapArea = 0;
    float area = silhouette1->size();
    if (silhouette2->size() < area){
        area = silhouette2->size();
    }
    MppSilhouette1D *s1_line;
    MppSilhouette1D *s2_line;
    while(1){
        s1_line = silhouette1->line(m);
        s2_line = silhouette2->line(n);
        for (int i = 0 ; i < s1_line->pairs() ; ++i){
            for (int j = 0 ;j < s2_line->pairs() ; ++j){
                float y1 = s1_line->pair_in_y(i) + y1;
                float y2 = s1_line->pair_out_y(i) + y1;
                float yp1 = s2_line->pair_in_y(i) + y2;
                float yp2 = s2_line->pair_out_y(i) + y2;

                if (y2 < yp1){
                    continue;
                }
                if (yp2 < y1){
                    continue;
                }
                if ( y2 >= yp1 && y2 <= yp2){
                    if (y1 <= yp1)
                        overlapArea += y2 - yp1 + 1;
                    else
                        overlapArea += yp2 - yp1 + 1;
                }
                if (yp2 >= y1 && yp2 <= y2){
                    if (yp1 <= y1)
                        overlapArea += yp2 - y1 + 1;
                    else
                        overlapArea += y2 - y1 + 1;
                }
            }
        }
        m++; if (m >= silhouette1->count_lines()){return float(overlapArea)/area;}
        n++; if (n >= silhouette2->count_lines()){return float(overlapArea)/area;}
        if (silhouette1->line(m)->x() + x1 != silhouette1->line(n)->x() + x2){
            return float(overlapArea)/area;
        }
    }
}