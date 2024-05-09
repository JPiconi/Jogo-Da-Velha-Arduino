//declaração das Variáveis
bool validaPosicao(String entrada);
int velha;
int linha;                //variável das linhas
int coluna;               //variável das colunas
bool haVencedor = false;  //booleano
int tabuleiro[9];         //declaração do tabuleiro de matriz 3x3

void Limpartabuleiro() {
  for (int index = 0; index <= 8; index++) {
    tabuleiro[index] = 0;
  }
}

void setup() {
  Serial.begin(9600);
  // Limpar/zerar o tabuleiro

  Limpartabuleiro();
}

void loop() {


  // Iniciar o jogo, definir quem joga primeiro
  int jogadorDaVez = 1;

  // Anotar/Registrar a jogada, do primeiro jogador
  velha = 1;
  do {
    //escrita do tabuleiro
    Serial.print(tabuleiro[0]);
    Serial.print(tabuleiro[1]);
    Serial.println(tabuleiro[2]);
    Serial.print(tabuleiro[3]);
    Serial.print(tabuleiro[4]);
    Serial.println(tabuleiro[5]);
    Serial.print(tabuleiro[6]);
    Serial.print(tabuleiro[7]);
    Serial.println(tabuleiro[8]);

    String jogada = "";
    Serial.print("Por favor, digite a posicao da sua peca JOGADOR ");
    Serial.println(jogadorDaVez);
    while (Serial.available() == 0) {
      // Aguarda a entrada de informações
    }
    jogada = Serial.readStringUntil('\n');
    if (validaPosicao(jogada)) {

      // a jogada é convertida de texto, em dois inteiros linha e coluna.
      //este funcionará como o parseInt que é utilizado no arduino,Procura o próximo inteiro válido no buffer de recebimento serial
      linha = jogada.substring(0, 1).toInt();
      coluna = jogada.substring(2, 3).toInt();
      Serial.print("Linha: ");
      Serial.print(linha);
      Serial.print("; Coluna: ");
      Serial.println(coluna);

      // este verificará se a posição da sua 'jogada' é valida ou não
      if (tabuleiro[3 * linha + coluna] == 0) {
        tabuleiro[3 * linha + coluna] = jogadorDaVez;
        if (tabuleiro[0] == jogadorDaVez && tabuleiro[1] == jogadorDaVez && tabuleiro[2] == jogadorDaVez || tabuleiro[3] == jogadorDaVez && tabuleiro[4] == jogadorDaVez && tabuleiro[5] == jogadorDaVez || tabuleiro[6] == jogadorDaVez && tabuleiro[7] == jogadorDaVez && tabuleiro[8] == jogadorDaVez) {
          haVencedor = true;
        } else {

          // Verificar a jogada vencedora nas colunas.
          if (tabuleiro[0] == jogadorDaVez && tabuleiro[3] == jogadorDaVez && tabuleiro[6] == jogadorDaVez || tabuleiro[1] == jogadorDaVez && tabuleiro[4] == jogadorDaVez && tabuleiro[7] == jogadorDaVez || tabuleiro[2] == jogadorDaVez && tabuleiro[5] == jogadorDaVez && tabuleiro[8] == jogadorDaVez) {
            haVencedor = true;
          } else {

            // Verificar a jogada vencedora nas diagonais.
            if (tabuleiro[0] == jogadorDaVez && tabuleiro[4] == jogadorDaVez && tabuleiro[8] == jogadorDaVez || tabuleiro[2] == jogadorDaVez && tabuleiro[4] == jogadorDaVez && tabuleiro[6] == jogadorDaVez) {
              haVencedor = true;
            } else {

              // Trocar o jogador
              jogadorDaVez = (jogadorDaVez == 1) ? 2 : 1;
            }
          }
        }
        velha++;
      } else {
        Serial.println("Esta posicao esta ocupada, por favor jogue novamente !!!");

        // Informar ao Jogador 1 que a posição está preenchida, é inválida e ele precisa informar um posição válida.
      }
    } else {
      Serial.println("Esta jogada e invalida, favor jogar novamente!");
    }

    // Verificar a jogada vencedora nas linhas.
  } while (!haVencedor && velha <= 9);

  // Verificar o tabuleiro, se houve ganhador ou empate, finalizar o jogo.
  if (haVencedor) {
    Serial.print("Parabens voce ganhou, Jogador ");
    Serial.println(jogadorDaVez);
  } else {
    Serial.println("Deu VELHA!");
  }
  Limpartabuleiro();

}
bool validaPosicao(String entrada) {
  bool entradaValida = false;
  if (entrada.length() == 3) {
    if (entrada.charAt(0) == '0' || entrada.charAt(0) == '1' || entrada.charAt(0) == '2') {
      if (entrada.charAt(2) == '0' || entrada.charAt(2) == '1' || entrada.charAt(2) == '2') {
        entradaValida = true;
      }
    }
  }
  return entradaValida;
}
