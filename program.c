#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct evento{
    int identificador;
    int gradoExpresividad;
    int hora;
    int minuto;
}evento;

int main(){

    srand((unsigned int)time(NULL));

    FILE *fp;

    evento ev;

    int opc = 0, u = 0, d = 0, t = 0, c = 0;
    int acumUno = 0, acumDos = 0, acumTres = 0, acumCuatro = 0;

    do{
        printf("\t\tMenu Principal\n");
        printf("\n[1]. Generar eventos al azar.");
        printf("\n[2]. Mostrar todos los eventos.");
        printf("\n[3]. Mostrar estadistica de eventos.");
        printf("\n[4]. Salir");

        printf("\nIngresa una opcion: ");
        scanf("%d", &opc);

        switch(opc){
            case 1:

                fp = fopen("eventos.txt","a");

                for(int i = 0; i < 100; i++){
                    ev.identificador = rand() % 4 + 1;
                    ev.gradoExpresividad = rand() % 100 + 1;
                    ev.hora = rand () % 23;
                    ev.minuto = rand () % 59;
                    fwrite(&ev, sizeof(evento),1, fp);
                }

                fclose(fp);
                break;

            case 2:
                fp = fopen("eventos.txt", "br");

                for(int i = 0; i < 100; i++){
                    fread(&ev, sizeof(evento), 1, fp);

                    printf("\nEvento # %d", i + 1);
                    printf("\nIdentificador: %d \n", ev.identificador);
                    printf("\Grado de Expresividad: %d \n", ev.gradoExpresividad);
                    printf("\Hora: %d \n", ev.hora);
                    printf("\Minuto: %d \n", ev.minuto);
                    printf("\n");
                }

                fclose(fp);
                break;

            case 3:
                u = 0; d = 0; t = 0; c = 0;
                acumCuatro = 0; acumDos = 0; acumTres = 0; acumUno = 0;

                printf("Gesto\t\t\t Cantidad\t\t\t Expresividad \n");
                fp = fopen("eventos.txt", "br");


                for(int i = 0; i < 100; i++){

                    fread(&ev, sizeof(evento), 1, fp);

                    if(ev.identificador == 1){
                        acumUno = acumUno + ev.gradoExpresividad;
                        u++;
                    } else if(ev.identificador == 2){
                        acumDos = acumDos + ev.gradoExpresividad;
                        d++;
                    } else if(ev.identificador == 3){
                        acumTres = acumTres + ev.gradoExpresividad;
                        t++;
                    } else {
                        acumCuatro = acumCuatro + ev.gradoExpresividad;
                        c++;
                    }

                }

                printf("Alegria\t\t\t %d\t\t\t\t %d \n", u, acumUno);
                printf("Enojo\t\t\t %d\t\t\t\t %d \n", d, acumDos);
                printf("Tristeza\t\t %d\t\t\t\t %d \n", t, acumTres);
                printf("Sorpresa\t\t %d\t\t\t\t %d \n", c, acumCuatro);

                fclose(fp);
                break;

        }

    } while (opc != 4);

    return 0;
}
