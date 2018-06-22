import math

def hitungUsed(m, g):
    if m > g:
        return (m*(m+1)//2) + ((m-g)*(m+g-1)//2)
    else:
        return m*(m+1)//2

def jwb(x, g):
    if x > g:
        return x + (x-g)
    else:
        return x

## MAIN PROGRAM
ans = 0
benteng = 0
N, H = raw_input().strip().split()
N = int(N)
H = int(H)

l = 1
r = pow(10,18)

while l<=r :
    m = (l+r)//2
    used = hitungUsed(m, H)    

    if used <= N:
        benteng = max(benteng, m)
        l = m+1
    else:
        r = m-1

N -= hitungUsed(benteng, H)

if N > 0:
    ans += N//benteng
        
    if N%benteng > 0:
        ans += 1

ans += jwb(benteng, H)
print(ans)