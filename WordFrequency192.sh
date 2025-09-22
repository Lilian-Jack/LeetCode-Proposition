declare -A tableau 

#while read -a permet de lire le fichier ligne par ligne puis de découpé la ligne en mot grâce à -a
while read -a words; do
    for i in "${words[@]}"; do
        (( tableau["$i"]++ ))
    done
done < "words.txt"

#-k2 permet de trier sur le deuxième élément de la ligne (ici valeur)
for key in "${!tableau[@]}"; do
    echo "$key ${tableau[$key]}"
done | sort -rn -k2
