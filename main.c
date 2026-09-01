#include <stdio.h>

int main(void) {
  float X[] = {1.0f, 2.0f, 3.0f, 4.0f};
//  float x2[] = {2, 1, 0, 3};
  float y[] = {9, 8, 7, 18};
//  float w1 = 0.0f;
  float W[] = {0.0f, 0.0f};  
  float pred; 
  float loss; 
  float error; 
  float grad_pred;
  //float grad_w1;
  float grad_w; 
  float lr = 0.0005f;
  int epochs = 1000;
  float bias = 0.1f;
  float grad_bias;
  int n = 2;
  for (int epoch = 0; epoch < epochs; epoch++) {
    loss = 0.0f;
    // grad_w1 = 0.0f;
    grad_w = 0.0f;   
    grad_bias = 0.0f;

    for (int i = 0; i < n; i++) {
      pred = W[i] * X[i] + bias;
      error = pred - y[i];
      grad_pred = 2.0f * error;
      grad_w += grad_pred * X[i];
      // grad_w2 += grad_pred * x2[i];
      loss += error * error;
      grad_bias += grad_pred;
    }

    loss /= n;
    //grad_w1 /= n;
    grad_w /= n;
    grad_bias /= n;

    printf("loss = %f grad_w = %f epoch = %i bias = %f W[0] = %f\n", loss, grad_w, epoch, bias, W[0]);

    bias = bias - lr * grad_bias;
    //w1 = w1 - lr * grad_w1;
    for (int i = 0; i < n; i++) {
      W[i] = W[i] - lr * grad_w;
    }
  }
  return 0;
}
