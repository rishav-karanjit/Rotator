//Process a binary ColorPixel file
#include <vector>
#include <string>

#ifndef ColorPixel_H
#define ColorPixel_H

using namespace std;
class ColorPixel {
    void init();
    //info about the ColorPixel file (height and width)
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

    ColorPixel();
    //create a ColorPixel object and fill it with data stored in fname 
    ColorPixel(const std::string &fname);
    //create an "epmty" ColorPixel image with a given width and height;the R,G,B arrays are filled with zeros
    ColorPixel(const unsigned int _width, const unsigned int _height);

    //
    void read();

    //read the ColorPixel image from fname
    void readp6();
    //read the ColorPixel image from fname
    void readp3();
    //write the ColorPixel image in fname
    void rotateR90(string output,int DegreeOfRotation);
    //write the ColorPixel image in fname
    void rotateR90P3(string output);

    void rotateR90P6(string output);
};

#endif
