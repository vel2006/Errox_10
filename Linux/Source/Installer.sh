#!/bin/bash

DownloadFromWeb()
{
	(curl -s "$1") > temp.temp
	cat temp.temp | while IFS= read -r line; do
		echo $line > "$2"
	done
}

if [[ $(whoami) != "root" ]]; then
	echo "ERROR 00: Please run this script as root or with admin perms"
	exit 1
fi

while true; do
	echo "[+] Which instalation method do you wish to use"
	echo "[1] Create Server (online install)"
	echo "[2] Create Server (offline install)"
	echo "[3] Create Client (online install)"
	echo "[4] Create Client (offline install)"
	echo "[5] Help"
	echo "[6] Close this program"
	read -p "> " input
	case $input in
		1)
			DownloadFromWeb "https://vel2006.github.io/Linux_Server.html" "Errox_10_Server"
		2)
			#CREATE FILE#
		3)
			DownloadFromWeb "https://vel2006.github.io/Linux_Client.html" "Errox_10_Client"
			DownloadFromWeb "https://vel2006.github.io/Linux_Per.html" "Errox_10_Per.sh"
		4)
			#CREATE FILE#
		5)
			echo "[+] Help Menu:"
			echo "[#] Server Mode: Used on the admin side of Errox_10. It will allow the user to see the device's usage and remotly access a client through its CMD/Terminal. It can be installed using online or offline modes, online makes the file through page requests while offline creates the files through writing to a file from this script. While offline is faster the version may be outdated due to it not being of the heighest importance."
			echo "[#] Client Mode: Used on the worker/client side of Errox_10. It will allow a computer running server mode to see information about the device its installed onto. It can be installed using online or offline modes, online creates the file through page requests while offine creates them through writing to a file from this script. While offline is faster the version installed may be outdated due to it not being of the heighest importance"
			echo "[#] Help: displays this help message..."
			echo "[#] Close this program: closes this program"
			echo "[+] Support the creator at:"
			echo "[#] https://www.github.com/vel2006"
			echo "[#] https://www.youtube.com/@That1EthicalHacker"
			;;
		6)
			exit 0
			;;
		*)
			echo "[!] ERROR 01: Unknown input on instalation method."
			echo "[#] Select \"5\" for help"
			;;
	esac
done
