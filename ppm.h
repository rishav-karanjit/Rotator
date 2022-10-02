//Process a binary PPM file
#include <vector>
#include <string>

#ifndef PPM_H
#define PPM_H

using namespace std;
class ppm {
    void init();
    //info about the PPM file (height and width)
    unsigned int nr_lines;
    unsigned int nr_columns;

public:
    //arrays for storing the R,G,B values
    std::vector<unsigned char> r;
    std::vector<unsigned char> g;
    std::vector<unsigned char> b;
    //
    //arrays for storing the R,G,B values
    std::vector<string> r_raw;
    std::vector<string> g_raw;
    std::vector<string> b_raw;
    unsigned int height;
    unsigned int width;
    unsigned int max_col_val;
    //total number of elements (pixels)
    unsigned int size;
    string ftype;
    string fname;

    ppm();
    //create a PPM object and fill it with data stored in fname 
    ppm(const std::string &fname);
    //create an "epmty" PPM image with a given width and height;the R,G,B arrays are filled with zeros
    ppm(const unsigned int _width, const unsigned int _height);

    //
    void read();

    //read the PPM image from fname
    void readp6();
    //read the PPM image from fname
    void readp3();
    //write the PPM image in fname
    void rotateR90(string output,int DegreeOfRotation);
    //write the PPM image in fname
    void rotateR90P3(string output);

    void rotateR90P6(string output);
};

#endif