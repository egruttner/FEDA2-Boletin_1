#include <iostream>
#include <vector>
#include <functional>

using namespace std;
const int valor_buscado = 1110;

//BUSQUEDA SECUENCIAL
void secuencial(const vector<int> &A) 
{
    for (int i = 0; i < A.size(); ++i) {

        if (A[i] == valor_buscado) 
        {
            cout<<"VALOR:" + to_string(valor_buscado) + " ENCONTRADO EN POSICION: " + to_string(i) <<endl;
            break;
        }
    }

}

void binaria(const vector<int> &A)
{
    int izquierda = 0;
    int derecha = A.size() - 1;

    while (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;

        if (A[medio] == valor_buscado) {
            cout<<"VALOR:" + to_string(valor_buscado) <<endl;//ENCONTRADO
            break;
        } else if (A[medio] < valor_buscado) {
            izquierda = medio + 1;  // El elemento está en la mitad derecha
        } else {
            derecha = medio - 1;  // El elemento está en la mitad izquierda
        }
    }
}


void galopante(const vector<int> &A)
{
    int tamano = A.size();
    int paso = sqrt(tamano);
    int previo = 0;

    // Realiza saltos hasta encontrar un intervalo que contenga el objetivo
    while (A[std::min(paso, tamano) - 1] < valor_buscado) {
        previo = paso;
        paso += std::sqrt(tamano);
        if (previo >= tamano) {
            cout<<"NO ENCONTRADO VALOR:" + to_string(valor_buscado) <<endl;//ENCONTRADO
        }
    }

    // Realiza una búsqueda secuencial en el intervalo actual
    for (int i = previo; i < std::min(paso, tamano); ++i) {
        if (A[i] == valor_buscado) {
            cout<<"ENCONTRADO:" + to_string(valor_buscado) <<endl;//ENCONTRADO
        }
    }

}



//PARA TOMAR EL TIEMPO
long long execution_time_ms(const vector<int> &A, int id_busqueda_seleccionada) {
  auto start_time = std::chrono::high_resolution_clock::now();
  
    switch (id_busqueda_seleccionada)
    {
    case 1:
        secuencial(A);
    case 2:
        binaria(A);
    case 3:
        galopante(A);
    case 4:
        secuencial(A);
    case 5:
        binaria(A);
    case 6:
        galopante(A);

    default:
        break;
    }

  auto end_time = std::chrono::high_resolution_clock::now();
  return std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
}

//LEER VECTOR DESDE INPUT
void read_vector(vector<int> &M){
  for(auto &row : M)
    {
        cin>>row;
    }
}



        
