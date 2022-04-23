#include <iostream>
#include <cstdlib>

using namespace std;

class lista{
private:
    class nodo{  
    public:
        int info;
        nodo *ant;
        nodo *sig;
    };
    nodo *nuevo, *p, *u, *aux;
    nodo *segundo, *p2, *q2, *auxIn;
public:
    int dato;
    lista(); ///Constructor
    void insertar_listaUno(int dato);
    void insertar_listaDos(int dato);
    void unir();
    void mostrar_lista();
    
    
};

lista::lista(){
    //Primera lista
    nuevo = NULL;
    p = NULL;
    u = NULL;
    aux = NULL;
    //Segunda lista
    segundo = NULL;
    p2 = NULL;
    q2 = NULL;
    auxIn = NULL;
}



void lista::insertar_listaUno(int dato){
    
    /// Crear el nodo a insertar
    nuevo = new nodo();
    nuevo->info = dato;
    nuevo->sig = NULL;
    nuevo->ant = NULL;
    if(p==NULL){ /// Esta vacia la lista y hay que crearla
    
        p=nuevo;
        u=nuevo;
        nuevo=NULL;
    } else { /// Si la lista no esta vacia lo agregamos antes del primero
        nuevo->sig = p;
        p->ant = nuevo;
        p = nuevo;
        nuevo = NULL;
    }
}
void lista::insertar_listaDos(int dato){
    
    /// Crear el nodo a insertar
    segundo = new nodo();
    segundo->info = dato;
    segundo->sig = NULL;
    segundo->ant = NULL;

    if(p2==NULL){ /// Esta vacia la lista y hay que crearla
        p2=segundo;
        q2=segundo;
        segundo=NULL;
    } else { /// Si la lista no esta vacia lo agregamos antes del primero
        segundo->sig = p2;
        p2->ant = segundo;
        p2 = segundo;
        segundo = NULL;
    }
}

void lista::unir(){
    
    for(auxIn=p2; auxIn != NULL; auxIn=auxIn->sig){
        this->insertar_listaUno(auxIn->info);
    }
    
    cout<<"\nLista unida"<<endl;
    for(aux=p; aux != NULL; aux=aux->sig){
        cout<<"Dato: "<<aux->info<<endl;
    }
        
}

void lista::mostrar_lista(){
    
    cout<<"\nPrimera lista"<<endl;
    for(aux=p; aux != NULL; aux=aux->sig){
        cout<<"Dato: "<<aux->info<<endl;
    }
    
    cout<<"\nSegunda lista"<<endl;
    for(auxIn=p2; auxIn != NULL; auxIn=auxIn->sig){
        cout<<"Dato: "<<auxIn->info<<endl;
    }
}

/* Agregar 5 ndos a una lista doblemente ligada */
int main(){
    
    //Variables
    int N,M,dato;
    
    //Llave de metodos
    lista key;
    
    cout<<"Ingrese numero de datos de la primera lista: ";
    cin >> N;
    for (int i = 0; i < N; i++){
        cout<<"Ingrese la cantidad: ";
        cin>>dato;
        key.insertar_listaUno(dato);
    }

    cout<<"\nIngrese numero de datos de la segunda lista: ";
    cin >> M;
    for (int j = 0; j < M; j++){
        cout<<"Ingrese la cantidad: ";
        cin>>dato;
        key.insertar_listaDos(dato);
    }
    
    key.mostrar_lista();
    key.unir();
}

