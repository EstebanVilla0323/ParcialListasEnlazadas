#include "Headers/Lista.h"
#include "Headers/Nodo.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

Lista::Lista() { head = NULL; tail = NULL;}

void Lista::crearLista() {
    head = NULL;
    tail = NULL;
    string n;
    int x;
    ifstream infile("nombres.txt");
    while (infile >> n >> x) {
        head = insertarCabezaLista(x,n);
    }

    infile.close();
}


Nodo * Lista::insertarCabezaLista(int entrada, string nombre) {
    Nodo *nuevo;
    nuevo = new Nodo(entrada,nombre,head,NULL);
    if (head != NULL) {
        head->ponerEnlacePrev(nuevo);
    } else {
        tail = nuevo;
    }
    head = nuevo;
    return nuevo;
}

Nodo* Lista::insertarColaLista(int entrada, string nombre) {
    Nodo* nuevo = new Nodo(entrada, nombre, NULL, tail);
    if (tail != NULL) {
        tail->ponerEnlaceNext(nuevo);
    }
    if (head == NULL) {
        head = nuevo;
    }
    tail = nuevo;
    return nuevo;
}


void Lista::visualizarIzquierda() {
    Nodo *n;
    int k = 0;
    n = head;
    while (n != NULL) {
        char c;
        k++;
        c = (k % 8 != 0 ? ' ' : '\n');
        cout << n->getNombreNodo()<< ": " << n->getCuartoNodo()<< "|" << c;
        n = n->getEnlaceNext();
    }
}

void Lista::visualizarDerecha() {
    Nodo *n;
    int k = 0;
    n = tail;
    while (n != NULL) {
        char c;
        k++;
        c = (k % 8 != 0 ? ' ' : '\n');
        cout << n->getNombreNodo()<< " :" << n->getCuartoNodo()<< "|" << c;
        n = n->getEnlacePrev();
    }
    cout << endl;
}



void Lista::buscar() {
    Nodo* n = head;
    int respuesta;
    cout << "Desea encontrar al cliente por nombre (1) o por cuarto (2)?" << endl;
    cin >> respuesta;
    if (respuesta == 1) {
        string nombre;
        cout << "Ingrese el nombre a buscar: " << endl;
        cin >> nombre;
        while (n != NULL) {
            if (n->getNombreNodo() == nombre) {
                cout << "El cuarto de " << nombre << " es: " << n->getCuartoNodo() << endl;
                return;
            } else {
                n = n->getEnlaceNext();
            }
        }
    }
    if (respuesta == 2) {
        int cuarto;
        cout << "Ingrese el cuarto a buscar: " << endl;
        cin >> cuarto;
        while (n != NULL) {
            if (n->getCuartoNodo() == cuarto) {
                cout << "El nombre de la persona en el cuarto " << cuarto << " es: " << n->getNombreNodo() << endl;
                return;
            } else {
                n = n->getEnlaceNext();
            }
        }
    }
    cout << "No se encontro el huesped buscado." << endl;
}


void Lista::eliminar(int entrada, string nombre) {
    Nodo *actual, *anterior;
    bool nombreEncontrado, cuartoEncontrado;
    actual = head;
    anterior = NULL;
    nombreEncontrado = false;
    cuartoEncontrado = false;
    while (actual != NULL && !(nombreEncontrado && cuartoEncontrado)) {
        nombreEncontrado = (actual->getNombreNodo() == nombre);
        cuartoEncontrado = (actual->getCuartoNodo() == entrada);
        if (!(nombreEncontrado && cuartoEncontrado)) {
            anterior = actual;
            actual = actual->getEnlaceNext();
        }
    }
    if (actual != NULL && nombreEncontrado && cuartoEncontrado) {
        if (anterior != NULL) {
            anterior->ponerEnlaceNext(actual->getEnlaceNext());
        } else {
            head = actual->getEnlaceNext();
        }
        if (actual->getEnlaceNext() != NULL) {
            actual->getEnlaceNext()->ponerEnlacePrev(anterior);
        }
        delete actual;
    }
}

