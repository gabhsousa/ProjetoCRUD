#ifndef PLANO_H
#define PLANO_H

#include <string>

using namespace std;

class Plano {
protected:
    string nomePlano;
    int periodoPlano;
    double valorPlano;
    bool pagamento;
    string dataInicioPlano;
    string dataPagamento;

public:
    Plano(const string& nomePlano, int periodoPlano, double valorPlano);

    string getNomePlano() const;
    int getPeriodoPlano() const;
    double getValorPlano() const;
    bool isPago() const;
    string getDataInicioPlano() const;
    string getDataPagamento() const;

    void setNomePlano(const string& novoNomePlano);
    void setPeriodoPlano(int novoPeriodoPlano);
    void setValorPlano(double novoValorPlano);
    void marcarPago(bool estado);
    void setDataInicioPlano(const string& data);
    void setDataPagamento(const string& data); 
    void verificarPagamento();
};

#endif
