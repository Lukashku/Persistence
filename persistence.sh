#!/bin/bash

echo "$(whoami)"
[ "$UID" -eq 0 ] || exec sudo "$0" "$@"

fdisk -l

echo ""
echo "---------------------------------------------------------------------------"
echo ""
echo " What is the name of the storage device? "
echo " Example: /dev/sda, /dev/sdb, /dev/sdc "
echo ""
read -p 'Device name: ' device
echo ""
echo ""
echo " What is your the name of the new partition that will be used for storage? "
echo " Example:
	Device     Boot   Start  End      Sectors  Size  ID  Type
	------------------------------------------------------
	/dev/sdb1  *         64  6802431  6802368  3.2G  17 Hidden HPFS/NTFS
	/dev/sdb2       6802432  6803839     1408  704K   1 FAT12

	Storage partition = /dev/sdb3 "
echo ""
echo ""
read -p 'Storage Partition: ' storage


(	
sleep 0.5
echo n
sleep 0.5
echo p
sleep 0.5
echo
sleep 0.5
echo
sleep 0.5
echo
sleep 0.5
echo w

) | fdisk $device

sleep 1
mkfs.ext4 -L persistence $storage
sleep 1
mkdir /mnt/persistentusb
sleep 1
mount $storage /mnt/persistentusb
sleep 1
echo "/ union" > /mnt/persistentusb/persistence.conf
sleep 1
umount $storage
