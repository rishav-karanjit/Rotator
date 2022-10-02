//Process a binary PGM file
#include <vector>
#include <string>

#ifndef PGM_H
#define PGM_H

using namespace std;
class pgm {
    void init();
    //info about the PGM file (height and width)
    unsigned int nr_lines;
    unsigned int nr_columns;

public:
    //arrays for storing the grey values
    std::vector<unsigned char> grey;
    //
    //arrays for storing the R,G,B values
    std::vector<string> grey_raw;
    unsigned int height;
    unsigned int width;
    unsigned int max_col_val;
    //total number of elements (pixels)
    unsigned int size;
    string ftype;
    string fname;

    pgm();
    //create a PPM object and fill it with data stored in fname 
    pgm(const std::string &fname);
    //create an "epmty" PPM image with a given width and height;the R,G,B arrays are filled with zeros
    pgm(const unsigned int _width, const unsigned int _height);

    //
    void read();

    //read the PPM image from fname
    void readp5();
    //read the PPM image from fname
    void readp2();
    //write the PPM image in fname
    void rotateR90(string output,int DegreeOfRotation);
    //write the PPM image in fname
    void rotateR90P2(string output);

    void rotateR90P5(string output);
};

#endif