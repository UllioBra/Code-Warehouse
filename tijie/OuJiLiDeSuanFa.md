###### ~~7.31.2018修改~~
# 欧几里得算法
## 概念
> 在数学中,辗转相除法,又称欧几里得算法(英语：Euclidean algorithm),是求最大公约数的算法.
> 辗转相除法基于如下原理:两个整数的最大公约数等于其中较小的数和两数的差的最大公约数.
>两个数的最大公约数通常写成GCD(a, b),或者简写成(a, b) 
>(引自wikipidia)


## 实现
用伪代码描述
```
//gcd(x,y)
//(x>=y>0)
while x!=0&&y!=0
	z=x
	x=x mod y
	y=z
```
最后非零的就是要求的最大公约数了   
而在实际编程中,可以选择递归或者递推实现(~~我选择递归0-0~~)   
这是递归代码(cpp)   
```c++
int gcd(int x,int y) {
	if(y) {
		return gcd(y,x%y);
	}
	return x;
}
//你也可以选择这么写=v=
int gcd(int x,int y) {return y==0?x:gcd(y,x%y);}
```
## 证明$\gcd \left( x,y\right) =\gcd \left( y,x\% y\right)$($\gcd \left( x,y\right)$已知)
### 1.   
设$x=ay+r$
设$d=\gcd\left( x,y\right)$,$e=\gcd \left( y,r\right)$   
因为a为整数,x,y可以被d整除   
所以,**r可以被d整除**   
所以e只可能大于等于d   
假设e大于d   
因为有$x=ay+r$,且a为整数,y,r可以被e整除   
推出x可以被e整除   
与已知矛盾   
所以e==d    
得证

# 扩展欧几里得算法
## 概念
>扩展欧几里得算法（英语：Extended Euclidean algorithm）是欧几里得算法（又叫辗转相除法）的扩展。已知整数a、b，扩展欧几里得算法可以在求得a、b的最大公约数的同时，能找到整数x、y（其中一个很可能是负数），使它们满足贝祖等式
$ax + by = \gcd \left(a, b\right)$。
 (引自wikipidia)

## 实现&证明(求解和证明$ax+by=\gcd \left( a,b\right)$)
**(注意接下来的除法,均为舍去小数点后的整除)**   
对于 $a\%b$ ,我们可以用$a-\left( a/b\right) \ast c$ 去替代   
那么考虑gcd中的一步 $\gcd \left( m,n\right)$ 和下一步 $\gcd \left( n,m\%n\right)$    
假设有$nx+\left( n\% m\right) y= \gcd \left( m,n\right)$    
请思考上述方程与 $ mx_{1} + ny_{1} = \gcd \left( m , n \right) $ 之间的关系  
...........................................    
$\because a\%b = a - \left( a / b \right) \ast b$   
$\therefore nx+\left( n\% m\right) y=nx+my-\left( m/n\right) ny=my+n\left( x-\left( m/n\right) \ast y\right)$    
$\therefore \begin{cases} x_{1} = y\\ y_{1} = x - \left( m / n \right) \ast  y \end{cases} $   
就这样,我们通过一组现解得到了它之前的一组解   
**那如果知道了最后一步的方程的解,不就可以逆推回初始方程的解了吗....**   
............................................    
考虑求解 $ \gcd \left(a,b\right) $ 时的最后一步(即b为0时)      
有$\gcd \left(a,b\right) = \gcd\left(m,0\right) = m $   
考虑方程 $ mx + 0y = \gcd\left(a,b\right) $ ,它的一个可行解为 $ \begin{cases}x=1\\ y=1\end{cases} $   
然后我们就得到了我们需要的一组解,接下来就是逆推的过程了   
好了,逆推的过程在求gcd时可以一起完成
>~~题目不难,留给读者自行思考
(摘自算法导论)~~

```c++
int exGCD(int a,int b,int&x,int&y) {
	if(b==0) {
		x=1;
		y=0;
		return a;
	}
	int r=exGCD(b,a%b,x,y);
	int x1=y;
	y=x-(a/b)*y;
	x=x1;
}
```
## 之后
###### ~~这里就是各种乱搞的地方啦~~
### 1.证明当 $ a_{i} $ 和 $ x_{i} $ 均为整数时, $ a_{1}x_{1} + a_{2}x_{2} + \ldots +a_{n}x_{n} $的值一定为 $ \gcd \left( a_{1},a_{2}, \ldots ,a_{n} \right)$的整数倍
假设 $ a_{1}x_{1} + a_{2}x_{2} + \ldots +a_{n}x_{n} = \varphi $   且 $ \varphi $ 不为$ \gcd \left( a_{1},a_{2}, \ldots ,a_{n} \right)$的整数倍  
对上式两边同除以 $ \gcd \left( a_{1},a_{2}, \ldots ,a_{n} \right)$ ,显然左边为一个整数   
又因为右边不为一个整数,与等式矛盾   
所以 $ \varphi $ 为$ \gcd \left( a_{1},a_{2}, \ldots ,a_{n} \right)$的整数倍     

>[CF1010C](https://www.cnblogs.com/ullio/p/9393751.html)