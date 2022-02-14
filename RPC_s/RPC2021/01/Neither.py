import sys
while True:
    try:
        a,n=tuple(map(int,input().split()))
        dos=0
        c=a
        cincos=0
        while(a%2==0):
            a//=2
            dos+=1
        while(a%5==0):
            a//=5
            cincos+=1
        if(n==0):
            print("0 1")
        elif(a!=1):
            print("Precision Error")
        else:
            dos*=n
            cincos*=n
            """
            if(dos==0 and cincos==0):
                print("0 1")
            elif (dos==cincos):
                print(str(dos) + " 1")
            elif(dos==0):
                print(str(cincos) + " " + str(2**cincos))
            elif(cincos==0):
                print(str(dos)+ " "+ str(5**dos))
            else:
            """
            if(dos>cincos):
                print(str(dos) + " "+ str(5**(dos-cincos)))
            else:
                print(str(cincos) + " "+ str(2**(cincos-dos)))

    except:
        break
