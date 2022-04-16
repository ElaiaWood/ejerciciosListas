#include <iostream>
#include <cstdlib>
#include <cmath>
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
    nodo *nodoProm, *q, *auxProm; 
    //nuevo es el nuevo nodo, p es el puntero, aux el auxiliar para recorrer
public:
    lista(); ///Constructor
    void insertar_nodoPrin(int N);
    void numProm();
    void mostrar_lista();
    int dato,suma;
    double prom;
};

lista::lista(){
    //Declarando valores del nodo principal
    nodoPrin = NULL;
    p = NULL;
    aux = NULL;
    
    //Declarando valores del nodo impar
    nodoProm = NULL;
    q = NULL;
    auxProm =NULL;
}

void lista::insertar_nodoPrin(int N){
   
    int a =0;
    for(int i=0; i <N; i++){
        
        do{
            cout<<"Ingrese el dato: "<<endl;
            cin >> dato;
            if(dato <=0){
                cout<<"El numero ingresado debe ser mayor a 0"<<endl;
            }
        }while(dato<=0);
        suma += dato;
        prom = abs(suma/N);
        
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

void lista::numProm(){
        for(aux=p; aux != NULL; aux=aux->sig){
            if(aux->info > prom){
                /// Crear el nodo de la lista impar
                nodoProm = new nodo();
                nodoProm->info = aux->info;
                nodoProm->sig = NULL;            

                if(q==NULL){ //Creando lista impar si no tiene nodos 
                    q=nodoProm;
                    nodoProm=NULL;
                } else { //Agregando nodos a la lista impar     
                    nodoProm->sig = q;
                    q = nodoProm;
                    nodoProm = NULL;         
                }    
            }
        }
}

void lista::mostrar_lista(){
     for(auxProm=q; auxProm != NULL; auxProm=auxProm->sig){
        cout<<"Dato: "<<auxProm->info<<endl;      
    }
        cout<<"Dato: "<<abs(prom)<<endl;      
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
    key.numProm();
    //Mostrando resultados
    key.mostrar_lista();
}

