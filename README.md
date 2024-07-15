README.md

This is a library to enable plug-and-play interaction with buttons on the Arduino platform. This library supports multi-touch.
Types of button presses accommodated:
 1. Toggles,
 2. Long-press toggles, and 
 3. Hold-downs.

The implementation details/variables are encapsulated from the user to avoid any weird behaviour and make user-side implementation as straightforward as possible.

Future plans:
 1. Create classes for buttons that only allow one kind of function (eg. long-press only). This will help make the final Arduino code more memory efficient. The Button class as it stands now can inherit from each 'special' class on Button.

