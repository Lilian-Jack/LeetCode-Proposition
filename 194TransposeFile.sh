# Read from the file file.txt and print its transposed content to stdout.
tableau=()
n=0
while read -a words;do 
    tabaux=()
    j=0
    for i in ${words[@]};do
        tabaux[$j]=$i
        (( j++ ))
    done
    tableau[$n]=tabaux
    (( n++ ))
done < 'file.txt'

for i in ${tableau[@]};do
    for j in $i;do
        echo -n $j
    done
    echo ''
done
