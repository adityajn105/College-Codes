open(FILE, "<file.pl") or die "Could not open file: $!";
my ($lines, $words, $chars)=(0,0,0);
while (<FILE>)
{
	$lines++;
	$chars+=length($_);
	$words+=scalar(split(/\s+/, $_));
}
print("lines=$lines words=$words chars=$chars\n");
