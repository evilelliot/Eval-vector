#ifndef Tokenizer_hpp
#define Tokenizer_hpp

#include <vector>
#include <string>
using namespace std;

class Tokenizer{
    public:
        static vector<string> tokenize(string); // gets an expresion
        static vector<float> numbers(string);
};

#endif