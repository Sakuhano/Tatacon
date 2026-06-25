# What is a Tatacon?
A Tatacon is a controller that uses a drum and drumsticks as it's input mechanism, it's most commonly used for the hit Japanese arcade video game: Taiko No Tatsujin.
A tatacon usually consists of 2 main parts, a drum and an ebox. The drum is self explanatory, you hit it to make inputs on piezo sensors attached to it. These signals are then sent to the EBox, which consists of a microcontroller and other components to improve processing speed and reduce misinput. The main feature I added that I've never seen on a comercially available ebox is a screen. The screen has a settings function allowing you to adjust the individual and total sensistivites of each piezo on the controller. It also consists of a controller (completely digital) which you can use to not require an external controller to navigate the Nintendo switch. Both the screen and controller functions are powered by 2 different boards so as not to lose any processing time for the inputs and make the most accurate controller. I consider my current build to be just a prototype of design as I lack a PCB and printed case, along with other polish I would like to add when finishing this project.


![Intro Screenshot](https://github.com/Sakuhano/Tatacon/blob/main/imgs/1what%20is%20it%20image.png)

# CAD and CNC

All the CNC machine files were based off openscad files by Moandor, these files are the standard shape used for almost all Tatacons, I made minimal edits for hole size (which turned out to be a mistake later however this was fixable with a drill)
I outsourced the CNC machine, and the woodshop generously offered the service at no-cost after hearing about my purpose. I then had to remove and sand each individual part from the large rectangle

![CNC](https://github.com/Sakuhano/Tatacon/blob/main/imgs/2cncimage.png)

Next, the CAD files were also based off the openscad files and were adapted for my specific size of wood and materials that I used.

![CAD](https://github.com/Sakuhano/Tatacon/blob/main/imgs/cad.png)


# Drumsticks

I made my own drumsticks as I have access to a lathe in school but it was made completely from scratch with no template, as such there is no design files for the drum stick. I just eyeballed them on the lathe. However, it is a replica of commonly available Taiko Bachi. Drumsticks are non-negotiable to use this product effectively.


![DRMSTICK](https://github.com/Sakuhano/Tatacon/blob/main/imgs/drumsticks.png)

# Drum Head (Skin)

Many projects like this buy official arcade skins imported from Japan, however those can range from 100-200 USD when factoring shipping. Due to this, I researched materials and found an effective substitute to be neoprene rubber. So using a strip and a large sheet, I constructed a drum head using superglue to bond the rubber. However, one issue is that the neoprene rubber releases a strong smell that fills a room, it can be mitigated by airing out the rubber however it still remains. Also, I use a towel over the head, as hitting the rubber with drumsticks quite hard tends to stain the sticks. Overall though, it works as quite a suitable substitute.



![DRMHD](https://github.com/Sakuhano/Tatacon/blob/main/imgs/drumhead.png)




# Coding

To make the menu, I built off a lot of exisiting code, first I built a menu framework, basing it off code by upir, his code only had a menu framework and bitmap pixel art, hwoever no features. I took his code and edited it to add my specific menus, run on a joystick for navigation as well as actually have features. The controller code is built off code from Luicat, which I took and allowed it to recieve inputs and changes from the menu. In these edits I allowed for serial communication between the boards so that one can interact with the other as well as actually send inputs to the Nintendo switch, making a succesfull digital controller and settings menu.



![menus](https://github.com/Sakuhano/Tatacon/blob/main/imgs/menu.png)


# Why did I make this?

The idea for this project came to me when I saw an arcade game called Taiko No Tatsujin while abroad it uses a drum controller for inputs. I didn't give it much thought then, but when I got home. I really wanted to play it and found out there was an official controller available for purchase. It was called the Hori TaTacon. It cost about $70, so I was expecting a great product. But on first usage, I was dissapointed. It required water bottles to keep it weighted so it didn't move, I had to hit it super hard for it to work and it was just janky. So I checked for alternatives online. I discovered numerous controllers avaiailable, however a decent one started at 200 for a small one and for a decent size one it went upwards of 500 or more. 

The EBOX is the electrical component, and when doing research on making my own, I thought that none of the ones online had much character, so I figured adding a screen and joystick would make it easy quite easy to adjust things like sensitivity, as well as add a controller without adding so many extra buttons. This led to the creation of my current product












Acknowledgements

Luicat- provided the base controller code that was adapted
https://github.com/LuiCat/ArduinoTaikoController/tree/master


Newsham Woodshop in Aldan, PA for CNC machining my parts for no charge

upir on youtube for the base menu code and tutorial for menu building
https://www.youtube.com/watch?v=HVHVkKt-ldc&time_continue=72&source_ve_path=MjM4NTE&embeds_referring_euri=https%3A%2F%2Fwww.bing.com%2F&embeds_referring_origin=https%3A%2F%2Fwww.bing.com


Friends for helping and teaching me many things

Hack Club for providing the environment to build this

The Taiko no Tatsujin community for help

ShikyC - providing some wiring ideas and examples
https://github.com/ShikyC/Taiko-Drum-Controller-Arduino


- Moandor for providing the base OPENSCAD files which I used to make CNCable files, ad well as providing advice throughout this
https://github.com/moandor-y/taiko-no-tatsujin-drum

W3 schools for teaching me C++

and many others whose guides and articles I couldn't have made this project w/o

