#ifndef PESSOA_H
#define PESSOA_H

#include <string>

using namespace std;

class Pessoa {
protected:
    string nome;
    string cpf;
    string telefone;
    int idade;
    string email;

public:
    Pessoa(const string& nome, const string& cpf, const string& telefone, const string& email, int idade);

    string getNome() const;
    string getCPF() const;
    string getTelefone() const;
    int getIdade() const;
    string getEmail() const;

    void setNome(const string& novoNome);
    void setTelefone(const string& novoTelefone);
    void setEmail(const string& novoEmail);
    void setIdade(int novaIdade);
};

#endif
