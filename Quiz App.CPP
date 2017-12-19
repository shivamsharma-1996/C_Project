#include<stdio.h>
#include<iostream.h>
#include<fstream.h>
#include<string.h>
#include<process.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<ctype.h>
#include<dos.h>



//Global Variables
char arr1[10]="Q",arr2[10];
int a,b=48,arr3[5],count=0,i=0;
char ch2,ch,ans[10];
int q,d,opt,mark=0,check;
int counter=1;
char match[10],cat[5],name[5],flag='0';
time_t t;

FILE *p;


char uname[20];
char pwd[20];

//Global functions
int quiz();
void showq();
void signup();
void signin();
void output_page();
void rules();
void load();
void showmark();
void catagory();


void main()
{
  int a;
  clrscr();

  while(1)
 {
    cout<<endl;
    cout<<"                                    -------------------------          \n"<<endl;
    cout<<"                                   |   press 1. for signup   |          \n"<<endl;
    cout<<"                                   |   press 2. for signin   |          \n"<<endl;
    cout<<"                                   |   press 3. for exit     |          \n"<<endl;
    cout<<"                                     -------------------------          \n"<<endl;

    cin>>a;

    switch(a)
    {
	case 1: signup(); break;
	case 2: signin(); exit(1); break;
	case 3: exit(1);  break;
	default: cout<<"you have pressed invalid key\n";

    }

   getch();
   clrscr();
 }
}



 void signup()
{
    cout<<"\n*****************************************************************************\n";
    cout<<"                               welcome to signup               ";
    cout<<"\n*****************************************************************************\n";
    cout<<"\nenter username\n";

    /******************* CPP File Objects ******************************/
    fstream ob1;
    ob1.open("username.txt",ios::app);
    gets(uname);
    ob1<<uname<<endl;
    ob1.close();


    fstream ob2;
    cout<<"enter password\n";
    ob2.open("password.txt",ios::app);
    gets(pwd);
    ob2<<pwd<<endl;
    ob2.close();

    cout<<"\n\n THANK YOU FOR REGISTRAION\n\n";
    cout<<"**************************************************************";
}


 void signin()
{
    char a[20];
    int flag,b;
    fstream ob1;

    cout<<"                            ENTER USERNAME:";
    gets(uname);
    cout<<"\n";
    cout<<"                            ENTER PASSWORD:";

    gets(pwd);
    cout<<"\n";
    ob1.open("username.txt",ios::in);

     while(1)
    {
       flag=ob1.eof();
       if(flag==1)           //flag initializes with one if file read properly
      {
	 break;
      }
      else
      {
	 ob1.getline(a,20);

	 b=strcmpi(uname,a);
	 if(b!=0)
	 {
	   continue;
	 }
	 else
	 {
	   cout<<"\nprofile exists\n";
	   getch();
	   clrscr();

	   rules();
	   break;
	 }
      }

    }

   if(flag==1)                   //check username exist or not(loop terminate on max. cond'n
  {
     cout<<"profile doesn't exists\n";
  }

  ob1.close();    //Closes the File objects
}



 void rules()
{
   int choise;
   clrscr();

   cout<<"\n                              RULES & REGULATIONS\n\n";
   cout<<"\n1.There are 3 catagories in quiz. So,choose one\n\n";
   cout<<"2.Each catagory contains 15 question for user\n\n";
   cout<<"3.On right answer +1 & on wrong answer -1\n\n\n";
   cout<<"                 CATAGORIES: a) C\n";
   cout<<"                             b) c++\n";
   cout<<"                             c) DSA\n";
   cout<<"\n                  CHOOSE ONE:";

   cin>>name;
   catagory();			    //opens a quiz_file of choosed catagory

   clrscr();
   cout<<"\n\n\n\n\n\n\n\n\n\n";
   cout<<"                              Hope Now You Are READY!\n\n";
   cout<<"                                    1. START\n";
   cout<<"                                        OR\n";
   cout<<"                                    2. EXIT\n";

   cin>>choise;
   if(choise==1)
   {
     output_page();

     for(int n=1;n<=5;n++)                       //prints quiz's 6 ques
     {
       cout<<"\n\n\n\n\n\n                        NEXT-->(PRESS ANY KEY)";
       if(getch())
       {
	 load();
	 output_page();
       }
     }

     if(n==6)                                    //end-point of quiz
    {
       clrscr();

       cout<<"\n\n\n\n\n\n\n\n\n\n";
       showmark();

       cout<<"\n\n\n\n\n\n\n";
       cout<<"                             THANK YOU FOR PLAY";
       getch();
    }
 }
 else
 {
   exit(1);
 }
}


 void catagory()
{
   int m;
   m=strcmpi(name,"a");

   if(m==0)
   {
     strcpy(cat,"c");
     return;
   }

   m=strcmpi(name,"b");
   if(m==0)
   {
     strcpy(cat,"cpp");
     return;
   }

   m=strcmpi(name,"c");
   if(m==0)
   {
     strcpy(cat,"dsa");
     return;

   }
}


 void output_page()               //quiz main page
{
   fstream fobj;
   clrscr();
   cout<<"\n\n                                QUIZ\n";

   showq();                     // write question

   d=(int) ch2 - 48;           // question no

   cout<<"\n\n\n\n\n\n                            CHOOSE AN ANSWER:";
   cin>>ans;

   fobj.open("ans.txt",ios::in);

   q=fobj.eof();

   counter=1;
   while(counter<=d && q!=1)
   {
      q=fobj.eof();
      fobj>>match;
      counter++;
   }

     check=strcmpi(ans,match);
     if(check==0)                        //case of correct answer
    {
       mark++;
    }
    else                                //case of wrong answer
    {
       mark--;
    }

    fobj.close();
}


 void load()
{
   clrscr();
   for(int z=1;z<=3;z++)
  {
     cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
     cout<<"                                  Loading";

     if(z==1)
     {
	cout<<".";
	delay(550);
	clrscr();
     }
     else if(z==2)
     {
	cout<<"..";
	delay(550);
	clrscr();
     }
     else
     {
	cout<<"...";
	delay(550);
	clrscr();
     }
  }
}

 void showq()
{
    int h,g;
    clrscr();
    a=quiz();

    a=a+b;
    ch2=toascii(a);
    arr1[1]=ch2;
    g=strcmpi(cat,"c");

   if(g==0)                        //what is this
   {
     p=fopen("c.txt","r");
     goto w;
   }

    g=strcmpi(cat,"cpp");
    if(g==0)
    {
      p=fopen("cpp.txt","r");
      goto w;
    }

    g=strcmpi(cat,"dsa");
    if(g==0)
    {
       p=fopen("dsa.txt","r");
       goto w;
    }

    w:  ;                   //w is a LABEL

    fscanf(p,"%s",arr2);
    int cmp=strcmpi(arr1,arr2);             //strcmp returns diffrence of arr2-arr1,o means both equal


   while(cmp!=0)
   {
      fscanf(p,"%s",arr2);
      cmp=strcmpi(arr1,arr2);
   }

     flag++;                       //corrects the serial no of question
     arr2[1]=flag;
     cout<<arr2<<".";             //question no. prints



   if(p==0)
  {
    cout<<"file not opened\n";
  }
  else                            //file checking and reading untill $ come
  {
    while(1)
    {
       if(feof(p))
       {
	 cout<<"eof";
	 break;
       }

       ch=fgetc(p);

       if(ch!='$')
       {
	 cout<<ch;
       }
       else
       {
	 break;
       }
    }                      //loop close
  }                        //else ends

 fclose(p);
}



 void showmark()
{
   cout<<"                       OBTAINED MARKS:"<<mark<<"/15";
}




 int quiz()
{
  randomize();
  srand((unsigned) time(&t));

  x: ;                              //x is a GOTO label forjump statement

  a=rand()%7;                       //Random function

  if(a==0)                          //case when zero returns
  {
    goto x;
  }
  else
  {
    for(int i=0;i<=count-1;i++)
    {
      if(a==arr3[i])
      {
	goto x;
      }
    }
   arr3[count]=a;
   count++;
  }
 return a;
}