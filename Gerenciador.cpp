#include "Gerenciador.h"
#include <sstream>

Gerenciador::Gerenciador() {
    carregarDados();
}

void Gerenciador::limparTela(){
    system("cls");
}

void Gerenciador::salvarDados() const {
    ofstream arquivoAlunos("alunos.txt");
    ofstream arquivoPersonais("personais.txt");
    ofstream arquivoPlanos("planos.txt");
    ofstream arquivoRelatorio("relatorio.txt");

    double rendaTotal = 0;
    arquivoRelatorio << "Relatorio Geral da Academia" << endl;
    arquivoRelatorio << "Quantidade de Alunos Inscritos: " << alunos.size() << endl;
    arquivoRelatorio << "Quantidade de Personais Inscritos: " << personais.size() << endl;
    arquivoRelatorio << "Quantidade de Planos Inscritos: " << planos.size() << endl;
    arquivoRelatorio << endl;

    for (const auto& aluno : alunos) {
        arquivoAlunos << aluno.getNome() << "," << aluno.getCPF() << "," << aluno.getTelefone() << ","
                      << aluno.getEmail() << "," << aluno.getIdade() << "," << aluno.getAltura() << ","
                      << aluno.getPeso() << "," << aluno.getNomePlano() << "," << aluno.getPeriodoPlano() << ","
                      << aluno.getValorPlano() << "," << aluno.isPago() << "," << aluno.getMatricula() << endl;
    }

    for (const auto& personal : personais) {
        arquivoPersonais << personal.getNome() << "," << personal.getCPF() << "," << personal.getTelefone() << ","
                         << personal.getEmail() << "," << personal.getIdade() << "," << personal.getCREF() << ","
                         << personal.getSalario() << endl;
    }

    for (const auto& plano : planos) {
        int n = 0;
            for(const auto& aluno: alunos){
                if(aluno.getNomePlano() == plano.getNomePlano()){
                    n++;
                }
            }
            double rendaPlano = n * plano.getValorPlano();
            rendaTotal += rendaPlano;

                arquivoPlanos << plano.getNomePlano() << "," << plano.getPeriodoPlano() << "," 
                            << plano.getValorPlano() << "," << plano.isPago() << endl;

            arquivoRelatorio << "Plano: " << plano.getNomePlano() << endl;
            arquivoRelatorio << "Numero de alunos inscritos: " << n << endl;
            arquivoRelatorio << "Renda gerada (R$): " << rendaPlano << endl;
            arquivoRelatorio << endl;
        }
    arquivoRelatorio << "Renda total da academia: (R$): " << rendaTotal << endl;
}

void Gerenciador::carregarDados() {
    ifstream arquivoAlunos("alunos.txt");
    ifstream arquivoPersonais("personais.txt");
    ifstream arquivoPlanos("planos.txt");

    if (arquivoAlunos.is_open()) {
        string linha;
        while (getline(arquivoAlunos, linha)) {
            stringstream ss(linha);
            string nome, cpf, telefone, email, nomePlano;
            int idade, periodoPlano;
            double altura, peso, valorPlano;
            bool pagamento;
            int matricula;

            getline(ss, nome, ',');
            getline(ss, cpf, ',');
            getline(ss, telefone, ',');
            getline(ss, email, ',');
            ss >> idade;
            ss.ignore();
            ss >> altura;
            ss.ignore();
            ss >> peso;
            ss.ignore();
            getline(ss, nomePlano, ',');
            ss >> periodoPlano;
            ss.ignore();
            ss >> valorPlano;
            ss.ignore();
            ss >> pagamento;
            ss.ignore();
            ss >> matricula;

            Aluno aluno(nome, cpf, telefone, email, idade, nomePlano, periodoPlano, valorPlano, altura, peso);
            aluno.marcarPago(pagamento);
            aluno.setMatricula(matricula);
            alunos.push_back(aluno);
        }
    }

    if (arquivoPersonais.is_open()) {
        string linha;
        while (getline(arquivoPersonais, linha)) {
            stringstream ss(linha);
            string nome, cpf, telefone, email, CREF;
            int idade;
            double salario;

            getline(ss, nome, ',');
            getline(ss, cpf, ',');
            getline(ss, telefone, ',');
            getline(ss, email, ',');
            ss >> idade;
            ss.ignore();
            getline(ss, CREF, ',');
            ss >> salario;

            Personal personal(nome, cpf, telefone, email, idade, CREF, salario);
            personais.push_back(personal);
        }
    }

    if (arquivoPlanos.is_open()) {
        string linha;
        while (getline(arquivoPlanos, linha)) {
            stringstream ss(linha);
            string nomePlano;
            int periodoPlano;
            double valorPlano;
            bool pagamento;

            getline(ss, nomePlano, ',');
            ss >> periodoPlano;
            ss.ignore();
            ss >> valorPlano;
            ss.ignore();
            ss >> pagamento;

            Plano plano(nomePlano, periodoPlano, valorPlano);
            plano.marcarPago(pagamento);
            planos.push_back(plano);
        }
    }
}

