#ifndef Eval_hpp
#define Eval_hpp

#include <string>
#include <vector>
using namespace std;

class Eval{
    public:
        static double eval(string);
        static void evalDot(vector<float>, vector<float>);
        static void evalCross(vector<float>, vector<float>);
        static void evalModule(vector<float>);
        static void evalTranslation(vector<float>, vector<float>);
        static void evalRotation(vector<float>, vector<float>);
};
#endif