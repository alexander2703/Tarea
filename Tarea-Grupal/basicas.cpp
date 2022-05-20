#include <iostream>
#include<windows.h>

using namespace std;

void gotoxy (int x,int y){
    HANDLE hcon;
    hcon=GetStdHandle (STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X= x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);
}

unsigned short menu(){
    unsigned short opc;
    do{
    system ("cls");
     gotoxy(40,4);cout<<"MENU DE OPCIONES";
     gotoxy(40,5);cout<<"******";
     gotoxy(40,6);cout<<"1.Registrar datos de tienda ";
     gotoxy(40,7);cout<<"2.Registrar datos de productos de tienda";
     gotoxy(40,8);cout<<"3.Registrar datos de cliente";
     gotoxy(40,9);cout<<"4.Registrar los datos por tienda en su almacen";
     gotoxy(40,10);cout<<"5.Listar Tienda";
     gotoxy(40,11);cout<<"6.Listar clientes por tienda";
     gotoxy(40,12);cout<<"7.Buscar tienda por su nombre";
     gotoxy(40,13);cout<<"8.Eliminar cliente de la cola";//falta hacer
     gotoxy(40,14);cout<<"9.Pasar productos a tienda";//falta hacer
     gotoxy(40,15);cout<<"10.Salir";
     gotoxy(40,16);cout<<"Elija Opcion:";
     cin>> opc;

    }while (!(opc>0 && opc<11));
    return opc;
}
string leerTexto ( string mensaje){
    string valor;
    do{
      cout<<mensaje;
      fflush(stdin);
      getline (cin, valor );
    }while(!(valor.length()>0));
    return valor;
}

unsigned short leerEntero(string mensaje){
    unsigned short valor;
    do{
       cout<<mensaje;
       cin>>valor;

    }while (!(valor<10000));
    return valor;
}
double leerDouble(string mensaje){
    double valor;
    do{
       cout<<mensaje;
       cin>>valor;

    }while (!(valor>0));
    return valor;
}
int leerDNI(string mensaje){
    int valor;
    do{
       cout<<mensaje;
       cin>>valor;

    }while (!(valor>=10000000));
    return valor;
}
void encabezado(){
    system ("cls");
    gotoxy (20,3); cout<<"Nombre";
    gotoxy (35,3); cout<<"Rubro";
    gotoxy (48,3); cout<<"Ruc";
    gotoxy (64,3); cout<<"Web";
    gotoxy (75,3); cout<<"Propietario";
}
void encabezadocl(){
    system ("cls");
    gotoxy (20,3); cout<<"Nombre";
    gotoxy (35,3); cout<<"Apellidos";
    gotoxy (51,3); cout<<"DNI";
    gotoxy (66,3); cout<<"Sexo";
    gotoxy (80,3); cout<<"Consulta";

}
