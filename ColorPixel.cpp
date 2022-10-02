#include <iostream>
#include <fstream>
#include <sstream>
#include <exception>
#include <string>

#include "ColorPixel.h"
using namespace std;
//init with default values

void ColorPixel::init() {
    width = 0;
    height = 0;
    max_col_val = 255;

    r_raw.clear();
    g_raw.clear();
    b_raw.clear();

    r.clear();
    g.clear();
    b.clear();
}

//create a ColorPixel object

ColorPixel::ColorPixel() {
    fname = "input.ppm";
    init();
}

//create a ColorPixel object and fill it with data stored in fname 

ColorPixel::ColorPixel(const std::string &fname) {
    init();
    this->fname = fname;
    read();
}

//create an "epmty" ColorPixel image with a given width and height;the R,G,B arrays are filled with zeros

ColorPixel::ColorPixel(const unsigned int _width, const unsigned int _height) {
    init();
    width = _width;
    height = _height;
    nr_lines = height;
    nr_columns = width;
    size = width*height;

    // fill r, g and b with 0
    r.resize(size);
    g.resize(size);
    b.resize(size);

    r_raw.resize(size);
    g_raw.resize(size);
    b_raw.resize(size);
}


//read the ColorPixel image from fname
void ColorPixel::read(){
    std::ifstream inp(fname.c_str(), std::ios::in);

    if(inp.is_open()){
        std::string line;
        std::getline(inp, line);
        ftype = line;
        if (line.compare("P6") || line.compare("P3")) {
            if(line == "P3")
                readp3();
            else
                readp6();

        }
        else{
            std::cout << "Error. Unrecognized file format." << std::endl;
            return;
        }
    }

}

//read the ColorPixel image from fname

void ColorPixel::readp6() {
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

        r.reserve(size);
        g.reserve(size);
        b.reserve(size);

        char aux;
        for (unsigned int i = 0; i < size; ++i) {
            inp.read(&aux, 1);
            r.push_back((unsigned char) aux);
            inp.read(&aux, 1);
            g.push_back((unsigned char) aux);
            inp.read(&aux, 1);
            b.push_back((unsigned char) aux);
        }
    } else {
        std::cout << "Error. Unable to open " << fname << std::endl;
    }
    inp.close();
}

void ColorPixel::readp3() {
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

        r_raw.reserve(size);
        g_raw.reserve(size);
        b_raw.reserve(size);

        string aux;
        for (unsigned int i = 0; i < size; ++i) {
            inp >> aux;
            r_raw.push_back(aux);
            inp >>aux;
            g_raw.push_back(aux);
            inp >> aux;
            b_raw.push_back(aux);
        }
    } else {
        std::cout << "Error. Unable to open " << fname << std::endl;
    }
    inp.close();
}
void ColorPixel::rotateR90(string output,int DegreeOfRotation){
     
    if(ftype == "P3")
        rotateR90P3(output);
    else
        rotateR90P6(output);

    DegreeOfRotation -= 90;

    string file;
    for(int i = DegreeOfRotation; i > 0; i -= 90){
        
        file = output;
        init();
        this->fname = file;
        read();
        cout<<fname;
        if(ftype == "P3")
            rotateR90P3(output);
        else
            rotateR90P6(output);
    }

}
void ColorPixel::rotateR90P3(string output){
    unsigned int start = size - width;
    unsigned int curr = 0;
    std::vector<string> r_new(size," "),g_new(size," "),b_new(size," ");
    
    //std::string r_new[size],g_new[size],b_new[size];
    // r_new.reserve(size);
    // g_new.reserve(size);
    // b_new.reserve(size);

    
    while(start < size){

        int i = start;
        
        while(i >= 0){

            r_new[curr] = r_raw[i];        
            g_new[curr] = g_raw[i];
            b_new[curr] = b_raw[i];
            
            curr++;
            i = i - width;

        }
        start++;
    }

    string fname = output;
    ofstream inp(fname, std::ios::out );

    //| std::ios::binary
    
    if (inp.is_open()) {
        inp << "P3\n";
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
            aux = r_new[i];
            inp<<aux<<endl;
            aux = g_new[i];
            inp<<aux<<endl;
            aux = b_new[i];
            inp<<aux<<endl;
        }

    } else {
        cout << "Error. Unable to open " << fname << std::endl;
    }
    
    inp.close();
    r_new.clear();
    g_new.clear();
    b_new.clear();

}

void ColorPixel::rotateR90P6(string output){
    
    unsigned int start = size - width;
    unsigned int curr = 0;
    std::vector<unsigned char> r_new,g_new,b_new;
    r_new.reserve(size);
    g_new.reserve(size);
    b_new.reserve(size);

    while(start < size){

        int i = start;
        
        while(i >= 0){
            r_new[curr] = r[i];        
            g_new[curr] = g[i];
            b_new[curr] = b[i];
                  
            curr++;
            i = i - width;

        }
        start++;
    }

    string fname = output;
    ofstream inp(fname, std::ios::out | std::ios::binary);
    
    if (inp.is_open()) {
        inp << "P6\n";
        inp << height;
        inp << " ";
        inp << width << "\n";
        inp << max_col_val << "\n";

        char aux;

        
        for (unsigned int i = 0; i < size; ++i) {
            
            aux = (char) r_new[i];
            inp.write(&aux, 1);
            aux = (char) g_new[i];
            inp.write(&aux, 1);
            aux = (char) b_new[i];
            inp.write(&aux, 1);
        }

    } else {
        cout << "Error. Unable to open " << fname << std::endl;
    }
    
    inp.close();
}