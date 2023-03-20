#ifndef HOTEL_MENU_H
#define HOTEL_MENU_H
#import "Lista.h"

class Menu {
private:
    Lista *lista;
    Lista *listaSorted;
public:
    Menu();

    void visualizar();

    void crearCliente();

    void buscar();


    void crearLista();

    void eliminar();

    void visualizarIzquierda();

    void sortAlfabetico();

    void visualizarSinCrear();

    void acciones();

    void imprimirAcciones();

    void getNomrbesVecinos();

    void encontrarCuarto();
};




#endif //HOTEL_MENU_H
