#include <iostream>
#include <string.h>

using namespace std;

#define M 2
#define N 3
#define O 2

typedef char cadena[20];

class cuatro{
    cadena tabla[M][N][O];
public:
    void cargar();
    void encontrar();
};
void cuatro::cargar(){
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<O;k++){
                cout << "Palabra " << i << ", " << j << ", " << k << ": ";
                cin >> tabla[i][j][k];
            }
        }
    }
}//fin del metodo

void cuatro::encontrar(){
    bool encontrado;
    int i, j, k;
    cadena buscado;
    i=0;
    encontrado = false;
    cout << "Dime la palabra que buscas: ";
    cin >> buscado;
    cout << "\n";
    while(i<M && (!encontrado)){
        j=0;
        while(j<N && (!encontrado)){
            k=0;
            while(k<O && (!encontrado)){
                if(strcmp(tabla[i][j][k], buscado) == 0){
                    encontrado = true;
                }
                else{
                    k++;
                }
            }
            if(encontrado == true){
                encontrado = true;
            }
            else{
                j++;
            }
        }
        if(encontrado == true){
            encontrado = true;
        }
        else{
            i++;
        }
    }
    if(encontrado == true){
        cout << "La palabra esta en la tabla y se encuentra en la posicion " << i << "," << j << "," << k << "\n\n\n";
    }
    else{
        cout << "La palabra NO esta en la tabla\n\n\n";
    }
}//fin de encontrar

int main(){

    cuatro ct;
    char opc;
    do{
        do{
            cout << "Busca palabras\n\n";
            cout << "a.\tCarga la tabla con palabras.\n\n";
            cout << "b.\tBusca la palabra que digas en la tabla.\n\n";
            cout << "f.\tSalir.\n\n";
            cout << "Elige una opcion(a, b o f).\n\n";
            cin >> opc;
            if (opc!='a' && opc!='b' && opc !='f'){
                cout << "Selecciona la opcion correcta\n";
            }
        }while(opc!='a' && opc!='b' && opc !='f');
        switch(opc){
            case 'a':
                ct.cargar();
                break;
            case 'b':
                ct.encontrar();
                break;
        }
    }while(opc!='f');


    return 0;
}
