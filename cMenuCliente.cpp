#include "cMenuCliente.hpp"
#include <iostream>
#include <fstream>

// Constructor
cMenuCliente::cMenuCliente(int capacidadInicial)
	: numClientes(0), capacidad(capacidadInicial) {
	clientes = new ccliente*[capacidad];
}

// Destructor
cMenuCliente::~cMenuCliente() {
	for (int i = 0; i < numClientes; ++i) {
		delete clientes[i];  // Eliminar cada cliente
	}
	delete[] clientes;  // Eliminar el arreglo de punteros
}

// Redimensionar el arreglo de clientes
void cMenuCliente::redimensionarArreglo(int nuevaCapacidad) {
	ccliente** nuevoArreglo = new ccliente*[nuevaCapacidad];
	for (int i = 0; i < numClientes; ++i) {
		nuevoArreglo[i] = clientes[i];  // Copiar los punteros a los nuevos lugares
	}
	delete[] clientes;  // Liberar el arreglo antiguo
	clientes = nuevoArreglo;  // Apuntar al nuevo arreglo
	capacidad = nuevaCapacidad;
}

// Guardar los clientes en un archivo de texto
void cMenuCliente::guardarClientesEnArchivo(const char* nombreArchivo) {
	std::ofstream archivo(nombreArchivo);
	if (!archivo) {
		std::cerr << "No se pudo abrir el archivo para escribir.\n";
		return;
	}

	// Escribir los datos de cada cliente en el archivo
	for (int i = 0; i < numClientes; ++i) {
		archivo << clientes[i]->getIdCliente() << "\n"
		        << clientes[i]->getNombre() << "\n"
		        << clientes[i]->getApellido() << "\n"
		        << clientes[i]->getDni() << "\n"
		        << clientes[i]->getTelefono() << "\n"
		        << clientes[i]->getFechaDeIngreso() << "\n";
	}

	archivo.close();  // Cerrar el archivo
	std::cout << "Clientes guardados en el archivo correctamente.\n";
}

// Menú principal
void cMenuCliente::menuPrincipal() {
	int opcion;
	do {
		std::cout << "1. Agregar Cliente\n";
		std::cout << "2. Modificar Cliente\n";
		std::cout << "3. Eliminar Cliente\n";
		std::cout << "4. Mostrar Cliente\n";
		std::cout << "5. Mostrar Todos los Clientes\n";
		std::cout << "6. Guardar Clientes en Archivo\n";
		std::cout << "7. Cargar Clientes desde Archivo\n";
		std::cout << "8. Salir\n";
		std::cout << "Seleccione una opción: ";
		std::cin >> opcion;

		switch (opcion) {
			case 1: agregarCliente(); break;
			case 2: 
				int id;
				std::cout << "Ingrese ID del Cliente a modificar: ";
				std::cin >> id;
				modificarCliente(id); 
				break;
			case 3: 
				std::cout << "Ingrese ID del Cliente a eliminar: ";
				std::cin >> id;
				eliminarCliente(id); 
				break;
			case 4: 
				std::cout << "Ingrese ID del Cliente a mostrar: ";
				std::cin >> id;
				mostrarCliente(id); 
				break;
			case 5: mostrarTodosLosClientes(); break;
			case 6: 
				guardarClientesEnArchivo("clientes.txt"); 
				break;
			case 7: 
				cargarClientesDesdeArchivo("clientes.txt"); 
				break;
		}
	} while (opcion != 8);
}

