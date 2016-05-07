import smbus
import time

bus = smbus.SMBus(1)
address = 0x08

def readNumber(): 
	number = bus.read_i2c_block_data(address, 0)
	return number

def displayValues(values):
	print str(values[0]) + " " + str(values[1]) + " " + str(values[2])

try:

	while True:
		data = readNumber()
		displayValues(data)
		time.sleep(1)
except KeyboardInterrupt:
	print "\nProgram terminated"
