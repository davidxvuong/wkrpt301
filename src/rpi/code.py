import smbus
import time

bus = smbus.SMBus(1)
address = 0x08

def readNumber(): 
	number = bus.read_i2c_block_data(address, 0)
	return number


data = readNumber()
x = data[0]
y = data[1]
z = data[2]

print x
print y
print z
