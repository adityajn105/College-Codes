open(FILE,"<trfile") or die "Could not open file,$!";
my($lines,$words,$chars)=(0,0,0);
print "Enter String whose occurence is to be find :";
$string=<STDIN>;
$offset=0;
$count=0;
chomp($string); //removes null at end
while<FILE>
{
	$lines++;
	$chars+=length($_);
	$words+=split(/\s+/,$_);
	$result=index($_,$string,$offset);
	while($result!=-1)
	{
		print"Found $char at $result";
		$offset=$result+1;
		$result=$index($_,$string,$offset);
		$count++;
	}
}
print "\nwords=$words\nchars=$chars\nlines=$lines";
print "\n$string is found $count times";
