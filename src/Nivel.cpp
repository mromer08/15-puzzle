#include "Nivel.h"

Nivel::Nivel(int capacidad, int filas_max, int colum_max)
{
    this->capacidad = capacidad;
    this->filas_max = filas_max;
    this->colum_max = colum_max;
    cantidad = 0;

    disponibles = new bool[capacidad];

    niveles = new int **[capacidad];
    for (int i = 0; i < capacidad; i++)
    {
        niveles[i] = new int *[filas_max];
        for (int j = 0; j < filas_max; j++)
        {
            niveles[i][j] = new int[colum_max];
        }
        disponibles[i] = true;
    }
}

Nivel::~Nivel()
{
    delete[] disponibles;

    for (int i = 0; i < capacidad; i++)
    {
        for (int j = 0; j < filas_max; j++)
        {
            delete[] niveles[i][j];
        }
        delete[] niveles[i];
    }
    delete[] niveles;
}

int **Nivel::getNivel(int pos)
{
    return niveles[pos];
}

int Nivel::getColumnas() { return colum_max; }

int Nivel::getFilas() { return filas_max; }

int Nivel::getCantidad() { return cantidad; }

int Nivel::getNivel(bool disponible)
{
    int pos = -1;
    do
    {
        printNiveles(disponible);
        pos = pedirNumero("Seleccione un espacio disponible: ") - 1;
    } while (pos < 0 || (disponible ? !disponibles[pos] : disponibles[pos]) || pos >= capacidad);
    return pos;
}

void Nivel::printNiveles(bool todos)
{
    cout << "-----[NIVELES]-----\n";
    for (int i = 0; i < capacidad; i++)
    {
        if (!todos && i < cantidad)
            cout << (i + 1) << ") ";
        else if (todos)
            cout << (i + 1) << ") ";
        if (!disponibles[i])
        {
            cout << "Nivel " << (i + 1) << endl;
        }

        else
        {
            if (todos)
                cout << "ESPACIO DISPONIBLE" << endl;
        }
    }
    cout << endl;
}

void Nivel::cargarArchivo(string ruta, int pos)
{
    try
    {
        ifstream archivo;
        string linea = "";
        archivo.open(ruta, ios::in);
        if (archivo.fail())
        {
            cout << "No se encontró el archivo :c";
        }
        else
        {
            while (!archivo.eof() && pos < capacidad)
            {
                string num = "";
                getline(archivo, linea);
                int fila = 0, columna = 0;
                for (auto x : linea)
                {
                    if (x == ',' || x == ' ')
                    {
                        if (num.length() > 0 && fila < filas_max)
                        {
                            niveles[pos][fila][columna++] = stoi(num);

                            if (columna >= colum_max)
                            {
                                columna = 0;
                                fila++;
                            }
                        }
                        num = "";
                    }
                    else
                    {
                        num += x;
                    }
                }

                disponibles[pos] = false;
                pos++;
                cantidad++;
            }
        }
        archivo.close();
    }
    catch (const std::exception &e)
    {
        cout<<"Ocurrió un error al momento de leer el archivo :c\n\n";
    }
}

void Nivel::addNivel(int tipo)
{
    cout << "-----[AGREGAR NIVEL]-----\n";
    int pos = getNivel(true);

    if (tipo != 3)
    {
        srand(time(NULL));
        for (int i = 0; i < filas_max; i++)
        {
            for (int j = 0; j < colum_max; j++)
            {
                int casilla;
                switch (tipo)
                {
                case 1:
                    casilla = random(1, 99);
                    if (i == filas_max - 1 && j == colum_max - 1)
                        casilla = -1;
                    break;
                case 2:
                    cout << "Casilla " << (i + 1) * (j + 1) << " de " << (filas_max) * (colum_max) << endl;
                    cout << "(Ingrese '-1' para el espacio vacío)\n";
                    casilla = pedirNumero("Ingrese un numero: ");
                    break;
                }
                niveles[pos][i][j] = casilla;
            }
        }
        cantidad++;
        disponibles[pos] = false;
    }
    else if (tipo == 3)
    {
        cargarArchivo(pedirCadena("Ingrese la ruta completa del archivo: "), pos);
    }
}

int Nivel::pedirNumero(string mensaje)
{
    int numero = -1;
    cout << mensaje;
    cin >> numero;
    cout << endl;
    return numero;
}

int Nivel::random(int inferior, int superior)
{
    return inferior + rand() % (superior + 1 - inferior);
}

string Nivel::pedirCadena(string mensaje)
{
    string cadena;
    cout << mensaje;
    cin >> cadena;
    cout << endl;
    return cadena;
}