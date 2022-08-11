Fork of RBD_Button that takes an `Adafruit_FreeTouch` object rather than a pin. Uses a diff value on the count value recieved from measurement to set the pressed/released state; a positive change indicates a touch, negative indicates release.

Hopefully RBD does not mind using the namespace here 🙂 - I thought I would keep it as it maintains the same interface as the RBD_Button (other than constructor).

# Requirements

* SAMD board; anything supported by Adafruit_FreeTouch library.
* [Adafruit_FreeTouch](https://github.com/adafruit/Adafruit_FreeTouch).
* [RBD_Timer](https://github.com/alextaujenis/RBD_Timer).

# Usage

See 'examples/touch_test' for constructor, which takes a pointer to a `Adafruit_FreeTouch` object. **NOTE** the FreeTouch object must call `begin()` somewhere.

Otherwise see the [RBD Button Documentation](https://robotsbigdata.com/docs-arduino-button.html) as the interface matches that.
