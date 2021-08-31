#include <math.h>
#include <iostream>
#include <stdio.h>
#include "log_approx.h"

double culc_exp(int n, double val){
  double sum = 0.0;
  for (int i = 0;i<n;i++)
    sum += exp(val);
  return sum;
}

double culc_sqrt(int n, double val){
  double sum = 0.0;
  for (int i = 0;i<n;i++)
    sum += sqrt(val);
  return sum;
}

double culc_sin(int n, double val){
  double sum = 0.0;
  for (int i = 0;i<n;i++)
    sum += sin(val);
  return sum;
}

double culc_log(int n, double val){
  double sum = 0.0;
  for (int i = 0;i<n;i++)
    sum += log(val);
  return sum;
}

double culc_pow(int n, double val){
  double sum = 0.0;
  for (int i = 0;i<n;i++)
    sum += pow(val,2);
  return sum;
}

double culc_erf(int n, double val){
  double sum = 0.0;
  for (int i = 0;i<n;i++)
    sum += pow(val,5);
  return sum;
}

double culc_plus(int n, double val){
  double sum = 0.0;
  for (int i = 0;i<n;i++)
    sum += val + val;
  return sum;
}

double culc_mult(int n, double val){
  double sum = 0.0;
  for (int i = 0;i<n;i++)
    sum += val*val;
  return sum;
}

double culc_div(int n, double val){
  double sum = 0.0;
  for (int i = 0;i<n;i++)
    sum += val*val;
  return sum;
}

void test_char_pointer(char *c){
  printf("%s \n", c);
}

void test_function(int nn, double val, double (*functocall)(int,double), char *functocall_name){ 
  unsigned int n=100;
  double tottime = 0.0;
  for(int l=0;l<n;l++){
    clock_t tic = clock();
    double sum = (*functocall)(nn, val);
    clock_t toc = clock();
    tottime = tottime + (double)(toc - tic);
    //printf("sum: %f \n", sum);
  }
  printf("%10s --> Elapsed: %f seconds\n",functocall_name, tottime / CLOCKS_PER_SEC / n);
}

int main(int argc, char **argv) {

  double val = atof(argv[1]);
  double d1 = log(val);
  double d2 = log_approx(val);
  double d3 = fast_log(val);
  
  std::cout<<"d1      "<<d1<<std::endl
	   <<"d2      "<<d2<<std::endl
    	   <<"d3      "<<d3<<std::endl
	   <<"(d1-d2) "<<(d1-d2)<<std::endl
  	   <<"(d1-d3) "<<(d1-d3)<<std::endl;

  int n = 1000000;
  double vall =  0.123456789;

  test_function(n, vall, culc_plus, "culc_plus");
  test_function(n, vall, culc_mult, "culc_mult");
  test_function(n, vall, culc_div, "culc_div");
  test_function(n, vall, culc_sqrt, "culc_sqrt");
  test_function(n, vall, culc_sin, "culc_sin");  
  test_function(n, vall, culc_pow, "culc_pow");
  test_function(n, vall, culc_exp, "culc_exp");
  test_function(n, vall, culc_log, "culc_log");
  test_function(n, vall, culc_erf, "culc_erf");
  
  //test_char_pointer("ddd");
  
  return 0;
}
