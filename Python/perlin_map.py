import numpy as np
from PIL import Image

from perlin_noise import noise

width = 1920
height= 1080

height_map = noise(width, height, 10, 5)

img = np.zeros((height, width, 3), 'uint8')

for x in range(width):
    for y in range(height):
        if height_map[y, x] > 245:
            img[y, x] = (255, 255, 255)
        elif height_map[y, x] > 225:
            img[y, x] = (100, 100, 100)
        elif height_map[y, x] > 80:
            img[y, x] = (50, ((-(height_map[y, x] - 80) / (225-80)) + 1) * 200 + 50, 50)
        elif height_map[y, x] <= 80:
            img[y, x] = (50, 50, (height_map[y, x] / 80) * 150 + 100)

Image.fromarray(img).show()
