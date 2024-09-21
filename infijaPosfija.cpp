#include<iostream>
#include "Pila.h"

using namespace std;

int main()
{
    //Creaci�n de un objeto de tipo pila
    Pila<char> *pilaOperadores = new Pila<char>();
    Pila<int> *pilaOperandos = new Pila<int>();
    Pila<char> *pilaParentesis = new Pila<char>;

    //Expresi�n en notaci�n infija
    string infija = "((1-8)*2+(2+2))";

    cout<<"Expresion matematica en notacion infija: "<<infija<<endl;

    string posfija = pilaOperadores->infija_posfija(infija);

    cout<<"Expresion en notacion posfija: "<<posfija<<endl;

    cout<<"Evaluacion de la expresion anterior en notacion posfija: "<<endl;

    cout<<pilaOperandos->evaluarPosfija(posfija);

    string parentesis = "({[][]()}){[()[]]}[()()}";

    if(pilaParentesis->balancearParentesis(parentesis))
        cout<<"\nLa expresion de parentesis "<<parentesis<<" si esta balanceado"<<endl;
    else
        cout<<"\nLa expresion de parentesis "<<parentesis<<" no esta balanceada"<<endl;

    return EXIT_SUCCESS;
}
