insert()
{
	echo "enter name"
	read name
	echo "enter phone"
	read phone
	echo "enter address"
	read address
	echo "$1| $name | $phone | $address">> $addressdb
	echo "Record inserted successfully"
}
modify()
{
	 grep -v -w $1 $addressdb > tempdb
	echo "enter name"
	read name
	echo "enter phone"
	read phone
	echo "enter address"
	read address
	cat tempdb > $addressdb
	echo "$1| $name | $phone | $address">> $addressdb
 
}
delete()
{
	grep -v -w $1 $addressdb > tempdb
	cat tempdb > $addressdb 
	echo "Record deleted succesfully"
}
 echo "Enter the file name"
 read addressdb
    if test -s $addressdb 
      then 
    echo "file already exits"
      else
    echo "RollNo|Name|Phone|Address" >$addressdb
      fi

  while [ true ]
   do
	echo "1.insert\n2.view\n3.modify\n4.delte\n5.view all\n"
	echo "enter ur choice"
	read ch
case  $ch in
1)
 while [ true ]
do
   echo "Enter the roll no"
	read rollno
 if (grep -w $rollno $addressdb)
then 
echo "Record already exists"
else
insert $rollno
break
fi
done
;;
2)
 echo "Enter Roll no"
 read rollno
 if(grep -w $rollno $addressdb)
 then echo""
 else
 echo "not found"
fi
;;
3)
echo "enter the roll no to be modified"
read rollno
if(grep -w $rollno $addressdb)  
 then 
modify $rollno
else
echo "No such record found"
fi
;;
4)
 echo "Enter the roll no to be deleted"
read rollno
if(grep -w $rollno $addressdb )
then 
 delete $rollno
else 
echo "Record not found"
fi
;;
5)
cat $addressdb
;;
6)exit 
;;

esac
done
