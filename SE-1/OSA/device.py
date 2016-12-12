import os;
print("\n\nListing Devices Information with number of instances and device names")

print("\n Column I  -No. of instances")
print("\n Column II -User")
print("\n Column III-Terminal Type")
print("\n Column IV -Major Number")
print("\n Coulmn V  -Minor Number")
print("\n\n\n I  II  III      IV  V   Device Name \n")
os.system("ls -l /dev|cut -c12-34,48-60|more");

