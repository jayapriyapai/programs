#include <iostream>
#include <conio.h>

using namespace std;

int main(){
    int n;
    cout<<"Enter n : ";
    cin>>n;
    int pascal[n][n];      
    
    for(int i=0;i<n;i++){
            /*initialize first column of every row to 1*/
            pascal[i][0]=1;
            for(int j=1;j<n;j++){
                    /*initialize rest of columns of every row to 0*/
                    pascal[i][j]=0;
            }
    }
    
    for(int i=1;i<n;i++){
            for(int j=1;j<=i;j++){
                    /*calculating value of each column by adding previous row's adjacent column values*/
                    pascal[i][j]=pascal[i-1][j-1]+pascal[i-1][j];
            }
    }
    
    for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                  /*print each column*/  
                  cout<<pascal[i][j]<<"\t"; 
                    
            }
            cout<<endl;       
    }
    
    getch();
    return 0;
}
