#include "../include/Tokenizer.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <regex>
using namespace std;

// Tokenize function
vector<string> Tokenizer::tokenize(string exp){
    const string ALL = "(\\+{1}|\\-{1}|\\/{1}|\\*{1}|\\({1}|\\){1}|\\,{1})|([+-]?([0-9]+([.][0-9]*)?|[.][0-9]+))";
    vector<string> data;
  
    const regex tok(ALL);
    smatch matches;

    while(regex_search(exp, matches, tok)){
        data.push_back(matches.str(0));
        exp = matches.suffix();
    }
    return data;
}
vector<float> Tokenizer::numbers(string _data){
    vector<float> data;
    const string ANY_NUMBER = "[+-]?([0-9]+([.][0-9]*)?|[.][0-9]+)";

    const regex tok(ANY_NUMBER);
    smatch matches;

    while(regex_search(_data, matches, tok)){
        data.push_back(stof(matches.str()));
        _data = matches.suffix();
    }
    return data;
}