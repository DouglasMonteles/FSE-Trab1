# Trabalho 1 - Fundamento de Sistemas Embarcados

## Como Executar

### Pré-Requisitos

- Clonar este projeto dentro de uma Raspberry PI;
- Possuir a lib `bcm2835` e `lwiringPi` instaladas;

### Compilação

- Utilize o `make` para compilar o projeto executando o seguinte comando na raiz do projeto:

```bash
# Elimina os binários de compilações anteriores
make clean

# Gera novos binários
make
```

### Executando o Servidor Distribuído

- Para facilitar a execução do servidor distribuído nas placas Raspberry PI, adicionei alguns comandos ao Makefile que executa o binário passando o respectivo arquivo de configuração para a sala em questão:

```bash
# Para a sala 01 
make run-distr-server FILE=configuracao_sala_01.sh

# Para a sala 02
make run-distr-server FILE=configuracao_sala_02.sh

# Para a sala 03 
make run-distr-server FILE=configuracao_sala_03.sh

# Para a sala 04
make run-distr-server FILE=configuracao_sala_04.sh
```

### Executando o Servidor Central

- Para facilitar a execução do servidor central nas placas Raspberry PI, adicionei alguns comandos ao Makefile que executa o binário passando o respectivo arquivo de configuração para a sala em questão:

```bash
# Para a sala 01 
make run-central-server FILE=configuracao_sala_01.sh

# Para a sala 02
make run-central-server FILE=configuracao_sala_02.sh

# Para a sala 03 
make run-central-server FILE=configuracao_sala_03.sh

# Para a sala 04
make run-central-server FILE=configuracao_sala_04.sh
```

Depois disso, o servidor central irá exibir um menu com as salas disponíveis e suas respectivas funcionalidades.

## Apresentação

<iframe width="1353" height="480" src="https://www.youtube.com/embed/j9pywNtLwbA" title="Apresentação FSE - Trabalho 1" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>