void Gerenciador::cadastrarAluno(const Aluno& aluno) {
    alunos.push_back(aluno);
    salvarDados();
}

void Gerenciador::cadastrarPersonal(const Personal& personal) {
    personais.push_back(personal);
    salvarDados();
}

void Gerenciador::cadastrarPlano(const Plano& plano) {
    planos.push_back(plano);
    salvarDados();
}

void Gerenciador::listarAlunos() const {
    if(alunos.empty()){
        cout << "Nenhum aluno inscrito." << endl;
    } else {
        cout << "ALUNOS INSCRITOS:" << endl << endl;
        for (size_t i = 0; i < alunos.size(); ++i) {
            cout << i + 1 << ". Nome: " << alunos[i].getNome() 
                << ", Matricula: " << alunos[i].getMatricula() 
                << ", IMC: " << alunos[i].calcularIMC()
                << ", Pagamento: " << (alunos[i].isPago() ? "Pago" : "Pendente") << endl;
        }
    }
    cout << endl << "Aperte enter para voltar";
    cin.ignore();
    cin.get();
}

void Gerenciador::listarPersonais() const {
    if(personais.empty()){
        cout << "Nenhum personal inscrito." << endl;
    }else{
        cout << "PERSONAIS INSCRITOS:" << endl << endl;
        for (size_t i = 0; i < personais.size(); ++i) {
            cout << i + 1 << ". Nome: " << personais[i].getNome() 
                << ", CREF: " << personais[i].getCREF() 
                << ", Salario: " << personais[i].getSalario() << endl;
        }
    }
    cout << endl << "Aperte enter para voltar";
    cin.ignore();
    cin.get();
}

void Gerenciador::listarPlanos() const {
    if(planos.empty()){
        cout << "Nenhum plano registrado." << endl;
    }else{
        cout << "PLANOS DISPONIVEIS:" << endl << endl;
        for (size_t i = 0; i < planos.size(); ++i) {
            cout << i + 1 << ". Nome do Plano: " << planos[i].getNomePlano() 
                << ", Periodo: " << planos[i].getPeriodoPlano() 
                << " dias, Valor: R$" << planos[i].getValorPlano() << endl;
        }
    }
}

int Gerenciador::getTotalPlanos() const {
    return planos.size();
}

int Gerenciador::getTotalAlunos() const {
    return alunos.size();
}

int Gerenciador::getTotalPersonais() const {
    return personais.size();
}

Plano Gerenciador::getPlano(int i) const {
    if (i >= 0 && i < planos.size()) {
        return planos[i];
    } else {
        cout << "Indice de plano invalido. Aperte enter para tentar novamente.";
        cin.ignore();
        cin.get();
    }
}

