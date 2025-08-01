#include <stdio.h>

int main() {
    int num1, num2, sum;

    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    sum = num1 + num2;

    printf("Sum = %d\n", sum);
    displayDigit();
    return 0;
}
int displayDigit(){
    for(int i = 0; i < 4; i++){
     prinf("%d\n", i);

}
}
