#include <iostream>

using namespace std;

struct puntajeDeNombre{
    string nombreJugador;
    int puntaje = 0;
};

//cantidad de rondas
int n = 0;
//hash 
puntajeDeNombre* hashRonda;


puntajeDeNombre* r1;
puntajeDeNombre* r2;
puntajeDeNombre* r3;

void casosPrueba(){

    //defino cantiad de ronda 
    n = 3;

    //puntaje de cada ronda- leer de arcivo
    r1 = new puntajeDeNombre();
    r1->nombreJugador = "mike";
    r1->puntaje = 3;

    r2 = new puntajeDeNombre();
    r2->nombreJugador = "andres";
    r2->puntaje = 5;

    r3 = new puntajeDeNombre();
    r3->nombreJugador = "mike";
    r3->puntaje = 2;
    
};

string main () {
   
    //hash cerrado de largo n  
    hashRonda = new puntajeDeNombre[n];
      
  

}