// Questão 5
int umFilho_ArvAVL(ArvAVL *raiz, int valor) {
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;

    if (((*raiz)->esq != NULL) && ((*raiz)->dir == NULL)) valor++;
    if (((*raiz)->esq == NULL) && ((*raiz)->dir != NULL)) valor++;

    int alt_esq = umFilho_ArvAVL(&((*raiz)->esq), valor);
    int alt_dir = umFilho_ArvAVL(&((*raiz)->dir), valor);
    return(alt_esq + alt_dir + 1);
}

// Questão 6
int consultaNO(ArvAVL *raiz, int valor, int *limitInf, int *limitSup) {
    if (*raiz == NULL)
        return 0;
    if (*raiz != NULL) {
        consultaNO(&((*raiz)->esq), valor, limitInf, limitSup);

        if ((*raiz)->info < valor) {
            *limitInf = (*raiz)->info;
        } else if (cont == 0) {
            *limitSup = (*raiz)->info;
            cont++;
        }
        consultaNO(&((*raiz)->dir), valor, limitInf, limitSup);
    }
    return 1;
}

int consultaIntervalarAVL(ArvAVL *raiz, int valor, int *limitInf, int *limitSup) {
    if (consulta_ArvAVL(raiz, valor)) {
        return 1;
    } else {
        consultaNO(raiz, valor, limitInf, limitSup);
        return 0;
    }
}
