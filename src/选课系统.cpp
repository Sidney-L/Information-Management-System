#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h> 
#define YEAR 2015
#define MON 9
#define DAY 25
#define HOUR 23
#define MIN 59
#define SEC 59
int student_checkin();/*学生登录函数原型*/ 
void classelectf(int);/*学生选课函数原型*/
void classSearchClassinf();/*按课程名查询课程信息函数原型*/
void schoolsearchinf();/*按开课学院查询课程信息函数原型*/
void class_reorder();/*课程排序函数原型*/
void stuclass_check(int);/*学生已选课程查询函数原型*/
void stuclass_delete(int );/*学生课程删除函数原型*/
void persclassinf(int);/*教师查询个人开课信息函数原型*/
int teacher_checkin();/*教师登录函数*/ 
void nameSearchStuinf();/*按学生姓名查询学生信息函数原型*/
void orderclassinf(int);/*统计选课信息函数原型*/
void classSearchStuinf();/*按课程名查询学生信息函数原型*/
void addClass(int);/*课程添加函数原型*/
void modiclassinf(int);/*修改课程信息函数原型*/
void deleteclass(int);/*教师删课函数原型*/
void teacher_information(int);/*教师信息修改函数*/ 
void autodelete();/*自动删除人数不足课程函数原型*/
void student_information(int);/*学生修改个人信息函数原型*/



int main()
{
  int loginCode, funCode, clacheckCode, checkcode, manageCode, code, code1, code2;
  int year,mon,day,hour,min,sec, test; 
  int ID;
  tm mytime;
  FILE *infile;
  struct Classinf {int classid; char classname[20]; int credit; int totaltime; char type[10]; char teacher[10]; char term[40]; int time; char place[6]; int limnum; char briefinf[80]; char book[30];  int numalready; };

  printf("欢迎使用选课系统\n");
  printf("\n请输入对应数字选择您的登录方式：1-学生登录，2-教师登录, 其他数字-退出程序\n");
  scanf("%d", &loginCode);
  switch(loginCode)
{
case 1:  /*学生模块*/
  ID=student_checkin();
  mainpage1:
  {
  printf("\n请输入对应数字选择相应版块：1-选课模块，2-查询课程模块，3-学生个人信息管理模块, 其他数字-退出程序\n");
  scanf("%d", &funCode);
  switch (funCode) 
  {
   case 1:/*进入选课功能模块*/
   printf("\n现在输出存在的所有课程信息\n\n");
   
   printf("\n编号   名称         学分 学时 类型  教师   时间  地点  限制人数  教材  已选人数\n");
   infile = fopen("课程信息.txt", "r");
   struct Classinf classinf;
   while (fscanf(infile, "%d %s %d %d %s %s %s %d %s %d %s %s %d",&classinf.classid, classinf.classname, &classinf.credit, &classinf.totaltime, classinf.type, classinf.teacher, classinf.term, &classinf.time, classinf.place, &classinf.limnum, classinf.briefinf, classinf.book, &classinf.numalready)!=EOF)
   printf("%d %-12s %d    %d   %s  %-6s %d   %s %-3d %-18s %d\n", classinf.classid, classinf.classname, classinf.credit, classinf.totaltime, classinf.type, classinf.teacher, classinf.time, classinf.place, classinf.limnum, classinf.book, classinf.numalready);
   fclose (infile);
   
   _getsystime(&mytime);/*读取系统时间*/      
   year=mytime.tm_year+1900;  
   mon=mytime.tm_mon+1;     
   day=mytime.tm_mday;   
   hour=mytime.tm_hour;  
   min=mytime.tm_min;   
   sec=mytime.tm_sec; 
   
   if (year<YEAR)
 test = 1;
 else
 {
  if (year>YEAR)
  {
  	test = 0;
  }
  else 
  {
   if (mon<MON)
   {
   	test = 1;
   }
   else
   {
   	if (mon>MON)
   	{
   		test = 0;
	   }
	   else
	   {
	   	if (day<DAY)
	   	{
	   		test = 1;
		   }
		   else
		   {
		   	if (day>DAY)
		   	{
		   		test = 0;
			   }
			   else
			   {
			   	if (hour<HOUR)
			   	{
			   		test = 1;
				   }
				   else 
				   {
				   	if (min<MIN)
				   	{
				   		test = 1;
					   }
					   else 
					   {
					   	if (sec<SEC)
					   	{
					   		test = 1;
						   }
						   else
						   test = 0;
					   }
				   }
			   }
		   }
	   }
   }
  }
 }
   if(test==1)
   {
   classelectf(ID);/*调用选课函数*/ 
   printf("\n现在将返回登陆成功界面\n");
   goto mainpage1;/*替代break直接返回功能选项界面*/
   }
   else
   {
   	printf("\n超过截止时间，现在返回成功登录界面\n\n");
   	goto mainpage1;
   }
   
   
   case 2:/*进入查询课程模块*/
   printf("\n请输入对应数字选择相应版块: 1-按课程名查询, 2-按开课学院查询, 3-按课余量或选课人数排序所有课程\n");
   scanf("%d", &clacheckCode);
   switch (clacheckCode)
{
   	case 1:
     classSearchClassinf();/*调用按课程名查询课程信息函数*/ 
     printf("\n请输入对应数字选择相应选项: 1-输入课程编号选课, 2-返回功能选项界面\n");
     scanf("%d", &checkcode);
     switch(checkcode)
     {
     	case 1:
     	classelectf(ID);/*调用选课函数*/ 
     	printf("\n现在将返回登陆成功界面\n\n");
     	goto mainpage1;
     	
     	case 2:
        goto mainpage1;
	 }
   	case 2:
   	   schoolsearchinf();/*调用按开课学院查询课程信息函数*/ 
   	   printf("\n请输入对应数字选择相应选项: 1-输入课程编号选课, 2-返回功能选项界面\n");
   	   scanf("%d", &checkcode);
       switch(checkcode)
       {
     	case 1:
     	classelectf(ID);/*调用选课函数*/
     	printf("\n现在将返回登陆成功界面\n\n");
     	goto mainpage1;
     	
     	case 2:
        goto mainpage1;
	   }
	case 3:
	  class_reorder();/*调用课程排序函数*/
	  printf("\n\n请输入对应数字选择相应选项: 1-输入课程编号选课, 2-返回功能选项界面\n");
	  scanf("%d", &checkcode);
       switch(checkcode)
       {
     	case 1:
     	classelectf(ID);/*调用选课函数*/
     	printf("\n现在将返回登陆成功界面\n\n");
     	goto mainpage1;
     	
     	case 2:
        goto mainpage1;
	   }

}
	   
	   
	   
    case 3:/*进入学生个人信息管理模块*/
	printf("\n请输入对应数字选择相应版块: 1-查询已选课程, 2-删除已选课程, 3-个人信息管理\n");
    scanf("%d", &manageCode);
    switch (manageCode)
    {
     case 1:
     stuclass_check(ID);/*调用学生查询已选课程函数*/
     printf("\n现在返回成功登陆界面\n\n");
     goto mainpage1;
     
     case 2:
      stuclass_delete(ID);/*调用删除已选课程函数*/
      printf("\n现在返回成功登陆界面\n\n");
      goto mainpage1;
      
     case 3:
      student_information(ID);/*调用个人信息管理函数*/
      
      printf("\n现在将返回登陆成功界面\n\n");
      goto mainpage1;
	  
	}
     default:/*退出程序*/ 
    printf("\n感谢使用，再见！\n");
    exit(1);
  }
  }
 
 
  case 2:/*教师模块*/
  ID=teacher_checkin();
  mainpage2:
{
  printf("\n成功登录，请输入对应数字选择相应版块：1-选课管理模块，2-课程管理模块，3-教师个人信息管理模块, 其他数字-退出程序\n");
  scanf("%d", &funCode);
  switch (funCode)
  {
   case 1:/*进入选课管理模块*/
   autodelete();/*调用自动删除冷门课程函数*/
   printf("\n请输入对应数字选择相应功能： 1-查询选课情况, 2-统计选课信息");
   scanf("%d", &manageCode);
   switch (manageCode)
   {
   	case 1:/*开始查询选课情况*/
   	 printf("\n请输入对应数字实现相关功能：1-显示我所开设的课程信息, 2-查询学生信息");
   	 scanf("%d", &code);
   	 switch (code)
   	 {
	  case 1:/*显示ID关联课程*/
	  persclassinf(ID);
	  printf("\n现在将返回成功登录界面\n\n");
	  goto mainpage2; 
	  
	  case 2:/*开始查询学生信息*/
	  printf("\n请选择查询方式：1-按学生姓名查询, 2-按课程名称查询选课学生信息");
	  scanf("%d", &code1);
	  switch (code1)
	  {
	  	case 1:
	  	nameSearchStuinf();/*调用按学生姓名查询函数*/
	  	printf("\n现在将返回登录成功界面\n\n");
		goto mainpage2; 
		
		case 2:
		classSearchStuinf();/*调用按课程名查询学生信息函数*/
		printf("\n现在将返回登录成功界面\n\n");
		goto mainpage2; 
	  }
	 }
	 case 2:/*统计选课信息*/
	  orderclassinf(ID);/*调用统计选课信息函数*/
	  printf("\n\n现在将返回登录成功界面\n\n");
		goto mainpage2; 
	  
   }
   case 2:/*课程管理模块*/
   printf("\n请输入对应数字选择对应选项：1-按课程名查询课程信息, 2-添加我的课程, 3-修改课程限制人数, 4-取消我的课程");
   scanf("%d", &code2);
   switch(code2)
   {
   	case 1:
   	 classSearchClassinf();/*调用课程名查询课程信息函数*/
   	 printf("\n现在将返回登录成功界面\n\n");
	  goto mainpage2; 
	  
	case 2:
	addClass(ID);/*调用课程添加函数*/
	printf("\n现在将返回登录成功界面\n\n");
	  goto mainpage2; 
	  
    case 3:
    modiclassinf(ID);/*调用限制人数修改函数*/
    printf("\n现在将返回登录成功界面\n\n");
	  goto mainpage2; 
	  
	case 4:
	deleteclass(ID);/*调用个人课程删除函数*/
	printf("\n现在将返回登录成功界面\n\n");
	  goto mainpage2; 
	
    }
    case 3:/*教师个人信息管理模块*/
    teacher_information(ID);/*调用教师个人信息管理函数*/
    printf("\n现在将返回登录成功界面\n\n");
	  goto mainpage2; 
	  
	default:
    printf("\n感谢使用，再见！\n");
	exit(1);
  }
  }
  
  
  
  default:/*退出程序*/ 
  printf("\n感谢使用，再见！\n");
  exit(1);
}
return 0;
}/*主函数结束*/



int student_checkin()/*学生登录函数首部行*/ 
{struct Information_stu 
 {int id_file;char college[15];char major[20];char name[10];char sex[3];int Tel;char password_file[20];char mail[30]; };
 int id,i;
 char password[20];
 FILE *student_file;
 struct Information_stu student[40];
 if((student_file=fopen("学生信息.txt","r"))==NULL)
 {printf("文件无法打开\n"); 
  }
 for(i=0;i<40;i++)     /*读取学生信息*/
 {fscanf(student_file,"%d %s %s %s %s %d %s %s",&student[i].id_file,student[i].college,student[i].major,student[i].name,student[i].sex,&student[i].Tel,student[i].password_file,student[i].mail);
 }
 while(i==40)
 {printf("\n请输入学号："); 
  scanf("%d",&id); 
  printf("\n请输入密码：");
  scanf("%s",password);
  fclose(student_file);
  for(i=0;i<40;i++)
  {if(id==student[i].id_file)    /*比对学生学号及密码*/ 
   {if(strcmp(password,student[i].password_file)==0)
    {printf("\n登录成功！");}
    else
    {printf("\n密码错误！请重新输入"); 
    i=40;
	}
    break;
   }
   if(i==39)
   printf("\n帐号不存在！请重新输入");
  } 
 }
 return(id);  /*向主程序返回学生学号*/ 
}


