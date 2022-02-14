a, b = tuple(map(int, input().split()))
while(a or b):
    A = set(map(int, input().split()))
    B = set(map(int, input().split()))
    print(len(A-B), len(A&B), len(B-A), len(A|B))
    a, b = tuple(map(int, input().split()))
