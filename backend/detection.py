import cv2
import numpy as np

def detect_colors(cube_image):
    # Define color ranges for each face of Rubik's Cube
    color_ranges = {
        "yellow": [(21, 150, 150), (30, 255, 255)],
        "green": [(50, 100, 100), (70, 255, 255)],
        "blue": [(110, 100, 100), (130, 255, 255)],
        "orange": [(0, 100, 100), (10, 255, 255)],
        "red": [(170, 100, 100), (180, 255, 255)],
        "white": [(0, 0, 150), (255, 30, 255)],
    }

    # Load the image and convert it to HSV color space
    img = cv2.imread(cube_image)
    hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)

    # Define the threshold for tile detection
    threshold = 100

    # Find the contours of the tiles in the image
    contours, hierarchy = cv2.findContours(cv2.inRange(hsv, (0, 0, 0), (255, threshold, 255)), cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

    # Sort the contours from top to bottom and left to right
    contours = sorted(contours, key=lambda c: (cv2.boundingRect(c)[1], cv2.boundingRect(c)[0]))

    # Define the positions of the tiles based on the contours
    positions = []
    for i in range(3):
        row = []
        for j in range(3):
            x, y, w, h = cv2.boundingRect(contours[i*3+j])
            row.append(((x, y), (x+w, y+h)))
        positions.append(row)

    # Detect the colors of each tile using color ranges and positions
    colors = []
    for row in positions:
        for pos in row:
            for color, (lower, upper) in color_ranges.items():
                color_mask = cv2.inRange(hsv[pos[0][1]:pos[1][1], pos[0][0]:pos[1][0]], lower, upper)
                if cv2.countNonZero(color_mask) > 100:
                    colors.append(color[0].upper())
                    break
            else:
                colors.append("X")

    # Return the matrix of the cube
    return np.array(colors).reshape(3, 3)

# Example usage
cube_face ='1.jpg'
print(detect_colors(cube_face))