void classelectf(int id)    /*学生选课函数首部行*/ 
{
FILE *classfile, *student_classfile,  *studentfile;

struct Classinf {int classid; char classname[20]; int credit; int totaltime; char type[10]; char teacher[10]; char term[40]; int time; char place[6]; int limnum; char briefinf[80]; char book[30];  int numalready; };
struct Classpicked {int studentid; char studentname[10]; int classid;};
struct Studentinf {int studentid; char school[20]; char major[20]; char name[10]; char gender[5]; char phone[15]; char password[10]; char mailaddr[20];};
int cid, count1 =0, count2 =0;
printf("请输入课程编号实现选课：\n");
scanf("%d", &cid);
classfile = fopen("课程信息.txt", "r");

int s1,s3,s4,s8,s10,s13;
char s2[81], s5[81], s6[81], s7[81], s9[81], s11[81], s12[81];/*s[i]系列的变量只做临时容器*/
while (fscanf(classfile, "%d %s %d %d %s %s %s %d %s %d %s %s %d",&s1, s2, &s3, &s4, s5, s6, s7, &s8, s9, &s10, s11, s12, &s13) != EOF)/*读取课程文件以确定有多少条课程信息*/
count1 ++;
fclose (classfile);

classfile = fopen("课程信息.txt", "r");
struct Classinf classinf[count1];
int j=0;
while (fscanf(classfile, "%d %s %d %d %s %s %s %d %s %d %s %s %d", &classinf[j].classid, classinf[j].classname, &classinf[j].credit, &classinf[j].totaltime, classinf[j].type, classinf[j].teacher, classinf[j].term, &classinf[j].time, classinf[j].place, &classinf[j].limnum, classinf[j].briefinf, classinf[j].book, &classinf[j].numalready) != EOF)
{
j++;
}
fclose(classfile);

int i, search;
for (i = 0, search = 1; i < count1 && search; i++)/*搜索是否有该课程*/ 
{
 if (cid == classinf[i].classid)
 search = 0;
}
if (search)
printf("\n输入课程编号有误！\n");
else
{
student_classfile = fopen("学生选课表.txt","r");/*确认学生选课表信息数量*/
int a1, a3;
char a2[81];/*a[i]系列变量只做临时容器*/
while (fscanf(student_classfile, "%d %s %d", &a1, a2, &a3)!= EOF)
count2++;
fclose (student_classfile);

student_classfile = fopen("学生选课表.txt","r");
struct Classpicked classpicked[count2];
int k =0, count3 =0;
while (fscanf(student_classfile, "%d %s %d", &classpicked[k].studentid, classpicked[k].studentname, &classpicked[k].classid)!= EOF)
{
if (classpicked[k].studentid == id)/*确认该学生已选课程数目*/
count3++;
k++;
}

if (count3 == 3)
printf("\n超过选课数量限制\n");
else/*确认该课程是否已经满员*/
{
 for (j=0; j<count1; j++)
 {
  if (cid == classinf[j].classid) 
  break;
  } 
  if (classinf[j].numalready == classinf[j].limnum)
  printf("\n该课程已满员！\n");
  
  else
  {
	if (count3 == 0)/*没有课程直接添加*/
	{
	  fclose(student_classfile);
	  student_classfile= fopen("学生选课表.txt", "a");
	  studentfile= fopen("学生信息.txt", "r");
	  int count6=0;
	  int b1;
	  char b2[81], b3[81], b4[81], b5[81], b6[81], b7[81], b8[81];
	  while(fscanf(studentfile, "%d %s %s %s %s %s %s %s", &b1, b2, b3, b4, b5, b6, b7, b8)!=EOF)/*用count6确定学生信息条目数*/
	  {
	  	count6++;
	  }
	  fclose(studentfile);
	  struct Studentinf studentinf[count6];
	  studentfile= fopen("学生信息.txt", "r");
	  i = 0;
	  while(fscanf(studentfile, "%d %s %s %s %s %s %s %s", &studentinf[i].studentid, studentinf[i].school, studentinf[i].major, studentinf[i].name, studentinf[i].gender, studentinf[i].phone, studentinf[i].password, studentinf[i].mailaddr)!=EOF)
	  {
	  	i++;
      }  
	  char stuname[10];/*提取学生姓名*/
	  for (i=0; i<count6; i++)
	  {
	  	if (id == studentinf[i].studentid)
	  	{
	  	 strcpy(stuname, studentinf[i].name);
	  	 break;
		  }
	  }
	  fprintf(student_classfile, "\n");
	  fprintf(student_classfile, "%-16d%-12s%-d", id, stuname, cid);
	  fclose(student_classfile);/*完成学生选课表的增添*/
	  
	  fclose(classfile);
	  classfile= fopen("课程信息.txt", "w");
	  for(i=0; i<count1; i++)/*完成课程信息中已选人数的修改*/
	  {
	  	if (cid == classinf[i].classid)
	  	{
	  		classinf[i].numalready++;
	  		break;
	  		
		  }
	  }
	  for(i=0; i<count1; i++)/*完成课程信息文件的重录*/
	{
	   fprintf(classfile, "%-d %-s %-d %-d %-s %-s %-s %-d %-s %-d %-s %-s %-d\n", classinf[i].classid, classinf[i].classname, classinf[i].credit, classinf[i].totaltime, classinf[i].type, classinf[i].teacher, classinf[i].term, classinf[i].time, classinf[i].place, classinf[i].limnum, classinf[i].briefinf, classinf[i].book, classinf[i].numalready);
	 } 
	 
	 
	 fclose(classfile);
	  
	  
	  printf("\n选课成功！\n");
     }
	else/*已有课程核对是否时间冲突*/ 
	{
	 int time[count3], classs[count3];
	 for (i=0, j=0; i<count2; i++)/*将课程的编号重新赋值给一个编号数组*/
	 {
	  if (id == classpicked[i].studentid)
	  {
	  	classs[j] = classpicked[i].classid;
	  	j++;
	  }
	 }

	 for (j=0, k=0; j<count3; j++)/*将编号数组与课程信息表对照获得对应的时间数组*/
	 {
	  for (i=0; i<count1; i++)
	  {
	  	if (classs[j]== classinf[i].classid)
	  	{
	  	  time[k]= classinf[i].time;
	  	  k++;
		  break; 	 
		  }
	  }
	 }/*下面验证输入的课程时间是否与时间数组里的时间重复*/

	 int classtime;
	 for (i=0; i<count1; i++)/*取得该课程的时间*/
	 {
	   if (cid == classinf[i].classid)
	   {
	   	classtime = classinf[i].time;
	   	break;
	   }
	 }
	  int test;
	  for (i=0, test=0; i < count3; i++)/*与时间数组比较*/
	  {
	  	if (classtime == time[i])
	  	{
	  	  test = 1;
	  	  break;
		  }
	  }

	 if (test)
	 printf("\n时间冲突\n");
	 else/*可以选该课*/
	 {
	  fclose(student_classfile);
	  student_classfile= fopen("学生选课表.txt", "a");
	  studentfile= fopen("学生信息.txt", "r");
	  int count6=0;
	  int b1;
	  char b2[81], b3[81], b4[81], b5[81], b6[81], b7[81], b8[81];
	  while(fscanf(studentfile, "%d %s %s %s %s %s %s %s", &b1, b2, b3, b4, b5, b6, b7, b8)!=EOF)/*用count6确定学生信息条目数*/
	  {
	  	count6++;
	  }
	  fclose(studentfile);
	  struct Studentinf studentinf[count6];
	  studentfile= fopen("学生信息.txt", "r");
	  i = 0;
	  while(fscanf(studentfile, "%d %s %s %s %s %s %s %s", &studentinf[i].studentid, studentinf[i].school, studentinf[i].major, studentinf[i].name, studentinf[i].gender, studentinf[i].phone, studentinf[i].password, studentinf[i].mailaddr)!=EOF)
	  {
	  	i++;
      }  
	  char stuname[10];/*提取学生姓名*/
	  for (i=0; i<count6; i++)
	  {
	  	if (id == studentinf[i].studentid)
	  	{
	  	 strcpy(stuname, studentinf[i].name);
	  	 break;
		  }
	  }
	  fprintf(student_classfile, "\n");
	  fprintf(student_classfile, "%-16d%-12s%-d", id, stuname, cid);
	  fclose(student_classfile);/*完成学生选课表的增添*/
	  
	  fclose(classfile);
	  classfile= fopen("课程信息.txt", "w");
	  for(i=0; i<count1; i++)/*完成课程信息中已选人数的修改*/
	  {
	  	if (cid == classinf[i].classid)
	  	{
	  		classinf[i].numalready++;
	  		break;
	  		
		  }
	  }
	  for(i=0; i<count1; i++)/*完成课程信息文件的重录*/
	{
	   fprintf(classfile, "%-d %-s %-d %-d %-s %-s %-s %-d %-s %-d %-s %-s %-d\n", classinf[i].classid, classinf[i].classname, classinf[i].credit, classinf[i].totaltime, classinf[i].type, classinf[i].teacher, classinf[i].term, classinf[i].time, classinf[i].place, classinf[i].limnum, classinf[i].briefinf, classinf[i].book, classinf[i].numalready);
	 } 
	 
	 
	 fclose(classfile);
	  
	  printf("\n选课成功！\n");
	  
	  }
	  } 
	}
	}
}
}


void classSearchClassinf()/*按课程名查询课程信息函数首部行*/
{
 FILE *classfile;
 struct Classinf {int classid; char classname[20]; int credit; int totaltime; char type[10]; char teacher[10]; char term[40]; int time; char place[6]; int limnum; char briefinf[80]; char book[30];  int numalready; };
 char name[81];
 printf("\n请输入课程名以提供该课程信息: ");
 scanf("%s", name);
 
classfile = fopen("课程信息.txt", "r");
int s1,s3,s4,s8,s10,s13, count1=0;
char s2[81], s5[81], s6[81], s7[81], s9[81], s11[81], s12[81];/*s[i]系列的变量只做临时容器*/
while (fscanf(classfile, "%d %s %d %d %s %s %s %d %s %d %s %s %d",&s1, s2, &s3, &s4, s5, s6, s7, &s8, s9, &s10, s11, s12, &s13) != EOF)/*读取课程文件以确定有多少条课程信息*/
count1 ++;
fclose (classfile);

classfile = fopen("课程信息.txt", "r");
struct Classinf classinf[count1];
int j=0;
while (fscanf(classfile, "%d %s %d %d %s %s %s %d %s %d %s %s %d", &classinf[j].classid, classinf[j].classname, &classinf[j].credit, &classinf[j].totaltime, classinf[j].type, classinf[j].teacher, classinf[j].term, &classinf[j].time, classinf[j].place, &classinf[j].limnum, classinf[j].briefinf, classinf[j].book, &classinf[j].numalready) != EOF)
{
j++;
}
fclose(classfile);

printf("\n编号   名称         学分 学时 类型  教师   时间  地点  限制人数  教材  已选人数\n");
int i, search,cid;
for (i = 0, search = 1; i < count1 && search; i++)/*搜索是否有该课程*/ 
{
 if (strcmp(name, classinf[i].classname)== 0)
 {
 	printf("%d %s   %d  %d   %s %s   %d    %s %d     %s %d\n", classinf[i].classid, classinf[i].classname, classinf[i].credit, classinf[i].totaltime, classinf[i].type, classinf[i].teacher, classinf[i].time, classinf[i].place, classinf[i].limnum, classinf[i].book, classinf[i].numalready); 
 	search = 0;
 	break;
 }
}
if (search)
printf("\n输入课程名有误！\n");

}



