#include <stdio.h>
#include <string.h>

typedef struct{

	char nome[30];

} string;

void ordena(string *, unsigned short tam);

void main ()
{

	int n, k, j, i;

	scanf("%d %d", &n, &k);
	string alunos[n];

	for (j = 0; j < n; j++)
		scanf("%s", alunos[n].nome);

	ordena(alunos,n);
	
	printf("%s\n", alunos[k - 1].nome);


}

void ordena(string *alunos, unsigned short tam)
{

	short i = 1, j;
	string pivo;

	while (i < tam)
	{

		j = i - 1;
		pivo = alunos[i];

		while (j >= 0 && strcmp(alunos[j].nome, pivo.nome) > 0)
		{

			alunos[j + 1] = alunos[j];
			j--;

		}

		alunos[j + 1] = pivo;
		i++;

	}
}
