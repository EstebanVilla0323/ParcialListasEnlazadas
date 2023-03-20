//
// Created by RYZEN 7 on 2/03/2023.
//

#ifndef HOTEL_NODO_H
#define HOTEL_NODO_H
using namespace std;
#include <string>


class Nodo {
protected:
    int cuarto;
    string nombre;
    Nodo *Next;
    Nodo *Prev;
public:
    Nodo(int d,string name, Nodo *n, Nodo* p);

    int getCuartoNodo() const;

    string getNombreNodo( ) const;

    Nodo *getEnlaceNext() const;

    Nodo *getEnlacePrev() const;

    void ponerEnlaceNext(Nodo *sgte);

    void ponerEnlacePrev(Nodo *prev);

    void setCuarto(int cuarto);

    void setNombre(const string &nombre);
};


#endif //HOTEL_NODO_H
