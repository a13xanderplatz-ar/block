#include "cAlmacen.hpp"
#include <iostream>
#include <cstring>  // Para usar strlen

// Constructor
cAlmacen::cAlmacen(const cAlmacen *obj, const char *name, const char *code, size_t tam_nom, size_t tam_cod, int valor)
{   
    nombre = nullptr;
    codigo = nullptr;

    if (obj != nullptr) { // Si obj no es nulo, copiamos los valores de obj
        fecha = obj->fecha;
        size_nom = obj->size_nom;
        size_cod = obj->size_cod;
    } 
    else { 
        fecha = valor;
        // Asignamos el tamaño de los nombres y códigos si se pasan o calculamos
        size_nom = (tam_nom > 0) ? tam_nom : (name ? contador(name) : 0);
        size_cod = (tam_cod > 0) ? tam_cod : (code ? contador(code) : 0);
    }

    // Crear memoria dinámica para los punteros
    crear_memoria();

    // Copiar los valores de las cadenas en la memoria dinámica
    if (name != nullptr && size_nom > 0) {
        copiar(name, nombre, size_nom);
    }
    if (code != nullptr && size_cod > 0) {
        copiar(code, codigo, size_cod);
    }
}

// Método para imprimir
void cAlmacen::print() {
    std::cout << "Fecha: " << fecha << std::endl;
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Codigo: " << codigo << std::endl;
}

// Método para contar caracteres de una cadena
size_t cAlmacen::contador(const char *cadena) {
    return std::strlen(cadena);  // Usar la función estándar de C++
}

// Crear memoria dinámica
void cAlmacen::crear_memoria() {
    if (size_nom > 0) { // Asignar memoria para el nombre
        nombre = new char[size_nom];
    }

    if (size_cod > 0) { // Asignar memoria para el código
        codigo = new char[size_cod];
    }
}

// Copiar una cadena en un espacio de memoria
void cAlmacen::copiar(const char *name, char *cadena, size_t tam) {
    for (size_t i = 0; i < tam; i++) {
        cadena[i] = name[i];
    }
    cadena[tam - 1] = '\0'; // Asegurar que la cadena termine con '\0'
}

// Destructor
cAlmacen::~cAlmacen() {
    delete[] nombre;  // Libera la memoria asignada a nombre
    delete[] codigo;  // Libera la memoria asignada a código
}
