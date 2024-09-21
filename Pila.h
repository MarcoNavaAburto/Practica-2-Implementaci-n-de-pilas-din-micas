#include "Nodo.h"
#include<iostream>
#include<cctype>
#include<string>
#include<cmath>

using namespace std;

template<typename T>
class Pila
{
    private:
        Nodo<T> *tope; //cima de la pila
        int numElementos; //N�mero de elementos de la pila

    public:
        Pila(); //constructor
        ~Pila(); //destructor
        void push(T valor); //inserci�n de un elemento en la pila
        void pop(); //eliminaci�n de un elemento en la pila
        string infija_posfija(string infija); //M�todo que cambia una expresi�n de notaci�n infija a notaci�n posfija
        T top(); //retornar el valor que hay guardado en la cima de la pila
        int getNumElementos(); //retorna el n�mero de elementos de la pila
        int evaluarPosfija(string posfija); //M�todo que evalua(da el resultado) de una expresi�n que estaba expresada en notaci�n infija
        void aplicarSuma(); //M�todo para aplicar la suma en dos operandos de una expresi�n notaci�n posfija
        void aplicarResta(); //M�todo para aplicar la resta sobre dos operandos de una expresi�n en notaci�n posfija
        void aplicarMultiplicacion(); //M�todo para aplicar la multiplicaci�n sobre 2 operandos de una expresi�n en notaci�n posfija
        void aplicarDivision(); //M�todo para aplicar la divisi�n sobre 2 operandos de una expresi�n en notaci�n posfija
        void aplicarModulo(); //M�todo para aplicar el m�dulo sobre 2 operandos de una expresi�n en notaci�n nposfija
        void aplicarPotencia(); //M�todo para aplicar la potencia de sobre 2 operandos de una expresi�n en notaci�n posfija
        bool balancearParentesis(string balanceo); //m�todo para indicar si una expresi�n tiene los par�ntesis balanceados
};

//Constructor
template<typename T>
Pila<T>::Pila()
{
    tope = nullptr;
    numElementos = 0;
}

//Destructor
template<typename T>
Pila<T>::~Pila()
{
    Nodo<T> aux;

    aux = tope;

    while(aux != nullptr)
    {
        tope = tope->getSiguiente();

        delete aux;

        aux = tope;
    }

}

//Hacer push en la pila(inserci�n de un elemento en la pila)
template<typename T>
void Pila<T>::push(T valor)
{
    //Creaci�n de un nuevo nodo
    Nodo<T> *nuevoNodo = new Nodo<T>(valor);

    if(tope == nullptr)
    {
        nuevoNodo->setSiguiente(nullptr);
    }
    else
    {
        nuevoNodo->setSiguiente(tope);
    }

    tope = nuevoNodo;

    numElementos++;
}

//Hacer pop en la pila (eliminaci�n de un elemento en la pila)
template<typename T>
void Pila<T>::pop()
{
    Nodo<T> *aux;

    aux = tope;

    tope = tope->getSiguiente();

    delete aux;

    numElementos--;
}


//M�todo que retorna el valor que hay guardado en el nodo cima
template<typename T>
T Pila<T>::top()
{
    return tope->getDato();
}

//M�todo que retorna el n�mero de elementos que hay en una pila
template<typename T>
int Pila<T>::getNumElementos()
{
    return numElementos;
}

