#include <iostream>
#include <fstream>
#include <sstream>
#include <exception>
#include <string>

#include "pgm.h"
using namespace std;
//init with default values

void pgm::init() {
    width = 0;
    height = 0;
    max_col_val = 255;

    grey_raw.clear();

    grey.clear();
}

//create a pgm object

pgm::pgm() {
    fname = "input.pgm";
    init();
}

//create a pgm object and fill it with data stored in fname 

pgm::pgm(const std::string &fname) {
    init();
    this->fname = fname;
    read();
}

//create an "epmty" pgm image with a given width and height;the grey,G,B arrays are filled with zeros

pgm::pgm(const unsigned int _width, const unsigned int _height) {
    init();
    width = _width;
    height = _height;
    nr_lines = height;
    nr_columns = width;
    size = width*height;

    // fill grey, g and b with 0
    grey.resize(size);

    grey_raw.resize(size);
}


//read the pgm image from fname
void pgm::read(){
    std::ifstream inp(fname.c_str(), std::ios::in);

    if(inp.is_open()){
        std::string line;
        std::getline(inp, line);
        ftype = line;
        if (line.compare("P2") || line.compare("P5")) {
            if(line == "P2")
                readp2();
            else
                readp5();

        }
        else{
            std::cout << "Error. Unrecognized file format." << std::endl;
            return;
        }
    }

}

//read the pgm image from fname

void pgm::readp5() {
    std::ifstream inp(fname.c_str(), std::ios::in | std::ios::binary);

    if (inp.is_open()) {
        std::string line;
        std::getline(inp, line);
        // if (line != "P6") {
        //     std::cout << "Error. Unrecognized file format." << std::endl;
        //     return;
        // }
        std::getline(inp, line);
        while (line[0] == '#') {
            std::getline(inp, line);
        }
        std::stringstream dimensions(line);

        try {
            dimensions >> width;
            dimensions >> height;
            nr_lines = height;
            nr_columns = width;
        } catch (std::exception &e) {
            std::cout << "Header file format error. " << e.what() << std::endl;
            return;
        }

        std::getline(inp, line);
        std::stringstream max_val(line);
        try {
            max_val >> max_col_val;
        } catch (std::exception &e) {
            std::cout << "Header file format error. " << e.what() << std::endl;
            return;
        }

        size = width*height;

        grey.reserve(size);

        char aux;
        for (unsigned int i = 0; i < size; ++i) {
            inp.read(&aux, 1);
            grey.push_back((unsigned char) aux);
        }
    } else {
        std::cout << "Error. Unable to open " << fname << std::endl;
    }
    inp.close();
}

void pgm::readp2() {
    std::ifstream inp(fname.c_str(), std::ios::in);

    if (inp.is_open()) {
        std::string line;
        std::getline(inp, line);
        ftype = line;

        std::getline(inp, line);
        while (line[0] == '#') {
            std::getline(inp, line);
        }
        std::stringstream dimensions(line);

        try {
            dimensions >> width;
            dimensions >> height;
            nr_lines = height;
            nr_columns = width;
        } catch (std::exception &e) {
            std::cout << "Header file format error. " << e.what() << std::endl;
            return;
        }

        std::getline(inp, line);
        std::stringstream max_val(line);
        try {
            max_val >> max_col_val;
        } catch (std::exception &e) {
            std::cout << "Header file format error. " << e.what() << std::endl;
            return;
        }

        size = width*height;

        grey_raw.reserve(size);

        string aux;
        for (unsigned int i = 0; i < size; ++i) {
            inp >> aux;
            grey_raw.push_back(aux);
        }
    } else {
        std::cout << "Error. Unable to open " << fname << std::endl;
    }
    inp.close();
}
void pgm::rotateR90(string output,int DegreeOfRotation){
     
    if(ftype == "P5")
        rotateR90P5(output);
    else
        rotateR90P2(output);

    DegreeOfRotation -= 90;

    string file;
    for(int i = DegreeOfRotation; i > 0; i -= 90){
        
        file = output;
        init();
        this->fname = file;
        read();
        cout<<fname;
        if(ftype == "P5")
            rotateR90P5(output);
        else
            rotateR90P2(output);
    }

}
void pgm::rotateR90P2(string output){
    unsigned int start = size - width;
    unsigned int curr = 0;
    std::vector<string> grey_new(size," ");
    
    //std::string r_new[size],g_new[size],b_new[size];
    // r_new.reserve(size);
    // g_new.reserve(size);
    // b_new.reserve(size);

    
    while(start < size){

        int i = start;
        
        while(i >= 0){

            grey_new[curr] = grey_raw[i];        
            
            curr++;
            i = i - width;

        }
        start++;
    }

    string fname = output;
    ofstream inp(fname, std::ios::out );

    //| std::ios::binary
    
    if (inp.is_open()) {
        inp << "P2\n";
        inp << height;
        inp << " ";
        inp << width << "\n";
        inp << max_col_val << "\n";

        string aux;

        
        // for (unsigned int i = 0; i < size; ++i) {
            
        //     aux = r_new[i];
        //     inp.write(&aux, 1);
        //     aux = g_new[i];
        //     inp.write(&aux, 1);
        //     aux = b_new[i];
        //     inp.write(&aux, 1);
        // }
        for (unsigned int i = 0; i < size; ++i) {
            aux = grey_new[i];
            inp<<aux<<endl;
        }

    } else {
        cout << "Error. Unable to open " << fname << std::endl;
    }
    
    inp.close();
    grey_new.clear();

}

void pgm::rotateR90P5(string output){
    
    unsigned int start = size - width;
    unsigned int curr = 0;
    std::vector<unsigned char> grey_new;
    grey_new.reserve(size);

    while(start < size){

        int i = start;
        
        while(i >= 0){
            grey_new[curr] = grey[i];        

                  
            curr++;
            i = i - width;

        }
        start++;
    }

    string fname = output;
    ofstream inp(fname, std::ios::out | std::ios::binary);
    
    if (inp.is_open()) {
        inp << "P5\n";
        inp << height;
        inp << " ";
        inp << width << "\n";
        inp << max_col_val << "\n";

        char aux;

        
        for (unsigned int i = 0; i < size; ++i) {
            
            aux = (char) grey_new[i];
            inp.write(&aux, 1);
        }

    } else {
        cout << "Error. Unable to open " << fname << std::endl;
    }
    
    inp.close();
}