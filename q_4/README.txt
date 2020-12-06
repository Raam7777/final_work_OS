פקודות ליצירת התקיות והקבצים: (מבוסס על הדוגמה)
mkdir dir
touch dir/a dir/b
ln -s a dir/sl
mkdir dir/sub
touch dir/sub/x

קימפול הקובץ בעזרת makefile ----> make
הרצת הקובץ:
./dir_traversal dir