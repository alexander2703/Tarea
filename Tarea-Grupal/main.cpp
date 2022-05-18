#include <iostream>
#include <estructuras.cpp>
using namespace std;

void inicializar (centroComercial *cen){
    cen->info = NULL;
    cen->list = new listaTienda();
    cen->list->cab = NULL;
    cen->list->nTiendas = 0;
}
void leerCentroComercia(informacion *inf){
    system("cls");
    gotoxy( 35, 3);cout << " .:: Centro Comercial ::. ";
    gotoxy( 35, 4);inf->nombre= leerTexto("Nombre: ");
    gotoxy( 35, 5);inf->direccion = leerTexto("Direccion: ");
    gotoxy( 35, 6);inf->mail = leerTexto("Mail: ");
    gotoxy( 35, 7);inf->ruc = leerTexto("Ruc: ");
    gotoxy( 35, 8);inf->web = leerTexto("Web: ");
}
void registrarCc( centroComercial *cen ){
    informacion *inf = new informacion();
    leerCentroComercia( inf );
}
void incializarTienda( tienda *tien){
    tien->lP = new listaProductos();
    tien->lP->cab = NULL;
    tien->lP->nProd = 0;
}
void leerTienda(tienda *tien){
    system("cls");
    gotoxy( 35, 3);cout << " .:: Tienda ::. ";
    gotoxy( 35, 4);tien->nombre= leerTexto("Nombre: ");
    gotoxy( 35, 5);tien->rubro = leerTexto("Rubro: ");
    gotoxy( 35, 6);tien->ruc= leerTexto("Ruc: ");
    gotoxy( 35, 7);tien->web = leerTexto("Web: ");
    gotoxy( 35, 8);tien->propietario= leerTexto("Propietario: ");
}
void insertarTienda( listaTienda *list, tienda *tien ){
    nodoTienda *aux = new (struct nodoTienda);
    nodoTienda *temp = new (struct nodoTienda);
    temp->info = tien;
    temp->sgte = NULL;
    if ( list->cab == NULL )
        list->cab = temp;
    else{
        aux = list->cab;
        while( aux->sgte != NULL){
            aux = aux->sgte;
        }
        aux->sgte = temp;
    }
    list->nTiendas++;
}
void registrarTienda( listaTienda*list){
    tienda *tien = new tienda();
    incializarTienda(tien);
    leerTienda( tien );
    insertarTienda(list,tien);
}

void mostrarTienda( tienda *tien, unsigned short pos){
    gotoxy(20, pos ); cout << tien->nombre;
    gotoxy(30, pos ); cout << tien->rubro;
    gotoxy(45, pos ); cout << tien->ruc;
    gotoxy(60, pos ); cout << tien->web;
    gotoxy(65, pos ); cout << tien->propietario;
}

nodoTienda *mostrartiendas (listaTienda *list){
    int valor;
    unsigned short numero=1;
    gotoxy (5,3);cout<<"LISTA TIENDAS";
    gotoxy (5, 4);cout<<"************";
    nodoTienda *aux = list->cab;
    while ( aux ){
        gotoxy (5, 4 + numero); cout<< numero << "." << aux->info->nombre;
        numero++;
        aux = aux->sgte;
    }
    do{
        gotoxy (5,4+ numero); cout<<"elija una opcion";
        cin>> valor;
    }while (!(valor >0 && valor < list->nTiendas + 1));
        aux = list->cab;
    for (int y=0 ; y< valor -1 ; y++){
        aux = aux->sgte;
    }
    return aux;
}
void inicializarProducto(producto *pro){
    pro->precio = 0;
}
void leerProducto (producto *pro){
    system("cls");
    gotoxy( 35, 3);cout << " .:: Producto ::. ";
    gotoxy( 35, 4);pro->nombre= leerTexto("Nombre: ");
    gotoxy( 35, 5);pro->codigo = leerTexto("Codigo: ");
    gotoxy( 35, 6);pro->precio= leerDouble("Precio: ");
    gotoxy( 35, 7);pro->categoria = leerTexto("Categoria: ");
 }
void insertarProducto (listaProductos *lp, producto *pro){
    nodoProducto *aux = new (struct nodoProducto);
    nodoProducto *temp = new (struct nodoProducto);
    temp->dato = pro;
    temp->sgte = NULL;
    if (lp->cab==NULL)
           lp->cab = temp;
       else{
           aux=lp->cab;
           while(aux->sgte !=NULL){
               aux=aux->sgte;
           }
           aux->sgte=temp;
       }
       lp->nProd++;
}
nodoTienda *elegirTienda (listaTienda *list){
    nodoTienda *aux = mostrartiendas(list);
    producto *pro = new producto();
      inicializarProducto(pro);
      leerProducto( pro );
      insertarProducto( aux->info->lP,pro );
}
void registrarProducto (listaTienda *list){
    system ("cls");
    if (list->nTiendas !=0){
        nodoTienda *tien = elegirTienda(list);
    }
    else{
        gotoxy (40,10); cout<< "Debes ingresar primero Tiendas";
    }
    Sleep (5000);
}
void listarTienda( listaTienda *list ){
    nodoTienda *aux = list->cab;
    unsigned short pos = 4;
    encabezado();
    if ( list->nTiendas == 0 ){
        cout << "Debes registrar tiendas";
    }
    else{
        while( aux != NULL ){
            mostrarTienda( aux->info, pos  );
            pos++;
            aux = aux->sgte;
        }
    }
    Sleep( 4000 );
}
void buscarTienda( listaTienda *list ){
    system("cls");
    bool sw = true;
    if ( list->cab!= NULL ){
        string nombre;
        nodoTienda *aux = list->cab;
        gotoxy(35, 3) ; nombre = leerTexto("Ingrese el nombre: "); //L0003
        while( aux ){
            if ( aux->info->nombre == nombre ){
                mostrarTienda( aux->info,4 );
                sw = false;
                break;
            }
            aux = aux->sgte;
        }
        if ( sw == true ){
            gotoxy(40, 5); cout << "la tienda " << nombre << " No se encuentra registrada";
        }
    }
    else{
        gotoxy(40, 5); cout << "No hay tiendas registradas";
    }
    Sleep(4000);
}
int main()
{

    unsigned short opc;

    centroComercial *cen = new centroComercial();
    inicializar(cen);


        do{
            opc = menu();
            switch ( opc ){
            case 1: registrarCc(cen);  break;//Registrar los datos del centro comercial
            case 2: registrarTienda(cen->list); break;
            case 3:registrarProducto(cen->list); break;
            case 6: listarTienda(cen->list); break;
            case 8: buscarTienda(cen->list); break;
            case 5:  break;
            }
        }while(!( opc == 11 ));


    return 0;
}

