#ifndef HOTEL_LISTA_H
#define HOTEL_LISTA_H

#include <cstddef>
#include "Nodo.h"

class Lista {
protected:
    Nodo *head;
    Nodo * tail;

public:
    Lista();

    void crearLista();

    Nodo * insertarCabezaLista(int entrada, string nombre);

    void visualizarDerecha();

    void visualizarIzquierda();

    Nodo *insertarColaLista(int entrada, string nombre);

    void addCliente();

    void buscar();

    void eliminar(int entrada, string nombre);

    bool checkCuarto(int cuarto);

    int checkVecinos(int cuarto);

    void sortAlfabetico();

    void checkNombreVecinos();

    void crearListaSorted();

    void sortAlfabeticoTail();

    static int encontrarCuarto(int cuarto);
};


#endif //HOTEL_LISTA_H
