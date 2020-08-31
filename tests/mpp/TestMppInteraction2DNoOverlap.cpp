#include <vector>
#include <iostream>

#include <mpp/MppShapeCircle.h>
#include <mpp/MppInteraction2DNoOverlap.h>

int main(int argc, char* argv[])
{ 

    MppShapeCircle* circle1 = new MppShapeCircle(0, 0, 2);
    MppShapeCircle* circle2 = new MppShapeCircle(0, 0, 3);
    MppShapeCircle* circle3 = new MppShapeCircle(0, 0, 5);

    //candidate1 = ShapeCandidate2D(circle1, x=5, y=5)
    //candidate2 = ShapeCandidate2D(circle2, x=10, y=10)
    //candidate3 = ShapeCandidate2D(circle3, x=12, y=12)

    MppInteraction2DNoOverlap interaction(0);
    // no overlap
    if (interaction.run(circle1, 5, 5, circle2, 11, 11) != 0){
        std::cout << "error circle1-circle2" << std::endl;
        return 1;
    }
    // overlap
    if (interaction.run(circle2, 10, 10, circle3, 12, 12) != -10){
        std::cout << "error circle2-circle3" << std::endl;
        return 1;
    }

    return 0;

}