# Read from the file file.txt and output the tenth line to stdout.
n=0
while read ligne;do
    ((n++))
    if [ $n -eq 10 ]; then
        echo $ligne
    fi
done < "file.txt"
