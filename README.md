# Guitarduino

A digital instrument in the body of a Guitar.


## Inspirations

 - [Arduino Ribbon Synth](https://github.com/deanm1278/Arduino-ribbon-synth)
 - [Otamatone](http://www.otamatone.com)

## Goals

As someone who learned violin as a child, I value the ability to play a continuous note, even as it changes, even while varying the volume.

I wanted a version of a soft-pot based instrument where the volume of a note could be controlled by the right hand.

Originally I had [an idea for an instrument that would be played like a cello](https://github.com/flyswatter/Arduino-ribbon-synth), but after getting stuck on the bowing mechanic and losing interest in the project, I eventually revisited it and had a fresh take:

Instead of a bow, or a drum pad to strike the string, I could use a spring-returning potentiometer, like a video game thumbstick, to control the volume, or even any one of 4 different variables per string!

I decided I would try to make the first prototype as simple as possible, and document it as well as possible (that's this repository!  As a result, I have here:

 - A simple schematic in the [Fritzing](http://fritzing.org/home/) format.
 - A simple code file that is immediately compatible with the fritzing example.
 - The entire project can be built in the body of an old electric guitar.

## Roadmap

- [x] Get a single string playing on a single speaker.
- [ ] Get multiple strings playing.
- [ ] Allow modulating the sound that is generated to the speaker.
- [ ] Have a headphone jack.
- [ ] Stream MIDI out.
- [ ] Add RGB LEDs that map the current note to a color on the spectrum.
- [ ] Control the instrument's MIDI output on the computer, to make it sound like different cool things.
