int main() {
    No* lista = NULL;
    char valores[] = {'A', 'B', 'A', 'C', 'A', 'D', 'E', 'A'};
    for (int i = 0; i < sizeof(valores) / sizeof(valores[0]); i++) {
        lista_adicionar_no(&lista, valores[i]);
    }

    printf("Lista original:\n");
    lista_imprimir(lista);

    char busca = 'A';
    int ocorrencias = lista_verificar_ocorrencias(lista, busca);
    printf("O valor '%c' ocorre %d vezes na lista.\n", busca, ocorrencias);

    lista_remover_no(&lista, busca);
    printf("Lista após a remoção de todos os nós com valor '%c':\n", busca);
    lista_imprimir(lista);

    int indice_para_inserir = 2;
    char valor_para_inserir = 'X';
    lista_inserir_no_i(&lista, indice_para_inserir, valor_para_inserir);
    printf("Lista após a inserção do valor '%c' na posição %d:\n", valor_para_inserir, indice_para_inserir);
    lista_imprimir(lista);

    char valor_para_verificar = 'B';
    int existe = lista_verificar_existencia(lista, valor_para_verificar);
    if (existe) {
        printf("O valor '%c' existe na lista.\n", valor_para_verificar);
    } else {
        printf("O valor '%c' NÃO existe na lista.\n", valor_para_verificar);
    }

    return 0;
}
