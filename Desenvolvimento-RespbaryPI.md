# Desenvolvimento RaspBerry PI

## Acesso via SSH

```bash
ssh <usuario>@<endereco_ip>
ssh douglasmonteles@192.168.0.1
senha: sua_matricula
```

## Cópia de arquivos remotos via SSH

```bash
scp <caminho local>
<usuario>@<endereco_ip>:<caminho remoto>

scp arquivo1.txt aluno@192.168.0.7:/home/aluno
```

## Cross-compiler no Linux (64 bits)

- Na pasta `rpi/tools/arm-bcm2708` encontra-se o diretório:

  ```bash
  gcc-linaro-arm-linux-gnueabihf-raspbian-x64
  ```

- Para compilar no linux:
  ```bash
  cd ~/

  nano .bashrc

  # Adicionar a linha abaixo no final do arquivo:
  export PATH=$PATH:$HOME/rpi/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian-x64/bin

  # Carregar as novas configurações
  source .bashrc
  ```

- Para testar o compilador
  
  ```bash
  arm-linux-gnueabihf-raspbian-x64 -v
  ```

## Utilizando o docker para compilar

```bash
# Pull the image
docker pull mitchallen/pi-cross-compile

# Clone my Raspberry Hello demo
mkdir ~/raspberry

cd ~/raspberry

git clone https://github.com/mitchallen/pi-hello-cross-compile.git --depth=1 hello

# Build the demo
docker run -it -v ~/raspberry/hello:/build mitchallen/pi-cross-compile

ls -l ~/raspberry/hello/bin/hello

file ~/raspberry/hello/bin/hello
```

A saída deve ser algo assim:

```bash
bin/hello: ELF 32-bit LSB executable, ARM, version 1 (SYSV), dynamically linked (uses shared libs), for GNU/Linux 2.6.26, not stripped
```

## Copiando o executável para o Raspberry PI

```bash
# Abrindo a conexão
ssh pi@192.168.0.51

# Copiando o executável
scp bin/hello pi@192.168.0.51:~/fse

# Se precisar informar a porta
scp -P 13508 hello/bin/hello  douglasmonteles@164.41.98.16:~/teste

#Executando
./hello
```

Fonte: <https://desertbot.io/blog/how-to-cross-compile-for-raspberry-pi>

## Acendendo a Lâmpada da Sala

```bash
douglasmonteles@rasp42:~$ echo "18" > /sys/class/gpio/export 
douglasmonteles@rasp42:~$ echo "out" > /sys/class/gpio/gpio
gpio18/      gpiochip0/   gpiochip504/ 
douglasmonteles@rasp42:~$ echo "out" > /sys/class/gpio/gpio18/direction 
douglasmonteles@rasp42:~$ echo "1" > /sys/class/gpio/gpio18/value 
douglasmonteles@rasp42:~$ echo "0" > /sys/class/gpio/gpio18/value
```

### Lendo o valor da entrada

```bash
douglasmonteles@rasp42:~$ echo "in" > /sys/class/gpio/gpio18/direction 
douglasmonteles@rasp42:~$ echo $(< "/sys/class/gpio/gpio18/value")
```

