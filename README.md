# ArduinoButton


| Function name  | Description |
| ------------- | ------------- |
|`Button(byte pin, byte anti_bounce, PullRes = FLOATING)`| _Constructor_. `pin` is the input to which the button is connected,`anti_bounce` is the **miliseconds** to avoid the bounce of the button, `PullRes` is to activate or not the pullup resistor|
| `bool falling()` | return `true` if the button has passed from high to low, else return `false`|
| `bool rissing()` | return `true` if the button has passed from high to low, else return `fasle`|
| `bool check()`   | return `true` if the pin of the button is high, else return `false`|


https://github.com/LewisMojica/ArduinoButton
