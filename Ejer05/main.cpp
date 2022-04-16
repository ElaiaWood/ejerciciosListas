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
    nodo *segundo, *m, *n, *auxIn;
public:
    int dato;
    lista(); ///Constructor
    void insertar_nodo(int N);
    void invertir();
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
    m = NULL;
    n = NULL;
    auxIn = NULL;
}
void lista::insertar_nodo(int N){
    
    for(int i = 0; i < N; i++){
        
        do{
            cout<<"Ingrese una cantidad mayor a 0: "<<endl;
            cin >> dato;
            if(dato <=0){
                cout<<"Dato incorrecto, ingrese una cantidad mayor a 0"<<endl;
            }
        }while(dato <=0);

        /// Crear el nodo a insertar
        nuevo = new nodo();
        nuevo->info = dato;
        nuevo->sig = NULL;
        nuevo->ant = NULL;

        if(p==NULL) /// Esta vacia la lista y hay que crearla
        {
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
}
void lista::invertir(){
     for(aux=p; aux != NULL; aux=aux->sig){
        /// Crear el nodo a insertar
        segundo = new nodo();
        segundo->info = aux->info;
        segundo->sig = NULL;
        segundo->ant = NULL;

        if(m==NULL) /// Esta vacia la lista y hay que crearla
        {
            m=segundo;
            n=segundo;
            segundo=NULL;
        } else { /// Si la lista no esta vacia lo agregamos antes del primero
            segundo->sig = m;
            m->ant = segundo;
            m = segundo;
            segundo = NULL;
        }         
    }
}

void lista::mostrar_lista(){
    
    for(aux=p; aux != NULL; aux=aux->sig){
        cout<<"Dato: "<<aux->info<<endl;
    }
    
    for(auxIn=m; auxIn != NULL; auxIn=auxIn->sig){
        cout<<"Dato: "<<auxIn->info<<endl;
    }
}

/* Agregar 5 ndos a una lista doblemente ligada */
int main(){
    
    //Variables
    int N;
    
    //Llave de metodos
    lista key;
    
    cout<<"Cuantos nodos quiere ingresar?"<<endl;
    cin >> N;
    
    
    key.insertar_nodo(N);
    key.invertir();
    key.mostrar_lista();
}

