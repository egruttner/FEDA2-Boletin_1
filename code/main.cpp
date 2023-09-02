#include <iostream>
#include <algorithm>
#include <chrono>
#include <fstream>
#include <string.h>
#include "busquedas.h"
#include <fstream>

using namespace std;

int main(int argv, char* argc[]) {
  srand(time(NULL)); 

  int n;
  string dir_csv;
  string busqueda_seleccionada;
  int id_busqueda_seleccionada;
  string nombre_archivo_salida;

  cout<<"INICIO"<<endl;

  //TIPOS DE PRUEBAS
  switch(atoi(argc[1])){
    case 1: busqueda_seleccionada = "secuencial"; break;
    case 2: busqueda_seleccionada = "binaria"; break;
    case 3: busqueda_seleccionada = "galopante"; break;
    case 4: busqueda_seleccionada = "secuencial"; break;
    case 5: busqueda_seleccionada = "binaria"; break;
    case 6: busqueda_seleccionada = "galopante"; break;

    default: busqueda_seleccionada = ""; break;
  }

  //DEFINE DIRECTORIO DE CSV
  dir_csv = "csv/csv" + to_string(atoi(argc[3]))+ "/";

  //SI ENTRA CON PARÁMETROS, REALIZA EL TEST
  if((argv > 2) && (strcmp(argc[2],"--test") == 0)){

    //LEE EL TAMAÑO DEL VECTOR
    cin>>n;

    //BUSQUEDA SELECCIONADA COMO PARAMETRO
    id_busqueda_seleccionada = atoi(argc[3]);

    //DEFINE MATRICES DE ENTRADA
    vector<int> M_A(n);   //MATRIZ A

    //LEE VECTOR
    read_vector(M_A);
    
    nombre_archivo_salida = dir_csv + busqueda_seleccionada + "_results.csv";
    ofstream outfile(nombre_archivo_salida,std::ios::app);

    double mm_total_time = 0;
    int numero_de_experimentos=1;
    for(int j = 0; j < numero_de_experimentos; j++){ 
      
      long long single_execution_time = execution_time_ms(M_A, id_busqueda_seleccionada);
      
      mm_total_time += single_execution_time;
    }
    double mm_avg_time = mm_total_time / numero_de_experimentos;
    outfile << n << "," << mm_avg_time <<endl;
    outfile.close(); 
    
    return 0;
  }
  else
  //SINO CREA EL ENCABEZADO PARA GUARDAR EL CSV
  {
    nombre_archivo_salida = dir_csv + busqueda_seleccionada + "_results.csv";
    ofstream outfile(nombre_archivo_salida);
    outfile << "n,tiempo[ms]\n";

    return 0;
  }


}