template<typename T>
string Pila<T>::infija_posfija(string infija)
{
    //Variable donde se guardar� la expresi�n en notaci�n posfija
    string salida = "";

    char dato;

    //Se recorre la expresi�n en notaci�n infija
    for(int i=0;i<infija.size();i++)
    {
        //Si es un operando el elemento actual que se esta visitando, entonces se agrega el valor al string de calida, que es donde se guardara la conversi�n de la expresi�n de notaci�n infija a notaci�n posfija
        if(infija[i] == '0' || infija[i] == '1' || infija[i] == '2' || infija[i] == '3' || infija[i] == '4' || infija[i] == '5' || infija[i] == '6' || infija[i] == '7' || infija[i] == '8' || infija[i] == '9')
        {
            salida += infija[i];
        }
        //Se push del par�ntesis izquierdo en la pila (se agrega a la estructura)
        else if(infija[i] == '(')
        {
            push(infija[i]);
        }
        //Se agregan todos los operadores que hay en el string salida, al igual se van eliminando
        else if(infija[i] == ')')
        {
            while(top() != '(')
            {
                salida += top();
                pop();
            }

            pop();
        }
        else if(infija[i] == '+' || infija[i] == '-')
        {
           while(numElementos != 0 && top() != '(')
           {
                salida += top();
                pop();
           }

           push(infija[i]);

        }
        else if(infija[i] == '*' || infija[i] == '/' || infija[i] == '%')
        {

            while(numElementos != 0 && (top() == '*' || top() == '/' || top() == '%') || top() == '^')
            {
                salida += top();
                pop();
            }

            push(infija[i]);
        }
        //Damos por entendido que si no se cumplen ninguna de las condiciones anteriores, quiere decir que entonces el operador actual puede ser el operador de ra�z, o el de exponente (potencia)
        else
        {
            while(numElementos != 0 && top() == '^')
            {
                salida += top();
                pop();
            }

            push(infija[i]);
        }

    }

    while(numElementos != 0)
    {
        salida += top();
        top();
    }

    return salida;
}

template<typename T>
int Pila<T>::evaluarPosfija(string posfija)
{
    int resultado;
    int numero;

    for(int i=0;i<posfija.size();i++)
    {
        if(isdigit(posfija[i]))
        {
            numero = posfija[i] - '0';
            push(numero);
        }
        else if(posfija[i] == '+')
        {
            aplicarSuma();
        }
        else if(posfija[i] == '-')
        {
            aplicarResta();
        }
        else if(posfija[i] == '*')
        {
            aplicarMultiplicacion();
        }
        else if(posfija[i] == '/')
        {
            aplicarDivision();
        }
        else if(posfija[i] == '%')
        {
            aplicarModulo();
        }
        else if(posfija[i] == '^')
        {
            aplicarPotencia();
        }
        else
        {
            cout<<"Operador no soportado"<<endl;
        }
    }

    resultado = top();

    pop();

    return resultado;

}


template<typename T>
void Pila<T>::aplicarSuma()
{
    int operando2 = top();
    pop();
    int operando1 = top();
    pop();

    int suma = operando1 + operando2;

    push(suma);
}

template<typename T>
void Pila<T>::aplicarResta()
{
    int operando2 = top();
    pop();
    int operando1 = top();
    pop();

    int resta = operando1 - operando2;

    push(resta);
}

template<typename T>
void Pila<T>::aplicarMultiplicacion()
{
    int operando2 = top();
    pop();
    int operando1 = top();
    pop();

    int multiplicacion = operando1 * operando2;

    push(multiplicacion);
}

template<typename T>
void Pila<T>::aplicarDivision()
{
    int operando2 = top();
    pop();
    int operando1 = top();
    pop();

    int division = operando1 / operando2;

    push(division);
}

template<typename T>
void Pila<T>::aplicarModulo()
{
    int operando2 = top();
    pop();
    int operando1 = top();
    pop();

    int modulo = operando1 % operando2;

    push(modulo);
}

template<typename T>
void Pila<T>::aplicarPotencia()
{
    int potencia;
    int operando2 = top();
    pop();
    int operando1 = top();
    pop();

    potencia = pow(operando1, operando2);

    push(potencia);
}

template<typename T>
bool Pila<T>::balancearParentesis(string balanceo)
{
    bool esBalanceada = true;

    for(int i=0;i<balanceo.size();i++)
    {
        if(balanceo[i] == '(' || balanceo[i] == '[' || balanceo[i] == '{')
        {
            push(balanceo[i]);
        }
        else if(balanceo[i] == ')')
        {
            if(top() != '(')
            {
                esBalanceada = false;
                break;
            }
            else
                pop();
        }
        else if(balanceo[i] == ']')
        {
            if(top() != '[')
            {
                esBalanceada = false;
                break;
            }
            else
                pop();
        }
        else
        {
            if(top() != '{')
            {
                esBalanceada = false;
                break;
            }
            else
                pop();
        }

    }

    return esBalanceada;

}
