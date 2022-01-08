#include <iostream>
#include <vector>
#include <cstring>
#include "colors.hpp"

#define S "-s"
#define SUM "--sum"
#define R "-r"
#define REST "--rest"
#define M "-m"
#define MULTI "--multi"
#define D "-d"
#define DIV "--div"

using namespace std;
using namespace Color;

struct Data{

    uint8_t Argc;
    string NameFlag;
    bool Debug, Help;
    vector<float> Vector;
    uint8_t VectorSize;
    float Result;

} typedef ParseData;

class ArgParse{

    public:
        ArgParse( int argc, char **argv){

            if ( argc != 1 ){

                this->argc = argc;
                this->argv = argv;

                FillData();
            }
            else {
                this->Parse.Help = true;
                HelpPanel();
            }
        }


        int FillData(){

            this->Parse.NameFlag = argv[1];
            this->Parse.Help = false;

            for ( int i = 2; i < this->argc; i++ ){
                if ( strcmp("--debug", argv[i]) == 0 ){
                    this->Parse.Debug = true;
                    break;

                }
                else{

                    try{
                        float n = atof(argv[i]);

                        if ( n != 0 ){
                            this->Parse.Vector.push_back(n);
                        }
                        else {
                            throw("Uno de los valores no es un número.");
                        }
                    } catch( const char *Err ){
                        cerr << LIGHTRED_EX << "[!]Hubo un Error: " << Err << endl;
                        return 1;
                    }
                }
            }
            this->Parse.VectorSize = this->Parse.Vector.size();
            InitOp();

            return 0;
        }

