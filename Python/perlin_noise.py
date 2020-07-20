from PIL import Image
import numpy as np
from random import randint

# perlin noise fade function
def fade(x):
    return (6 * x **5) - (15 * x ** 4) + (10 * x ** 3)

# linear interpolation with weighting
def lerp(a, b, weight):
    return (1 - weight) * a + (weight * b)

def noise(width, height, sub_w, sub_h):
    ''' returns a perlin noise height map with values from 0 to 255'''
    # create an array to store height values
    noise_array = np.zeros((height, width))

    # number of pixels in the height and width of one sub-box
    sub_x = width // sub_w
    sub_y = height // sub_h

    #creates random angles that are then used to generate the
    #random gradient vectors from the corners of each sub-box
    angles = 2*np.pi*np.random.rand(sub_h + 1, sub_w + 1)
    gradients = np.dstack((np.cos(angles), np.sin(angles)))

    # run through every pixel and decide height value
    for i in range(height):
        for j in range(width):
            # determines which box the pixel is in
            x_pos = j // sub_x
            y_pos = i // sub_y

            # uncertain
            x_vector = (j / sub_x) % 1
            y_vector = (i / sub_y) % 1

            # determines the weighting for the pixel in horizontal and vertical directions
            horizontal_weight = fade(x_vector)
            vertical_weight = fade(y_vector)

            # determines the gradient vectors
            gradient_vectors = []
            for dx, dy in [(0, 0), (0, 1), (1, 0), (1, 1)]:
                gradient_vectors.append(gradients[y_pos + dy, x_pos + dx, :])

            # determines the distance vectors (from the corners of the sub-box to the pixel)
            distance_vectors = []
            for xi, yi in [(0, 0), (0, -1), (-1, 0), (-1, -1)]:
                distance_vectors.append([x_vector + xi, y_vector + yi])

            # dot product between distance and gradient vectors
            dotted_vectors = []
            for grad, dist in zip(gradient_vectors, distance_vectors):
                dotted_vectors.append(grad.dot(dist))

            # lerps the vectors to achieve a value
            top_lerped_vector = lerp(dotted_vectors[0], dotted_vectors[2], horizontal_weight)
            bottom_lerped_vector = lerp(dotted_vectors[1], dotted_vectors[3], horizontal_weight)
            final_lerped_vector = lerp(top_lerped_vector, bottom_lerped_vector, vertical_weight)
            
	    #adds the height value to the noise_array
            noise_array[i, j] = final_lerped_vector

    #normalizes the noise array to the range 0-255
    noise_array -= noise_array.min()
    noise_array = (noise_array / noise_array.max() * 255).astype(np.uint8) 
    
    return noise_array

if __name__ == '__main__':
    Image.fromarray(noise(2000, 1000, 10, 5)).show()
    #Image.fromarray(land_map_from_height_map(perlin_noise(200, 100, 10, 5))).show()
