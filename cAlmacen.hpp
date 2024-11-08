#ifndef CALMACEN_HPP  
#define CALMACEN_HPP  

#include <cstddef>  // Necesario para usar size_t

class cAlmacen
{
public:
    char *nombre = nullptr;
    char *codigo = nullptr;
    int fecha = 0;
    size_t size_nom = 0;
    size_t size_cod = 0;

    cAlmacen(const cAlmacen *obj = nullptr, const char *name = nullptr, const char *code = nullptr, 
             size_t tam_nom = 0, size_t tam_cod = 0, int valor = -1);

    ~cAlmacen();

    void print();
    void crear_memoria();
    void copiar(const char *name, char *cadena, size_t tam);
    size_t contador(const char *cadena);  // Cambiar int a size_t
    void offset();  
};

#endif // CALMACEN_HPP
