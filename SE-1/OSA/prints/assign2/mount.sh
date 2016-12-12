# Name : Sudeep Biswas
# Roll No.: 202029
while [ true ]
do
echo "1. List partition table for connected devices "
echo "2. Mount a device "
echo "3. Unmount a device "
echo "4. Exit "
echo "Please enter your choice : "
read ch
case $ch in 
1)
	lsblk
	;;
2)
	echo "Enter device location  : "
	read mlocation
	echo "Enter mount point : "
	read mpoint
	if [ -d $mpoint ]
	then
		mount $mlocation $mpoint
	else
		echo "Creating a directory " $mpoint
		mkdir $mpoint
		mount $mlocation $mpoint
	fi
	;;
3)
	echo "Enter device location : "
	read mlocation
	umount $mlocation
	echo "Unmounted successfully"
	;;
4)
	exit
	;;
esac
done

	
	


