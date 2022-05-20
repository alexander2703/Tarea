#include <iostream>
#include <basicas.cpp>
using namespace std;

struct cliente{
    string nombres;
    string apellidos;
    int dni;
    string genero;
    string consulta;
};

struct nodoCliente{
    cliente *cli;
    nodoCliente *sgte;
};

struct listaClientes{
    nodoCliente *cab;
    unsigned short nclie;
};

struct atencion{
    string nroTicket;
    string nombreCliente;
    string apellidosCliente;
    int dni;
    string fecha;
};

struct nodoAtencion{
    atencion *ate;
    nodoAtencion *sgte;
};

struct colaAtencion{
    nodoAtencion *delante;
    nodoAtencion *atras;
    unsigned short nAt;
};


struct producto{
    string nombre;
    string codigo;
    double precio;
    string categoria;
};
struct nodoProducto{
    producto *dato;
    nodoProducto *sgte;
};

struct pilaProductos{
    unsigned short nProd;
    nodoProducto *cima;
 };
struct listaProductos{
    nodoProducto *cab;
    unsigned short nProd;
};

struct tienda{
    string nombre;
    string rubro;
    string ruc;
    string web;
    colaAtencion *cA;
    listaClientes *lC;
    string propietario;
    pilaProductos *pP;      //en el almacen
    listaProductos *lP;      //en exhibicion
};

struct nodoTienda{
    nodoTienda *sgte;
    tienda *info;
};

struct listaTienda{
    unsigned short nTiendas;
    nodoTienda *cab;
};

struct informacion{
    string nombre;
    string direccion;
    string ruc;
    string web;
    string mail;
};

struct centroComercial{
    informacion *info;
    listaTienda *list;

};




