//这里求a^b % m ，对问题本身有两种写法，对% m的运算也有两种做法
//对% m的第一种写法就是先算出a^b本身，再%m
//另一种嵌在下面两种对问题本身解法中，虽然我对这种做法的逻辑还不是很能理解

//第一种常规做法，没用二分幂，这种的时间复杂度为O(b)，在b大了之后不能接受
typedef long long LL;
LLpow(LL a, LL b, LL m) {
	LL ans = 1;
	for(int i = 0; i < b; i++) {
		ans = ans * a % m;
	}
	return ans;
}

//第二种时间复杂度O(logb)，采用快速幂的递归写法
typedef long long LL;
//求a^b % m，递归写法
LL binaryPow(LL a, LL b, LL m) {
	if(b == 0)
		return 1;		//如果b为0，那么a^0 = 1  这里是递归边界
	//b为奇数，转换为 b - 1
	if(b % 2 == 1)
		return a * binaryPow(a, b - 1, m) % m;
	else {		//b为偶数，转换为b / 2
		LL mul = binaryPow(a, b / 2, m);
		return mul * mul % m;
	}
}
