#include "cprecio.hpp"
#include <cstring>

// Función auxiliar para calcular longitud
int longitud(const char* cadena) {
    if (cadena == nullptr) return 0;
    int i = 0;
    while (cadena[i] != '\0') {
        i++;
    }
    return i;
}

// Constructor
cprecio::cprecio() {
    // Los miembros ya están inicializados en el hpp mediante inicialización uniforme
    // idProducto{0}, precio{0.0f}, descuento{0.0f}, 
    // fechaDeVencimiento{0}, cantidadEnInventario{0}
    // nombreProducto = nullptr
}

// Destructor
cprecio::~cprecio() {
    delete[] nombreProducto;
}

// Implementación de setNombreProducto
void cprecio::setNombreProducto(const char* nombre) {
    // Liberar memoria existente
    delete[] nombreProducto;
    nombreProducto = nullptr;
    
    if (nombre != nullptr) {
        int len = longitud(nombre);
        nombreProducto = new char[len + 1];  // +1 para el caracter nulo
        for (int i = 0; i <= len; i++) {  // <= para incluir el caracter nulo
            nombreProducto[i] = nombre[i];
        }
    }
}