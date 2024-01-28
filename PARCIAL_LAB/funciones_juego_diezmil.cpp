#include <iostream>
using namespace std;
#include "rlutil.h"
using namespace rlutil;
#include <ctime>
#include <cstdlib>




/// ACA SE HACEN LAS FUNCIONES DE COMBINACIONES GANADORAS


/// COMBINACION JUEGO DE 1
int puntajeJuegode1(int v[]){  /// aca se verifica si hay 1 o 2 unos
    int i, r=0; /// r SERVIRA PARA CONTAR LOS UNOS
    int p = 0; /// p SERÁ EL PUNTAJE QUE SE DEVOLVERA
    for(i=0; i<6; i++){ /// EN ESTE FOR SE FIJA CUANTOS ELEMENTOS DEL VECTOR TIENEN EL NUMERO 1, Y SI LOS TIENE SE LE SUMA UN 1 AL CONTADOR r.
        if(v[i] == 1){
            r++;
        }
      }
    if(r == 1 || r == 2){ /// ACA SE PREGUNTA SI r ES IGUAL A 1 Ó r ES IGUAL A 2, SI ES VERDADERO ALGUNO DE LOS DOS, ENTONCES r*100, PORQUE r SERIA LOS DADOS QUE TIENEN EL NUMERO 1.
            p = r*100;

    }
    return p;
}

/// FUNCION COMBINACION JUEGO DE 5
int puntajeJuegode5(int v[]){  /// aca se verifica si hay 1 o 2 cincos
    int i, r=0; /// r SERVIRA PARA VERIFICAR CUANTOS CINCOS HAY EN LOS ELEMENTOS DEL VECTOR
    int p = 0; /// p ES LOS PUNTOS QUE SE DEVOLVERÁ
    for(i=0; i<6; i++){
        if(v[i] == 5){ /// SE FIJA CUANTOS ELEMENTOS CONTIENEN EL NUMERO 5. SI ES VERDADERO ENTONCES SE SUMA 1 AL CONTADOR r.
            r++;
        }
      }
    if(r == 1 || r == 2){ /// SE PREGUNTA SI r ES IGUAL A 1 Ó 2, SI ES VERDAERO ENTONCES r*50. YA QUE SE DABA 50 PUNTOS POR CADA DADO CON EL VALOR 5.
            p = r*50;

    }
    return p;
}

/// FUNCION COMBINACION JUEGO DE TRIO
int puntajeJuegoTrio(int v[]){ /// ACA SE FIJA SI HAY 3 DADOS CON EL VALOR 1.
int i, r=0; /// r SERVIRÁ PARA CONTAR CUANTOS UNOS HAY.
int p = 0; /// p SERÁ EL PUNTAJE QUE SE DEVOLVERA
    for(i=0; i<6; i++){
        if(v[i] == 1){ /// SE PREGUNTA SI EL VECTOR EN LA POSICION i ES IGUAL A 1, SI ES VERDADERO SE LE SUMA 1 AL CONTADOR r.
            r++;
            }
    }
    if(r==3){ /// ACA SE PREGUNTA SI r ES IGUAL A 3, ES DECIR, SI HAY 3 DADOS CON EL VALOR 1. SI ES VERDADERO SE LE ASIGNA A p 1000.
        p=1000;
    }
    return p;
}
/// FUNCION COMBINACION JUEGO DE TRIO "X"
int puntajeJuegoTrioX(int v[]){ /// ACA SE FIJA SI ENTRE LOS 6 DADOS, HAY 3 DADOS QUE TIENEN EL MISMO VALOR.
    int i, r = 0, p = 0, pm = 0; /// r CONTARÁ CUANTOS REPETIDOR HAY DE DICHO NUMERO EN VECTOR POSICION i. p SERÁ LOS PUNTOS QUE DÁ EL TRIO, PERO NO ES LO QUE DEVOLVERA EN ESTE CASO. Y PM VERIFICA CUAL ES EL TRIO DE MAYOR VALOR. ES DECIR, SI HAY DOS TRIOS(3,3,3,6,6,6) DEVOLVERA EL PUNTAJE DEL TRIO 6,6,6 YA QUE DAN MAYOR PUNTAJE QUE EL OTRO TRIO.
    for(i=0; i<6; i++){
        for(int j=0; j<6; j++){
            if(v[i]==v[j]){
                r++;
            }
        }
        if(r==3){ /// ACA SE VERIFICA SI r ES IGUAL A 3, ES DECIR, SI HAY 3 DADOS CON EL MISMO VALOR
            p = v[i] * 100; /// SI ES VERDADERO ENTONCES SE LE ASIGNA A p EL VALOR DEL DADO * 100.
        }
        if(p>pm){ /// ESTE if SIRVE PARA VERIFICAR EN CASO DE QUE HAYA DOS TRIOS, CUAL ES EL QUE DÁ MAS PUNTOS. LA PRIMERA VEZ SIEMPRE SERÁ VERDADERA SI HAY UN TRIO.
            pm = p;
        }
        p = 0; /// SE LE ASIGNA A p EL VALOR DE 0 PARA VERIFICAR EL OTRO TRIO SI HAY OTRO, SINO NO HARÁ NADA, NO MODIFICARA EN NADA.
        r = 0; /// SE LE ASIGNA A r EL VALOR 0 PARA VERIFICAR LOS OTROS NUMEROS.
    }
    return pm; /// LO QUE SE DEVUELVE, EL PUNTAJE.

}

