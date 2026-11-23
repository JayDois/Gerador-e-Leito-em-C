#include <stdio.h>
#include <string.h>

#define ARQ_NAME "Grupo_Jogos.bin"

typedef enum Genero{
   ACAO,
   AVENTURA,
   RPG,
   BATTLE_ROYALE,
   SOBREVIVENCIA,
   CONSTRUCAO,
   ESPORTE,
   MISTERIO,
   ESTRATEGIA,
   MULTIPLAYER,
   JRPG,
   METROIDVANIA,
   PUZZLE,
   ROGUELIKE,
   SANDBOX,
   SIMULACAO,
   AUTOMOBILISMO,
   TERROR,
   FPS,
   PLATAFORMA,
   NULO_GENERO,
}genero;

typedef enum Plataforma{
    WINDOWS,
    LINUX,
    MAC,
    MOBILE,
    STADIA,
    NINTENDO_64,
    NINTENDO_SWITCH,
    SUPER_NINTENDO,
    XBOX_360,
    XBOX_ONE,
    XBOX_SERIES,
    PS_VITA,
    PS2,
    PS3,
    PS4,
    PS5,
    NULA_PLATAFORMA,
}plataforma;

typedef enum Dificuldade{
    RELAXANTE,
    BAIXA,
    FACIL,
    MEDIA,
    ALTA,
    EXTREMA,
    AJUSTAVEL,
    DINAMICA,
}dificuldade;

typedef struct Jogo{
    char nome[200];
    genero generos[10];
    float nota;
    plataforma plataformas[16];
    float preco;
    dificuldade dificuldade;
    float tempo;
    int conquistas;
    int id;
}jogo;

const char* print_genero(int genero){
    switch(genero){
        case ACAO: return "Ação";
        case AVENTURA: return "Aventura";
        case RPG: return "Rpg";
        case BATTLE_ROYALE: return "Battle Royale";
        case SOBREVIVENCIA: return "Sobrevivencia";
        case CONSTRUCAO: return "Construção";
        case ESPORTE: return "Esporte";
        case MISTERIO: return "Mistério";
        case ESTRATEGIA: return "Estratégia";
        case MULTIPLAYER: return "Multiplayer";
        case JRPG: return "JRPG";
        case METROIDVANIA: return "Metroidvania";
        case PUZZLE: return "Puzzle";
        case ROGUELIKE:  return "RogueLike";
        case SANDBOX: return "Sandbox";
        case SIMULACAO: return "Simulação";
        case AUTOMOBILISMO: return "Automobilismo";
        case TERROR: return "Terror";
        case FPS: return "FPS";
        case PLATAFORMA: return "Plataforma";
        case NULO_GENERO: return "NULO";
    }
    return "Desconhecido";
}

const char* print_plataforma(int plataforma){
    switch(plataforma){
        case WINDOWS: return "Windows";
        case LINUX: return "Linux";
        case MAC: return "Mac";
        case MOBILE: return "Mobile";
        case STADIA: return "Stadia";
        case NINTENDO_64: return "Nintendo";
        case NINTENDO_SWITCH: return "Nintendo Switch";
        case SUPER_NINTENDO: return "Super Nintendo";
        case XBOX_360: return "Xbox 360";
        case XBOX_ONE: return "Xbox One";
        case XBOX_SERIES: return "Xbox Series";
        case PS_VITA: return "PS Vita";
        case PS2: return "PS2";
        case PS3: return "PS3";
        case PS4: return "PS4";
        case PS5: return "PS5";
        case NULA_PLATAFORMA: return "NULO";
    }
    return "Desconhecido";
}

const char* print_dificuldade(int dificuldade){
    switch(dificuldade){
        case RELAXANTE: return "Relaxante";
        case BAIXA: return "Baixa";
        case FACIL: return "Fácil";
        case MEDIA: return "Média";
        case ALTA: return "Alta";
        case EXTREMA: return "Extrema";
        case AJUSTAVEL: return "Ajustável";
        case DINAMICA: return "Dinámica";
    }
    return "Desconhecida";
}

void exibindo_Nome(){
    FILE *p;
    FILE *arq;
    jogo j[100];
    int i;
    arq = fopen("Todos_os_Jogos.txt", "w");
    p = fopen("Grupo_Jogos.bin", "rb");
    if(!p){
        printf("Erro ao abrir o arquivo");
        fprintf(arq, "Erro ao abrir o arquivo");
    }
    fread(&j, sizeof(jogo), 100, p);
   
    for(i=0; i<100; i++){
    printf("\n------------------------------\n");
    fprintf(arq,"\n------------------------------\n");
    printf("        Jogo %d \n", i+1);
    fprintf(arq,"        Jogo %d \n", i+1);
    printf("------------------------------\n");
    fprintf(arq,"------------------------------\n");
    printf("  Nome: %s\n", j[i].nome);
    fprintf(arq,"  Nome: %s\n", j[i].nome);
    printf("  ID: %i\n", j[i].id);
    fprintf(arq,"  ID: %i\n", j[i].id);
    }
    fclose(p);    
    fclose(arq);    
}

