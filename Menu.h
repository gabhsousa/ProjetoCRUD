#ifndef MENU_H
#define MENU_H

#include "Gerenciador.h"
#include <locale>

class Menu {
private:
    Gerenciador gerenciador;

    void menuAluno();
    void menuPersonal();
    void menuPlano();

    void cadastrarAluno();
    void alterarDadosAluno();
    void marcarPagamentoAluno();
    void deletarAluno();

    void cadastrarPersonal();
    void alterarDadosPersonal();
    void deletarPersonal();

    void cadastrarPlano();
    void alterarDadosPlano();
    void deletarPlano();

public:
    void exibirMenuPrincipal();
};

#endif
