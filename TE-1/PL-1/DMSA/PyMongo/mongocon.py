import pymongo
con=pymongo.MongoClient("localhost",27017) #establish a connection
print "Connection Established"
db=con.Blogger	#use or create Blogger
col=db.blogs	#create collection blogs

while(True):
	ch=int(raw_input("***Menu***\n1.Insert\n2.Delete\n3.Update\n4.Show ALl\n5.Exit\n"))
	if(ch==1):
		title=raw_input("Enter title  :")
		desc=raw_input("Enter Description  :")
		col.insert_one({"title":title,"description":desc})
	elif(ch==2):
		title=raw_input("Enter title to be deleted  :")
		col.delete_many({"title":title})
	elif(ch==3):
		title=raw_input("Enter title to be updated :")
		desc=raw_input("Enter new Description  :")
		col.update_one({"title":title},{"$set":{"description":desc}})
	elif(ch==4):
		print "title	description"
		cursor=col.find({},{"_id":0})
		for n in cursor:
			print n["title"]+"	"+n["description"]
	else:
		break
	

