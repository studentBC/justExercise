# Read from the file words.txt and output the word frequency list to stdout.
count=0
max=0
line=()
ans=()
while IFS='' read -r lines || [[ -n "$lines" ]]; do
    line+=($lines)
done < "words.txt"
    #echo "a lines $line total number ${#line[@]}"
    for ((i=0; i<${#line[@]}; i++)); do
        if [ ${line[$i]} != "$" ]; then
            #echo "go to find ${line[$i]}"
            count=1
            for ((j=i+1; j<${#line[@]}; j++)); do
            #   echo "i is  ${line[$i]}   j is  ${line[$j]}"
                if [ ${line[$i]} == ${line[$j]} ]; then
                    ((count++))
                    line[$j]="$"
                fi
            done
            ans[$count]=${line[$i]}
            line[$i]="$"
            if [ $count -gt $max ]; then
                max=$count
            fi
        fi
    done
#   echo "---------------"
    for ((i=$max; i>-1; i--)); do
        if [ ${ans[$i]} ]; then
            echo "${ans[$i]} $i"
        fi
    done

#the fatest method
# Read from the file words.txt and output the word frequency list to stdout.
cat words.txt | tr -s ' ' '\n' | sort | uniq -c | sort -r | awk '{ print $2, $1 }'

# tr => delete , edit substring
#		-r : replace each input sequence of a repeated character that is listed in SET1 with a single occurence of that character

