//Process a binary GrayPixel file
#include <vector>
#include <string>

#ifndef GrayPixel_H
#define GrayPixel_H

using namespace std;
class GrayPixel {
    void init();
    //info about the GrayPixel file (height and width)
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

    GrayPixel();
    //create a PPM object and fill it with data stored in fname 
    GrayPixel(const std::string &fname);
    //create an "epmty" PPM image with a given width and height;the R,G,B arrays are filled with zeros
    GrayPixel(const unsigned int _width, const unsigned int _height);

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