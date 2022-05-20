#include <iostream>
#include <estructuras.cpp>
using namespace std;

void inicializar (centroComercial *cen){
    cen->info = NULL;
    cen->list = new listaTienda();
    cen->list->cab = NULL;
    cen->list->nTiendas = 0;
}

// Registrar Centro Coemcial (Alexander Valverde)
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

// Registar Tiendas(Alexander Valverde)
void inicializarlP(listaProductos *lP){
    lP = new listaProductos();
    lP->cab = NULL;
    lP->nProd = 0;
}
void inicializarcA(colaAtencion *cA){
    cA = new colaAtencion();
    cA->delante = NULL;
    cA->atras = NULL;
    cA->nAt = 0;
}
void inicializarpP(pilaProductos *pP){
    pP = new pilaProductos();
    pP->cima = NULL;
    pP->nProd = 0;
}


void incializarTienda( tienda *tien){
   inicializarlP(tien->lP);
   inicializarcA(tien->cA);
   inicializarpP(tien->pP);
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

// Registrar Producto en Tienda exhibicion (Alexander Valverde)
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
        gotoxy (6,4+ numero); cout<<"elija una opcion: ";
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
    return aux;
}
void registrarProducto (listaTienda *list){
    system ("cls");
    if (list->nTiendas !=0){
        nodoTienda *tien = elegirTienda(list);
        producto *pro = new producto();
          inicializarProducto(pro);
          leerProducto( pro );
          insertarProducto( tien->info->lP,pro );

    }
    else{
        gotoxy (40,10); cout<< "Debes ingresar primero Tiendas";
    }
    Sleep (5000);
}

// Resgistrar Datos del Cliente (Narumi Cabrera)
void inicializarCL(cliente *cl){
    cl->dni=0;
}
void leercliente(cliente *cl){
    system ("cls");

    gotoxy(30, 3);cout << " Clientes ";
    gotoxy(30, 4);cout << "***********";
    gotoxy(30, 5); cl->nombres=leerTexto("Nombres: ");
    gotoxy(30, 6); cl->apellidos=leerTexto("Apellidos:");
    gotoxy(30, 7); cl->consulta=leerTexto("Ingrese consulta: ");
    gotoxy(30, 8); cl->dni=leerDNI("DNI: ");
    gotoxy(30, 9); cl->genero=leerTexto("Sexo: ");
}

void insertarcliente( listaClientes *lC, cliente*cl ){
    nodoCliente *aux = new nodoCliente();
    nodoCliente*temp = new nodoCliente();
    temp->cli = cl;
    aux = lC->cab;
    if ( aux ){
        while  ( aux->sgte !=NULL){
            aux= aux->sgte;
        }
        temp->sgte = aux->sgte;
        aux->sgte = temp;

    }
    else{
       temp->sgte = aux;
       lC->cab = temp;
    }
    lC->nclie++;
}
nodoTienda *elegirTiendas (listaTienda *list){
    nodoTienda *aux = mostrartiendas(list);
    return aux;
}
void registrarCliente (listaTienda *list){
    system ("cls");
    if (list->nTiendas !=0){
        nodoTienda *tien = elegirTiendas(list);
        cliente *cl = new cliente();
        inicializarCL(cl);
        leercliente( cl );
        insertarcliente( tien->info->lC,cl );
    }
    else{
        gotoxy (40,10); cout<< "Debes ingresar primero Tiendas";
    }
    Sleep (5000);
}



nodoCliente *mostrarCliente (listaClientes *lC){
    int valor;
    unsigned short numero=1;
    gotoxy (5,3);cout<<"LISTA CLIENTES";
    gotoxy (5, 4);cout<<"************";
    nodoCliente *aux = lC->cab;
    while ( aux ){
        gotoxy (5, 4 + numero); cout<< numero << "." << aux->cli->nombres<<" "<<aux->cli->apellidos;
        numero++;
        aux = aux->sgte;
    }
    do{
        gotoxy (6,4+ numero); cout<<"elija una opcion: ";
        cin>> valor;
    }while (!(valor >0 && valor < lC->nclie+ 1));
        aux = lC->cab;
    for (int y=0 ; y< valor -1 ; y++){
        aux = aux->sgte;
    }
    return aux;
}


