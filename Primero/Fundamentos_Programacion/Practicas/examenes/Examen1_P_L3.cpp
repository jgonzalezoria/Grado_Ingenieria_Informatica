#include <iostream>
#include <cstdlib>
#include <ctime>
#define N 6

using namespace std;

class Primitiva{
    int Ganadora[N];
    int Jugada[N];
    int complementario;
public:
    void CargarGanadora();
    void CargarJugada();
    void CargarComplementario();
    int CalcularAciertos();
    void MostrarGanadora();
    void MostrarJugada();
    bool EstaComplementario();
};
//metodo para cargar la combinaci�n ganadora
void Primitiva::CargarGanadora(){
    int numGanador;
    /*
    cout << "Dime la combinaci�n ganadora: \n";
    for(int i=0;i<N;i++){
        do{
            cout << "Dime el numero de la posicion " << i+1 << " : \n";
            cin >> numGanador;
        }while(numGanador < 1 || numGanador > 49);
        Ganadora[i] = numGanador;
    }
    */
    cout << "Cargamos la combinacion ganadora.\n";
    srand(time(NULL));
    for(int i=0;i<N;i++){
        numGanador = 1 + rand()%49;
        if(i>0){
            for(int j=0;j<i;j++){
                if(numGanador==Ganadora[j]){
                    numGanador = 1 + rand()%49;
                    j--;
                }
            }
        }
        Ganadora[i] = numGanador;
    }
    cout << "Combinacion cargada correctamente\n";
}//fin de cargarGanadora

//m�todo para cargar el n�mero complementario
void Primitiva::CargarComplementario(){
    int numCompl;
    do{
        cout << "Dime el numero complementario: ";
        cin >> numCompl;
    }while(numCompl < 1 || numCompl > 49);
    complementario = numCompl;
    cout << "Complementario cargado correctamente.\n";
}

//m�todo para cargar nuestra jugada
void Primitiva::CargarJugada(){
    int numJugada;
    cout << "Dime la combinaci�n de tu jugada: \n";
    for(int i=0;i<N;i++){
        do{
            cout << "Dime el numero de la posicion " << i+1 << " : \n";
            cin >> numJugada;
        }while(numJugada < 1 || numJugada > 49);
        Jugada[i] = numJugada;
    }
    cout << "Combinacion cargada correctamente\n";
}//fin de cargarJugada

//m�todo para calcular cuantos aciertos hemos obtenido
int Primitiva::CalcularAciertos(){
    int i = 0;
    int aciertos = 0;
    while(i<N){
        if(Ganadora[i] == Jugada[i]){
            aciertos = aciertos + 1;
        }
        i++;
    }
    return aciertos;
}//fin de CalcularAciertos

//muestra la combinaci�n ganadora
void Primitiva::MostrarGanadora(){
    cout << "La combinacion ganadora es: \n\n";
    for(int i=0;i < N;i++){
        cout << Ganadora[i] << "\t";
    }
    cout << "\n\n";
}//fin de MostrarGanadora

//m�todo para calcular nuestra jugada
void Primitiva::MostrarJugada(){
    cout << "La combinacion de tu jugada es: \n\n";
    for(int i=0;i < N;i++){
        cout << Jugada[i] << "\t";
    }
    cout << "\n\n";
}//fin de MostrarJugada
bool Primitiva::EstaComplementario(){
    bool comple;
    if(complementario == 0){
        return comple = false;
    }
    else{
        return comple = true;
    }
}

int main()
{
    int opcion, aciertos;
    //con estas variables comprobaremos si las jugadas han sido cargadas.
    bool estaGanadora = false;
    bool estaJugada = false;
    Primitiva pr;
    do{
        do{
            system("cls");
            cout << "COMPROBAR COMBINACION\n\n";
            cout << "1.\Cargar combinacion ganadora y complementario\n";
            cout << "2.\Cargar combinacion jugada\n";
            cout << "3.\Comprobar aciertos\n";
            cout << "4.\Salir.\n";
            cout << "Selecciona una opcion: \n";
            cin >> opcion;
            if(opcion < 1 || opcion > 4){
                cout << "Opcion incorrecta. Marca otra opcion.\n";
            }
        }while(opcion < 1 || opcion > 4);
        switch(opcion){
            case 1:
                estaGanadora = true;
                pr.CargarGanadora();
                pr.CargarComplementario();
                break;
            case 2:
                estaJugada = true;
                pr.CargarJugada();
                break;
            case 3:
                //aqu� comprobamos si las jugadas est�n cargadas o no
                if(estaGanadora && estaJugada){
                    pr.MostrarGanadora();
                    pr.MostrarJugada();
                    aciertos = pr.CalcularAciertos();
                    cout << "Has obtenido " << aciertos << " aciertos.\n\n";
                    //comprobamos si existe el complementario
                    if(pr.EstaComplementario()){
                        cout << "El numero complementario esta cargado\n\n";
                    }
                    else{
                        cout << "El numero complementario NO esta cargado\n\n";
                    }
                }
                else{
                    cout << "Debe introducir su jugada y la combinacion ganadora.\n\n";
                }
                break;
        }
        cout << "\n";
        system("pause");

    }while(opcion != 4);

    return 0;
}
