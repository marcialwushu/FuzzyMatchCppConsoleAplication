// ConsoleApplicationCpp.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//


#include <algorithm>
#include <string>
#include <iostream>
#include <vector>

int min3(int a, int b, int c) {
    return std::min(a, std::min(b, c));
}

int levenshteinDistance(std::string str1, std::string str2) {
    int n = str1.size();
    int m = str2.size();

    std::vector<std::vector<int>> d(n + 1, std::vector<int>(m + 1));
    for (int i = 0; i <= n; i++) {
        d[i][0] = i;
    }
    for (int j = 0; j <= m; j++) {
        d[0][j] = j;
    }

    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            if (str1[i - 1] == str2[j - 1]) {
                d[i][j] = d[i - 1][j - 1];
            }
            else {
                d[i][j] = min3(
                    d[i - 1][j] + 1,
                    d[i][j - 1] + 1,
                    d[i - 1][j - 1] + 1
                );
            }
        }
    }

    return d[n][m];
}


int fuzzyMatch(std::string pattern, std::string target, double maxRatio) {
    int distance = levenshteinDistance(pattern, target);
    int m = pattern.size();
    int n = target.size();
    int maxLength = std::max(m, n);
    double ratio = 1.0 - (double)distance / maxLength;
    if (ratio < maxRatio) {
        return (int)(ratio * 100);
    }
    else {
        return 0;
    }
}



int main()
{
    /*std::cout << "Hello World!\n";*/
    std::cout << fuzzyMatch("kitten", "sitting", 0.6) << std::endl;
    std::cout << fuzzyMatch("flaw", "flaws", 0.6) << std::endl;
    std::cout << fuzzyMatch("abc", "abd", 0.7) << std::endl;

}

// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
