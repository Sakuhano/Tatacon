# What is a Tatacon?
A Tatacon is a controller that uses a drum and drumsticks as its input mechanism, its most commonly used for the hit Japanese arcade video game: Taiko No Tatsujin.
A tatacon usually consists of 2 main parts, a drum and an ebox. The drum is self explanatory, you hit it to make inputs on piezo sensors attached to it. These signals are then sent to the EBox, which consists of a microcontroller and other components to improve processing speed and reduce misinput. The main feature I added that I've never seen on a commercially available ebox is a screen. The screen has a settings function allowing you to adjust the individual and total sensitivities of each piezo on the controller. It also consists of a controller (completely digital) which you can use to not require an external controller to navigate the Nintendo switch. Both the screen and controller functions are powered by 2 different boards so as not to lose any processing time for the inputs and make the most accurate controller. This github is just design, as the printed case is not complete, along with other polish I would like to add when finishing this project.



![Intro Screenshot](https://github.com/Sakuhano/Tatacon/blob/main/imgs/1what%20is%20it%20image.png)


# Drum

I've split the section for the case and drum for ease of readability




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

To make the menu, I built off a lot of exisiting code, first I built a menu framework, basing it off code by upir, his code only had a menu framework and bitmap pixel art, however no features. I took his code and edited it to add my specific menus, run on a joystick for navigation as well as actually have features. The controller code is built off code from Luicat, which I took and allowed it to recieve inputs and changes from the menu. In these edits I allowed for serial communication between the boards so that one can interact with the other as well as actually send inputs to the Nintendo switch, making a successful digital controller and settings menu.



![menus](https://github.com/Sakuhano/Tatacon/blob/main/imgs/menu.png)




#  Pre Assembly

Before starting, there are a couple things to do to prepare. First it'll make life a lot easier if you solder extension wires on each piezo, however don't remove the wires that come preattached else you risk ruining the sensor. Then take each of these lengthened piezo sensors and electrical tape or glue them in the following locations to the top plate parts. There are successful labels on the 3d model, however they are difficult to see in this image.

![piezos](https://github.com/Sakuhano/Tatacon/blob/main/imgs/piezo%20locations.png)




#  Drum Assembly

Assembly of this is quite easy once the parts are obtained, using the following items to hold things together
18x M5 bolts 
32x M5 thread nuts
46x washers (should be small and thin but size isn't super important)
soldering iron
electrical tape
piezos
wood pieces
corner brace
drill

Corner brace - note I included my specific one in the bom however, almost any can be used as I find it to be much better to just line up your support leg and measure where a hole using the brace has holes. This allows for much more part flexibility, and you just have to drill out the holes, and this is what I did for my brace.

To assemble, start with placing a washer on 14 of your M5 bolts, then take your bottom plate and place one of those 14 bolts in every single hole except for the 4 ones in the middle. it should look like this

![Step 1](https://github.com/Sakuhano/Tatacon/blob/main/imgs/step%201.png)


Now is the easiest time to place your support legs, Line up your corner brace(s) with your support legs and put a bolt through each of the 4 holes and add a nut on the opposite side from the bolt head and brace. Your supports shouldn’t move very much if at all.


Now, place a nut on each one of the bolts and screw it in fully, after this place each of your rubber dampers on the bolts and screw them in. now it should look something like this (support bolts not shown) , I've added a cross section of how it should look for each bolt

![Step 2](https://github.com/Sakuhano/Tatacon/blob/main/imgs/step2.png)





Now place another washer on each, and place on each piece of the top plate, its easiest to thread the piezo wire extensions through the holes in the bottom plate now, then to finish off with adding a nut and tightening each bolt in fully. The image below is unfinished to make it easier to see. however the diagram on the right is complete






![Step 3](https://github.com/Sakuhano/Tatacon/blob/main/imgs/step3.png)


Plug in your connectors attached to the piezo wires and you're good to go!



# Case/ebox
Originally, this was going to be a PCB, however after much research I thought making a case on the side to hold all my electronics would be much better. I've always liked how sim racing setups feel like stations rather than just accessories to the pc, I wanted the same vibe with this and with a large case on the side, it feels much more integrated into my gaming setup rather than being an accessory on the side. I'm a big fan of how it looks as well. 

# CAD

Using some part models I found online (credits in files) I added parts to my case to show what it would look like when fully done, below is the image, it has sections and text for easy assembly.

![Step 2](https://github.com/Sakuhano/Tatacon/blob/main/imgs/full%20assembled.png)



# Pre Assembly

Required materials:
Superglue
Neodymium Magnets
Plastic Screws and washers
Lever connectors
Arduinos
Ferrules
1m ohm resistor
dupont wires
db107 bridge rectifiers
soldering iron (optional)



First, after printing all the files, you want to take your magnets and glue them on the circle divots on the lid and the 4 lowered pillars in the case. 
Next, glue the joystick insert block on the case under the hole that corresponds with the joystick on the print. (check 3d file for reference). Take the Ferrules and place them on the wires coming out of the drum, differently colored in pairs so as to know which wire goes to which piezo.

# Base (optional)

requires
marker
drill
scrap wood
hammer

To add an extra element of flair you can make a base for your case, which makes it all the more cooler >:) this is totally optional though. To make one, you can use scrap wood and cut it to shape, then place your case over the wood in the spot you would like it to be. Mark the drill points by sticking a marker through the bolt holes for arduino. After drilling, hammer inserts into the holes. 



# Assembly

Now place all your components in their respective locations based on the image above as well as the labels placed on the board. Place your M3 bolts through the holes to lock all components into place. If you make a base, you can thread the bolts on the bottom through the m3 inserts Lock the components in with the washers. Glue 8 lever connectors in the spot that is labeled lever connector like the image above. Now you are ready to start wiring.


# Wiring

Wire everything according to the schematic below, its not necessary to use breadboards, as you can make your own splitter cables for ground by cutting dupont wires and soldering together. Go slow, and attach components to dupont wires for ease.

![schematic](https://github.com/Sakuhano/Tatacon/blob/main/imgs/Screenshot%202026-06-25%20235739.png)


After wiring everything together, plug the ferrules into the lever connects, close the lid and you're done!!!!

# Drumsticks

To make drumsticks I used a lathe and eyeballed some measurements using scrap wood for what I think the drumstick should be in thickness. However just searching up taiko no tatsujin bachi will help you find ones that work. Drumsticks are basically required for this as it makes much more precise inputs. However, I would more recommend just buying one if you don't have access or knowledge of using a lathe. They can go for as low as $10-$15 for a medium quality one.



# Why did I make this?

The idea for this project came to me when I saw an arcade game called Taiko No Tatsujin while abroad it uses a drum controller for inputs. I didn't give it much thought then, but when I got home. I really wanted to play it and found out there was an official controller available for purchase. It was called the Hori TaTacon. It cost about $70, so I was expecting a great product. But on first usage, I was disappointed. It required water bottles to keep it weighted so it didn't move, I had to hit it super hard for it to work and it was just janky. So I checked for alternatives online. I discovered numerous controllers available, however a decent one started at 200 for a small one and for a decent size one it went upwards of 500 or more. So I vowed to make my own. After doing some initial research over a year ago, I realized how much of a monumental task it was and gave up, but the want for one still lingered. And a year later, I found the motivation to start building again for Fallout. After many hours of work, that brings us to today.


# Acknowledgements

Luicat- provided the base controller code that was adapted
https://github.com/LuiCat/ArduinoTaikoController/tree/master


Newsham Woodshop in Aldan, PA for CNC machining my parts for no charge

upir on youtube for the base menu code and tutorial for menu building
https://www.youtube.com/watch?v=HVHVkKt-ldc&time_continue=72&source_ve_path=MjM4NTE&embeds_referring_euri=https%3A%2F%2Fwww.bing.com%2F&embeds_referring_origin=https%3A%2F%2Fwww.bing.com


Friends for helping and teaching me many things

My shop teacher for showing me how to use a lathe



Hack Club for providing the environment to build this

The Taiko no Tatsujin community for help

ShikyC - providing some wiring ideas and examples
https://github.com/ShikyC/Taiko-Drum-Controller-Arduino


- Moandor for providing the base OPENSCAD files which I used to make CNCable files, as well as providing advice throughout this
https://github.com/moandor-y/taiko-no-tatsujin-drum

W3 schools for teaching me C++

and many others whose guides and articles I couldn't have made this project w/o

