/**
 * @file Nivel.h
 * @author 202030799 Manuel Rojas
 * @brief Manejador para los distintos niveles del juego
 * @version 0.1
 * @date 2022-04-05
 *
 *
 */

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>

using namespace std;
/**
 * @brief Clase encargada de manejar los niveles del Juego
 * 
 */
class Nivel
{
private:
    /**
     * @brief Puntero para un arreglo 3D de numeros enteros para los niveles y sus respectivos tableros.
     * 
     */
    int ***niveles;
    /**
     * @brief Puntero hacia un arreglo de booleanos para saber si un nivel se encuentra lleno o disponible.
     * 
     */
    bool *disponibles;
    /**
     * @brief La cantidad de niveles que se acumularán
     * 
     */
    int cantidad;
    /**
     * @brief La capacidad de niveles que se podrán almacenar
     * 
     */
    int capacidad;
    /**
     * @brief La cantidad de filas para cada Tablero del Juego
     * 
     */
    int filas_max;
    /**
     * @brief La cantidad de columnas para cada Tablero del Juego
     * 
     */
    int colum_max;
    /**
     * @brief Método que sirve para generar un número aleatorio
     * 
     * @param inferior Rango inferior para generar el número aleatorio.
     * @param superior Rango superior para generar el número aleatorio
     * @return int Retorna el número aleatorio generado.
     */
    int random(int inferior, int superior);

public:
    /**
     * @brief Constructor para un nuevo Manejador de niveles
     *
     * @param capacidad Es la cantidad de niveles que podrá almacenar.
     * @param filas_max Es la cantidad de filas que tendrán los tableros de cada nivel.
     * @param colum_max Es la cantidad de columnas que tendrán los tableros de cada nivel.
     */
    Nivel(int capacidad, int filas_max, int colum_max);

    /**
     * @brief Destructor del manejador de niveles.
     *
     */
    ~Nivel();

    /**
     * @brief Imprime una lista de los niveles almacenados en el orden en que fueron agregados.
     *
     * @param todos Indicar si se requiere imprimir todos los nombres o no. En caso de ser todos y alguno de 
     *              éstos no estuviera ocupado aún aparecerá como DISPONIBLE.
     */
    void printNiveles(bool todos);
    /**
     * @brief Agrega un nuevo nivel
     * 
     * @param tipo La manera en la que se agregará el nivel: 1. Aleatorio, 2. Manual, 3. Por archivo
     * 
     */
    void addNivel(int tipo);
    /**
     * @brief Método para cargar un archivo de entrada con elementos para crear un tablero o varios.
     * 
     * @param ruta La ruta completa donde se encuentra el archivo a cargar.
     * @param pos La posición inicial desde donde se comenzarán a agregar los niveles que contenga el archivo.
     */
    void cargarArchivo(string ruta, int pos);
    /**
     * @brief Obtener un tablero con una posisción específica dentro del manejador de niveles.
     * 
     * @param pos La posición o número de nivel que se quiere obtener.
     * @return int** Devuelve una matriz de punteros de enteros con los valores del tablero solicitado.
     */
    int **getNivel(int pos);
    /**
     * @brief Método para obtener la posición de cierto nivel dentro del manejador de niveles.
     * 
     * @param disponible Se debe indicar si se requiere que el nivel en esa posición esté diponible (true) o no (false)
     * @return int Devuelve el número de la posición del nivel seleccionado.
     */
    int getNivel(bool disponible);
    /**
     * @brief Método para pedir valores enteros al usuario.
     * 
     * @param mensaje Texto que se le mostrará al usuario antes de solicitar el número.
     * @return int Devuelve el número ingresado por el usuario.
     */
    static int pedirNumero(string mensaje);
    /**
     * @brief Método para pedir cadenas de texto al usuario.
     * 
     * @param mensaje Texto que se le mostrará al usuario antes de solicitar la cadena de texto.
     * @return string Devuelve la cadena ingresada por el usuario.
     */
    static string pedirCadena(string mensaje);
    /**
     * @brief Obtener la cantidad de niveles acumulados.
     * 
     * @return int Devuelve la cantidad exácta de niveles creados hasta el momento.
     */
    int getCantidad();
    /**
     * @brief Obtener las filas máximas para cada tablero
     * 
     * @return int Devuelve las filas máximas para cada tablero.
     */
    int getFilas();
    /**
     * @brief Obtener las columnas máximas para cada tablero.
     * 
     * @return int Devuelve las columnas máximas para cada tablero.
     */
    int getColumnas();
};