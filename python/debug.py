import numpy as np

# 创建矩阵
A = np.array([[1, 2, 3],
              [4, 5, 6],
              [7, 8, 9]])

B = np.array([[9, 8, 7],
              [6, 5, 4],
              [3, 2, 1]])

# 矩阵相加
C = A + B
print("矩阵相加：")
print(C)

# 矩阵相减
D = A - B
print("矩阵相减：")
print(D)

# 矩阵乘法
E = np.dot(A, B)
print("矩阵乘法：")
print(E)

# 矩阵转置
F = np.transpose(A)
print("矩阵转置：")
print(F)

# 矩阵求逆
G = np.linalg.inv(A)
print("矩阵求逆：")
print(G)
