typedef struct No {
    char valor;
    struct No* proximo;
} No;
void lista_adicionar_no(No** L, char valor) {
    No* novo_no = (No*)malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->proximo = *L;
    *L = novo_no;
}
void lista_imprimir(No* L) {
    No* atual = L;
    while (atual != NULL) {
        printf("%c -> ", atual->valor);
        atual = atual->proximo;
    }
    printf("NULL\n");
}
int lista_verificar_existencia(No* L, char valor_busca) {
    No* atual = L;

    while (atual != NULL) {
        if (atual->valor == valor_busca) {
            return 1;
        }
        atual = atual->proximo;
    }

    return 0;
}
int lista_verificar_ocorrencias(No* L, char valor_busca) {
    No* atual = L;
    int ocorrencias = 0;

    while (atual != NULL) {
        if (atual->valor == valor_busca) {
            ocorrencias++;
        }
        atual = atual->proximo;
    }

    return ocorrencias;
}
void lista_remover_no(No** L, char valor_busca) {
    No* atual = *L;
    No* anterior = NULL;

    while (atual != NULL) {
        if (atual->valor == valor_busca) {
            if (anterior != NULL) {
                anterior->proximo = atual->proximo;
                free(atual);
                atual = anterior->proximo;
            } else {
                *L = atual->proximo;
                free(atual);
                atual = *L;
            }
        } else {
            anterior = atual;
            atual = atual->proximo;
        }
    }
}
void lista_inserir_no_i(No** L, int i, char novo_valor) {
    No* novo_no = (No*)malloc(sizeof(No));
    novo_no->valor = novo_valor;

    if (i == 0) {
        novo_no->proximo = *L;
        *L = novo_no;
    } else {
        No* atual = *L;
        int posicao = 0;

        while (atual != NULL && posicao < i - 1) {
            atual = atual->proximo;
            posicao++;
        }

        if (atual == NULL) {
            printf("Índice fora dos limites da lista.\n");
            free(novo_no);
            return;
        }

        novo_no->proximo = atual->proximo;
        atual->proximo = novo_no;
    }
}
