// #ifndef CPRENDA_HPP  
// #define CPRENDA_HPP  

// class cPrenda
// {
    // public:
    // float cantidad;
    // float precio_unitario;
    // float monto_total;
    // int num_modelos;
    
    // cPrenda( const cPrenda *obj = nullptr,double negative = -1.0, int nopositive= -1);//obj no modif,icar
    
    // void print();
    // void offset();
// };

// #endif
#ifndef CPRENDA_HPP  
#define CPRENDA_HPP  

class cPrenda
{
    public:
    float cantidad;
    float precio_unitario;
    float monto_total;
    int num_modelos;
    
    // Constructor con parámetros por defecto
    cPrenda(const cPrenda* obj = nullptr, double valorInicial = 0.0, int numModelosInicial = 0);

    // Destructor
    ~cPrenda();

    // Método para imprimir los detalles de la prenda
    void print() const;

    // Método para aplicar algún ajuste a los valores
    void offset(); 
};

#endif
