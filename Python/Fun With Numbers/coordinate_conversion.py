from math import sin, cos, sqrt

def cylindrical_to_cartesian(r, theta, z):
    return (r * cos(theta), r * sin(theta), z)

def spherical_to_cartesian(rho, theta, phi):
    return (rho * sin(phi) * cos(theta), rho * sin(phi) * sin(theta), rho * cos(phi))

if __name__ == "__main__":
    # TODO
    pass