void schoolsearchinf()/*按开课学院查询课程信息函数*/
{
 FILE *classfile, *teacherfile;
 struct Classinf {int classid; char classname[20]; int credit; int totaltime; char type[10]; char teacher[10]; char term[40]; int time; char place[6]; int limnum; char briefinf[80]; char book[30];  int numalready; };
 struct Teacherinf {int teacherid; char school[30]; char teachername[20]; char mailaddr[30];  char password[10]; };
 
 char school[81];
 printf("\n请输入学院名以提供该学院开课信息: ");
 scanf("%s", school);
 
 classfile = fopen("课程信息.txt", "r");
 int s1,s3,s4,s8,s10,s13, count1=0;
 char s2[81], s5[81], s6[81], s7[81], s9[81], s11[81], s12[81];/*s[i]系列的变量只做临时容器*/
 while (fscanf(classfile, "%d %s %d %d %s %s %s %d %s %d %s %s %d",&s1, s2, &s3, &s4, s5, s6, s7, &s8, s9, &s10, s11, s12, &s13) != EOF)/*读取课程文件以确定有多少条课程信息*/
 count1 ++;
 fclose (classfile);

 classfile = fopen("课程信息.txt", "r");
 struct Classinf classinf[count1];
 int j=0;
 while (fscanf(classfile, "%d %s %d %d %s %s %s %d %s %d %s %s %d", &classinf[j].classid, classinf[j].classname, &classinf[j].credit, &classinf[j].totaltime, classinf[j].type, classinf[j].teacher, classinf[j].term, &classinf[j].time, classinf[j].place, &classinf[j].limnum, classinf[j].briefinf, classinf[j].book, &classinf[j].numalready) != EOF)
 {
 j++;
 }
 fclose(classfile);
 
 teacherfile = fopen("教师信息.txt", "r");
 int count2=0, a1;
 char a2[81], a3[81], a4[81], a5[81];/*a系列函数只是临时容器*/
 while(fscanf(teacherfile, "%d %s %s %s %s", &a1, a2, a3, a4, a5)!= EOF)/*第一次读取文件以确认信息条目数*/
 {
 count2++;
 }
 fclose(teacherfile);
 
 teacherfile = fopen("教师信息.txt", "r");
 struct Teacherinf teacherinf[count2];
 int i=0;
 while (fscanf(teacherfile, "%d %s %s %s %s", &teacherinf[i].teacherid, teacherinf[i].school, teacherinf[i].teachername, teacherinf[i].mailaddr, teacherinf[i].password)!= EOF)
 {
 i++;
 }
 printf("\n编号   名称         学分 学时 类型  教师   时间  地点  限制人数  教材  已选人数\n");
 int search, count3=0;
 for (i = 0; i < count1; i++)
 {
  for (j = 0, search=1; j<count2; j++)
  {
   if (strcmp(classinf[i].teacher, teacherinf[j].teachername)==0)
   {
    search = 0;
    break;
   }
  }
   if (strcmp(school, teacherinf[j].school)==0 && search == 0)
   {
   	printf("%d %s   %d  %d   %s %s   %d    %s %d     %s %d\n", classinf[i].classid, classinf[i].classname, classinf[i].credit, classinf[i].totaltime, classinf[i].type, classinf[i].teacher, classinf[i].time, classinf[i].place, classinf[i].limnum, classinf[i].book, classinf[i].numalready);
   	count3++;
   }
 }
  if (count3 == 0)
  {
  	printf("\n没有该学院的开课信息！\n");
  }
 }
 
 
 void class_reorder()/*课程排序函数首部行*/
{FILE *classfile;
 struct Classinf {int classid; char classname[20]; int credit; int totaltime; char type[10]; char teacher[10]; char term[40]; int time; char place[6]; int limnum; char briefinf[80]; char book[30];  int numalready; };
 int choose; 
classfile = fopen("课程信息.txt", "r");
int s1,s3,s4,s8,s10,s13, count1=0;
char s2[81], s5[81], s6[81], s7[81], s9[81], s11[81], s12[81];/*s[i]系列的变量只做临时容器*/
while (fscanf(classfile, "%d %s %d %d %s %s %s %d %s %d %s %s %d",&s1, s2, &s3, &s4, s5, s6, s7, &s8, s9, &s10, s11, s12, &s13) != EOF)/*读取课程文件以确定有多少条课程信息*/
count1 ++;
fclose (classfile);
classfile = fopen("课程信息.txt", "r");
struct Classinf classinf[count1];
int j=0;
while (fscanf(classfile, "%d %s %d %d %s %s %s %d %s %d %s %s %d", &classinf[j].classid, classinf[j].classname,&classinf[j].credit,&classinf[j].totaltime, classinf[j].type, classinf[j].teacher,classinf[j].term, &classinf[j].time,classinf[j].place, &classinf[j].limnum, classinf[j].briefinf, classinf[j].book, &classinf[j].numalready) != EOF)
{
j++;                                                /*将文件信息读入结构*/ 
}
fclose(classfile);
struct Classinf temp;
int rest[count1],i,temp1;
for(i=0;i<count1;i++)
{rest[i]=classinf[i].limnum-classinf[i].numalready;
}
printf("\n按课余量排序请输入1；按选课人数排序请输入2:");
scanf("%d",&choose);
if(choose==1)
{for(i=0;i<count1;i++)              /*对比排序*/ 
 {for(j=0;j<(count1-1);j++)
  {if (rest[j]>rest[j+1])
   {temp=classinf[j];             
    classinf[j]=classinf[j+1];             
    classinf[j+1]=temp;
    temp1=rest[j];
    rest[j]=rest[j+1];
    rest[j+1]=temp1;
   }
  }
 }
 printf("\n编号   名称         学分 学时 类型  教师   时间  地点  限制人数  教材  课余量\n");
 for (i=(count1-1);i>-1;i--)        /*打印课程表*/ 
 {printf("\n%d %-12s %d %d   %s  %-6s %d   %s %-3d %-18s %d", classinf[i].classid, classinf[i].classname, classinf[i].credit, classinf[i].totaltime, classinf[i].type, classinf[i].teacher, classinf[i].time, classinf[i].place, classinf[i].limnum, classinf[i].book,rest[i]); 
 }
}
else if(choose==2)               
{for(i=0;i<count1;i++)                /*对比排序*/ 
 {for(j=0;j<(count1-1);j++)
  {if(classinf[j].numalready>classinf[j+1].numalready)
   {temp=classinf[j];             
    classinf[j]=classinf[j+1];             
    classinf[j+1]=temp;
   }
  }
 }
 printf("\n编号   名称         学分 学时 类型  教师   时间  地点  限制人数  教材  已选人数\n");
 for (i=(count1-1);i>-1;i--)        /*打印课程表*/ 
 {printf("\n%d %-12s %d    %d   %s  %-6s %d   %s %-3d %-18s %d", classinf[i].classid, classinf[i].classname, classinf[i].credit, classinf[i].totaltime, classinf[i].type, classinf[i].teacher, classinf[i].time, classinf[i].place, classinf[i].limnum, classinf[i].book, classinf[i].numalready); 
 }
}
}


void stuclass_check(int id)/*学生查询已选课程函数首部行*/ 
{struct Information_stuclass
 {int id_file;char name[10];int clas;};
 struct Information_Class
 {int classid; char classname[20]; int credit; int totaltime; char type[10]; char teacher[10]; char term[40]; int time; char place[6]; int limnum; char briefinf[80]; char book[30];  int numalready; };
 struct Information_stuclass student[120];
 struct Information_Class classinf[100];
 int i=0,j=0,count,mark,choose,markid[3],markname[3],k=0,classid,choose1,mark1,mark2,year,mon,day,hour,min,sec; 
 FILE *studentclass_file,*class_file;
 if((class_file=fopen("课程信息.txt","r"))==NULL)
 {printf("文件无法打开\n"); 
  }
 while(fscanf(class_file,"%d %s %d %d %s %s %s %d %s %d %s %s %d",&classinf[j].classid, classinf[j].classname, &classinf[j].credit, &classinf[j].totaltime, classinf[j].type, classinf[j].teacher, classinf[j].term, &classinf[j].time, classinf[j].place, &classinf[j].limnum, classinf[j].briefinf, classinf[j].book, &classinf[j].numalready) != EOF)  
 {j++;
 }                           /*读取课程信息，存入结构*/ 
 count=j;                       /*记录课程数量*/ 
 if((studentclass_file=fopen("学生选课表.txt","r"))==NULL)
 {printf("文件无法打开\n"); 
  }
 printf("\n课程编号        课程名称");
 while(fscanf(studentclass_file,"%d %s %d",&student[i].id_file,student[i].name,&student[i].clas)!=EOF)   /*读取学生已选课程信息，存入结构*/ 
 {if(id==student[i].id_file)
  {for(j=count;j>-1;j--)
   {if(classinf[j].classid==student[i].clas)
    {printf("\n%-10d      %-20s",student[i].clas,classinf[j].classname);                              
     markid[k]=i;                /*记录已选课程存储位置*/ 
     markname[k]=j;
     k++;
	}
   }
   mark=1;                        /*判断是否选择课程*/ 
  }
  i++;
 }
 if(mark!=1)
 printf("\n\n没有选择任何课程");
 fclose(studentclass_file);
 fclose(class_file);
}


