#include "Header.h"
using namespace std;
void transpose(double **mas, int *rows, int *cols)
{
	double temp;
	int i, j;

	for (i = 0; i < *rows; i++)
		for (j = 0; j < *cols; j++)
		{
			temp = mas[i][j];
			mas[i][j] = mas[j][i];
			mas[j][i] = temp;
		}

	*rows = *rows + *cols;
	*cols = *rows - *cols;
	*rows = *rows - *cols;
}

int main5()
{
	double **mas;
	char buff;
	int n = 0, m;
	int res;
	int i, j;

	FILE *in;

	if ((in = fopen("fail.bin", "r")) == NULL)
		return -1;

	while ((buff = fgetc(in)) != EOF)
		if (buff == '\n')
			n++;

	fseek(in, 0, SEEK_SET);
	fscanf(in, "%d", &m);

	res = (m > n) ? m : n;

	mas = (double **)malloc(res * sizeof(double *));

	for (i = 0; i < res; i++)
		mas[i] = (double *)malloc(res * sizeof(double));

	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			fscanf(in, "%lf", &mas[i][j]);

	transpose(mas, &n, &m);

	FILE *out;

	if ((out = fopen("out.bin", "w")) == NULL)
		return -1;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			fprintf(out, "%lf ", mas[j][i]);

		fprintf(out, "\n");
	}

	fclose(in);
	fclose(out);

	for (i = 0; i < res; i++)
		free(mas[i]);

	free(mas);

	return 0;
}