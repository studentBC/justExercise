# Read from the file file.txt and output the tenth line to stdout.
file="file.txt"
count=0
while IFS=' ' read -r line || [[ -n "$line" ]]; do
	count=$((count+1))
	if [ $count -eq 10 ]
	then
		echo $line
		exit
	fi 
done < "$file"
echo ""
#the simplest method
# Read from the file file.txt and output the tenth line to stdout.
sed -ne 10p file.txt
#for sed = stream editor 
#the -n means not out put to current pattern space
#    -e menas execute sed internal script
#	 p = output to current pattern space
