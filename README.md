Arduino-Based Controller for Osu! Mania!

This project is a custom Arduino-based controller designed to interact with the popular rhythm game Osu! Mania!. It was developed as part of the MM4010 - Mechatronic Systems course.

Purpose;
The primary goal of this project is to emulate the keyboard inputs (specifically 'd', 'f', 'j', 'k' keys) required to play Osu! Mania! using custom hardware. Instead of a standard keyboard, it utilizes physical switches to send key press and release signals to the computer, offering a more tactile and engaging gameplay experience.

How It Works;
The system uses an Arduino Uno as its core, programmed in C++.

-Keyboard Emulation: Four primary physical switches (e.g., microswitches or arcade buttons) serve as the main inputs. When a switch is pressed, the Arduino sends a corresponding "key down" signal (e.g., dD) via the serial port. When released, it sends a "key up" signal (e.g., dU). A Python script on the computer reads these serial signals and simulates actual keyboard presses. Follow-up LEDs also light up for each key press, providing visual feedback.

-LDR-Servo Mechanism: The project includes an experimental automated input feature. Four LDRs (Light Dependent Resistors) detect light from the screen. If an LDR detects sufficient light (value < 400), it triggers a corresponding servo motor to move. The servo arm then physically presses a dedicated microswitch, creating an automated keystroke.

-Temperature Display: An LM35 temperature sensor is used to monitor the temperature of one of the servo motors. This is a preventative measure, as overheating could indicate excessive strain and potential failure. The temperature is visualized using five LEDs, which act like a thermometer: more LEDs light up as the servo's temperature increases. This feature is a supplementary diagnostic tool.

Future Improvements
For future development, the dependency on a background Python or MATLAB script can be eliminated by using an Arduino Leonardo (or any board with native USB HID capability). By including the Keyboard.h library, the Arduino can be recognized directly as a keyboard by the computer. This would only require minor code modifications to replace Serial.print() commands with Keyboard.press() and Keyboard.release(), simplifying the setup and making the controller a true plug-and-play device.

Hardware
-Arduino Uno (or compatible)
-8 x Microswitches (4 for manual play, 4 for the servo mechanism)
-4 x LDRs
-4 x Servo Motors (e.g., SG90)
-1 x Temperature Sensor (e.g., LM35)
-9 x LEDs
-Resistors (for LEDs and pull-downs if needed)
-Breadboard and Jumper Wires

How to Use
-Upload the .ino code to your Arduino Uno.
-Important: Once the code is uploaded, close the Arduino IDE's Serial Monitor (or any other program using that COM port). The Python script needs exclusive access to the serial port to work correctly.
-Run a Python script that reads the serial data (e.g., 'dD', 'fU') and uses a library like pynput or keyboard to simulate key presses.
-Start Osu! Mania! and play using your custom controller!
