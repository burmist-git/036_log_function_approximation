#include <math.h>
#include <iostream>
#include <stdio.h>

constexpr int LogPrecisionLevel = 12;
constexpr int LogTableSize = 1 << LogPrecisionLevel;

double log_table[LogTableSize];

void init_log_table() {
    for (int i = 0; i < LogTableSize; i++) {
        log_table[i] = log2(1 + (double)i / LogTableSize);
    }
}

double fast_log2(double x) { // x>0
    long long t = *(long long*)&x;
    int exp = (t >> 52) - 0x3ff;
    int mantissa = (t >> (52 - LogPrecisionLevel)) & (LogTableSize - 1);
    return exp + log_table[mantissa];
}

int main(int argc, char **argv) {

  const double xmin = 1.0e-3;
  const double xmax = 100.0;
  const unsigned int n = 10000;
  const unsigned int na = 2;  
  const double dx = (xmax - xmin)/n;
  const double dx_half = dx/2.0; 
  
  float x[n];
  float y[n][na];

  for(unsigned int i = 0;i<n;i++){
    x[i] = xmin + dx*i + dx_half;
    y[i][0] = log(x[i]);
    y[i][1] = 1.0/x[i];
  }

  /*
  //x
  printf("double x[%d] = {",n);
  for(unsigned int i = 0;i<n;i++){
    if(i<n-1)
      printf("%10.10f,",x[i]);
    else
      printf("%10.10f",x[i]);
  }
  printf("};");
  std::cout<<std::endl;
  */

  /*  
  //y
  printf("double y[%d][%d] = {",n,na);
  for(unsigned int i = 0;i<n;i++){
    if(i<n-1)
      printf("{%10.10f,%10.10f},",y[i][0],y[i][1]);
    else
      printf("{%10.10f,%10.10f}",y[i][0],y[i][1]);
  }
  printf("};");
  std::cout<<std::endl;
  */
  //////////////////////////////////////////

  init_log_table();
  
  //std::cout<<"LogPrecisionLevel "<<LogPrecisionLevel<<std::endl
  //	   <<"LogTableSize      "<<LogTableSize<<std::endl;

  printf("double log_table[%d] = {",LogTableSize);
  for(unsigned int i = 0;i<LogTableSize;i++){
    if(i<LogTableSize-1)
      printf("%10.10f,",log_table[i]);
    else
      printf("%10.10f",log_table[i]);
  }
  printf("};");
  std::cout<<std::endl;

  //////////////////////////////////////////
  
  return 0;
}
