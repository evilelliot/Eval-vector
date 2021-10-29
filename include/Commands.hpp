#ifndef Commands_hpp
#define Commands_hpp

#include <string>
#include <vector>
using namespace std;

class Commands{
    public:
        static bool command(string, string);
        static vector<string> artos(char**, int);
        static string toLowercase(string); 
};
#endif