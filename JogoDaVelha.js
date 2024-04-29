function main() {
    // Criar um tabulero e os jogadores, zerar as variáveis.
    // 
    // 0: posição vazia
    // 1:para jogador 1
    // 2: para jogador 2
    var validatabuleiro;

    validatabuleiro = 0;
    var velha;
    var coluna;
    var linha;
    var haVencedor;

    haVencedor = false;
    var tabuleiro = createArray(9);
    var index;

    // Limpar/Zerar o tabuleiro
    for (index = 0; index <= 8; index++) {
        tabuleiro[index] = 0;
    }
    var jogada;
    var jogador1;

    jogador1 = "Jogador 1";
    var jogador2;

    jogador2 = "Jogador 2";
    var jogadordaVez;

    jogadordaVez = 1;

    // anotar/Registrar a jogada do 1º Jogador
    velha = 1;
    do {
        window.alert(tabuleiro[0].ToString() + tabuleiro[1] + tabuleiro[2]);
        window.alert(tabuleiro[3].ToString() + tabuleiro[4] + tabuleiro[5]);
        window.alert(tabuleiro[6].ToString() + tabuleiro[7] + tabuleiro[8]);
        jogada = "";

        // registrar a jogada do primeiro jogador
        window.alert("Digite a posição da sua peça JOGADOR" + jogadordaVez);
        jogada = window.prompt('Enter a value for jogada');

        // converter a jogada texto em dois inteiros linha e coluna
        if (validaPosicao(jogada)) {
            linha = parseInt(jogada.charAt(0));
            coluna = parseInt(jogada.charAt(2));
            window.alert("Linha: " + linha + "; Coluna: " + coluna);
            if (tabuleiro[3 * linha + coluna] == 0) {
                tabuleiro[3 * linha + coluna] = jogadordaVez;

                // verificar o tabuleiro se houver ganhador ou empate finalizar o jogo
                validatabuleiro = validatabuleiro(jogadordaVez, tabuleiro);
                if (validatabuleiro != 2) {
                    if (jogadordaVez == 1) {
                        jogadordaVez = 2;
                    } else {
                        jogadordaVez = 1;
                    }
                }

                // verificar a jogada vencedora nas linhas
            } else {
                window.alert("Esta posição já está ocupada!!!");

                // informar ao jogador 1 que a posição esta preenchida e é invalida. Jogador precisa informer uma valida
            }
            velha = velha + 1;
        } else {
            window.alert("Posição invalida, favor insira outra posição!");
        }

        // Simula a função Serial.parseInt() do Arduino
        // Verificar se a posição "jogada" é valída
    } while (validatabuleiro == 0 && velha <= 9);
    if (velha <= 9) {
        window.alert("Parabens você venceu Jogador" + jogadordaVez + "!!");
    } else {
        window.alert("Deu velha!!");
    }
    window.alert(tabuleiro[0].ToString() + tabuleiro[1] + tabuleiro[2]);
    window.alert(tabuleiro[3].ToString() + tabuleiro[4] + tabuleiro[5]);
    window.alert(tabuleiro[6].ToString() + tabuleiro[7] + tabuleiro[8]);
}

function validaPosicao(entrada) {
    var entradaValida;

    entradaValida = false;
    window.alert(entrada.length());
    if (entrada.length() == 3) {
        if (entrada.charAt(0) == "0" || entrada.charAt(0) == "1" || entrada.charAt(0) == "2") {
            if (entrada.charAt(2) == "0" || entrada.charAt(2) == "1" || entrada.charAt(2) == "2") {
                entradaValida = true;
            }
        }
    }
    
    return entradaValida;
}

function validatabuleiro(jogadordaVez, tabuleiro) {
    var validatabuleiro;

    validatabuleiro = 0;
    if (tabuleiro[0] == jogadordaVez && tabuleiro[1] == jogadordaVez && tabuleiro[2] == jogadordaVez || tabuleiro[3] == jogadordaVez && tabuleiro[4] == jogadordaVez && tabuleiro[5] == jogadordaVez || tabuleiro[6] == jogadordaVez && tabuleiro[7] == jogadordaVez && tabuleiro[8] == jogadordaVez) {
        validatabuleiro = 2;
    } else {

        // verificar a jogada vencedora nas colunas
        if (tabuleiro[0] == jogadordaVez && tabuleiro[3] == jogadordaVez && tabuleiro[6] == jogadordaVez || tabuleiro[1] == jogadordaVez && tabuleiro[4] == jogadordaVez && tabuleiro[7] == jogadordaVez || tabuleiro[2] == jogadordaVez && tabuleiro[5] == jogadordaVez && tabuleiro[8] == jogadordaVez) {
            validatabuleiro = 2;
        } else {

            // verificar a jogada vencedora nas diagonais
            if (tabuleiro[0] == jogadordaVez && tabuleiro[4] == jogadordaVez && tabuleiro[8] == jogadordaVez || tabuleiro[2] == jogadordaVez && tabuleiro[4] == jogadordaVez && tabuleiro[6] == jogadordaVez) {
                validatabuleiro = 2;
            } else {

                // Troca jogador
            }
        }
    }
    
    return validatabuleiro;
}
