/**
 * @file Reportes.h
 * @author 202030799 Manuel Rojas
 * @brief Manejador de los reportes del juego tipo Lista Enlazada Simple
 * @version 0.1
 * @date 2022-04-05
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "Partida.h"
/**
 * @brief Estructura para los nodos de la lista enlazada
 *
 */
struct Nodo
{
    /**
     * @brief Puntero hacia el dato que almacenará el nodo
     *
     */
    Partida *dato;
    /**
     * @brief Puntero hacia el siguiente nodo
     *
     */
    Nodo *siguiente;
};

/**
 * @brief Clase Reportes basada en una lista enlazada para almacenar las diferentes partidas del juego.
 *
 */

class Reportes
{
private:
    /**
     * @brief Nodo inicial, es la cabeza de la lista
     *
     */
    Nodo *inicio;

public:
    /**
     * @brief Constructor para un nuevo manejador de reportes
     *
     */
    Reportes(/* args */);
    /**
     * @brief Destructor de la clase reportes
     *
     */
    ~Reportes();
    /**
     * @brief Imprime la tabla de posiciones del juego con todas las partidas jugadas desde el punteo más alto hasta el más bajo.
     *
     */
    void print();
    /**
     * @brief Agrega una nueva partida a la lista de reportes de manera ordenada según el punteo obtenido del jugador.
     *
     * @param valor El puntero de la partida que se agregará a la lista.
     */
    void addSort(Partida *valor);
};
