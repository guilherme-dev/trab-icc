#include "lib.h"

void testa_parametros(int argc, char const *argv[]){
    
    n = atoi(argv[1]);
    if (n < 0) {
        fprintf(stderr, "ERRO: n negativo: %s\n", argv[1]);
    }
    nBandas = atoi(argv[2]);
    int i = 3;
    if (!strcmp(argv[i],"-i")) {
        maxIter = atoi(argv[i]);
        i++;
    } else if (!strcmp(argv[i],"-t")) {
        i++;
        tolerancia = atof(argv[i]);
    } else if (!strcmp(argv[i],"-o")) {
        arquivo_saida = malloc(sizeof(char) * strlen(argv[i]));
        strcpy(arquivo_saida, argv[i]);
        output = fopen(arquivo_saida, "wr");
    } else {
        fprintf(stderr, "ERRO: parametro \"%s\" não reconhecido\n", argv[i]);
        exit(-1);
    }
}

// double timestamp (){
//     struct timeval tp;
//     gettimeofday(&tp, NULL);
//     return((double)(tp.tv_sec + tp.tv_usec/1000000.0));
// }

// void grava_arquivo(double *matriz, double *res, int n, int nx, int ny, double hx, double hy, double sor_time, double res_time){
//     int i, j;
//     fprintf(output,"#########################################\n");
//     fprintf(output, "# Tempo Método SOR: %lf\n", sor_time);
//     fprintf(output, "# Tempo Resíduo: %lf\n", res_time);
//     fprintf(output, "# Norma do Residuo \n");

//     for (i = 0; i < max_iter; i++) {
//         fprintf(output, "# iter %d: %f\n", i, res[i]);
//     }
//     fprintf(output, "#########################################\n");
//     fprintf(output, "set title  'ICC'\n");
//     fprintf(output, "set xlabel 'x'\n");
//     fprintf(output, "set ylabel 'y'\n");
//     fprintf(output, "set zlabel 'z'\n");
//     fprintf(output, "splot '-' with lines\n");
    
//     for (i = 0; i < ny; i++) {
//         for (j = 0; j < nx; j++) {
//             fprintf(output,"%.3f %.3f %.3f\n", (hx*j), (hy *i), matriz[i*nx+j]);
//         }
//     }
// }