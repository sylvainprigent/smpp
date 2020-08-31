#include <iostream>

#include <mpp>

int main(int argc, char *argv[])
{

    try
    {
        std::cout << "Hello MPP" << std::endl;

    }
    catch (std::exception &e)
    {
        //sciLogAccess::instance()->log(e.what());
        return 1;
    }


    return 0;

}
