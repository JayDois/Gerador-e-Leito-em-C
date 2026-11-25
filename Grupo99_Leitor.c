#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void perguntar(){
    int e;
    printf("\n\n  ------------------------------------------\n");
    printf("             QUERES VOLTAR AO MENU?\n");
    printf("  ------------------------------------------\n");
    printf("  [1] = Sim.\n");
    printf("  [2] = Não.\n");
    printf("\n  §... ");  
    scanf("%d", &e);
    switch(e){
        case 1:
            limparTela();
            printf("  Voltando ao MENU...");
            break;
        case 2:
            limparTela();
            printf("\n  Saindo do programa...");  
            exit(0);
            break;
        default:
            limparTela();
            printf("\n  Opção não encontrada. Voltando ao MENU.");
            break;
    }
}

void exibindo_Nome(){
    FILE *p;
    FILE *arq;
    jogo j[100];
    int i;
    limparTela();
    arq = fopen("Todos_os_Jogos.txt", "w");
    p = fopen("Grupo_Jogos.bin", "rb");
    if(!p){
        printf("  Erro ao abrir o arquivo");
        fprintf(arq,"  Erro ao abrir o arquivo");
    }
    fread(&j, sizeof(jogo), 100, p);
   
    for(i=0; i<100; i++){
    printf("\n  ------------------------------------------\n");
    fprintf(arq,"\n  ------------------------------------------\n");
    printf("                     JOGO %d \n", i+1);
    fprintf(arq,"                    JOGO %d \n", i+1);
    printf("  ------------------------------------------\n");
    fprintf(arq,"  ------------------------------------------\n");
    printf("  Nome: %s\n", j[i].nome);
    fprintf(arq,"  Nome: %s\n", j[i].nome);
    printf("  ID: %i\n", j[i].id);
    fprintf(arq,"  ID: %i\n", j[i].id);
    }
    fclose(p);    
    fclose(arq); 
    perguntar();
}

int pesq_genero(){
    FILE *p;
    FILE *arq;
    jogo j[100];
    int i, k, e;
    limparTela();
    p = fopen(ARQ_NAME, "rb");
    arq = fopen("Pesquisa_Gênero.txt", "w"); //
    if(!p || !arq){
        printf("Falha ao abrir o arquivo");
        return 1;
    }
    fread(&j, sizeof(jogo), 100, p);
    printf("\n\n  ------------------------------------------\n");
    printf("                  POR GÊNERO\n");
    printf("  ------------------------------------------\n");
    printf("  Qual genero deseja ver?\n");
    for(i=0;i<20;i++){
        printf("  [%d] = %s\n", i+1, print_genero(i));
    }
    if(e>20){
        limparTela();
        printf("\n  Opção não encontrada.\n  Tente novamente.");
        pesq_genero();      
    }
    printf("  [0] = Sair.\n");
    printf("\n  §... ");
    scanf("%d", &e);
    if(e == 0) {
        perguntar();
        return 1;
    }
    limparTela();    
    printf("\n  ------------------------------------------\n");
    fprintf(arq,"\n  ------------------------------------------\n");
    printf("                    GÊNERO: %s\n", print_genero(e-1));
    fprintf(arq,"                   GÊNERO: %s\n", print_genero(e-1));
    printf("  ------------------------------------------\n");
    fprintf(arq,"  ------------------------------------------\n");

    if(e >20){
        return 1;
    }
    for(i=0;i<100;i++){
        int encontrado = 0;
        for(k=0;k<3;k++){
            if(j[i].generos[k] == (genero)e-1) encontrado = 1;
        }
        if(encontrado){
            printf("  Nome: %s\n  ID: %d\n\n", j[i].nome, j[i].id);
            fprintf(arq,"  Nome: %s\n  ID: %d\n\n", j[i].nome, j[i].id);
        }  
    }
    fclose(p);
    fclose(arq);
    perguntar();
    return 0;
}
    
