#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

int rQueen; 
int cQueen;

int B[8] = {0, 0, 0, 0, 0, 0, 0 , 0};

enum { U, D, L, R, UR, DR, DL, UL };

int blocks(int r, int c) {
    if (r == rQueen) return c > cQueen ? R : L;
    if (c == cQueen) return r > rQueen ? U : D;
    if (abs(r - rQueen) == abs(c - cQueen)) {
        if (r < rQueen && c < cQueen) return DL;
        if (r < rQueen && c > cQueen) return DR;
        if (r > rQueen && c < cQueen) return UL;
        return UR;
    }
    return -1;
}

int main(){
    int n; 
    int k; 
    scanf("%d %d",&n,&k);
    scanf("%d %d",&rQueen,&cQueen);
    
    B[D]  = rQueen - 1;
    B[U]  = n - rQueen;
    B[L]  = cQueen - 1;
    B[R]  = n - cQueen;
    B[UL] = min(B[U], B[L]);
    B[UR] = min(B[U], B[R]);
    B[DL] = min(B[D], B[L]);
    B[DR] = min(B[D], B[R]);
    
    for(int a0 = 0; a0 < k; a0++){
        int rObstacle; 
        int cObstacle; 
        scanf("%d %d",&rObstacle,&cObstacle);
        int b = blocks(rObstacle, cObstacle);
        if (b != -1) {
            int nv = max(abs(rObstacle-rQueen), abs(cObstacle-cQueen)) - 1;
            if (nv < B[b]) B[b] = nv;
        }
    }
    int s = 0;
    for (int i = 0; i < 8; s += B[i++]) {}
    printf("%d\n", s);
    return 0;
}
