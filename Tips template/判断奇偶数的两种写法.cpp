//常规写法
if(b % 2 == 1)	//奇数
if(b % 2 == 0)	//偶数

//用位与操作判断
if(b & 1)

//因为b & 1进行位与操作，判断b(二进制)的末位是否为1，因此当b为奇数时，b & 1返回1，if条件成立
//相比b为偶数时，b & 1返回的便是0了
//这样执行速度会快一点
