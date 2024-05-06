int velha;
int linha;
int coluna;
bool haVencedor = false;
int tabuleiro[9];
int index;


void setup() {
  Serial.begin(9600);
  for (index = 0; index <= 8; index++) {
    tabuleiro[index] = 0;
  }
}

void loop() {
  String jogador1 = "Jogador1";

  String jogador2 = "Jogador2";

  String jogada;

  int jogadorDaVez = 1;



  velha = 1;
  do {
    Serial.print(tabuleiro[0]);
    Serial.print(tabuleiro[1]);
    Serial.println(tabuleiro[2]);
    Serial.print(tabuleiro[3]);
    Serial.print(tabuleiro[4]);
    Serial.println(tabuleiro[5]);
    Serial.print(tabuleiro[6]);
    Serial.print(tabuleiro[7]);
    Serial.println(tabuleiro[8]);

    jogada = "";
    Serial.print(" Digite a posicao da sua peca JOGADOR ");
    Serial.println(jogadorDaVez);
    while (Serial.available() == 0) {
      // Aguarda a entrada de informações
    }
   // jogada = Serial.readStringUntil('\n');
    jogada = Serial.readString();
    if (validaPosicao(jogada)) {

      linha = jogada.substring(0, 1).toInt();
      coluna = jogada.substring(2, 3).toInt();

       Serial.print("Linha: ");
       Serial.print(linha);
       Serial.print(" ;Coluna: ");
       Serial.println(coluna);

      // Verifica se a posição da sua 'jogada' é valida
      if (tabuleiro[3 * linha + coluna] == 0) {
        tabuleiro[3 * linha + coluna] = jogadorDaVez;
        // Verifica se sua jogada foi vencedora nas linhas
        if (tabuleiro[0] == jogadorDaVez && tabuleiro[1] == jogadorDaVez && tabuleiro[2] == jogadorDaVez || tabuleiro[3] == jogadorDaVez && tabuleiro[4] == jogadorDaVez && tabuleiro[5] == jogadorDaVez || tabuleiro[6] == jogadorDaVez && tabuleiro[7] == jogadorDaVez && tabuleiro[8] == jogadorDaVez) {
          haVencedor = true;
        } else {

          // Verifica se a sua jogada foi vencedora nas colunas.
          if (tabuleiro[0] == jogadorDaVez && tabuleiro[3] == jogadorDaVez && tabuleiro[6] == jogadorDaVez || tabuleiro[1] == jogadorDaVez && tabuleiro[4] == jogadorDaVez && tabuleiro[7] == jogadorDaVez || tabuleiro[2] == jogadorDaVez && tabuleiro[5] == jogadorDaVez && tabuleiro[8] == jogadorDaVez) {
            haVencedor = true;
          } else {

            // Verifica se a sua jogada foi vencedora nas diagonais.
            if (tabuleiro[0] == jogadorDaVez && tabuleiro[4] == jogadorDaVez && tabuleiro[8] == jogadorDaVez || tabuleiro[2] == jogadorDaVez && tabuleiro[4] == jogadorDaVez && tabuleiro[6] == jogadorDaVez) {
              haVencedor = true;
            } else {

              // Troca o jogador
             jogadorDaVez = (jogadorDaVez == 1)? 2 : 1;
            }
          }
        }
        velha = velha + 1;
      } else {  // se o jogador inserir a mesma posição, imprime o texto:
        Serial.println("Posicao ocupada, jogue novamente !!!");
      }
    } else {  // ou se jogador inserir uma posição inexistente, imprime o texto:
      Serial.println("Jogada invalida !!!");
    }
  } while (!haVencedor && velha <= 9);  //enquanto não tiver um vencedor continue o jogo
  if (haVencedor) {                    // se tiver vencedor imprima o texto:
    Serial.println("Parabens pela a vitoria, jogador ") & jogadorDaVez;
  } else {  // se ninguem ganhou deu velha pois então, imprima o texto:
    Serial.println("Deu VELHA!!!");
  }
  Serial.print(tabuleiro[0]);
  Serial.print(tabuleiro[1]);
  Serial.println(tabuleiro[2]);
  Serial.print(tabuleiro[3]);
  Serial.print(tabuleiro[4]);
  Serial.println(tabuleiro[5]);
  Serial.print(tabuleiro[6]);
  Serial.print(tabuleiro[7]);
  Serial.println(tabuleiro[8]);
}

bool validaPosicao(String entrada) {
  bool entradaValida;

  entradaValida = false;
  Serial.print(entrada.length());
  if (entrada.length() == 3) {
    if (entrada[0] == '0' || entrada[0] == '1' || entrada[0] == '2') {
      Serial.print(entrada[0]);
      if (entrada[2] == '0' || entrada[2] == '1' || entrada[2] == '2') {
        Serial.print(entrada[2]);
        entradaValida = true;
      }
    }
  }

  return entradaValida;
}
