#include <iostream>

#include <smpp>
#include <simageio>

int main(int argc, char *argv[])
{
    try
    {
        std::cout << "Hello MPP" << std::endl;

        SImageFloat* image = dynamic_cast<SImageFloat*>(SImageReader::read("/Users/sprigent/Documents/MATLAB/syntetic_tracking/tracks1/track1_t003.tif"));
        SImageUInt* mask = dynamic_cast<SImageUInt*>(SImageReader::read("/Users/sprigent/Documents/MATLAB/syntetic_tracking/tracks1/track1_t003_mask.tif", 8));
        std::cout << "image size = " << image->getSizeX() << ", " << image->getSizeY() << std::endl;
        std::cout << "mask size = " << mask->getSizeX() << ", " << mask->getSizeY() << std::endl;

        float threshold = 9;
        unsigned int min_r = 4;
        unsigned int max_r = 4;
        int n_iter = 100000;

        MppDataTerm2DBhattacharyya* data_term = new MppDataTerm2DBhattacharyya(image, threshold);
        MppInteraction2DNoOverlap* interaction = new MppInteraction2DNoOverlap();
        MppDictionary2DCircle* dictionary = new MppDictionary2DCircle(min_r, max_r);
        MppAlgorithm2DSBCR* algo = new MppAlgorithm2DSBCR(data_term, interaction, dictionary);
        algo->set_birth_mask(mask);
        algo->set_n_iter(n_iter);
        algo->run();
        std::vector<MppShape2D*> shapes = algo->shapes();

        std::cout << "main got " << shapes.size() << "shapes" << std::endl;

        MppDraw2D drawer(image);
        SImageUInt* out_image = drawer.run(shapes);
        std::cout << "save image representation " << std::endl;
        SImageReader::write(out_image, "/Users/sprigent/Documents/code/mpp_track1_t003.tif");

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
