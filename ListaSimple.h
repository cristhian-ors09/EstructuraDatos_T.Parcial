#pragma once
#include<iostream>
#include"Nodo.h"
#include"Usuario.h"
#include <string>
#include <functional>
using namespace std;

//ENLACE SIMPLE 
template<class T>
class ListaSimple{
private: 
    function<void(T)> imprimir;
	Nodo<T>* inicio;
    int tamaño; 
public:
	ListaSimple(function<void(T)> imprimir) {
        this->imprimir = imprimir;
		this->inicio = nullptr;
        this->tamaño = 0;
	};
    void Imprimir(){
        Nodo<T>* aux = inicio;
        for (int i = 0; i < tamaño; i++) {
            imprimir(aux->elemento);
            aux = aux->siguiente;
        }
    }
	void Insertar(T elemento) {
        Nodo<T>* nuevo = new Nodo<T>(elemento);
        // 0 elementos
        if (inicio == nullptr) {
            inicio = nuevo;
        }

        //+1 elemento
        else {
            Nodo<T>* aux = inicio;
            while (aux->siguiente != nullptr) {
                aux = aux->siguiente;
            }
            aux->siguiente = nuevo;
        }
        tamaño++;
	}
	void InsertarInicio(T elemento) {
        Nodo<T>* nuevo = new Nodo<T> (elemento);
        if (!inicio) {
            inicio = nuevo;
        }
        else {
            Nodo* aux = inicio;
            nuevo->siguiente = inicio;
            inicio = nuevo;
            while (aux) {
                aux = aux->siguiente;
            }
        }
        tamaño++;
	}
	void InsertarFinal(T elemento){
        Nodo<T>* nuevo = new Nodo<T> (elemento);
        Nodo<T>* aux = inicio;

        if (!inicio) {
            inicio = nuevo;
        }
        else {
            while (aux->siguiente != NULL) {
                aux = aux->siguiente;
            }
            aux->siguiente = nuevo;
        }
        tamaño++;
    }
    
    int GetTamaño() {
        return tamaño;
    }
    T obtenerxPos(int pos)
    {
        if (pos >= 0 && pos < tamaño)
        {
            Nodo<T>* aux = inicio;
            for (int i = 0; i < pos; i++)
            {
                aux = aux->siguiente;
            }
            return aux->elemento;
        }
    }
};

