#include <stdio.h>

enum state {In, Out};
typedef enum state State;

int main() {
    State s = Out;
    int nc = nl = nw = 0;
    char c;

    while((c = getchar()) != EOF) {
        ++nc;
        switch(c) {
            case '\n':
                ++nl;
                s = Out;
            break;
            case '\t':
                s = Out;
            break;
            case ' ':
                s = Out;
            break;
            default:
                if (s == Out) {
                    ++nw;
                    s = In;
                }
            break;
        }
    }

    printf("%d %d %d \n", nl, nw, nc);
}