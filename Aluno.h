#ifndef ALUNO_H
#define ALUNO_H

#include "Pessoa.h"
#include "Plano.h"
#include <string>

using namespace std;

class Aluno : public Pessoa, public Plano {
protected:
    double altura;
    double peso;
    int matricula;

public:
    Aluno(const string& nome, const string& cpf, const string& telefone, const string& email, int idade,
          const string& nomePlano, int periodoPlano, double valorPlano, double altura, double peso);

    double getAltura() const;
    double getPeso() const;
    double calcularIMC() const;
    int gerarMatricula() const;
    int getMatricula() const;

    void setAltura(double novaAltura);
    void setPeso(double novoPeso);
    void setMatricula(int novaMatricula); 
};

#endif
