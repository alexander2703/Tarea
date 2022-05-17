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
     gotoxy(40,3);cout<<"MENU DE OPCIONES";
     gotoxy(40,4);cout<<"******";
     gotoxy(40,5);cout<<"1.Registrar centro comercial ";
     gotoxy(40,6);cout<<"2.Registrar datos de tienda ";
     gotoxy(40,7);cout<<"3.registrar datos de productos de tienda";
     gotoxy(40,8);cout<<"4.registrar datos de cliente";
     gotoxy(40,9);cout<<"5.registrar los datos por tienda en su almacen";
     gotoxy(40,10);cout<<"6.Listar Tienda";
     gotoxy(40,11);cout<<"7.Listar clientes por tienda";
     gotoxy(40,12);cout<<"8.Buscar tienda por su nombre";
     gotoxy(40,13);cout<<"9. Elimar cliente de la cola";
     gotoxy(40,14);cout<<"10. Pasar productos a tienda";
     gotoxy(40,15);cout<<"11. Salir";
     gotoxy(40,16);cout<<"Elija Opcion:";
     cin>> opc;

    }while (!(opc>0 && opc<12));
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

    }while (!(valor<10000000));
    return valor;
}
unsigned short leerDouble(string mensaje){
    double valor;
    do{
       cout<<mensaje;
       cin>>valor;

    }while (!(valor>0));
    return valor;
}

void encabezado(){
    system ("cls");
    gotoxy (20,3); cout<<"codigo";
    gotoxy (35,3); cout<<"marca";
    gotoxy (48,3); cout<<"modelo";
    gotoxy (60,3); cout<<"placa";
    gotoxy (70,3); cout<<"precio";
    gotoxy (80,3); cout<<"propietario";

}