int por_nota(){
    FILE *arq;
    FILE *p;   
    jogo j[100];
    int i;
    float min, max;
    arq = fopen("Pesquisa_Nota.txt", "w");
    p = fopen(ARQ_NAME, "rb");
    if(!p || !arq){
        printf("Erro ao abrir o arquivo");
        return 0;
    }
    fread(&j, sizeof(jogo), 100, p);
    limparTela();
    printf("\n\n  ----------------------------------------------\n");
    printf("                     POR NOTA \n");
    printf("  ----------------------------------------------\n");
    printf("  Qual é a nota máxima dos jogos que queres ver?\n  [de 0 a 10]\n");
    printf("  §... ");
    scanf("%f", &max);
    printf("  Qual é a nota mínima [de 0 a 10]?\n");
    printf("  §... ");
    scanf("%f", &min);
   
    if(max>=6.8){
    printf("\n  ------------------------------------------\n");
    fprintf(arq,"\n  ------------------------------------------\n");
    printf("        JOGOS COM NOTA DE %.1f a %.1f: \n", min, max);
    fprintf(arq,"       JOGOS COM NOTA DE %.1f a %.1f: \n", min, max);
    printf("  ------------------------------------------\n");
    fprintf(arq,"  ------------------------------------------\n");

        for(i=0; i<100; i++){
            if((j[i].nota >= min) && (j[i].nota <= max)){
                printf("  Nome: %s    \n  ID: %d    \n  Nota: %.1f\n\n", j[i].nome, j[i].id, j[i].nota);
                fprintf(arq,"  Nome: %s    \n  ID: %d    \n  Nota: %.1f\n\n", j[i].nome, j[i].id, j[i].nota);            
            } 
        }
    }else{
        printf("\n  Infelizmente, não há jogos no sistema entre %.1f a %.1f\n", min, max);
        fprintf(arq,"\n  Infelizmente, não há jogos no sistema entre %.1f a %.1f\n", min, max);
        perguntar();
        return 0;
    }
    fclose(p);
    fclose(arq);
    perguntar();
    return 0;
}    

int por_preco(){
    FILE *arq;
    FILE *p;   
    jogo j[100];
    int i;
    float min, max;
    arq = fopen("Pesquisa_Preço.txt", "w");
    p = fopen(ARQ_NAME, "rb");
    if(!p || !arq){
        printf("  Erro ao abrir o arquivo");
        return 0;
    }
    limparTela();
    printf("\n\n  --------------------------------------------------------\n");
    printf("                          POR PREÇO \n");
    printf("  ------------------------------------------------------------\n");
    printf("  Qual é o preço máximo em reais(R$) dos jogos que queres ver?\n");
    printf("  §... ");
    scanf("%f", &max);
    printf("  Qual é o preço mínimo em reais(R$)?\n");
    printf("  §... ");
    scanf("%f", &min);
   
    fread(&j, sizeof(jogo), 100, p);
    limparTela();
    printf("\n  ------------------------------------------\n");
    fprintf(arq,"\n  ------------------------------------------\n");
    printf("        JOGOS COM PREÇO DE %.1f a %.1f: \n", min, max);
    fprintf(arq,"       JOGOS COM PREÇO DE %.1f a %.1f: \n", min, max);
    printf("  ------------------------------------------\n");
    fprintf(arq, "  ------------------------------------------\n");

        for(i=0; i<100; i++){
            if((j[i].preco >= min) && (j[i].preco <= max)){
                if(j[i].preco == 0){
                    printf("  Nome: %s    \n  ID: %d    \n  GRATUITO\n\n", j[i].nome, j[i].id);
                    fprintf(arq, "  Nome: %s    \n  ID: %d    \n  GRATUITO\n\n", j[i].nome, j[i].id);  
                } else {
                    printf("  Nome: %s    \n  ID: %d    \n  Preço: %.2f\n\n", j[i].nome, j[i].id, j[i].preco);
                    fprintf(arq, "  Nome: %s    \n  ID: %d    \n  Preço: %.2f\n\n", j[i].nome, j[i].id, j[i].preco);                          
                }
            } 
        }
    fclose(p);
    fclose(arq);
    perguntar();
    return 0;
}    

int por_tempo(){
    FILE *arq;
    FILE *p;   
    jogo j[100];
    int i;
    float min, max;
    arq = fopen("Pesquisa_Tempo.txt", "w");
    p = fopen(ARQ_NAME, "rb");
    if(!p || !arq){
        printf("  Erro ao abrir o arquivo");
        return 1;
    }
    limparTela();
    printf("\n\n  ---------------------------------------------------------------------\n");
    printf("                                POR TEMPO \n");
    printf("  ---------------------------------------------------------------------\n");
    printf("  Qual é o tempo máximo de duração (em horas) dos jogos que queres ver?\n");
    printf("  §... ");
    scanf("%f", &max);
    printf("  E qual é o tempo mínimo em horas?\n");
    printf("  §... ");
    scanf("%f", &min);
    
    fread(&j, sizeof(jogo), 100, p);
    limparTela();
    printf("\n  ------------------------------------------\n");
    fprintf(arq,"\n  ------------------------------------------\n");
    printf("      JOGOS COM TEMPO ENTRE %.1f e %.1f: \n", min, max);
    fprintf(arq,"      JOGOS COM TEMPO ENTRE %.1f e %.1f: \n", min, max);
    printf("  ------------------------------------------\n");
    fprintf(arq, "  ------------------------------------------\n");

    for(i=0; i<100; i++){
        if((j[i].tempo >= min) && (j[i].tempo <= max)){
                printf("  Nome: %s    \n  ID: %d    \n  Tempo: %.1f\n\n", j[i].nome, j[i].id, j[i].tempo);
                fprintf(arq, "  Nome: %s    \n  ID: %d    \n  Tempo: %.1f\n\n", j[i].nome, j[i].id, j[i].tempo);                          
        }
    } 
    fclose(p);
    fclose(arq);
    perguntar();
    return 0;
}

