#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <stdlib.h>

void w_str_buffer(unsigned char *buf, char *str) {
  int counter = 0;

  while (str[counter] != '\0') {
    *buf++ = str[counter];
    counter++;
  }
}

int main(int argc, char **argv) {
  int uart0_filestream = -1;

  uart0_filestream = open("/dev/serial1", O_RDWR | O_NOCTTY | O_NDELAY);

  if (uart0_filestream == -1) {
    printf("Erro na abertura da UART!\n");
    exit(1);
  }

  struct termios options;

  tcgetattr(uart0_filestream, &options);

  options.c_cflag = B115200 | CS8 | CLOCAL | CREAD;
  options.c_iflag = IGNPAR;
  options.c_oflag = 0;
  options.c_lflag = 0;

  tcflush(uart0_filestream, TCIFLUSH);
  tcsetattr(uart0_filestream, TCSANOW, &options);

  unsigned char tx_buffer[10];
  unsigned char *p_tx_buffer;

  p_tx_buffer = &tx_buffer[0];
  //w_str_buffer(p_tx_buffer, "Ola Mundo");

  *p_tx_buffer++ = 'T';
  *p_tx_buffer++ = 'E';
  *p_tx_buffer++ = 'S';
  *p_tx_buffer++ = 'T';
  *p_tx_buffer++ = 'E';

  printf("Escrevendo na UART...\n");

  int counter = write(uart0_filestream, &tx_buffer[0], (p_tx_buffer - &tx_buffer[0]));

  if (counter < 0) {
    printf("Erro no envio de dados - TX\n");
    exit(1);
  }

  sleep(1);

  unsigned rx_buffer[100];
  int rx_length = read(uart0_filestream, (void*) rx_buffer, 100);

  if (rx_length < 0) {
    printf("Erro na leitura da UART - RX\n");
    exit(1);
  }

  if (rx_length == 0) {
    printf("Nenhum dado disponivel\n");
    exit(0);
  }

  rx_buffer[rx_length] = '\0';

  printf("Mensagem de comprimento %d: %s\n", rx_length, rx_buffer);

  close(uart0_filestream);

  return 0;
}