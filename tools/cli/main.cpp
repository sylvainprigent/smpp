#include <iostream>

#include <mpp>
#include <simageio>

int main(int argc, char *argv[])
{

    try
    {
        std::cout << "Hello MPP" << std::endl;

        SImage* image = SImageReader::read("/Users/sprigent/Documents/code/simageio/tests/simageio/imagesTest/celegans.tif");
        std::cout << "image size = " << image->sx() << ", " << image->sy() << std::endl;
        return 0;
    }
    catch (std::exception &e)
    {
        //sciLogAccess::instance()->log(e.what());
        return 1;
    }


    return 0;

}
