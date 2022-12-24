#include <stdio.h>
#include <stdlib.h> // For malloc
#include <math.h> // NEED TO LINK WITH -lm

int str_len(char *str) {
  int length = 0;
  while (str[length] != '\0') length++;
  return length;
}

int *byte_from_str(char *str, int start, int end) {
  int *byte_arr = (int *) malloc(sizeof (int) * 8);
  for (int i = start; i < end; i++) {
    byte_arr[i % 8] = str[i] - '0';
  }
  return byte_arr;
}

void print_byte(int *byte) {
  printf("[");
  for (int i = 0; i < 8; i++) {
    printf(i == 7 ? "%d" : "%d,", byte[i]); 
  }
  printf("]\n");
}

int seg_to_ascii(int *seg) {
  int ascii_code = 0;
  for (int p = 7; p >= 0; p--) {
    ascii_code += seg[7 - p] * (int) pow(2, p);
  }
  return ascii_code;
}

size_t num_bytes(char *str) {
  return (size_t) str_len(str) / 8;
}

char *str_from_bin(char *bin_str) {
  char *ascii_str = (char *) malloc(sizeof(char) * num_bytes(bin_str));
  for (int i = 0; i < str_len(bin_str); i += 8) {
    int *segment = byte_from_str(bin_str, i, i+8);
    char character = (char) seg_to_ascii(segment);
    ascii_str[i / 8] = character;
  }
  return ascii_str;
}

int main(void) {
  char *str = "010000010100001001000011";
  char *ascii_str = str_from_bin(str);
  printf("%s\n", ascii_str);
  return 0;
}
