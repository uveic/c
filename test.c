#include <stdio.h>

#define VECES 50000
#define PREG_ACERTADA 0.5
#define PREG_FALLADA -0.125
#define TOT_PREGUNTAS 20
#define NUM_RESPUESTAS_PREG 3

int respuestas_correctas[TOT_PREGUNTAS];

void generar_respuestas_correctas()
{
  int i;

  srand(time(NULL));

  system("clear");
  printf("Respuestas correctas:\n");

  for(i=0;i<TOT_PREGUNTAS;i++)
  {
    respuestas_correctas[i]=(rand()%NUM_RESPUESTAS_PREG)+1;
    printf("%2d",respuestas_correctas[i]);
  }
  printf("\n\n");
}

float calcular_nota()
{
  float nota=0;
  int i,respuesta;

  for(i=0;i<TOT_PREGUNTAS;i++) {
    respuesta=(rand()%NUM_RESPUESTAS_PREG)+1;
    if (respuesta==respuestas_correctas[i])
      nota=nota+PREG_ACERTADA;
    else
      nota=nota+PREG_FALLADA;
  }
  return nota;
}

int main(void)
{
  int i,j;
  float nota;

  int aprobados=0,suspensos=0;
  float nota_media=0,nota_max=0,nota_min=10;
  generar_respuestas_correctas();

  for (i=0;i<VECES;i++)
  {
    nota=calcular_nota();
    nota_media=nota_media+nota;
    if (nota_max<nota) nota_max=nota;
    if (nota_min>nota) nota_min=nota;

    if (nota>=5)
      aprobados++;
    else
      suspensos++;
  }

  printf("\nSe ha hecho el examen %d veces, y los resultados son:\n",VECES);

  printf("\nLa nota máxima es: %0.3f",nota_max);
  printf("\nLa nota mínima es: %0.3f",nota_min);
  printf("\nLa nota media es: %0.3f",nota_media/VECES);
  printf("\nHa suspendido %d veces, lo que supone el %0.2f%%.",suspensos,(float)suspensos*100/VECES);
  printf("\nHa aprobado %d veces, lo que supone el %0.2f%%.",aprobados,(float)aprobados*100/VECES);
  printf("\n\n");
}
