#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Función que devuelve el resultado de un dado
int lanzarDado() {
    return (rand() % 6) + 1;
}
//Función que muestra las reglas del juego
void mostrarReglas() {
    printf("Reglas del juego de Craps:\n");
    printf("1. El jugador lanza dos dados de seis caras.\n");
    printf("2. Si la suma de los dados en el primer lanzamiento es 7 u 11, el jugador gana.\n");
    printf("3. Si la suma es 2, 3 o 12, el jugador pierde.\n");
    printf("4. Si la suma es cualquier otro numero, ese numero se convierte en 'el punto'.\n");
    printf("5. El jugador debe repetir 'el punto' antes de lanzar un 7 para ganar.\n");
    printf("6. Si se lanza un 7 antes de repetir 'el punto', el jugador pierde.\n");
}
//Función main
int main() {
    srand(time(NULL));
    int dado1, dado2, suma, punto = 0;
    char opcion;
    double saldo = 100.0; 
    double apuesta;

    printf("Bienvenido al juego del Craps!\n");

    do {
        printf("Menu:\n");
        printf("1. Ver las reglas del juego\n");
        printf("2. Jugar Craps\n");
        printf("3. Salir\n");
        
        printf("Selecciona una opcion (1/2/3): ");
        scanf(" %c", &opcion);
        system("cls");

        switch (opcion) {
            case '1':
                mostrarReglas(); //Llama a la función creada arriba
                break;
            case '2': 			//Comienza el juego
                if (saldo <= 0) {
                    printf("Tu saldo es insuficiente. Debes recargar para continuar jugando.\n");
                    break;
                }
               		 //Hacer la apuesta
                printf("Tu saldo actual: $%.2lf\n", saldo);
                printf("Ingresa la cantidad a apostar: $");
                scanf("%lf", &apuesta);
                system("cls");

                if (apuesta <= 0 || apuesta > saldo) {
                    printf("Apuesta no valida. Debes ingresar una cantidad valida.\n");
                    break;
                }
					//Lanzar los dados
                do {
                    printf("Presiona Enter para lanzar los dados...");
                    getchar();

                    dado1 = lanzarDado();
                    dado2 = lanzarDado();
                    suma = dado1 + dado2;
                    printf("Tus dados: %d y %d (suma: %d)\n", dado1, dado2, suma);

                    if (suma == 7 || suma == 11) {
                        printf("¡Ganaste en tu primer lanzamiento!\n");
                        saldo += apuesta;
                    } else if (suma == 2 || suma == 3 || suma == 12) {
                        printf("La maquina gana en tu primer lanzamiento. Craps!\n");
                        saldo -= apuesta;
                    } else {
                        punto = suma;
                        printf("Tu punto es %d. Debes repetirlo para ganar.\n", suma);

                        do {
                            printf("Presiona Enter para lanzar los dados de nuevo...");
                            getchar();

                            dado1 = lanzarDado();
                            dado2 = lanzarDado();
                            suma = dado1 + dado2;
                            printf("Tus dados: %d y %d (suma: %d)\n", dado1, dado2, suma);

                            if (suma == punto) {
                                printf("¡Ganaste al repetir tu punto!\n");
                                saldo += apuesta;
                                break;
                            } else if (suma == 7) {
                                printf("La maquina gana al sacar un 7 antes de repetir tu punto.\n");
                                saldo -= apuesta;
                                break;
                            }
                        } while (1);
                    }

                    printf("Tu saldo actual: $%.2lf\n", saldo);

                    if (saldo <= 0) {
                        printf("¡Te has quedado sin dinero! Gracias por jugar.\n");
                        break;
                    }

                    printf("¿Quieres jugar de nuevo? (S/N): ");
                    scanf(" %c", &opcion);
                    system("cls");
                } while (opcion == 'S' || opcion == 's');
                break;
            case '3':
                printf("Gracias por jugar al Craps.\n");
                
                return 0; 
            default:
			 printf("Opcion no valida. Por favor, elige una opción valida.\n");
        }
    } while (1);

    return 0;
}
