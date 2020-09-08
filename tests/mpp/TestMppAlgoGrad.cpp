#include <iostream>

#include <smpp>
#include <simageio>

#include "smppTestConfig.h"

int main(int argc, char *argv[])
{
    try
    {
        std::cout << "Hello MPP grad" << std::endl;

        SImageFloat* image = dynamic_cast<SImageFloat*>(SImageReader::read(CELL));
        SImageUInt* mask = dynamic_cast<SImageUInt*>(SImageReader::read(CELLBM, 8));
        std::cout << "image size = " << image->getSizeX() << ", " << image->getSizeY() << std::endl;
        std::cout << "mask size = " << mask->getSizeX() << ", " << mask->getSizeY() << std::endl;

        float threshold = 4;
        unsigned int min_r = 8;
        unsigned int max_r = 10;
        int n_iter = 10000;

        //MppDataTerm2DGradient* data_term = new MppDataTerm2DGradient(image, threshold);
        MppDataTerm2DGradientNorm* data_term = new MppDataTerm2DGradientNorm(image, threshold);
        MppInteraction2DNoOverlap* interaction = new MppInteraction2DNoOverlap();
        MppDictionary2DCircle* dictionary = new MppDictionary2DCircle(min_r, max_r);
        MppAlgorithm2DSBCR* algo = new MppAlgorithm2DSBCR(data_term, interaction, dictionary);
        algo->set_birth_mask(mask);
        algo->set_n_iter(n_iter);
        algo->run();
        std::cout << "draw shapes" << std::endl;
        std::vector<MppShape2D*> shapes = algo->shapes();

        std::cout << "main got " << shapes.size() << "shapes" << std::endl;

        MppDraw2D drawer(image);
        SImageUInt* out_image = drawer.run(shapes);
        std::cout << "save image representation " << std::endl;
        SImageReader::write(out_image, "/home/sprigent/Documents/code/smpp/tests/mpp/imagesTest/res.tif");

        // delete
        delete image;
        delete data_term;
        delete interaction;
        delete dictionary;
        delete algo;
        for (int s = 0 ; s < shapes.size() ; s++){
            delete shapes[s];
        }
        delete out_image;
        return 0;
    }
    catch (std::exception &e)
    {
        //sciLogAccess::instance()->log(e.what());
        return 1;
    }

    return 0;

}
