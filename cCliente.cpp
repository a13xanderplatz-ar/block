#include "ccliente.hpp"
#include <cstring>

// Constructor por defecto
ccliente::ccliente() : 
    idCliente(0), 
    nombre(nullptr), 
    apellido(nullptr),
    dni(0),
    telefono(0),
    fechadeIngreso(0),
    montoCompra(0.0f) 
{
}

// Destructor
ccliente::~ccliente() {
    delete[] nombre;
    delete[] apellido;
}

// Implementación de setNombre
void ccliente::setNombre(const char* nuevoNombre) {
    delete[] nombre;
    nombre = nullptr;
    
    if (nuevoNombre == nullptr) {
        return;
    }
    
    int len = 0;
    while (nuevoNombre[len] != '\0') len++;
    
    nombre = new char[len + 1];
    for (int i = 0; i <= len; i++) {
        nombre[i] = nuevoNombre[i];
    }
}

// Implementación de setApellido
void ccliente::setApellido(const char* nuevoApellido) {
    delete[] apellido;
    apellido = nullptr;
    
    if (nuevoApellido == nullptr) {
        return;
    }
    
    int len = 0;
    while (nuevoApellido[len] != '\0') len++;
    
    apellido = new char[len + 1];
    for (int i = 0; i <= len; i++) {
        apellido[i] = nuevoApellido[i];
    }
}