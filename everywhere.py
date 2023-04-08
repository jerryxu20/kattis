n = int(input())

for _ in range(n):
    m = int(input())
    st = set()
    for _ in range(m):
        st.add(input())
        
    print(len(st))