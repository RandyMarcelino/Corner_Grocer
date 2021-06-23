# Corner_Grocer_App
Summarize the project and what problem it was solving.
-The Corner Grocer App takes in a text file with a list of grocery item names that were bought for that day. Depending on the user choice to the menu from one to four where one produces a list of all items in the file and the frequency of the item by sending a query to python from C++. Option two prints out the frequency of single item by reaching out to Python via C++. Option three calls to Python from C++ to create a list of items in the file with their frequency then post that list to a new file called frequency.dat, then the C++ code reads the frequency.dat file and prints out the file histogram with the items and a * depiction of how many items there are.

What did you do particularly well?
-I personally did well in the C++ coding keeping it clean while still speaking with the Python code and making it function seemlessly. I also think I did well to make the C++ code given to me into inherited code and creating a header for it to be called so that the code wont clutter the main CPP file.

Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?
-Where I could improve the code would be in the CPP i created the function to read the file but i could create a header and seperate CPP file so that it wont be involved in the main. Another fix I could do is clean the pythons code and create smaller portions to be called in the main functions that are called by CPP.

Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?
-The hardest for me to program was the connection between the two languages. Granted that part was coded for me but what was dificult was working around the limitation of data that could be sent and recieved between the two. I did attempt to send more arguments but coudnt be done unless sending a tuple to python. And recieving data is even worse if it is not an integer. I worked around it by handling data in the Python code instead of having to send it from C++.

What skills from this project will be particularly transferable to other projects or course work?
-The connection between two different languages now that I have learned to combine more than one language I will continue to attempt this with more languages in the future in different projects. It mimics the real world projects with how it is required to use more than one language to deal with different situations and data in code.

How did you make this program maintainable, readable, and adaptable?
-I managed to make this code maintainable by keeping the main clean of excess code that does not need to be there. I have made it readable by adding comments to all code that needed it and properly seperated code with whitespaces into code segments based on what it is doing. It is more adaptable by how mode of the code is in seperate files so if something needs to be added or ammended it can easibly be accomplished.
