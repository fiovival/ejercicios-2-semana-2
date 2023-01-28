#include"ArregloPlato.h"
#include"conio.h"
void imprimir(ArregloPlato* arreglo) {
	cout << "indice\tnombre\tcalor\tpican\tcaloria\tprecio\n";
	for (int i = 0; i < arreglo->tamanio(); i++){
		cout << i + 1 << "\t" << arreglo->conseguir(i)->get_nombre() << "\t"
			<< arreglo->conseguir(i)->get_calor() << "\t" 
			<< arreglo->conseguir(i)->get_picante() << "\t" 
			<< arreglo->conseguir(i)->get_calorias() << "\t" 
			<< arreglo->conseguir(i)->get_precio() << endl;
	}
	cout << endl;
}
void agregar(ArregloPlato* arreglo) {
	arreglo->agregar_final(new Plato());
}
void eliminar(ArregloPlato* arreglo) {
	imprimir(arreglo);
	int indice;
	cin >> indice;
	arreglo->eliminar_en_pos(indice - 1);
}
void modificar(ArregloPlato* arreglo) {
	string aux;
	bool aux1;
	bool aux2;
	float aux3;
	imprimir(arreglo);
	int indice;
	cin >> indice;
	int seleccion;
	cin >> seleccion;
	switch (seleccion)
	{
	case 1:	cin>>aux;arreglo->conseguir(indice-1)->set_nombre(aux);break;
	case 2:	cin>>aux1;arreglo->conseguir(indice-1)->set_calor(aux1);break;
	case 3:	cin>>aux1;arreglo->conseguir(indice-1)->set_picante(aux1);break;
	case 4:	cin>>aux2;arreglo->conseguir(indice-1)->set_calorias(aux2);break;
	case 5:	cin>>aux3;arreglo->conseguir(indice-1)->set_precio(aux3);break;
	}
}
void menu() {
	ArregloPlato* arreglo = new ArregloPlato();
	bool termino = true;
	while (true) {
		int opcion;
		cin >> opcion;
		switch (opcion)
		{
		case 1:	imprimir(arreglo); break;
		case 2:	agregar(arreglo); break;
		case 3:	eliminar(arreglo); break;
		case 4:	modificar(arreglo); break;
		case 5:	imprimir(arreglo->report1()); break;
		case 6:	imprimir(arreglo->report2()); break;
		case 7:	break;
		case 8:	break;
		case 9:	break;
		case 0: termino = false; break;
		default:break;
		}
		_getch();
		system("cls");
	}
	delete arreglo;
}
void main() {
	srand(time(0));
	menu();
}