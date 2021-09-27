#pragma once
#include <string>
#include <fstream>
#include <sys/stat.h> 
#include <sstream> 
#include"ListaDoble.h"
#include"ListaDoble.h"
#include"ListaSimple.h"
#include "Usuario.h"
class Red{
private:
	ListaSimple<UsuarioPropietario*>* redUsuarios;

public:
	Red() {
		function<void(UsuarioPropietario*)> imprimir = [](UsuarioPropietario* objU) {
			cout << objU->getCuenta() << "\n";
		};
		redUsuarios = new ListaSimple<UsuarioPropietario*>(imprimir);
		mkdir("Red");
	};
	void AgregarUsuario(string cuenta) {
		
		redUsuarios->Insertar(new UsuarioPropietario(cuenta));
	}
	void MostrarUsuarios(){
		redUsuarios->Imprimir();
	}
	
	UsuarioPropietario* getUsuario(string cuenta){
		for(int i=0; i < redUsuarios->GetTamaño();i++){
			if(redUsuarios->obtenerxPos(i)->getCuenta()==cuenta){
				return redUsuarios->obtenerxPos(i);
			}
		}
	}

};

