/* Andre Augusto Giannotti Scota
 * andre.scota@gmail.com
 */

#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 
#include <limits.h>

#define MAX_DECMALDT	(9)

int func(char *buf, size_t szbuf, unsigned int x)
{
	const char *milhar[] = {"mil", "milhoes", "bilhoes", "trilhoes", "quatrilhoes"};
	const char *decadaMaldita[MAX_DECMALDT] = {"onze", "doze", "terze", "quatorze", "quinze", "dezesseis", "dezesete", "dezoito", "dezenove"};
	const char *numeros[][3] = {
		{"cem"         , "dez"     , "um"    },
		{"duzentos"    , "vinte"   , "dois"  },
		{"trezentos"   , "trinta"  , "tres"  },
		{"quatrocentos", "quarenta", "quatro"},
		{"quinhentos"  , "ciquenta", "cinco" },
		{"seiscentos"  , "secenta" , "seis"  },
		{"setecentos"  , "setenta" , "sete"  },
		{"oitocentos"  , "oitenta" , "oito"  },
		{"novecentos"  , "noventa" , "nove"  }
	};
	char aux[50] = {0};
	char auxToken[4] = {0};
	int auxLen = 0;
	int xCharcterLen = 0;
	int i = 0, it = 0;
	int howMuchTokens = 0;

	auxLen = sprintf(aux, "%u", x);
	if((auxLen%3) == 0) xCharcterLen = sprintf(aux, "%0*u",   (auxLen%3)+auxLen , x);
	else                xCharcterLen = sprintf(aux, "%0*u", 3-(auxLen%3)+auxLen , x);
	howMuchTokens = (int) (xCharcterLen / 3) - 2;

	for(i = 0; aux[i] != '\0'; ){

		auxToken[0] = aux[i++];
		auxToken[1] = aux[i++];
		auxToken[2] = aux[i++];

		/* printf("\nauxToken: [%s]\n", auxToken); */

		for(it = 0; auxToken[it] != '\0'; it++){

			/* printf("\tit: [%d] auxToken[it]: %c\n", it, auxToken[it]); */


			if(auxToken[it] == '0')
				continue;

			if(it == 1 && auxToken[it] == '1' && auxToken[it+1] != '0'){
				/* LOGICA PARA A DECADA MALDITA (pq tinha q ser diferente? "dez e um", "dez e dois",.. "dez e oito". Mas temos coisas como "ONZE"! VTNC!!) */
				strcat(buf, decadaMaldita[auxToken[it+1] - '0' - 1]); strcat(buf, " ");
				break;
			}

			switch(auxToken[it]){
				case '1':
					if(it == 0 && (auxToken[it+1] != '0' || auxToken[it+2] != '0'))
						strcat(buf, "cento");
					else
						strcat(buf, numeros[0][it]);
					break;
				case '2':
					strcat(buf, numeros[1][it]);
					break;
				case '3':
					strcat(buf, numeros[2][it]);
					break;
				case '4':
					strcat(buf, numeros[3][it]);
					break;
				case '5':
					strcat(buf, numeros[4][it]);
					break;
				case '6':
					strcat(buf, numeros[5][it]);
					break;
				case '7':
					strcat(buf, numeros[6][it]);
					break;
				case '8':
					strcat(buf, numeros[7][it]);
					break;
				case '9':
					strcat(buf, numeros[8][it]);
					break;
			}
			if((it == 0 && auxToken[it+1] == '0' && auxToken[it+2] == '0') ||
			   (it == 1 && auxToken[it+1] == '0')                          ||
			   (it == 2))
				strcat(buf, " ");
			else
				strcat(buf, " e ");
		}

		if(howMuchTokens >= 0){
			strcat(buf, milhar[howMuchTokens]);
			strcat(buf, ", ");
			howMuchTokens--;
		}
	}
	return(0);
}

#define	MAXSZ	((size_t) 512)

int main(int argc, char *argv[])
{
	unsigned int x = 0;
	char buf[MAXSZ] = {0};

	if(argc == 2)
		x = atoi(argv[1]);
	else{
		printf("Digite um numero (maximo: %u): ", UINT_MAX);
		scanf("%u", &x);
	}

	func(buf, MAXSZ, x);

	printf("%s\n", buf);

	return(0);
}
