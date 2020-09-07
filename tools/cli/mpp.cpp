#include <iostream>

#include <smpp>
#include <simageio>
#include <scmd>

int main(int argc, char *argv[])
{
    try
    {
        SCmdParser cmdParser(argc, argv);
        cmdParser.addInputData("-i", "Input image file");
        cmdParser.addOutputData("-o", "Output image file");
        cmdParser.addOutputData("-m", "Birth mask image file");

        cmdParser.addParameterInt("-rmin", "Minimum circle radius", 2);
        cmdParser.addParameterInt("-rmax", "Maximum circle radius", 5);
        cmdParser.addParameterFloat("-threshold", "Dataterm threshold", 5);
        cmdParser.addParameterInt("-niter", "Number of iteration", 100000);

        cmdParser.parse(2);


        std::string inputImageFile = cmdParser.getDataURI("-i");
        std::string outputImageFile = cmdParser.getDataURI("-o");
        std::string maskImageFile = cmdParser.getDataURI("-m");

        const int rmin = cmdParser.getParameterInt("-rmin");
        const int rmax = cmdParser.getParameterInt("-rmax");
        const float threshold = cmdParser.getParameterFloat("-threshold");
        const int n_iter = cmdParser.getParameterInt("-niter");

        if (inputImageFile == ""){
            std::cout << "mpp: Input image path is empty" << std::endl;
            return 1;
        }

        SImageFloat* image = dynamic_cast<SImageFloat*>(SImageReader::read(inputImageFile));

        std::cout << "image size = " << image->sx() << ", " << image->sy() << std::endl;

        MppImageFloat* mpp_image = new MppImageFloat(image->buffer(), image->sx(), image->sy());
        MppDataTerm2DBhattacharyya* data_term = new MppDataTerm2DBhattacharyya(mpp_image, threshold);
        MppInteraction2DNoOverlap* interaction = new MppInteraction2DNoOverlap();
        MppDictionary2DCircle* dictionary = new MppDictionary2DCircle(rmin, rmax);
        MppAlgorithm2DSBCR* algo = new MppAlgorithm2DSBCR(data_term, interaction, dictionary);
        SImageUInt* mask = nullptr;
        MppImageUInt* mpp_mask = nullptr;
        if (maskImageFile != ""){
            mask = dynamic_cast<SImageUInt*>(SImageReader::read(maskImageFile, 8));
            mpp_mask = new MppImageUInt(mask->buffer(), mask->sx(), mask->sy());
            std::cout << "mask size = " << mask->sx() << ", " << mask->sy() << std::endl;
            algo->set_birth_mask(mpp_mask);
        }
        algo->set_n_iter(n_iter);
        algo->run();
        std::vector<MppShape2D*> shapes = algo->shapes();

        std::cout << "main got " << shapes.size() << "shapes" << std::endl;

        MppDraw2D drawer(mpp_image);
        MppImageUInt* mpp_out_image = drawer.run(shapes);
        SImageUInt* out_image = new SImageUInt(mpp_out_image->buffer(), mpp_out_image->sx(), mpp_out_image->sy(), 1, 1, 3);
        std::cout << "save image representation " << std::endl;
        SImageReader::write(out_image, outputImageFile);

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
    catch (SCmdException &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (std::exception &e)
    {
        //sciLogAccess::instance()->log(e.what());
        return 1;
    }

    return 0;

}
