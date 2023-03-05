#include <stdio.h>
#define N 40

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
	arq = fopen("disciplinas.txt", "a");
	
	if (arq != NULL) {
		printf("Codigo: \n");
		scanf("%d", &disciplina.codigo);
		printf("Nome: \n");
		scanf("%s", &disciplina.nome);
		fprintf(arq, "%d %s \n", disciplina.codigo, disciplina.nome);
	}
	fclose(arq);
}

void incluirAluno(FILE *arq) {
	struct Disciplina disciplina;
	int i;
	arq = fopen("alunos.txt", "w");
	
	if (arq != NULL) {
		for (i = 0; i < N; i++) {
			printf("Nome: \n");
			scanf("%s", &disciplina.turma[i].aluno.nome);
			printf("Matricula: \n");
			scanf("%d", &disciplina.turma[i].aluno.matricula);
			printf("Idade: \n");
			scanf("%d", &disciplina.turma[i].aluno.idade);
			printf("Curso: \n");
			scanf("%s", &disciplina.turma[i].aluno.curso);
			printf("CR: \n");
			scanf("%f", &disciplina.turma[i].aluno.cr);
			printf("Faltas: \n");
			scanf("%d", &disciplina.turma[i].faltas);
			printf("Nota: \n");
			scanf("%f", &disciplina.turma[i].notas);
			fprintf(arq, "%s %d %d %s %f %d %f \n", disciplina.turma[i].aluno.nome, disciplina.turma[i].aluno.matricula, disciplina.turma[i].aluno.idade, disciplina.turma[i].aluno.curso, disciplina.turma[i].aluno.cr, disciplina.turma[i].faltas, disciplina.turma[i].notas);
		}
	}
	fclose(arq);
}

void listarAlunos(FILE *arq) {
	int i;
	struct Disciplina disciplina;
	arq = fopen("alunos.txt", "r");
	
	if (arq != NULL) {
		for (i = 0; i < N; i++) {
			fscanf(arq, "%s %d %d %s %f %d %f", &disciplina.turma[i].aluno.nome, &disciplina.turma[i].aluno.matricula, &disciplina.turma[i].aluno.idade, &disciplina.turma[i].aluno.curso, &disciplina.turma[i].aluno.cr, &disciplina.turma[i].faltas, &disciplina.turma[i].notas);
			printf("Nome: %s | Matricula: %d | Idade: %d | Curso: %s | CR: %.2f | Faltas: %d | Notas: %.2f \n", disciplina.turma[i].aluno.nome, disciplina.turma[i].aluno.matricula, disciplina.turma[i].aluno.idade, disciplina.turma[i].aluno.curso, disciplina.turma[i].aluno.cr, disciplina.turma[i].faltas, disciplina.turma[i].notas);
		}
	}
	fclose(arq);
}

void imprimirBoletim(FILE *alunos, FILE* boletins) {
	int i;
	struct Disciplina disciplina;
	alunos = fopen("alunos.txt", "r");
	boletins = fopen("boletins.txt", "a");
	
	for (i = 0; i < N; i++) {
		fscanf(alunos, "%s %d %d %s %f %d %f", &disciplina.turma[i].aluno.nome, &disciplina.turma[i].aluno.matricula, &disciplina.turma[i].aluno.idade, &disciplina.turma[i].aluno.curso, &disciplina.turma[i].aluno.cr, &disciplina.turma[i].faltas, &disciplina.turma[i].notas);
		printf("Nome: %s | Curso: %s | Matricula: %d | Total de faltas: %d | Nota: %.2f \n", disciplina.turma[i].aluno.nome, disciplina.turma[i].aluno.curso, disciplina.turma[i].aluno.matricula, disciplina.turma[i].faltas, disciplina.turma[i].notas);
		fprintf(boletins, "%s %s %d %d %f \n", disciplina.turma[i].aluno.nome, disciplina.turma[i].aluno.curso, disciplina.turma[i].aluno.matricula, disciplina.turma[i].faltas, disciplina.turma[i].notas);
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
