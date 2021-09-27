#pragma once
#include <functional>
using namespace std;
typedef unsigned int uEntero;

template<typename T>
class ListaDoble {
	struct Nodo {
		T elemento;
		Nodo* sgte;
		Nodo* ant;
		Nodo(T elemento = nullptr, Nodo* sgte = nullptr, Nodo* ant = nullptr) :elemento(elemento), sgte(sgte), ant(ant) {}
	};

	Nodo* raiz;
	uEntero longitud;
	function<void(T)> imprimir;

public:

	ListaDoble(function<void(T)> imprimir) :raiz(nullptr), longitud(0), imprimir(imprimir) {}
	~ListaDoble() {}
	void Imprimir()
	{
		Nodo* aux = raiz;
		for (int i = 0; i < longitud; i++)
		{
			imprimir(aux->elemento);
			aux = aux->sgte;
		}
	}
	uEntero getLongitud() {
		return longitud;
	}
	bool esVacia() {
		return longitud == 0;
	}
	void agregarInicio(T elemento) {
		if (longitud == 0) {
			Nodo* nuevo = new Nodo(elemento, raiz);
			raiz = nuevo;
			longitud++;
		}
		else {
			Nodo* nuevo = new Nodo(elemento, raiz);
			raiz->ant = nuevo;
			raiz = nuevo;
			longitud++;
		}
	}
	void agregarPosicion(T elemento, uEntero pos) {
		if (pos > longitud)return;
		if (pos == 0) {
			agregarInicio(elemento);
		}
		if (pos > 0 && pos < longitud) {
			Nodo* aux = raiz;
			for (int i = 1; i < pos; i++) {
				aux = aux->sgte;
			}
			Nodo* nuevo = new Nodo(elemento, aux->sgte, aux);
			aux->sgte->ant = nuevo;
			aux->sgte = nuevo;
			longitud++;
		}
		if (pos == longitud) {
			Nodo* aux = raiz;
			for (int i = 1; i < pos; i++) {
				aux = aux->sgte;
			}
			Nodo* nuevo = new Nodo(elemento, aux->sgte, aux);
			aux->sgte = nuevo;
			longitud++;

		}
	}
	void agregarFinal(T elemento) {
		agregarPosicion(elemento, longitud);
	}
	void modificarInicio(T newElemento) {
		if (longitud > 0) {
			raiz->elemento = newElemento;
		}
	}
	void modificarPosicion(T newElemento, uEntero pos) {
		if (pos >= 0 && pos < longitud) {
			Nodo* aux = raiz;
			for (int i = 0; i < pos; i++) {
				aux = aux->sgte;
			}
			aux->elemento = newElemento;
		}
	}
	void modificarFinal(T newElemento) {
		modificarPosicion(newElemento, longitud - 1);
	}
	
	T obtenerxPos(uEntero pos) {
		if (pos >= 0 && pos < longitud) {
			Nodo* aux = raiz;
			for (int i = 0; i < pos; i++) {
				aux = aux->sgte;
			}
			return aux->elemento;
		}
		else
			return nullptr;
	}

};
