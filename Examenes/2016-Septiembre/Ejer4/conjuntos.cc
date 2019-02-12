#include <iostream>

using namespace std;

template<typename T>
class Conjunto{
private:
  class Node{
  private:
  public:
      T dato;
      Node* sig;
      Node(T _dato, Node* _sig): dato(_dato), sig(_sig) { }

      void cambiar_sig(Node* new_sig){
        this->sig = new_sig;
      }
      friend class Conjunto;
  };
  Node* head;
public:
  Conjunto(): head(0) {}

  bool insertar_Conjunto(T new_data){
    //Si el conjunto es vacio lo insertamos
    //Si se cumple es el elemento menor del conjunto lo añadimos el primero
    if(head == 0 || new_data < this->head->dato){
      this->head = new Node(new_data,this->head);
    }
    else{
      Node* aux_ant = this->head;
      Node* aux_pos = this->head->sig;

      while(true){
        //Si es igual lo añadimos de nuevo al conjunto
        if(new_data == aux_ant->dato){
          return false;
        }

        //Si es mayor que el ultimo lo insertamos al final
        else if(new_data > aux_ant->dato && aux_pos == nullptr){
          Node* k= new Node(new_data,aux_ant->sig);
          aux_ant->cambiar_sig(k);
          return true;
        }

        //Si se cumple lo insertamos el nuevo elemento entre los correspondientes
        else if(new_data > aux_ant->dato && new_data < aux_pos->dato){
          Node* k= new Node(new_data,aux_pos->sig);
          aux_ant->cambiar_sig(k);
          return true;
        }

        else{
          aux_ant = aux_pos;
          aux_pos = aux_pos->sig;
        }
      }
    }
  }
  void listar(){
    cout << "hoal";
    Node* aux = this->head;
    cout << "{ ";
    while(aux->sig != nullptr){
      //cout << aux->dato << " | ";
      aux = aux->sig;
    }
    aux = aux->sig;
    //cout << aux->dato << " }\n";
  }
};

int main(){
  Conjunto<int> c;

  c.insertar_Conjunto(10);
  c.insertar_Conjunto(6);
  c.insertar_Conjunto(7);
  c.insertar_Conjunto(56);
  c.insertar_Conjunto(78);
  c.insertar_Conjunto(16);
  c.insertar_Conjunto(17);
  if(c.insertar_Conjunto(17)){
    cout << "fin" <<endl;
  }
  else{
    cout << "ok" <<endl;
  }
  c.listar();

}
