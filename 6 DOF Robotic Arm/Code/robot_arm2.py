import serial
import time
from pynput import keyboard


PORT = "COM9"

arduino = serial.Serial(PORT, 9600)
time.sleep(2)

pressed_keys = set()


def on_press(key):

    try:
        key_char = key.char.lower()

        # Prevent repeated commands when key is held
        if key_char in pressed_keys:
            return

        pressed_keys.add(key_char)

        # Shoulder

        if key_char == 'f':
            arduino.write(b'F')

        elif key_char == 'b':
            arduino.write(b'B')


        # wrist

        elif key_char == 'w':
            arduino.write(b'W')

        elif key_char == 's':
            arduino.write(b'S')


        # Gripper

        elif key_char == 'g':
            arduino.write(b'G')

        elif key_char == 'h':
            arduino.write(b'H')

    except AttributeError:
        pass


def on_release(key):

    try:
        key_char = key.char.lower()

        pressed_keys.discard(key_char)

        # Shoulder

        if key_char == 'f' or key_char == 'b':
            arduino.write(b'X')


        # Wrist 2

        elif key_char == 'w' or key_char == 's':
            arduino.write(b'Y')


        # Grippers

        elif key_char == 'g' or key_char == 'h':
            arduino.write(b'Z')

    except AttributeError:
        pass

    # ESC = exit
    if key == keyboard.Key.esc:
        return False


print("--------------------------------")
print("     ROBOT ARM CONTROLLER")
print("--------------------------------")
print("SHOULDER")
print("F = Forward")
print("B = Backward")
print()
print("WRIST 2")
print("W = Forward")
print("S = Backward")
print()
print("GRIPPER")
print("G = Open")
print("H = Close")
print()
print("Release key = STOP + HOLD")
print("ESC = Exit")
print("--------------------------------")

with keyboard.Listener(
        on_press=on_press,
        on_release=on_release
) as listener:

    listener.join()

arduino.close()