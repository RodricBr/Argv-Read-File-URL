#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

  // Variável que receberá URL como string (valor para o argumento "-u")
  // Iniciando com um valor default nulo
  char *url_flag_u = NULL;

  // Verificações dos argumentos
  for (int i = 1; i < argc; i++){
    if (strcmp(argv[i], "-f") == 0){
      // Processando o arquivo
      if (i + 1 < argc) {
        processar_arquivo(argv[i + 1]);
        i++; // Ignorando nome do arquivo
      } else{ // Except se a flag "-f" não conter um arquivo (argumento sem um valor)
        printf("\033[38;5;196m⚠ Erro:\033[0m A flag '-f' precisa de um nome de arquivo que não esteja vazio!\nExemplo: %s -f arquivo.txt\n", argv[0]);
        return 1;
      }
    // Se a flag for "-h" exibir mensagem de help
    } else if (strcmp(argv[i], "-h") == 0){
      printf("\nUso:\n");
      printf("  %s -h             :: Exibe uma mensagme de ajuda\n ", argv[0]);
      printf("  %s -u example.com :: Definindo uma única URL\n", argv[0]);
      printf("  %s -f arquivo.txt :: Definindo um arquivo com várias URLs para o programa ler\n", argv[0]);
      return 0;
    } else if (strcmp(argv[i], "-u") == 0){
      // Processando string da flag "-u"
      if (i + 1 < argc){
        url_flag_u = argv[i + 1];
        i++;
      } else{
        printf("\033[38;5;196m⚠ Erro:\033[0m A flag '-u' precisa de uma URL!\nExemplo: %s -u site.com.br\n", argv[0]);
        return 1;
      }
    } else{
      printf("\033[38;5;196m⚠ Erro:\033[0m Flag inválida '%s'!\nExemplo: %s -f/-u arquivo.txt/site.com.br\n", argv[i], argv[0]);
      return 1;
    }
  }

  // Se a flag "-u" foi passada com a URL, execute os comandos com a URL
  if (url_flag_u != NULL){
    executar_comandos(url_flag_u);
  }
  return 0;
}

// Função para processar a leitura do arquivo passada na flag "-f"
void processar_arquivo(char *nome_arquivo){
  // Abrindo arquivo comoo "read-only"
  FILE *arquivo = fopen(nome_arquivo, "r");
  if (arquivo == NULL){
    printf("\033[38;5;196m⚠ Erro:\033[0m Não foi possível abrir o arquivo '%s'! Verifique se ele existe no sistema.\n", nome_arquivo);
    return;
  }

  // Lendo cada linha do arquivo dada na flag "-f"
  char linha[1024];
  while (fgets(linha, sizeof(linha), arquivo)){

    // Removendo caracteres de nova linha (espaços vazios)
    linha[strcspn(linha, "\n")] = 0;

    // Executando os comandos com as linhas do arquivo lido
    executar_comandos(linha);
  }
  // Fechando o arquivo
  fclose(arquivo);
}

// Função para executar comandos pela flag "-u"
// Todos os comandos devem vir aqui:
void executar_comandos(char *url){
  // Comando HTTPx:
  char comando_httpx[2048]; //2KB pq a string é maior
  sprintf(comando_httpx, "echo \"%s\" | httpx -silent -sc -t 200 -cl -fr >> httpx.txt", url);
  system(comando_httpx);

  // Comando ping:
  char comando_ping[2048];
  sprintf(comando_ping, "ping -c 1 -q \"%s\"", url);
  system(comando_ping);
}

//printf("argv[%d] = %s\n", i, argv[i]);


//printf("./%s", __FILE__); // nome od arquivo
// filename: refus --> (re)read; (f)file; (u)url; (s)pq sim;
