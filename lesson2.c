/*
 * lesson2.c
 *
 * Created by Vladimir Nepeyvoda
 * 
 */

#include <stdio.h>
#include <stdlib.h>

// 1 Реализовать функцию перевода из 10 системы в двоичную используя рекурсию.
int decToBin(int d) {
  if (d == 1) return 1;
  if (d % 2) return 1 + decToBin(d >> 1) * 10;
  return decToBin(d >> 1) * 10;
}

// 2. Реализовать функцию возведения числа a в степень b:
  // a. рекурсивно;
double power(double a, int b) {
  if (b == 0) return 1;
	return a * power(a, b - 1);
}
 	//  b. *рекурсивно, используя свойство чётности степени.
double powerFast(double a, int b) {
  if (b == 0) return 1;
  if (b % 2) return a * powerFast(a, b - 1);
  return powerFast(a * a, b / 2);
}

/* 3. Программа преобразует целое число. У программы две команды:
  	  	  Прибавь 1
  	  	  Умножь на 2
	Сколько существует путей для данной программы, которые число 3 преобразуют в число 20? Решить с использованием рекурсии. */
int paths = 0;

void path(int from, int to){
  if (from == to) paths++;
  if (from < to) path(from + 1, to);
  if (from * 2 <= to) path(from * 2, to);
}

int main(int argc, const char** argv) {
  //1
  // printf("%d\n", decToBin(21));

  // 2.
  // int a = 6;
  // int b = 32;
  // printf("%0.f\n", power(a, b));
  // printf("%0.f\n", powerFast(a, b));

  // 3.
  // path(3, 20);
  // printf("Paths: %d\n", paths);

  return 0;
}