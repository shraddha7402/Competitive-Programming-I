#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int reg[10];
int ram[1000];
void init() {
int i;
for (i = 0; i < 10; i++) {
reg[i] = 0;
}
for (i = 0; i < 1000; i++) {
ram[i] = 0;
} 
}
void getop(int v, int *op1, int *op2) {
v = v % 100;
*op1 = v / 10;
*op2 = v - *op1 * 10;
}
void setv(int *p, int v) { *p = (v < 1000) ? v : v % 1000; }
int main() {
char buff[10];
int cases;
int n;
int *p;
int k;
int v;
int op1, op2;
fgets(buff, 10, stdin), sscanf(buff, "%d", &cases);
fgets(buff, 10, stdin);
while (cases-- > 0) {
init();
p = ram;
while (fgets(buff, 10, stdin) != NULL && strcmp(buff, "")) {
sscanf(buff, "%d", p);
p++;
}
for (n = 1, k = 0; (v = ram[k]) != 100; n++) { 
getop(v, &op1, &op2);
if (v < 100) {
if (*(reg + op2)) {
k = *(reg + op1);
continue;
}
} else if (v < 200) {
} else if (v < 300) {
setv(reg + op1, op2);
} else if (v < 400) {
setv(reg + op1, *(reg + op1) + op2);
} else if (v < 500) {
setv(reg + op1, *(reg + op1) * op2);
} else if (v < 600) {
*(reg + op1) = *(reg + op2);
} else if (v < 700) {
setv(reg + op1, *(reg + op1) + *(reg + op2));
} else if (v < 800) {
setv(reg + op1, *(reg + op1) * *(reg + op2));
} else if (v < 900) {
*(reg + op1) = *(ram + *(reg + op2));
} else {
*(ram + *(reg + op2)) = *(reg + op1);
}
k++;
}
printf("%d\n", n);
if (cases) {
putchar('\n');
}
}
return EXIT_SUCCESS;
} 