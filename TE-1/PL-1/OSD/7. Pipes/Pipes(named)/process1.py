import os,os.path

path="/tmp/myfifo.fifo"
if os.path.exists(path):
	os.remove(path)
os.mkfifo(path)

fifo = open(path, 'w')
# write stuff to fifo
fifo.write("Hello process")
fifo.close()
exit()