/// FUNCION COMBINACION JUEGO DE TRIO XM, LE PUSE ESTE NOMBRE PARA DIFERENCIARLO DE LOS OTROS, ES EL TRIO X++.
int puntajeJuegoTrioXM(int v[]){
    int i, r = 0, p = 0; ///r SERVIRA PARA VERIFICAR CUANTOS NUMEROS REPETIDOS HAY DEL VECTOR EN POSICION i. p SERÁ LOS PUNTOS QUE DEVOLVERA.
    for(i=0; i<6; i++){
        if(v[i]!=1){ /// ACA SE FIJA SI EL NUMERO QUE ESTA EN EL ELEMENTO DEL VECTOR EN POSICION i ES DISTINTO DE 1. SI ES VERDAD, SE VERIFICARÁ CUANTOS DE ESE NUMERO HAY EN EL VECTOR.
        for(int j=0; j<6; j++){
            if(v[i]==v[j]){
                r++;
                }

            }
            if(r==4 || r==5){ /// SE PREGUNTA ACA SI r ES IGUAL A 4 Ó 5. SI ES VERDADERO, ENTONCES EL NUMERO QUE ESTÁ EN ESA POSICION QUE SERIA EL VALOR DEL DADO * 200.
                p = v[i] * 200;
            }
            r=0; /// SE LE ASIGNA A r EL VALOR 0 PARA VOLVER A VERIFICAR LOS DEMAS ELEMENTOS DEL VECTOR
}
    }
    return p;
}

/// FUNCION COMBINACION JUEGO TRIO AMPLIADO
int puntajeJuegoTrioampliado(int v[]){
    int i, r = 0, p = 0; /// r SIRVE PARA CONTAR LOS UNOS QUE HAY, Y p ES EL PUNTAJE QUE SE DEVOLERA.
    for(i=0; i<6; i++){
        if(v[i]==1){ /// ACA SE VERIFICA SI EL VECTOR EN POSICION i ES IGUAL A 1, SI ES ASI SE LE SUMA 1 AL CONTADOR r
           r++;
        }
    }
    if(r==4 || r==5){ ///ACA SE PREGUNTA SI r ES IGUAL A 4 Ó 5, SI ES VERDADERO SE LE ASIGNA A p 2000.
        p=2000;
    }
    return p;
}

///FUNCION COMBINACION JUEGO DE TRES PARES
int puntajeJuegoTresPares(int v[]){
    int i, r=0, p=0, pares=0; /// r SERVIRA PARA CONTAR CUANTOS NUMEROS REPETIDOS HAY. p SERÁ EL PUNTAJE QUE SE DEVOLVERA. pares SERVIRA PARA CONTAR CUANTOS NUMEROS REPETIDOS HAY TAMBIEN. ES DECIR, SI HAY 3 PARES, pares TENDRÁ 6.
    for(i=0; i<6; i++){
        for(int j=0; j<6; j++){
            if(v[i]==v[j]){ /// ACA VERIFICA SI LOS EL VECTOR EN LA POSICION i ES IGUAL AL VECTOR EN LA POSICION j. SI SON IGUALES SE LE SUMA UNO AL CONTADOR r.
                r++;
            }
        }
        if(r==2 || r==4 || r==6){ /// ACA SE PREGUNTA SI LOS r ES IGUAL A 2, 4 o 6, SI ES VERDADERO ENTONCES pares++.
            pares++;
        }
        r=0; /// A r SE LE ASIGNA EL VALOR 0 PARA PODER VERIFICAR EL PROXIMO NUMERO.
    }
    if(pares==6){ /// AL FINAL DEL FOR ESTE SE PREGUNTA SI pares ES IGUAL A 6, SI ES VERDADERO ENTONCES A p SE LE ASIGNA 1000.
        p=1000;
    }

    return p;
}

///FUNCION COMBINACION JUEGO ESCALERA LARGA
int puntajeJuegoEscaleraLarga(int v[]){
    int i, r = 0, tr = 0, p = 0; /// r SERVIRA PARA CONTAR LOS NUMEROS REPETIDOS. tr SERVIRA PARA VERIFICAR CUANTOS NUMEROS NO TIENEN VALORES REPETIDOS,ES DECIR, SI SON LOS UNICOS. p SERÁ LO QUE SE DEVOLVERA.
    for(i=1; i<7; i++){
        for(int j=0; j<6; j++){
            if(v[j]==i){ /// ACA SE PREGUNTA SI VECTOR EN LA POSICION j ES IGUAL A i. ESTE SIRVE PARA VER CUANTOS NUMEROS IGUALES HAY EN EL VECTOR, DEL 1 AL 6.
                r++;
            }
        }
        if(r==1){ /// SI r ES IGUAL A 1 ES PORQUE i NO TIENE NUMEROS REPETIDOS. SOLO TIENE 1.
            tr++;
        }
        r=0; /// SE LE ASIGNA A r EL VALOR 0 PARA VERIFICAR LOS OTROS NUMEROS.
    }
    if(tr==6){ /// ACA SE PREGUNTA SI tr ES IGUAL A 6, PORQUE SI EN TOTAL ES 6, ES QUE NINGUN ELEMENTO DEL VECTOR TIENE LOS MISMOS VALORES. CON LO CUAL SERIA ESCALERA.
        p=1500;
    }
    return p;
}

///FUNCION JUEGO SEXTETO
int puntajeJuegoSexteto(int v[], int puntaje){ /// A DIFERENCIA DE LOS DEMAS, ESTA FUNCION RECIBE UN VECTOR Y LA VARIABLE QUE SERIA EL PUNTAJE QUE TIENE EL JUGADOR HASTA EL MOMENTO.
    int i, j, r=0, p=0; /// u SERIAN LOS UNOS QUE HAY, Y p SERIA LO QUE SE DEVUELVE.
    for(i=0; i<6; i++){
      for(j=0; j<6; j++){
            if(v[i] == v[j]){
                r++;
            }

      }
       if(r==6){
        p=10000-puntaje;
        return p;
       }

    r=0;
    }
    return p;
}
