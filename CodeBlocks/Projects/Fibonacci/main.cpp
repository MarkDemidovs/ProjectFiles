#include <iostream>

//int num1 = 0;
//int num2 = 1;
int result = 0;
int timesDone = 0;

int recursionFibonacci(int num1, int num2) {
    if (timesDone <=19) {
        result = num1+num2;
        std::cout << result << '\n';
        num2=num1;
        num1=result;
        timesDone++;
        recursionFibonacci(1,0);
    }

}

int main()
{  /*  while (timesDone <= 18) {
        std::cout << fibonacci() << std::endl;
        timesDone++;
    }*/

    //forLoopFibonacci();

    recursionFibonacci(1,0);

    return 0;
}











/*int forLoopFibonacci() {
    for(int i=0; i<=38; i++) {
            result = num1 + num2;
            num1=num2;
            num2=result;
            i++;
            std::cout << num2 << std::endl;

    }
    return result;
}


int fibonacci() {
    result = num1 + num2;
    num1=num2;
    num2=result;

    return result;
}
*/