void Gerenciador::alterarDadosAluno() {
    string nomeBusca;
    cout << "Digite o nome do aluno que deseja buscar: ";
    cin.ignore();
    getline(cin, nomeBusca);

    vector<int> encontrados;
    for (size_t i = 0; i < alunos.size(); ++i) {
        if (alunos[i].getNome().find(nomeBusca) != string::npos) {
            encontrados.push_back(i);
        }
    }

    if (encontrados.empty()) {
        cout << "Nenhum aluno encontrado com o nome: " << nomeBusca << endl;
        cout << endl << "Pressione enter para voltar ao menu do Aluno: " << endl;
        cin.get();
        return;
    }

    cout << "Alunos encontrados com o nome : " << nomeBusca << endl;
    for (size_t i = 0; i < encontrados.size(); ++i) {
        int j = encontrados[i];
        cout << i + 1 << ". Nome: " << alunos[j].getNome()
             << ", Matricula: " << alunos[j].getMatricula()
             << ", IMC: " << alunos[j].calcularIMC()
             << ", Pagamento: " << (alunos[j].isPago() ? "Pago" : "Pendente") << endl;
    }

    int escolha;
    cout << "Digite o numero do aluno que deseja alterar (1-" << encontrados.size() << "): ";
    cin >> escolha;
    escolha--;

    if (escolha >= 0 && escolha < encontrados.size()) {
        int selecionado = encontrados[escolha];
        
        string nome, telefone, email;
        int idade;
        double altura, peso;

        cout << "Novo nome: ";
        cin.ignore();
        getline(cin, nome);
        cout << "Novo telefone: ";
        getline(cin, telefone);
        cout << "Novo email: ";
        getline(cin, email);
        cout << "Nova idade: ";
        cin >> idade;
        cout << "Nova altura (em metros): ";
        cin >> altura;
        cout << "Novo peso (em kg): ";
        cin >> peso;

        alunos[selecionado].setNome(nome);
        alunos[selecionado].setTelefone(telefone);
        alunos[selecionado].setEmail(email);
        alunos[selecionado].setIdade(idade);
        alunos[selecionado].setAltura(altura);
        alunos[selecionado].setPeso(peso);

        cout << "Dados do aluno atualizados com sucesso!" << endl;
    } else {
        cout << "Indice de aluno invalido." << endl;
    }
    cout << endl << "Pressione enter para voltar ao menu do Aluno: " << endl;
    cin.ignore();
    cin.get();
}

void Gerenciador::alterarDadosPersonal() {
    string nomeBusca;
    cout << "Digite o nome do personal que deseja buscar: ";
    cin.ignore();
    getline(cin, nomeBusca);

    vector<int> encontrados;
    for (size_t i = 0; i < personais.size(); ++i) {
        if (personais[i].getNome().find(nomeBusca) != string::npos) {
            encontrados.push_back(i);
        }
    }

    if (encontrados.empty()) {
        cout << endl << "Nenhum personal encontrado com o nome: " << nomeBusca << endl;
        cout << endl << "Pressione enter para voltar ao menu do Personal: " << endl;
        cin.get();
        return;
    }

    cout << endl << "Personais encontrados com o nome " << nomeBusca << ":" << endl;
    for (size_t i = 0; i < encontrados.size(); ++i) {
        int j = encontrados[i];
        cout << i + 1 << ". Nome: " << personais[j].getNome()
             << ", CREF: " << personais[j].getCREF()
             << ", Salario: " << personais[j].getSalario() << endl;
    }

    int escolha;
    cout << endl << "Digite o numero do personal que deseja alterar (1-" << encontrados.size() << "): ";
    cin >> escolha;
    escolha--;

    if (escolha >= 0 && escolha < encontrados.size()) {
        int selecionado = encontrados[escolha];
        string nome, telefone, email, CREF;
        int idade;
        double salario;

        cout << "Novo nome: ";
        cin.ignore();
        getline(cin, nome);
        cout << "Novo telefone: ";
        getline(cin, telefone);
        cout << "Novo email: ";
        getline(cin, email);
        cout << "Nova idade: ";
        cin >> idade;
        cout << "Novo CREF: ";
        cin.ignore();
        getline(cin, CREF);
        cout << "Novo salario: ";
        cin >> salario;

        personais[selecionado].setNome(nome);
        personais[selecionado].setTelefone(telefone);
        personais[selecionado].setEmail(email);
        personais[selecionado].setIdade(idade);
        personais[selecionado].setCREF(CREF);
        personais[selecionado].setSalario(salario);

        cout << endl << "Dados do personal atualizados com sucesso!" << endl;
        salvarDados();
    } else {
        cout << endl << "Indice de personal invalido." << endl;
    }
}


