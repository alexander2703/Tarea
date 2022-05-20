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
    if(cen->info==NULL){
        informacion *inf = new informacion();
        leerCentroComercia( inf );
    }
    else{
        cout<<"Ya existe un Cenctro comercial";
    }
}

// Registar Tiendas(Alexander Valverde)
void incializarTienda( tienda *tien){
    tien->lP = new listaProductos();
    tien->lP->cab = NULL;
    tien->lP->nProd = 0;
    tien->lC = new listaClientes();
    tien->lC->cab = NULL;
    tien->lC->nclie = 0;
    tien->cA = new colaAtencion();
    tien->cA->delante = NULL;
    tien->cA->atras = NULL;
    tien->cA->nAt = 0;
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
//Registrar Producto exhbicion(Alexander Valverde)
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
void inicializarAtencion(atencion *At){
    At->dni = 0;
}
nodoTienda *elegirTiendas (listaTienda *list){
    nodoTienda *aux = mostrartiendas(list);
    return aux;
}

void leerCliente(atencion *At, unsigned short a){
    system ("cls");

        gotoxy(30, 3);cout << " Clientes ";
        gotoxy(30, 4);cout << "***********";
        gotoxy(30, 5);At->nroTicket = a+1;cout<<"Ticket N: 00"<<a+1;
        gotoxy(30, 6); At->nombreCliente=leerTexto("Nombres: ");
        gotoxy(30, 7); At->apellidosCliente=leerTexto("Apellidos:");
        gotoxy(30, 8); At->dni=leerDNI("DNI: ");
        gotoxy(30, 9); At->sexo = leerTexto("Genero: ");
        gotoxy(30, 9); At->consulta = leerTexto("Consulta: ");
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
void registrarCliente (listaTienda *list){
    system ("cls");
    if (list->nTiendas !=0){
        nodoTienda *tien = elegirTiendas(list);
        atencion *At = new atencion();
        inicializarAtencion(At);
        leerCliente( At,tien->info->cA->nAt );
        encolar( tien->info->cA,At );
    }
    else{
        gotoxy (40,10); cout<< "Debes ingresar primero Tiendas";
    }
    Sleep (5000);
}
//

void mostraratencion (atencion *At , int x){
    gotoxy (20, 5 + x); cout<<At->nombreCliente;
    gotoxy (40, 5 + x); cout<<At->apellidosCliente;
    gotoxy (60, 5 + x); cout<<At->dni;
    gotoxy (75, 5 + x);cout<<At->sexo;

}
void inicializarCL(cliente *cl){
    cl->dni=0;
}
void pasarclieneLista(cliente *cl, atencion *At){
    cl->nombres = At->nombreCliente;
    cl->apellidos = At->apellidosCliente;
    cl->dni = At->dni;
    cl->genero = At->sexo;
    cl->consulta = At->consulta;
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

void desencolar (colaAtencion *colaA,listaClientes *lC){
    atencion *At  = new atencion();
     nodoAtencion*aux = new nodoAtencion();
     aux= colaA->delante;
     At=aux->ate;
     colaA->delante=colaA->delante->sgte;
     if (colaA->delante==NULL)
         colaA->atras= NULL;
        colaA->nAt--;
        system("cls");
        encabezadocl();
        mostraratencion (At,0);
         cliente *cl  = new cliente();
        inicializarCL(cl);
        pasarclieneLista(cl,At);
        insertarcliente(lC,cl);
     delete aux;
     Sleep (4000);
}

void eliminaratencion (listaTienda *list){
    system ("cls");
    if (list->cab->info->cA->delante ==NULL){
        gotoxy (40, 5); cout<<"no hay atencion registradas";
        Sleep (4000);
        }else{

            nodoTienda *tien = elegirTiendas(list);
            desencolar (tien->info->cA,tien->info->lC);
        }
}

// Registrar los productos de tienda en el almacen (Narumi Cabrera)
void inicializarProduct(product *prod){
    prod->precio = 0;
}
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
void leerproductoAlmacen(product *prod){
    system ("cls");
    gotoxy(35,4); cout<< "Producto de almacen";
    gotoxy(35,5); prod->codigo=leerTexto("Ingrese Codigo:");
    gotoxy(35,6); prod->categoria=leerEntero("Ingrese categoria:");
    gotoxy(35,7); prod->nombre=leerTexto("Ingrese nombre:");
    gotoxy(35,8); prod->precio=leerEntero("Ingrese precio:");
}
void push( pilaProductos *pP, product *prod){
    nodoProduct *auxi = new nodoProduct();
    auxi->prodato = prod;
    auxi->sgte = pP->cima;
    pP->cima = auxi;
    pP->nProd++;
}
nodoTienda *elegirTiendaAlmacen (listaTienda *list){
    nodoTienda *aux = mostrartiendas(list);
    return aux;
}
void registrarproductoAlmacen (listaTienda *list){
    system ("cls");
    if (list->nTiendas !=0){
        nodoTienda *tien = elegirTiendaAlmacen(list);
        product *prod = new product();
        inicializarProduct(prod);
        leerproductoAlmacen( prod );
        push( tien->info->pP,prod );
    }
    else{
        gotoxy (40,10); cout<< "Debes ingresar primero Tiendas";
    }
    Sleep (5000);
}
// Listar Tienda con su propietario(Jesus Cruz)
void mostrarTienda( tienda *tien, unsigned short pos){
    gotoxy(20, pos ); cout << tien->nombre;
    gotoxy(35, pos ); cout << tien->rubro;
    gotoxy(48, pos ); cout << tien->ruc;
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
//Listar Clientes por Tienda (Jesus Cruz)-- Falta desencolar
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
    return aux;
}
void listarCl (listaTienda *list){
    system ("cls");
    if (list->nTiendas !=0){
        nodoTienda *tien = elegirTiendaCl(list);
        cliente *cl = new cliente();
        mostrarcliente(cl,4);
        listarcliente(tien->info->lC);
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
//



int main()
{

    unsigned short opc;

    centroComercial *cen = new centroComercial();
    inicializar(cen);
    registrarCc(cen); //Registrar los datos del centro comercial

        do{
            opc = menu();
            switch ( opc ){

            case 1: registrarTienda(cen->list); break;
            case 2: registrarProducto(cen->list); break;
            case 3:registrarCliente(cen->list);break;
            case 4: registrarproductoAlmacen(cen->list); break;
            case 5: listarTienda(cen->list); break;
            case 6: listarCl(cen->list); break;
            case 7: buscarTienda(cen->list); break;
            case 8: eliminaratencion(cen->list); break;
            case 9: break;
            }
        }while(!( opc == 11 ));


    return 0;
}
