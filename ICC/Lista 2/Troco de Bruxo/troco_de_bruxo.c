#include <stdio.h>

int main() {
    int vg, vs, vn, pg, ps, pn, rg, rs, rn, totalv, totalp, result;
    scanf("%d %d %d %d %d %d", &vg, &vs, &vn, &pg, &ps, &pn);
    totalp = pg * 493 + ps * 29 + pn;
    totalv = vg * 493 + vs * 29 + vn;
    result = totalp - totalv;
    if(result >= 493){
        rg = result/493;
        result = result%493;
    }
        else{
            rg = 0;
        }
    if(result >= 29){
        rs = result/29;
        result = result%29;
    }
        else{
            rs = 0;
        }
  
    rn = result;
    printf("Seu troco eh %d galeoes, %d sicles e %d nuques, Harry!", rg, rs, rn);
  
    return 0;
}
