#include "Pessoa.h"

Pessoa::Pessoa(const string& nome, const string& cpf, const string& telefone, const string& email, int idade)
    : nome(nome), cpf(cpf), telefone(telefone), email(email), idade(idade) {}

string Pessoa::getNome() const {
    return nome;
}

string Pessoa::getCPF() const {
    return cpf;
}

string Pessoa::getTelefone() const {
    return telefone;
}

int Pessoa::getIdade() const {
    return idade;
}

string Pessoa::getEmail() const {
    return email;
}

void Pessoa::setNome(const string& novoNome) {
    nome = novoNome;
}

void Pessoa::setTelefone(const string& novoTelefone) {
    telefone = novoTelefone;
}

void Pessoa::setEmail(const string& novoEmail) {
    email = novoEmail;
}

void Pessoa::setIdade(int novaIdade) {
    idade = novaIdade;
}
