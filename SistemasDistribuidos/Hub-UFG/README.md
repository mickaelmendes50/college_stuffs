# Hub UFG
## Descrição do Projeto
Tanto a Universidade quanto os Alunos e Movimentos Estudantis (CA's, DCE, etc) realizam eventos, conferências, projetos e oferecem assistência aos alunos. Cada entidade possui seu próprio veículo oficial de informação, seja um site proprietário ou em uma rede social, o que exige que os estudantes estejam sempre atentos a diversos canais para se manter atualizados com o que acontece na Universidade. Visando resolver isso, o Hub UFG tem a missão de centralizar essas informações em um único lugar, o corpo de um email, que será enviado aos emails cadastrados na plataforma.

O objetivo do seguinte projeto é a implementação de um serviço de Newsletter para o público acadêmico da UFG, em especial os alunos, de forma que esses podem receber as informações pertinentes no e-mail que escolherem.

## Análise de Requisitos
O produto consiste em uma aplicação web em que as pessoas irão cadastrar o email de sua preferência para receber emails contendo os links para as principais notícias referentes à Universidade e Movimentos Estudantis.

Foi realizado o levantamento dos requisitos para o projeto.
Como **requisitos funcionais** foram identificados:

- Realizar login com chave de acesso corporativo único (email) e senha.
- Campo para escrever o email que será enviado aos emails cadastrados.
- Campo para cadastrar email para o recebimento dos emails de notícias.

Como **requisitos não funcionais** foram identificados:
- O produto final será um sistema Web.
- O produto deverá utilizar o padrão arquitetural Publish-Subscribe

## Especificações e Cronograma de Desenvolvimento
- Disponíveis no [Trello](https://trello.com/b/3sHKeKhe/projeto-hub-ufg).

## Arquitetura
Com uma arquitetura de microsserviços, um aplicativo é criado como componentes independentes que executam cada processo do aplicativo como um serviço. Esses serviços se comunicam por meio de uma interface bem definida usando APIs leves. Os serviços são criados para recursos empresariais e cada serviço realiza uma única função. Como são executados de forma independente, cada serviço pode ser atualizado, implantado e escalado para atender a demanda de funções específicas de um aplicativo.

Padrão arquitetural onde tem os Publishers (Publicadores) que enviam as mensagens e os Subscribers (Assinantes) que recebem as mensagens. Em uma maneira mais prática, sempre que houver algum evento, o publicador vai enviar uma mensagem para que seus ouvintes sejam notificados. Ou seja, existe um publicador, que vai enviar uma mensagem em um canal (Bus). O Canal redistribui uma cópia da mensagem para cada subscriber.

<img src="https://github.com/SD-20221-2/Time-6-HUB-UFG/blob/main/Hub-UFG/docs/arch/arch-hub.png" alt="drawing" width="700"/>

## Modelo Entidade-Relacionamento
Será utilizado o PostgreSQL como Banco de Dados da Aplicação

<img src="https://github.com/SD-20221-2/Time-6-HUB-UFG/blob/main/Hub-UFG/docs/mer/mer-hub.png" alt="drawing" width="450"/>

## Wireframe
<p align="left"> 
  <img src="https://github.com/SD-20221-2/Time-6-HUB-UFG/blob/main/Hub-UFG/docs/wireframe/page-01.jpg" alt="drawing" width="300"/>
  <img src="https://github.com/SD-20221-2/Time-6-HUB-UFG/blob/main/Hub-UFG/docs/wireframe/page-02.jpg" alt="drawing" width="300"/>
  <img src="https://github.com/SD-20221-2/Time-6-HUB-UFG/blob/main/Hub-UFG/docs/wireframe/page-03.jpg" alt="drawing" width="300"/>
</p>
