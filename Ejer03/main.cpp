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
    //Nodo de la lista principal
    nodo *nodoPrin, *p, *aux;
    //Nodo de la segunda lista
    nodo *nodoImpar, *q, *auxIm; 
    //nuevo es el nuevo nodo, p es el puntero, aux el auxiliar para recorrer
public:
    lista(); ///Constructor
    void insertar_nodoPrin(int N);
    void numImpares();
    void mostrar_lista();
    int dato;
};

lista::lista(){
    //Declarando valores del nodo principal
    nodoPrin = NULL;
    p = NULL;
    aux = NULL;
    
    //Declarando valores del nodo impar
    nodoImpar = NULL;
    q = NULL;
    auxIm =NULL;
}

void lista::insertar_nodoPrin(int N){
   
    int a =0;
    for(int i=0; i <N; i++){
        int a = 0;
        
        do{
            cout<<"Ingrese el dato: "<<endl;
            cin >> dato;
            if(dato <=0){
                cout<<"El numero ingresado debe ser mayor a 0"<<endl;
            }
        }while(dato<=0);
        
        /// Crear el nodo de la lista principal
        nodoPrin = new nodo();
        nodoPrin->info = dato;
        nodoPrin->sig = NULL;
        
        if(p==NULL){ //Creando lista principal sino tiene 
            p=nodoPrin;
            nodoPrin=NULL;

        } else { //Agregando nodos a la lista principal     
            nodoPrin->sig = p;
            p = nodoPrin;
            nodoPrin = NULL;      
        }
    }
}

void lista::numImpares(){
        for(aux=p; aux != NULL; aux=aux->sig){
            if(aux->info%2 !=0){
                /// Crear el nodo de la lista impar
                nodoImpar = new nodo();
                nodoImpar->info = aux->info;
                nodoImpar->sig = NULL;            

                if(q==NULL){ //Creando lista impar si no tiene nodos 
                    q=nodoImpar;
                    nodoImpar=NULL;
                } else { //Agregando nodos a la lista impar     
                    nodoImpar->sig = q;
                    q = nodoImpar;
                    nodoImpar = NULL;         
                }    
            }
        }
}

void lista::mostrar_lista(){
     for(auxIm=q; auxIm != NULL; auxIm=auxIm->sig){
        cout<<"Dato: "<<auxIm->info<<endl;      
    }
}

int main() {   
    //Key
    lista key;
   
    //N
    int N = 0;
    
    cout<<"Numeros a ingresar: "<<endl;
    cin >>N;
    
    //Ingresando datos a la lista principal
    key.insertar_nodoPrin(N);
    //Creando lista de numeros impares
    key.numImpares();
    //Mostrando resultados
    key.mostrar_lista();
}

