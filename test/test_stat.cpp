#include "stat.h"

#include <iostream>

using namespace std;

const int N = 3;

int main()
{
statistic* ptr[N];
ptr[0] = new maxi;
ptr[1] = new mini;
ptr[2] = new ang;

double k = 0;
for(double i = 0; cin>>i;){
   ptr[0]->process(i);
   ptr[1]->process(i);
   ptr[2]->process(i);
}

for(int i = 0; i < N; i++)
  ptr[i]->result();   

return 0;
}
