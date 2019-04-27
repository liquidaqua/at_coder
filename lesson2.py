N, A, B = list(map(int, input().split(' ')))

num = format(A ^ B, 'b').count('1')
if num > 2**N - 1 or num % 2 == 0:
    print('NO')
else:
    C = A ^ B
    c = format(A ^ B, 'b')
    p = list()
    p.append(A)
    for i in range(len(c)):
        if int(c[len(c)-1-i]) == 1:
            tmp = p[-1] ^ (C & (1 << i))
            p.append(tmp)
    for i in range(2**N-len(p)):
        p.append(p[-2])
    print('YES')
    for i in range(len(p)):
        print(p[i], end=' ')
    print(' ')
    for i in range(len(p)):
        print(format(p[i], 'b'), end=' ')
