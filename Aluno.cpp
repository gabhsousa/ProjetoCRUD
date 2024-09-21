#include "Aluno.h"
#include <ctime>

Aluno::Aluno(const string& nome, const string& cpf, const string& telefone, const string& email, int idade,
    const string& nomePlano, int periodoPlano, double valorPlano, double altura, double peso) 
    : Pessoa(nome, cpf, telefone, email, idade), Plano(nomePlano, periodoPlano, valorPlano), altura(altura), peso(peso), matricula(gerarMatricula()) {}

double Aluno::getAltura() const {
    return altura;
}

double Aluno::getPeso() const {
    return peso;
}

double Aluno::calcularIMC() const {
    return peso / (altura * altura);
}

int Aluno::gerarMatricula() const {
    time_t t = time(0);
    struct tm* now = localtime(&t);
    int anoAtual = now->tm_year + 1900;
    static int anoArmazenado = anoAtual;
    static int numero = anoAtual * 100000;

    if (anoArmazenado != anoAtual) {
        anoArmazenado = anoAtual;
        numero = anoAtual * 100000;
    }

    numero++;
    return numero;
}

int Aluno::getMatricula() const {
    return matricula;
}

void Aluno::setAltura(double novaAltura) {
    altura = novaAltura;
}

void Aluno::setPeso(double novoPeso) {
    peso = novoPeso;
}

void Aluno::setMatricula(int novaMatricula) {
    matricula = novaMatricula;
}