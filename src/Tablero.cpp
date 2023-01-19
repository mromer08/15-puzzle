#include "Tablero.h"

Tablero::Tablero(int filas, int columnas)
{
    this->filas = filas;
    this->columnas = columnas;
    fila_jugador = -1;
    colum_jugador = -1;
    crearMatriz();
}

Tablero::Tablero(int filas, int columnas, int **tablero_ref)
{
    this->filas = filas;
    this->columnas = columnas;
    fila_jugador = -1;
    colum_jugador = -1;
    crearMatriz();
    copyTablero(tablero_ref);
    findJugador(tablero_ref);
}

Tablero::~Tablero()
{
    for (int i = 0; i < filas; i++)
    {
        delete[] matriz[i];
    }
    delete[] matriz;
}

void Tablero::print()
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            showCasilla(i, j);
        }
        cout << endl;
    }
    cout << endl;
}

void Tablero::autollenar()
{
    srand(time(NULL));
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            matriz[i][j] = random(1, 99);
        }
    }
}

void Tablero::showCasilla(int fila, int columna)
{
    int casilla = matriz[fila][columna];
    if (casilla < 0)
        cout << "[ x]";
    else if (casilla > 9)
        cout << "[" << casilla << "]";
    else
        cout << "[ " << casilla << "]";
}

void Tablero::crearMatriz()
{
    matriz = new int *[filas];
    for (int i = 0; i < filas; i++)
    {
        matriz[i] = new int[columnas];
    }
}

bool Tablero::moverCasilla(int tipo_movimiento)
{

    int fila_ini = fila_jugador;
    int columna_ini = colum_jugador;
    bool resultado = false;

    switch (tipo_movimiento)
    {
    case MV_UP:
        if (fila_ini - 1 >= 0)
        {
            fila_jugador--;
            resultado = true;
        }

        break;
    case MV_DOWN:
        if (fila_ini + 1 < filas)
        {
            fila_jugador++;
            resultado = true;
        }
        break;
    case MV_LEFT:
        if (columna_ini - 1 >= 0)
        {
            colum_jugador--;
            resultado = true;
        }
        break;
    case MV_RIGHT:
        if (columna_ini + 1 < columnas)
        {
            colum_jugador++;
            resultado = true;
        }
        break;
    }
    moverCasilla(fila_ini, columna_ini, fila_jugador, colum_jugador);
    return resultado;
}

void Tablero::moverCasilla(int fila_ini, int column_ini, int fila_fin, int column_fin)
{
    int *casilla_inicio = &matriz[fila_ini][column_ini];
    int *casilla_destino = &matriz[fila_fin][column_fin];
    int aux = *casilla_inicio;

    *casilla_inicio = *casilla_destino;
    *casilla_destino = aux;
}

void Tablero::setMatriz(int **matriz)
{
    copyTablero(matriz);
    setCasilla(fila_jugador, colum_jugador, -1);
}

void Tablero::setCasilla(int fila, int columna, int valor)
{
    matriz[fila][columna] = valor;
}

int Tablero::random(int inferior, int superior)
{
    return inferior + rand() % (superior + 1 - inferior);
}

void Tablero::copyTablero(int **tablero_ref)
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            if (tablero_ref[i][j] == -1 && fila_jugador != -1 && colum_jugador != -1)
            {

                matriz[i][j] = tablero_ref[fila_jugador][colum_jugador];
                ;
            }
            else
            {
                matriz[i][j] = tablero_ref[i][j];
            }
        }
    }
}

void Tablero::findJugador(int **tablero)
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            if (tablero[i][j] == -1)
            {
                fila_jugador = i;
                colum_jugador = j;
                return;
            }
        }
    }
}

void Tablero::sort()
{
    int casillas = (filas * columnas) - 1;
    int arreglo[casillas];
    int pos = 0;
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            if (matriz[i][j] != -1)
            {
                arreglo[pos++] = matriz[i][j];
            }
        }
    }

    for (int i = 0; i < casillas; i++)
    {
        int actual = arreglo[i];
        int j = i - 1;
        while (j >= 0 && arreglo[j] > actual)
        {
            arreglo[j + 1] = arreglo[j];
            j--;
        }
        arreglo[j + 1] = actual;
    }

    pos = 0;

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            if (pos != casillas)
            {
                matriz[i][j] = arreglo[pos++];
            }
        }
    }
    matriz[filas - 1][columnas - 1] = -1;
    fila_jugador = filas - 1;
    colum_jugador = columnas - 1;
}

int Tablero::getCasilla(int fila, int columna) { return matriz[fila][columna]; }