void Gerenciador::alterarDadosPlano() {
    listarPlanos();
    int planoIndex;
    cout << "Selecione o indice do plano a ser alterado: ";
    cin >> planoIndex;

    if (planoIndex > 0 && planoIndex <= planos.size()) {
        string nomePlano;
        int periodoPlano;
        double valorPlano;

        cout << endl << "Novo nome do plano: ";
        cin.ignore();
        getline(cin, nomePlano);
        cout << "Novo periodo do plano (dias): ";
        cin >> periodoPlano;
        cout << "Novo valor do plano: ";
        cin >> valorPlano;

        planos[planoIndex - 1].setNomePlano(nomePlano);
        planos[planoIndex - 1].setPeriodoPlano(periodoPlano);
        planos[planoIndex - 1].setValorPlano(valorPlano);

        cout << endl << "Dados do plano atualizados com sucesso!" << endl;
        salvarDados();
    } else {
        cout << endl << "Indice de plano invalido." << endl;
    }
    cout << endl << "Pressione enter para voltar ao menu do Plano: " << endl;
    cin.ignore();
    cin.get();
}

void Gerenciador::marcarPagamentoAluno() {
    string nomeBusca;
    cout << "Digite o nome do aluno que deseja buscar: ";
    cin.ignore();
    getline(cin, nomeBusca);

    vector<int> encontrados;
    for (size_t i = 0; i < alunos.size(); ++i) {
        if (alunos[i].getNome().find(nomeBusca) != string::npos) {
            encontrados.push_back(i);
        }
    }

    if (encontrados.empty()) {
        cout << endl << "Nenhum aluno encontrado com o nome: " << nomeBusca << endl;
        cout << endl << "Pressione enter para voltar ao menu do Aluno: " << endl;
        cin.get();
        return;
    }

    cout << endl << "Alunos encontrados com o nome " << nomeBusca << ":" << endl;
    for (size_t i = 0; i < encontrados.size(); ++i) {
        int j = encontrados[i];
        cout << i + 1 << ". Nome: " << alunos[j].getNome()
             << ", Matricula: " << alunos[j].getMatricula()
             << ", Pagamento: " << (alunos[j].isPago() ? "Pago" : "Pendente") << endl;
    }

    int escolha;
    cout << endl << "Digite o numero do aluno para marcar pagamento (1-" << encontrados.size() << "): ";
    cin >> escolha;
    escolha--;

    if (escolha >= 0 && escolha < encontrados.size()) {
        int selecionado = encontrados[escolha];
        bool pagamento;

        cout << endl << "O aluno pagou? (1 para Sim, 0 para Nao): ";
        cin >> pagamento;

        alunos[selecionado].marcarPago(pagamento);

        if (pagamento) {
            time_t t = time(0);
            struct tm* now = localtime(&t);
            char buffer[80];
            strftime(buffer, sizeof(buffer), "%Y-%m-%d", now);
            string dataAtual(buffer);

            alunos[selecionado].setDataInicioPlano(dataAtual);
            alunos[selecionado].setDataPagamento(dataAtual);
        }

        cout << endl << "Pagamento do aluno atualizado com sucesso!" << endl;
    } else {
        cout << endl << "Indice de aluno invalido." << endl;
    }

    for (size_t i = 0; i < alunos.size(); ++i) {
        alunos[i].verificarPagamento();
    }
    cout << endl << "Pressione enter para voltar ao menu do Aluno: " << endl;
    cin.ignore();
    cin.get();
}

