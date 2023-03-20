#include "Headers/Nodo.h"

Nodo::Nodo(int d, string name,  Nodo* n =NULL, Nodo* p = NULL) // crea el nodo y lo enlaza a n
{
    this->cuarto = d;
    this->nombre = name;
    this->Next = n;
    this->Prev = p;
}

int Nodo::getCuartoNodo( ) const
{
    return cuarto;
}

string Nodo::getNombreNodo( ) const{
    return nombre;
}

Nodo *Nodo::getEnlaceNext( ) const
{
    return Next;
}

Nodo *Nodo::getEnlacePrev( ) const
{
    return Prev;
}

void Nodo:: ponerEnlaceNext(Nodo* sgte)
{
    this->Next = sgte;
}

void Nodo:: ponerEnlacePrev( Nodo *prev)
{

    this->Prev = prev;
}

void Nodo::setCuarto(int cuarto) {
    Nodo::cuarto = cuarto;
}

void Nodo::setNombre(const string &nombre) {
    Nodo::nombre = nombre;
}
