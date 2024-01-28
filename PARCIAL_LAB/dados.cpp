#include <iostream>
using namespace std;
#include "rlutil.h"
using namespace rlutil;
#include <cstdlib>
#include <ctime>

/// TODO ESTO LO HICE GUIANDOME EL VIDEO DE LA CLASE 15 O 16, EN ESA CLASE EXPLICAN COMO DIBUJAR LOS DADOS.

void recuadro(int x, int y, int ancho, int alto){
        const char *UI_BOTTOM_RIGHT = "\xD9"; // 217 - ┘
        const char *UI_BOTTOM_LEFT = "\xC0"; // 192 - └
        const char *UI_TOP_LEFT = "\xDA"; // 218 - ┌
        const char *UI_TOP_RIGHT = "\xBF"; // 191 - ┐
        const char *UI_CROSS = "\xC5"; // 197 - ┼
        const char *UI_HORIZONTAL_LINE = "\xC4"; // 196 - ─
        const char *UI_HORIZONTAL_LINE_TOP = "\xC1"; // 193 - ┴
        const char *UI_HORIZONTAL_LINE_BOTTOM = "\xC2"; // 194 - ┬";
        const char *UI_VERTICAL_LINE = "\xB3"; // 179 - │
        const char *UI_VERTICAL_LINE_LEFT = "\xC3"; // 195 - ├
        const char *UI_VERTICAL_LINE_RIGHT = "\xB4"; // 180 - ┤

        /// se borra el espacio del recuadro
        int i, j;
        for(i=x; i<=x+ancho; i++){
            for(j=y; j<=y+alto; j++){
                locate(i, j);
                cout << " ";
            }
        }



        /// lineas horizontales
        for(i=x; i<=x+ancho; i++){
            locate(i, y); /// i seria "x" recorre toda la linea horizontal y la "y"
            cout << UI_HORIZONTAL_LINE;
            locate(i, y+alto);/// i, y+alto para hacer la otra linea horizontal
            cout << UI_HORIZONTAL_LINE;
        }

        /// lineas verticales
        for(i=y; i<=y+alto; i++){
            locate(x, i);
            cout << UI_VERTICAL_LINE;
            locate(x+ancho, i);
            cout << UI_VERTICAL_LINE;

        /// vertices (extremos)
        locate(x, y); ///EXTREMO SUPERIOR IZQUIERDO
        cout << UI_TOP_LEFT;
        locate(x, y+alto);
        cout << UI_BOTTOM_LEFT; /// ABAJO A LA IZQUIEDA
        locate(x+ancho, y);
        cout << UI_TOP_RIGHT; /// EXTREMO SUPERIOR DERECHO
        locate(x+ancho, y+alto);
        cout << UI_BOTTOM_RIGHT; /// ABAJO A LA DERECHA
        }
}

    void dibujarDado(int nroDado, int valor){
            const int Y = 10;
            const int ALTO = 4;
            const int INI = 5;///lo que hace esto es colocar los dados mas a la izquierda o derecha
            const int X = INI + (nroDado * 10); /// esto es para evitar que se dibuje sobre si mismo
            const int ANCHO = 8;

            ///UBICACIONES DE LOS PUNTOS
            const int CENTRO_X = X + ANCHO/2;
            const int CENTRO_Y = Y + ALTO/2;
            const int ARRIBA_X = CENTRO_X + 2;
            const int ARRIBA_Y = CENTRO_Y + 1;
            const int ABAJO_X = CENTRO_X - 2;
            const int ABAJO_Y = CENTRO_Y - 1;


            recuadro (X, Y, ANCHO, ALTO);
            /// dibujar los puntos
            const char *punto = "." ;
            switch(valor){
            case 1:
                locate(CENTRO_X, CENTRO_Y);///dado 1
                cout << punto;
                break;

            case 2:
                locate(ARRIBA_X, ARRIBA_Y);
                cout << punto;
                locate(ABAJO_X, ABAJO_Y);
                cout << punto;
                break;

            case 3:
                locate(CENTRO_X, CENTRO_Y);
                cout << punto;
                locate(ARRIBA_X, ARRIBA_Y);
                cout << punto;
                locate(ABAJO_X, ABAJO_Y);
                cout << punto;
                break;

            case 4:
                locate(ARRIBA_X, ARRIBA_Y);
                cout << punto;
                locate(ABAJO_X, ABAJO_Y);
                cout << punto;
                locate(ABAJO_X, ARRIBA_Y);
                cout << punto;
                locate(ARRIBA_X, ABAJO_Y);
                cout << punto;
                break;

            case 5:
                locate(CENTRO_X, CENTRO_Y);
                cout << punto;
                locate(ARRIBA_X, ARRIBA_Y);
                cout << punto;
                locate(ABAJO_X, ABAJO_Y);
                cout << punto;
                locate(ABAJO_X, ARRIBA_Y);
                cout << punto;
                locate(ARRIBA_X, ABAJO_Y);
                cout << punto;
                break;

            case 6:
                locate(ARRIBA_X, ARRIBA_Y);
                cout << punto;
                locate(ABAJO_X, ABAJO_Y);
                cout << punto;
                locate(ABAJO_X, ARRIBA_Y);
                cout << punto;
                locate(ARRIBA_X, ABAJO_Y);
                cout << punto;
                locate(ABAJO_X, CENTRO_Y);
                cout << punto;
                locate(ARRIBA_X, CENTRO_Y);
                cout << punto;
                break;
            }


        }

/*void tirarDados(int v[]){
    int i;
    int d;
    for(i=0; i<6; i++){
        cout << "INGRESE UN NUMERO DE DADO: ";
        cin >> d;
        v[i] = d;
        dibujarDado(i+1, v[i]);
    }
}*/

void tirarDados(int v[]) {
    srand(time(0)); // Semilla para la generación de números aleatorios basada en el tiempo actual
    for (int i = 0; i < 6; i++) {
        // Genera un número aleatorio entre 1 y 6 para simular el lanzamiento de un dado
        int valorDado = rand() % 6 + 1;
        v[i] = valorDado;
        dibujarDado(i + 1, v[i]);
    }
}
