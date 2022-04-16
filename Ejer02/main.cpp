#include <iostream>
#include <cstdlib>

using namespace std;


class lista{
private:
    class nodo{  
    public:
        int info;
        nodo *sig;
    };
    nodo *nuevo, *p, *aux;
    //nuevo es el nuevo nodo, p es el puntero, aux el auxiliar para recorrer
public:
    lista(); ///Constructor
    void insertar_nodo(int N);
    int elementos(int& ma, int& me);
    void mostrar_lista(int ma, int me);
};

lista::lista()
{
    nuevo = NULL;
    p = NULL;
    aux = NULL;
}

void lista::insertar_nodo(int N){
    int dato;
    for(int i=0; i <N; i++){
        
        cout<<"Ingrese el dato: "<<endl;
        cin >> dato;
                   
        /// Crear el nodo a insertar
        nuevo = new nodo();
        nuevo->info = dato;
        nuevo->sig = NULL;
        
        if(p==NULL){ /// Esta vacia la lista y hay que crearla
            p=nuevo;
            nuevo=NULL;

        } else { /// Si la lista no esta vacia lo agregamos antes del primero     
            nuevo->sig = p;
            p = nuevo;
            nuevo = NULL;      
        }
    }
}

int lista::elementos(int& ma, int& me){
    
     for(aux=p; aux != NULL; aux=aux->sig){
         
         if(aux->info >= 100){
             ma++;
         } else if(aux->info <=60){
             me++;
         }  
    }
     return 0;
}

void lista::mostrar_lista(int ma, int me){
    cout<<"El numero de elementos mayores o iguales a 100 son: "<<ma<<endl;
    cout<<"El numero de elementos menores o iguales a 60 son: "<<me<<endl;
}

int main(int argc, char** argv) {
    
    //Key
    lista key;
   
    //N
    int N = 0;
    int ma=0,me=0;
    
    cout<<"Numeros a ingresar: "<<endl;
    cin >>N;
    

    
    key.insertar_nodo(N);
    key.elementos(ma,me);
    key.mostrar_lista(ma,me);
  
    
}

