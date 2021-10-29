#ifndef Helpers_hpp
#define Helpers_hpp

#include <math.h>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Helpers{
    public: 
    static vector<string> artos(char**, int);
    static bool parse(string, string);
    static string toLowercase(string);   
    static float degRad(float deg); 
};

#endif