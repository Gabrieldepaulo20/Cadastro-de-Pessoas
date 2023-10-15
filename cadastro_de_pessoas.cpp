#include <iostream>
#include <string>
#include <vector>

using namespace std;
 //criei uma estrutura pessoa que contém as informações que pedem depois
struct Pessoa {  
    string nome = 0;
    int idade ;
    double peso = 0;
    double altura = 0;
    double imc;
};
// função de calcular imc que é dado no próprio trabalho
double calcularIMC(double peso, double altura) {
    return peso / (altura * altura);
}
// criando o vetor
int main() {
    vector<Pessoa> pessoas;
    int opcaoMenu;

    Pessoa pessoa;
    // criando o menu conforme descrito no trabalho
    do {
     cout << "Menu de Opções:\n";
        cout << "1. Cadastrar pessoa\n";
        cout << "2. Listar pessoas cadastradas\n";
        cout << "3. Pesquisar pessoa por nome\n";
        cout << "4. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcaoMenu;
        // para criar essa próxima parte tive ajuda
        switch (opcaoMenu) {
        case 1:
            cout << "Nome: ";
            cin.ignore();
            getline(cin, pessoa.nome);
            cout << "Idade: ";
            cin >> pessoa.idade;
            cout << "Peso kg: ";
            cin >> pessoa.peso;
            cout << "Altura m: ";
            cin >> pessoa.altura;

            pessoa.imc = calcularIMC(pessoa.peso, pessoa.altura);
            pessoas.push_back(pessoa);

            cout << "Pessoa cadastrada com sucesso!\n";
            break;
        case 2:
            if (pessoas.empty()) {
                cout << "Nenhuma pessoa cadastrada.\n";
            }
            else {
                cout << "Pessoas cadastradas:\n";
                for (const Pessoa& p : pessoas) {
                    cout << "Nome: " << p.nome << ", Idade: " << p.idade << ", IMC: " << p.imc << "\n";
                }
            }
            break;
        case 3:
            string nomePesquisa;
            cout << "Digite o nome da pessoa: ";
            cin.ignore();
            getline(cin, nomePesquisa);

            bool encontrada = false;
            for (const Pessoa& p : pessoas) {
                if (p.nome == nomePesquisa) {
                    cout << "Nome: " << p.nome << ", Idade: " << p.idade << ", IMC: " << p.imc << "\n";
                    encontrada = true;
                    break;
                }
            }
            // essa parte é só parte final mesmo
            if (!encontrada) {
                cout << "Pessoa não encontrada.\n";
            }
            break;
        case 4:
            cout << "Saindo do programa. Obrigado!\n";
            break;
        default:
            cout << "Opção inválida. Tente novamente.\n";
        }
    } while (opcaoMenu != 4);

    return 0;  // retornei 0 para garantir que o programa foi executado certo.
}
