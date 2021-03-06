#include <cstdio>

int main() {
    int n, i = 0, a[5] = {0};
    scanf("%d", &n);
    if (n == 0) {
        printf("0\n");
        return 0;
    }
    while (n != 0) {
        a[i++] = n % 10;
        n /= 10;
    }
    for (int j = 0; j < a[2]; j++) {
        printf("B");
    }
    for (int j = 0; j < a[1]; j++) {
        printf("S");
    }
    for (int j = 1; j <= a[0]; j++) {
        printf("%d", j);
    }
    return 0;
}



//example
#include <cstdio>
int main() {
  int n;
  scanf("%d", &n);
  int num = 0, ans[5];      //num存放n的位数
  while(n != 0) {           //将n的每一位存放到ans数组中
    ans[num++] = n % 10;
    n /= 10;
  }
  for(int i = num - 1; i >= 0; i--) {     //从高位到低位枚举
    if(i == 2) {    //如果是百位
      for(int j = 0; j < ans[i]; j++) {
        printf("B");      //输出ans[i]个B
      }
    }
    else if(i == 1) {   //如果是十位
      for(int j = 0; j < ans[i]; j++) {
        printf("S");
      }
    }
    else {      //如果是个位
      for(int j = 1; j <= ans[i]; j++) {
        printf("%d", j);    //输出12...ans[i]
      }
    }
  }
  //printf("\n");
  return 0;
}
