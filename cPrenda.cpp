// #include "cPrenda.hpp"
// #include <iostream>
// cPrenda::cPrenda(const cPrenda *obj, double negative, int nopositive)
// {

    // if (obj != nullptr) { // Si obj no es nulo, copiamos los valores de obj
        // cantidad = (*obj).cantidad;
        // precio_unitario =  (*obj).precio_unitario;
        // monto_total =  (*obj).monto_total;
        // num_modelos =  (*obj).num_modelos;
    // } 
    // else { 
        // cantidad = negative;
        // precio_unitario = negative;
        // monto_total = negative;
        // num_modelos = nopositive; // Convertimos lola a int para num_modelos
		
    // } 
// }

// void cPrenda::print()
// {
    // std::cout<<"cantidad: "<< cantidad<<std::endl;
    // std::cout<<"PRECIO UNITARIO: " <<precio_unitario<<std::endl;
    // std::cout<<"MONTO TOTAL: " <<monto_total<<std::endl;
    // std::cout<<"NUMERO DE MODELOS: " <<num_modelos<<std::endl;
// }

#include "cPrenda.hpp"
#include <iostream>

cPrenda::cPrenda(const cPrenda* obj, double valorInicial, int numModelosInicial)
{
    if (obj != nullptr) { // Si obj no es nulo, copiamos los valores de obj
        cantidad = obj->cantidad;
        precio_unitario = obj->precio_unitario;
        monto_total = obj->monto_total;
        num_modelos = obj->num_modelos;
    } else { 
        cantidad = valorInicial;
        precio_unitario = valorInicial;
        monto_total = valorInicial;
        num_modelos = numModelosInicial;
    }
}

// Destructor
cPrenda::~cPrenda()
{
    // En este caso, no hay memoria dinámica que liberar,
    // pero se podría agregar código para liberar recursos si fuera necesario.
    std::cout << "Destruyendo objeto cPrenda..." << std::endl;
}

void cPrenda::print() const
{
    std::cout << "Cantidad: " << cantidad << std::endl;
    std::cout << "Precio unitario: " << precio_unitario << std::endl;
    std::cout << "Monto total: " << monto_total << std::endl;
    std::cout << "Número de modelos: " << num_modelos << std::endl;
}

void cPrenda::offset()
{
    // Aquí podrías agregar código para aplicar ajustes o modificaciones
}
