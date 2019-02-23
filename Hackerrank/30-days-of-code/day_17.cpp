// More Exceptions
#include <cmath>
#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;

//Write your code here
class negative_values_exception : public exception {
    // const char* what() const throw() {   // Even this one is correct, can use interchangeably
    const char* what() const noexcept {
        return "n and p should be non-negative";
    }
} negex;
class Calculator {
    public:
    int power(int n, int p) {
        if(n < 0 || p < 0) throw negex;
        if(p == 0) return 1;
        else if(p == 1) return n;
        else if(p % 2 == 0) return power(n * n, p / 2);
        else if(p % 2 == 1) return n * power(n * n, p / 2);
        return -1;
    }
};

int main()
{
    Calculator myCalculator=Calculator();
    int T,n,p;
    cin>>T;
    while(T-->0){
      if(scanf("%d %d",&n,&p)==2){
         try{
               int ans=myCalculator.power(n,p);
               cout<<ans<<endl;
         }
         catch(exception& e){
             cout<<e.what()<<endl;
         }
      }
    }

}