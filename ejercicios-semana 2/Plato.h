#pragma once
#include"iostream"
using namespace std;
string nombres[5] = { "Marco","Luis","Pedro","Mateo","Camila" };
class Plato{
public:
	Plato();
	~Plato();
	string get_nombre();
	bool get_calor();
	short get_picante();
	short get_calorias();
	float get_precio();
	void set_nombre(string dato);
	void set_calor(bool dato);
	void set_picante(short dato);
	void set_calorias(short dato);
	void set_precio(float dato);

private:
	string nombre;
	bool calor;
	short calorias;
	short picante;
	float precio;
};

Plato::Plato(){
	nombre = nombres[rand() % 5];
	calor = rand() % 2;
	picante = rand() % 2;
	calorias = rand() % 501 + 500;
	precio = float (rand() % (3000-1000+1))/10 + 10.0;
}

Plato::~Plato(){}
string Plato::get_nombre() { return nombre; }
bool Plato::get_calor() { return calor; }
short Plato::get_picante() { return picante; }
short Plato::get_calorias() { return calorias; }
float Plato::get_precio() { return precio; }
void Plato::set_nombre(string dato) { nombre = dato; }
void Plato::set_calor(bool dato) { calor = dato; }
void Plato::set_picante(short dato) { picante = dato; }
void Plato::set_calorias(short dato) { calorias = dato; }
void Plato::set_precio(float dato) { precio = dato; }
