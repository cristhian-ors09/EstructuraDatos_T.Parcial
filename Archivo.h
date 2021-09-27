#pragma once
#include"ListaDoble.h"
#include"Comentario.h"
#include <fstream>
#include <sstream>
#include<iostream>
#include<functional>


class Archivo{
private: 
	string nombre;
	string ruta;
	string autor;
	ListaDoble<Comentario*>* comentarios;
	
public:
	Archivo(string nombre, string autor,string ruta) {

		function<void(Comentario*)> imprimir = [](Comentario* objC) {
			cout << objC->getComentador() << ":    "<<objC->getComentario()<<"\n";
		};
		comentarios = new ListaDoble<Comentario*>(imprimir);
		this->nombre = nombre;
		this->ruta = ruta;
		this->autor = autor;
		fstream archivo(ruta + "/" + nombre, ios::app);
		archivo.close();
	}

	void AbrirArchivo(){
		string linea = "Red\\" + autor + "\\" + nombre;
		system(linea.c_str());
	}
	void MostrarArchivo() {
		string linea;
		fstream archivo(ruta + "/" + nombre, ios::in);
		while(getline(archivo,linea)){
			cout << linea << "\n";
		}
		archivo.close();
	}
	void ComentarArchivo(string comentario,string autor){
		comentarios->agregarFinal(new Comentario(comentario,autor,ruta,nombre));
	}
	string getNombre(){
		return nombre;
	}
};

