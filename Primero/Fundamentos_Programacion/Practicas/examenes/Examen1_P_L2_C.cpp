#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string.h>

using namespace std;

#define Npruebas 5 //La competición cuenta con 5 pruebas
#define MAXPart 10 //Número máximo de participantes 10

typedef char cadena[50];

// datos del competidor
struct Datos{
    cadena Nombre; // Nombre de participante
    int dorsal; // Número que se le asigna como dorsal
};

class Competicion{
    int NumPart;                        // Nº de participantes inscritos en la competición
    Datos Participantes[MAXPart];       // Información de cada participante
    int Puntuaciones[MAXPart][Npruebas];// Puntuación entre 0 y 10 obtenida por cada participante en cada prueba
public:
    void Inscribir();
    void AnotarPuntos();
    void DatosCompetidor();
    void Perdedor();
};// fin de la clase Competición

//método para inscribir a los participantes
void Competicion::Inscribir(){
    srand(time(NULL));
    int dors;
    do{
        cout << "Dime el numero de participantes: ";
        cin >> NumPart;
        if(NumPart < 1 || NumPart > MAXPart){
            cout << "El numero de participantes es erroneo, indique otro numero.\n\n";
        }
    }while(NumPart < 1 || NumPart > MAXPart);
    cout << "\n";
    for(int i=0;i<NumPart;i++){
        cout << "Dime el nombre del participante " << i+1 << ": ";
        cin >> Participantes[i].Nombre;
        dors = 1 + rand()%100;
        if(i>0){
            for(int j=0;j<i;j++){
                if(dors == Participantes[i].dorsal){
                    dors = 1 + rand()%100;
                    j--;
                }
            }
        }
        Participantes[i].dorsal = dors;
        cout << "\n";
    }
}//fin del método Inscribir

// método que se utilizará para anotar las puntuaciones obtenidas de cada participante
void Competicion::AnotarPuntos(){
    int puntos;
    for(int i=0;i<NumPart;i++){
        cout << "Dime las puntuaciones de las pruebas del participante " << Participantes[i].Nombre << ": \n";
        for(int j=0;j<Npruebas;j++){
            do{
                cout << "Puntuacion prueba " << j+1 << " es: ";
                cin >> puntos;
                if(puntos < 0 || puntos > 10){
                    cout << "Puntuacion erronea, indica una puntuacion entre 0 y 10.\n";
                }
            }while(puntos < 0 || puntos > 10);
            Puntuaciones[i][j] = puntos;
        }
        cout << "\n";
    }
}// fin del método anotar puntos
// muestra el dorsal y los puntos conseguidos en cada prueba de cada participante
void Competicion::DatosCompetidor(){
    cadena buscado;
    bool encontrado;
    int i;
    do{
        i=0;
        encontrado = false;
        cout << "Dime el nombre del participante: ";
        cin >> buscado;
        while(i<NumPart && (!encontrado)){
            if(strcmp(Participantes[i].Nombre, buscado) == 0){
                encontrado = true;
            }
            else{
                i++;
            }
        }
        if(!encontrado){
            cout << "Este participante no existe, digame otro: \n";
        }
    }while(encontrado != true);
    cout << "Dorsal: " << Participantes[i].dorsal << "\n";
    for(int j=0;j<Npruebas;j++){
        cout << "Puntuacion prueba " << j+1 << ": " << Puntuaciones[i][j] << endl;
    }
    cout << "\n";
}// fin del método DatosCompetidor

// muestra los datos de participante perdedor y la puntuación de cada prueba.
void Competicion::Perdedor(){
    //hallamos las puntuaciones totales
    int puntosTotales[NumPart];
    for(int i=0;i<NumPart;i++){
        puntosTotales[i]=0;
        for(int j=0;j<Npruebas;j++){
            puntosTotales[i] = puntosTotales[i] + Puntuaciones[i][j];
        }
    }
    //comparamos las puntuaciones para encontrar la mas baja
    int menorPunt, contador;
    contador = 0;
    menorPunt = puntosTotales[0];

    for(int i=1;i<NumPart;i++){
         if(puntosTotales[i]<menorPunt){
            menorPunt = puntosTotales[i];
            contador = i;
         }
    }
    cout << "El competidor que ha perdido es " << Participantes[contador].Nombre << " con dorsal "
    << Participantes[contador].dorsal << "\n";
    // mostramos las puntuciaciones del perdedor
    for(int j=0;j<Npruebas;j++){
        cout << "Puntuacion prueba " << j+1 << ": " << Puntuaciones[contador][j] << endl;
    }
    cout << "\n";

}

int main()
{
    Competicion cp;
    bool estaInscrito = false;
    bool estaAnotado = false;
    char opc;
    int opcion;
    //mostramos el menu por pantalla
    do{
        do{
            system("cls");
            cout << "1.\tInscribir al conjunto de participantes en la competicion.\n";
            cout << "2.\tAnotar las puntuaciones conseguidas.\n";
            cout << "3.\tConsultar los datos de un competidor.\n";
            cout << "4.\tMostrar los datos del perdedor.\n";
            cout << "5.\tSalir.\n";
            cout << "Selecciona una opcion: \n";
            cin >> opcion;
            if(opcion < 1 || opcion > 5){
                cout << "Opcion incorrecta. Marca otra opcion.\n";
            }
            cout << "\n";
        }while(opcion < 1 || opcion > 5);
        switch(opcion){
            case 1:
                estaInscrito = true;
                cp.Inscribir();
                break;
            case 2:
                if(estaInscrito){
                    estaAnotado = true;
                    cp.AnotarPuntos();
                }
                else{
                    cout << "Debe introducir lo datos de los competidores.\n";
                }

                break;
            case 3:
                if(estaAnotado && estaInscrito){
                    do{
                        do{
                            cout << "Quieres ver los datos de un competidor (S o N): \n\n";
                            cin >> opc;
                            if(opc !='s' && opc !='S' && opc !='n' && opc !='N'){
                            cout << "Opcion incorrecta, marca la opcion correcta";
                            }
                        }while(opc !='s' && opc !='S' && opc !='n' && opc !='N');
                        switch(opc){
                            case 's':
                            case 'S':
                                cp.DatosCompetidor();
                                break;
                        }
                    }while(opc !='n' && opc !='N');
                }
                else{
                    cout << "Debe introducir lo datos de los competidores.\n";
                }
                break;
            case 4:
                if(estaAnotado && estaInscrito){
                    cp.Perdedor();
                }
                else{
                    cout << "Debe introducir lo datos de los competidores";
                }
                break;
        }
        cout << "\n";
        system("pause");
    }while(opcion !=5);
    return 0;
}
