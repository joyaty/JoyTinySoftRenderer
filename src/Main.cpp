
#include <iostream>
#include "math/vec.h"

int main(int args_count, char** args)
{
    std::cout << "Hello, JoyTinySoftRenderer!" << std::endl;

    Joy::Vec<4> vec;
    vec[0] = 3;
    vec[1] = 4;
    vec[2] = 0;
    vec[3] = 0;

    std::cout << vec.Norm() << ", " << vec.SqrNorm() << std::endl;
    return 0;
}