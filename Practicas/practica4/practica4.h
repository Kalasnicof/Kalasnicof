#include <iostream>

using namespace std;

#ifndef PRACTICA4_H
#define PRACTICA4_H

//----------------------------DESCRIPCION---------------------------------------

//He definido un clase Generico, la cual define un tipo de producto generelas,
//es decir en caso de generar unc ontenedor de tipo generico podemos meter todo
//tipo de productos menos productos especiales y camiones. La clase Generico
//es padre de la clase contenedor y de la clase producto, y su unico parametro
//es el volumen.

//He definido un clase productosEspeciales, la cual posee parametros de tipo
//nombre identificador del producto y volumen, y es padre de los productos
//especiales en este caso es toxico y serVivo

//Hemos definido una clase transporte que recoge tanto contenedores como camiones

//Hemos definido una funcion volOcupa la cual para cada carga nos permite saber
//Su correspondiente tamaño independientemente del tipo que sea.

//Camion guarda cargas de tipo generico es decir productos y contenedores, no
//puede almacenar productos especiales, por otro lado contenedor guarda datos
//del tipo que se declare en contenedor, es decir toxicos, serVivo o Generico.

//--------------------DEFINICION DE LAS CLASES UTILIZADAS-----------------------

//-----------------------------Clase Generico-----------------------------------
//Clase generico parametro unico que es el volumen, funcion que se define en sus
//clases derivadas volOcupa. Padre de las clases producto y contenedor
class Generico{
public:
    //Constructor
    Generico(double);
    //destructor
    ~Generico();
    //Devuelve el volumen que Ocupa
    virtual double volOcupa();

protected:
    double volumen;
};

//--------------------------Clase Producto especiales---------------------------
//La clase productos especiales posee parametros de tipo nombre y volumen, se
//define una funcion para sus clases derivadas volOcupa para definir el tamaño
//del producto, Clase padre de Toxico y Servivo
class ProductoEspecial{
public:
    //Constructor
    ProductoEspecial(double,const string&);
    //destructor
    ~ProductoEspecial();
    //Devuelve el volumen que Ocupa
    virtual double volOcupa();

protected:
    string nombre;
    double volumen;
};

//------------------------------Clase SerVivo-----------------------------------
//Clase ser vivo es una clase derivada de producto especial, las cargas de este
//tipo se deben de guardar en un contenedor de este tipo y solo se pueden guardar
//en el cargas de este tipo.
class SerVivo : public ProductoEspecial{
public:
    //Constructor
    SerVivo(double,const string&);

    //destructor
    ~SerVivo();
    //Devuelve el volumen que Ocupa
    double volOcupa();
};

//---------------------------------Clase Toxico---------------------------------
//Clase toxico es una clase derivada de producto especial, las cargas de este
//tipo se deben de guardar en un contenedor de este tipo y solo se pueden guardar
//en el cargas de este tipo.
class Toxico : public ProductoEspecial{
public:
    //Constructor
    Toxico(double,const string&);

    //destructor
    ~Toxico();
    //Devuelve el volumen que Ocupa
    double volOcupa();
};

//------------------------------Clase Producto----------------------------------
//Clase derivada de generico, posee como parametro identificador nombre
class Producto : public Generico{
public:
    //Constructor
    Producto(double,const string&);

    //destructor
    ~Producto();
    //Devuelve el volumen que Ocupa
    double volOcupa();

private:
    string nombre;
};

//-----------------------------Clase Transporte---------------------------------
//Cada se encarga de reflejar el tamaño del transporte y recoge el espacio libre
//en la variable espacio actual, que varia conforme vamos guardando productos
template<typename T>
class Transporte {
public:
    //Constructor
    Transporte(double _capacidad) {
        capacidad_Total = _capacidad;
        capacidad_Actual = _capacidad;
    }
    //destructor
    ~Transporte() { }
    //Funcion que guarda una carga determinada en el contenedor
    bool guardar(T carga){
        if(capacidad_Actual < carga.volOcupa()) return false;
        else{
            capacidad_Actual = capacidad_Actual - carga.volOcupa();
            return true;
        }
    }

private:
    double capacidad_Total;
    double capacidad_Actual;
};

//-----------------------------Clase Contenedor---------------------------------
//Cada contenedor ocupa un volumen determinado que coincide con su capacidad.
//Un contenedor puede contener varios productos de tipo T
//El volumen total de todos los productos debe de ser menor o igual a la
//capacidad del contenedor y un contenedor puede contener otros contenedores
template<typename T>
class Contenedor : public Generico, public Transporte<T>{
public:
    //Constructor
    Contenedor(double _capacidad) : Generico(_capacidad), Transporte<T>(_capacidad){ }
    //destructor
    ~Contenedor() { }
    //Devuelve el volumen que volOcupa
    double volOcupa(){
        return volumen;
    }
    //Funcion que guarda una carga determinada en el contenedor
    bool guardar(T carga){
        return Transporte<T>::guardar(carga);
    }
};


//-----------------------------Clase camion-------------------------------------
//Cada Camion posee una capacidad determinada en los que los productos deben de
//ser menor de su capacidad, puede contener contenedores tambien, pero nunca
//un contenedor puede contener un camion
class Camion: public Transporte<Generico>{
public:
    //Constructor
    Camion(double);
    //destructor
    ~Camion();
    //Funcion que guarda una cargas de tipo generico en el contenedor
    bool guardar(Generico);
};

//----------DEFINICION DEL CODIGO DE LAS FUNCIONES DE LAS CLASES----------------

//---------------------------Funciones Generico---------------------------------
//Constructor
Generico::Generico(double _volumen){
    volumen = _volumen;
}
//destructor
Generico::~Generico()  { }
//Funcion que devuelve el volumen que ocupa
double Generico::volOcupa(){
    return volumen;
}

//-------------------------Funciones ProductoEspecial---------------------------
//Constructor
ProductoEspecial::ProductoEspecial(double _volumen,const string& _nombre){
    volumen = _volumen;
    nombre = _nombre;
}
//destructor
ProductoEspecial::~ProductoEspecial()  { }
//Funcion que devuelve el volumen que ocupa el producto
double ProductoEspecial::volOcupa(){
    return volumen;
}

//---------------------------Funciones SerVivo----------------------------------
//Constructor
SerVivo::SerVivo(double _volumen,const string& _nombre) : ProductoEspecial(_volumen,_nombre) { }

//destructor
SerVivo::~SerVivo() { }

//Devuelve el volumen que ocupa
double SerVivo::volOcupa(){
    return volumen;
}

//--------------------------------Funciones Toxico------------------------------
//Constructor
Toxico::Toxico(double _volumen,const string& _nombre) : ProductoEspecial(_volumen,_nombre) { }

//destructor
Toxico::~Toxico() { }

//Devuelve el volumen que ocupa
double Toxico::volOcupa(){
    return volumen;
}

//-----------------------------Funciones Producto-------------------------------
//Constructor
Producto::Producto(double _volumen,const string& _nombre) :   Generico(_volumen)   {
    nombre = _nombre;
}

//destructor
Producto::~Producto() { }

//Devuelve el volumen que volOcupa
double Producto::volOcupa(){
    return volumen;
}

//---------------------------Funciones Camion-----------------------------------
//Constructor
Camion::Camion(double _capacidad) : Transporte<Generico>(_capacidad) { }
//destructor
Camion::~Camion()  { }
//Funcion que guarda una cargas de tipo generico en el contenedor
bool Camion::guardar(Generico carga){
    return Transporte<Generico>::guardar(carga);
}

#endif
