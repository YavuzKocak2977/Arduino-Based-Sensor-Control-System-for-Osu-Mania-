Arduino-Based Sensor Controller for Osu Mania!

This project is a custom Arduino-based controller designed to interact with the popular rhythm game Osu Mania!. It was developed as part of the MM4010 - Mechatronic Systems.

Purpose

The primary goal of this project is to emulate keyboard inputs (specifically 'd', 'f', 'j', 'k' keys) required to play Osu Mania! using custom hardware. Instead of a standard keyboard, it utilizes touch sensors to send key press and release signals to the computer via the serial port.
How It Works

The system uses an Arduino Uno  as its core, programmed in C++.

----Keyboard Emulation: Four touch sensors are monitored. When a sensor is touched, the Arduino sends a corresponding "key down" signal (e.g., dD) via the serial port. When released, it sends a "key up" signal (e.g., dU). A Python script (or similar software like pyserial) can be used on the computer to read these serial signals and simulate actual keyboard presses. Follow-up LEDs also light up for each key press.

LDR-Servo Mechanism: The project includes an experimental feature where four LDRs (Light Dependent Resistors) detect light. If an LDR detects sufficient light (value < 400), it triggers a corresponding servo motor to move. The idea was to potentially use servos to physically press the touch sensors, creating an alternative (or even automated) input method.
Temperature Display: An LM35 temperature sensor reads the ambient temperature. This temperature is then visualized using five LEDs, where more LEDs light up and shine brighter as the temperature increases.

Hardware

----Arduino Uno (or compatible)
----4 x Touch Sensors (e.g., TTP223B) 

4 x LDRs
4 x Servo Motors (e.g., SG90)
1 x Temperature Sensor (e.g., LM35)
9 x LEDs
Resistors (for LEDs and pull-downs if needed)
Breadboard and Jumper Wires

How to Use

----Upload the .ino code to your Arduino Uno.
----Important: Once the code is uploaded, close the Arduino IDE's Serial Monitor (or any other program using that COM port). The Python script needs exclusive access to the serial port to work correctly.
----Run a Python script (you'll need to write or find one) that reads the serial data (e.g., 'dD', 'fU') and uses a library like pynput or keyboard to simulate key presses for Osu Mania!.
----Start Osu Mania! and play using your custom controller!
