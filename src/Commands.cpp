#include "../include/Commands.hpp"
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;


// Char array to string vector
vector<string> Commands::artos(char* data[], int argc){
    // Convert arg char to string
    vector<string> argList;
    for(int i = 1; i < argc; i++){
        argList.push_back(data[i]);
    }
    return argList;
}
// Parse commands easily
bool Commands::command(string arg, string command){
    arg = toLowercase(arg);
    command = toLowercase(command);
    char fchar = command[0];
    return arg == command || arg == "-" + string(1, fchar);
}
// Convert string to lowercase
string Commands::toLowercase(string data){
    for_each(data.begin(), data.end(), [](char & ch) {
        ch = tolower(ch);
    });
    return data;
}
