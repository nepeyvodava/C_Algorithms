/*
 * lesson1.c
 *
 * Created by Vladimir Nepeyvoda
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define true 1
#define false 0

typedef int boolean;

/*
1. Рассчитать и вывести индекс массы тела по формуле I = m / (h * h), где m – масса тела в килограммах, h – рост в метрах.
2. Написать программу нахождения корней заданного квадратного уравнения.
3. Ввести возраст человека (от 1 до 150 лет) и вывести его вместе со словом «год», «года» или «лет».
4. Даны числовые координаты двух полей шахматной доски (x1, y1, x2, y2). 
Требуется определить, относятся ли к поля к одному цвету или нет.
5. * Автоморфные числа. Натуральное число называется автоморфным, если оно равно последним цифрам своего квадрата. 
Например, 25 ^ 2 = 625. Напишите функцию, которая выводит на экран все автоморфные числа, меньше десяти тысяч
*/

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
char* ageAdder(int a) {
  int t = a % 100;
  int b = t % 10;
  if ((t != 11) && (b == 1)) {
    return "год";
  } else if (((b > 1) && (b < 5)) && 
                ((t > 14) || (t < 11))) {
    return "года";
  } else {
    return "лет";
  }
}

// 4. Даны числовые координаты двух полей шахматной доски (x1, y1, x2, y2). 
// Требуется определить, относятся ли к поля к одному цвету или нет.
boolean areSame(int x1, int y1, int x2, int y2) {
  return (x1 + y1 + x2 + y2) % 2 == 0;
}

// 5. * Автоморфные числа. Натуральное число называется автоморфным, если оно равно последним цифрам своего квадрата. 
// Например, 25 ^ 2 = 625. Напишите функцию, которая выводит на экран все автоморфные числа, меньше десяти тысяч
boolean isAutomorphic(num) {
  int sqrtNum = num * num - num;
  int tmp = num;
  int res = 0;
  do {
    res += sqrtNum % 10;
    sqrtNum /= 10;
  } while ((tmp /= 10) != 0);
  return res == 0;
}

int main(int argc, const char** argv) {
  // averageFix();
  
  // 1
  // printf("%.2f\n", BMI(63, 1.69));

  // 2
  // qEquation(20.9, 35.8, 6);

  // 3
  // int age = 111;
  // printf("Возраст %d %s\n", age, ageAdder(age));

  // 4
  // printf("Colors are %s \n", areSame(1, 2, 7, 8) ? "same" : "different");
  
  // 5
  // for (int num = 0; num < 10000; num++){
  //   if (isAutomorphic(num))
  //     printf("Number %d is automorphic to %d\n", num, num*num);
  // }
  
  return 0;
}