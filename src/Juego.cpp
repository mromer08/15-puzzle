#include "Juego.h"

Juego::Juego()
{
    nivel = nullptr;
    reportes = new Reportes();
    start();
    
}

Juego::~Juego()
{
    delete nivel;
    delete reportes;
}

void Juego::start()
{
    int opcion;
    bool salir = false;

    while (!salir)
    {
        cout << "--------[JUEGO DEL 15]--------\n";
        cout << "1) Jugar\n2) Crear Nivel\n3) Reportes\n4) Salir\n";
        opcion = Nivel::pedirNumero("Ingrese una opción: ");
        switch (opcion)
        {
        case 1:
            menuJugar();
            break;
        case 2:
            menuCrearNivel();
            break;
        case 3:
            reportes->print();
            break;
        case 4:
            cout << "Vuelve a jugar pronto uwu\n";
            salir = true;
            break;
        default:
            cout << "Ups, esa opción no existe :c\n";
            break;
        }
    }
}

void Juego::menuJugar()
{
    if (nivel == nullptr)
    {
        cout << "No hay niveles disponibles para jugar :c\n";
        cout << "Ingrese al menú de Crear Nivel y cree uno antes de jugar\n";
    }
    else
    {
        string name = Nivel::pedirCadena("Ingrese un nombre para el jugador: ");
        reportes->addSort(new Partida(name, nivel));
        reportes->print();
    }
}

void Juego::menuCrearNivel()
{
    int opcion;
    bool salir = false;

    while (!salir)
    {
        cout << "------[CREACIÓN DE NIVELES]------\n";
        cout << "1) Tablero aleatorio\n2) Definir tablero\n3) Cargar Archivo\n4) Regresar\n";
        opcion = Nivel::pedirNumero("Ingrese una opción: ");
        switch (opcion)
        {
        case 1:;
        case 2:;
        case 3:;
            crearTablero(opcion);
            break;
        case 4:
            salir = true;
            break;
        default:
            cout << "Ups, esa opción no existe :c\n";
            break;
        }
    }
}

void Juego::crearTablero(int opcion)
{
    if (nivel == nullptr)
    {
        int filas = Nivel::pedirNumero("Ingrese la cantidad de filas para el tablero: ");
        int columnas = Nivel::pedirNumero("Ingrese la cantidad de columnas para el tablero: ");
        nivel = new Nivel(5, filas, columnas);
    }
    nivel->addNivel(opcion);
}