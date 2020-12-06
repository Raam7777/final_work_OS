פותחים שני טרמינלים

בראשון: 
מקפלים את הקובץ בעזרת makefile , רושמים בטרמינל make וזה יקמפל את הקובץ.
אחר כך רושמים - 
./set_policy <policy> <priority>

בשני:
רושמים את הפקודה 
pidof ./set_policy
מקבלים את pid
ואז
chrt -p <pid>