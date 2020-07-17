# ESP8266LittleFSFileReader
A little Sketch (for Copy and Paste) to readout Files and directories saved on ESP

Just Copy and Paste the main.cpp

Open Serial-Monitor (baudrate 115200) or simply change it^^

You will see your data Structure like this: 
 Click "<a href="https://raw.githubusercontent.com/j54j6/ESP8266LittleFSFileReader/master/README.md">RAW View</a>" to see the "correct" Layout
 
 
|- Hallo.txt -> 0Byte"
|- alpha.txt -> 0Byte
|- beta.txt -> 591Byte
|- dsadsa.txt -> 0Byte
|--| testDir1
   |- anotherFile.txt -> 0Byte
   |--| inDir1
      |--| data3
         |--| anotherDir
            |- file.txt -> 0Byte
            |- file.txt -> 0Byte
   |- file.txt -> 0Byte
|--| testDir2
   |- configFile1.txt -> 591Byte
|- tester.txt -> 591Byte
