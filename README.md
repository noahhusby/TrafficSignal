# TrafficSignal
A simple controller for a traffic signal

### Configuration
Set the following variables at the top of the program files:
| Variable  | Purpose | Default |
| ------------- | ------------- | ------------- |
| RED  | Pin of the red signal relay  | 2 |
| YELLOW | Pin of the yellow signal relay | 3 |
| GREEN  | Pin of the green signal relay  | 4 |
| BUTTON  | Pin of the mode switching button  | 10 |
| INTERVAL  | Interval of signal flashing (in milliseconds)  | 1000 |

### Modes
The controller comes with the following modes:
| Modes  | Action |
| ------------- | ------------- |
| OFF  | All signals are off |
| RED_ON  | The red signal is solid on|
| YELLOW_ON | The yellow signal is solid on |
| GREEN_ON | The green signal is solid on |
| RED_FLASH | The red signal is flashing at the configured interval |
| YELLOW_FLASH | The yellow signal is flashing at the configured interval |
| CYCLE | All signals are looping in a preset cycle |

## Deploying
1. Open the program in the Arduino IDE
2. Select the Arduino model and COM port from the `tools` menu
3. Press `upload`
