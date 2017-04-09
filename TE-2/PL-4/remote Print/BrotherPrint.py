# Import libraries BrotherPrint and socket
from brotherprint import BrotherPrint
import socket
# Establish socket connection
f_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
f_socket.connect(("172.16.133.157", 9100))  # Supply IP address of printer and port (default 9100)
printjob = BrotherPrint(f_socket)  # Create a print job

# Editing the print job
printjob.command_mode()
printjob.initialize()
printjob.bold('on')
#printjob.send("Printed from Python program")  # Pass string that needs to be printed
#printjob.print_page("full")  # Print mode. Options: 'full', 'half', 'special' etc.

# To print from a file

f1 = open ('/home/student/Desktop/print.txt', 'r')
text = f1.read()
printjob.send(text)
printjob.print_page("full")
