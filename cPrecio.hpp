#ifndef CPRECIO_HPP
#define CPRECIO_HPP

class cprecio {
    private:
        int idProducto{0};               // Identificador único para el producto
        char* nombreProducto = nullptr;  // Nombre del producto
        float precio{0.0f};              // Precio del producto
        float descuento{0.0f};           // Descuento aplicado al producto (en porcentaje)
        int fechaDeVencimiento{0};       // Fecha de vencimiento del producto (formato YYYYMMDD)
        int cantidadEnInventario{0};     // Cantidad de unidades disponibles en inventario

    public:
        cprecio();                       // Constructor
        ~cprecio();                      // Destructor

        // Métodos set
        void setIdProducto(int id) { idProducto = id; }
        void setNombreProducto(const char* nombre);
        void setPrecio(float nuevoPrecio) { precio = nuevoPrecio; }
        void setDescuento(float nuevoDescuento) { descuento = nuevoDescuento; }
        void setFechaDeVencimiento(int fecha) { fechaDeVencimiento = fecha; }
        void setCantidadEnInventario(int cantidad) { cantidadEnInventario = cantidad; }

        // Métodos get
        int getIdProducto() const { return idProducto; }
        const char* getNombreProducto() const { return nombreProducto; }
        float getPrecio() const { return precio; }
        float getDescuento() const { return descuento; }
        int getFechaDeVencimiento() const { return fechaDeVencimiento; }
        int getCantidadEnInventario() const { return cantidadEnInventario; }

        // Método para calcular el precio con descuento
        float calcularPrecioConDescuento() const {
            return precio - (precio * descuento / 100.0f);
        }
};

#endif // CPRECIO_HPP
