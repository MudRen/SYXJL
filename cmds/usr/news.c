//Cmds:/cmds/usr/news.c 
//Created by kittt@djx 
//modified by bsd@SYXJL.MUD


#include <ansi.h>; 
inherit BULLETIN_BOARD; 

//createpart����ͨ��BOARD��� 
void create() 
{ 
  set_name("��Եϴ��¼���Ű�",({"news board"})); 
  set("location","/u/bsd/workroom");//��������һ��ROOM������BOARD�� 
  set("board_id","syxjlnews_b");//��һ��ָ������������Ҳ���ԡ� 
  set("long","��Ե���Ű�\n");
  setup(); 
  set("capacity",500); 
} 

//���������������loginʱ���õġ� 
int check_news(object me) 
{ 
  int num,i,last_time_read; 
  mapping *notes,last_read_time; 
  string myid,msg=""; 
  notes=query("notes"); 
  last_read_time=me->query("board_last_read"+(string)query("board_id")); 
  myid=query("board_id"); 
  if(!pointerp(notes)||!sizeof(notes))return  1; 

  if(userp(me)) 
  { 
	i=sizeof(notes)-me->query("LastReadNews"); 

	if(i<6&&i>0)//С��6�����Ų���ʾ���⣬��Ȼ��FLOOD 
	{ 
	msg=HIC"\n��"HIY"����������Եϴ��¼������Ϣ����������������������������������������������������"HIC"��\n"NOR; 
 
	if(!mapp(last_read_time)||undefinedp(last_read_time[myid])) 
	num=1; 
 
       else 
	for(num=1;num<=sizeof(notes);num++) 
	  if(notes[num-1]["time"]>last_read_time[myid])break; 
 
	if(mapp(last_read_time))last_time_read=last_read_time[myid]; 
	for(i=sizeof(notes)-1;i>num-2;i--) 
	{ 
	 msg+=sprintf(HIY"��"NOR"%3d"HIY"��"NOR,i+1); 
	 msg+=sprintf("%-=25s%18s(%s)\n", 
	 notes[i]["title"],notes[i]["author"], 
//        RTIME_D->chinese_time(5,ctime(notes[i]["time"]))); 
	  ctime(notes[i]["time"])[0..9]);
     } 
 
	msg+=HIC"��"HIY"����������������������������������������������������������ԵС��ͨ����������"HIC"��"NOR; 
	me->start_more(msg); 
    } 
 
    i=sizeof(notes)-me->query("LastReadNews"); 
    if(i<0)i=0; 
    write(HIY"����ԵС��ͨ���������������ϴ�����������"+((i==0)?"û���κ�":"����"+WHT+chinese_number(i)+HIY"��")+"���ţ�\n"NOR); 
    if(i>10)write("�����Help news���鿴����ԵС��ͨ��������������\n");//���Ѳ�֪����NEWSϵͳ�����ʹ��news 
  } 
} 
int main(object me,string arg) 
{ 
  int num,i,last_time_read; 
  mapping *notes,last_read_time; 
  string myid,msg,title,number; 

  last_read_time=me->query("board_last_read"); 
  myid=query("board_id"); 
  notes=query("notes"); 
  i=sizeof(notes)-me->query("LastReadNews"); 
  if(!pointerp(notes)||!sizeof(notes)) 
  return notify_fail(WHT"����ԵС��ͨ�����������Բ��𣬡���Եϴ��¼��Ŀǰû���κ����š�\n"NOR); 
  if(!arg) 
  { 
    if(i<0) i=0; 
    if(i>10)write("�����Help news���鿴��Եϴ��¼����ϵͳ��ʹ�÷�����\n"); 
    write(WHT"����ԵС��ͨ��"NOR"������������Եϴ��¼��Ŀǰ����"+WHT+chinese_number(sizeof(notes))+NOR"������"+((i==0)?"��":"������"+HIY+chinese_number(i)+NOR"����δ������")+"\n");return  1;} 

  if(sscanf(arg,"add%s",title)==1){ 
    if(!title) return notify_fail("��ָ��һ�����ŵı��⡣\n"); 
    if(!wizardp(me)) return notify_fail("�Բ���ֻ����Եϴ��¼����ʦ�ſ��Է������š�\n"); 
    else{ 
	do_post(title); 
	return 1; 
       } 
      } 

  if(sscanf(arg,"del%s",number)==1){ 
    if(!number) return  notify_fail("��Ҫɾ����һ����ŵ����ţ�\n"); 
    if(!wizardp(me))return notify_fail("�Բ���ֻ����Եϴ��¼����ʦ�ſ���ɾ�����š�\n"); 
    else{ 
	do_discard(number); 
	return 1; 
      } 
} 

    if(arg=="all")//��ʾ�������� 
     { 
        msg=HIC"\n��"HIY"����������Եϴ��¼�������ũ���������������������������������������������������"HIC"��\n"NOR; 
	notes=query("notes"); 

	if(mapp(last_read_time))last_time_read=last_read_time[myid]; 
        for(i=sizeof(notes)-1;i>-1;i--) 
       { 
	msg+=sprintf("%s"WHT"��"NOR"%3d"WHT"��"NOR, 
	notes[i]["time"]>last_time_read?HIY:"",i+1); 
	msg+=sprintf("%-=25s%18s(%s)\n", 
	  notes[i]["title"],notes[i]["author"], 
//	  RTIME_D->chinese_time(5,ctime(notes[i]["time"]))); 
	   ctime(notes[i]["time"])[0..9]);
	} 
    msg+=HIC"��"HIY"����������������������������������������������������������ԵС��ͨ������������"HIC"��"NOR; 
       me->start_more(msg); 
       return 1; 
     } 
       if(arg=="new")//��ʾ�������� 
   { 
      if(!mapp(last_read_time)||undefinedp(last_read_time[myid])) 
      num=1; 
      else 
	for(num=1;num<=sizeof(notes);num++) 
	 if(notes[num-1]["time"]>last_read_time[myid])break; 
    } 
    if(!sscanf(arg,"%d",num))return notify_fail("�㵽��Ҫ���ڼ�������ѽ��\n"); 
    if(num<1||num>sizeof(notes)) 
    return notify_fail("������㣬����û����������Ү��\n"); 
  num--; 
  me->start_more(sprintf("\n\n%s\n"RED"�������⣺"HIY"%s\n"WHT"������ʦ��"NOR"%s\n"GRN"����ʱ�䣺%s\n"HIC 
  "��"HIY"����������Եϴ��¼���Ų��ũ�������������������������������������������"HIC"��\n"NOR, 
   HIC"���ǡ���Եϴ��¼�����������ĵ�"+chinese_number(num+1)+"�����š�"NOR, 
   notes[num]["title"],notes[num]["author"], 
   "/cmds/usr/rtime"->chinese_time(5,ctime(notes[num]["time"]))) 
   +notes[num]["msg"]+ 
  HIC"��"HIY"��������������������������������������������������ԵС��ͨ������������"HIC"��"NOR,); 

  if(!mapp(last_read_time)) 
    me->set("board_last_read",([myid:notes[num]["time"]])); 
  else 
    if(undefinedp(last_read_time[myid])||notes[num]["time"]>last_read_time[myid]) 
	last_read_time[myid]=notes[num]["time"]; 

  if(me->query("LastReadNews")<num+1) 
    me->set("LastReadNews",num+1); 
 return 1; 
} 

