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
    cliente *cl = new cliente();
      leercliente( cl );
      insertarcliente( aux->info->lC,cl );
}
void registrarCliente (listaTienda *list){
    system ("cls");
    if (list->nTiendas !=0){
        nodoTienda *tien = elegirTiendas(list);
    }
    else{
        gotoxy (40,10); cout<< "Debes ingresar primero Tiendas";
    }
    Sleep (5000);
}


void mostrarcliente (cliente*cl , unsigned short posi){
       gotoxy(20, posi ); cout <<cl->nombres;
       gotoxy(35, posi ); cout <<cl->apellidos;
       gotoxy(50, posi ); cout <<cl->dni;
       gotoxy(65, posi ); cout <<cl->genero;
       gotoxy(80, posi ); cout <<cl->consulta;

}
// falata poner opcion de listar en tiendas
void listarcliente( listaClientes *lC ){
    nodoCliente *aux = lC->cab;
    unsigned short posi = 4;
    encabezado();
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

nodoCliente *mostrarCliente (listaClientes *lC){
    int valor;
    unsigned short numero=1;
    gotoxy (5,3);cout<<"LISTA Clientes";
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
    aux->info = At;
    aux->sgte = NULL;
    if (colaA->delante == NULL) //es el primer elemento
        colaA->delante= aux;
    else
        colaA->atras->sgte = aux;
    colaA->atras = aux;
    colaA->nAt++;
}
/* falta arreglar
nodoCliente *elegirCliente (listaTienda *list){
    nodoCliente *aux = mostrarCliente(list->cab->info->lC);
    cliente *cl = new cliente();
      leeratencion( list->cab->info->cA->delante->info );
      encolar( list->cab->info->cA ,list->cab->info->cA->delante->info  );
}
void registraratencion (listaTienda *list){
    system ("cls");
    if (list->cab->info->lC->nclie !=0){
        nodoCliente *l = elegirCliente(list->cab->info->lC);
    }
    else{
        gotoxy (40,10); cout<< "Debes ingresar primero Clientes";
    }
    Sleep (5000);
}

*/
void mostraratencion (atencion *At , int x){
    gotoxy (20, 5 + x); cout<<At->nombreCliente;
    gotoxy (40, 5 + x); cout<<At->apellidosCliente;
    gotoxy (60, 5 + x); cout<<At->dni;
    gotoxy (75, 5 + x);cout<<At->fecha;
    gotoxy (85, 5 + x); cout<<At->nroTicket;
}
/*
void desencolar (colaAtencion *colaA){
    atencion *At  = new atencion();
     nodoAtencion*aux = new nodoAtencion();
     aux= colaA->delante;
     At=aux->info;
     colaA->delante=colaA->delante->sgte;
     if (colaA->delante==NULL)
         colaA->atras= NULL;
        colaA->nAt--;
        mostraratencion (At,0);
     delete aux;
     Sleep (4000);
}

void eliminaratencion (colaAtencion *colaA){
    system ("cls");
    if (colaA->delante ==NULL){
        gotoxy (40, 5); cout<<"no hay atencion registradas";
        }else{
          desencolar (colaA);
        }
}

void listaratencion( colaAtencion *colaA){
    system ("cls");

    if ( colaA->nAt == 0 ){
       cout << "Debes registrar la atencion";
    }
    else{
        nodoAtencion*aux = colaA->delante;
        unsigned short pos = 1;
        encabezadoAten();
        while( aux  ){
            mostraratencion( aux->info, pos  );
            pos++;
            aux = aux->sgte;
        }
    }
    cout<<endl;
    Sleep(4000);
}

void buscaratencion(colaAtencion *colaA){
    system ("cls");
    bool sw=true;
    if (colaA->delante !=NULL){
        string codigoBuscar;
        nodoAtencion *aux = colaA->delante;
        gotoxy(35,3); codigoBuscar = leerTexto("Ingrese el codigo a buscar: ");
        while ( aux ){
            if (aux->info->nroTicket== codigoBuscar){
                mostraratencion (aux->info , 0);
                sw=false;
                break;
            }
            aux= aux->sgte;
        }
        if (sw==true){
            gotoxy (40,5); cout<<"El numero de tikect"<<codigoBuscar<<"no se encuentra ";
        }
    }
    else{
        gotoxy (40,5); cout<< "No hay atencion registrada";
    }
    Sleep(4000);
}
*/

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
            case 3: registrarProducto(cen->list); break;
            case 4: registrarCliente(cen->list); break;
            case 5: listarcliente(cen->list->cab->info->lC); break;
            case 6: listarTienda(cen->list); break;
            case 7: registraratencion(cen->list->cab->info->lC); break;
            case 8: buscarTienda(cen->list); break;

            }
        }while(!( opc == 11 ));


    return 0;
}