void leeratencion(atencion *At){
    system ("cls");
    gotoxy( 35, 3);cout << " Atencion";
    gotoxy( 35, 4);cout << "***********";
    gotoxy( 30, 5);At->apellidosCliente = leerTexto("Ingrese apellidos:");
    gotoxy( 30, 6);At->dni = leerDNI("Ingrese el DNI :");
    gotoxy( 30, 7);At->fecha = leerTexto("Ingrese la fecha:");
    gotoxy( 30, 8);At->nombreCliente= leerTexto("Ingrese el nombre del cliente:");
    gotoxy( 30, 9);At->nroTicket= leerTexto("Ingrese nro de tikect:");
}
void encolar (colaAtencion *colaA ,atencion *At){
    nodoAtencion *aux = new nodoAtencion();
    aux->ate = At;
    aux->sgte = NULL;
    if (colaA->delante == NULL) //es el primer elemento
        colaA->delante= aux;
    else
        colaA->atras->sgte = aux;
    colaA->atras = aux;
    colaA->nAt++;
}
void mostraratencion (atencion *At , int x){
    gotoxy (20, 5 + x); cout<<At->nombreCliente;
    gotoxy (40, 5 + x); cout<<At->apellidosCliente;
    gotoxy (60, 5 + x); cout<<At->dni;
    gotoxy (75, 5 + x);cout<<At->fecha;
    gotoxy (85, 5 + x); cout<<At->nroTicket;
}
// Registrar los productos de tienda en el almacen (Narumi Cabrera)

nodoTienda *mostrarTiendaAlmacen(listaTienda *list){
    int valor;
    unsigned short numero=1;
    gotoxy (5,3);cout<<"LISTA TIENDAS";
    gotoxy (5,4);cout<<"************";
    nodoTienda *aux = list->cab;
    while ( aux ){
        gotoxy (5, 4 + numero); cout<< numero << "." << aux->info->nombre<<" ";
        numero++;
        aux = aux->sgte;
    }
    do{
        gotoxy (6,4+ numero); cout<<"elija una opcion: ";
        cin>> valor;
    }while (!(valor >0 && valor < list->nTiendas + 1));
        aux = list->cab;
    for (int y=0 ; y< valor -1 ; y++){
        aux = aux->sgte;
    }
    return aux;
}
void inicializarproductoAlmacen(producto *pro){
    pro->precio=0;
}

void leerproductoAlmacen(producto *pro){
    system ("cls");
    gotoxy(35,4); cout<< "Producto de almacen";
    gotoxy(35,5); pro->codigo=leerTexto("Ingrese Codigo:");
    gotoxy(35,6); pro->categoria=leerEntero("Ingrese categoria:");
    gotoxy(35,7); pro->nombre=leerTexto("Ingrese nombre:");
    gotoxy(35,8); pro->precio=leerEntero("Ingrese precio:");
}
void push( pilaProductos *pP, producto *pro){
    nodoProducto *aux = new nodoProducto();
    aux->dato = pro;
    aux->sgte = pP->cima;
    pP->cima = aux;
    pP->nProd++;
}
nodoTienda *elegirTiendaAlmacen (listaTienda *list){
    nodoTienda *aux = mostrartiendas(list);
    producto *pro = new producto();
      inicializarProducto(pro);
      leerProducto( pro );
      push( aux->info->pP,pro );
}
void registrarproductoAlmacen (listaTienda *list){
    system ("cls");
    if (list->nTiendas !=0){
        nodoTienda *tien = elegirTiendaAlmacen(list);
    }
    else{
        gotoxy (40,10); cout<< "Debes ingresar primero Tiendas";
    }
    Sleep (5000);
}



