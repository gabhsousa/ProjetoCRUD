#include "Plano.h"
#include <sstream>
#include <ctime>

Plano::Plano(const string& nomePlano, int periodoPlano, double valorPlano)
    : nomePlano(nomePlano), periodoPlano(periodoPlano), valorPlano(valorPlano), pagamento(false) {}

string Plano::getNomePlano() const {
    return nomePlano;
}

int Plano::getPeriodoPlano() const {
    return periodoPlano;
}

double Plano::getValorPlano() const {
    return valorPlano;
}

bool Plano::isPago() const {
    return pagamento;
}

void Plano::setNomePlano(const string& novoNomePlano) {
    nomePlano = novoNomePlano;
}

void Plano::setPeriodoPlano(int novoPeriodoPlano) {
    periodoPlano = novoPeriodoPlano;
}

void Plano::setValorPlano(double novoValorPlano) {
    valorPlano = novoValorPlano;
}

void Plano::marcarPago(bool estado) {
    pagamento = estado;
}

void Plano::setDataInicioPlano(const string& data) {
    dataInicioPlano = data;
}

string Plano::getDataInicioPlano() const {
    return dataInicioPlano;
}

void Plano::setDataPagamento(const string& data) {
    dataPagamento = data;
}

string Plano::getDataPagamento() const {
    return dataPagamento;
}

void Plano::verificarPagamento() {
    if (!pagamento) return;

    tm tmPagamento = {};
    istringstream ssPagamento(dataPagamento);
    string ano, mes, dia;
    
    getline(ssPagamento, ano, '-');
    getline(ssPagamento, mes, '-');
    getline(ssPagamento, dia, '-');

    tmPagamento.tm_year = stoi(ano) - 1900; 
    tmPagamento.tm_mon = stoi(mes) - 1;     
    tmPagamento.tm_mday = stoi(dia);        

    time_t dataAtual = time(nullptr);
    tm tmAtual = *localtime(&dataAtual);

    time_t dataPagamento = mktime(&tmPagamento);
    time_t dataAtualFinal = mktime(&tmAtual);

    double diferenca = difftime(dataAtualFinal, dataPagamento) / (60 * 60 * 24);

    if (diferenca > periodoPlano) {
        pagamento = false;
    }
}
