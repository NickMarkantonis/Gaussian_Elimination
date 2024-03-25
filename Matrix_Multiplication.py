# Nick Markantonis CSD5449  2/17/2024

def matrixMulti(A, B):
    if (len(A[0]) != len(B)):
        print("Mathematicall Error!")
        return 
    C = [[0 for _ in range(len(B[0]))] for _ in range(len(A))]
    for i in range(len(A)):
        for j in range(len(B[0])):
            for z in range(len(B)):
                C[i][j] += A[i][z] * B[z][j]
    return C
