/**
 * @file Partida.h
 * @author 202030799 Manuel Rojas
 * @brief Manejador para la partida del jugador. Es una clase auxiliar de la clase Juego
 * @version 0.1
 * @date 2022-04-05
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <string>
#include <sstream>
#include <chrono>
#include "Tablero.h"
#include "Nivel.h"

using namespace std;
/**
 * @brief Clase de manejar cada Partida de los jugadores.
 *
 */
class Partida
{
private:
    /**
     * @brief Nombre del jugador en la Partida
     *
     */
    string jugador;
    /**
     * @brief Pasos del jugador en la Partida.
     *
     */
    int pasos;
    /**
     * @brief Punteo del jugador en la Partida.
     *
     */
    int punteo;
    /**
     * @brief Puntero hacia un manejador de niveles para el Juego.
     *
     */
    Nivel *niveles;
    /**
     * @brief Puntero hacia un Tablero para usar en la Partida
     * 
     */
    Tablero *tablero;
    /**
     * @brief Horas jugadas en Partida
     * 
     */
    int horas;
    /**
     * @brief Minutos jugadas en Partida
     * 
     */
    int minutos;
    /**
     * @brief Segundos jugadas en Partida
     * 
     */
    int segundos;
    /**
     * @brief Nivel en el que se encuentra el jugador
     * 
     */
    int nivel_actual;
    /**
     * @brief Método para cambiar de nivel
     * 
     * @param isNext Valor true para ir hacia el siguiente nivel, de lo contrario se irá hacia el anterior.
     */
    void cambiarNivel(bool isNext);
    /**
     * @brief Método para imprimir un tablero.
     * 
     */
    void printTablero();
    /**
     * @brief Método para calcular el punteo del jugador en partida
     * 
     */
    void calcularPunteo();
    /**
     * @brief Método para calcular el tiempo en partida del jugador
     * 
     */
    void calcularTiempo();
    /**
     * @brief Método para estilizar la muestra de horas, minutos o segundos
     * 
     * @param time El valor númerico
     * @return string Retorna una cadena con el valor ya estilizado. Ej.: 01, 12, 09
     */
    string getTime(int time);
    /**
     * @brief Método para iniciar por completo una partida
     * 
     */
    void start();

public:
    /**
     * @brief Valor representativo para indicar el cambio hacia el siguiente nivel.
     *
     */
    static const int NEXT_LVL = 9;
    /**
     * @brief Valor representativo para indicar el cambio hacia el anterior nivel.
     *
     */
    static const int LAST_LVL = 7;
    /**
     * @brief Valor representativo para indicar el reinicio de nivel.
     *
     */
    static const int REBOOT_LVL = 1;
    /**
     * @brief Valor representativo para indicar la finalización de la partida.
     *
     */
    static const int FINISH_LVL = 3;

    /**
     * @brief Primer constructor de la clase partida.
     *
     * @param jugador El nombre del jugador que jugará la partida. Éste se guardará en los registros del juego
     * @param niveles El manejador de niveles del juego. Servirá para poder seleccionar tableros y moverse de nivel en nivel de ser el caso.
     */
    Partida(string jugador, Nivel *niveles);
    /**
     * @brief Segundo constructor de la clase partida. Puede utilizarse para realizar pruebas independientes.
     *
     * @param jugador El nombre del jugador que jugará la partida. Éste se guardará en los registros del juego
     * @param punteo El punteo obtenido por el jugador.
     * @param pasos Los pasos dados por el jugador en la partida.
     */
    Partida(string jugador, int punteo, int pasos);
    /**
     * @brief Destructor de la clase.
     *
     */
    ~Partida();
    /**
     * @brief Obtener el punteo de la partida
     *
     * @return int Devuelve el punteo obtenido por el jugador en la partida.
     */
    int getPunteo();
    /**
     * @brief Obtener los resultados de la partida.
     *
     * @param isComplete Indicar si se requiere un resumen de los resultados o se requieren todos los datos de la partida.
     * @return string Retorna los resultados de la partida.
     */
    string getResults(bool isComplete);
    /**
     * @brief Obtener el tiempo de juego.
     *
     * @return string Devuelve una cadena con el tiempo en partida en formato hh:mm:ss
     */
    string getTime();
};