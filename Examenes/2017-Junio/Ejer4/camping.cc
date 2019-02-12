#include <iostream>
#include <string>

using namespace std;

class Avisador{
public:
  Avisador() { }

  virtual void avisar(){
    cout << "Aviso" << endl;
  }
};

class Adulto: public Avisador{
private:
public:
  Adulto() :  Avisador() { }

  void avisar() override{
    cout << "Señal parpadeante emitida al adulto" << endl;
  }
};

class Alojamiento: public Avisador {
public:
  Alojamiento() : Avisador() { }

  void avisar() override{
    cout << "Señal acustica emitida en el alojamiento" << endl;
  }
};

class Parcela{
private:
  int num_Personas;
  int num_Vehiculos;
  int num_Alojamientos;
  class Node{
  private:
  public:
      Avisador* dato;
      Node* sig;
      Node(Avisador* d, Node* s): dato(d), sig(s) { }
  };
  Node* head;
public:
  Parcela() : num_Personas(0), num_Vehiculos(0), num_Alojamientos(0), head(0) {}

  void insertar_Elemento(string tipo_elemento){
      if("Adulto"==tipo_elemento)
                              {
                              this->num_Personas++;
                              Avisador* p = new Adulto();
                              this -> head = new Node(p,this->head);
                              cout << "Se ha añadido adulto." << endl;
                              }

      else if("Niño"==tipo_elemento)
                              {
                              this->num_Personas++;
                              cout << "Se ha añadido niño." << endl;
                              }

      else if("Tienda"==tipo_elemento)
                              {
                              this->num_Alojamientos++;
                              Avisador* p = new Alojamiento();
                              this -> head = new Node(p,this->head);
                              cout << "Se ha añadido Tienda." << endl;
                              }

      else if("Caravana"==tipo_elemento)
                              {
                              this->num_Alojamientos++;
                              Avisador* p = new Alojamiento();
                              this -> head = new Node(p,this->head);
                              cout << "Se ha añadido Caravana." << endl;
                              }

      else if("Coche"==tipo_elemento)
                              {
                              num_Vehiculos++;
                              cout << "Se ha añadido Coche." << endl;
                              }

      else if("Autocaravana"==tipo_elemento)
                              {
                              this->num_Vehiculos++;
                              this->num_Alojamientos++;
                              Avisador* p = new Alojamiento();
                              this -> head = new Node(p,this->head);
                              cout << "Se ha añadido Autocaravana." << endl;
                              }

      else if("Microbus"==tipo_elemento)
                              {
                              this->num_Vehiculos = this->num_Vehiculos + 2;
                              cout << "Se ha añadido Microbus." << endl;
                              }
      else                    {
                              cout << "No existe el elemento " << tipo_elemento << endl;
                              }
    }
    int precio_diario_parcela(){
          return (this->num_Vehiculos * 5) + (this->num_Alojamientos * 6) +
                 (this->num_Personas * 4);
    }
    void emergencia(){
      cout << "Se ha avisado emergencia en la parcela." << endl;
      Node* aux = this->head;
      while (aux != 0){
          aux->dato->avisar();
          aux=aux->sig;
      }
    }
};

class Camping{
private:
    //lista de parcelas al decir conjunto
    class Node{
    private:
    public:
        Parcela* dato;
        Node* sig;
        Node(Parcela* d, Node* s): dato(d), sig(s) { }
    };
    Node* head;
public:
  Camping() : head(0) {}

  void insertar_parcela(Parcela* p){
    cout << "Se ha inserta parcela en el camping." << endl;
    this -> head = new Node(p,this->head);
  }

  int precio_diario_camping(){
    Node* aux = this->head;
    int recaudacion = 0;
    while (aux != 0){
        recaudacion = recaudacion + aux->dato->precio_diario_parcela();
        aux=aux->sig;
    }
    return recaudacion;
  }


  void avisar_emergencia(){
    cout << "Se ha avisa emergencia nivel camping." << endl;
    Node* aux = this->head;
    while (aux != 0){
        aux->dato->emergencia();
        aux=aux->sig;
    }
  }
};

int main(){
  Camping* c = new Camping();
  Parcela* Uno = new Parcela();
  Parcela* Dos = new Parcela();
  c->insertar_parcela(Uno);
  c->insertar_parcela(Dos);

  Uno->insertar_Elemento("Niño");
  Uno->insertar_Elemento("Adulto");
  Uno->insertar_Elemento("Coche");
  Uno->insertar_Elemento("Tienda");
  Uno->insertar_Elemento("Caravana");
  Uno->insertar_Elemento("Autocaravana");
  Uno->insertar_Elemento("Microbus");


  Dos->insertar_Elemento("Adulto");
  Dos->insertar_Elemento("Adulto");
  Dos->insertar_Elemento("Adulto");
  Dos->insertar_Elemento("Adulto");
  Dos->insertar_Elemento("Autocaravana");

  cout << "\n El precio diario del camping es: " << c->precio_diario_camping() <<endl;


  cout << "\n El precio diario dela parcela Uno es: " << Uno->precio_diario_parcela() <<endl;

  cout << "\n El precio diario dela parcela Dos es: " << Dos->precio_diario_parcela() <<endl;

  c->avisar_emergencia();



}
