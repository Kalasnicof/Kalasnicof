#include <iostream>

using namespace std;

class Personal{
protected:
  string nombre;
  string DNI;
public:
  Personal(string _nombre, string _DNI) : nombre(_nombre), DNI(_DNI) { }

  virtual string saludo(){
    return "Hola, buenos dias " + this->nombre;
  }

  virtual int pagar(int cantidad){
    return cantidad;
  }
};

class Empleado_Horas: public Personal{
private:
  int horas_Trabajo;
  int precio_Por_Hora;
public:
  Empleado_Horas(string _nombre, string _DNI) : Personal(_nombre,_DNI) { }

//  int pagar(int cantidad) override{
//    return cantidad;
//  }

  int horasTrabajadas(){
    return horas_Trabajo;
  }

  int precioHora(){
    return precio_Por_Hora;
  }
};

class Empleado_Fijo: public Personal{
private:
  int sueldo_mes;
public:
  Empleado_Fijo(string _nombre, string _DNI) : Personal(_nombre,_DNI) { }

  //  int pagar(int cantidad) override{
  //    return cantidad;
  //  }

  int sueldo(){
    return this->sueldo_mes;
  }
};

class Encargado: public Personal{
private:
  int sueldo_mes;
public:
  Encargado(string _nombre, string _DNI) : Personal(_nombre,_DNI) { }

  //  int pagar(int cantidad) override{
  //    return cantidad;
  //  }

  int sueldo(){
    return this->sueldo_mes;
  }
};

class Director: public Personal {
private:
  //
public:
  Director(string _nombre, string _DNI) : Personal(_nombre,_DNI) { }

  //  int pagar(int cantidad) override{
  //    return cantidad;
  //  }
};

//-----------------------------------------------------------------------------

class Empresa {
private:
  Director* _director;
  Personal* Head;
};

int main(){
  Personal* per= new Empleado_Horas("Juana","56789032E");
  Empleado_Horas* p= per;
  cout<<p->sueldo();
}
