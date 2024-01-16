# following the demo on quantum teleportation by Xanadu at
# https://strawberryfields.ai/photonics/demos/run_teleportation.html

# import strawberryfields for quantum fun!
import strawberryfields as sf
from strawberryfields.ops import *

# import numpy for nicer calculations
import numpy as np
from numpy import pi, sqrt

# create a program with 3 registers
program = sf.Program(3, "teleportation!")

# create a state
a = 1+0.5j
r = np.abs(a)
theta = np.angle(a)

# begin the program!
with program.context as q: # q holds the registers, similar to a list
    # prepare initial states
    # registers/subsystems begin in a vacuum state, here we change them to 
    # coherent and squeezed states
    Coherent(r, theta) | q[0]
    Squeezed(-2) | q[1]
    Squeezed(2) | q[2]

    # apply beamsplitter (BS) gates
    BS = BSgate(pi/4, pi)
    BS | (q[1], q[2])
    BS | (q[0], q[1])

    # Perform homodyne measurements
    MeasureX | q[0]
    MeasureP | q[1]

    # Displacement gates conditioned on the measurements
    Xgate(sqrt(2) * q[0].par) | q[2]
    Zgate(-sqrt(2) * q[1].par) | q[2]


# prepare a backend engine to run the program
eng = sf.Engine('fock', backend_options = {"cutoff_dim": 15})

# run program 'program' with one measurement 
result = eng.run(program, shots=1, modes=None, compile_options={})

# view the results
print(result.samples)
print(result.state)
