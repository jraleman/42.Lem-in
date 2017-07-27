header()
{
	clear;
	echo "\x1B[31m    .    _    _ _______ ____  _      ______ __  __ _____ _   _";
	echo "\x1B[32m    /\  | |  | |__   __/ __ \| |    |  ____|  \/  |_   _| \ | |";
	echo "\x1B[33m   /  \ | |  | |  | | | |  | | |    | |__  | \  / | | | |  \| |";
	echo "\x1B[34m  / /\ \| |  | |  | | | |  | | |    |  __| | |\/| | | | | . \` |";
	echo "\x1B[35m / ____ \ |__| |  | | | |__| | |____| |____| |  | |_| |_| |\  |";
	echo "\x1B[36m/_/    \_\____/   |_|  \____/|______|______|_|  |_|_____|_| \_|\x1B[0m";

	echo "\x1B[31m         ___      \x1B[32m  _  __  ___   _   _   __ ___  ___   ___";
	echo "\x1B[31m        / o.)_ __ \x1B[32m / |/ /,' _/ .' \ / \,' // o |/ o | / _/";
	echo "\x1B[31m       / o \ \V / \x1B[32m/ || /_\ \`. / o // \,' // _,'/  ,' / _/";
	echo "\x1B[31m      /___,'  )/ \x1B[32m/_/|_//___,'/_n_//_/ /_//_/  /_/\`_\/___/";
	echo "\x1B[31m             //";
	echo; echo; echo;
}

working()
{
	for map in "directlink2end" "simple" "roundmap" "input2" "duplicatepipe1" "input3" "underflow" "invalidcommand" "comments" "diamond" "simple1" "overflow" "loop" "hardmap" "cobmap" "map10" "testbug" "pentagram" "input1" "in0" "map14" "map42" "input0" "maptest" "triforce" "shortest" "test" "Chloe" "toile" "multiplewaysmap" "toile2" "europe_utf" "europe" "42" "bmap" "big" "mmkr2";
	do
	header;
	echo "\x1B[35m***********INPUT FILE************\x1B[0m";
	echo $map;
	echo "\x1B[35m*********************************\x1B[0m";

	echo "\x1B[32m***********CAT INPUT************\x1B[0m";
	cat -e ./maps/$map;
	echo "\x1B[32m********************************\x1B[0m";

	echo "\x1B[36m*********LEM-IN RESULT**********\x1B[0m";
	./lem-in < ./maps/$map;
	echo "\x1B[36m********************************\x1B[0m";

	read;
done;
}


unvalid()
{
	for map in "empty" "no_rooms" "startisend" "nopath" "no_tubes" "multiends" "nostart" "noend" "no_ants" "noants" "bad_rooms" "invalidcommand1" "whitespaces" "illegalname1" "illegalname" "space_room" "space_room_2" "loop1" "test2commentary" "comments2" "map4" "simple2" "test1" "map3" "input4" "map5" "haaaaaaaaaaaaaaaaaaaardtest";
	do

	header;
	echo "\x1B[35m***********INPUT FILE************\x1B[0m";
	echo $map;
	echo "\x1B[35m*********************************\x1B[0m";

	echo "\x1B[32m***********CAT INPUT************\x1B[0m";
	cat -e ./maps/$map;
	echo "\x1B[32m********************************\x1B[0m";

	echo "\x1B[36m*********LEM-IN RESULT**********\x1B[0m";
	./lem-in < ./maps/$map;
	echo "\x1B[36m********************************\x1B[0m";

	read;
	done;
}


printf "Working or Unworking maps (w/u) ? ";
read response;

if [ $response = "u" ]
	then	unvalid

elif [ $response = "w" ]
	then	working
else
	exit
fi

exit;
