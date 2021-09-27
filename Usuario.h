#pragma once

#include"ListaSimple.h"
#include"Archivo.h"
#include <direct.h>
#include "Archivo.h"
using namespace std; 
#include<string>
class UsuarioPropietario{
private:
	string cuenta;
	ListaDoble<Archivo*>* Archivos; 
	string ruta;
public:
	UsuarioPropietario(string cuenta) {	
		this->cuenta = cuenta;
		function<void(Archivo*)> imprimir = [](Archivo* objA) {
			cout << objA->getNombre() << "\n";
		};
		Archivos=new ListaDoble<Archivo*>(imprimir); 
		ruta = "Red/" + cuenta;
		mkdir(ruta.c_str());
	}
	string getCuenta(){
		return cuenta;
	}
	void CrearArchivo(string nombre){
		Archivos->agregarFinal(new Archivo(nombre,cuenta,ruta));
	}
	void MostrarArchivos(){
		Archivos->Imprimir();
	}
	void MostrarArchivo(string nombre){
		for(int i=0;i<Archivos->getLongitud();i++){
			if (Archivos->obtenerxPos(i)->getNombre() == nombre) {
				Archivos->obtenerxPos(i)->MostrarArchivo();
				break;
			}
		}
	}
	Archivo* getArchivo(string nombre){
		for(int i=0;i<Archivos->getLongitud();i++){
			if (Archivos->obtenerxPos(i)->getNombre() == nombre)
				return Archivos->obtenerxPos(i);
		}
	}

};

