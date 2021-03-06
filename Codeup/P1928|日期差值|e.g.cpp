//example
//本题运用的是最直接的思路，令日期不断加1，直到第一个日期等于第二个日期为止
//如果想要加快速度，见算法笔记P91，直接加年份至距离第二个日期年份差1，根据平闰加天数，然后再令日期不断加1
#include <cstdio>       //为了方便直接取出每个月的天数
int month[13][2] = {    //平年和闰年的每个月的天数,第二维为0时表示平年，为1时表示闰年
    {0, 0}, {31, 31}, {28, 29}, {31, 31}, {30, 30}, {31, 31}, {30, 30}, {31, 31}, {31, 31}, {30, 30}, {31, 31}, {30, 30}, {31, 31}
};

bool isLeap(int year) { //判断是否是闰年
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main() {
    int time1, y1, m1, d1;
    int time2, y2, m2, d2;
    while(scanf("%d%d", &time1, &time2) != EOF) {   //多点测试
        if(time1 > time2) {     //不妨假设第一个日期早于第二个日期，故若第一个日期晚于第二个日期，则交换
            int temp = time1;
            time1 = time2;
            time2 = temp;
        }
        y1 = time1 / 10000, m1 = time1 % 10000 / 100, d1 = time1 % 100;
        y2 = time2 / 10000, m2 = time2 % 10000 / 100, d2 = time2 % 100;
        int ans = 1;            //记录结果,注意这里初值设为1因为题设说明如果两个日期是连续的，则规定它们之间的天数为两天，依据现在的循环工作逻辑，体现在数值关系上就是要使ans初值为1
        //第一个日期没有达到第二个日期时进行循环
        //即!((y1 == y2) && (m1 == m2) && (d1 == d2))
        while(y1 < y2 || m1 < m2 || d1 < d2) {
            d1++;       //天数加1
            if(d1 == month[m1][isLeap(y1)] + 1) {       //满当月天数, +1勿落
                m1++;      //日期变为下个月的1号
                d1 = 1;
            }
            if(m1 == 13) {      //月份满12个月
                y1++;       // 日期变为下一年的1月
                m1 = 1;
            }
            ans++;          //天数差距累计！
        }
        printf("%d\n", ans);    //输出结果
    }
    return 0;
}
