#include "../include/Eval.hpp"
#include "../include/Helpers.hpp"
#include <vector>
#include <iostream>
#include <string>
using namespace std;


double Eval::eval(string expr){
    string formated;
    for (int i = 0; i < expr.length(); i++){
        if (expr[i] != ' '){
            formated += expr[i];
        }
    }
    // Evaluando los parentesis
    string tok = ""; 
    for (int i = 0; i < formated.length(); i++){
        if (formated[i] == '('){
            int iter = 1;
            string token;
            i++;
            while(true){
                if (formated[i] == '('){
                    iter++;
                }else if(formated[i] == ')'){
                    iter--;
                    if (iter == 0){
                        i++;
                        break;
                    }
                }
                token += formated[i];
                i++;
            }
            tok += to_string(eval(token));
        }
        tok += formated[i];
    }
    // Evaluando sumas y restas
    for (int i = 0; i < tok.length(); i++){
        if (tok[i] == '+'){
            return eval(tok.substr(0, i)) + eval(tok.substr(i+1, tok.length()-i-1));
        }else if (tok[i] == '-'){
            return eval(tok.substr(0, i)) - eval(tok.substr(i+1, tok.length()-i-1));
        }
    }
    // Evaluando multiplicaciones
    for(int i = 0; i < tok.length(); i++){
        if(tok[i] == '*'){
            //cout << tok.substr(0, i) + " * " +  tok.substr(i+1, tok.length()-i-1) << " == " << eval(tok.substr(0, i)) * eval(tok.substr(i+1, tok.length()-i-1)) << endl;
            return eval(tok.substr(0, i)) * eval(tok.substr(i+1, tok.length()-i-1));
        }
    }
    return stod(tok.c_str());
}
void Eval::evalDot(vector<float> v1, vector<float> v2){
    float dot_product = 0;
    if(v1.size() >= 2 && v2.size() >= 2){
        for(int i = 0; i < v1.size(); i++){
            dot_product = dot_product + (v1[i] * v2[i]);
        }
        cout << "V\u2192 ⋅ W\u2192 = ";
        cout << dot_product << endl;
    }else{
        cout << "Invalid arguments." << endl;
    }
}
void Eval::evalCross(vector<float> v1, vector<float> v2){
    float x, y, z;
    x = (v1[1] * v2[2]) - (v1[2] * v2[1]);
    y = -(v1[0] * v2[2] - v1[2] * v2[0]);
    z = (v1[0] * v2[1]) - (v1[1] * v2[0]);

    cout << "V\u2192 ⋅ W\u2192 = ";
    cout << "{" << x << "," << y << "," << z << "}" << endl; 
}
void Eval::evalModule(vector<float> v){
    float sum = 0;
    for(float f: v){
        sum = sum + pow(f, 2);
    }
    cout << " = " << sqrt(sum);
}
void Eval::evalTranslation(vector<float> v, vector<float> t){
    float x, y, _x, _y, a, b;
    x  = v[0]; y  = v[1];
    a  = t[0]; b  = t[1];
    if(v.size() == 4){
        _x = v[2]; _y = v[3];
        cout << "R₁ = (" << x + a << "," << y + b << ")" << endl;
        cout << "R₂ = (" << _x + a << "," << _y + b << ")" << endl;
    }else{
        cout << "R = (" << x + a << "," << y + b << ")" << endl;
    }
}
void Eval::evalRotation(vector<float> v, vector<float> a){
    float _x = 0, _y = 0, x, y, c = 0, s = 0, rad = 0;
    if(v.size() == 2 && a.size() == 1){
        rad = Helpers::degRad(a[0]);
        c   = cos(rad);   s = sin(rad);
        x   = v[0];       y = v[1];

        _x = 0 + cos(rad) * (x - 0) - sin(rad) * (y - 0);
        _y = 0 + sin(rad) * (x - 0) + cos(rad) * (y - 0);

        cout << "R= (" << _x << "," << _y << ")" << endl;    
    }else{
        cout << "Invalid vector" << endl;
    }
}