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
    void mostrar_lista();
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
        int a = 0;
        
        do{
            cout<<"Ingrese el dato: "<<endl;
            cin >> dato;
            
             for(aux=p; aux != NULL; aux=aux->sig){
                if(dato== aux->info){
                    cout<<"Dato repetido, intente con uno nuevo"<<endl;
                    a++;
                    break;
                }
                a=0;
            }  
        }while(a!=0);
        
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

void lista::mostrar_lista()
{
     for(aux=p; aux != NULL; aux=aux->sig){
        cout<<"Dato: "<<aux->info<<endl;      
    }
}


int main(int argc, char** argv) {
    
    //Key
    lista key;
   
    //N
    int N = 0;
    
    cout<<"Numeros a ingresar: "<<endl;
    cin >>N;
    
    key.insertar_nodo(N);
    key.mostrar_lista();
  
    
}

