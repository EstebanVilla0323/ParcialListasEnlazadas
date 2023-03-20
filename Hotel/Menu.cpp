#include "Headers/Menu.h"
#include <iostream>
Menu::Menu(){
    lista = new Lista();
    listaSorted = new Lista();
}

void Menu:: acciones(){
    crearLista();
    int respuesta;
    string repetir;
    imprimirAcciones();
    cin >> respuesta;
    if (respuesta == 1){
        crearCliente();
    }
    else if( respuesta == 2){
        buscar();
    }
    else if(respuesta == 3){
        visualizar();
    }
    else if (respuesta == 4){
        sortAlfabetico();
        cout<< endl;
    }

    else if (respuesta == 5){
        getNomrbesVecinos();
    }

    else if (respuesta == 6){
        eliminar();
        visualizarSinCrear();
        cout<< "Nodo eliminado correctamente!"<< endl;
    }

    cout << "desea realizar alguna otra accion? y/n "<< endl;
    cin >> repetir;
    if (repetir == "y"){
        acciones();
    }
    else if (repetir == "n"){
        cout << "Gracias por usar el programa del Hotel"<< endl;
        return;
    }
    else if(repetir != "y" || "n"){
        cout<< " por favor ingrese un caracter valido "<< endl;
        cin>> repetir;
    }
}

void Menu :: imprimirAcciones(){
    cout << "BIENVENIDO AL MENU, SUS ACCIONES A REALIZAR SON: "<< endl;
    cout << "(1) Agregar un nuevo huesped al hotel" << endl;
    cout << "(2) Buscar un usuario por nombre o por numero de cuarto"<< endl;
    cout << "(3) Mostrar los huespedes en orden de llegada al hotel" << endl;
    cout << "(4) Mostrar los huespedes en orden alfabetico" << endl;
    cout << "(5) Mostrar el nombre de los vecinos del cuarto que desee revisar"<< endl;
    cout << "(6) Eliminar un nodo de la lista enlzada"<< endl;
    cout << "accion: ";
}

void Menu::visualizar(){
    lista->visualizarDerecha();
}

void Menu::visualizarSinCrear(){
    lista->visualizarDerecha();
}

void Menu::visualizarIzquierda(){
    lista->visualizarIzquierda();
}

void Menu:: crearCliente(){
    lista->addCliente();
}

void Menu:: buscar(){
    lista->buscar();
}
void Menu::crearLista(){
    lista->crearLista();
}
void Menu :: sortAlfabetico(){
    listaSorted->crearLista();
    listaSorted->sortAlfabetico();
    listaSorted->visualizarIzquierda();
}

void Menu :: eliminar(){
    string nombre;
    int cuarto;
    cout << "ingrese nombre a eliminar: "<< endl;
    cin >> nombre;
    cout<< "Ingrese el cuarto: "<< endl;
    cin >> cuarto;
    lista->eliminar(cuarto, nombre);
}



void Menu:: getNomrbesVecinos(){
    lista->checkNombreVecinos();
}

void Menu:: encontrarCuarto(){
    int cuarto;
    cout<< "Que cuarto desea encontrar en el archivo?"<< endl;
    cin >> cuarto;
    cout<< "el cuarto "<< cuarto<< "se encuentra en la linea: "<< lista->encontrarCuarto(cuarto)<< endl;
}