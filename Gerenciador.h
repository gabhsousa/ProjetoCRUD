#ifndef GERENCIADOR_H
#define GERENCIADOR_H

#include "Aluno.h"
#include "Personal.h"
#include "Plano.h"
#include <vector>
#include <iostream>
#include <fstream>

class Gerenciador {
private:
    vector<Aluno> alunos;
    vector<Personal> personais;
    vector<Plano> planos;

    void salvarDados() const;
    void carregarDados();

public:
    Gerenciador();
    
    void cadastrarAluno(const Aluno& aluno);
    void cadastrarPersonal(const Personal& personal);
    void cadastrarPlano(const Plano& plano);
    
    void listarAlunos() const;
    void listarPersonais() const;
    void listarPlanos() const;

    int getTotalPlanos() const;
    int getTotalAlunos() const;
    int getTotalPersonais() const;
    Plano getPlano(int i) const;

    void alterarDadosAluno();
    void alterarDadosPersonal();
    void alterarDadosPlano();
    void marcarPagamentoAluno();

    void deletarAluno();
    void deletarPersonal();
    void deletarPlano();

    void relatorioGeral();
    void limparTela();
};

#endif
