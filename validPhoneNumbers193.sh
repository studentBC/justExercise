#original solution which will lead to TLE
# Read from the file file.txt and output all valid phone numbers to stdout.
#!/bin/bash
while IFS= read -r line
do
        #if [[ "$line"=="^[0-9]{3}-[0-9]{3}-[0-9]{4}$" || "$line"=="^\([0-9]{3}\)\s[0-9]{3}[0-9]{4}$" ]]; then
        #if [[ $line=="^([0-9]){3}[-/]([0-9]){3}[-/]([0-9]){4}$" ]]; then
        #if [[ $line==$v2 ]]; then
        #if [[ "$line"=="/^([0-9]{3})\s[0-9]{3}[0-9]{4}$/" ]]; then
            echo "$line" | awk '/^[0-9]{3}[-/][0-9]{3}[-/][0-9]{4}$/'
            echo "$line" | awk '/^\([0-9]{3}\)\s[0-9]{3}[-/][0-9]{4}$/'
        #fi
done < "file.txt"
#my second solution which can pass the test
#!/bin/bash
v1="^[0-9]\{3\}-[0-9]\{3\}-[0-9]\{4\}$"
v2="^([0-9]\{3\})\s[0-9]\{3\}-[0-9]\{4\}$"
while IFS= read -r line
do
	o2=`expr match "$line" "$v2"`
    o1=`expr match "$line" "$v1"`
	#echo $o1
	#echo $o2

	if [ $o1 -gt 0 ] || [ $o2 -gt 0 ];then 
		echo "$line"
	fi
done < "file.txt"
#the fatest method
# Read from the file file.txt and output all valid phone numbers to stdout.
awk '/^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$/' file.txt
