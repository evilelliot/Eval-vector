#ifndef Builder_hpp
#define Builder_hpp

#include <vector>
#include <string>
using namespace std;

class Builder{
    public:
        Builder(){}
        string x_e;
        string y_e;
        string z_e;
        void build2D(vector<string>);
        void build3D(vector<string>);
};
#endif