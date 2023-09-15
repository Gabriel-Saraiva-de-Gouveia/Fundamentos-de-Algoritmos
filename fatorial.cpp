#include <iostream>
#include "bscpp.hpp"
using namespace std;

int fatorial (int n){
    int fat;
    if(n == 0){
        fat = 1;
    }else{
        fat = n * fatorial(n-1);
    }
    return fat;
}
examples{
    check_expect(fatorial(4), 24);
    check_expect(fatorial(5), 120);
    check_expect(fatorial(6), 720);
    check_expect(fatorial(7), 5040);
    check_expect(fatorial(8), 40320);
    }
int main(){
    run_tests();
    }
