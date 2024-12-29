import serial
import time

# Configuration
SERIAL_PORT = "/dev/ttyUSB0"  # Adjust this to your ESP32 serial port
BAUD_RATE = 115200
MATRIX_WIDTH = 32  # Set to 32 for your matrix
MATRIX_HEIGHT = 16
NUM_LEDS = MATRIX_WIDTH * MATRIX_HEIGHT

def stream_dot():
    try:
        ser = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=1)
        print(f"Connected to {SERIAL_PORT} at {BAUD_RATE} baud.")
    except serial.SerialException as e:
        print(f"Error: Could not open serial port {SERIAL_PORT}. {e}")
        return

    print("Streaming a moving dot... Press Ctrl+C to stop.")
    try:
        while True:
            for i in range(NUM_LEDS):
                # Create a frame with a single dot
                frame = [(0, 0, 0)] * NUM_LEDS  # All LEDs off
                frame[i] = (255, 255, 255)  # Set one LED to white

                # Send the frame to the ESP32
                for r, g, b in frame:
                    ser.write(bytes([r, g, b]))

                time.sleep(0.05)  # Adjust speed of the dot movement
    except KeyboardInterrupt:
        print("Streaming stopped.")
    finally:
        ser.close()

if __name__ == "__main__":
    stream_dot()

