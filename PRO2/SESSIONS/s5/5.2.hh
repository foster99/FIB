/**
 * @mainpage Ejemplo de diseño modular:  Ej 5.2.
 */

/** @file 5.2.cc
    @brief Programa principal para el ejercicio <em>Ej 5.2</em>.
*/

#include "Palabra.hh" // para que el diagrama modular quede bien
#include "ListaPalabras.hh"


/** \Pre 0 < word < Palabra(MAXLONG)
 * \Pre  0 < words < ListaPalabras(MAXNUMPAL)
 * \Post "lista" contains all words.
 */
void leer(ListaPalabras& l){
  Palabra p;
  p.leer('.');
  while(p.long_pal() != 0){
    l.anadir_palabra(p);
  }
}



/** @brief Programa principal para el ejercicio <em>Ej 5.2</em>.
*/
int main ()
{
  ListaPalabras lista;
  leer(lista);
  cout << lista.max_freq() << endl;
}
/*
Dado un texto terminado en ’.’, obtener la frecuencia de la palabra mas frecuente del 
mismo. El ´
separadas por cualquier otro ´
El texto no contendra m´ as de ´ MAXNUMPAL palabras distintas, 
cada una de ellas no mayor
El texto se introduce por el canal standard de entrada. Podeis hacer las ´2 SESION 5.
DISE ´ NO MODULAR EN C++ (I) ˜
pero resultar ´ a interesante que tambi ´ en lo prob ´ eis ´
entrada a un ﬁchero como pro2 s52.txt.
De este enunciado podemos deducir dos claras abstracciones de datos:
necesitamos la clase
necesitamos otra estructura para
frecuencias.
La clase Palabra esta preparada para usarse en este ejercicio ya que la longitud 
m ´ axima ´
Podeis ver un ejemplo de uso ´
Para representar la otra estructura de datos os ofrecemos la clase
tambien est ´ a preparada para usarse en este ejercicio ya que el n ´ umero de ´
palabras distintas que permite coincide con el MAXNUMPAL del texto.*/