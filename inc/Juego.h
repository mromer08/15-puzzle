/**
 * @file Juego.h
 * @author 202030799 Manuel Rojas
 * @brief Manejador principal del juego
 * @version 0.1
 * @date 2022-04-05
 *
 *
 */
#include "Reportes.h"

using namespace std;
/**
 * @brief Clase encargada de guiar al jugador por el juego.
 * 
 */
class Juego
{
private:
    /**
     * @brief Puntero hacia un manejador de niveles para el Juego.
     * 
     */
    Nivel *nivel;
    /**
     * @brief Puntero hacia un manejador de reportes el cual contendrá todas las Partidas jugadas.
     * 
     */
    Reportes *reportes;
    /**
     * @brief Menú que se le mostrará al jugador cuando quiera iniciar una nueva Partida
     * 
     */
    void menuJugar();
    /**
     * @brief Menú que se le mostrará al usuario cuando quiera crear un nuevo Nivel
     * 
     */
    void menuCrearNivel();
    /**
     * @brief Menú que se le mostrá al usuario cuando quiera crear un nuevo Tablero
     * 
     * @param tipo El tipo de creación que hará: 1. Aleatorio, 2. Manual, 3. Por archivo
     */
    void crearTablero(int tipo);
    /**
     * @brief Método que inicializa el juego por completo.
     * 
     */
    void start();

public:
    /**
     * @brief Constructor para un nuevo Juego, se iniciará de inmediato el juego
     *
     */
    Juego();

    /**
     * @brief Destructor del juego
     *
     */
    ~Juego();
};
