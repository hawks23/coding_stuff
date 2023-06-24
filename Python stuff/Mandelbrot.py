import numpy as np
import matplotlib.pyplot as plt

def mandelbrot(c):
    z = c
    n = 256
    for i in range(n):
        if abs(z) > 2:
            return i
        z = z*z + c
    return n

x = np.linspace(-2, 1, 300)
y = np.linspace(-1.5, 1.5, 200)

X, Y = np.meshgrid(x, y)
Z = X + 1j*Y
C = Z

M = np.zeros_like(C, dtype=int)
for i in range(C.shape[0]):
    for j in range(C.shape[1]):
        M[i,j] = mandelbrot(C[i,j])

plt.imshow(M, cmap='hot', extent=(x.min(), x.max(), y.min(), y.max()))
plt.show()
