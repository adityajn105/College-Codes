file=open("try.txt","r")
#print(file.read())
vowcnt=0
charcnt=0
linecnt=0
blcnt=0
wordcnt=0
specialcnt=0
char=file.read(1)

print("File is:")
while char:
        charcnt+=1
        print(char)
        if char in "aeiou":
                vowcnt+=1
        if char=="\n":
                linecnt+=1
                wordcnt+=1
                charcnt-=1
        if char==' ':
                blcnt+=1
                wordcnt+=1
               
        if char =="."  or char=="," or char==";":
                specialcnt+=1
        char=file.read(1)
file.close()
# print the result on the screen
print("vowels")
print(vowcnt)
print("characters:"+str(charcnt))
print("Lines"+str(linecnt))
print("blank "+str(blcnt))
print("Words "+str(wordcnt))
print("Special "+str(specialcnt))
# write the count in the result file
 
file1=open("result.txt","w")

file1.write("No of vowels : "+str(vowcnt));
file1.write("\nNo of characters : "+str(charcnt));
file1.write("\nNo of lines : "+str(linecnt));
file1.write("\nNo of blanks : "+str(blcnt));
file1.write("\nNo of words : "+str(wordcnt));
file1.close() 

