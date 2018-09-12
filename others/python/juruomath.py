
def Mat_Mul(x, y, lex, ley):
    # Matrix multiplication
    """
        x : "The left Matrix" ,

        y : "The right Matrix" , 

        lex : "The size of 'x'.(It is a list)" , 

        ley : "The size of 'y'.(It is a list)" ,

    """
    c = [[0 for i in range(lex[0])] for j in range(ley[1])]
    for i in range(lex[0]):
        for j in range(ley[1]):
            for k in range(lex[1]):
                c[i][j] += x[i][k] * y[k][j]
    return c


def Fib(n):
    # Fibonacci sequence calculation
    """
        n : "The N-th term of the Fibonacci sequence" ,

    """
    if n <= 2:
        return 1
    n -= 2
    b = [[0, 1], [1, 1]]
    ans = [[1, 1], [0, 0]]
    while n:
        if n & 1:
            ans = Mat_Mul(ans, b, [2, 2], [2, 2])
        b = Mat_Mul(b, b, [2, 2], [2, 2])
        n >>= 1

    return ans[0][1]

def Euler(n):
    '''
        n : "The value of the Nth term of the Euler function" ,
    '''
