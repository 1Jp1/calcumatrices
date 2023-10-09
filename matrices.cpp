/*  Este programa muestra la reservación y liberación de matrices en tiempo de ejecución.
    El operador "new" es similar a malloc de C y "delete" es similar a "free" de C.
    Una vez creada la matriz dinámica, nótese que su uso es igual al de una matriz "normal". */

#include <iostream> //Biblioteca para flujos estándar de C++.
#define N_FILAS 2   //Macro que define N_FILAS como 2.
//#define N_COLUS 3   //Macro que define N_COLUS como 3.


//Función que imprime una matriz. Nótese su manejo como matriz "normal".
//Recibe un apuntador de apuntadores representando la matriz y no regresa nada.
void imprimir_matriz(float **matriz) {
    for (int i = 0; i < N_FILAS; i++) {
        for (int j = 0; j < N_FILAS; j++) {
            std::cout << matriz[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

void suma_matrices(float **matriz, float **matriz2 ){
    std::cout << "La suma de las matrices es "  << "\n" ;
    for (int i = 0; i < N_FILAS; i++) {
        for (int j = 0; j < N_FILAS; j++) {
            std::cout << matriz[i][j] + matriz2[i][j] << '\t';
        }
        std::cout << std::endl;
    }    
}

void resta_matrices(float **matriz, float **matriz2 ){
    std::cout << "La resta de las matrices es "  << "\n" ;
    for (int i = 0; i < N_FILAS; i++) {
        for (int j = 0; j < N_FILAS; j++) {
            std::cout << matriz[i][j] - matriz2[i][j] << '\t';
        }
        std::cout << std::endl;
    }    
}

//Función que llena con valores una matriz. Nótese su manejo como matriz "normal".
//Recibe un apuntador de apuntadores representando la matriz y no regresa nada.
void llenar_matriz(float **matriz, int intento) {
    std::cout << "LLena la matriz " << intento << "\n" ;
    for (int i = 0; i < N_FILAS; i++) {
        for (int j = 0; j < N_FILAS; j++) {
            std::cout << "Ingresa el elemento (" << i+1 <<", " << j+1 << "): ";
            std::cin >> matriz[i][j];
        }
    }
}

int main(void) {
    float **matriz; //Apuntador a apuntador donde se guardará la referencia de la matriz.
    float **matriz2;

    //Se reserva memoria para N_FILAS cantidad de filas.
    matriz = new float*[N_FILAS];
    matriz2 = new float*[N_FILAS];
    //Por cada fila, se reserva memoria para N_COLUS.       
    for (int i = 0; i < N_FILAS; i++) {
        matriz[i] = new float[ N_FILAS ];
        matriz2[ i ] = new float[ N_FILAS ];
    }


    //Se llena e imprime la matriz con las funciones creadas.
    llenar_matriz(matriz, 1);
    llenar_matriz( matriz2, 2);    
    imprimir_matriz(matriz);
    imprimir_matriz(matriz2);

    suma_matrices( matriz , matriz2 );
    resta_matrices( matriz , matriz2);
    
    //Se borra cada fila de la matriz.
    for (int i = 0; i < N_FILAS; i++) {
        delete[] matriz[i];
        delete[] matriz2[i];
        
    }
    //Se borran los apuntadores a cada fila de la matriz.
    delete[] matriz;
    delete[] matriz2;

    return 0;

}
