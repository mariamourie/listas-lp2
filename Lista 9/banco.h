#ifndef __BANCO__
#define __BANCO__
#define N 3
#include <stdio.h>

typedef struct {
	int numeroConta;
	char cpf[13];
	float saldoAtual;
} Cliente;

void lerDados(FILE *file, Cliente *cliente) {
	int i;
	file = fopen("contas.dat", "a");
	
	if (file != NULL) {
		for (i = 0; i < N; i++) {
			printf("Numero da conta: \n");
			scanf("%d", &cliente[i].numeroConta);
			fwrite(&cliente[i].numeroConta, sizeof(int), 1, file);
			printf("CPF: \n");
			scanf("%s", &cliente[i].cpf);
			fwrite(&cliente[i].cpf, sizeof(char), 13, file);
			printf("Saldo atual: \n");
			scanf("%f", &cliente[i].saldoAtual);
			fwrite(&cliente[i].saldoAtual, sizeof(float), 1, file);
		}
	}
	fclose(file);
}

void excluirCliente(FILE *file, Cliente *cliente, int numeroConta) {
	int i;
	file = fopen("contas.dat", "w+b");
	
	if (file != NULL) {
		for (i = 0; i < N; i++) {
			if (cliente[i].numeroConta == numeroConta) {
				cliente[i].numeroConta = 0;
			}
			fwrite(&cliente[i].numeroConta, sizeof(int), 1, file);
			fwrite(&cliente[i].cpf, sizeof(char), 13, file);
			fwrite(&cliente[i].saldoAtual, sizeof(float), 1, file);
		}
	}
	fclose(file);
}

void relatorioCompleto(FILE *file) {
	Cliente cliente;
	int i;
	file = fopen("contas.dat", "rb");
	
	if (file != NULL) {
		for (i = 0; i < N; i++) {
			fread(&cliente.numeroConta, sizeof(int), 1, file);
			fread(&cliente.cpf, sizeof(char), 13, file);
			fread(&cliente.saldoAtual, sizeof(float), 1, file);
			if (cliente.numeroConta != 0) {
				printf("Numero da conta: %d | CPF: %s | Saldo atual: %.2f \n", cliente.numeroConta, cliente.cpf, cliente.saldoAtual);	
			}
		}
	}
	fclose(file);
}

void relatorioDevedores(FILE *file) {
	Cliente cliente;
	int i;
	file = fopen("contas.dat", "rb");
	
	if (file != NULL) {
		for (i = 0; i < N; i++) {
			fread(&cliente.numeroConta, sizeof(int), 1, file);
			fread(&cliente.cpf, sizeof(char), 13, file);
			fread(&cliente.saldoAtual, sizeof(float), 1, file);
			if (cliente.saldoAtual < 0) {
				printf("Numero da conta: %d | CPF: %s | Saldo atual: %.2f \n", cliente.numeroConta, cliente.cpf, cliente.saldoAtual);	
		    }
		}
	}
	fclose(file);
}

void otimizarBD(FILE *file) {
	Cliente cliente;
	FILE *temp;
	int i;
	file = fopen("contas.dat", "rb");
	temp = fopen("temp.dat", "wb");
	
	if (file != NULL) {
		for (i = 0; i < N; i++) {
			fread(&cliente.numeroConta, sizeof(int), 1, file);
			fread(&cliente.cpf, sizeof(char), 13, file);
			fread(&cliente.saldoAtual, sizeof(float), 1, file);
			if (cliente.numeroConta != 0) {
				fwrite(&cliente.numeroConta, sizeof(int), 1, temp);
				fwrite(&cliente.cpf, sizeof(char), 13, temp);
				fwrite(&cliente.saldoAtual, sizeof(float), 1, temp);
		    }
		}
	}
	remove("contas.dat");
	rename("temp.dat", "contas.dat");
	fclose(temp);
}

#endif
