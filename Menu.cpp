#include "Menu.h"
#include <iostream>

using namespace std;

void Menu::exibirMenuPrincipal() {
    int opcao;
    do {
        gerenciador.limparTela();
        cout << "Selecione uma opcao:" << endl << endl;
        cout << "1. Menu do Aluno" << endl;
        cout << "2. Menu do Personal" << endl;
        cout << "3. Menu dos Planos" << endl;
        cout << "4. Mostrar Relatorio" << endl;
        cout << "0. Sair" << endl << endl;
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1: menuAluno(); break;
            case 2: menuPersonal(); break;
            case 3: menuPlano(); break;
            case 4: gerenciador.limparTela(); gerenciador.relatorioGeral(); break;
            case 0: cout << "Encerrando o programa..." << endl; break;
            default: cout << "Opcao invalida. Aperte enter para tentar novamente." << endl;
            cin.ignore();
            cin.get();
            break;
        }
    } while (opcao != 0);
}

void Menu::menuAluno() {
    int opcao;
    do {
        gerenciador.limparTela();
        cout << "Menu do Aluno:" << endl << endl;
        cout << "1. Cadastrar Aluno" << endl;
        cout << "2. Listar Alunos" << endl;
        cout << "3. Alterar Dados do Aluno" << endl;
        cout << "4. Marcar Pagamento de Aluno" << endl;
        cout << "5. Deletar Aluno" << endl;
        cout << "0. Voltar" << endl << endl;
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1: cadastrarAluno(); break;
            case 2: gerenciador.limparTela(); gerenciador.listarAlunos(); break;
            case 3: alterarDadosAluno(); break;
            case 4: marcarPagamentoAluno(); break;
            case 5: deletarAluno(); break;
            case 0: break;
            default: cout << "Opcao invalida. Aperte enter para tentar novamente." << endl;
            cin.ignore();
            cin.get();
            break;
        }
    } while (opcao != 0);
}

void Menu::menuPersonal() {
    int opcao;
    do {
        gerenciador.limparTela();
        cout << "Menu do Personal:" << endl << endl;
        cout << "1. Cadastrar Personal" << endl;
        cout << "2. Listar Personais" << endl;
        cout << "3. Alterar Dados do Personal" << endl;
        cout << "4. Deletar Personal" << endl;
        cout << "0. Voltar" << endl << endl;
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1: cadastrarPersonal(); break;
            case 2: gerenciador.limparTela(); gerenciador.listarPersonais(); break;
            case 3: alterarDadosPersonal(); break;
            case 4: deletarPersonal(); break;
            case 0: break;
            default: cout << "Opcao invalida. Aperte para tentar novamente." << endl;
            cin.ignore();
            cin.get();
            break;
        }
    } while (opcao != 0);
}

void Menu::menuPlano() {
    int opcao;
    do {
        gerenciador.limparTela();
        cout << "Menu dos Planos:" << endl << endl;
        cout << "1. Cadastrar Plano" << endl;
        cout << "2. Listar Planos" << endl;
        cout << "3. Alterar Dados do Plano" << endl;
        cout << "4. Deletar Plano" << endl;
        cout << "0. Voltar" << endl << endl;
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1: cadastrarPlano(); break;
            case 2: gerenciador.limparTela(); gerenciador.listarPlanos();
                cout << endl << "Aperte enter para voltar";
                cin.ignore();
                cin.get();
                break;
            case 3: alterarDadosPlano(); break;
            case 4: deletarPlano(); break;
            case 0: break;
            default: cout << "Opcao invalida. Aperte enter para tentar novamente." << endl;
            cin.ignore();
            cin.get();
            break;
        }
    } while (opcao != 0);
}