bool Lista::checkCuarto(int cuarto){
    Nodo* actual;
    actual = head;
    while (actual != NULL){
        if (cuarto == actual->getCuartoNodo()){
            return false;
        }
        else{
            actual = actual->getEnlaceNext();
        }
    }
    return true;
}

int Lista::checkVecinos(int cuarto) {
    if (!checkCuarto(cuarto)) {
        string respuesta;
        cout << "El cuarto " << cuarto << " esta ocupado, desea revisar los cuartos vecinos? (y/n)" << endl;
        cin >> respuesta;
        if (respuesta == "y") {
            bool vecinoAnt = checkCuarto(cuarto-1);
            bool vecinoNext = checkCuarto(cuarto+1);
            if (!vecinoAnt && !vecinoNext) {
                cout << "No hay cuartos disponibles cerca de " << cuarto << ", por favor ingrese un numero de cuarto distinto: " << endl;
                cin >> cuarto;
                return checkVecinos(cuarto);
            } else if (vecinoAnt) {
                cout << "El cuarto " << cuarto-1 << " esta disponible." << endl;
                return cuarto - 1;
            } else if (vecinoNext) {
                cout << "El cuarto " << cuarto+1 << " esta disponible." << endl;
                return cuarto + 1;
            }
        }

        else if (respuesta == "n"){
            cout << "Gracias por querer hospedarse en nuestro hotel "<< endl;
            return -1;
        }
    } else {
        cout << "El cuarto " << cuarto << " esta disponible." << endl;
        return cuarto;
    }
}
void Lista::addCliente() {
    fstream myFile;
    myFile.open("nombres.txt", ios::app);
    string nombre;
    int cuarto;
    cout << "Ingrese cuarto del cliente: " << endl;
    cin >> cuarto;
    cuarto = checkVecinos(cuarto);
    if(cuarto == -1){
        return;
    }
    cout << "Ingrese nombre del cliente: " << endl;
    cin >> nombre;
    Nodo *n = new Nodo(cuarto,nombre,NULL, NULL);
    tail->ponerEnlaceNext(n);
    n->ponerEnlacePrev(tail);
    tail = n;
    if (myFile.is_open()) {
        myFile << nombre << "\n";
        myFile << cuarto << "\n";
        myFile.close();
    }
}

void Lista :: checkNombreVecinos( ){
    int cuarto;
    bool cuartoEncontrado = false;
    Nodo* n = head;
    cout << "Ingrese el cuarto del cual desea revisar los vecinos: "<< endl;
    cin >> cuarto;
    while (!cuartoEncontrado){
        if (cuarto == n->getCuartoNodo()){
            cuartoEncontrado = true;
        }
        else{
            n = n->getEnlaceNext();
        }
    }
    cout << "Los nombres de los vecinos del cuarto " << cuarto<< " son: "<< endl;
    cout<< n->getEnlacePrev()->getNombreNodo()<< " y " << n->getEnlaceNext()->getNombreNodo()<< endl;
}


void Lista:: sortAlfabetico() {
    Nodo *actual = head;
    Nodo *sig = NULL;
    string temp;
    int tempo;

    while (actual != NULL) {
        sig = actual->getEnlaceNext();
        while (sig != NULL) {
            if (actual->getNombreNodo() > sig->getNombreNodo()) {
                temp = actual->getNombreNodo();
                tempo = actual->getCuartoNodo();
                actual->setNombre(sig->getNombreNodo());
                actual->setCuarto(sig->getCuartoNodo());
                sig->setCuarto(tempo);
                sig->setNombre(temp);
            }
            sig = sig->getEnlaceNext();
        }
        actual = actual->getEnlaceNext();
    }
}

int Lista::encontrarCuarto(int cuarto){
    ifstream infile("nombres.txt");
    string nombre;
    int numeroC;
    int contador;

    while(infile>>nombre>>numeroC){
        contador += 2;
        if (numeroC == cuarto){
            return contador;
        }
    }
    infile.close();
}



