arr=(w who date `cat /proc/cupinfo` mount uptime) # env lsof last lastb  )
for ((index=0; index<${#arr[@]};index++)) do
#	echo " $(${arr[$index]}) "
#	printf "\n"
	set -v
	${arr[$index]}
	printf "\n"
done


