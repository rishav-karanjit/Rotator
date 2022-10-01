#include <iostream>
#include <string.h>
#include <vector>
#include <fstream>
#include "ppm.h"
using namespace std;

// Main() function: where the execution of program begins
int main(int argc, char** argv)
{
    for (int i = 1; i < argc; ++i)
        cout << argv[i] << "\n";
    ppm test("cats_chips.ppm");
    
    test.rotateR90();
    // string fname = "tst.ppm";
    // ofstream inp(fname, std::ios::out | std::ios::binary);

    return 0;
}