void Gerenciador::deletarAluno() {
    string nomeBusca;
    cout << "Digite o nome do aluno que deseja buscar: ";
    cin.ignore();
    getline(cin, nomeBusca);

    vector<int> encontrados;
    for (size_t i = 0; i < alunos.size(); ++i) {
        if (alunos[i].getNome().find(nomeBusca) != string::npos) {
            encontrados.push_back(i);
        }
    }

    if (encontrados.empty()) {
        cout << endl << "Nenhum aluno encontrado com o nome: " << nomeBusca << endl;
        cout << endl << "Pressione enter para voltar ao menu do Aluno: " << endl;
        cin.get();
        return;
    }

    cout << endl << "Alunos encontrados com o nome " << nomeBusca << ":" << endl;
    for (size_t i = 0; i < encontrados.size(); ++i) {
        int j = encontrados[i];
        cout << i + 1 << ". Nome: " << alunos[j].getNome()
             << ", Matricula: " << alunos[j].getMatricula()
             << ", IMC: " << alunos[j].calcularIMC()
             << ", Pagamento: " << (alunos[j].isPago() ? "Pago" : "Pendente") << endl;
    }

    int escolha;
    cout << endl << "Digite o numero do aluno que deseja deletar (1-" << encontrados.size() << "): ";
    cin >> escolha;
    escolha--;

    if (escolha >= 0 && escolha < encontrados.size()) {
        int selecionado = encontrados[escolha];
        
        alunos.erase(alunos.begin() + selecionado);
        salvarDados();
        
        cout << endl << "Aluno deletado com sucesso!" << endl;
    } else {
        cout << endl << "Indice de aluno invalido." << endl;
    }
    cout << endl << "Pressione enter para voltar ao menu do Aluno: " << endl;
    cin.ignore();
    cin.get();
}

void Gerenciador::deletarPersonal() {
    string nomeBusca;
    cout << "Digite o nome do personal que deseja buscar: ";
    cin.ignore();
    getline(cin, nomeBusca);

    vector<int> encontrados;
    for (size_t i = 0; i < personais.size(); ++i) {
        if (personais[i].getNome().find(nomeBusca) != string::npos) {
            encontrados.push_back(i);
        }
    }

    if (encontrados.empty()) {
        cout << endl << "Nenhum personal encontrado com o nome: " << nomeBusca << endl;
        cout << endl << "Pressione enter para voltar ao menu do Personal: " << endl;
        cin.get();
        return;
    }

    cout << endl << "Personais encontrados com o nome " << nomeBusca << ":" << endl;
    for (size_t i = 0; i < encontrados.size(); ++i) {
        int j = encontrados[i];
        cout << i + 1 << ". Nome: " << personais[j].getNome()
             << ", CREF: " << personais[j].getCREF()
             << ", Salario: " << personais[j].getSalario() << endl;
    }

    int escolha;
    cout << endl << "Digite o numero do personal que deseja deletar (1-" << encontrados.size() << "): ";
    cin >> escolha;
    escolha--;

    if (escolha >= 0 && escolha < encontrados.size()) {
        int selecionado = encontrados[escolha];
        
        personais.erase(personais.begin() + selecionado);
        salvarDados();
        
        cout << endl << "Personal deletado com sucesso!" << endl;
    } else {
        cout << endl << "Indice de personal invalido." << endl;
    }
    cout << endl << "Pressione enter para voltar ao menu do Personal: " << endl;
    cin.ignore();
    cin.get();
}

void Gerenciador::deletarPlano() {
    listarPlanos();
    int planoIndex;
    cout << endl << "Selecione o indice do plano a ser deletado: ";
    cin >> planoIndex;

    if (planoIndex > 0 && planoIndex <= planos.size()) {
        planos.erase(planos.begin() + planoIndex - 1);
        cout << endl << "Plano deletado com sucesso!" << endl;
        salvarDados();
    } else {
        cout << endl << "Indice de plano invalido." << endl;
    }
    cout << endl << "Pressione enter para voltar ao menu do Plano: " << endl;
    cin.ignore();
    cin.get();
}

void Gerenciador::relatorioGeral(){
    ifstream arquivoRelatorio("relatorio.txt");
        if(arquivoRelatorio.is_open()){
            string linha;
            while(getline(arquivoRelatorio, linha)){
                cout << linha << endl;
            }
            arquivoRelatorio.close();
        } else {
            cout << "Nao foi possivel abrir o relatorio" << endl;
    }
    cout << endl << "Pressione enter para voltar ao menu: " << endl;
    cin.ignore();
    cin.get();
}