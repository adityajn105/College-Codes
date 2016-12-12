import sys
import email.parser
fd=open(sys.argv[1],"r")
content=fd.read()

parser = email.parser.FeedParser()
parser.feed(content)
msg = parser.close()

print("To:         " +msg['to'])
print("From:       " +msg['from'])
print("Subject:    " +msg['subject'])
print("Body:       " +repr(msg.get_payload()))