void Menu::cadastrarAluno() {
    gerenciador.limparTela();
    string nome, cpf, telefone, email;
    int idade, planoIndex;
    double altura, peso;

    if (gerenciador.getTotalPlanos() == 0) {
        cout << "Nenhum plano cadastrado. Cadastre um plano primeiro." << endl << "Aperte enter para tentar novamente";
        cin.ignore();
        cin.get();
        return;
    }

    cout << "Nome: ";
    cin.ignore();
    getline(cin, nome);
    cout << "CPF: ";
    getline(cin, cpf);
    cout << "Telefone: ";
    getline(cin, telefone);
    cout << "Email: ";
    getline(cin, email);
    cout << "Idade: ";
    cin >> idade;
    cout << "Altura (em metros): ";
    cin >> altura;
    cout << "Peso (em kg): ";
    cin >> peso;

    cout << endl;
    gerenciador.listarPlanos();
    cout << endl << "Selecione o indice do plano desejado: ";
    cin >> planoIndex;

    if (planoIndex > 0 && planoIndex <= gerenciador.getTotalPlanos()) {
        Plano planoSelecionado = gerenciador.getPlano(planoIndex - 1);
        Aluno aluno(nome, cpf, telefone, email, idade, planoSelecionado.getNomePlano(), planoSelecionado.getPeriodoPlano(), planoSelecionado.getValorPlano(), altura, peso);
        gerenciador.cadastrarAluno(aluno);
        cout << endl << "Aluno cadastrado com sucesso! Aperte enter para voltar" << endl;
        cin.ignore();
        cin.get();
    } else {
        cout << endl << "indice de plano invalido. Aperte enter para voltar ao menu do Aluno" << endl;
        cin.ignore();
        cin.get();
        return;
    }
}

void Menu::alterarDadosAluno() {
    gerenciador.limparTela();
    gerenciador.alterarDadosAluno();
}

void Menu::marcarPagamentoAluno() {
    gerenciador.limparTela();
    gerenciador.marcarPagamentoAluno();
}

void Menu::deletarAluno() {
    gerenciador.limparTela();
    gerenciador.deletarAluno();
}

void Menu::cadastrarPersonal() {
    gerenciador.limparTela();
    string nome, cpf, telefone, email, CREF;
    int idade;
    double salario;

    cout << "Nome: ";
    cin.ignore();
    getline(cin, nome);
    cout << "CPF: ";
    getline(cin, cpf);
    cout << "Telefone: ";
    getline(cin, telefone);
    cout << "Email: ";
    getline(cin, email);
    cout << "Idade: ";
    cin >> idade;
    cout << "CREF: ";
    cin.ignore();
    getline(cin, CREF);
    cout << "Salario: ";
    cin >> salario;

    Personal personal(nome, cpf, telefone, email, idade, CREF, salario);
    gerenciador.cadastrarPersonal(personal);
    cout << endl << "Personal cadastrado com sucesso! Pressione enter para voltar" << endl;
    cin.ignore();
    cin.get();
}

void Menu::alterarDadosPersonal() {
    gerenciador.limparTela();
    gerenciador.alterarDadosPersonal();
}

void Menu::deletarPersonal() {
    gerenciador.limparTela();
    gerenciador.deletarPersonal();
}

void Menu::cadastrarPlano() {
    gerenciador.limparTela();
    string nomePlano;
    int periodoPlano;
    double valorPlano;

    cout << "Nome do Plano: ";
    cin.ignore();
    getline(cin, nomePlano);
    cout << "Periodo do Plano (dias): ";
    cin >> periodoPlano;
    cout << "Valor do Plano: ";
    cin >> valorPlano;

    Plano plano(nomePlano, periodoPlano, valorPlano);
    gerenciador.cadastrarPlano(plano);
    cout << endl << "Plano registrado com sucesso! Aperte enter para voltar" << endl;
    cin.ignore();
    cin.get();
}

void Menu::alterarDadosPlano() {
    gerenciador.limparTela();
    gerenciador.alterarDadosPlano();
}

void Menu::deletarPlano() {
    gerenciador.limparTela();
    gerenciador.deletarPlano();
}