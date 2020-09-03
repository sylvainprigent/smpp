#include <iostream>

#include <mpp>
#include <simageio>

int main(int argc, char *argv[])
{
    try
    {
        std::cout << "Hello MPP" << std::endl;

        SImageFloat* image = dynamic_cast<SImageFloat*>(SImageReader::read("/Users/sprigent/Documents/MATLAB/syntetic_tracking/tracks1/track1_t003.tif"));
        SImageUInt* mask = dynamic_cast<SImageUInt*>(SImageReader::read("/Users/sprigent/Documents/MATLAB/syntetic_tracking/tracks1/track1_t003_mask.tif"));
        std::cout << "image size = " << image->sx() << ", " << image->sy() << std::endl;
        std::cout << "mask size = " << mask->sx() << ", " << mask->sy() << std::endl;

        float threshold = 9;
        unsigned int min_r = 4;
        unsigned int max_r = 4;
        int n_iter = 100000;

        MppImageFloat* mpp_image = new MppImageFloat(image->buffer(), image->sx(), image->sy());
        MppDataTerm2DBhattacharyya* data_term = new MppDataTerm2DBhattacharyya(mpp_image, threshold);
        MppInteraction2DNoOverlap* interaction = new MppInteraction2DNoOverlap();
        MppDictionary2DCircle* dictionary = new MppDictionary2DCircle(min_r, max_r);
        MppAlgorithm2DSBCR* algo = new MppAlgorithm2DSBCR(data_term, interaction, dictionary);
        MppImageUInt* mpp_mask = new MppImageUInt(mask->buffer(), mask->sx(), mask->sy());
        algo->set_birth_mask(mpp_mask);
        algo->set_n_iter(n_iter);
        algo->run();
        std::vector<MppShape2D*> shapes = algo->shapes();

        std::cout << "main got " << shapes.size() << "shapes" << std::endl;

        MppDraw2D drawer(mpp_image);
        MppImageUInt* mpp_out_image = drawer.run(shapes);
        SImageUInt* out_image = new SImageUInt(mpp_out_image->buffer(), mpp_out_image->sx(), mpp_out_image->sy(), 1, 1, 3);
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
