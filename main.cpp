#include "ArgParse.hpp"
#define __CALCULADORA__
#define _VERSION_ "0.2"
#define __AUTHOR__ "justgr0w(David)"
#define __GITHUB_PROFILE__ "https://github.com/justgr0w"

int main(int argc, char **argv){

    setlocale(LC_ALL, "spanish");

    // SetFlags (I / O)
    cout.setf(std::ios::boolalpha);

    // Instancia
    ArgParse MyObj(argc, argv);
    return 0;
}
