import os;
print("Demonstrating nice and renice from a python program using sys calls")
os.system("ps -l")
os.system("nice -n 3 firefox&")
os.system("ps -l")
os.system("nice -n 2 top")
os.system("renice -n 4 -u student")
os.system("ps -l")
os.system("echo exiting now.....")

