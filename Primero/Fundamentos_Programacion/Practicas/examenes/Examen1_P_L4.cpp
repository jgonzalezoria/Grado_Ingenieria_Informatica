/*
    Autor: José Alberto González Oria
    email: josealberto.oria@alu.uhu.es
    Grupo de Prácticas L4

*/
#include <iostream>

using namespace std;

#define M 6
#define N 6

class examen{
    int t[M][N];
    int nfilas;     // Tendrá el número de filas de la tabla que tiene valores
    int ncolumnas; // Tendrá el número de columnas de la tabla que tienen valores
public:
    void cargar();
    //Pedirá por teclado el número de filas que va a tener cargadas la tabla
    //asi como el numero de columnas, estos valores deberán estar
    //comprendidos entre 0 y 6 ambos incluídos, si no se cumple esto se volverá
    //a pedir hasta que sean correctos.
    //Solicitando por teclado el valor de cada uno de los elementos de la tabla

    bool esta();
    //Pedirá por teclado un número que se quiere buscar.
    //Pedirá por teclado un número de columna y devolverá true si el
    //número está almacenado en esa columna, false en caso contrario.

};//fin de la clase examen
 //cargamos la tabla
void examen::cargar(){
    //comprobamos que tanto filas como las columnas están dentro de los valores
    do{
        cout << "Dime el numero filas: ";
        cin >> nfilas;
        if(nfilas < 0 || nfilas > 6){
            cout << "El numero de filas no es correcto, introducelo de nuevo.\n";
        }
    }while(nfilas < 0 || nfilas > 6);
    do{
        cout << "Dime el numero columnas: ";
        cin >> ncolumnas;
        if(ncolumnas < 0 || ncolumnas > 6){
            cout << "El numero de columnas no es correcto, introducelo de nuevo.\n";
        }
    }while(ncolumnas < 0 || ncolumnas > 6);

    //rellenamos la tabla por valores desde teclado
    cout << "Los valores de la tabla son: \n";
    for(int i = 0;i<nfilas;i++){
        for(int j = 0;j<ncolumnas;j++){
            cout << "Valor " << i+1 << ", " << j+1 << ": ";
            cin >> t[i][j];
        }
    }
}//fin del método cargar

//metodo para ver si el número buscado está en la tabla
bool examen::esta(){
    int num, i;
    int numCol;
    bool encontrado;
    //numero que queremos buscar
    cout << "Dime el numero que quieres buscar: ";
    cin >> num;
    //columna en la que queremos buscar dentro de sus valores
    do{
        cout << "Dime el numero de columna donde quieres buscar el numero: ";
        cin >> numCol;
        if(ncolumnas < 0 || ncolumnas > 6){
            cout << "El numero de columna no es correcto, introducelo de nuevo.\n";
        }
    }while(ncolumnas < 0 || ncolumnas > 6);
    numCol = numCol - 1;
    //esquema de búsqueda para encontrar el número
    i = 0;
    encontrado = false;
    while(i<nfilas && (!encontrado)){
        if(t[i][numCol] == num){
            encontrado = true;
        }
        else{
            i++;
        }
    }
    return encontrado;

}//fin del método esta

int main()
{
    //cargamos un objeto de la clase para ejecutar los métodos de arriba.
    examen ex;
    bool enc;
    ex.cargar();
    enc = ex.esta();
    if(enc){
        cout << "El numero se encuentra en la tabla y el valor de bool es: " << enc << "\n";
    }
    else{
        cout << "El numero NO se encuentra en la tabla y el valor de bool es: " << enc << "\n";
    }

    return 0;
}
