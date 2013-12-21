#ifndef _TwoDimArrayUIntUIntToFloat
#define _TwoDimArrayUIntUIntToFloat
typedef struct uuf_matrix{
	float **values;
	int col_num;
	int row_num;
} uuf_matrix;
void uuf_init(uuf_matrix **pm, int cn, int rn){
	int i;
	*pm = malloc(sizeof(uuf_matrix));
	(*pm)->col_num  = cn;
	(*pm)->row_num  = rn;
	(*pm)->values = (float**)malloc(cn * sizeof(float*));
	for(i=0; i<cn; i++)
		(*pm)->values[i] =  (float*)calloc(rn, sizeof(float));
}
int uuf_read_file(uuf_matrix *m, char *file){
	FILE *fp;
  char line[32000];
  char *token;
  int i,j;
	float f;
	if ((fp = fopen(file, "r")) == NULL)
    fprintf(stderr, "%s: Coudn't open file\n");
	while (fgets(line, sizeof(line), fp) != NULL ) {
//    printf("%s",line);
    if ((token = strtok(line, "\t")) == NULL)
      break;
    i = atoi(token);
		if ((token = strtok(NULL, "\t")) == NULL)
      break;
    j = atoi(token);
		if ((token = strtok(NULL, "\n")) == NULL)
      break;
    f = atof(token);
		m->values[i][j] = f;
		m->values[j][i] = f;
	}
	fclose(fp);
}
void uuf_cal_file(uuf_matrix *m, char *file){
	FILE *fp;
  char line[32000];
  char *token;
  int i,j;
	float f;
	if ((fp = fopen(file, "r")) == NULL)
    fprintf(stderr, "%s: Coudn't open file\n");
	while (fgets(line, sizeof(line), fp) != NULL ) {
//    printf("%s",line);
    if ((token = strtok(line, "\t")) == NULL)
      break;
    i = atoi(token);
		if ((token = strtok(NULL, "\t\n")) == NULL)
      break;
    j = atoi(token);
		printf("%d\t%d\t%f\n", i, j, m->values[i][j]);
	}
	fclose(fp);
}
#endif
