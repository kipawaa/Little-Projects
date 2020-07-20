from graphics import *
from random import randint

#allows drawing rectangles for the 'visualize' funtion
def drawRect(x, y, width, length, colour):
    shape = Rectangle(Point(x, y), Point(x+width, y+length))
    shape.setFill(colour)
    shape.setOutline('')
    return shape

#generates maps with heights based upon the 'start' variable and the 'variance' variable
def basicMap(width, height, start, variance):
    #holds the map to be returned
    returnMap = []

    #runs a for loop to generate the map
    for i in range(height):
        #temporarily holds each node in the row being generated
        row = []

        #generates each row of the map
        for j in range(width):
            #adds nodes across the row
            row.append(start + randint(-variance, variance))

        #adds the newly-generated row to the map
        returnMap.append(row)

    return returnMap

#generates maps with heights influenced by surrounding nodes
def advancedMap(width, height, start, variance):
    returnMap = []
    for i in range(height):
        row = []

        if i == 0:
            row.append(start)

            for j in range(width-1):
                row.append(row[j-1] + randint(-variance, variance))
            returnMap.append(row)
        else:

            for j in range(width):
                if i%2 == 0:
                    if j == 0:
                        row.append(int(returnMap[i-1][0] + randint(-variance, variance)))
                    else:
                        row.append(int((row[j-1] + returnMap[i-1][j])/2 + randint(-variance, variance)))
                else:
                    if j == 0:
                        row.append(int(returnMap[i-1][len(returnMap[i-1])-1] + randint(-variance, variance)))
                    else:
                        row.insert(0, int((row[len(row)-j] + returnMap[i-1][len(returnMap[i-1])-1-j])/2 + randint(-variance, variance)))
                    
            returnMap.append(row)
    
    return returnMap

def visualize(arr):
    win = GraphWin('Map', 1280, 710, autoflush = False)
    
    height = -100000000000000000
    for i in arr:
        for j in i:
            if abs(j) > height:
                height = abs(j)
    
    
    for i in range(len(arr)):
        for j in range(len(arr[0])):
            colour = int(arr[i][j]*255/height)
            
            if colour >= 0:
                colour = color_rgb(0, colour, 0)
            else:
                colour = color_rgb(0, 0, 255+colour)
            
            plot = drawRect(j/len(arr[0])*1280, i/len(arr)*710, 1280/len(arr[0]), 710/len(arr), colour)
            plot.draw(win)
        update()

visualize(advancedMap(1280, 710, 0, 250))
