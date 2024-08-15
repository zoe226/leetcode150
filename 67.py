def addBinary(a: str, b: str) -> str:
    idx_a = len(a) - 1
    idx_b = len(b) - 1
    c = 0
    s = ''
    st = []
    while idx_a >= 0 and idx_b >= 0:
        temp = chr((ord(a[idx_a]) - ord('0') + ord(b[idx_b]) - ord('0') + c) % 2 + ord('0'))
        c = (ord(a[idx_a]) - ord('0') + ord(b[idx_b]) - ord('0') + c) // 2
        st.append(temp)
        idx_a -= 1
        idx_b -= 1
    while idx_a >= 0:
        temp = chr((ord(a[idx_a]) + c) % 2 + ord('0'))
        c = (ord(a[idx_a]) - ord('0') + c) // 2
        st.append(temp)
        idx_a -= 1
    while idx_b >= 0:
        temp = chr((ord(b[idx_b]) + c) % 2 + ord('0'))
        c = (ord(b[idx_b]) - ord('0') + c) // 2
        st.append(temp)
        idx_b -= 1
    if c > 0:
        st.append(chr(c + ord('0')))
    while st:
        s += st.pop()
    return s
a = "1010"
b = "1011"
addBinary(a,b)