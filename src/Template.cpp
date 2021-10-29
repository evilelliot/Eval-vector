/**
 * @file Template.cpp
 *
 * @author Alberto Ocaranza
 * Contact: alt.ocaranza@gmail.com
 *
 */
#include "../include/Template.hpp"
#include <iostream>
#include <string>
using namespace std;

void Template::help(){
    cout << "----------------------------------------------" << endl;
    cout << R"(
███████ ██    ██  █████  ██      ██████  
██      ██    ██ ██   ██ ██           ██ 
█████   ██    ██ ███████ ██       █████  
██       ██  ██  ██   ██ ██      ██      
███████   ████   ██   ██ ███████ ███████                                                          
)" << '\n';
    cout << "----------------------------------------------" << endl;
    cout << "usage:\033[1;32m eval \033[0m \033[1;33m[options]\033[0m \033[1;36m(arguments)\033[0m" << endl;
    cout << "-h  | -H  | help" << endl;
    cout << "-v  | -V  | version" << endl;
    cout << "-c  | -C  | credits" << endl;
    cout << "-o  | -o  | operate [some expression]" << endl;
    cout << "-d  | -D  | dot [vector] [vector]" << endl;
    cout << "-k  | -K  | kross [vector] [vector]" << endl;
    cout << "-m  | -M  | module [vector]" << endl;
    cout << "-t  | -T  | translate [vector]" << endl;
    cout << "-r  | -R  | rotate [vector]" << endl;
    cout << "----------------------------------------------" << endl;
}
void Template::version(){
    // lmao I totally forgot to update this message
    cout << "\033[1;32mEval 2\033[0m" << endl;
}
void Template::credits(){
    cout << "Made by: Alberto Ocaranza (fevil)" << endl;
    cout << "https://github.com/evilelliot" << endl;
}
