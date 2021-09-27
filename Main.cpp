#include<iostream>
#include <windows.h>
#include "conio.h"
#include <cstdlib>
#include"Menu.h"
#include"Red.h"
using namespace std;

void PantallaInicio(Red*& red,UsuarioPropietario*& usuario,int&pantalla) {
    string linea;
    string nombreusuario;
    MenuInicio(); 
    linea = GetUsuario();
    //Creacion de Usuario
      //Usuario Nuevo
    if (linea=="New"){ 
        cin >> nombreusuario;
        red->AgregarUsuario(nombreusuario);
        usuario = red->getUsuario(nombreusuario);
        pantalla = 2;
    }
    else{
        usuario = red->getUsuario(linea);
        pantalla = 2;
	}
}
void PantallaMenuArchivos(Red*& red,UsuarioPropietario*& usuario,Archivo*& arch,int&pantalla) {
    int opcion = MenuArchivos(usuario->getCuenta());
    string nom;
    string linea;
    if(opcion==1){
        cout << "\nIngrese un nombre para el archivo:";
        cin >> nom;
        usuario->CrearArchivo(nom);
        pantalla = 2;
	}
    if(opcion==2){
        cout << "\nIngrese un nombre para el archivo:";
        cin >> nom;
        usuario->getArchivo(nom)->AbrirArchivo();
        pantalla = 2;
	}
    if(opcion==3){
        int op;
        cout << "\nIngrese un nombre para el archivo para hacer la busqueda:";
        cin >> nom;
        Busqueda();
        do {
            cout << "Ingrese una opcion:";
            cin >> op;
        }while (busquedaArchivo(op));
        
        cin >> linea;
	}
    if(opcion==4){
        string comen;
        cout << "\nIngrese usuario para comentar un archivo: ";
        cin >> linea;
        cout << "\nIngrese un archivo del usuario elegido para comentarlo: ";
        cin >> nom;
        cout << "\nIngrese su comentario: ";
        cin >> comen;
        red->getUsuario(linea)->getArchivo(nom)->ComentarArchivo(comen,nom);
        pantalla = 2;
	}
    if(opcion==5){
        pantalla = 1;
	}
}
int main() {
    Red* red=new Red();
    UsuarioPropietario* usuario;
    Archivo* arch;
    int pantalla = 1;
    while (1) {
        if (pantalla == 1) {
            Console::SetWindowSize(76, 30);
            PantallaInicio(red,usuario,pantalla);
        }
        if (pantalla == 2) {
            Console::SetWindowSize(72, 30);
            PantallaMenuArchivos(red,usuario,arch,pantalla);
        }

    }
    system("pause>0");
    return 0;
}