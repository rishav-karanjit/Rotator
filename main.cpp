#include <iostream>
#include <string.h>
#include <vector>
#include <fstream>
#include "ppm.h"
using namespace std;

string getExtension(string filename){
    //store the position of last '.' in the file name
    int position=file_name.find_last_of(".");
  
    //store the characters after the '.' from the file_name string
    string result = file_name.substr(position+1);
}

void checkExtension(string ipextension){
    if(ipextension != "ppm" || ipextension != "pgm"){
        cout<<"Incorrect file input";
        exit(-1);
    }
}

void checkOptions(string option){
    if(option[0] != '-' || !(option[1] == 'l' || option[1] == r)){
        cout<<"Incorrect option"<<endl;
        cout<<"Posible options:"<<endl;
        cout<<"-r : rotate right"<<endl;
        cout<<"-l : rotate left"<<endl<<endl;
        exit(-1); 
    }
}

void checkDegree(string degree){
    if(degree != "90" || degree != "180" || degree != "270"){
        cout<<"Invalid degree of rotation input"<<endl;
        cout<<"Available rotation degree is 90, 180 or 270"<<endl;
        exit(-1);
    }
}

// Main() function: where the execution of program begins
int main(int argc, char** argv)
{
    for (int i = 1; i < argc; ++i)
        cout << argv[i] << "\n";
    string input = argv[1];

    string ipExtension = getExtension(input);
    checkExtension(ipExtension);

    string output = argv[2];
    string opExtension = getExtension(output);

    if(ipExtension != opExtension){
        cout<<"Input and Output files extension does not match";
        return -1;
    }

    string options = argv[3];
    checkOptions(options);

    string degree = argv[4];
    checkDegree(degree);

    ppm test("cats_chips.ppm");
    
    
    test.rotateR90();

    return 0;
}