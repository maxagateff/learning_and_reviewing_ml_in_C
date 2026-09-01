#include <stdio.h>

float fone(float x) {
  // float x = 3.0f;
  float result = x * x;
  //printf("result = %f\n", result);
  return result;
}

int main(void) {
  float x = 3.0f;
  float epsilon = 0.01f;
  float x_plus_epsilon = x + epsilon;
  float result = (fone(x_plus_epsilon) - fone(x - epsilon)) / (2 * epsilon);
  printf("result = %f\n", result);
  return 0;
}
