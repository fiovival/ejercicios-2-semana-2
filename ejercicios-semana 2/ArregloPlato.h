#pragma once
#include"Plato.h"
class ArregloPlato
{
public:
	ArregloPlato();
	~ArregloPlato();
	//agregar eliminar conseguir tamaño
	void agregar_inicio(Plato* dato);
	void agregar_final(Plato* dato);//push_back
	void agregar_en_pos(Plato* dato, int pos);
	void eliminar_inicio();
	void eliminar_final();
	void eliminar_en_pos(int pos);//erase
	Plato* conseguir(int pos);//at
	int tamanio();//size
	//-----------------------
	ArregloPlato* report1();
	ArregloPlato* report2();
private:
	Plato** arreglo;
	int n;
};

ArregloPlato::ArregloPlato(){
	n = 0;
	arreglo = new Plato*[n];
}

ArregloPlato::~ArregloPlato(){
	delete[] arreglo;
}
void ArregloPlato::agregar_inicio(Plato* dato){
	Plato** aux = new Plato*[n + 1];
	for (int i = 0; i < n; i++){
		aux[i + 1] = arreglo[i];
	}
	aux[0] = dato;
	n++;
	//--------------------magia de punteros
	delete[] arreglo;
	arreglo = aux;
	aux = nullptr;
	delete aux;
}
void ArregloPlato::agregar_final(Plato* dato) {//push_back
	Plato** aux = new Plato*[n + 1];
	for (int i = 0; i < n; i++) {
		aux[i] = arreglo[i];
	}
	aux[n] = dato;
	n++;
	//--------------------magia de punteros
	delete[] arreglo;
	arreglo = aux;
	aux = nullptr;
	delete aux;
}
void ArregloPlato::agregar_en_pos(Plato* dato, int pos){
	Plato** aux = new Plato*[n + 1];
	for (int i = 0; i < n; i++) {
		if(i<pos)
		aux[i] = arreglo[i];
		else
		aux[i+1] = arreglo[i];
	}
	aux[pos] = dato;
	n++;
	//--------------------magia de punteros
	delete[] arreglo;
	arreglo = aux;
	aux = nullptr;
	delete aux;
}
void ArregloPlato::eliminar_inicio(){
	Plato** aux = new Plato*[n - 1];
	for (int i = 0; i < n-1; i++) {
		aux[i] = arreglo[i+1];
	}
	n--;
	//--------------------magia de punteros
	delete[] arreglo;
	arreglo = aux;
	aux = nullptr;
	delete aux;
}
void ArregloPlato::eliminar_final() {
	Plato** aux = new Plato*[n - 1];
	for (int i = 0; i < n - 1; i++) {
		aux[i] = arreglo[i];
	}
	n--;
	//--------------------magia de punteros
	delete[] arreglo;
	arreglo = aux;
	aux = nullptr;
	delete aux;
}
void ArregloPlato::eliminar_en_pos(int pos) { //erase
	Plato** aux = new Plato*[n - 1];
	for (int i = 0; i < n - 1; i++) {
		if (i < pos)
			aux[i] = arreglo[i];
		else
			aux[i] = arreglo[i+1];
	}
	n--;
	//--------------------magia de punteros
	delete[] arreglo;
	arreglo = aux;
	aux = nullptr;
	delete aux;
}
Plato* ArregloPlato::conseguir(int pos) {//at
	return arreglo[pos];
}
int ArregloPlato::tamanio() {//size
	return n;
}
ArregloPlato* ArregloPlato::report1(){
	ArregloPlato* aux = new ArregloPlato();
	for (int i = 0; i < n; i++){
		if (arreglo[i]->get_picante() == 1) {
			aux->agregar_final(arreglo[i]);
		}
	}
	return aux;
}
ArregloPlato* ArregloPlato::report2(){
	ArregloPlato* aux = new ArregloPlato();
	for (int i = 0; i < n; i++) {
		if (arreglo[i]->get_precio() >= 100) {
			aux->agregar_final(arreglo[i]);
		}
	}
	return aux;
}