int por_conquista(){
    FILE *arq;
    FILE *p;   
    jogo j[100];
    int i, min, max;
    arq = fopen("Pesquisa_Conquistas.txt", "w");
    p = fopen(ARQ_NAME, "rb");
    if(!p || !arq){
        printf("  Erro ao abrir o arquivo");
        return 1;
    }
    limparTela();
    printf("\n\n  --------------------------------------------------------------\n");
    printf("                         POR CONQUISTAS \n");
    printf("  --------------------------------------------------------------\n");
    printf("  Qual é o número máximo de conquistas dos jogos que queres ver?\n");
    printf("  §... ");
    scanf("%i", &max);
    printf("  E qual é o número mínimo de conquistas?\n");
    printf("  §... ");
    scanf("%i", &min);
   
    fread(&j, sizeof(jogo), 100, p);
    limparTela();
    printf("\n  -------------------------------------------------\n");
    fprintf(arq,"\n  -------------------------------------------------\n");
    printf("    JOGOS COM NÚMERO DE CONQUISTAS ENTRE %i e %i: \n", min, max);
    fprintf(arq,"    JOGOS COM NÚMERO DE CONQUISTAS ENTRE %i e %i: \n", min, max);
    printf("  -------------------------------------------------\n");
    fprintf(arq, "  -------------------------------------------------\n");

    for(i=0; i<100; i++){
        if((j[i].conquistas >= min) && (j[i].conquistas <= max)){
            printf("  Nome: %s    \n  ID: %d    \n  Conquistas: %i\n\n", j[i].nome, j[i].id, j[i].conquistas);
            fprintf(arq, "  Nome: %s    \n  ID: %d    \n  Conquistas: %i\n\n", j[i].nome, j[i].id, j[i].conquistas);                          
        }
    } 
    fclose(p);
    fclose(arq);
    perguntar();    
    return 0;
}
    
