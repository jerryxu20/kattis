a = input()
s = input()
openbrackets = "{[("
closebrackets = "]})"
op = {
    '{': '}',
    '[': ']',
    '(': ')'
}
stack = []
bad = False
for i in range(len(s)):
    if s[i] in openbrackets:
        stack.append(s[i])
    elif s[i] in closebrackets:
        if (len(stack) > 0 and op[stack[-1]] == s[i]):
            stack.pop()
            continue
        print(s[i], i)
        bad = True
        break
if not bad:
    print("ok so far")