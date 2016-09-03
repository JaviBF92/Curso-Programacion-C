/* En el programa main, dado un numero 'n' con el valor que nosotros queramos
 * definir. Comprobar si ese numero es par usando la funcion definida en
 * utils.
 * Si ese numero es par, debemos multiplicarlo por otro numero secreto que
 * nosotros definimos. Para ello debemos realizar una función de tipo estática
 * llamada multiplicar_numero_secreto donde el argumento de entrada sea el
 * numero 'n'.
 *
 * Devolver la multiplicacion del numero 'n' con el numero secreto en caso de
 * que 'n' sea par. Si no devolver -1.
 */

/* Zona para incluir las bibliotecas o las cabeceras */
#include "utils.h"
/* Zona para declarar la funcion estática */
static int multiplicar_numero_secreto(int numero){
	int n;
	if(es_par(numero))
		n = numero * 3;
	else
		n = -1;
	return n;
}
/* Programa Principal */
void main ()
{
	int n = 8;
	int multi = multiplicar_numero_secreto(n);
  
	printf("Número: %d \n", multi);
  
}
