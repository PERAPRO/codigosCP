import sys

for line in sys.stdin:
    a, n  = map(int, line.split()) 
    exp = a
    
    fives = 0
    while exp % 5 == 0:
        exp /= 5
        fives += 1
      
    dos = 0
    while exp % 2 == 0:
        exp /= 2
        dos += 1

    if exp > 1 and n > 0:
      print("Precision Error")
      continue
    
    fives *= n
    dos *= n
    
    if fives > dos:
      ans = 2**(fives - dos)
    else:
      ans = 5**(dos - fives)
      
    # print("dos {} cincos {}".format(dos, fives))
    print(max(fives, dos), ans)