#include "cPrenda.hpp"
#include "cAlmacen.hpp"
#include "cMenuCliente.hpp"
#include "ccliente.hpp"
#include <iostream>

#ifdef _WIN32
    #include <windows.h>
    #define CLEAR_COMMAND "cls"
#elif defined(__APPLE__) || defined(__MACH__) || defined(__linux__)
    #include <unistd.h>
    #include <termios.h>
    #define CLEAR_COMMAND "clear"
#endif

int main() {
    // Crear objeto de la clase cPrenda y mostrar su información
    cPrenda lola(nullptr, 10.2, 4);
    lola.print();
    
    // Inicializar datos para cAlmacen
    char nombre[40] = "Lola";
    char codigo[40] = "3048573";
    
    cAlmacen almacen1(nullptr, nombre, codigo, -1, -1, 13);
    almacen1.print();
    
    /**********************************************************************************************************************/
    // Crear el menú para gestionar clientes
    cMenuCliente menu;
    menu.menuPrincipal();  // Llamamos al menú principal para gestionar clientes

    // Ejemplo de cómo usar getNumClientes en main (obtenemos el número de clientes)
    std::cout << "Número total de clientes: " << menu.getNumClientes() << std::endl;
    /************************************************************************************************************************/

    int opcion;
    do {
        std::cout << "======== MENU DE CLIENTES ========\n";
        std::cout << "1. Agregar Cliente\n";
        std::cout << "2. Modificar Cliente\n";
        std::cout << "3. Eliminar Cliente\n";
        std::cout << "4. Mostrar Cliente\n";
        std::cout << "5. Mostrar Todos los Clientes\n";
        std::cout << "6. Guardar Clientes en Archivo\n";
        std::cout << "7. Cargar Clientes desde Archivo\n";
        std::cout << "0. Salir\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;
        
        switch (opcion) {
            case 1:
                menu.agregarCliente();
                break;
            case 2: {
                int id;
                std::cout << "Ingrese ID del cliente a modificar: ";
                std::cin >> id;
                menu.modificarCliente(id);
                break;
            }
            case 3: {
                int id;
                std::cout << "Ingrese ID del cliente a eliminar: ";
                std::cin >> id;
                menu.eliminarCliente(id);
                break;
            }
            case 4: {
                int id;
                std::cout << "Ingrese ID del cliente a mostrar: ";
                std::cin >> id;
                menu.mostrarCliente(id);
                break;
            }
            case 5:
                menu.mostrarTodosLosClientes();
                break;
            case 6: {
                char nombreArchivo[50];
                std::cout << "Ingrese el nombre del archivo para guardar: ";
                std::cin >> nombreArchivo;
                menu.guardarClientesEnArchivo(nombreArchivo);
                break;
            }
            case 7: {
                char nombreArchivo[50];
                std::cout << "Ingrese el nombre del archivo para cargar: ";
                std::cin >> nombreArchivo;
                menu.cargarClientesDesdeArchivo(nombreArchivo);
                break;
            }
            case 0:
                std::cout << "Saliendo del sistema.\n";
                break;
            default:
                std::cout << "Opción inválida. Intente de nuevo.\n";
                break;
        }
        std::cout << "\n";
    } while (opcion != 0);

    return 0;
}
