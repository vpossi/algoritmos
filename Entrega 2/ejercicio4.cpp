// # C++
//     # compilar
//         # Win
//             g++ -o ejemplo.exe ejemplo.cpp
// g++ -o ejercicio1.exe Obligatorio\ejercicio1.cpp
//     # ejecutar "sin salida"
//         # Win
//             ejemplo.exe < 1000.in.txt > nul
#include <climits>
#include <string>
#include <iostream>
using namespace std;

template <class T>
//generico para todo nodolista
struct NodoLista
{
	T dato;
	NodoLista* sig;
	NodoLista(T& unDato) : dato(unDato), sig(0) {};
	NodoLista(T& unDato, NodoLista* unSig) : dato(unDato), sig(unSig) {};
};

struct Arista
{
	int _origen;
	int _destino;
	Arista(int origen, int destino) {
		this->_origen = origen;
		this->_destino = destino;
	}
};
typedef NodoLista<Arista>* ListaAristas;

template <class T>
class Cola
{
private:
	struct NodoColaFIFO
	{
		T dato;                                                                                // guarda el dato en si dentro del nodo
		NodoColaFIFO* sig;                                                                     // guarda la referencia al siguiente nodo
		NodoColaFIFO(T& unDato, NodoColaFIFO* unSiguiente) : dato(unDato), sig(unSiguiente) {} // Constructor con ambos datos
		NodoColaFIFO(T& unDato) : dato(unDato), sig(0) {}                                      // Constructor con solo el dato, por defecto el sig es null
	};

	NodoColaFIFO* ppio;
	NodoColaFIFO* fin;

public:
	Cola()
	{
		ppio = fin = 0;
	}
	void encolar(T nuevoDato)
	{
		NodoColaFIFO* nuevoNodo = new NodoColaFIFO(nuevoDato);
		if (ppio == NULL)
		{
			ppio = nuevoNodo;
		}
		else
		{
			fin->sig = nuevoNodo;
		}
		fin = nuevoNodo;
	}
	// pre: no esta vacia
	T desencolar()
	{
		assert(!estaVacia()); // validacion
		T ret = ppio->dato;
		ppio = ppio->sig;
		if (ppio == NULL)
		{
			fin = NULL;
		}
		return ret;
	}
	bool estaVacia()
	{
		return ppio == NULL;
	}
	T tope()
	{
		assert(!estaVacia()); // validacion
		return ppio->dato;
	}
};

class Grafo
{
public:
	// pre: v y w son vertices adyacentes
	// pos: agrega la arista (v, w) al grafo
	virtual void agregarArista(int v, int w) = 0;

	//pre: grafo disperso, no poderado y no dirigido 
	//pos: cantidad de componentes conexas que contiene en orden temporal: O(V + A).
	virtual int cantidadComponentesConexas() = 0;

};


class GrafoListaAdyacencia : public Grafo
{
private:
	int componentes = 0;
	//cant vertices
	int V = 0;
	//cant aristas
	int E = 0;
	ListaAristas* lstAdyacentes = nullptr;

	//bool* conocidos;
public:
	//constructor de la clase que inicializa vertices y cantidad de listas que tendrá
	GrafoListaAdyacencia(int cantVertices, int cantAristas) //O(V)
	{
		this->V = cantVertices;
		this->E = cantAristas;
		lstAdyacentes = new ListaAristas[cantVertices + 1];

		for (int i = 1; i <= cantVertices; i++)//O(V)
		{
			lstAdyacentes[i] = NULL;
		}
	}

	void agregarArista(int v, int w)// O(1)
	{
		//como el grafo no es dirigido tengo que agregarla en ambos sentidos
		Arista arista1(v, w);
		Arista arista2(w, v);
		lstAdyacentes[v] = new NodoLista<Arista>(arista1, lstAdyacentes[v]); // se agrega al ppio de la lista de los adyacentes al veritce v
		lstAdyacentes[w] = new NodoLista<Arista>(arista2, lstAdyacentes[w]); // se agrega al ppio de la lista de los adyacentes al veritce w
	}
	int  cantidadComponentesConexas() {
		bool* conocidos = new bool[V + 1];//O(v)
		for (int i = 1; i <= V + 1; i++)
		{
			conocidos[i] = false;
		}
		for (int i = 1; i < V + 1; i++) //o(v+a)
		{
			if (!conocidos[i] && lstAdyacentes[i] != NULL)
			{
				this->componentes++;
				DFS(i, conocidos);
			}
		}
		return this->componentes;
	}


	void DFS(int origen, bool* conocidos)
	{
		conocidos[origen] = true;
		ListaAristas adyacentes = this->lstAdyacentes[origen];
		 while (adyacentes != NULL)
        {
            int w = adyacentes->dato._destino;
            if(!conocidos[w]) {
                DFS(w, conocidos);
            }
            adyacentes = adyacentes->sig; 
        }	
	}
};

int main() {

//g++ -o ejercicio4.exe ejercicio4.cpp 
//ejercicio4.exe < 10.in.txt > prueba.txt 

	int V = 0;
	int E = 0;
	cin >> V;
	cin >> E;
	
	Grafo *grafo = new GrafoListaAdyacencia(V, E);
	
	int v, w;
	while(E > 0){
		cin >> v;
		cin >> w;

		if	(v != w)
			grafo->agregarArista(v, w);
		E--;
	}

	for(int v = 1; v <= V; v++)
		grafo->agregarArista(v, v);

	cout << grafo->cantidadComponentesConexas();
}