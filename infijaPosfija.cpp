#include<iostream>
#include "Pila.h"

using namespace std;

int main()
{
    //Creación de un objeto de tipo pila
    Pila<char> *pilaOperadores = new Pila<char>();
    Pila<int> *pilaOperandos = new Pila<int>();

    //Expresión en notación infija
    string infija = "(3*(4+5)*(7-2))";

    cout<<"Expresion matematica en notacion infija: "<<infija<<endl;

    string posfija = pilaOperadores->infija_posfija(infija);

    cout<<"Expresion en notacion posfija: "<<posfija<<endl;

    cout<<pilaOperandos->evaluarPosfija(posfija)<<endl;

    return EXIT_SUCCESS;
}
