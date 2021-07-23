type in vi :set ff=unix command;
awk '{ sub("\r$", ""); print }' git-copy.sh > git-copy2.sh
mv git-copy2.sh git-copy.sh