
#include <cstdio>
#include <iostream>
#include "math/Mat.hpp"

int main(int args_count, char** args)
{
    std::cout << "Hello, JoyTinySoftRenderer!" << std::endl;

    Joy::Mat<4, 4> mat = Joy::Mat<4, 4>::Identity();

    return 0;
}