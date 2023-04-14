import serial
import time
import solve_cube


"""
clockwise   counterclockwise
R   r
L   l
U   u
D   d
F   f
B   b
"""
dummy_cube = 'BBURUDBFUFFFRRFUUFLULUFUDLRRDBBDBDBLUDDFLLRRBRLLLBRDDF'

ser = serial.Serial('/dev/ttyUSB0', 9600)
#delay for arduino to reset
time.sleep(4)



if __name__ == '__main__':
    solution = solve_cube.solve(dummy_cube)
    ser.write(solution)
        
    while True:
        if ser.in_waiting > 0:
            line = ser.readline().decode('utf-8').rstrip()
            print(line)
            if line == 'Done':
                print('Done')
                break

