# Automatic_ping_pong_score_keeper
In the first (step 0) is just proof of concept. We're experimenting with microphones and trying to detect a ball bouncing on the table. Currently, as seen on the waveforms above, we can quite reliably visually detect solid hits in the waveform (the recordings were made outside, with car noise, music and conversations in the background). Smaller hits, such as the ball quickly bouncing off from the net are trickier, but still well-discernable. The microphone in both instances is firmly attached by the head to the bottom of the table. Using the .ino file we track the output of the microphone via the Arduino ADC, and simply print it bytewise to the serial, from where the serialread.py script reads it and outputs it to a .wav file. Then, via findpeaks.py we can pretty reliably detect individual ball hits. Currently we just print them out, the point here is just to prove we can do it.

## [Predefence #1](https://docs.google.com/presentation/d/1tYvUVYLU2cZWBHHJEJNIgzLSFKruPFqIlwTNZ3SOkuE/edit?usp=sharing)

## Recording 1
![image](https://user-images.githubusercontent.com/92575534/198638021-48818a1b-1229-4371-b586-35f0eb63476c.png)
Peaks found:

![photo_2022-10-28_18-08-00](https://user-images.githubusercontent.com/70999143/198669774-f354f9e9-15b4-4597-8999-ff663124e5ab.jpg)

## Recording 2
![image](https://user-images.githubusercontent.com/92575534/198633349-e41bbc5d-9308-4176-808a-f89c5a05151f.png)
Peaks found:

![photo_2022-10-28_18-08-04](https://user-images.githubusercontent.com/70999143/198669938-6b63663f-1e6f-441d-b1ee-4496fda03f43.jpg)


## [Predefence #2](https://docs.google.com/presentation/d/1Y51iK64kRnoQn8WuYitMMo7ChrXf7JN7aYCZU_rgBgo/edit#slide=id.g1c31464959f_2_0)

## [Final defence](https://docs.google.com/presentation/d/19uyxuohUU7DYo5pHPFj-YEt1fol1QqGYeuHdZflqrxI/edit#slide=id.g181c9e7557d_1_40)

Throughout the development of the project, we decided to use Edge Impulse as our AI-model of choice and, because of the need for continious classification, to transfer the data to the microcontroller via DMA (direct memory access) and not RTOS (real-time operation system).

At first, we used Arduino Uno to collect the samples required (tablehit -- ball hitting the left part of the tennis table, oppositehit -- ball hitting the right part of the table, silence -- no sound of hitting the table (but any other sound is allowed)). 
After the collection of the samples and training the model using Edge Impulse service, we used Edge Impulse CLI and its Data Forwarder to test our mechanism of recognizing samples. Before that, we had to properly cut our samples so that the model would recognize them with reasonable frequency, and got the accuracy of almost 90%.


<img width="437" alt="Screenshot 2023-01-18 at 09 36 41" src="https://user-images.githubusercontent.com/91616317/213111608-d0150281-09ea-474a-9203-7c04c669db08.png">


Having completed the successful deployment of our AI-model to the microcontroller itself (as CMSIS-PACK), we started retraining the model on the samples collected using the STM32 ADC (analog-to-digital converter) and got pretty similar results (accuracy ~ 90%).  
<img width="330" alt="Screenshot 2023-01-18 at 09 36 49" src="https://user-images.githubusercontent.com/91616317/213111628-ee2bee1b-47e1-4622-9246-74db4375b200.png">



We used Nokia LCD 5110 as the display, STM32F3DISCO as our microcontoroller of choice and KY038 as microphone to recognize the sound.
The game logic (according to the rules of table tennis) was implemented using the FSM (finite state machine). Here is the diagram of states of the game logic:
![FSM_APPSC](https://user-images.githubusercontent.com/91616317/213109929-a9b48bba-d170-4b68-b867-5e8258771dab.jpg)


Connection schema for the display and the microphone:


<img width="561" alt="Screenshot 2023-01-18 at 09 31 11" src="https://user-images.githubusercontent.com/91616317/213110343-4ced4045-e0b8-46d4-8d9c-6db7a655a810.png">

