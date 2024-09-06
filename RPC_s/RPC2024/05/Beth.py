n = int(input())

s = input()

new_s = ""

i = 0
while i + 1 < n:
    if s[i] == '(' and s[i + 1] == ')':
        new_s += s[i]
        new_s += '1'
        # new_s += s[i + 1]
        # i+=2;
    elif s[i] == ')' and s[i + 1] == ')':
        new_s += s[i]
        new_s += '+1'
        # new_s += s[i + 1]
        # i+=3;
    elif s[i] == ')' and s[i + 1] == '(':
        new_s += s[i]
        new_s += '*'
        # new_s += s[i + 1]
        # i+=2;
    else:
        new_s += s[i] 
    i+=1
new_s += s[n- 1]       
print(eval(new_s))
        