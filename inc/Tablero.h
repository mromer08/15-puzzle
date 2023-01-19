/**
 * @file Tablero.h
 * @author 202030799 Manuel Rojas
 * @brief Manejador para un tablero.
 * @version 0.1
 * @date 2022-04-05
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
/**
 * @brief Clase encargada de manejar un tablero dentro del Juego
 * 
 */
class Tablero
{
private:
    /**
     * @brief Filas totales del tablero
     * 
     */
    int filas;
    /**
     * @brief Columnas totales del tablero
     * 
     */
    int columnas;
    /**
     * @brief Fila donde se encuentra el jugador
     * 
     */
    int fila_jugador;
    /**
     * @brief Columna donde se encuentra el jugador
     * 
     */
    int colum_jugador;
    /**
     * @brief Matriz de punteros numericos que contienen las casillas del tablero
     * 
     */
    int **matriz;
    /**
     * @brief Método para crear los espacios en memoria para el tablero
     * 
     */
    void crearMatriz();
    /**
     * @brief Método para imprimir una casilla estilizada
     * 
     * @param fila Fila de la casilla
     * @param columna Columna de la casilla
     */
    void showCasilla(int fila, int columna);
    /**
     * @brief Método que sirve para generar un número aleatorio
     * 
     * @param inferior Rango inferior para generar el número aleatorio.
     * @param superior Rango superior para generar el número aleatorio
     * @return int Retorna el número aleatorio generado.
     */
    int random(int inferior, int superior);
    /**
     * @brief Método para copiar un tablero
     * 
     * @param tablero_ref Una matriz de punteros numericos del cual se tomará referencia para copiar sus valores
     */
    void copyTablero(int **tablero_ref);
    /**
     * @brief Método para encontrar al jugador en un tablero
     * 
     * @param tablero El tablero en el cual se buscará al jugador.
     */
    void findJugador(int **tablero);

public:
    /**
     * @brief Valor representativo para indicar el movimiento hacia arriba.
     *
     */
    static const int MV_UP = 8;
    /**
     * @brief Valor representativo para indicar el movimiento hacia abajo.
     *
     */
    static const int MV_DOWN = 5;
    /**
     * @brief Valor representativo para indicar el movimiento hacia la derecha.
     *
     */
    static const int MV_RIGHT = 6;
    /**
     * @brief Valor representativo para indicar el movimiento hacia la izquierda.
     *
     */
    static const int MV_LEFT = 4;
    /**
     * @brief Primer constructor para un tablero
     *
     * @param filas Número de filas que tendrá el tablero
     * @param columnas Número de columnas que tendrá el tablero.
     */
    Tablero(int filas, int columnas);
    /**
     * @brief Segundo constructor para un tablero
     *
     * @param filas Número de filas que tendrá el tablero
     * @param columnas Número de columnas que tendrá el tablero.
     * @param tablero_ref Matriz de punteros de números enteros de alguna matriz de referencia
     */
    Tablero(int filas, int columnas, int **tablero_ref);
    /**
     * @brief Destructor de la clase
     *
     */
    ~Tablero();
    /**
     * @brief Método para mover una casilla hacia otra.
     *
     * @param fila_ini posición de la fila incial.
     * @param column_ini posición de la columna incial.
     * @param fila_fin posición de la fila hacia donde se moverá.
     * @param column_fin posición de la columna hacia donde se moverá.
     */
    void moverCasilla(int fila_ini, int column_ini, int fila_fin, int column_fin);
    /**
     * @brief Método para realizar movientos en partida sobre el tablero.
     *
     * @param tipo_movimiento El tipo de movimiento que se realizará. Ver los valores estáticos definidos en la clase.
     * @return true Devuelve verdadero cuando el movimiento pudo realizarse con éxito.
     * @return false Devuelve falso cuando el movimientoo no pudo realizarse.
     */
    bool moverCasilla(int tipo_movimiento);
    /**
     * @brief Obtener el valor de una casilla especifica del tablero
     *
     * @param fila posición de la fila donde se encuentra
     * @param columna posición de la columna donde se encuentra
     * @return int Devuelve el valor encontrado en el tablero.
     */
    int getCasilla(int fila, int columna);
    /**
     * @brief Cambiar la matriz de números del tablero, puede utilizarse cuando se requiere cambiar de nivel
     *
     * @param matriz Matriz de punteros de numeros enteros el cual servirá como nuevo tablero.
     */
    void setMatriz(int **matriz);
    /**
     * @brief Cambiar el valor de una casilla especifica del tablero
     *
     * @param fila posición de la fila donde se encuentra
     * @param columna posición de la columna donde se encuentra
     * @param valor El valor que se reemplazará en la posición indicada.
     */
    void setCasilla(int fila, int columna, int valor);
    /**
     * @brief Imprime el tablero en consola.
     *
     */
    void print();
    /**
     * @brief Rellena el tablero de manera automática
     *
     */
    void autollenar();
    /**
     * @brief Ordena el tablero de menor a mayor
     *
     */
    void sort();
};