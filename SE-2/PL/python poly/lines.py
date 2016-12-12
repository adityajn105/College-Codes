import pygame
pygame.init()
black=(0,0,0)
red=(255,0,0)
green=(0,255,0)
blue=(0,0,255)
white=(255,255,255)

s1=pygame.display.set_mode((720,1080))
pygame.display.set_caption("hello")

s1.fill(white)
pygame.draw.line(s1,red,[100,200],[300,200],2)
pygame.draw.line(s1,blue,[300,250],[400,250],10)
for i in range(10,200):
	if(i%3==0):
		pygame.draw.line(s1,green,[i,100],[i+1,100],3)
	if(i%15<6):
		pygame.draw.line(s1,blue,[i,300],[i,300],2)
	elif(i%15==10):
		pygame.draw.line(s1,black,[i,300],[i+1,300],2)
	
pygame.draw.line(s1,blue,[100,400],[400,400],2)
pygame.draw.line(s1,blue,[50,500],[400,500],2)
pygame.draw.line(s1,blue,[50,600],[400,600],2)
pygame.draw.line(s1,blue,[100,400],[50,500],2)
pygame.draw.line(s1,blue,[100,400],[150,500],2)
pygame.draw.line(s1,blue,[400,400],[400,600],2)
pygame.draw.line(s1,blue,[50,500],[50,600],2)
pygame.draw.line(s1,blue,[150,500],[150,600],2)


pygame.display.update()
done=True
while done:
	for event in pygame.event.get():
		if event.type==pygame.QUIT:
			done=False
pygame.quit()
			
	
