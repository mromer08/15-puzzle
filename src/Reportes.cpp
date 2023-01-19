#include "Reportes.h"

Reportes::Reportes()
{
    inicio = nullptr;
}

Reportes::~Reportes()
{
    while (inicio != nullptr)
    {

        Nodo *puntero1 = inicio;
        Nodo *puntero2 = inicio;
        if (inicio != nullptr)
        {
            while (puntero1->siguiente != nullptr)
            {
                puntero2 = puntero1;
                puntero1 = puntero1->siguiente;
            }
            if (puntero1 != puntero2)
            {
                puntero2->siguiente = nullptr;
                delete puntero1;
            }
            else
            {
                delete inicio;
                inicio = nullptr;
            }
        }
    }
}

void Reportes::addSort(Partida *elemento)
{
    Nodo *nuevo = new Nodo();
    nuevo->dato = elemento;
    nuevo->siguiente = nullptr;

    if (inicio == nullptr || elemento->getPunteo() > inicio->dato->getPunteo())
    {
        nuevo->siguiente = inicio;
        inicio = nuevo;
    }
    else
    {
        Nodo *aux = inicio;
        while (aux->siguiente != nullptr && aux->siguiente->dato->getPunteo() > elemento->getPunteo())
        {
            aux = aux->siguiente;
        }
        if (aux->siguiente != nullptr)
        {
            nuevo->siguiente = aux->siguiente;
        }
        aux->siguiente = nuevo;
    }
}

void Reportes::print()
{
    int cont = 1;
    cout << "---------[TABLA DE POSICIONES]--------\n";
    cout<<"No.\tJUGADOR\t\tPUNTEO\tTIEMPO\n";
    for (Nodo *p = inicio; p != nullptr; p = p->siguiente)
    {
        cout << cont << ".\t" << p->dato->getResults(false) << endl;
        cont++;
    }
    cout<<endl;
}

