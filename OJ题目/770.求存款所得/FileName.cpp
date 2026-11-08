#include <stdio.h>

#define R3 0.0275  
#define R2 0.021   
#define R1 0.015   
int main() {
    int strategy;
    scanf_s("%d", &strategy);  

    double final_amount = 0.0;
    int is_valid = 1;  

    switch (strategy) {
    case 1:  
    {
        double p1 = 1000.0 * (1 + R3 * 3);  
        final_amount = p1 * (1 + R2 * 2);   
        break;
    }
    case 2:  
    {
        double p1 = 1000.0 * (1 + R2 * 2);  
        final_amount = p1 * (1 + R3 * 3);   
        break;
    }
    case 3:  
    {
        double p1 = 1000.0 * (1 + R1 * 1);  
        double p2 = p1 * (1 + R2 * 2);      
        final_amount = p2 * (1 + R2 * 2);   
        break;
    }
    case 4:  
    {
        double p1 = 1000.0 * (1 + R3 * 3);  
        double p2 = p1 * (1 + R1 * 1);      
        final_amount = p2 * (1 + R1 * 1);   
        break;
    }
    default:  
        is_valid = 0;
        break;
    }

    if (is_valid) {
        printf("%d\n", (int)final_amount);  
    }
    else {
        printf("error\n");
    }

    return 0;
}