int por_ID(){
    FILE *arq;
    FILE *p;
    jogo j[100];
    int i, k;
    int id;  
    arq = fopen("Pesquisa_de_ID.txt", "w");
    p = fopen(ARQ_NAME, "rb");
    if(!p || !arq){
        printf("  Erro ao abrir o arquivo");
        return 1;
    }
    limparTela();
    printf("  Qual ID do jogo que queres ver?\n");
    printf("  §... ");
    scanf("%i", &id);
    
    fread(&j, sizeof(jogo), 100, p);
    limparTela();
    for(i=0; i<100; i++){
        if(id==i+1){
            printf("\n  ------------------------------------------\n");
            fprintf(arq,"\n  ------------------------------------------\n");
            printf("                    JOGO %d \n", i+1);
            fprintf(arq,"                    JOGO %d \n", i+1);
            printf("  ------------------------------------------\n");
            fprintf(arq, "  ------------------------------------------\n");
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
            if(j[i].preco == 0){
                printf("\n  Preço: 0. (GRATUITO)\n");
                fprintf(arq,"\n  Preço: 0. (GRATUITO)\n");
            } else{
                printf("\n  Preço: %.2f\n", j[i].preco);
                fprintf(arq,"\n  Preço: %.2f\n", j[i].preco);
            }
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
    perguntar();
    return 0;
}

int por_plataforma(){
    FILE *p;
    FILE *arq;
    jogo j[100];
    int i, k, e;
    limparTela();
    p = fopen(ARQ_NAME, "rb");
    arq = fopen("Pesquisa_Plataforma.txt", "w"); //
    if(!p || !arq){
        printf("Falha ao abrir o arquivo");
        return 1;
    }
    fread(&j, sizeof(jogo), 100, p);
    printf("\n\n  -------------------------------------------\n");
    printf("                POR PLATAFORMA\n");
    printf("  -------------------------------------------\n");
    printf("  Jogos de qual plataforma deseja ver?\n");
    for(i=0;i<16;i++){
        printf("  [%d] = %s\n", i+1, print_plataforma(i));
    }
    printf("  [0] = Sair.\n");
    printf("\n  §... ");
    scanf("%d", &e);
    if(e>16){
        limparTela();
        printf("\n  Opção não encontrada.\n  Tente novamente.");
        por_plataforma();      
    }
    if(e == 0){ 
        perguntar();
        return 1;
    }
    limparTela();    
    printf("\n  ------------------------------------------\n");
    fprintf(arq,"\n  ------------------------------------------\n");
    printf("                PLATAFORMA: %s\n", print_plataforma(e-1));
    fprintf(arq,"               PLATAFORMA: %s\n", print_plataforma(e-1));
    printf("  ------------------------------------------\n");
    fprintf(arq, "  ------------------------------------------\n");

    if(e >16){
        return 1;
    }
    for(i=0;i<100;i++){
        int encontrado = 0;
        for(k=0;k<16;k++){
            if(j[i].plataformas[k] == (plataforma)e-1) encontrado = 1;
        }
        if(encontrado){
            printf("  Nome: %s\n  ID: %d\n\n", j[i].nome, j[i].id);
            fprintf(arq,"  Nome: %s\n  ID: %d\n\n", j[i].nome, j[i].id);
        }  
    }
    fclose(p);
    fclose(arq);
    perguntar();
    return 0;
}

int por_dificuldade(){
    FILE *p;
    FILE *arq;
    jogo j[100];
    int i, e;
    limparTela();
    p = fopen(ARQ_NAME, "rb");
    arq = fopen("Pesquisa_Dificuldade.txt", "w"); //
    if(!p || !arq){
        printf("Falha ao abrir o arquivo");
        return 1;
    }
    fread(&j, sizeof(jogo), 100, p);
    printf("\n\n  ------------------------------------------\n");
    printf("               POR DIFICULDADE\n");
    printf("  ------------------------------------------\n");
    printf("  Jogos de qual dificuldade deseja ver?\n");
    for(i=0;i<8;i++){
        printf("  [%d] = %s\n", i+1, print_dificuldade(i));
    }
    printf("  [0] = Sair.\n");
    printf("\n  §... ");
    scanf("%d", &e);
    if(e>8){
        limparTela();
        printf("\n  Opção não encontrada.\n  Tente novamente.");
        por_dificuldade();      
    }
    if(e == 0){
        perguntar();
        return 1;
    }
    limparTela();    
    printf("\n  ------------------------------------------\n");
    fprintf(arq,"\n  ------------------------------------------\n");
    printf("                DIFICULDADE: %s\n", print_dificuldade(e-1));
    fprintf(arq,"               DIFICULDADE: %s\n", print_dificuldade(e-1));
    printf("  ------------------------------------------\n");
    fprintf(arq,"  ------------------------------------------\n");

    if(e >8){
        return 1;
    }
    for(i=0;i<100;i++){
        if(j[i].dificuldade == (dificuldade)e-1){
            printf("  Nome: %s\n  ID: %d\n\n", j[i].nome, j[i].id);
            fprintf(arq,"  Nome: %s\n  ID: %d\n\n", j[i].nome, j[i].id);
        }  
    }
    fclose(p);
    fclose(arq);
    perguntar();
    return 0;
}

int main(){
    int sair = 0, e; 
    do{
        limparTela();
        printf("\n\n  ------------------------------------------\n");
        printf("                MENU PRINCIPAL\n");
        printf("  ------------------------------------------\n");
        printf("  Como queres ver cada jogo?\n");
        printf("  [1] = Todos os Jogos.\n");
        printf("  [2] = Por Gênero.\n");
        printf("  [3] = Por Nota.\n");
        printf("  [4] = Por Plataforma.\n");
        printf("  [5] = Por Preço.\n");
        printf("  [6] = Por Dificuldade.\n");
        printf("  [7] = Por Tempo.\n");
        printf("  [8] = Por Número de Conquistas.\n");
        printf("  [9] = Por ID.\n");
        printf("  [0] = Sair.\n");
        printf("\n  §... ");
        scanf("%d", &e);
        limparTela();
        switch(e){
            case 1:
                printf("  Exibindo...");
                exibindo_Nome();
                break;
            case 2:
                pesq_genero();
                break;
            case 3:
                por_nota();
                break;
            case 4:
                por_plataforma();
                break;
            case 5:
                por_preco();
                break;
            case 6:
                por_dificuldade();
                break;
            case 7:
                por_tempo();
                break;
            case 8:
                por_conquista();
                break;
            case 9: 
                por_ID();
                break;
            case 0:
                printf("\n  Gerando arquivo...");  
                printf("\n  Saindo do programa...");  
                sair = 67;
                break;
            default:
                limparTela();
                printf("\n  Opção não encontrada. Tente novamente.");
                break;
        }
    } while(sair == 0);
   
    return 0;
}