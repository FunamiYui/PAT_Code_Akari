//按列检查
//‘0’是空字符，空白符包括换行，空格等
#include <cstdio>
#include <iostream>
#include <string>           //cin.getline用不上，给getline用的
#include <cstring>
#include <algorithm>
using namespace std;

char str[110][260];

int main() {
    int n, minlen = 260, suffixlen = 0;                //minlen记录最短字符串的长度，后面遍历会用到
    bool flag = true;                                  //若发现公共后缀对不上了，就置flag为false
    scanf("%d", &n);
    getchar();                                         //后面不用scanf了，所以这里一定需要接收一下多余的换行符
    for (int i = 0; i < n; i++) {       //接收字符串的同时进行一些预处理
        cin.getline(str[i], 260);   //第三个参数是用于设定读到哪停，不填就默认换行符
        int len = strlen(str[i]);
        /*                              //fgets会连换行符一起收，所以不但要吧换行符换成空字符还要重新获取len值
        fgets(str[i], 260, stdin);      //不如就用getline了
        int len = strlen(str[i]);
        if (str[i][len - 1] = '\n') {
            str[i][len - 1] = '\0';
        }
        len--;
         */
        if (len < minlen) {
            minlen = len;
        }
        reverse(str[i], &str[i][len]);  //因为要求公共后缀，所以这里要反转对齐
    }
    for (int j = 0; j < minlen; j++) {          //i为行数，j为列数，这里是一列列按顺序检查
        for (int i = 0; i < n; i++) {
            if (str[i][j] != str[0][j]) {
                flag = false;
                break;
            }
        }
        if (!flag) {
            break;
        }
        suffixlen++;                //公共后缀长度
    }
    if (suffixlen == 0) {
        printf("nai\n");
    } else {
        for (int k = suffixlen - 1; k >= 0; k--) {      //因为反转了，所以要从高到低遍历输出
            printf("%c",str[0][k]);
        }
    }
    return 0;
}


//example
//scanf后欲接gets，中间必加getchar
//由于字符串中可能有空格，因此不要用scanf来读入字符串，因为scanf的%s格式是以空白符（包括空格）来进行截断的，这会造成字符串读入不完整
#include <cstdio>
#include <cstring>
int n, minlen = 260, ans = 0;     //minlen要合理赋初值, ans是公共前缀长度计数器
char s[100][260];     //至多100个字符串，每个字符串至多256个字符

int main() {
  scanf("%d", &n);    //n是字符串个数
  getchar();    //接收换行符，scanf后欲接gets，中间必加getchar
  for(int i = 0; i < n; i++) {
    //gets(s[i]);       //这里得用gets，具体见上方注释,但PAT里C++编译器没法用gets
    fgets(s[i], 260, stdin);              //PTA网站如果使用C++(g++)编译不能使用gets(),如果使用c(gcc)编译不能使用C++头文件
    if(s[i][strlen(s[i]) - 1] == '\n')    //此处需用fgets()替代gets()，并且把换行符去了，因为fgets()把换行符也接收了
      s[i][strlen(s[i]) - 1] = '\0';      //还能用cin.getline，有关getline的相关说明见我的tips文件夹
    int len = strlen(s[i]);
    if(len < minlen)
      minlen = len;       //取最小长度
    for(int j = 0; j < len / 2; j++) {      //反转字符串s[i]，转化为求公共前缀
      char temp = s[i][j];
      s[i][j] = s[i][len - 1 - j];
      s[i][len - 1 -j] = temp;
    }
  }
  for(int i = 0; i < minlen; i++) {       //判断所有字符串的第i个字符是否全部相等
    char c = s[0][i];     //取第一个字符串的第i个字符
    bool same = true;     //设置标记，并赋合理初值(设置标记很重要！要会用),用来当作判断条件
    for(int j = 1; j < n; j++) {      //判断其余字符串的第i个字符是否等于c
      if(s[j][i] != c) {        //只要有一个不等，就停止枚举，说明公共前缀到此为止
        same = false;
        break;
      }
    }
    if(same) {
      ans++;                  //若所有字符串的第i位相等，则计数器ans加1
    }
    else {
      break;
    }
  }
  if(ans) {
    for(int i = ans - 1; i >= 0; i--) {       //注意输出顺序(方向)，由于字符串是反转过的，所以相应地要进行方向上的调整(自行模拟)
      printf("%c", s[0][i]);
    }
  }
  else {
    printf("nai");      //不存在公共前缀
  }
  return 0;
}
