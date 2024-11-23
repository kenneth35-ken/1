#include <stdio.h>      

int main() {
    int number;
    
    printf("Input an integer:");
    scanf("%d", &number);
    
    if(number >=1000){
        printf("Error! Limit reached\n");
     }else{
        
        if (number % 2 == 0){
            printf("The number is even.\n");
        }else{
            printf("The number iss odd.\n");
        }
     }

     if (number >= 1 && number <= 10){
        printf("The number is small.\n");
        
    }else if (number >= 11 && number <= 99){
        printf("The number is medium.\n");
        
    }else if (number == 999){
        printf("The number is large.\n");
    }else{
        printf("The number doesnt fall into a specified category\n");
    }
        
    
    return 0;
}