/**
 * @file Template.hpp
 *
 * @author Alberto Ocaranza
 * Contact: alt.ocaranza@gmail.com
 *
 */
#ifndef Template_hpp
#define Template_hpp

#include <string>
using namespace std;
class Template{
    public:
    void help();
    void version();
    void credits();
    void greetings(string data);
    void greetings(string data, int times);
};

#endif