int pesq_genero(){
    FILE *p;
    FILE *arq;
    jogo j[100];
    int i, k, e;
    p = fopen(ARQ_NAME, "rb");
    arq = fopen("Pesquisa_Genero", "w");
    if(!p || !arq){
        printf("Falha ao abrir o arquivo");
        return 1;
    }
    fread(&j, sizeof(jogo), 100, p);
    printf("\n\n------------------------------\n");
    printf("        POR GENERO\n");
    printf("------------------------------\n");
    printf("Qual genero deseja ver?\n");
    for(i=0;i<20;i++){
        printf("[%d] = %s\n", i+1, print_genero(i));
    }
    printf("[0] = Sair.\n");
    printf("\n§... ");
    scanf("%d", &e);
    
    printf("\n------------------------------\n");
    fprintf(arq,"\n------------------------------\n");
    printf("        Genero %s \n", print_genero(e-1));
    fprintf(arq,"        Genero %s \n", print_genero(e-1));
    printf("------------------------------\n");
    fprintf(arq, "------------------------------\n");

    if(e >20){
        return 1;
    }
    for(i=0;i<100;i++){
        int encontrado = 0;
        for(k=0;k<3;k++){
            if(j[i].generos[k] == (genero)e-1) encontrado = 1;
        }
        if(encontrado){
            printf("Nome: %s    ID: %d\n\n", j[i].nome, j[i].id);
            fprintf(arq, "Nome: %s    ID: %d\n\n", j[i].nome, j[i].id);
        }  
    }
    fclose(p);
    fclose(arq);
    return 0;
}
void pesq_ID(){
    FILE *arq;
    FILE *p;
    jogo j[100];
    int i, k;
    int id;  
    printf("Qual ID do jogo que queres ver?\n");
    printf("§... ");
    scanf("%i", &id);
    arq = fopen("Pesquisa_de_ID.txt", "w");
    p = fopen(ARQ_NAME, "rb");
    if(!p || !arq){
        printf("Erro ao abrir o arquivo");
    }
    fread(&j, sizeof(jogo), 100, p);
   
    for(i=0; i<100; i++){
        if(id==i+1){
        
            printf("\n------------------------------\n");
            fprintf(arq,"\n------------------------------\n");
            printf("        Jogo %d \n", i+1);
            fprintf(arq,"        Jogo %d \n", i+1);
            printf("------------------------------\n");
            fprintf(arq, "------------------------------\n");
            printf("  Nome: %s\n", j[i].nome);
            fprintf(arq,"  Nome: %s\n", j[i].nome);
            printf("  Generos: ");
            fprintf(arq,"  Generos: ");
            for(k=0;k<3;k++){
                if(strcmp(print_genero(j[i].generos[k]), "NULO") != 0){
                    printf("%s, ", print_genero(j[i].generos[k]));
                    fprintf(arq, "%s, ", print_genero(j[i].generos[k]));
                }
            }  
            printf("\n  Nota: %.1f\n", j[i].nota);
            fprintf(arq, "\n  Nota: %.1f\n", j[i].nota);
            printf("  Plataformas: ");
            fprintf(arq, "  Plataformas: ");
            for(k=0; k<16; k++){
                if(strcmp(print_plataforma(j[i].plataformas[k]), "NULO") != 0){
                    printf("%s, ", print_plataforma(j[i].plataformas[k]));
                    fprintf(arq,"%s, ", print_plataforma(j[i].plataformas[k]));
                }
            }
            printf("\n  Preço: %.2f\n", j[i].preco);
            fprintf(arq,"\n  Preço: %.2f\n", j[i].preco);
            printf("  Dificuldade: ");
            fprintf(arq,"  Dificuldade: ");
            if(strcmp(print_dificuldade(j[i].dificuldade), "NULO") != 0){
                    printf("%s\n", print_dificuldade(j[i].dificuldade));
                    fprintf(arq, "%s\n", print_dificuldade(j[i].dificuldade));
                }
            printf("  Conquistas: %i\n", j[i].conquistas);
            fprintf(arq,"  Conquistas: %i\n", j[i].conquistas);
            printf("  ID: %i\n", j[i].id);
            fprintf(arq,"  ID: %i\n", j[i].id);
        }
    }
    fclose(p);    
    fclose(arq);
}


int main(){
    int sair = 0, e;    
    do{
        printf("\n\n------------------------------\n");
        printf("        MENU PRINCIPAL\n");
        printf("------------------------------\n");
        printf("Como queres ver cada jogo?\n");
        printf("[1] = Todos os Jogos.\n");
        printf("[2] = Por Gênero.\n");
        printf("[3] = Por Nota.\n");
        printf("[9] = Por ID.\n");
        printf("[0] = Sair.\n");
        printf("\n§... ");
        scanf("%d", &e);
        switch(e){
            case 1:
                printf("Exibindo...");
                exibindo_Nome();
                break;
            case 2:
                pesq_genero();
                break;
            case 9: 
                pesq_ID();
                break;
            case 0:
                printf("\nSaindo do programa...");  
                sair = 67;
                break;
            default:
                printf("\nOpção não encontrada, jegue. Tente novamente.");
                break;
        }
    } while(sair == 0);
   
    return 0;
}