void init() 
{ 
  object me=this_player(); 
//ֻ��apprentice�������ϵ���ʦ�޸����� 
if(wizardp(me)&&wiz_level(me)>wiz_level("(apprentice)")) 
  { 
    add_action("do_post","broadcast"); 
    add_action("do_post","gb"); 
    add_action("do_discard","discard"); 
}
} 

void done_post(object me,mapping note,string text) 
{ 
  mapping *notes; 

  note["time"]=time(); 
  note["msg"]=text; 
  notes=query("notes"); 
  if(!pointerp(notes)||!sizeof(notes)) 
    notes=({note}); 
  else 
    notes+=({note}); 

  if(sizeof(notes)>query("capacity")) 
    notes=notes[query("capacity")/2..query("capacity")]; 

  set("notes",notes); 
  save(); 
  restore(); 
//ʹ��channel��ʾ��ʾ������������ 
//    CHANNEL_D->do_channel(me,"bidd",BLINK + HIG"����Եϴ��¼�������������ţ���λ�������news�鿴��"NOR); 
  tell_object(me,"���ŷ�����ϡ�\n"); 
  return ; 
} 

int help(object me) 
{ 
write(@HELP 
����Եϴ��¼������ϵͳָ�� 

ָ���ʽ: 
news �鿴���еĺ����·��������š� 
news all��Եϴ��¼����һ���� 
news new�Ķ����µ����š� 
news <���ű��>�鿴�˱�����ŵ���ϸ���ݡ� 
HELP 
); 
return 1; 
} 

