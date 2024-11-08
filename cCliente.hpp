#ifndef CCLIENTE_HPP
#define CCLIENTE_HPP

class ccliente
{
	private:
		int idCliente{0};
		char* nombre = nullptr;
		char* apellido = nullptr;
		int dni{0};
		int telefono{0};
		int fechadeIngreso{0};
		float montoCompra{0.0f};

	public:
		ccliente();  
		~ccliente(); 

		void setIdCliente(int id) { idCliente = id; }
		void setNombre(const char* nuevoNombre);
		void setApellido(const char* nuevoApellido);
		void setDni(int nuevoDni) { dni = nuevoDni; }
		void setTelefono(int nuevoTelefono) { telefono = nuevoTelefono; }
		void setFechaDeIngreso(int fecha) { fechadeIngreso = fecha; }
		void setMontoCompra(float monto) { montoCompra = monto; }

		int getIdCliente() const { return idCliente; }
		const char* getNombre() const { return nombre; }
		const char* getApellido() const { return apellido; }
		int getDni() const { return dni; }
		int getTelefono() const { return telefono; }
		int getFechaDeIngreso() const { return fechadeIngreso; }
		float getMontoCompra() const { return montoCompra; }
};

#endif // CCLIENTE_HPP
