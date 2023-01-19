#include "Partida.h"

Partida::Partida(string jugador, Nivel *niveles)
{
    this->niveles = niveles;
    this->jugador = jugador;
    cout<<"----[SELECCION DE NIVEL]-----\n";
    this->nivel_actual = niveles->getNivel(false);
    this->tablero = new Tablero(niveles->getFilas(), niveles->getColumnas(), niveles->getNivel(nivel_actual));
    punteo = 0;
    minutos = 0;
    segundos = 0;
    horas = 0;
    start();
}

Partida::Partida(string jugador, int punteo, int pasos)
{
    this->jugador = jugador;
    this->pasos = pasos;
    this->punteo = punteo;
}

Partida::~Partida()
{
    // delete tablero;
}

int Partida::getPunteo() { return punteo; }

string Partida::getResults(bool isComplete)
{
    ostringstream results;

    if (isComplete)
    {
        results << "Jugador: " << jugador << "\nTiempo: " << getTime() << "\nPasos: " << pasos
                << "\nPuntaje: " << punteo;
    }
    else
    {
        results << jugador << "\t\t" << punteo << "\t" << getTime();
    }

    return results.str();
}

string Partida::getTime()
{
    ostringstream time;
    time << getTime(horas) << ":" << getTime(minutos) << ":" << getTime(segundos);
    return time.str();
}

string Partida::getTime(int time)
{
    ostringstream time_convert;
    if (time < 10)
        time_convert << '0';
    time_convert << time;

    return time_convert.str();
}

void Partida::start()
{
    int opcion;
    bool salir = false;
    auto tiempo_inicial = chrono::system_clock::now();

    while (!salir)
    {
        printTablero();
        cout << "8) Cambiar Arriba\n5) Cambiar Abajo\n6) Cambiar Derecha\n4) Cambiar Izquierda\n7) Nivel Anterior\n9) Siguiente Nivel\n1) Reiniciar Nivel\n3) Terminar Partida\n";
        opcion = Nivel::pedirNumero("Ingrese una opción: ");
        switch (opcion)
        {
        case Tablero::MV_UP:;
        case Tablero::MV_DOWN:;
        case Tablero::MV_RIGHT:;
        case Tablero::MV_LEFT:
            if (tablero->moverCasilla(opcion))
                pasos++;
            else
                cout << "No se puede realizar ese movimiento\n";
            break;
        case NEXT_LVL:
            cambiarNivel(true);
            break;
        case LAST_LVL:
            cambiarNivel(false);
            break;
        case REBOOT_LVL:
            delete this->tablero;
            tablero = new Tablero(niveles->getFilas(), niveles->getColumnas(), niveles->getNivel(nivel_actual));
            break;
        case FINISH_LVL:
            salir = true;
            break;
        default:
            cout << "\nEsa opción no está disponible :c\n";
            break;
        }
    }
    auto tiempo_final = chrono::system_clock::now();
    chrono::duration<float> duration = tiempo_final - tiempo_inicial;
    segundos = (int)duration.count();
    calcularTiempo();

    calcularPunteo();
    delete this->tablero;
    cout << getResults(true) << "\n\n";
}

void Partida::cambiarNivel(bool isNext)
{
    if (isNext && (nivel_actual + 1) < niveles->getCantidad())
    {
        tablero->setMatriz(niveles->getNivel(++nivel_actual));
    }
    else if (!isNext && (nivel_actual - 1) >= 0)
    {
        tablero->setMatriz(niveles->getNivel(--nivel_actual));
    }
    else
    {
        cout << "No se puede cambiar de nivel\n";
        pasos--;
    }
    pasos++;
}

void Partida::printTablero()
{
    cout << "-----[NIVEL " << (nivel_actual + 1) << "]-----\n";
    tablero->print();
}

void Partida::calcularPunteo()
{
    Tablero solucion = Tablero(niveles->getFilas(), niveles->getColumnas(), niveles->getNivel(nivel_actual));
    solucion.sort();
    cout << "-----[SOLUCIÓN DE NIVEL]-----\n";
    solucion.print();

    for (int i = 0; i < niveles->getFilas(); i++)
    {
        for (int j = 0; j < niveles->getColumnas(); j++)
        {
            if (solucion.getCasilla(i, j) == tablero->getCasilla(i, j))
            {
                punteo += 2;
            }
        }
    }
}

void Partida::calcularTiempo()
{
    horas = segundos / 3600;
    segundos %= 3600;
    minutos = segundos / 60;
    segundos %= 60;
}