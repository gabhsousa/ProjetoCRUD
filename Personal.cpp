#include "Personal.h"

Personal::Personal(const string& nome, const string& cpf, const string& telefone, const string& email, int idade, const string& CREF, double salario)
    : Pessoa(nome, cpf, telefone, email, idade), CREF(CREF), salario(salario) {}

string Personal::getCREF() const {
    return CREF;
}

double Personal::getSalario() const {
    return salario;
}

void Personal::setCREF(const string& novoCREF) {
    CREF = novoCREF;
}

void Personal::setSalario(double novoSalario) {
    salario = novoSalario;
}