void stuclass_delete(int id)/*学生课程删除函数首部行*/
{struct Information_stuclass
 {int id_file;char name[10];int clas;};
 struct Information_Class
 {int classid; char classname[20]; int credit; int totaltime; char type[10]; char teacher[10]; char term[40]; int time; char place[6]; int limnum; char briefinf[80]; char book[30];  int numalready; };
 struct Information_stuclass student[120];
 struct Information_Class classinf[100];
 int i=0,j=0,count,mark,choose,markid[3],markname[3],k=0,classid,choose1,mark1,mark2,year,mon,day,hour,min,sec,test; 
 FILE *studentclass_file,*class_file;
 if((class_file=fopen("课程信息.txt","r"))==NULL)
 {printf("文件无法打开\n"); 
  }
 while(fscanf(class_file,"%d %s %d %d %s %s %s %d %s %d %s %s %d",&classinf[j].classid, classinf[j].classname, &classinf[j].credit, &classinf[j].totaltime, classinf[j].type, classinf[j].teacher, classinf[j].term, &classinf[j].time, classinf[j].place, &classinf[j].limnum, classinf[j].briefinf, classinf[j].book, &classinf[j].numalready) != EOF)  
 {j++;
 }                           /*读取课程信息，存入结构*/ 
 count=j;                       /*记录课程数量*/ 
 if((studentclass_file=fopen("学生选课表.txt","r"))==NULL)
 {printf("文件无法打开\n"); 
  }
 printf("\n课程编号        课程名称");
 while(fscanf(studentclass_file,"%d %s %d",&student[i].id_file,student[i].name,&student[i].clas)!=EOF)   /*读取学生已选课程信息，存入结构*/ 
 {if(id==student[i].id_file)
  {for(j=count;j>-1;j--)
   {if(classinf[j].classid==student[i].clas)
    {printf("\n%-10d      %-20s",student[i].clas,classinf[j].classname);      
	 markid[k]=i;                /*记录已选课程存储位置*/ 
     markname[k]=j;
     k++;
	}
   }
   mark=1;                        /*判断是否选择课程*/ 
  }
  i++;
 }
 fclose(studentclass_file);
 fclose(class_file);
 
 tm mytime;                   /*读取系统时间*/
 _getsystime(&mytime);      
 year=mytime.tm_year+1900;  
 mon=mytime.tm_mon+1;     
 day=mytime.tm_mday;   
 hour=mytime.tm_hour;  
 min=mytime.tm_min;   
 sec=mytime.tm_sec;
  if (year<YEAR)
 test = 1;
 else
 {
  if (year>YEAR)
  {
  	test = 0;
  }
  else 
  {
   if (mon<MON)
   {
   	test = 1;
   }
   else
   {
   	if (mon>MON)
   	{
   		test = 0;
	   }
	   else
	   {
	   	if (day<DAY)
	   	{
	   		test = 1;
		   }
		   else
		   {
		   	if (day>DAY)
		   	{
		   		test = 0;
			   }
			   else
			   {
			   	if (hour<HOUR)
			   	{
			   		test = 1;
				   }
				   else 
				   {
				   	if (min<MIN)
				   	{
				   		test = 1;
					   }
					   else 
					   {
					   	if (sec<SEC)
					   	{
					   		test = 1;
						   }
						   else
						   test = 0;
					   }
				   }
			   }
		   }
	   }
   }
  }
 }
 
    
 if(mark!=1)
 {printf("\n没有选择任何课程");  
 }
 else if(test)    /*判断时间是否截止*/
 {printf("\n删除课程请输入1;输入其他数字返回成功登录界面:");   
  scanf("%d",&choose);
  if(choose==1)
  {printf("\n输入要删除的课程编号：");
   scanf("%d",&classid);
   if(classid==student[markid[0]].clas||classid==student[markid[1]].clas||classid==student[markid[2]].clas)  /*检测已经选择的课程中是否有输入编号的课程*/ 
  {printf("\n是否确认删除以下课程？"); 
   if(classid==student[markid[0]].clas)
   {printf("\n%-10d      %-20s",student[markid[0]].clas,classinf[markname[0]].classname);                    /*将输入的编号与已选课程以依次比对，相同则打印*/  
    mark1=markid[0];
	mark2=markname[0];}
   else if(classid==student[markid[1]].clas) 
   {printf("\n%-10d      %-20s",student[markid[1]].clas,classinf[markname[1]].classname);
    mark1=markid[1];
	mark2=markname[1];}
   else if(classid==student[markid[2]].clas)
   {printf("\n%-10d      %-20s",student[markid[2]].clas,classinf[markname[2]].classname);
    mark1=markid[2];
	mark2=markname[2];}
   printf("\n确认删除请输入1；输入其他数字取消删除：");
   scanf("%d",&choose1) ;
   if(choose1==1)
   {studentclass_file=fopen("学生选课表.txt","w"); 
    class_file=fopen("课程信息.txt","w");
    for(i=0;student[i].id_file;i++)     /*将更新后的信息重新写入学生文件*/ 
    {if(i!=mark1)                       /*写入文件时跳过删除的课程*/ 
	 {fprintf(studentclass_file,"%-16d%-12s%-d\n",student[i].id_file,student[i].name,student[i].clas);
	 }
	}
	classinf[mark2].numalready--;     /*将删除掉的课程人数减1*/ 
	for(j=0;j<count;j++)                  /*将更新后的信息重新写入课程文件*/ 
	{fprintf(class_file,"%d %s %d %d %s %s %s %d %s %d %s %s %d\n",classinf[j].classid, classinf[j].classname, classinf[j].credit, classinf[j].totaltime, classinf[j].type, classinf[j].teacher, classinf[j].term, classinf[j].time, classinf[j].place, classinf[j].limnum, classinf[j].briefinf, classinf[j].book, classinf[j].numalready) ;
	} 
	printf("\n删除课程成功！"); 
	fclose(studentclass_file);
    fclose(class_file);
   }
  }
  else 
  printf("\n已选课程中不包含此门课程！");
  }
 }
 else
 {printf("\n选课截止，选课信息无法修改！"); 
  printf("\n现在将返回成功登录界面\n");
 }
}


void persclassinf(int id)/*教师查询个人开课信息函数首部*/ 
{
 FILE *classfile, *teacherfile;
 struct Classinf {int classid; char classname[20]; int credit; int totaltime; char type[10]; char teacher[10]; char term[40]; int time; char place[6]; int limnum; char briefinf[80]; char book[30];  int numalready; };
 struct Teacherinf {int teacherid; char school[30]; char teachername[20]; char mailaddr[30];  char password[10]; };
 
 teacherfile = fopen("教师信息.txt", "r");
 int count1=0, a1;
 char a2[81], a3[81], a4[81], a5[81];/*a系列函数只是临时容器*/
 while(fscanf(teacherfile, "%d %s %s %s %s", &a1, a2, a3, a4, a5)!= EOF)/*第一次读取文件以确认信息条目数*/
 {
 count1++;
 }
 fclose(teacherfile);
 
 teacherfile = fopen("教师信息.txt", "r");
 struct Teacherinf teacherinf[count1];
 int i=0;
 while (fscanf(teacherfile, "%d %s %s %s %s", &teacherinf[i].teacherid, teacherinf[i].school, teacherinf[i].teachername, teacherinf[i].mailaddr, teacherinf[i].password)!= EOF)
 {
 i++;
 }
 char name[81];/*提取教师姓名*/
 for (i=0; i<count1; i++)
 {
  if (id == teacherinf[i].teacherid)
  {
  	strcpy(name, teacherinf[i].teachername);
  	break;
  }
 }
 
classfile = fopen("课程信息.txt", "r");
int s1,s3,s4,s8,s10,s13, count2 = 0;
char s2[81], s5[81], s6[81], s7[81], s9[81], s11[81], s12[81];/*s[i]系列的变量只做临时容器*/
while (fscanf(classfile, "%d %s %d %d %s %s %s %d %s %d %s %s %d",&s1, s2, &s3, &s4, s5, s6, s7, &s8, s9, &s10, s11, s12, &s13) != EOF)/*读取课程文件以确定有多少条课程信息*/
count2 ++;
fclose (classfile);

classfile = fopen("课程信息.txt", "r");
struct Classinf classinf[count2];
int j=0;
while (fscanf(classfile, "%d %s %d %d %s %s %s %d %s %d %s %s %d", &classinf[j].classid, classinf[j].classname, &classinf[j].credit, &classinf[j].totaltime, classinf[j].type, classinf[j].teacher, classinf[j].term, &classinf[j].time, classinf[j].place, &classinf[j].limnum, classinf[j].briefinf, classinf[j].book, &classinf[j].numalready) != EOF)
{
j++;
}
fclose(classfile);

int count3=0;
printf("\n下面是您所开设的课程信息：\n");
printf("\n");
printf("编号   课程名称   学分 学时 性质 教师 时间 地点 限制人数 教材 已选人数\n");

for (i=0; i<count2; i++)/*搜索课程信息找出匹配项并输出到显示器*/
{
  if (strcmp(name, classinf[i].teacher) == 0)
  {
  	printf("%d %s  %d  %d  %s %s %d %s %d %s %d\n", classinf[i].classid, classinf[i].classname, classinf[i].credit, classinf[i].totaltime, classinf[i].type, classinf[i].teacher, classinf[i].time, classinf[i].place, classinf[i].limnum, classinf[i].book, classinf[i].numalready);
  	count3++;
  }
}
if (count3 == 0)
{
	printf("\n您未开设课程！\n");
}
}


int teacher_checkin()/*教师登录函数首部行*/ 
{struct Information_tea 
 {int id_file;char college[15];char name[10];char mail[30];char password_file[20]; };
 int id,i;
 char password[20];
 FILE *teacher_file;
 struct Information_tea teacher[16];
 if((teacher_file=fopen("教师信息.txt","r"))==NULL)
 {printf("文件无法打开\n"); 
  }
 for(i=0;i<16;i++)   /*读取教师信息*/
 {fscanf(teacher_file,"%d %s %s %s %s",&teacher[i].id_file,teacher[i].college,teacher[i].name,teacher[i].mail,teacher[i].password_file);
 }
 while(i==16)
 {printf("\n请输入工号："); 
  scanf("%d",&id); 
  printf("\n请输入密码：");
  scanf("%s",password);
  fclose(teacher_file);
  for(i=0;i<16;i++)     /*比对教师工号及密码*/ 
  {if(id==teacher[i].id_file)
   {if(strcmp(password,teacher[i].password_file)==0)
    {printf("\n登录成功！");}
    else
    {printf("\n密码错误！请重新输入"); 
    i=16;
	}
    break;
   }
   if(i==15)
   printf("\n帐号不存在！请重新输入");
  } 
 }
 return(id);    /*向主程序返回教师工号*/ 
}


void nameSearchStuinf()/*按学生姓名查找函数首部行*/ 
{
 FILE *studentfile;
 struct Studentinf {int studentid; char school[20]; char major[20]; char name[10]; char gender[5]; char phone[15]; char password[10]; char mailaddr[20];};
 char name[81];
 
 printf("\n请输入学生姓名完成信息查找： ");
 scanf("%s", name);
 
 studentfile= fopen("学生信息.txt", "r");
 int count1=0;
 int b1, i;
 char b2[81], b3[81], b4[81], b5[81], b6[81], b7[81], b8[81];
 while(fscanf(studentfile, "%d %s %s %s %s %s %s %s", &b1, b2, b3, b4, b5, b6, b7, b8)!=EOF)/*用count1确定学生信息条目数*/
{
 count1++;
}
 fclose(studentfile);
 
 struct Studentinf studentinf[count1];
 studentfile= fopen("学生信息.txt", "r");
	  i = 0;
	  while(fscanf(studentfile, "%d %s %s %s %s %s %s %s", &studentinf[i].studentid, studentinf[i].school, studentinf[i].major, studentinf[i].name, studentinf[i].gender, studentinf[i].phone, studentinf[i].password, studentinf[i].mailaddr)!=EOF)
	  {
	  	i++;
      }  
 
  int test;
 for (i=0, test=1; i<count1; i++)/*检测是否有该学生信息*/
 {
 	if(strcmp(name, studentinf[i].name)== 0)
 	{
 	  printf("%d  %s  %s  %s  %s\n", studentinf[i].studentid, studentinf[i].school, studentinf[i].major, studentinf[i].name, studentinf[i].gender);
 	  test = 0;
 	  break;
	 }
 }
 
 if (test)
 printf("\n没有该学生！\n");
 
}