        void InitOp(){
            if ( this->Parse.Help ) { HelpPanel(); }
            else {
                try{
		            if ( this->Parse.NameFlag == S || this->Parse.NameFlag == SUM ){
		                cout << LIGHTYELLOW_EX << "NameFlag" << RESET << ": " << LIGHTRED_EX << this->Parse.NameFlag << RESET << endl;
		                cout << LIGHTRED_EX << "Debug" << RESET << ": " << this->Parse.Debug << endl;

		                for ( uint8_t i = 0; i < this->Parse.VectorSize; i++){
		                    if ( i == 0){
		                        this->Parse.Result = this->Parse.Vector[i];
		                    } else { this->Parse.Result += this->Parse.Vector[i]; }

		                    if ( i + 1 == this->Parse.VectorSize ){ break; }

		                    if ( this->Parse.Debug ){
		                        cout << LIGHTRED_EX << "> " << LIGHTYELLOW_EX << this->Parse.Result << RESET << " + " << LIGHTYELLOW_EX << this->Parse.Vector[i+1] << RESET << endl;
		                    }
		                }
		                cout << LIGHTGREEN_EX << "\nResultado: " << this->Parse.Result << RESET;
		            }
		            else if ( this->Parse.NameFlag == R || this->Parse.NameFlag == REST ){
		                cout << LIGHTYELLOW_EX << "NameFlag" << RESET << ": " << LIGHTRED_EX << this->Parse.NameFlag << RESET << endl;
		                cout << LIGHTRED_EX << "Debug" << RESET << ": " << this->Parse.Debug << endl;

		                for ( uint8_t i = 0; i < this->Parse.VectorSize; i++){
		                    if ( i == 0){
		                        this->Parse.Result = this->Parse.Vector[i];
		                    } else { this->Parse.Result -= this->Parse.Vector[i]; }

		                    if ( i + 1 == this->Parse.VectorSize ){ break; }

		                    if ( this->Parse.Debug ){
		                        cout << LIGHTRED_EX << "> " << LIGHTYELLOW_EX << this->Parse.Result << RESET << " - " << LIGHTYELLOW_EX << this->Parse.Vector[i+1] << RESET << endl;
		                    }
		                }
		                cout << LIGHTGREEN_EX << "\nResultado: " << this->Parse.Result << RESET;
		            }
		            else if ( this->Parse.NameFlag == M || this->Parse.NameFlag == MULTI ){
		                cout << LIGHTYELLOW_EX << "NameFlag" << RESET << ": " << LIGHTRED_EX << this->Parse.NameFlag << RESET << endl;
		                cout << LIGHTRED_EX << "Debug" << RESET << ": " << this->Parse.Debug << endl;

		                for ( uint8_t i = 0; i < this->Parse.VectorSize; i++){
		                    if ( i == 0){
		                        this->Parse.Result = this->Parse.Vector[i];
		                    } else { this->Parse.Result *= this->Parse.Vector[i]; }

		                    if ( i + 1 == this->Parse.VectorSize ){ break; }

		                    if ( this->Parse.Debug ){
		                        cout << LIGHTRED_EX << "> " << LIGHTYELLOW_EX << this->Parse.Result << RESET << " * " << LIGHTYELLOW_EX << this->Parse.Vector[i+1] << RESET << endl;
		                    }
		                }
		                cout << LIGHTGREEN_EX << "\nResultado: " << this->Parse.Result << RESET;
		            }
		            else if ( this->Parse.NameFlag == D || this->Parse.NameFlag == DIV ){
		                cout << LIGHTYELLOW_EX << "NameFlag" << RESET << ": " << LIGHTRED_EX << this->Parse.NameFlag << RESET << endl;
		                cout << LIGHTRED_EX << "Debug" << RESET << ": " << this->Parse.Debug << endl;

		                for ( uint8_t i = 0; i < this->Parse.VectorSize; i++){
		                    if ( i == 0){
		                        this->Parse.Result = this->Parse.Vector[i];
		                    } else { this->Parse.Result /= this->Parse.Vector[i]; }

		                    if ( i + 1 == this->Parse.VectorSize ){ break; }

		                    if ( this->Parse.Debug ){
		                        cout << LIGHTRED_EX << "> " << LIGHTYELLOW_EX << this->Parse.Result << RESET << " / " << LIGHTYELLOW_EX << this->Parse.Vector[i+1] << RESET << endl;
		                    }
		                }
		                cout << LIGHTGREEN_EX << "\nResultado: " << this->Parse.Result << RESET;
		            }
                	else { throw("Parámetro Inválido"); }
				} catch (const char *Err){
					cerr << LIGHTRED_EX << "[!]Hubo un Error: " << Err << endl;
					Usage();
				}
            }
        }

        void Usage(){
            cout << LIGHTGREEN_EX << "\tUsage: ./Calc +parametro val1.. val5... +debug(opcional)" << RESET << endl;
        }

        void HelpPanel(){
            cout << LIGHTYELLOW_EX << "\n\tCalculator " << BLUE << "v0.2" << RESET << " by Justgr0w.\n\n";
            cout << LIGHTYELLOW_EX << "[-s][--sum]" << RESET << "\tSUMAR\t\tPara sumar los valores.\n";
            cout << LIGHTYELLOW_EX << "[-r][--rest]" << RESET << "\tRESTAR\t\tPara restar los valores.\n";
            cout << LIGHTYELLOW_EX << "[-m]{--multi}" << RESET << "\tMULTIPLICACIÓN\tPara Multiplicar los valores.\n";
            cout << LIGHTYELLOW_EX << "[-d][--div]" << RESET << "\tDIVIDIR\t\tPara dividir los valores.\n";
            cout << LIGHTYELLOW_EX << "[--debug]" << RESET << "\tDEBUG\t\tPara ver el registro de las operaciones.\n";
            Usage();
        }

        void PrintVector(){
            cout << this->argc-1 << " Valores: ";
            for ( uint8_t i = 0; i < this->Parse.VectorSize; i++){
                cout << this->Parse.Vector[i] << " ";
            }
        }

        ~ArgParse(){
        }

    private:

        uint8_t argc;
        char **argv;
        ParseData Parse;
};
