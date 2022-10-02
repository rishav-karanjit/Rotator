//Process a binary PPM file
#include <vector>
#include <string>

#include <string.h>
#include <iostream>

#ifndef Rotator_H
#define Rotator_H

using namespace std;

class Rotator {
   private:
      static Rotator* instance; // can be named other than instance
      string input, output;
      // Private constructor so that no objects can be created.
      Rotator() {
      }
      
      void init(string ip,string op);
      string getExtension(string filename);
      void checkExtension(string ipextension);
      void checkOptions(string options);
      void checkDegree(string degree);
      int getDegreeOfRotation(string degreeWord,string option);
   public:
      // can be named anything, but recommended to have word Instance in the name
      static Rotator* getInstance(string ip,string op) {
         if (!instance)
            instance = new Rotator();

         instance->init(ip,op);
         return instance;
      }
      void rotate(string option, string degree);
};

#endif