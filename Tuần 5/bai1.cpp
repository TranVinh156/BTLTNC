#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function
    int tmp_a = *a;
    int tmp_b = *b;
    *a = tmp_a + tmp_b;
    if (tmp_a > tmp_b)
    {
        *b = tmp_a - tmp_b;
        
    }
    else *b = tmp_b - tmp_a;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}