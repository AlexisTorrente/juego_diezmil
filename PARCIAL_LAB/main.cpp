#include <iostream>
using namespace std;
#include <cstdlib>
#include "rlutil.h"
#include <ctime>
#include <cstring>
#include "funciones_juego.h"
using namespace rlutil;
const char *UI_VERTICAL_LINE = "\xB3"; // 179 - │
char jugador1[25]; /// ACA SE ALMACENA EL NOMBRE DEL PRIMER JUGADOR
char jugador2[25]; // ACA SE ALMACENA EL NOMBRE DEL SEGUNDO JUGADOR
char jugador3[1][25]; /// ACA SE ALMACENA EL JUGADOR POR DEFECTO QUE IRÁ EN EL "HALL OF FAME"
char BP[1][50]; /// BEST PLAYER
int MR = 50; /// MENOR RONDAS
int rondas; /// servira para indicar la cantidad de rondas totales que tardo el jugador para ganar


int main(){
///MAXIMO RECORD POR DEFECTO
strcpy(jugador3[0], "ADMIN");
strcpy(BP[0], jugador3[0]);

/// ACA IRÁ LOS NOMBRES DE LAS JUGADAS, PARA INDICAR AL JUGADOR QUE JUGADA GANADORA DE MAYOR PUNTAJE HIZO.
char palabras[10][35];
strcpy(palabras[0], "OBTUVISTE UN JUEGO DE 1");
strcpy(palabras[1], "OBTUVISTE UN JUEGO DE 5");
strcpy(palabras[2], "OBTUVISTE UN TRIO DE 1");
strcpy(palabras[3], "OBTUVISTE UN TRIO");
strcpy(palabras[4], "OBTUVISTE UN TRIO");
strcpy(palabras[5], "OBTUVISTE UN TRIO AMPLIADO");
strcpy(palabras[6], "OBTUVISTE TRES PARES");
strcpy(palabras[7], "OBTUVISTE UNA ESCALERA LARGA");
strcpy(palabras[8], "OBTUVISTE UN SEXTETO");
strcpy(palabras[9], "NO HIZO NINGUNA COMBINACION");
srand(time(NULL));
hidecursor();
int opc; ///opcion a elegir (modo 1 jugador, 2 jugador, maximo record o salir del juego)
int p = 0; /// puntaje que se le asignara segun la combinacion ganadora
int mj = 0; /// mejor jugada, es decir, la combinacion con mas puntos en esa ronda
int dados[6]; /// los dados
int puntaje = 0; ///el puntaje que se irá sumando mediante la partida
int puntajej1 = 0; // PUNTAJE PARA EL JUGADOR 1 EN MODO DOS JUGADORES
int puntajej2 = 0; // PUNTAJE PARA EL JUGADOR 2 EN MODO DOS JUGADORES
int elegir; /// sirve para elegir si lanzar de nuevoe el dado o no
int C1=1; /// condicion 1, para verificar si el jugador que tuvo puntos desea tirar otra vez
int C2=0; /// complemento de la condicion 2, si decida tirar otra vez, entonces esta condicion modificara la C1
bool tirar = true; ///es una condicion auxiliar para tirar o no. Durante el programa  no se modifica.

/// TODAS LAS COMBINACIONES GANADORAS. SE LES ASIGNA UN ESPACIO EN EL VECTOR DE COMBINACIONES GANADORAS. COMO SON SOLO 9 COMBINACIONES GANADORAS, SERA UN VECTOR DE 9 ELEMENTOS
int CombinacionesGanadoras[9];
CombinacionesGanadoras[0] = puntajeJuegode1(dados);
CombinacionesGanadoras[1] = puntajeJuegode5(dados);
CombinacionesGanadoras[2] = puntajeJuegoTrio(dados);
CombinacionesGanadoras[3] = puntajeJuegoTrioX(dados);
CombinacionesGanadoras[4] = puntajeJuegoTrioXM(dados);
CombinacionesGanadoras[5] = puntajeJuegoTrioampliado(dados);
CombinacionesGanadoras[6] = puntajeJuegoTresPares(dados);
CombinacionesGanadoras[7] = puntajeJuegoEscaleraLarga(dados);
CombinacionesGanadoras[8] = puntajeJuegoSexteto(dados, puntaje);
int ronda = 1; /// LA RONDA
int lanzamiento = 1; /// LANZAMIENTO
bool infinito = true; ///SIRVE PARA QUE SE REPITA UNA Y OTRA VEZ HASTA QUE SE SELECCIONE LA OPC 4.

    setBackgroundColor(MAGENTA);
    cls();
    setColor(WHITE);
    /// PRESENTACION DEL JUEGO
    cout << "--------------------------------[ DIEZ MIL ]------------------------------------" <<endl;
    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl<< endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
    cout << "--------------------------------[BIENVENIDO]------------------------------------"  << endl << endl;
    cout << "Presione una tecla para continuar..." << endl << endl;
    cout << "HECHO POR: ALEXIS TORRENTE";
    locate(1,28);
    cout << "Version 1.0.0" << endl;
    locate(1,29);
    cout << "Copyright c 2020 Universidad Tecnologica Nacional";
    anykey();
    ///EL DO-WHILE INFINITO
    do{
       ///DO-WHILE DEL MENU DE JUEGO
       do{
                system("cls");
                locate(10, 2);
                cout << "POR FAVOR, SELECCIONE UNA OPCION: ";
                cout << endl << endl;
                locate(10, 4);
                cout << "1. MODO UN JUGADOR" << endl; ///MODO UN JUGADOR(COMPLETO)
                locate(10, 6);
                cout << "2. MODO DOS JUGADORES" << endl; /// MODO DOS JUGADORES(COMPLETO)
                locate(10, 8);
                cout << "3. MAXIMO PUNTAJE" << endl; /// MAXIMO PUNTAJE(COMPLETO)
                locate(10, 10);
                cout << "4. SALIR DEL JUEGO" << endl << endl; /// SALIR DEL JUEGO(COMPLETO)
                cout << "OPCION A ESCOGER: ";
                cin >> opc;
                switch(opc){

                    case 1:
                            system("cls");
                            cout << "INGRESE SU NOMBRE: "; /// MENSAJE PIDIENDO EL NOMBRE DEL JUGADOR
                            cin.ignore();
                            cin.getline(jugador1, 25); /// ACA SE ESCRIBE EL NUMERO DEL JUGADOR
                            system("cls");
                            cout << "BIENVENIDO " << jugador1 << endl << endl; ///BIENVENIDA
                            cout << "PARA GANAR DEBERAS LLEGAR A 10000 PUNTOS, NI MAS, NI MENOS. ASI QUE PIENSA BIEN TUS JUGADAS!" << endl << endl; /// REGLA SUPER RESUMIDA
                            system("pause");
                            system("cls");
                            puntaje = 0;
                            ronda = 1;
                            /// ENTRE RONDAS PRINCIPAL, SOLO SE MUESTRA LA PRIMERA VEZ AL INICIAR LA PARTIDA
                                cout << "--------------------------------------------------------------------------------" << endl;
                                cout << "                       RONDA N: " << ronda << endl;
                                cout << "                       PROXIMO TURNO: " << jugador1 << endl;
                                cout << "                       PUNTAJE " << jugador1 << " : " << puntaje << "  PUNTOS" << endl;
                                cout << "--------------------------------------------------------------------------------";
                                cout << endl << endl;
                                system("pause");
                                system("cls");

                                ///ESTE WHILE VERIFICA QUE SE HARÁ TODO LO QUE ESTA ADENTRO, SIEMPRE Y CUANDO EL PUNTAJE SEA DISTINTO DE 10000
                            while(puntaje!=10000){
                             /// SE HACE ESTO POR PRIMERA VEZ PARA LUEGO PREGUNTAR SI DESEA TIRAR NUEVAMENTE. POR ESO ES UN DO-WHILE
                            do{
                                ///ACA SE VERIFICA LA CONDICION QUE MENCIONE AL PRINCIPIO. EN CASO DE DAR VERDADERO SE MODIFICA LA C1.
                                if(C2==1){
                                   C1=2;
                                }
                                int pm = 0; /// ESTA VARIABLE SIRVE PARA VERIFICAR EL PUNTAJE MAXIMO ENTRE LAS COMBINACIONES. SI EN UNA RONDA HAY 2 COMBINACIONES, QUE DA 500 PUNTOS UNA, Y 1000 OTRA, ESTA VARIABLE SERVIRA PARA ESCOGER LA DE MAYOR PUNTAJE, QUE EN ESTE CASO SERIA 1000.
                                /// LA PANTALLA QUE SE MOSTRARA MEDIANTE EL JUEGO, SERVIRA PARA INFORMAR AL JUGADOR DE LA RONDA QUE ESTA, LOS PUNTOS QUE TIENE Y EL NUMERO DEL LANZAMIENTO.
                                cout << "JUGADOR: " << jugador1 << endl;
                                cout << "--------------------------------------------------------------------------------" << endl;
                                cout << "                       RONDA: " << ronda << endl;
                                cout << "                       LANZAMIENTO: " << lanzamiento << endl;
                                cout << "                       PUNTOS: " << puntaje << endl;
                                cout << "--------------------------------------------------------------------------------" << endl;
                                cout << "PRESIONE ALGUNA TECLA PARA TIRAR" << endl;
                                system("pause");
                                tirarDados(dados); /// LO QUE HACE ESTA FUNCION ES QUE LLENA LOS ELEMENTOS DEL VECTOR DADOS CON NUMEROS "ALEATORIOS" Y LUEGO LOS DIBUJA.
                                cout << endl;
                                ///ACA TODAS LAS COMBINACIONES GANADORAS RECIBEN EL VECTOR DADOS PARA HACER SU RESPECTIVA FUNCION. EXCEPTO LA ULTIMA COMBINACION GANADORA, QUE RECIBE APARTE EL PUNTAJE.
                                CombinacionesGanadoras[0] = puntajeJuegode1(dados);
                                CombinacionesGanadoras[1] = puntajeJuegode5(dados);
                                CombinacionesGanadoras[2] = puntajeJuegoTrio(dados);
                                CombinacionesGanadoras[3] = puntajeJuegoTrioX(dados);
                                CombinacionesGanadoras[4] = puntajeJuegoTrioXM(dados);
                                CombinacionesGanadoras[5] = puntajeJuegoTrioampliado(dados);
                                CombinacionesGanadoras[6] = puntajeJuegoTresPares(dados);
                                CombinacionesGanadoras[7] = puntajeJuegoEscaleraLarga(dados);
                                CombinacionesGanadoras[8] = puntajeJuegoSexteto(dados, puntaje);
                                /// EL SIGUIENTE FOR SIRVE PARA VERIFICAR CUAL COMBINACION GANADORA DÁ MÁS PUNTOS SEGUN LOS VALORES DE LOS DADOS.
                                for(int i=0; i<9; i++){
                                    p = CombinacionesGanadoras[i]; /// ACA SE LE ASIGNA EL VALOR QUE RETORNA DICHA FUNCION A p.
                                    if(p>pm){ /// ACA SE PREGUNTA SI p ES MAYOR A pm.
                                        pm = p; /// pm SERIA PUNTAJE MAXIMO, ES DECIR, LA COMBINACION QUE MÁS PUNTAJE DÁ CON RESPECTO A LOS DADOS.
                                        mj = i; /// mj SIRVE PARA INDICAR LA MEJOR JUGADA. ESTO AYUDARÁ A MANDAR EL MENSAJE CORRESPONDIENTE DE LA MEJOR JUGADA.
                                    }
                                }
                                /// ESE if SIRVE PARA VER SI CON LOS DADOS NO SE PUDO HACER NINGUNA COMBINACION GANADORA. SI NO SE PUDO DARÁ EL MENSAJE DE QUE NO HUBO NINGUNA COMBINACION GANADORA.
                                if(pm==0){
                                    mj = 9;
                                }
                                locate(1, 17);
                                cout << palabras[mj] << " +" << pm << " PUNTOS" << endl; /// LE INFORMA AL JUGADOR LOS PUNTOS QUE GANO EN ESE LANZAMIENTO Y QUE NOMBRE DE JUGADA ES.
                                locate(0, 25);
                                system("pause");
                                /// ACA SE PREGUNTA SI LA C1 ES IGUAL A 1. ESTO PARA VER SI ES EL PRIMER LANZAMIENTO, O SI EL JUGADOR DESPUES DE UN LANZAMIENTO CON COMBINACION GANADORA DECIDIO HACER OTRO LANZAMIENTO.
                                if(C1==1){
                                if(pm>0){ /// SE PREGUNTA SI TUVO UN PUNTAJE MAYOR A 0, SI ES VERDAD SE HACE LO QUE CORRESPONDE, SINO, SE HARÁ OTRO LANZAMIENTO SIN NINGUNA CONSECUENCIA NI NADA.
                                cout << "QUIERE VOLVER A TIRAR?" << endl;
                                cout << "1 - SI" << endl;
                                cout << "CUALQUIER NUMERO DECIMAL(MENOS EL 1) - NO" << endl;
                                cin >> elegir;
                                if(elegir==1){ /// SI ELIGE VOLVER A TIRAR CUANDO TIENE PUNTAJE CORRESPONDIENTE A UNA COMBINACION GANADORA, ENTONCES LA C2 SE LE SUMA 1, CON LO CUAL CUANDO VUELVA A RECORRER EL DO-WHILE MODIFICARA LA C1 Y POR ENDE NO PODRÁ HACER MAS LANZAMIENTO EN ESA RONDA.
                                    C2++;
                                    lanzamiento++;
                                    pm=0; /// PM SE IGUALA A 0 PARA VOLVER A VERIFICAR EN EL SIGUIENTE LANZAMIENTO.
                                }if(elegir!=1){ /// SI DECIDE NO VOLVER A TIRAR, SE LE ASIGNARA LOS PUNTOS OBTENIDOS EN ESTA RONDA AL PUNTAJE TOTAL.
                                    C1=2;/// Y ACA SE MODIFICA DIRECTAMENTE LA C1 PARA QUE NO HAGA OTRO LANZAMIENTO Y PASE A LA PROXIMA RONDA
                                    puntaje+=pm; /// SE LE ASIGNA A PUNTAJE EL VALOR DE pm.
                                }
                            }
                        }else{ /// ESTO SIRVE PARA QUE EN EL SIGUIENTE LANZAMIENTO TRAS HABER ELEGIDO LANZAR DE NUEVO, SE LE ASIGNE LOS PUNTOS.
                            puntaje+=pm;
                        }
                            if(puntaje > 10000){ /// SE PREGUNTA SI SUMANDO LOS PUNTOS QUE TUVO EN LA RONDA AL PUNTAJE TOTAL SUPERAN LOS 10000 REQUERIDOS, SI LOS SUPERA, ENTONCES TENDRÁ LOS PUNTOS CON LOS QUE EMPEZO.
                                puntaje=puntaje-pm;
                            }

                            system("cls");
                            }while(tirar=true && C1<2); /// ACA LA CONDICION QUE IMPORTA ES C1, LA DE tirar ES AUXILIAR QUE USE PARA ORIENTARME MEJOR.
                            ronda++; /// CUANDO SALE DEL DO-WHILE SUMA LA RONDA, ES DECIR, LO PREPARA PARA LA SIGUIENTE RONDA.
                            lanzamiento=1; /// LANZAMIENTO SE LE ASIGNA EL VALOR 1, YA QUE SERÁ EL LANZAMIENTO NUMERO 1 DE LA SIGUIENTE RONDA-
                            /// ACA SE ASIGNA EL VALOR A LOS CONDICIONANTES COMO ESTABAN AL INICIO PARA PODER REPETIR EL PROCEDIMIENTO.
                            C1=1;
                            C2=0;
                            /// SI EL PUNTAJE QUE SE OBTUVO ES MENOR A 10000, SE MOSTRARA POR PANTALLA LA DE "ENTRE TURNOS", INFORMANDO AL JUGADOR RONDA SIGUIENTE, DE QUIEN ES EL PROXIMO TURNO Y EL PUNTAJE QUE TIENE HASTA EL MOMENTO. CUANDO EL JUGADOR OBTIENE 10000 ESTA OPCION SE OMITE PARA QUE SE VEA MÁS ESTETICO.
                            if(puntaje<10000){
                                cout << "--------------------------------------------------------------------------------" << endl;
                                cout << "                       RONDA N: " << ronda << endl;
                                cout << "                       PROXIMO TURNO: " << jugador1 << endl;
                                cout << "                       PUNTAJE " << jugador1 << " : " << puntaje << "  PUNTOS" << endl;
                                cout << "--------------------------------------------------------------------------------";
                                cout << endl << endl;
                                system("pause");
                                system("cls");
                                }
                             /// SI EL PUNTAJE ES !=10000 ENTONCES SE VOLVERÁ A HACER LO MISMO, HASTA QUE OBTENGA LOS 10000, NI MÁS NI MENOS.
                            }
                            rondas = ronda-1; ///indica en cuantas rondas totales gano, SE LE RESTA 1 A ronda PARA QUE SEA LA RONDA EXACTA EN LA CUAL GANO.
                            /// MENSAJE DE FELICITACION POR HABER GANADO LA PARTIDA.
                            system("cls");
                            locate(1,10);
                            cout << ".-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-" << endl << endl;
                            cout << "FELICIDADES " << jugador1 << " HAS GANADO CON " << rondas << " RONDAS" << endl << endl;
                            cout << "-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.";
                            system("pause");
                            system("cls");
                            /// LO QUE HACE LO SIGUIENTE ES VER SI HA ROTO EL RECORD DE ACABAR LA PARTIDA EN LA MENOR CANTIDAD DE RONDAS POSIBLES, SI LO HA ROTO, SE LE ASIGANARA EN "MAXIMOS PUNTAJES" EL NOMBRE DEL JUGADOR Y EN CUANTAS RONDAS GANO LA PARTIDA.
                            if(rondas<MR){
                                MR=rondas;
                                locate(1,10);
                                cout << "-----.-----.-----.-----.-----.-----.-----.-----.-----.-----.-----.-----.-----.--" << endl << endl;
                                cout << "FELICIDADES, HAS ROTO EL RECORD DE: " << BP[0] << endl << endl;
                                cout << "-----.-----.-----.-----.-----.-----.-----.-----.-----.-----.-----.-----.-----.--" << endl;
                                cout << "ACASO USAS HACKS?!" << endl << endl;
                                strcpy(BP[0], jugador1);
                                cout << endl;
                                system("pause");
                            }
                            system("cls");
                            break;


                    case 2: ///MODO DOS JUGADORES
                            puntajej1 = 0; ///PUNTAJE DEL JUGADOR 1
                            puntajej2 = 0; ///PUNTAJE DEL JUGADOR 2
                            system("cls");
                            cout << "INGRESE EL NOMBRE DEL PRIMER JUGADOR: "; // MENSAJE PIDIENDO EL NOMBRE DEL JUGADOR
                            cin.ignore();
                            cin.getline(jugador1, 25); // ACA SE ESCRIBE EL NOMBRE DEL JUGADOR
                            system("cls");
                            cout << "INGRESE EL NOMBRE DEL SEGUNDO JUGADOR: "; // MENSAJE PIDIENDO EL NOMBRE DEL JUGADOR
                            cin.getline(jugador2, 25); // ACA SE ESCRIBE EL NOMBRE DEL JUGADOR
                            system("cls");
                            cout << "BIENVENIDOS " << jugador1 << " Y " << jugador2 << endl << endl; //BIENVENIDA
                            cout << "PARA GANAR ALGUNO DE LOS DOS DEBE LLEGAR A 10000 PUNTOS, NI MAS, NI MENOS. ASI QUE PIENSEN BIEN SUS JUGADAS!" << endl << endl; /// REGLA SUPER RESUMIDA
                            system("pause");
                            system("cls");
                            ronda = 1; ///RONDA
                            ///EL SIGUIENTE WHILE SERÁ VERDADERO MIENTRAS EL PUNTAJE DEL J1 Y J2 SEAN DISTINTOS DE 10000, ES DECIR, CUANDO UNO CONSIGA 10000 SE SALE DEL WHILE
                            while(puntajej1 != 10000 && puntajej2 != 10000){
                                cout << "--------------------------------------------------------------------------------" << endl;
                                cout << "                 RONDA N: " << ronda << endl;
                                cout << "                 PROXIMO TURNO: " << jugador1 << endl;
                                cout << "                 PUNTAJE " << jugador1 << " : " << puntajej1 << "  PUNTOS" << endl;
                                cout << "                 PUNTAJE " << jugador2 << " : " << puntajej2 << "  PUNTOS" << endl;
                                cout << "--------------------------------------------------------------------------------";
                                cout << endl << endl;
                                system("pause");
                                system("cls");
                                do{
                                    ///ACA SE VERIFICA LA CONDICION QUE MENCIONE AL PRINCIPIO. EN CASO DE DAR VERDADERO SE MODIFICA LA C1.
                                if(C2==1){
                                   C1=2;
                                }
                                int pm = 0; /// ESTA VARIABLE SIRVE PARA VERIFICAR EL PUNTAJE MAXIMO ENTRE LAS COMBINACIONES. SI EN UNA RONDA HAY 2 COMBINACIONES, QUE DA 500 PUNTOS UNA, Y 1000 OTRA, ESTA VARIABLE SERVIRA PARA ESCOGER LA DE MAYOR PUNTAJE, QUE EN ESTE CASO SERIA 1000.
                                /// LA PANTALLA QUE SE MOSTRARA MEDIANTE EL JUEGO, SERVIRA PARA INFORMAR AL JUGADOR DE LA RONDA QUE ESTA, LOS PUNTOS QUE TIENE Y EL NUMERO DEL LANZAMIENTO.
                                cout << "JUGADOR: " << jugador1 << endl;
                                cout << "--------------------------------------------------------------------------------" << endl;
                                cout << "RONDA: " << ronda << endl;
                                cout << "LANZAMIENTO: " << lanzamiento << endl;
                                cout << "PUNTOS: " << puntajej1 << endl;
                                cout << "--------------------------------------------------------------------------------" << endl;
                                cout << "PRESIONE ALGUNA TECLA PARA TIRAR" << endl;
                                system("pause");
                                tirarDados(dados); /// LO QUE HACE ESTA FUNCION ES QUE LLENA LOS ELEMENTOS DEL VECTOR DADOS CON NUMEROS "ALEATORIOS" Y LUEGO LOS DIBUJA.
                                cout << endl;
                                ///ACA TODAS LAS COMBINACIONES GANADORAS RECIBEN EL VECTOR DADOS PARA HACER SU RESPECTIVA FUNCION. EXCEPTO LA ULTIMA COMBINACION GANADORA, QUE RECIBE APARTE EL PUNTAJE.
                                CombinacionesGanadoras[0] = puntajeJuegode1(dados);
                                CombinacionesGanadoras[1] = puntajeJuegode5(dados);
                                CombinacionesGanadoras[2] = puntajeJuegoTrio(dados);
                                CombinacionesGanadoras[3] = puntajeJuegoTrioX(dados);
                                CombinacionesGanadoras[4] = puntajeJuegoTrioXM(dados);
                                CombinacionesGanadoras[5] = puntajeJuegoTrioampliado(dados);
                                CombinacionesGanadoras[6] = puntajeJuegoTresPares(dados);
                                CombinacionesGanadoras[7] = puntajeJuegoEscaleraLarga(dados);
                                CombinacionesGanadoras[8] = puntajeJuegoSexteto(dados, puntajej1);
                                /// EL SIGUIENTE FOR SIRVE PARA VERIFICAR CUAL COMBINACION GANADORA DÁ MÁS PUNTOS SEGUN LOS VALORES DE LOS DADOS.
                                for(int i=0; i<9; i++){
                                    p = CombinacionesGanadoras[i]; /// ACA SE LE ASIGNA EL VALOR QUE RETORNA DICHA FUNCION A p.
                                    if(p>pm){ /// ACA SE PREGUNTA SI p ES MAYOR A pm.
                                        pm = p; /// pm SERIA PUNTAJE MAXIMO, ES DECIR, LA COMBINACION QUE MÁS PUNTAJE DÁ CON RESPECTO A LOS DADOS.
                                        mj = i; /// mj SIRVE PARA INDICAR LA MEJOR JUGADA. ESTO AYUDARÁ A MANDAR EL MENSAJE CORRESPONDIENTE DE LA MEJOR JUGADA.
                                    }
                                }
                                /// ESE if SIRVE PARA VER SI CON LOS DADOS NO SE PUDO HACER NINGUNA COMBINACION GANADORA. SI NO SE PUDO DARÁ EL MENSAJE DE QUE NO HUBO NINGUNA COMBINACION GANADORA.
                                if(pm==0){
                                    mj = 9;
                                }
                                locate(1, 17);
                                cout << palabras[mj] << " +" << pm << " PUNTOS" << endl; /// LE INFORMA AL JUGADOR LOS PUNTOS QUE GANO EN ESE LANZAMIENTO Y QUE NOMBRE DE JUGADA ES.
                                locate(0, 25);
                                system("pause");
                                /// ACA SE PREGUNTA SI LA C1 ES IGUAL A 1. ESTO PARA VER SI ES EL PRIMER LANZAMIENTO, O SI EL JUGADOR DESPUES DE UN LANZAMIENTO CON COMBINACION GANADORA DECIDIO HACER OTRO LANZAMIENTO.
                                if(C1==1){
                                if(pm>0){ /// SE PREGUNTA SI TUVO UN PUNTAJE MAYOR A 0, SI ES VERDAD SE HACE LO QUE CORRESPONDE, SINO, SE HARÁ OTRO LANZAMIENTO SIN NINGUNA CONSECUENCIA NI NADA.
                                cout << "QUIERE VOLVER A TIRAR?" << endl;
                                cout << "1 - SI" << endl;
                                cout << "CUALQUIER NUMERO DECIMAL(MENOS EL 1) - NO" << endl;
                                cin >> elegir;
                                if(elegir==1){ /// SI ELIGE VOLVER A TIRAR CUANDO TIENE PUNTAJE CORRESPONDIENTE A UNA COMBINACION GANADORA, ENTONCES LA C2 SE LE SUMA 1, CON LO CUAL CUANDO VUELVA A RECORRER EL DO-WHILE MODIFICARA LA C1 Y POR ENDE NO PODRÁ HACER MAS LANZAMIENTO EN ESA RONDA.
                                    C2++;
                                    lanzamiento++;
                                    pm=0; /// PM SE IGUALA A 0 PARA VOLVER A VERIFICAR EN EL SIGUIENTE LANZAMIENTO.
                                }if(elegir!=1){ /// SI DECIDE NO VOLVER A TIRAR, SE LE ASIGNARA LOS PUNTOS OBTENIDOS EN ESTA RONDA AL PUNTAJE TOTAL.
                                    C1=2;/// Y ACA SE MODIFICA DIRECTAMENTE LA C1 PARA QUE NO HAGA OTRO LANZAMIENTO Y PASE A LA PROXIMA RONDA
                                    puntajej1+=pm; /// SE LE ASIGNA A PUNTAJE DEL JUGADOR 1 EL VALOR DE pm.
                                }
                            }
                        }else{ /// ESTO SIRVE PARA QUE EN EL SIGUIENTE LANZAMIENTO TRAS HABER ELEGIDO LANZAR DE NUEVO, SE LE ASIGNE LOS PUNTOS AL JUGADOR 1.
                            puntajej1+=pm;
                        }
                            if(puntajej1 > 10000){ /// SE PREGUNTA SI SUMANDO LOS PUNTOS QUE TUVO EN LA RONDA AL PUNTAJE TOTAL SUPERAN LOS 10000 REQUERIDOS, SI LOS SUPERA, ENTONCES TENDRÁ LOS PUNTOS CON LOS QUE EMPEZO.
                                puntajej1=puntajej1-pm;
                            }

                            system("cls");
                            }while(tirar=true && C1<2); /// ACA LA CONDICION QUE IMPORTA ES C1, LA DE tirar ES AUXILIAR QUE USE PARA ORIENTARME MEJOR.
                            lanzamiento=1; /// LANZAMIENTO SE LE ASIGNA EL VALOR 1, YA QUE SERÁ EL LANZAMIENTO NUMERO 1 DE LA SIGUIENTE RONDA-
                            /// ACA SE ASIGNA EL VALOR A LOS CONDICIONANTES COMO ESTABAN AL INICIO PARA PODER REPETIR EL PROCEDIMIENTO.
                            C1=1;
                            C2=0;
                            system("cls");
                                cout << "--------------------------------------------------------------------------------";
                                cout << "                       RONDA N: " << ronda << endl;
                                cout << "                 PROXIMO TURNO: " << jugador2 << endl << endl;
                                cout << "      PUNTAJE " << jugador1 << " : " << puntajej1 << "  PUNTOS" << endl;
                                cout << "      PUNTAJE " << jugador2 << " : " << puntajej2 << "  PUNTOS" << endl;
                                cout << "--------------------------------------------------------------------------------";
                                cout << endl << endl;
                                system("pause");
                                system("cls");
                            do{
                                    ///ACA SE VERIFICA LA CONDICION QUE MENCIONE AL PRINCIPIO. EN CASO DE DAR VERDADERO SE MODIFICA LA C1.
                                if(C2==1){
                                   C1=2;
                                }
                                int pm = 0; /// ESTA VARIABLE SIRVE PARA VERIFICAR EL PUNTAJE MAXIMO ENTRE LAS COMBINACIONES. SI EN UNA RONDA HAY 2 COMBINACIONES, QUE DA 500 PUNTOS UNA, Y 1000 OTRA, ESTA VARIABLE SERVIRA PARA ESCOGER LA DE MAYOR PUNTAJE, QUE EN ESTE CASO SERIA 1000.
                                /// LA PANTALLA QUE SE MOSTRARA MEDIANTE EL JUEGO, SERVIRA PARA INFORMAR AL JUGADOR DE LA RONDA QUE ESTA, LOS PUNTOS QUE TIENE Y EL NUMERO DEL LANZAMIENTO.
                                cout << "JUGADOR: " << jugador2 << endl;
                                cout << "--------------------------------------------------------------------------------" << endl;
                                cout << "RONDA: " << ronda << endl;
                                cout << "LANZAMIENTO: " << lanzamiento << endl;
                                cout << "PUNTOS: " << puntajej2 << endl;
                                cout << "--------------------------------------------------------------------------------";
                                cout << "PRESIONE ALGUNA TECLA PARA TIRAR" << endl;
                                system("pause");
                                tirarDados(dados); /// LO QUE HACE ESTA FUNCION ES QUE LLENA LOS ELEMENTOS DEL VECTOR DADOS CON NUMEROS "ALEATORIOS" Y LUEGO LOS DIBUJA.
                                cout << endl;
                                ///ACA TODAS LAS COMBINACIONES GANADORAS RECIBEN EL VECTOR DADOS PARA HACER SU RESPECTIVA FUNCION. EXCEPTO LA ULTIMA COMBINACION GANADORA, QUE RECIBE APARTE EL PUNTAJE.
                                CombinacionesGanadoras[0] = puntajeJuegode1(dados);
                                CombinacionesGanadoras[1] = puntajeJuegode5(dados);
                                CombinacionesGanadoras[2] = puntajeJuegoTrio(dados);
                                CombinacionesGanadoras[3] = puntajeJuegoTrioX(dados);
                                CombinacionesGanadoras[4] = puntajeJuegoTrioXM(dados);
                                CombinacionesGanadoras[5] = puntajeJuegoTrioampliado(dados);
                                CombinacionesGanadoras[6] = puntajeJuegoTresPares(dados);
                                CombinacionesGanadoras[7] = puntajeJuegoEscaleraLarga(dados);
                                CombinacionesGanadoras[8] = puntajeJuegoSexteto(dados, puntajej2);
                                /// EL SIGUIENTE FOR SIRVE PARA VERIFICAR CUAL COMBINACION GANADORA DÁ MÁS PUNTOS SEGUN LOS VALORES DE LOS DADOS.
                                for(int i=0; i<9; i++){
                                    p = CombinacionesGanadoras[i]; /// ACA SE LE ASIGNA EL VALOR QUE RETORNA DICHA FUNCION A p.
                                    if(p>pm){ /// ACA SE PREGUNTA SI p ES MAYOR A pm.
                                        pm = p; /// pm SERIA PUNTAJE MAXIMO, ES DECIR, LA COMBINACION QUE MÁS PUNTAJE DÁ CON RESPECTO A LOS DADOS.
                                        mj = i; /// mj SIRVE PARA INDICAR LA MEJOR JUGADA. ESTO AYUDARÁ A MANDAR EL MENSAJE CORRESPONDIENTE DE LA MEJOR JUGADA.
                                    }
                                }
                                /// ESE if SIRVE PARA VER SI CON LOS DADOS NO SE PUDO HACER NINGUNA COMBINACION GANADORA. SI NO SE PUDO DARÁ EL MENSAJE DE QUE NO HUBO NINGUNA COMBINACION GANADORA.
                                if(pm==0){
                                    mj = 9;
                                }
                                locate(1, 17);
                                cout << palabras[mj] << " +" << pm << " PUNTOS" << endl; /// LE INFORMA AL JUGADOR LOS PUNTOS QUE GANO EN ESE LANZAMIENTO Y QUE NOMBRE DE JUGADA ES.
                                locate(0, 25);
                                system("pause");
                                /// ACA SE PREGUNTA SI LA C1 ES IGUAL A 1. ESTO PARA VER SI ES EL PRIMER LANZAMIENTO, O SI EL JUGADOR DESPUES DE UN LANZAMIENTO CON COMBINACION GANADORA DECIDIO HACER OTRO LANZAMIENTO.
                                if(C1==1){
                                if(pm>0){ /// SE PREGUNTA SI TUVO UN PUNTAJE MAYOR A 0, SI ES VERDAD SE HACE LO QUE CORRESPONDE, SINO, SE HARÁ OTRO LANZAMIENTO SIN NINGUNA CONSECUENCIA NI NADA.
                                cout << "QUIERE VOLVER A TIRAR?" << endl;
                                cout << "1 - SI" << endl;
                                cout << "CUALQUIER NUMERO DECIMAL(MENOS EL 1) - NO" << endl;
                                cin >> elegir;
                                if(elegir==1){ /// SI ELIGE VOLVER A TIRAR CUANDO TIENE PUNTAJE CORRESPONDIENTE A UNA COMBINACION GANADORA, ENTONCES LA C2 SE LE SUMA 1, CON LO CUAL CUANDO VUELVA A RECORRER EL DO-WHILE MODIFICARA LA C1 Y POR ENDE NO PODRÁ HACER MAS LANZAMIENTO EN ESA RONDA.
                                    C2++;
                                    lanzamiento++;
                                    pm=0; /// PM SE IGUALA A 0 PARA VOLVER A VERIFICAR EN EL SIGUIENTE LANZAMIENTO.
                                }if(elegir!=1){ /// SI DECIDE NO VOLVER A TIRAR, SE LE ASIGNARA LOS PUNTOS OBTENIDOS EN ESTA RONDA AL PUNTAJE TOTAL.
                                    C1=2;/// Y ACA SE MODIFICA DIRECTAMENTE LA C1 PARA QUE NO HAGA OTRO LANZAMIENTO Y PASE A LA PROXIMA RONDA
                                    puntajej2+=pm; /// SE LE ASIGNA A PUNTAJE EL VALOR DE pm.
                                }
                            }
                        }else{ /// ESTO SIRVE PARA QUE EN EL SIGUIENTE LANZAMIENTO TRAS HABER ELEGIDO LANZAR DE NUEVO, SE LE ASIGNE LOS PUNTOS.
                            puntajej2+=pm;
                        }
                            if(puntajej2 > 10000){ /// SE PREGUNTA SI SUMANDO LOS PUNTOS QUE TUVO EN LA RONDA AL PUNTAJE TOTAL SUPERAN LOS 10000 REQUERIDOS, SI LOS SUPERA, ENTONCES TENDRÁ LOS PUNTOS CON LOS QUE EMPEZO.
                                puntajej2=puntajej2-pm;
                            }

                            system("cls");
                            }while(tirar=true && C1<2);
                            /// SE REINICIAN LOS VALORES PARA PODER HACER EL MISMO PROCEDIMIENTO
                            ronda++;
                            C1=1;
                            C2=0;
                            lanzamiento=1;
                                }
                                system("cls");
                                rondas = ronda-1; /// SE CREA OTRA VARIABLE LLAMADA "RONDAS" PARA INDICAR LA RONDA EXACTA EN LA CUAL GANO EL JUGADOR, PARA ESO RONDA - 1.
                               /// POR SI LLEGAN A GANAR AMBOS EN LA MISMA RONDA
                                if(puntajej1==puntajej2){
                                    locate(1,10);
                                    cout << ".-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-" << endl << endl;
                                    cout << "FELICIDADES " << jugador1 << " Y " << jugador2 << " HAN GANADO CON " << rondas << " RONDAS" << endl;
                                    cout << "JUEGUEN OTRA VEZ A VER SI SE ROMPE EL EMPATE!" << endl << endl;
                                    cout << "-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.";
                                    system("pause");
                                    system("cls");
                                }else{
                                    /// SI GANA EL JUGADOR 1
                                    if(puntajej1 > puntajej2){
                                        locate(10, 10);
                                        cout << ".-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-" << endl << endl;
                                        cout << "FELICIDADES " << jugador1 << " HAS GANADO CON " << rondas << " RONDAS" << endl << endl;
                                        cout << "-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-." << endl << endl;
                                        cout << " SUERTE A " << jugador2 << " PARA LA PROXIMA !" << endl << endl;
                                        system("pause");
                                        system("cls");
                                        if(rondas<MR){
                                        MR=rondas;
                                        locate(1,10);
                                        cout << "-----.-----.-----.-----.-----.-----.-----.-----.-----.-----.-----.-----.-----.--" << endl << endl;
                                        cout << "FELICIDADES " << jugador1 << " HAS ROTO EL RECORD DE: " << BP[0] << endl << endl;
                                        cout << "-----.-----.-----.-----.-----.-----.-----.-----.-----.-----.-----.-----.-----.--" << endl;
                                        strcpy(BP[0], jugador1);
                                        cout << endl;
                                        system("pause");
                                        }
                                    }else{ /// SI GANA EL JUGADOR 2
                                        locate(10, 10);
                                        cout << ".-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-" << endl << endl;
                                        cout << "FELICIDADES " << jugador2 << " HAS GANADO CON " << rondas << " RONDAS" << endl << endl;
                                        cout << "-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-." << endl << endl;
                                        cout << " SUERTE A " << jugador1 << " PARA LA PROXIMA !" << endl << endl;
                                        system("pause");
                                        system("cls");
                                        if(rondas<MR){
                                        MR=rondas;
                                        locate(1,10);
                                        cout << "-----.-----.-----.-----.-----.-----.-----.-----.-----.-----.-----.-----.-----.--" << endl << endl;
                                        cout << "FELICIDADES " << jugador2 << " HAS ROTO EL RECORD DE: " << BP[0] << endl << endl;
                                        cout << "-----.-----.-----.-----.-----.-----.-----.-----.-----.-----.-----.-----.-----.--" << endl;
                                        strcpy(BP[0], jugador2);
                                        cout << endl;
                                        system("pause");
                                        }
                                    }
                                }

                            break;

                    case 3: /// APARTADO DE RECORDS, QUIEN GANÓ LA PARTIDA EN LA MENOR CANTIDAD DE RONDAS POSIBLES. PUSE UN RECORD POR DEFECTO PARA METERLE UN RETO FACIL AL JUGADOR.
                            system("cls");
                            cout << "HALL OF FAME" << endl << endl;
                            cout << "JUGADOR: " << BP[0] << endl;
                            cout << "GANO CON: " << MR << " RONDAS" << endl << endl;
                            system("pause");
                            break;

                    case 4: /// ACA ES LA OPCION PARA SALIR DEL JUEGO
                            system("cls");
                            cout << endl << endl << "HASTA LA PROXIMA!" << endl;
                            return 0;
                            break;

                    default:    /// SI NO ELIGE LA OPCION CORRECTA MANDARA UN MENSAJE AL JUGADOR INFORMANDOLE
                                cout << "OPCION INCORRECTA, VUELVA A INTENTARLO" << endl;
                                system("pause");
                                (cls);
                            break;
                }

        } while(opc!=1&&opc!=2&&opc!=3&&opc!=4); /// SIRVE PARA REPETIR LAS VECES QUE SEA NECESARIO HASTA QUE EL JUGADOR SELECCIONE UNA OPCION CORRECTA.

    }while(infinito); /// WHILE INFINITO PARA QUE SE REPITA TODAS LAS VECES HASTA QUE EL JUGADOR DESEÉ SALIR DEL JUEGO MEDIANTE LA OPCION DEL MENU.


}