void orderclassinf(int id)/*统计选课信息函数首部行*/
{
 FILE *classfile, *teacherfile;
 struct Classinf {int classid; char classname[20]; int credit; int totaltime; char type[10]; char teacher[10]; char term[40]; int time; char place[6]; int limnum; char briefinf[80]; char book[30];  int numalready; };
 struct Teacherinf {int teacherid; char school[30]; char teachername[20]; char mailaddr[30];  char password[10]; };
 
 teacherfile = fopen("教师信息.txt", "r");
 int count1=0, a1;
 char a2[81], a3[81], a4[81], a5[81];/*a系列函数只是临时容器*/
 while(fscanf(teacherfile, "%d %s %s %s %s", &a1, a2, a3, a4, a5)!= EOF)/*第一次读取文件以确认信息条目数*/
 {
 count1++;
 }
 fclose(teacherfile);
 
 teacherfile = fopen("教师信息.txt", "r");
 struct Teacherinf teacherinf[count1];
 int i=0;
 while (fscanf(teacherfile, "%d %s %s %s %s", &teacherinf[i].teacherid, teacherinf[i].school, teacherinf[i].teachername, teacherinf[i].mailaddr, teacherinf[i].password)!= EOF)
 {
 i++;
 }
 
 char name[81];/*提取教师姓名*/
 for (i=0; i<count1; i++)
 {
  if (id == teacherinf[i].teacherid)
  {
  	strcpy(name, teacherinf[i].teachername);
  	break;
  }
 }
 
classfile = fopen("课程信息.txt", "r");
int s1,s3,s4,s8,s10,s13, count2 = 0;
char s2[81], s5[81], s6[81], s7[81], s9[81], s11[81], s12[81];/*s[i]系列的变量只做临时容器*/
while (fscanf(classfile, "%d %s %d %d %s %s %s %d %s %d %s %s %d",&s1, s2, &s3, &s4, s5, s6, s7, &s8, s9, &s10, s11, s12, &s13) != EOF)/*读取课程文件以确定有多少条课程信息*/
count2 ++;
fclose (classfile);

classfile = fopen("课程信息.txt", "r");
struct Classinf classinf[count2];
int j=0;
while (fscanf(classfile, "%d %s %d %d %s %s %s %d %s %d %s %s %d", &classinf[j].classid, classinf[j].classname, &classinf[j].credit, &classinf[j].totaltime, classinf[j].type, classinf[j].teacher, classinf[j].term, &classinf[j].time, classinf[j].place, &classinf[j].limnum, classinf[j].briefinf, classinf[j].book, &classinf[j].numalready) != EOF)
{
j++;
}
fclose(classfile);

int count3=0;/*设置开设课程数目变量*/

for (i=0; i<count2; i++)/*搜索课程信息确认开课数目*/
{
  if (strcmp(name, classinf[i].teacher) == 0)
  {
  	count3++;
  }
}

printf("\n您已开设%d门课程,下面将按选课人数排序\n", count3);
printf("\n编号   名称         学分 学时 类型  教师   时间  地点  限制人数  教材  已选人数\n");

if (count3 == 0)
{
	printf("\n您未开设课程！\n");
}

if (count3 == 1)
{
  for (i=0; i<count2; i++)
  {
  	if (strcmp(name, classinf[i].teacher) == 0)
  	{
    printf("%d %s  %d  %d  %s %s %d %s %d %s %d\n", classinf[i].classid, classinf[i].classname, classinf[i].credit, classinf[i].totaltime, classinf[i].type, classinf[i].teacher, classinf[i].time, classinf[i].place, classinf[i].limnum, classinf[i].book, classinf[i].numalready);
    break;
	}
   }
 } 
 
 if(count3 == 2)
 {
 	struct Classinf personalclass[count3], temp;
 	for (i=0, j=0; i<count2; i++)
 	{
 	 if (strcmp(name, classinf[i].teacher) == 0)
 	 {
 	 	personalclass[j] = classinf[i];
 	 	j++;
	  }
	 }
	 if (personalclass[0].numalready < personalclass[1].numalready)
	 {
	 	temp = personalclass[0];
	 	personalclass[0] = personalclass[1];
	 	personalclass[1] = temp;
	 }
	 
	 for (i=0; i<count3; i++)
	 {
	  printf("%d %s  %d  %d  %s %s %d %s %d %s %d\n", personalclass[i].classid, personalclass[i].classname, personalclass[i].credit, personalclass[i].totaltime, personalclass[i].type, personalclass[i].teacher, personalclass[i].time, personalclass[i].place, personalclass[i].limnum, personalclass[i].book, personalclass[i].numalready);
	 }
	 
 }
 
}


void classSearchStuinf()/*按课程名查询学生信息函数首部行*/ 
{
 FILE *classfile, *student_classfile,  *studentfile; 
 struct Classinf {int classid; char classname[20]; int credit; int totaltime; char type[10]; char teacher[10]; char term[40]; int time; char place[6]; int limnum; char briefinf[80]; char book[30];  int numalready; };
 struct Classpicked {int studentid; char studentname[10]; int classid;};
 struct Studentinf {int studentid; char school[20]; char major[20]; char name[10]; char gender[5]; char phone[15]; char password[10]; char mailaddr[20];};
 
 char name[81];
 printf("\n请输入课程名以提供所有选课学生信息: ");
 scanf("%s", name);
 
classfile = fopen("课程信息.txt", "r");
int s1,s3,s4,s8,s10,s13, count1=0;
char s2[81], s5[81], s6[81], s7[81], s9[81], s11[81], s12[81];/*s[i]系列的变量只做临时容器*/
while (fscanf(classfile, "%d %s %d %d %s %s %s %d %s %d %s %s %d",&s1, s2, &s3, &s4, s5, s6, s7, &s8, s9, &s10, s11, s12, &s13) != EOF)/*读取课程文件以确定有多少条课程信息*/
count1 ++;
fclose (classfile);

classfile = fopen("课程信息.txt", "r");
struct Classinf classinf[count1];
int j=0;
while (fscanf(classfile, "%d %s %d %d %s %s %s %d %s %d %s %s %d", &classinf[j].classid, classinf[j].classname, &classinf[j].credit, &classinf[j].totaltime, classinf[j].type, classinf[j].teacher, classinf[j].term, &classinf[j].time, classinf[j].place, &classinf[j].limnum, classinf[j].briefinf, classinf[j].book, &classinf[j].numalready) != EOF)
{
j++;
}
fclose(classfile);

int i, search,cid;
for (i = 0, search = 1; i < count1 && search; i++)/*搜索是否有该课程*/ 
{
 if (strcmp(name, classinf[i].classname)== 0)
 {
 	cid = classinf[i].classid;
 	search = 0;
 	break;
 }
}
if (search)
printf("\n输入课程名有误！\n");

 
else
{ 
 student_classfile = fopen("学生选课表.txt","r");/*确认学生选课表信息数量*/
 int a1, a3, count2=0;
 char a2[81];/*a[i]系列变量只做临时容器*/
 while (fscanf(student_classfile, "%d %s %d", &a1, a2, &a3)!= EOF)
 count2++;
 fclose (student_classfile);
 
 student_classfile = fopen("学生选课表.txt","r");
 struct Classpicked classpicked[count2];
 i = 0;
 while(fscanf(student_classfile, "%d %s %d", &classpicked[i].studentid, classpicked[i].studentname, &classpicked[i].classid)!= EOF)
 {
  i++;
 }

int count3=0;/*该计数变量用于确认该课程选课人数*/
for (i=0; i<count2; i++)
{
 if (cid == classpicked[i].classid)
 {
  count3++;
  } 
}

int sid[count3], j;/*建立学生号数组*/
for (i=0, j=0; i<count2; i++)
{
 if (cid == classpicked[i].classid)
 {
  sid[j] = classpicked[i].studentid;
  j++;
 }
}

studentfile= fopen("学生信息.txt", "r");
int count4=0;
int b1;
char b2[81], b3[81], b4[81], b5[81], b6[81], b7[81], b8[81];
while(fscanf(studentfile, "%d %s %s %s %s %s %s %s", &b1, b2, b3, b4, b5, b6, b7, b8)!=EOF)/*用count4确定学生信息条目数*/
{
count4++;
}
fclose(studentfile);

struct Studentinf studentinf[count4];
studentfile= fopen("学生信息.txt", "r");
i = 0;
while(fscanf(studentfile, "%d %s %s %s %s %s %s %s", &studentinf[i].studentid, studentinf[i].school, studentinf[i].major, studentinf[i].name, studentinf[i].gender, studentinf[i].phone, studentinf[i].password, studentinf[i].mailaddr)!=EOF)
{
i++;
}

printf("\n以下是选择该课的所有学生信息：\n");
for(i=0; i<count3; i++)
{
	for(j=0; j<count4; j++)
	{
	  if (sid[i] == studentinf[j].studentid)
	  {
	  	printf("%d  %s  %s  %s  %s\n", studentinf[j].studentid, studentinf[j].school, studentinf[j].major, studentinf[j].name, studentinf[j].gender);
	  	break;
	  }
	}
  }  
}	

}


