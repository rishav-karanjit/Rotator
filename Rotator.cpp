#include <iostream>
#include "Rotator.h"
#include "ppm.h"
#include "pgm.h"

using namespace std;

Rotator *Rotator::instance = 0;


string Rotator::getExtension(string filename){
    //store the position of last '.' in the file name
    int position=filename.find_last_of(".");
  
    //store the characters after the '.' from the file_name string
    string result = filename.substr(position+1);

    return result;
}

void Rotator::checkExtension(string ipextension){
    if(!(ipextension == "ppm" || ipextension == "pgm")){
        cout<<"Incorrect file input";
        exit(-1);
    }
}

void Rotator::init(string ip,string op){
   string ipExtension = getExtension(ip);
   checkExtension(ipExtension);
   input = ip;

   string opExtension = getExtension(op);

   if(ipExtension != opExtension){
      cout<<"Input and Output files extension does not match";
      exit(-1);
   }
   output = op;
}

void Rotator::checkOptions(string option){
    if(option[0] != '-' || !(option[1] == 'l' || option[1] == 'r')){
        cout<<"Incorrect option"<<endl;
        cout<<"Posible options:"<<endl;
        cout<<"-r : rotate right"<<endl;
        cout<<"-l : rotate left"<<endl<<endl;
        exit(-1); 
    }
}

void Rotator::checkDegree(string degree){
    if(!(degree == "90" || degree == "180" || degree == "270")){
        cout<<"Invalid degree of rotation input"<<endl;
        cout<<"Available rotation degree is 90, 180 or 270"<<endl;
        exit(-1);
    }
}

int Rotator::getDegreeOfRotation(string degreeWord,string option){
    int degree = stoi(degreeWord);
    if(option[1] == 'r')
        return degree;
    return(360 - degree);
}

void Rotator::rotate(string option, string degree){
   checkOptions(option);
   checkDegree(degree);
   int DegreeOfRotation = getDegreeOfRotation(degree,option);

   if(getExtension(input) == "ppm"){
        ppm test(input);
        test.rotateR90(output,DegreeOfRotation);
    }
    else{
        pgm test(input);
        test.rotateR90(output,DegreeOfRotation);
    }
}