
$offset=0;
print("Enter the string\n");
$string=<STDIN>;
print ("Enter the substring\n");
$substring=<STDIN>;

$count=0;
$result=index($string,$substring,$offset);
print ("\n\nresult::$result\n\n");
while ($result!=-1)
{
print "Found $substring at $result \n";
$offset =$result + 1;
$count++;
$result =index($string,$substring,$offset);
}
print("\n $substring appeared $count times");

