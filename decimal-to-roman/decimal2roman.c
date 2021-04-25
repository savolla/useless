#include <stdio.h>

const char *roman = "IVXLCDM";
int max_int = 3999;

int readInt() {
  int value = 0;
  if (scanf("%d", &value) == 0) {
    char *chars;
    scanf("%s", chars);
  }
  return value;
}

char *convertNumber(int n, char *numeral, const char *roman) {
  if (n == 0) {
    return numeral;
  }

  int digit = n % 10;
  n /= 10;
  if (n != 0) {
    numeral = convertNumber(n, numeral, roman + 2);
  }

  if (digit == 9) {
    *numeral = *roman;
    *(numeral + 1) = *(roman + 2);
    numeral += 2;
  } else if (digit == 4) {
    *numeral = *roman;
    *(numeral + 1) = *(roman + 1);
    numeral += 2;
  } else {
    if (digit >= 5) {
      digit -= 5;
      *numeral = *(roman + 1);
      numeral++;
    }
    int i;
    for (i = digit; i > 0; i--) {
      *numeral = *roman;
      numeral++;
    }
  }
  return numeral;
}

void printNumberToRoman() {
  printf("Bir sayi giriniz: ");
  int n = readInt();
  char numeral[16];
  convertNumber(n, numeral, roman);
  printf("Girdiginiz sayinin Roman sayi karsiligi: %s\n", numeral);
}

int main(void) {
    printNumberToRoman();
    return 0;
}
