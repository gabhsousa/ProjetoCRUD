Projeto de Gerenciamento de Academia
Este projeto é um sistema de gerenciamento de academia implementado em C++. Ele permite o cadastro e gerenciamento de alunos, personais e planos, além de fornecer relatórios sobre os dados do sistema. O projeto é modular, com classes que representam os diferentes atores e funcionalidades da academia, como alunos, personais, planos e gerenciamento de dados.

Estrutura do Projeto

1. Classes
Pessoa
A classe Pessoa é uma classe base que serve para representar características comuns entre alunos e personais, como nome, CPF, telefone, idade e email.

Aluno
A classe Aluno herda de Pessoa e Plano, e representa um aluno da academia. Possui atributos específicos, como altura, peso e matrícula, além de métodos para calcular o Índice de Massa Corporal (IMC) e gerar a matrícula do aluno.

Personal
A classe Personal também herda de Pessoa, e representa um personal trainer da academia. Possui atributos como o CREF (registro profissional) e o salário.

Plano
A classe Plano é responsável por gerenciar os dados dos planos de assinatura da academia, como nome do plano, período, valor, status de pagamento, data de início e data de pagamento.

Gerenciador
A classe Gerenciador atua como uma camada de controle do sistema. Ela mantém listas de alunos, personais e planos, além de fornecer métodos para realizar operações de cadastro, listagem, alteração e remoção desses elementos. Também é responsável por salvar e carregar os dados do sistema de/para arquivos e gerar relatórios gerais.

Menu
A classe Menu é responsável pela interação com o usuário. Ela exibe o menu principal e os submenus, e faz chamadas para os métodos da classe Gerenciador conforme as opções selecionadas.

2. Funcionalidades
Cadastro
O sistema permite o cadastro de novos alunos, personais e planos. Os dados são validados e armazenados no sistema.

Listagem
É possível listar todos os alunos, personais e planos cadastrados no sistema.

Alteração e Remoção
O sistema permite alterar os dados dos alunos, personais e planos, além de possibilitar a remoção desses registros.

Pagamento
Há uma funcionalidade específica para marcar o pagamento do plano de um aluno, ajustando a data de início do plano de acordo com a data do pagamento.

Relatório
O sistema gera um relatório geral, que calcula a renda total da academia com base no número de alunos inscritos em cada plano e no valor de cada plano.

Salvamento e Carregamento de Dados
Os dados do sistema podem ser salvos em arquivos e carregados na inicialização para garantir persistência entre execuções.

3. Arquivos
Aluno.h: Declaração da classe Aluno.
Gerenciador.h: Declaração da classe Gerenciador, que gerencia alunos, personais e planos.
Menu.h: Declaração da classe Menu, responsável pela interface de usuário.
Personal.h: Declaração da classe Personal, que representa um personal trainer.
Pessoa.h: Declaração da classe Pessoa, a classe base para alunos e personais.
Plano.h: Declaração da classe Plano, que representa um plano de assinatura na academia.

4. Como Compilar e Executar
 Certifique-se de ter um compilador C++ instalado (como g++).

Compile o projeto executando o comando:
g++ -o crud Pessoa.cpp Aluno.cpp Personal.cpp Plano.cpp Gerenciador.cpp Menu.cpp

Execute o programa com o comando:
./crud

5. Possíveis Melhorias Futuras
Implementar uma interface gráfica para o sistema.
Adicionar funcionalidades para gerenciar horários de aulas e disponibilidade de personal trainers.
Melhorar o sistema de persistência de dados, talvez utilizando um banco de dados.

6. Autores
Gabriel Henrique Cavalcante de Sousa
Maria Julia Leonella da Silva Carlos
Marina Gomes Gonçalves de Carvalho
