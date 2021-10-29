#include "../include/Builder.hpp"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

void Builder::build2D(vector<string> list){
    string x_expresion;
    string y_expresion;Builder_hpp
    for(int i = 0; i < list.size(); i++){
        if(list[i] == "+" || list[i] == "-" || list[i] == "*" || list[i] == "," || list[i] == "(" || list[i] == ")"){
            // Sea i un operador distinto de la coma
            if(list[i] != ","){
                x_expresion = x_expresion + list[i];
                y_expresion = y_expresion + list[i];
            }
        }else{
            // Sea i un numero
            // Detectar si es una X o una Y
            if((i != 0) && list[i + 1] == ","){
                x_expresion = x_expresion + list[i];
            }else if((i != 0) && list[i - 1] == ","){
                y_expresion = y_expresion + list[i];
            }else if(list[i + 1] == "*"){
                x_expresion = x_expresion + list[i];
                y_expresion = y_expresion + list[i];
            }else if((i != 0) && list[i - 1] == "*"){
                x_expresion = x_expresion + list[i];
                y_expresion = y_expresion + list[i];
            }
        }
        
    }
    x_e = x_expresion;
    y_e = y_expresion;
}
void Builder::build3D(vector<string> list){
    int comma_counter = 0;
    string x_expresion;
    string y_expresion;
    string z_expresion;
    for(int i = 0; i < list.size(); i++){
        if(list[i] == "+" || list[i] == "-" || list[i] == "*" || list[i] == "," || list[i] == "(" || list[i] == ")"){
            // Sea i un operador distinto de la coma
            if(list[i] != ","){
                x_expresion = x_expresion + list[i];
                y_expresion = y_expresion + list[i];
            }
        }else{
            // Sea i un numero
            // Detectar si es una X o una Y
            if((i != 0) && list[i + 1] == ","){
                x_expresion = x_expresion + list[i];
            }else if((i != 0) && list[i - 1] == ","){
                y_expresion = y_expresion + list[i];
                comma_counter++;
            }else if(list[i + 1] == "*"){
                x_expresion = x_expresion + list[i];
                y_expresion = y_expresion + list[i];
                z_expresion = z_expresion + list[i];
            }else if((i != 0) && list[i - 1] == "*"){
                x_expresion = x_expresion + list[i];
                y_expresion = y_expresion + list[i];
                z_expresion = z_expresion + list[i];
            }
        }
        
    }
    x_e = x_expresion;
    y_e = y_expresion;
    z_e = z_expresion;
}