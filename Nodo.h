#include<iostream>

using namespace std;

template<typename T>
class Nodo
{
    private:
        Nodo<T> *siguiente; //Apuntador al siguiente nodo
        T dato; //Tipo de dato que guardara el nodo

    public:
        Nodo();//Constructor vac�o
        Nodo(T dat); //Constructor con par�metros
        ~Nodo(); //Destructor
        void setDato(T dat);
        T getDato();
        Nodo *getSiguiente();
        void setSiguiente(Nodo *sig);
};

//Constructor vac�o
template<typename T>
Nodo<T>::Nodo(){

}


//Constructor con par�metros
template<typename T>
Nodo<T>::Nodo(T dat){
    dato = dat;
    siguiente = nullptr;
}


//Destructor
template<typename T>
Nodo<T>::~Nodo(){

}


//M�todo getter, que devuelve el valor del nodo
template<typename T>
T Nodo<T>::getDato()
{
    return dato;
}


//M�todo que devuelve el nodo siguiente del nodo actual del nodo con el que se esta trabajando
template<typename T>
Nodo<T>* Nodo<T>::getSiguiente()
{
    return siguiente;
}

//M�todo set que establece el valor de un nodo como siguiente
template<typename T>
void Nodo<T>::setSiguiente(Nodo<T> *sig)
{
    siguiente = sig;
}


//M�todo set, que establece un valor en un nodo
template<typename T>
void Nodo<T>::setDato(T dat)
{
    dato = dat;
}


