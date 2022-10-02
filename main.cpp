#include <iostream>
#include <string.h>

#include "Rotator.h"
using namespace std;

int main(int argc, char** argv){

    string input = argv[1];
    string output = argv[2];
    string options = argv[3];
    string degree = argv[4];
    
    Rotator *r = r->getInstance(input,output);
    r->rotate(options,degree);  

    return 0;
}