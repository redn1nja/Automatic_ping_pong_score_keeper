import serial
import serial.tools.list_ports
import wave

serial_port = serial.tools.list_ports.comports()[-1].device
baud_rate = 115200
sampleRate = 8820.0 # hertz
ser = serial.Serial(serial_port, baud_rate)
with wave.open('soundtest.wav','w') as obj:
    obj.setnchannels(1) # mono
    obj.setsampwidth(1)
    obj.setframerate(sampleRate)
    line_left = ser.read(2)
    while line_left:
        obj.writeframesraw(line_left)
        line_left = ser.read(2)


