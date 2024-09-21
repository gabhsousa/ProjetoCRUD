Projeto de Gerenciamento de Academia<br/>
Este projeto é um sistema de gerenciamento de academia implementado em C++. Ele permite o cadastro e gerenciamento de alunos, personais e planos, além de fornecer relatórios sobre os dados do sistema. O projeto é modular, com classes que representam os diferentes atores e funcionalidades da academia, como alunos, personais, planos e gerenciamento de dados.

Estrutura do Projeto
1. Classes<br/>

Pessoa<br/>
A classe Pessoa é uma classe base que serve para representar características comuns entre alunos e personais, como nome, CPF, telefone, idade e email.

Aluno<br/>
A classe Aluno herda de Pessoa e Plano, e representa um aluno da academia. Possui atributos específicos, como altura, peso e matrícula, além de métodos para calcular o Índice de Massa Corporal (IMC) e gerar a matrícula do aluno.

Personal<br/>
A classe Personal também herda de Pessoa, e representa um personal trainer da academia. Possui atributos como o CREF (registro profissional) e o salário.

Plano<br/>
A classe Plano é responsável por gerenciar os dados dos planos de assinatura da academia, como nome do plano, período, valor, status de pagamento, data de início e data de pagamento.

Gerenciador<br/>
A classe Gerenciador atua como uma camada de controle do sistema. Ela mantém listas de alunos, personais e planos, além de fornecer métodos para realizar operações de cadastro, listagem, alteração e remoção desses elementos. Também é responsável por salvar e carregar os dados do sistema de/para arquivos e gerar relatórios gerais.

Menu<br/>
A classe Menu é responsável pela interação com o usuário. Ela exibe o menu principal e os submenus, e faz chamadas para os métodos da classe Gerenciador conforme as opções selecionadas.

2. Funcionalidades<br/>

Cadastro<br/>
O sistema permite o cadastro de novos alunos, personais e planos. Os dados são validados e armazenados no sistema.

Listagem<br/>
É possível listar todos os alunos, personais e planos cadastrados no sistema.

Alteração e Remoção<br/>
O sistema permite alterar os dados dos alunos, personais e planos, além de possibilitar a remoção desses registros.

Pagamento<br/>
Há uma funcionalidade específica para marcar o pagamento do plano de um aluno, ajustando a data de início do plano de acordo com a data do pagamento.

Relatório<br/>
O sistema gera um relatório geral, que calcula a renda total da academia com base no número de alunos inscritos em cada plano e no valor de cada plano.

Salvamento e Carregamento de Dados<br/>
Os dados do sistema podem ser salvos em arquivos e carregados na inicialização para garantir persistência entre execuções.

3. Arquivos<br/>

Aluno.h: Declaração da classe Aluno.<br/>
Gerenciador.h: Declaração da classe Gerenciador, que gerencia alunos, personais e planos.<br/>
Menu.h: Declaração da classe Menu, responsável pela interface de usuário.<br/>
Personal.h: Declaração da classe Personal, que representa um personal trainer.<br/>
Pessoa.h: Declaração da classe Pessoa, a classe base para alunos e personais.<br/>
Plano.h: Declaração da classe Plano, que representa um plano de assinatura na academia.<br/>

4. Como Compilar e Executar<br/>

Certifique-se de ter um compilador C++ instalado (como g++).

Compile o projeto executando o comando:<br/>
g++ -o crud Pessoa.cpp Aluno.cpp Personal.cpp Plano.cpp Gerenciador.cpp Menu.cpp

Execute o programa com o comando:<br/>
./crud

5. Possíveis Melhorias Futuras<br/>

Implementar uma interface gráfica para o sistema.<br/>
Adicionar funcionalidades para gerenciar horários de aulas e disponibilidade de personal trainers.<br/>
Melhorar o sistema de persistência de dados, talvez utilizando um banco de dados.<br/>

6. Autores<br/>

Gabriel Henrique Cavalcante de Sousa<br/>
Maria Julia Leonella da Silva Carlos<br/>
Marina Gomes Gonçalves de Carvalho<br/>
