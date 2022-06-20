#include <vector>
#include <fstream>
#include <iostream>
#include <cmath>
double poisson(double mu, int k){
  return pow(mu,k)*exp(-mu)/tgamma(k+1);
}

int main(void){
std::vector<int> zaehler(11); 

std::ifstream fin("datensumme.txt");
std::ofstream fout("histpoi.txt");
int a;
while (fin >> a) {
  zaehler[a]+=1;
     }
  fin.close();
  for ( unsigned int k = 0 ; k < zaehler . size () ; ++ k ) {
  fout << k << " " << zaehler [ k ] << " " << poisson(3.11538, k)*234 << std :: endl ;
}
  return 0;
  }