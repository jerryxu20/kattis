a, b, k = map(int, input().split())

# numbers between a and b that are palindromes in every base

st = set(range(a, b + 1))

def convert(num, base):
    ans = []
    if num == 0: return [0]
    while num > 0:
        ans.append(num % base)
        num //= base
    return ans
        
def pal(arr):
    low = 0
    high = len(arr) - 1
    while low < high:
        if arr[low] != arr[high]: return False
        low += 1
        high -= 1
    return True
for base in range(2, k + 1):
    st2 = set()
    for num in st:
        if pal(convert(num, base)):
            st2.add(num)
    st = st.intersection(st2)
    
    
print(len(st))