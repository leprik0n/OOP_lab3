#include "stat.h"

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void maxi::process(double item){
     vec1.push_back(item);
}

void mini::process(double item){
     vec2.push_back(item);
}

void ang::process(double item){
     vec3.push_back(item);
}

void maxi::result(){
     sort(vec1.begin(),vec1.end());
     cout<<"max = "<<vec1[vec1.size()-1]<<endl;
}

void mini::result(){
     sort(vec2.begin(),vec2.end());
     cout<<"min = "<<vec2[0]<<endl;
}

void ang::result(){
     int sum = 0;
     int k = 0;
     for(int i = 0; i < vec3.size(); ++i){
         sum += vec3[i];
         ++k;
     }
     sum /= k;
cout<<"sum/n = "<<sum<<endl;
}
