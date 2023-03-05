#include "banco.h"

void main() {
	Cliente cliente[N];
	FILE *file;
	int opc, numeroConta;
	
	while (opc != 6) {
		printf("1- Ler dados\n 2-Excluir cliente\n 3-Relatorio Completo\n 4- Relatorio devedores\n 5- Otimizar BD \n 6- Sair\n");
		scanf("%d", &opc);
		
		switch(opc) {
			case 1: {
				lerDados(file, &cliente);
				break;
							}
			case 2: {
				printf("Numero da conta: \n");
				scanf("%d", &numeroConta);
				excluirCliente(file, &cliente, numeroConta);
				break;
			}
			case 3: {
				relatorioCompleto(file);
				break;
			}
			case 4: {
				relatorioDevedores(file);
				break;
			}
			case 5: {
				break;
			}
		}
	}
}