void addClass(int id)/*课程添加函数首部行*/
{
FILE *classfile, *teacherfile;
struct Classinf {int classid; char classname[20]; int credit; int totaltime; char type[10]; char teacher[10]; char term[40]; int time; char place[6]; int limnum; char briefinf[80]; char book[30];  int numalready; };
struct Teacherinf {int teacherid; char school[30]; char teachername[20]; char mailaddr[30];  char password[10]; };

 teacherfile = fopen("教师信息.txt", "r");/*建立教师信息结构数组*/
 int count1=0, a1;
 char a2[81], a3[81], a4[81], a5[81];/*a系列函数只是临时容器*/
 while(fscanf(teacherfile, "%d %s %s %s %s", &a1, a2, a3, a4, a5)!= EOF)/*第一次读取文件以确认信息条目数*/
 {
 count1++;
 }
 fclose(teacherfile);
 
 teacherfile = fopen("教师信息.txt", "r");
 struct Teacherinf teacherinf[count1];
 int i=0;
 while (fscanf(teacherfile, "%d %s %s %s %s", &teacherinf[i].teacherid, teacherinf[i].school, teacherinf[i].teachername, teacherinf[i].mailaddr, teacherinf[i].password)!= EOF)
 {
 i++;
 }
 
 char name[81];/*根据id提取教师姓名*/
 for (i=0; i<count1; i++)
 {
  if (id == teacherinf[i].teacherid)
  {
  	strcpy(name, teacherinf[i].teachername);
  	break;
  }
  } 

 classfile = fopen("课程信息.txt", "r");/*建立课程信息结构数组*/
 int s1,s3,s4,s8,s10,s13, count2 = 0;
 char s2[81], s5[81], s6[81], s7[81], s9[81], s11[81], s12[81];/*s[i]系列的变量只做临时容器*/
 while (fscanf(classfile, "%d %s %d %d %s %s %s %d %s %d %s %s %d",&s1, s2, &s3, &s4, s5, s6, s7, &s8, s9, &s10, s11, s12, &s13) != EOF)/*读取课程文件以确定有多少条课程信息*/
 count2 ++;
 fclose (classfile);

 classfile = fopen("课程信息.txt", "r");
 struct Classinf classinf[count2];
 int j=0;
 while (fscanf(classfile, "%d %s %d %d %s %s %s %d %s %d %s %s %d", &classinf[j].classid, classinf[j].classname, &classinf[j].credit, &classinf[j].totaltime, classinf[j].type, classinf[j].teacher, classinf[j].term, &classinf[j].time, classinf[j].place, &classinf[j].limnum, classinf[j].briefinf, classinf[j].book, &classinf[j].numalready) != EOF)
{
j++;
}
fclose(classfile);

int classnum=0, classtime;
/*得到已开设的课程数目*/
for (i=0; i<count2; i++)
{
 if (strcmp(name, classinf[i].teacher) == 0)
 {
 classnum++;
 classtime = classinf[i].time;
}
}

if (classnum >= 2)
printf("\n超过开设课程数目限制\n\n");
else/*可以开课*/
{
 if (classnum == 0)/*还没有开设课程的情况*/ 
 { 
  printf("\n请按提示输入课程信息\n");
  struct Classinf classs;
  printf("\n请输入6位课程编号：");
test1: 
   do
  {
  	scanf("%d", &classs.classid);
  	if (classs.classid>999999 || classs.classid<100000)
	  printf("\n不满足6位，请重新输入："); 
   } while(classs.classid>999999 || classs.classid<100000);
   
   int test;
   for (i=0, test=0; i<count2; i++)
   {
   	if (classs.classid == classinf[i].classid)
   	{
	test = 1;
   	printf("\n与已有课程编号重复，请重新输入：");
   	break;
   }
   }
   if (test)
   goto test1;/*设置课程编号*/
   
   do
   {
   printf("\n请输入课程名：");
   scanf("%s", classs.classname);
   for(i=0, test=0; i<count2; i++)
   {
   	if(strcmp(classs.classname, classinf[i].classname)==0)
   	{
	test = 1;
   	printf("\n与已有课程名重复，需要重新输入\n");
   	break;
   }
   }
   }while(test);/*设置课程名*/
   
   do
   {
   	test = 0;
   	printf("\n请输入学分：");
   	scanf("%d", &classs.credit);
   	if(classs.credit>4||classs.credit<1)
   	{
	   test = 1;
	   printf("\n学分为1到4分，需重新输入\n");
    }
   }while(test);/*设置学分*/
   
   do
   {
   	test = 0;
    printf("\n请输入学时（16或者32）：");
    scanf("%d", &classs.totaltime);
    if (classs.totaltime!=16 && classs.totaltime!=32)
    {
    	test =1;
    	printf("\n学时格式不符，需重新输入\n");
	}
   }while(test);/*设置学时*/
   
   do
   {
   	test = 0;
   	printf("\n请输入课程性质（选修或者必修）：");
   	scanf("%s", classs.type);
   	if (strcmp(classs.type, "选修")!=0 && strcmp(classs.type, "必修")!=0)
   	{
   		test = 1;
   		printf("\n课程性质不符，需重新输入：\n");
	   }
	} while(test);/*设置课程性质*/
	
	strcpy(classs.teacher, name);/*设置教师*/
	
	printf("\n请输入课程起止时间，格式为201*-201*学年第*学期第*周-第*周：");
	scanf("%s", classs.term);/*设置起止时间*/
	
	do
	{
	test = 0;
	printf("\n请输入上课时间对应数字\n1--8:00-8:50\n2--9:00-9:50\n3--10:00-10:50\n4--11:00-11:50\n5--13:30-14:20\n6--14:30-15:20\n7--15:30-16:20\n8--16:30-17:20\n9--18:30-19:20\n10--19:30-20:20\n输入：");
	scanf("%d", &classs.time);
	if (classs.time<1 || classs.time>10)
	{
	 test = 1;
	 printf("\n时间数字有误，需重新输入\n");
	}
    }while(test);/*设置上课时间*/
	
	printf("\n请输入上课地点，格式为楼号-房间号：");
	scanf("%s", classs.place);/*设置上课地点*/
	
	do
	{
	 test = 0;
	 printf("\n请输入课程限制人数（80或100）：");
	 scanf("%d", &classs.limnum);
	 if (classs.limnum!=80 && classs.limnum!=100)
	 {
	  test = 1;
	  printf("\n课程限制人数输入有误，需重新输入\n");
	 }
	}while(test);/*设置限制人数*/
	
	printf("\n请输入课程简介（35字以内）:");
	scanf("%s", classs.briefinf);/*输入简介*/
	
	printf("\n请输入教材名称，格式为《书名》：");
	scanf("%s", classs.book);/*输入教材名*/
	
	classs.numalready = 0;/*初始化已选人数*/
	
	classfile = fopen("课程信息.txt", "a");
	fprintf(classfile,"\n");
	fprintf(classfile, "%d %s %d %d %s %s %s %d %s %d %s %s %d", classs.classid, classs.classname, classs.credit, classs.totaltime, classs.type, classs.teacher, classs.term, classs.time, classs.place, classs.limnum, classs.briefinf, classs.book, classs.numalready);/*完成添加*/   
	printf("\n开课成功\n");
    fclose(classfile);
 } 
 
 else/*已开设了一门*/
 {
  printf("\n请按提示输入课程信息\n");
  struct Classinf classs;
  printf("\n请输入6位课程编号：");
test3: 
   do
  {
  	scanf("%d", &classs.classid);
  	if (classs.classid>999999 || classs.classid<100000)
	  printf("\n不满足6位，请重新输入："); 
   } while(classs.classid>999999 || classs.classid<100000);
   
   int test;
   for (i=0, test=0; i<count2; i++)
   {
   	if (classs.classid == classinf[i].classid)
   	{
	test = 1;
   	printf("\n与已有课程编号重复，请重新输入：");
   	break;
   }
   }
   if (test)
   goto test3;/*设置课程编号*/
   
   do
   {
   printf("\n请输入课程名：");
   scanf("%s", classs.classname);
   for(i=0, test=0; i<count2; i++)
   {
   	if(strcmp(classs.classname, classinf[i].classname)==0)
   	{
	test = 1;
   	printf("\n与已有课程名重复，需要重新输入\n");
   	break;
   }
   }
   }while(test);/*设置课程名*/
   
   do
   {
   	test = 0;
   	printf("\n请输入学分：");
   	scanf("%d", &classs.credit);
   	if(classs.credit>4||classs.credit<1)
   	{
	   test = 1;
	   printf("\n学分为1到4分，需重新输入\n");
    }
   }while(test);/*设置学分*/
   
   do
   {
   	test = 0;
    printf("\n请输入学时（16或者32）：");
    scanf("%d", &classs.totaltime);
    if (classs.totaltime!=16 && classs.totaltime!=32)
    {
    	test =1;
    	printf("\n学时格式不符，需重新输入\n");
	}
   }while(test);/*设置学时*/
   
   do
   {
   	test = 0;
   	printf("\n请输入课程性质（选修或者必修）：");
   	scanf("%s", classs.type);
   	if (strcmp(classs.type, "选修")!=0 && strcmp(classs.type, "必修")!=0)
   	{
   		test = 1;
   		printf("\n课程性质不符，需重新输入：\n");
	   }
	} while(test);/*设置课程性质*/
	
	strcpy(classs.teacher, name);/*设置教师*/
	
	printf("\n请输入课程起止时间，格式为201*-201*学年第*学期第*周-第*周：");
	scanf("%s", classs.term);/*设置起止时间*/
	
	test4:
	do
	{
	test = 0;
	printf("\n请输入上课时间对应数字\n1--8:00-8:50\n2--9:00-9:50\n3--10:00-10:50\n4--11:00-11:50\n5--13:30-14:20\n6--14:30-15:20\n7--15:30-16:20\n8--16:30-17:20\n9--18:30-19:20\n10--19:30-20:20\n输入：");
	scanf("%d", &classs.time);
	if (classs.time<1 || classs.time>10)
	{
	 test = 1;
	 printf("\n时间数字有误，需重新输入\n");
	}
    }while(test);/*设置上课时间*/
    if (classs.time == classtime)
    { 
    printf("\n与已开设时间冲突，请重新设定\n");
    goto test4;
    } 
    
	
	printf("\n请输入上课地点，格式为楼号-房间号：");
	scanf("%s", classs.place);/*设置上课地点*/
	
	do
	{
	 test = 0;
	 printf("\n请输入课程限制人数（80或100）：");
	 scanf("%d", &classs.limnum);
	 if (classs.limnum!=80 && classs.limnum!=100)
	 {
	  test = 1;
	  printf("\n课程限制人数输入有误，需重新输入\n");
	 }
	}while(test);/*设置限制人数*/
	
	printf("\n请输入课程简介（35字以内）:");
	scanf("%s", classs.briefinf);/*输入简介*/
	
	printf("\n请输入教材名称，格式为《书名》：");
	scanf("%s", classs.book);/*输入教材名*/
	
	classs.numalready = 0;/*初始化已选人数*/
	
	classfile = fopen("课程信息.txt", "a");
	fprintf(classfile,"\n");
	fprintf(classfile, "%d %s %d %d %s %s %s %d %s %d %s %s %d", classs.classid, classs.classname, classs.credit, classs.totaltime, classs.type, classs.teacher, classs.term, classs.time, classs.place, classs.limnum, classs.briefinf, classs.book, classs.numalready);/*完成添加*/
    printf("\n开课成功\n");
    fclose(classfile);
 }
 }
 }
 
 
 void modiclassinf(int id)/*修改课程信息函数首部行*/
{
 FILE *classfile, *teacherfile;
 struct Classinf {int classid; char classname[20]; int credit; int totaltime; char type[10]; char teacher[10]; char term[40]; int time; char place[6]; int limnum; char briefinf[80]; char book[30];  int numalready; };
 struct Teacherinf {int teacherid; char school[30]; char teachername[20]; char mailaddr[30];  char password[10]; };
 
 int cid, test;
 printf("\n请输入想修改的您所开设课程的编号：");
 scanf("%d", &cid);
 
 classfile = fopen("课程信息.txt", "r");/*建立课程信息结构数组*/
 int s1,s3,s4,s8,s10,s13, count1 = 0;
 char s2[81], s5[81], s6[81], s7[81], s9[81], s11[81], s12[81];/*s[i]系列的变量只做临时容器*/
 while (fscanf(classfile, "%d %s %d %d %s %s %s %d %s %d %s %s %d",&s1, s2, &s3, &s4, s5, s6, s7, &s8, s9, &s10, s11, s12, &s13) != EOF)/*读取课程文件以确定有多少条课程信息*/
 count1 ++;
 fclose (classfile);

 classfile = fopen("课程信息.txt", "r");
 struct Classinf classinf[count1];
 int j=0;
 while (fscanf(classfile, "%d %s %d %d %s %s %s %d %s %d %s %s %d", &classinf[j].classid, classinf[j].classname, &classinf[j].credit, &classinf[j].totaltime, classinf[j].type, classinf[j].teacher, classinf[j].term, &classinf[j].time, classinf[j].place, &classinf[j].limnum, classinf[j].briefinf, classinf[j].book, &classinf[j].numalready) != EOF)
  {
 j++;
 }
 fclose(classfile);
 
 int i, count2= -1;/*搜索是否有该课程，如果有就保存它的序号*/
 for (i=0; i<count1; i++)
 {
  if (cid == classinf[i].classid)
  {
   count2 = i;
   break;
  }
 }
 
 if (count2 == -1)
 printf("\n没有该条课程信息！\n");
 
 else
 {
   teacherfile = fopen("教师信息.txt", "r");/*建立教师信息结构数组*/
   int count3=0, a1;
   char a2[81], a3[81], a4[81], a5[81];/*a系列函数只是临时容器*/
   while(fscanf(teacherfile, "%d %s %s %s %s", &a1, a2, a3, a4, a5)!= EOF)/*第一次读取文件以确认信息条目数*/
  {
  count3++;
  }
  fclose(teacherfile);
 
  teacherfile = fopen("教师信息.txt", "r");
  struct Teacherinf teacherinf[count3];
  i=0;
  while (fscanf(teacherfile, "%d %s %s %s %s", &teacherinf[i].teacherid, teacherinf[i].school, teacherinf[i].teachername, teacherinf[i].mailaddr, teacherinf[i].password)!= EOF)
  {
  i++;
  }
 
 char name[81];/*根据id提取教师姓名*/
 for (i=0; i<count3; i++)
 {
  if (id == teacherinf[i].teacherid)
  {
  	strcpy(name, teacherinf[i].teachername);
  	break;
  }
  } 
  fclose(teacherfile);
  
  if (strcmp(name, classinf[count2].teacher) != 0)
  {
   printf("\n该课程不是您所开设，无法修改！\n");
  }
  
  else/*确认是该教师开设的课程*/
  {
  	if (classinf[count2].numalready == 0)/*还没有人选该课*/
  	{
  		printf("\n还没有人选该课，可以修改教材，课程简介，限制人数, 下面请根据提示完成修改\n");
  		printf("\n是否修改教材？请输入对应数字: 1-是，2-否");
  		int chocode1;
  		scanf("%d", &chocode1);
  		if (chocode1 == 1)
  		{
  		 printf("\n原书名%s, 请重新输入教材信息：", classinf[count2].book);
         scanf("%s", classinf[count2].book); 
		  }
		  
		printf("\n是否修改课程简介？请输入对应数字：1-是，2-否");
		int chocode2;
		scanf("%d", &chocode2);
		if (chocode2 == 1)
		{
		 printf("\n请重新录入课程简介：");
		 scanf("%s", classinf[count2].briefinf);
		}
		
		printf("\n是否修改限制人数？请输入对应数字：1-是，2-否");
		int chocode3;
		scanf("%d", &chocode3);
		if (chocode3 == 1)
		{
		 printf("\n原限制人数%d, 请重新输入限制人数（80或100）\n", classinf[count2].limnum);
		 do
	     {
	      test = 0;
	      printf("\n请输入课程限制人数（80或100）：");
	      scanf("%d", &classinf[count2].limnum);
	      if (classinf[count2].limnum!=80 && classinf[count2].limnum!=100)
	     {
	       test = 1;
	       printf("\n课程限制人数输入有误，需重新输入\n");
	     }
	     }while(test);/*设置限制人数*/
		}
		
		classfile = fopen("课程信息.txt", "w");/*重录课程信息*/
		for (i=0; i<count1; i++)
		{
		fprintf(classfile, "%d %s %d %d %s %s %s %d %s %d %s %s %d\n", classinf[i].classid, classinf[i].classname, classinf[i].credit, classinf[i].totaltime, classinf[i].type, classinf[i].teacher, classinf[i].term, classinf[i].time, classinf[i].place, classinf[i].limnum, classinf[i].briefinf, classinf[i].book, classinf[i].numalready);
	    }
		printf("\n课程信息修改成功！\n");		
	  }
	  
	  else/*已经有人选课*/
	  {
	  	printf("\n已有人选该课，只能修改限制人数\n");
	  	printf("\n是否修改限制人数？请输入对应数字：1-是，2-否");
	    int chocode4; 
	    scanf("%d", &chocode4);
	    if(chocode4 == 1)
	    {
	     printf("\n原限制人数%d, 请重新输入限制人数（80或100）\n", classinf[count2].limnum);
		 do
	     {
	      test = 0;
	      printf("\n请输入课程限制人数（80或100）：");
	      scanf("%d", &classinf[count2].limnum);
	      if (classinf[count2].limnum!=80 && classinf[count2].limnum!=100)
	     {
	       test = 1;
	       printf("\n课程限制人数输入有误，需重新输入\n");
	     }
	     }while(test);/*设置限制人数*/
		}
		classfile = fopen("课程信息.txt", "w");/*重录课程信息*/
		for (i=0; i<count1; i++)
		{
		fprintf(classfile, "%d %s %d %d %s %s %s %d %s %d %s %s %d\n", classinf[i].classid, classinf[i].classname, classinf[i].credit, classinf[i].totaltime, classinf[i].type, classinf[i].teacher, classinf[i].term, classinf[i].time, classinf[i].place, classinf[i].limnum, classinf[i].briefinf, classinf[i].book, classinf[i].numalready);
	    }
		printf("\n完成\n");
	  }
  }	
  } 
}


