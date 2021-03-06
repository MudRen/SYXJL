//Cmds:/cmds/usr/news.c 
//Created by kittt@djx 
//modified by bsd@SYXJL.MUD


#include <ansi.h>; 
inherit BULLETIN_BOARD; 

//createpart和普通的BOARD差不多 
void create() 
{ 
  set_name("随缘洗剑录新闻版",({"news board"})); 
  set("location","/u/bsd/workroom");//这里用了一个ROOM来放置BOARD。 
  set("board_id","syxjlnews_b");//成一个指令来输入新闻也可以。 
  set("long","随缘新闻版\n");
  setup(); 
  set("capacity",500); 
} 

//这个部份是用来在login时调用的。 
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

	if(i<6&&i>0)//小于6条新闻才显示标题，不然会FLOOD 
	{ 
	msg=HIC"\n≡"HIY"────随缘洗剑录最新消息──────────────────────────"HIC"≡\n"NOR; 
 
	if(!mapp(last_read_time)||undefinedp(last_read_time[myid])) 
	num=1; 
 
       else 
	for(num=1;num<=sizeof(notes);num++) 
	  if(notes[num-1]["time"]>last_read_time[myid])break; 
 
	if(mapp(last_read_time))last_time_read=last_read_time[myid]; 
	for(i=sizeof(notes)-1;i>num-2;i--) 
	{ 
	 msg+=sprintf(HIY"【"NOR"%3d"HIY"】"NOR,i+1); 
	 msg+=sprintf("%-=25s%18s(%s)\n", 
	 notes[i]["title"],notes[i]["author"], 
//        RTIME_D->chinese_time(5,ctime(notes[i]["time"]))); 
	  ctime(notes[i]["time"])[0..9]);
     } 
 
	msg+=HIC"≡"HIY"────────────────────────────随缘小灵通─────"HIC"≡"NOR; 
	me->start_more(msg); 
    } 
 
    i=sizeof(notes)-me->query("LastReadNews"); 
    if(i<0)i=0; 
    write(HIY"【随缘小灵通】告诉您：从您上次收听到现在"+((i==0)?"没有任何":"共有"+WHT+chinese_number(i)+HIY"条")+"新闻！\n"NOR); 
    if(i>10)write("你可以Help news来查看【随缘小灵通】的收听方法。\n");//提醒不知道有NEWS系统的玩家使用news 
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
  return notify_fail(WHT"【随缘小灵通】告诉您：对不起，「随缘洗剑录」目前没有任何新闻。\n"NOR); 
  if(!arg) 
  { 
    if(i<0) i=0; 
    if(i>10)write("你可以Help news来查看随缘洗剑录新闻系统的使用方法。\n"); 
    write(WHT"【随缘小灵通】"NOR"告诉您：「随缘洗剑录」目前共有"+WHT+chinese_number(sizeof(notes))+NOR"条新闻"+((i==0)?"。":"，您有"+HIY+chinese_number(i)+NOR"条尚未收听。")+"\n");return  1;} 

  if(sscanf(arg,"add%s",title)==1){ 
    if(!title) return notify_fail("请指定一个新闻的标题。\n"); 
    if(!wizardp(me)) return notify_fail("对不起，只有随缘洗剑录的巫师才可以发布新闻。\n"); 
    else{ 
	do_post(title); 
	return 1; 
       } 
      } 

  if(sscanf(arg,"del%s",number)==1){ 
    if(!number) return  notify_fail("你要删除哪一个编号的新闻？\n"); 
    if(!wizardp(me))return notify_fail("对不起，只有随缘洗剑录的巫师才可以删除新闻。\n"); 
    else{ 
	do_discard(number); 
	return 1; 
      } 
} 

    if(arg=="all")//显示所有新闻 
     { 
        msg=HIC"\n≡"HIY"────随缘洗剑录所有新闻──────────────────────────"HIC"≡\n"NOR; 
	notes=query("notes"); 

	if(mapp(last_read_time))last_time_read=last_read_time[myid]; 
        for(i=sizeof(notes)-1;i>-1;i--) 
       { 
	msg+=sprintf("%s"WHT"【"NOR"%3d"WHT"】"NOR, 
	notes[i]["time"]>last_time_read?HIY:"",i+1); 
	msg+=sprintf("%-=25s%18s(%s)\n", 
	  notes[i]["title"],notes[i]["author"], 
//	  RTIME_D->chinese_time(5,ctime(notes[i]["time"]))); 
	   ctime(notes[i]["time"])[0..9]);
	} 
    msg+=HIC"≡"HIY"────────────────────────────随缘小灵通──────"HIC"≡"NOR; 
       me->start_more(msg); 
       return 1; 
     } 
       if(arg=="new")//显示最新新闻 
   { 
      if(!mapp(last_read_time)||undefinedp(last_read_time[myid])) 
      num=1; 
      else 
	for(num=1;num<=sizeof(notes);num++) 
	 if(notes[num-1]["time"]>last_read_time[myid])break; 
    } 
    if(!sscanf(arg,"%d",num))return notify_fail("你到底要看第几条新闻呀？\n"); 
    if(num<1||num>sizeof(notes)) 
    return notify_fail("看清楚点，好像没有这条新闻耶。\n"); 
  num--; 
  me->start_more(sprintf("\n\n%s\n"RED"新闻主题："HIY"%s\n"WHT"新闻巫师："NOR"%s\n"GRN"新闻时间：%s\n"HIC 
  "≡"HIY"────随缘洗剑录新闻播放──────────────────────"HIC"≡\n"NOR, 
   HIC"这是「随缘洗剑录」创立以来的第"+chinese_number(num+1)+"条新闻。"NOR, 
   notes[num]["title"],notes[num]["author"], 
   "/cmds/usr/rtime"->chinese_time(5,ctime(notes[num]["time"]))) 
   +notes[num]["msg"]+ 
  HIC"≡"HIY"────────────────────────随缘小灵通──────"HIC"≡"NOR,); 

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
//只给apprentice级别以上的巫师修改新闻 
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
//使用channel显示提示有了最新新闻 
//    CHANNEL_D->do_channel(me,"bidd",BLINK + HIG"【随缘洗剑录】有了最新新闻！各位玩家请用news查看。"NOR); 
  tell_object(me,"新闻发表完毕。\n"); 
  return ; 
} 

int help(object me) 
{ 
write(@HELP 
「随缘洗剑录」新闻系统指令 

指令格式: 
news 查看共有的和最新发布的新闻。 
news all随缘洗剑录新闻一览。 
news new阅读最新的新闻。 
news <新闻编号>查看此编号新闻的详细内容。 
HELP 
); 
return 1; 
} 

