#include "include/Eval.hpp"
#include "include/Tokenizer.hpp"
#include "include/Builder.hpp"
#include "include/Commands.hpp"
#include "include/Template.hpp"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
    Template t;

    if(argc == 1){
        cout << "Check -h for help!" << endl;
    }else{
        vector<string> arguments = Commands::artos(argv, argc);
        // Parsing commands
        if(Commands::command(arguments[0], "Help")){
            t.help();
        }else if(Commands::command(arguments[0], "Version")){
            t.version();    
        }else if(Commands::command(arguments[0], "Credits")){
            t.credits();
        }else if(Commands::command(arguments[0], "Operate")){
            if(arguments.size() == 2){
                string ex = arguments[1];
                vector<string> data = Tokenizer::tokenize(ex);
                Builder mybuild;
                mybuild.build2D(data);

                float x = Eval::eval(mybuild.x_e);
                float y = Eval::eval(mybuild.y_e);
                cout << ex << " = " << "(" << x << "," << y << ")" << endl;
            }
        }else if(Commands::command(arguments[0], "Dot")){
            if(arguments.size() == 3){
                Tokenizer tk;
                vector<float> v1 = tk.numbers(arguments[1]);
                vector<float> v2 = tk.numbers(arguments[2]);

                Eval::evalDot(v1, v2);
            }
        }else if(Commands::command(arguments[0], "Kross")){
            if(arguments.size() == 3){
                Tokenizer tk;
                vector<float> v1 = tk.numbers(arguments[1]);
                vector<float> v2 = tk.numbers(arguments[2]);

                Eval::evalCross(v1, v2);
            }
        }else if(Commands::command(arguments[0], "Module")){
            if(arguments.size() == 2){
                Tokenizer tk;
                vector<float> v = tk.numbers(arguments[1]);

                Eval::evalModule(v);
            }
        }else if(Commands::command(arguments[0], "Rotation")){
            if(arguments.size() == 3){
                Tokenizer tk;
                vector<float> v = tk.numbers(arguments[1]);
                vector<float> a = tk.numbers(arguments[2]);

                Eval::evalRotation(v, a);
            }
        }else if(Commands::command(arguments[0], "Translation")){
            if(arguments.size() == 3){
                Tokenizer tk;
                vector<float> v  = tk.numbers(arguments[1]);
                vector<float> v2 = tk.numbers(arguments[2]);
                
                Eval::evalTranslation(v, v2);
            }
        }
    }
    return 0;
}