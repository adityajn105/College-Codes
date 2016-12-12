import os

if os.path.exists("/boot/efi") or os.path.exists("/boot/firmware/efi"):
	print("System is booted to UEFI")
else:
	print("System is booted to LEGACY")
