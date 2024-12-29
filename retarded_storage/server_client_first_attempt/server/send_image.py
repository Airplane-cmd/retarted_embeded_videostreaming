import serial
from PIL import Image
import sys

# Configuration
SERIAL_PORT = "/dev/ttyUSB0"  # Adjust to your device
BAUD_RATE = 115200
IMAGE_PATH = "/home/bit/WS/robotics/retarted_image_server/images/Untitled.jpeg"  # Replace with your image file path
MATRIX_WIDTH = 16
MATRIX_HEIGHT = 16

def send_image():
    # Open the serial port
    ser = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=1)
    print(f"Connected to {SERIAL_PORT} at {BAUD_RATE} baud.")

    # Open and resize the image
    img = Image.open(IMAGE_PATH).resize((MATRIX_WIDTH, MATRIX_HEIGHT)).convert("RGB")
    pixels = list(img.getdata())

    # Send image data over serial
    for r, g, b in pixels:
        ser.write(bytes([r, g, b]))

    print("Image sent!")
    ser.close()

if __name__ == "__main__":
    if len(sys.argv) > 1:
        IMAGE_PATH = sys.argv[1]
    send_image()