void deleteclass(int id)/*教师删课函数首部行*/
{
 FILE *classfile, *teacherfile, *student_classfile; 
 struct Classinf {int classid; char classname[20]; int credit; int totaltime; char type[10]; char teacher[10]; char term[40]; int time; char place[6]; int limnum; char briefinf[80]; char book[30];  int numalready; };
 struct Teacherinf {int teacherid; char school[30]; char teachername[20]; char mailaddr[30];  char password[10]; };
 struct Classpicked {int studentid; char studentname[10]; int classid;};
 
 int cid, test;
 printf("\n请输入想修改的您所开设课程的编号：");
 scanf("%d", &cid);
 
 classfile = fopen("课程信息.txt", "r");/*建立课程信息结构数组*/
 int s1,s3,s4,s8,s10,s13, count1 = 0;
 char s2[81], s5[81], s6[81], s7[81], s9[81], s11[81], s12[81];/*s[i]系列的变量只做临时容器*/
 while (fscanf(classfile, "%d %s %d %d %s %s %s %d %s %d %s %s %d",&s1, s2, &s3, &s4, s5, s6, s7, &s8, s9, &s10, s11, s12, &s13) != EOF)/*读取课程文件以确定有多少条课程信息*/
 count1 ++;
 fclose (classfile);

 classfile = fopen("课程信息.txt", "r");
 struct Classinf classinf[count1];
 int j=0;
 while (fscanf(classfile, "%d %s %d %d %s %s %s %d %s %d %s %s %d", &classinf[j].classid, classinf[j].classname, &classinf[j].credit, &classinf[j].totaltime, classinf[j].type, classinf[j].teacher, classinf[j].term, &classinf[j].time, classinf[j].place, &classinf[j].limnum, classinf[j].briefinf, classinf[j].book, &classinf[j].numalready) != EOF)
  {
 j++;
 }
 fclose(classfile);
 
 int i, count2= -1;/*搜索是否有该课程，如果有就保存它的序号*/
 for (i=0; i<count1; i++)
 {
  if (cid == classinf[i].classid)
  {
   count2 = i;
   break;
  }
 }
 
 if (count2 == -1)
 printf("\n没有该条课程信息！\n");
 
 else
 {
   teacherfile = fopen("教师信息.txt", "r");/*建立教师信息结构数组*/
   int count3=0, a1;
   char a2[81], a3[81], a4[81], a5[81];/*a系列函数只是临时容器*/
   while(fscanf(teacherfile, "%d %s %s %s %s", &a1, a2, a3, a4, a5)!= EOF)/*第一次读取文件以确认信息条目数*/
  {
  count3++;
  }
  fclose(teacherfile);
 
  teacherfile = fopen("教师信息.txt", "r");
  struct Teacherinf teacherinf[count3];
  i=0;
  while (fscanf(teacherfile, "%d %s %s %s %s", &teacherinf[i].teacherid, teacherinf[i].school, teacherinf[i].teachername, teacherinf[i].mailaddr, teacherinf[i].password)!= EOF)
  {
  i++;
  }
 
 char name[81];/*根据id提取教师姓名*/
 for (i=0; i<count3; i++)
 {
  if (id == teacherinf[i].teacherid)
  {
  	strcpy(name, teacherinf[i].teachername);
  	break;
  }
  } 
  fclose(teacherfile);
  
  if (strcmp(name, classinf[count2].teacher) != 0)
  {
   printf("\n该课程不是您所开设，无法删除！\n");
  }	
  
  else/*确认是该教师开设的课程*/
  {
  	if (classinf[count2].numalready != 0)
  	{
  	 printf("\n已有学生选该课，不可删除\n");
	  }
  	
  	else
  	{
  		printf("\n目前无人选该课，执行删除中\n");
  		classfile= fopen("课程信息.txt", "w");
  		for (i=0; i<count1; i++)
  		{
  		 if (i != count2)
  		 {
  		 	fprintf(classfile, "%d %s %d %d %s %s %s %d %s %d %s %s %d\n", classinf[i].classid, classinf[i].classname, classinf[i].credit, classinf[i].totaltime, classinf[i].type, classinf[i].teacher, classinf[i].term, classinf[i].time, classinf[i].place, classinf[i].limnum, classinf[i].briefinf, classinf[i].book, classinf[i].numalready);
		   }
  			
		  }
		student_classfile = fopen("学生选课表.txt","r");/*确认学生选课表信息数量*/
        int a1, a3, count4= 0;
        char a2[81];/*a[i]系列变量只做临时容器*/
        while (fscanf(student_classfile, "%d %s %d", &a1, a2, &a3)!= EOF)
        count4++;
        fclose (student_classfile);
        
        student_classfile = fopen("学生选课表.txt","r");
        struct Classpicked classpicked[count4];
        int k = 0;
        while (fscanf(student_classfile, "%d %s %d", &classpicked[k].studentid, classpicked[k].studentname, &classpicked[k].classid)!= EOF)
        {
         k++;
		}
        fclose(student_classfile);
        
        student_classfile = fopen("学生选课表.txt", "w");
        for (k=0; k<count4; k++)
        {
         if (cid != classpicked[k].classid)
         {
          fprintf(student_classfile, "%-16d%-12s%-d\n", classpicked[k].studentid, classpicked[k].studentname, classpicked[k].classid);
		 }
		}
    
		  printf("\n删除成功！\n");
	  }
  	
  	
  	} 
 
 } 
}


