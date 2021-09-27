#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
using namespace System;

void MenuInicio() {
	Console::Clear();
	cout << "***************************** BIENVENIDO ***********************************\n";
	cout << "**  Para crear una nueva cuenta, ingrese el comando New y, despues de un  **\n"
		<< "**  espacio, tu nombre de usuario y, despues de un guion bajo, tu correo  **\n";
	cout << "**  Para ingresar a tu cuenta, simplemente escribe tu usuario completo,   **\n"
		<< "**  es decir, tu nombre de usuario y, despues de un guion bajo, tu correo **\n";
	cout << "********************************CREDITOS************************************\n";
	cout << "** \t+Emilia Duran                                                     **\n";
	cout << "** \t+Diego                                                            **\n";
	cout << "** \t+Cristhian Orosco                                                 **\n";
	cout << "****************************************************************************\n";

}
string GetUsuario() {
	string linea;
	cout << "\n \nIngrese su cuenta o cree una: ";
	cin >> linea;
	return linea;
}
int MenuArchivos(string usuario) {
	Console::Clear();
	int opcion;
	cout << "Usuario: " << usuario << "\n\n\n";
	cout << "*********************************MENU*******************************\n\n\n\n";
	cout << "     1.- Crear Archivo\n     2.- Abrir Archivo\n     3.- Busqueda de Archivos\n     4.- Comentar Archivo\n     5.- Regresar\n";
	cout << "\nIngrese una opcion: ";
	cin >> opcion;
	return opcion;
}
void Busqueda() {
	Console::Clear();
	cout << "****************************BUSQUEDA DE DATOS****************************\n\n\n\n";
	cout << "     1.- Igual a\n     2.- Inicia con\n     3.- Finaliza con\n     4.- Esta contenido en\n     5.- No esta contenido en\n\n";
}
bool busquedaArchivo(int opcion) {
	if (opcion == 1) {
		cout << "\nIngrese nombre del archivo: ";
		return true;
	}
	else if (opcion == 2) {
		cout << "\nIngrese letra inicial: ";
		return true;
	}
	else if (opcion == 3) {
		cout << "\nIngrese letra final: ";
		return true;
	}
	else if (opcion == 4) {
		cout << "\nIngrese el texto contenido: ";
		return true;
	}
	else if (opcion == 5) {
		cout << "\nIngrese el texto no contenido: ";
		return true;
	}
	else {
		cout << "\nOpcion Incorrecta";
		getch();
		return false;
	}
}
string getOpcion() {
	string opcion;
	cout << "\nIngrese una opcion: ";
	cin >> opcion;
	return opcion;
}