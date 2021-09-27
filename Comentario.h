#pragma once
#include <fstream>
#include <sstream>
#include<iostream>
#include<functional>
using namespace std;

class Comentario{
private:
	string comentario;
	string comentador;

public:
	Comentario(string comentario,string comentador,string ruta,string nomArch){
		this->comentario = comentario;
		this->comentador = comentador;
		fstream archivo(ruta + "/coments" + nomArch + ".txt", ios::app);
		archivo.close();
	}
	string getComentador(){
		return comentador;
	}
	string getComentario(){
		return comentario;
	}
};

