#include <vector>
#include <iostream>

#include <mpp/MppPoint.h>
#include <mpp/MppSilhouette2D.h>


bool assert_point_list_equals(std::vector<MppPoint2D*>* l1, std::vector<MppPoint2D*>* l2){

    if (l1->size() != l2->size()){
        return false;
    }
    for (int i = 0 ; i < l1->size() ; i++){
        if ((*l1)[i]->x() != (*l2)[i]->x() ||
            (*l1)[i]->y() != (*l2)[i]->y() ){
            return false;
        }
    }
    return true;
}

int main(int argc, char* argv[])
{ 
    // Create a silhouette 2D
    MppSilhouette2D* silhouette = new MppSilhouette2D();
    silhouette->add_line(-2, -1, 1);
    silhouette->add_line(-1, -2, 2);
    silhouette->add_line(0, -2, 2);
    silhouette->add_line(1, -2, 2);
    silhouette->add_line(2, -1, 1);

    

    // bounding box
    int* ref_box = new int[4];
    ref_box[0] = -2;
    ref_box[1] = 2;
    ref_box[2] = -2;
    ref_box[3] = 2;

    int* box = silhouette->bounding_box();

    std::cout << "silhouette box = " << std::endl;
    for (int i = 0 ; i < 4 ; i++){
        std::cout << "box[" << i <<  "] = " << box[i] << std::endl;
    }

    if(box[0] != ref_box[0] || 
       box[1] != ref_box[1] || 
       box[2] != ref_box[2] ||
       box[3] != ref_box[3]){
        return 1;     
    }

    // size
    if (silhouette->size() != 21){
        return 1;
    }   

    // fill
    std::vector<MppPoint2D*> *ref_fill = new std::vector<MppPoint2D*>(21);
    (*ref_fill)[0] = new MppPoint2D(-2, -1);
    (*ref_fill)[1] = new MppPoint2D(-2, 0);
    (*ref_fill)[2] = new MppPoint2D(-2, 1);
    (*ref_fill)[3] = new MppPoint2D(-1, -2);
    (*ref_fill)[4] = new MppPoint2D(-1, -1);
    (*ref_fill)[5] = new MppPoint2D(-1, 0);
    (*ref_fill)[6] = new MppPoint2D(-1, 1);
    (*ref_fill)[7] = new MppPoint2D(-1, 2);
    (*ref_fill)[8] = new MppPoint2D(0, -2);
    (*ref_fill)[9] = new MppPoint2D(0, -1);
    (*ref_fill)[10] = new MppPoint2D(0, 0);
    (*ref_fill)[11] = new MppPoint2D(0, 1);
    (*ref_fill)[12] = new MppPoint2D(0, 2);
    (*ref_fill)[13] = new MppPoint2D(1, -2);
    (*ref_fill)[14] = new MppPoint2D(1, -1);
    (*ref_fill)[15] = new MppPoint2D(1, 0);
    (*ref_fill)[16] = new MppPoint2D(1, 1);
    (*ref_fill)[17] = new MppPoint2D(1, 2);
    (*ref_fill)[18] = new MppPoint2D(2, -1);
    (*ref_fill)[19] = new MppPoint2D(2, 0);
    (*ref_fill)[20] = new MppPoint2D(2, 1);

    if (!assert_point_list_equals(ref_fill, silhouette->fill())){
        return 1;
    }

    // contour
    std::vector<MppPoint2D*> *ref_contour = new std::vector<MppPoint2D*>(16);
    (*ref_contour)[0] = new MppPoint2D(-3, -1);
    (*ref_contour)[1] = new MppPoint2D(-3, 0);
    (*ref_contour)[2] = new MppPoint2D(-3, 1);
    (*ref_contour)[3] = new MppPoint2D(-2, -2);
    (*ref_contour)[4] = new MppPoint2D(-2, 2);
    (*ref_contour)[5] = new MppPoint2D(-1, -3);
    (*ref_contour)[6] = new MppPoint2D(-1, 3);
    (*ref_contour)[7] = new MppPoint2D(0, -3);
    (*ref_contour)[8] = new MppPoint2D(0, 3);
    (*ref_contour)[9] = new MppPoint2D(1, -3);
    (*ref_contour)[10] = new MppPoint2D(1, 3);
    (*ref_contour)[11] = new MppPoint2D(2, -2);
    (*ref_contour)[12] = new MppPoint2D(2, 2);
    (*ref_contour)[13] = new MppPoint2D(3, -1);
    (*ref_contour)[14] = new MppPoint2D(3, 0);
    (*ref_contour)[15] = new MppPoint2D(3, 1);

    if (!assert_point_list_equals(ref_contour, silhouette->contour())){
        return 1;
    }

    // delete
    for (int i = 0 ; i < ref_fill->size() ; i++){
        delete (*ref_fill)[i];
    }
    delete ref_fill;
    for (int i = 0 ; i < ref_contour->size() ; i++){
        delete (*ref_contour)[i];
    }
    delete ref_contour;
    delete silhouette;
    return 0;
}
