#include "utils.h">

void main() {
	FILE *arq;
	tpFigura desenho[N];
	char ponto;
	int opc;
	
	while (opc != 4) {
		printf("1- Preenche \n 2- Imprime \n 3- Apaga \n 4- Encerrar \n");
		scanf("%d", &opc);
		
		switch(opc) {
			case 1:{
				preenche(arq, &desenho);
				break;
			}
			case 2:{
				imprime(arq, &desenho);
				break;
			}
			case 3:{
				printf("Escolha um rotulo: \n");
				scanf(" %c", &ponto);
				apaga(arq, &desenho, ponto);
				break;
			}
			case 4:{
				break;
			}
		}
	}	
}
