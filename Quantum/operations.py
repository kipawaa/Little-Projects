import numpy as np

CNOT = np.matrix('1 0 0 0; 0 1 0 0; 0 0 0 1; 0 0 1 0')
H = 1 / np.sqrt(2) * np.matrix('1 1; 1 -1')
X = np.matrix('0 1; 1 0')
#Y = np.matrix('0 -i; i 0')
Z = np.matrix('1 0; 0 -1')