void teacher_information(int id)/*教师修改个人信息函数首部行*/
{struct Information_tea 
{int id_file;char college[15];char name[10];char mail[30];char password_file[20]; };
 int i,choose,j=0,mark,choose1,count=0;
 int test1=0,test2=0,test3=0; 
 char password1[20],password2[20],mail[30];
 FILE *teacher_file;
 
 if((teacher_file=fopen("教师信息.txt","r"))==NULL)
 {printf("文件无法打开\n"); 
  }

 else
 {
  struct Information_tea teacher1;
 while(fscanf(teacher_file,"%d %s %s %s %s",&teacher1.id_file,teacher1.college,teacher1.name,teacher1.mail,teacher1.password_file)!= EOF)
 {
 	count++;
 }
 fclose(teacher_file);
 
  teacher_file=fopen("教师信息.txt","r");
  struct Information_tea teacher[count];
 printf("工号       学院            姓名       邮箱                           密码            \n"); /*从文件中读取并打印当前工号下教师信息*/ 
 for(i=0;i<count;i++) 
 {fscanf(teacher_file,"%d %s %s %s %s",&teacher[i].id_file,teacher[i].college,teacher[i].name,teacher[i].mail,teacher[i].password_file);
  if(id==teacher[i].id_file)
  {mark=i;
   printf("%9d %-15s %-10s %-30s %-20s\n",teacher[i].id_file,teacher[i].college,teacher[i].name,teacher[i].mail,teacher[i].password_file);
  }
 }
 i=mark;    /*记录当前工号下信息存储位置*/ 
 printf("\n修改信息请输入1;输入其他数字返回登录成功页面：");
 scanf("%d",&choose1); 
 if(choose1==1)
 {printf("\n修改个人邮箱请输入1；修改密码请输入2：");
  scanf("%d",&choose);
  if(choose==1)
  {while(!test1)
  {j=1;
   test3=0;
   printf("\n请输入新邮箱：");     
   scanf("%s",mail);
   while(mail[j])      /*验证邮箱格式*/
   {if(mail[j]=='@')
    {break;}
    j++;
   }
   j=j+2;
   while(mail[j])
   {if(mail[j]=='.')
    break;
    j++;
   }
   if (mail[0]=='@')
   test3=1;
   if((!mail[j+1])||(test3==1))
   {printf("\n邮箱格式错误！请重新输入：");
   }
   
   else
   {printf("\n邮箱修改成功！");
    strcpy(teacher[i].mail,mail);
    test1=1;
   }
  }
  }
  else if(choose==2)
  {while(!test2)
   {printf("\n请输入旧密码：");/*验证密码一致性*/ 
    scanf("%s",password1);
    if(strcmp(password1,teacher[i].password_file)==0)
    {while(!test1)
	 {printf("\n请输入新密码（密码不可包括空格）：");   
      scanf("%s",password1);
      printf("\n请再次输入新密码：");
      scanf("%s",password2);
      if(strcmp(password1,password2)==0)
      {strcpy(teacher[i].password_file,password1);
       printf("\n密码修改成功！");
       break;
      }
	  else
	   printf("\n两次输入密码不一致！"); 
	 }
	 break;
    }
    else
    printf("\n密码输入错误！");
   }
  }
 fclose(teacher_file);
 if((teacher_file=fopen("教师信息.txt","w"))==NULL)
 {printf("文件无法打开\n"); 
  }
  for(i=0;i<16;i++)     /*将更新后的信息重新写入文件*/ 
  {fprintf(teacher_file,"%9d %-15s %-10s %-30s %-20s\n",teacher[i].id_file,teacher[i].college,teacher[i].name,teacher[i].mail,teacher[i].password_file);
  }
  fclose(teacher_file);
 }
}
}


void autodelete()/*自动删除冷门函数首部行*/
{
 int year,mon,day,hour,min,sec, test, count=0;	
 tm mytime;
  FILE *classfile, *student_classfile;
  struct Classinf {int classid; char classname[20]; int credit; int totaltime; char type[10]; char teacher[10]; char term[40]; int time; char place[6]; int limnum; char briefinf[80]; char book[30];  int numalready; };            
  struct Classpicked {int studentid; char studentname[10]; int classid;};
 
 _getsystime(&mytime);/*读取系统时间*/      
 year=mytime.tm_year+1900;  
 mon=mytime.tm_mon+1;     
 day=mytime.tm_mday;   
 hour=mytime.tm_hour;  
 min=mytime.tm_min;   
 sec=mytime.tm_sec;   
 

 if (year<YEAR)
 test = 1;
 else
 {
  if (year>YEAR)
  {
  	test = 0;
  }
  else 
  {
   if (mon<MON)
   {
   	test = 1;
   }
   else
   {
   	if (mon>MON)
   	{
   		test = 0;
	   }
	   else
	   {
	   	if (day<DAY)
	   	{
	   		test = 1;
		   }
		   else
		   {
		   	if (day>DAY)
		   	{
		   		test = 0;
			   }
			   else
			   {
			   	if (hour<HOUR)
			   	{
			   		test = 1;
				   }
				   else 
				   {
				   	if (min<MIN)
				   	{
				   		test = 1;
					   }
					   else 
					   {
					   	if (sec<SEC)
					   	{
					   		test = 1;
						   }
						   else
						   test = 0;
					   }
				   }
			   }
		   }
	   }
   }
  }
 }
 
 if (test == 1)
 printf("\n未超过截止时间\n");
 else
 {
 	printf("\n超过选课时间，正在删除人数小于2的课程");
 	classfile = fopen("课程信息.txt", "r");
 	struct Classinf classs;
 	while(fscanf(classfile,"%d %s %d %d %s %s %s %d %s %d %s %s %d",&classs.classid, classs.classname, &classs.credit, &classs.totaltime, classs.type, classs.teacher, classs.term, &classs.time, classs.place, &classs.limnum, classs.briefinf, classs.book, &classs.numalready) != EOF)  
   {
   	count ++;
   }                         
   fclose(classfile);
   
   classfile = fopen("课程信息.txt", "r");
   struct Classinf classinf[count];
   int i =0;
   while(fscanf(classfile,"%d %s %d %d %s %s %s %d %s %d %s %s %d",&classinf[i].classid, classinf[i].classname, &classinf[i].credit, &classinf[i].totaltime, classinf[i].type, classinf[i].teacher, classinf[i].term, &classinf[i].time, classinf[i].place, &classinf[i].limnum, classinf[i].briefinf, classinf[i].book, &classinf[i].numalready) != EOF)
   {
   	i++;
   }
   fclose(classfile);
   
   classfile = fopen("课程信息.txt", "w");
   int count1=0; 
   for (i=0; i<count; i++)
   {
   	if (classinf[i].numalready >= 2)
   	{
   		fprintf(classfile,"%d %s %d %d %s %s %s %d %s %d %s %s %d\n", classinf[i].classid, classinf[i].classname, classinf[i].credit, classinf[i].totaltime, classinf[i].type, classinf[i].teacher, classinf[i].term, classinf[i].time, classinf[i].place, classinf[i].limnum, classinf[i].briefinf, classinf[i].book, classinf[i].numalready);
	   }
	   else count1++;/*记录删除了几条课程*/
	   }/*在课程信息文件里删除该课程*/
	   fclose(classfile);
   
   int cid[count1], j;
   for (i=0, j=0; i<count; i++)
   {
   	if (classinf[i].numalready<2)
   	{
   		cid[j] = classinf[i].classid;
   		j++;
	   }
	} /*建立删除课程的ID数组*/
   
    student_classfile = fopen("学生选课表.txt","r");/*确认学生选课表信息数量*/
    int a1, a3, count2= 0;
    char a2[81];/*a[i]系列变量只做临时容器*/
    while (fscanf(student_classfile, "%d %s %d", &a1, a2, &a3)!= EOF)
    count2++;
    fclose (student_classfile);
    
    student_classfile = fopen("学生选课表.txt","r");
        struct Classpicked classpicked[count2];
        int k = 0;
        while (fscanf(student_classfile, "%d %s %d", &classpicked[k].studentid, classpicked[k].studentname, &classpicked[k].classid)!= EOF)
        {
         k++;
		}
        fclose(student_classfile);
        
        student_classfile = fopen("学生选课表.txt","w");
        for (i=0; i<count2; i++)
        {
        	for (k=0, test=1; k<count1; k++)
        	 {
        	 	if (classpicked[i].classid == cid[k])
        	 	{
        	 	 test = 0;
        	 	 break;
				 }
			 }
			 if (test)
             fprintf(student_classfile, "%-16d%-12s%-d\n", classpicked[i].studentid, classpicked[i].studentname, classpicked[i].classid);
             
			
		}/*完成学生选课表的重录*/
   fclose(student_classfile);
   printf("\n删除完成！\n");
   
   }
}


void student_information(int id)/*学生修改个人信息函数首部行*/
{struct Information_stu 
 {int id_file;char college[15];char major[20];char name[10];char sex[3];char Tel[15];char password_file[20];char mail[30]; };
 int i,mark,choose,j=0,choose1, count=0;
 int test1=0,test2=0,test3=0; 
 char password1[20],password2[20],mail[30];  
 FILE *student_file;
 
 if((student_file=fopen("学生信息.txt","r"))==NULL)
 {printf("文件无法打开\n"); 
  }
  
  else
  {
  	struct Information_stu student1;
  	while(fscanf(student_file,"%d %s %s %s %s %s %s %s",&student1.id_file,student1.college,student1.major,student1.name,student1.sex,student1.Tel,student1.password_file,student1.mail)!= EOF)
 {
 	count++;
 }
 fclose(student_file);
 } 
  student_file=fopen("学生信息.txt","r");
  struct Information_stu student[count];
 printf("学号       学院            专业                     姓名    性别   手机号码\n");  /*从文件中读取并打印当前学号下学生信息*/
 for(i=0;i<count;i++) 
 {fscanf(student_file,"%d %s %s %s %s %s %s %s",&student[i].id_file,student[i].college,student[i].major,student[i].name,student[i].sex,student[i].Tel,student[i].password_file,student[i].mail);
  if(id==student[i].id_file) 
  {printf("%9d %-15s %-20s %10s %3s %15s\n",student[i].id_file,student[i].college,student[i].major,student[i].name,student[i].sex,student[i].Tel); 
   printf("\n密码                 邮箱         21                  \n");
   printf("%-20s %-30s\n",student[i].password_file,student[i].mail);
   mark=i;/*记录当前学号下信息存储位置*/
  }
 }
 i=mark; 
 printf("\n修改信息请输入1；输入其他数字返回登录成功页面:");
 scanf("%d",&choose1); 
 if(choose1==1)
 {printf("\n修改个人邮箱请输入1；修改密码请输入2；修改电话号码请输入3；");
  scanf("%d",&choose);
  if(choose==1)
  {while(!test1)
  {j=1; 
   test3=0;
   printf("\n请输入新邮箱：");     
   scanf("%s",mail);
   while(mail[j])      /*验证邮箱格式*/
   {if(mail[j]=='@')
    {break;}
    j++;
   }
   j=j+2;
   while(mail[j])
   {if(mail[j]=='.')
    break;
    j++;
   }
   if (mail[0]=='@')
   test3=1;
   if((!mail[j+1])||(test3==1))
   {printf("\n邮箱格式错误！请重新输入：");
   }
   else
   {printf("\n邮箱修改成功！");
    strcpy(student[i].mail,mail);
    test1=1;
   }
  }
  }
  else if(choose==2) 
  {while(!test2)
   {printf("\n请输入旧密码："); /*验证密码一致性*/
    scanf("%s",password1);
    if(strcmp(password1,student[i].password_file)==0)
    {while(!test1)
	 {printf("\n请输入新密码（密码不可包括空格）：");
      scanf("%s",password1);
      printf("\n请再次输入新密码：");
      scanf("%s",password2);
      if(strcmp(password1,password2)==0)
      {strcpy(student[i].password_file,password1);
       printf("\n密码修改成功！");
       break;
      }
	  else
	   printf("\n两次输入密码不一致！"); 
	 }
	 break;
    }
    else
    printf("\n密码输入错误！");
   }
  }
  else if(choose==3)
  {printf("\n请输入新手机号码：");
   scanf("%s",student[i].Tel);
   printf("\n修改成功！");
  }
 fclose(student_file);
 if((student_file=fopen("学生信息.txt","w"))==NULL)
 {printf("文件无法打开\n"); 
 }
 for(i=0;i<39;i++)  /*将更新后的信息重新写入文件*/ 
 {fprintf(student_file,"%9d %-15s %-20s %-10s %3s %15s %-20s %-30s\n",student[i].id_file,student[i].college,student[i].major,student[i].name,student[i].sex,student[i].Tel,student[i].password_file,student[i].mail);
 }
 fclose(student_file);
 }
}
