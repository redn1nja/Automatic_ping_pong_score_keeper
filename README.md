# Automatic_ping_pong_score_keeper
# Recording 1
![image](https://user-images.githubusercontent.com/92575534/198638021-48818a1b-1229-4371-b586-35f0eb63476c.png)
Peaks found:
![image](https://user-images.githubusercontent.com/70999143/198667878-c59e12de-5d35-476a-a960-0ad7da0c2edf.png)

# Recording 2
![image](https://user-images.githubusercontent.com/92575534/198633349-e41bbc5d-9308-4176-808a-f89c5a05151f.png)
Peaks found:
![image](https://user-images.githubusercontent.com/70999143/198668011-e52ad980-71fe-4c43-a843-bb2f8418e3f0.png)

In the first (step 0) is just proof of concept. We're experimenting with microphones and trying to detect a ball bouncing on the table. Currently, as seen on the waveforms above, we can quite reliably visually detect solid hits in the waveform (the recordings were made outside, with car noise, music and conversations in the background). Smaller hits, such as the ball quickly bouncing off from the net are trickier, but still well-discernable. The microphone in both instances is firmly attached by the head to the bottom of the table. Using the .ino file we track the output of the microphone via the Arduino ADC, and simply print it bytewise to the serial, from where the serialread.py script reads it and outputs it to a .wav file. Then, via findpeaks.py we can pretty reliably detect individual ball hits. Currently we just print them out, the point here is just to prove we can do it.
