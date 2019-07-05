/*
 * lesson1.c
 *
 * Created by Vladimir Nepeyvoda
 * 
 */

/*
1. Рассчитать и вывести индекс массы тела по формуле I = m / (h * h), где m – масса тела в килограммах, h – рост в метрах.
2. Написать программу нахождения корней заданного квадратного уравнения.
3. Ввести возраст человека (от 1 до 150 лет) и вывести его вместе со словом «год», «года» или «лет».
4. Даны числовые координаты двух полей шахматной доски (x1, y1, x2, y2). 
Требуется определить, относятся ли к поля к одному цвету или нет.
5. * Автоморфные числа. Натуральное число называется автоморфным, если оно равно последним цифрам своего квадрата. 
Например, 25 ^ 2 = 625. Напишите функцию, которая выводит на экран все автоморфные числа, меньше десяти тысяч
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Задание с урока.
void average() {
  int counter = 0;
  float sum = 0;
  int in;
  do {
	scanf("%d", &in);
	if (in == -1) break; // <-- this is very very wrong))))))
	sum += in;
	counter++;
  } while (in != -1);
  if (counter != 0) {
	printf("mean = %.2f\n", (float)(sum / counter));
  } else {
	printf("%s\n", "No input");
  }
}

void averageFix() {
  int counter = 0;
  float sum = 0;
  int in = 0;
  do {
	sum += in;
	counter++;
  scanf("%d", &in);
  } while (in != -1);
  if (--counter != 0) {
	printf("mean = %.2f\n", (float)(sum / counter));
  } else {
	printf("%s\n", "No input");
  }
}

// 1. Рассчитать и вывести индекс массы тела по формуле I = m / (h * h), где m – масса тела в килограммах, h – рост в метрах.
float BMI(float m, float h) {
  return m / (h * h);
}

// 2. Написать программу нахождения корней заданного квадратного уравнения. a*x^2 + b*x + c = 0
void qEquation(float a, float b, float c) {
  if (a != 0){
    float d = b*b - 4*a*c;
    if (d < 0) {
      printf("%s\n", "There are no real roots");
    } else if (d > 0){
      float x1 = (-b + sqrt(d)) / (2 * a);
      float x2 = (-b - sqrt(d)) / (2 * a);
      printf("x1 = %.2f, x2 = %.2f\n", x1, x2);
    } else if (d == 0) {
      float x = -b / (2 * a);
      printf("x = %.2f\n", x);
    }
  } else {
    printf("%s\n", "This is not quadratic equation");
  }
}

// 3. Ввести возраст человека (от 1 до 150 лет) и вывести его вместе со словом «год», «года» или «лет».
void printAge(int a) {
  int t = a % 100;
  int b = t % 10;
  if ((t < 11) || (t > 14)) {
    switch (b) 
    {
      case 1:
        printf("Возраст %d год\n", a);
        break;
      case 2:
        printf("Возраст %d года\n", a);
        break;
      case 3:
        printf("Возраст %d года\n", a);
        break;
      case 4:
        printf("Возраст %d года\n", a);
        break;
      default:
        printf("Возраст %d лет\n", a);
        break;
    }
  } else {
    printf("Возраст %d лет\n", a);
  }
}

// 4. Даны числовые координаты двух полей шахматной доски (x1, y1, x2, y2). 
// Требуется определить, относятся ли к поля к одному цвету или нет.
void chess(int x1, int y1, int x2, int y2) {
  int res = (x1 + y1 + x2 + y2) % 2;
  if (res == 0) {
    printf("True\n");
  } else {
    printf("False\n");
  }
}

// 5. * Автоморфные числа. Натуральное число называется автоморфным, если оно равно последним цифрам своего квадрата. 
// Например, 25 ^ 2 = 625. Напишите функцию, которая выводит на экран все автоморфные числа, меньше десяти тысяч
void printAutomorphic() {
  int num = 0;
  while(num < 10000) {
    int sqrtNum = num * num - num;
    int tmp = num;
    int res = 0;
    do {
      res += sqrtNum % 10;
      sqrtNum /= 10;
    } while ((tmp /= 10) != 0);

    if (res == 0) {
      printf("%d; ", num);
    }
    num++;
  }
}

int main(int argc, const char** argv) {
  // averageFix();
  // printf("%.2f\n", BMI(63, 1.69));
  // qEquation(20.9, 35.8, 6);
  // printAge(13);
  // chess(1, 2, 7, 8);
  // printAutomorphic();
  return 0;
}