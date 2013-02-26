#include <stdio.h>
change(int *x, int y){
    *x = y;
}
    

int main() {
    int x = 1;
    printf("%i\n", x);
    change(&x, 3);
    printf("%i\n", x);
}
    
