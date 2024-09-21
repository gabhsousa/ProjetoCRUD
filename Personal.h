#ifndef PERSONAL_H
#define PERSONAL_H

#include "Pessoa.h"
#include <string>

using namespace std;

class Personal : public Pessoa {
protected:
    string CREF;
    double salario;

public:
    Personal(const string& nome, const string& cpf, const string& telefone, const string& email, int idade, const string& CREF, double salario);

    string getCREF() const;
    double getSalario() const;

    void setCREF(const string& novoCREF);
    void setSalario(double novoSalario);
};

#endif
