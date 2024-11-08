#ifndef CMENUCLIENTE_HPP
#define CMENUCLIENTE_HPP

#include "ccliente.hpp"
#include <fstream>  // Biblioteca para manejo de archivos

class cMenuCliente {
	private:
		ccliente** clientes;  // Arreglo dinámico de punteros a ccliente
		int numClientes;      // Número de clientes actuales
		int capacidad;        // Capacidad del arreglo

		void redimensionarArreglo(int nuevaCapacidad);

	public:
		cMenuCliente(int capacidadInicial = 10);//no redimenciono de manera inmediata 
		~cMenuCliente();

		void agregarCliente();
		void modificarCliente(int id);
		void eliminarCliente(int id);
		void mostrarCliente(int id) const;
		void mostrarTodosLosClientes() const;
		void menuPrincipal();

		// Métodos para guardar y cargar
		void guardarClientesEnArchivo(const char* nombreArchivo);
		void cargarClientesDesdeArchivo(const char* nombreArchivo);
		
		
		// Getter para el número de clientes
		int getNumClientes() const { return numClientes; }
		
		
		
};

#endif // CMENUCLIENTE_HPP