void mostrarproductoAlmacen(producto *pro, int x){
    gotoxy (20, 5 + x);cout<<pro->codigo;
    gotoxy (30, 5 + x);cout<<pro->nombre;
    gotoxy (40, 5 + x);cout<<pro->categoria;
    gotoxy (50, 5 + x);cout<<pro->precio;

}

void listarproductoAlmacen( pilaProductos  *pP ){
    nodoProducto *aux = pP->cima;
    unsigned short pos = 4;
    encabezado();
    if ( pP->nProd == 0 ){
        cout << "Debes registrar productos";
    }
    else{
        while( aux != NULL ){
            mostrarproductoAlmacen( aux->dato, pos  );
            pos++;
            aux = aux->sgte;
        }
    }
    Sleep( 4000 );
}

// Listar Tienda con su propietario(Jesus Cruz)
void mostrarTienda( tienda *tien, unsigned short pos){
    gotoxy(20, pos ); cout << tien->nombre;
    gotoxy(34, pos ); cout << tien->rubro;
    gotoxy(45, pos ); cout << tien->ruc;
    gotoxy(60, pos ); cout << tien->web;
    gotoxy(75, pos ); cout << tien->propietario;
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
//Listar Clientes por Tienda (Jesus Cruz)
void mostrarcliente (cliente*cl , unsigned short posi){
       gotoxy(20, posi ); cout <<cl->nombres;
       gotoxy(35, posi ); cout <<cl->apellidos;
       gotoxy(50, posi ); cout <<cl->dni;
       gotoxy(65, posi ); cout <<cl->genero;
       gotoxy(80, posi ); cout <<cl->consulta;

}
void listarcliente( listaClientes *lC ){
    nodoCliente *aux = lC->cab;
    unsigned short posi = 4;
    encabezadocl();
    if ( lC->nclie == 0 ){
        cout << "Debes registrar el cliente";
    }
    else{
        while( aux != NULL ){
         mostrarcliente(aux->cli, posi);
            posi++;
            aux = aux->sgte;
        }
    }
    Sleep( 4000 );
}

nodoTienda *elegirTiendaCl (listaTienda *list){
    nodoTienda *aux = mostrartiendas(list);
    producto *cl = new producto();
    mostrarcliente(aux->info->lC->cab->cli,4);
    listarcliente(aux->info->lC);

}
void listarCl (listaTienda *list){
    system ("cls");
    if (list->nTiendas !=0){
        nodoTienda *tien = elegirTiendaCl(list);
    }
    else{
        gotoxy (40,10); cout<< "Debes ingresar primero Tiendas";
    }
    Sleep (5000);
}
// Buscar Tienda por Nombre(Jesus Cruz)
void buscarTienda( listaTienda *list ){
    system("cls");
    bool sw = true;
    if ( list->cab!= NULL ){
        string nombre;
        nodoTienda *aux = list->cab;
        gotoxy(35, 3) ; nombre = leerTexto("Ingrese el nombre: "); //L0003
        while( aux ){
            if ( aux->info->nombre == nombre ){
                system("cls");
                encabezado();
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
    unsigned short opc1;
    centroComercial *cen = new centroComercial();
    inicializar(cen);
    registrarCc(cen); //Registrar los datos del centro comercial

        do{
            opc = menu();
            switch ( opc ){

            case 2: registrarTienda(cen->list); break;
            case 3: registrarProducto(cen->list); break;
            case 4:
                do{
                  opc1 = menu1();
                  switch ( opc1 ){
                  case 1: registrarCliente(cen->list);break;
                  case 2:break;

                  }
              }while(!( opc1 == 3 ));  break;
            case 5: registrarproductoAlmacen(cen->list); break;
            case 6: listarTienda(cen->list); break;
            case 7: listarCl(cen->list); break;
            case 8: buscarTienda(cen->list); break;


            }
        }while(!( opc == 11 ));


    return 0;
}
