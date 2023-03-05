#include <stdio.h>
#define N 2

struct Aluno {
	char nome[15], curso[15];
	int idade, matricula;
	float cr;
};

typedef struct {
	struct Aluno aluno;
	float notas;
	int faltas;
} AlunosMat;

struct Disciplina {
	int codigo;
	char nome[15];
	AlunosMat turma[N];
};

void criarDisciplina(FILE* arq) {
	struct Disciplina disciplina;
	arq = fopen("disciplinas.dat", "ab");
	
	if (arq != NULL) {
		printf("Codigo: \n");
		scanf("%d", &disciplina.codigo);
		printf("Nome: \n");
		scanf("%s", &disciplina.nome);
		fwrite(&disciplina.codigo, sizeof(int), 1, arq);
		fwrite(&disciplina.nome, sizeof(char), 15, arq);
	}
	fclose(arq);
}

void incluirAluno(FILE *arq) {
	struct Disciplina disciplina;
	int i;
	arq = fopen("alunos.dat", "wb");
	
	if (arq != NULL) {
		for (i = 0; i < N; i++) {
			printf("Nome: \n");
			scanf("%s", &disciplina.turma[i].aluno.nome);
			fwrite(&disciplina.turma[i].aluno.nome, sizeof(char), 15, arq);
			printf("Matricula: \n");
			scanf("%d", &disciplina.turma[i].aluno.matricula);
			fwrite(&disciplina.turma[i].aluno.matricula, sizeof(int), 1, arq);
			printf("Idade: \n");
			scanf("%d", &disciplina.turma[i].aluno.idade);
			fwrite(&disciplina.turma[i].aluno.idade, sizeof(int), 1, arq);
			printf("Curso: \n");
			scanf("%s", &disciplina.turma[i].aluno.curso);
			fwrite(&disciplina.turma[i].aluno.curso, sizeof(char), 15, arq);
			printf("CR: \n");
			scanf("%f", &disciplina.turma[i].aluno.cr);
			fwrite(&disciplina.turma[i].aluno.cr, sizeof(float), 1, arq);
			printf("Faltas: \n");
			scanf("%d", &disciplina.turma[i].faltas);
			fwrite(&disciplina.turma[i].faltas, sizeof(int), 1, arq);
			printf("Nota: \n");
			scanf("%f", &disciplina.turma[i].notas);
			fwrite(&disciplina.turma[i].notas, sizeof(float), 1, arq);
		}
	}
	fclose(arq);
}

void listarAlunos(FILE *arq) {
	int i;
	struct Disciplina disciplina;
	arq = fopen("alunos.dat", "rb");
	
	if (arq != NULL) {
		for (i = 0; i < N; i++) {
			fread(&disciplina.turma[i].aluno.nome, sizeof(char), 15, arq);
			fread(&disciplina.turma[i].aluno.matricula, sizeof(int), 1, arq);
			fread(&disciplina.turma[i].aluno.idade, sizeof(int), 1, arq);
			fread(&disciplina.turma[i].aluno.curso, sizeof(char), 15, arq);
			fread(&disciplina.turma[i].aluno.cr, sizeof(float), 1, arq);
			fread(&disciplina.turma[i].faltas, sizeof(int), 1, arq);
			fread(&disciplina.turma[i].notas, sizeof(float), 1, arq);
			printf("Nome: %s | Matricula: %d | Idade: %d | Curso: %s | CR: %.2f | Faltas: %d | Notas: %.2f \n", disciplina.turma[i].aluno.nome, disciplina.turma[i].aluno.matricula, disciplina.turma[i].aluno.idade, disciplina.turma[i].aluno.curso, disciplina.turma[i].aluno.cr, disciplina.turma[i].faltas, disciplina.turma[i].notas);
		}
	}
	fclose(arq);
}

void imprimirBoletim(FILE *alunos, FILE* boletins) {
	int i;
	struct Disciplina disciplina;
	alunos = fopen("alunos.dat", "rb");
	boletins = fopen("boletins.dat", "ab");
	
	for (i = 0; i < N; i++) {
		fread(&disciplina.turma[i].aluno.nome, sizeof(char), 15, alunos); 
		fread(&disciplina.turma[i].aluno.matricula, sizeof(int), 1, alunos); 
		fread(&disciplina.turma[i].aluno.idade, sizeof(int), 1, alunos); 
		fread(&disciplina.turma[i].aluno.curso, sizeof(char), 15, alunos); 
		fread(&disciplina.turma[i].aluno.cr, sizeof(float), 1, alunos); 
		fread(&disciplina.turma[i].faltas, sizeof(int), 1, alunos);
		fread(&disciplina.turma[i].notas, sizeof(float), 1, alunos);
		printf("Nome: %s | Curso: %s | Matricula: %d | Total de faltas: %d | Nota: %.2f \n", disciplina.turma[i].aluno.nome, disciplina.turma[i].aluno.curso, disciplina.turma[i].aluno.matricula, disciplina.turma[i].faltas, disciplina.turma[i].notas);
		fwrite(&disciplina.turma[i].aluno.nome, sizeof(char), 15, boletins);
		fwrite(&disciplina.turma[i].aluno.curso, sizeof(char), 15, boletins);
		fwrite(&disciplina.turma[i].aluno.matricula, sizeof(int), 1, boletins);
		fwrite(&disciplina.turma[i].faltas, sizeof(int), 1, boletins);
		fwrite(&disciplina.turma[i].notas, sizeof(float), 1, boletins);
	}
	fclose(boletins);
	fclose(alunos);
}

void main() {
	FILE *disciplina, *alunos, *boletins;
	int opc;
	
	while (opc != 5) {
		printf("1- Criar disciplina \n 2- Incluir aluno \n 3- Listar alunos \n 4- Imprimir boletim \n 5- Sair \n");
		scanf("%d", &opc);
		
		switch(opc) {
			case 1: {
				criarDisciplina(disciplina);
				break;
			}
			case 2: {
				incluirAluno(alunos);
				break;
			}
			case 3: {
				listarAlunos(alunos);
				break;
			}case 4: {
				imprimirBoletim(alunos, boletins);
				break;
			}
			case 5: {
				break;
			}
		}
	}
}
