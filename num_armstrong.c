#include <stdio.h>
#include <math.h>

const NUM_MAX=999999;

//La función elevar devuleve el resultado de un número que recibe(base) elevado al exponente que recibe(exp), en realidad es lo mismo que pow, pero no me funcionabal en mi ordenador, por lo tanto, tienes que borrarla y sustituir casi al final del programa la línea en la que uso la función elevar por la que está al lado.
long elevar(int base,int exp)
{
  long res;
  int i;
  res=1;
  if (base==1)
    res=1;
  else
    for(i=1;i<=exp;i++)
      res=res*base;
  return res;
}

int main(int argc, char *argv[])
{
  int num; //Variable para hacer cálculos.
  long int i; //Variable contador, para bulces y cálculos.
  int cont; //Variable para guardar el número de cifras del número introducido.
  int resto;
  long int resultado; //Variable para hacer cálculos. En ella se guarda el resultado de elevar todas las cifras del número a un exponente y compararlas con el número introducido.
  //Las siguientes variables son para guardar la cifra correspondiente del número para posteriormente hacer cálculos.
  int u; //unidades
  int d; //decenas
  int c; //centenas
  int um; //unidades de millar
  int dm; //decenas de millar
  int cm; //centenas de millar

  printf("** Cálculo de números armstrong menores de %i **\n",NUM_MAX);
  for(i=1;i<=NUM_MAX;i++)
  {
    //Se pasa el valor de i a la variable num para no cambiar el valor de i y hacer cálculos con num.
    //Se va comprobando el valor de num y guardando en cada una de las variables la cifra correspondiente. El % devuelve el resto de una operación.
    num=i;

    u=0;
    d=0;
    c=0;
    um=0;
    dm=0;
    cm=0;
    cont=0;
    while (num>0)
    {
      //Se obtienen las cifras en orden inverso. Primero unidades, luego decenas...
      resto=num%10; //Con esta operación obtenemos el resto de dividir por diez, que será siempre la última cifra.
      num=(num-resto)/10; //Quitamos la última cifra al número y actualizamos la variable num para obtener la siguiente cifra.
      cont++; //Aumentamos en uno el contador de cifras. Según este contador, guardamos la cifra en la variable correspondiente.
      if (cont==1) u=resto;
      else if(cont==2) d=resto;
      else if(cont==3) c=resto;
      else if(cont==4) um=resto;
      else if(cont==5) dm=resto;
      else if(cont==6) cm=resto;
      else num=0; //Nunca debería llegar aquí
    }

    //Ya tenemos el número descompuesto en sus cifras: u,d,c,um,dm,cm
    //Inicializamos resultado.
    resultado=0; //En resultado se guarda el resultado obtenido después de elevar cada número a sus exponentes.

    resultado=elevar(u,cont)+elevar(d,cont)+elevar(c,cont)+elevar(um,cont)+elevar(dm,cont)+elevar(cm,cont);
    //Se guarda en la variable el resultado de elevar cada cifra al exponente correspondiente para cada una de las cifras.
    //Se comprueba si el resultado es igual al número actual, puesto que i es igual, estamos ante un número armstrong.
    if (resultado==i)
      printf("El número %li es un número armstrong.\n",i);
  }
  return 0;
}
