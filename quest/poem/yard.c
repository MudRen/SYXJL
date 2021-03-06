#include <ansi.h>;
inherit ROOM;

int POEMS=20;
string this_place="/quest/poem/yard";
//need to change above line if this room is moved to another place.

string author,title,*poem;
string author1,title1,*poem1;
int length,length1,running;
string current,current_all,last,last_all;
string curr_show;
int index,chance;
int poem_index,answerd,ans_curr,ans_last;

void new_poem();
void copy_to_old();
void do_test();
void do_init(object me);
void poem_reward(object me,string arg);
void poem_reward1(object me);
//void poem_penalty(object me);
int find_newline();
string enscript(string arg);

void create ()
{
    set("short", "兰花厅");
    set("long", @LONG
在这个厅子周围种满了兰花，兰花厅由此而来。在厅子里放着两张大圆桌，一
个上面放着各色茶具。一个上面摆着笔墨纸砚,一位老者坐在桌子的旁边，正在写在
什么，你不禁想看一下他在写什么(what)。
LONG);

  set("exits", ([ /* sizeof() == 3 */

    "south" : "/d/city/shuyuan",

]));

  set("no_fight", 1);

  set("objects", ([
    __DIR__"npc/daxueshi": 1,
  ]));

  set("coor/x",10);
	set("coor/y",20);
	set("coor/z",0);
	set("coor/x",10);
	set("coor/y",20);
	set("coor/z",0);
	set("coor/x",10);
	set("coor/y",20);
	set("coor/z",0);
	set("coor/x",10);
	set("coor/y",20);
	set("coor/z",0);
	setup();

  remove_call_out("do_test");
  poem_index=1;
  running=0;

}

void init()
{   
     add_action("do_answer","answer");
     add_action("do_author","author");
     add_action("do_look","look");
     
     call_out("do_init",1,this_player());

     if(running==0) {
       running=1;
       new_poem();
       copy_to_old();
       new_poem();
       call_out("do_test",2);
     }
}

void do_init(object me)
{ 
    tell_object(me,CYN"\n老者用一种怀疑的眼光看了你一眼，向你说道：\n\n\t"+NOR+YEL+"你可以用"+HIR+"answer ..."+NOR+YEL+"来对诗句，"+HIR+"author ..."+NOR+YEL+"来回答作者姓名。\n\n"NOR);
    return;
}

int do_author(string arg)
{   object me=this_player();
    
    if(!arg) return notify_fail(HIR"作者是谁？\n"NOR);

    if( living(me) ) me->receive_damage("jing",5+random(15));

    arg=replace_string(arg," ","");
    if(me->query_temp("poem/index")!=poem_index ) 
      return notify_fail(HIR"只有对出诗句后才能回答作者是谁。\n"NOR);

    if(answerd==1) return
      notify_fail(HIY"别人已经回答过这首诗的作者了。\n"NOR);
      
    message_vision(CYN"$N说道：这首诗的作者是"+arg+"？\n"NOR,me);
    if(arg==author) { 
         answerd=1;
         write(CYN"老者说道：对了！\n"NOR);
         poem_reward1(me);
    } else {
      me->add_temp("poem/wrong",1);
      if(me->query_temp("poem/wrong")>20)
        {
// poem_penalty(me);
        message_vision(HIR"老者对$N说道：“你再道朱喜那里去学两年再来吧”\n"NOR,me);
        message_vision(HIR"老者说完就将$N推了出去。\n"NOR,me);
        me->move("/d/city/shuyuan");
        }
    }
    return 1;
}

int do_answer(string arg)
{ 
    object me=this_player();

    if(!arg) return notify_fail(HIR"回答什么？\n"NOR);

    if( living(me) ) me->receive_damage("jing",5+random(15));

    arg=replace_string(arg," ","");
    switch(random(2)) {
     case 0: message_vision(CYN"$N说道：可是．．．"+arg+"？\n"NOR,me);
             break;
     case 1: message_vision(CYN"$N答道："+arg+"？\n"NOR,me);
             break;
    }
    if(arg==current&&strlen(current)>2) {
      if(ans_curr==1) {
       write(HIY"别人已经回答过这句诗了。\n"NOR);
       return 1;
      }
      ans_curr=1;
      
      //change to a new poem once this one is answered.
      index=length-1;

      me->set_temp("poem/index",poem_index);
      poem_reward(me,current_all);
    } else if(arg==last&&strlen(last)>2) {
      if(ans_last==1) {
       write(HIY"别人已经回答过这句诗了。\n"NOR);
       return 1;
      }
      ans_last=1;
      poem_reward(me,last_all);
    } else {
      write(RED"老者摇了摇头：好象不对吧？\n"NOR);
      me->add_temp("poem/wrong",1);
      if(me->query_temp("poem/wrong")>20) 
        {
//      poem_penalty(me);
        message_vision(HIR"老者对$N说道：“你再道朱喜那里去学两年再来吧”\n"NOR,me);
        message_vision(HIR"老者说完就将$N推了出去。\n"NOR,me);
        me->move("/d/city/shuyuan");
        }
    }

    return 1;
}

void poem_reward(object me,string arg)
{
    me->set_temp("poem/wrong",0);
      message_vision(HIR"老者点头道："+arg+"好诗！好诗！\n"NOR,me);
    poem_reward1(me);
}

void poem_reward1(object me)
{  
        int dx,pot,lite;

        if ( me->query("combat_exp") >= 50000 )
        {
                 write("你已经无法从对诗中学到东西了。\n");
                 return;
        }

    switch(random(3)) {
     case 0: dx=5+random(18);
             me->add("combat_exp",dx);
             message_vision(YEL"$N的实战经验增加了！\n"NOR,me);
             break;
     case 1: pot=3+random(9);
             if(me->query("potential")+pot-me->query("learned_points")<=400)
               me->add("potential",pot);
             message_vision(YEL"$N的潜能增加了！\n"NOR,me);
             break;
     case 2: lite=3+random(6);
             me->improve_skill("literate",lite);
             message_vision(YEL"$N的读书识字进步了！\n"NOR,me);
             break;
    }

}

void do_test()
{  
   int newt;
   string first,second,quest;

   if(strlen(current)>2&&ans_curr==0) {
     last=current;
     last_all=current_all;
     ans_last=0;
   }
   
   newt=0;
   while(newt==0) {
    if(!find_newline()) {
     copy_to_old();
     new_poem();
    } else {
      if(sscanf(poem[index],"%s  %s",first,second)==2 &&
       !sscanf(poem[index],"%*s［") && 
       !sscanf(poem[index],"%*s（") &&
       !sscanf(poem[index],"%*s□") ) {
         if(strlen(first)>2&&strlen(second)>2) {
           newt=1;
         } 
      }
    }
   }

   first=replace_string(first," ","");
   second=replace_string(second," ","");
   current_all=first+"  "+second;
   ans_curr=0;
   if(random(2)==0) {
     quest=enscript(first);
     current=second;
     curr_show=quest+enscript("．．．");
     switch(random(2)) {
       case 0: 
		tell_room(this_object(),CYN"老者道："+quest+"..."+CYN+"的后半句是什么？\n"NOR);
         break;
       case 1:
		tell_room(this_object(),CYN"老者说："+quest+"．．．"+CYN+"后面是什么来着？\n"NOR);
         break;
     }
   } else {
     quest=enscript(second);
     current=first;
     curr_show=enscript("．．．")+quest;
     switch(random(2)) {
       case 0:
		tell_room(this_object(),CYN"老者道："+quest+CYN+"的前半句是什么？\n"NOR);
         break;
       case 1:
		tell_room(this_object(),CYN"老者说："+quest+CYN+"前面是什么来着？\n\n"NOR);
         break;
     }
   }

   call_out("do_test",60);
   return;
}

int do_look(string arg)
{   int i;

    if(!arg || arg!="what") return 0;

    write("\n\n    "+author1+"："+title1+"\n");
    for (i=0;i<length1;i++) {
      write("    "+poem1[i]+"\n");
    }
    write("\n\n\n");

    write(enscript("当前题目：　　　")+curr_show+"\n\n"NOR);

    return 1;

}

void copy_to_old()
{    int i;
     author1=author;
     title1=title;
     length1=length;
     poem1=({});
     last="";
     for (i=0;i<length;i++)
       poem1+=({poem[i]});
     return;
}

void new_poem()
{   string filename,buf;
    int i,j,k;

    length=0;
    while (length==0) {
    while((k=(1+random(POEMS)))==poem_index);
    filename=__DIR__"poem/poem"+k;
    buf=read_file(filename,1,1);
    sscanf(buf,"%s：%s",author,title);
    i=0;
    j=0;
    poem=({});
    while(buf=read_file(filename,2+i,1)) {
      if(strlen(buf)>2) {
        buf=replace_string(buf,"\n","");
        poem+=({buf});
        j++;
      }
      i++;
    }
    length=j;
    }
    poem_index=k;
    answerd=0;
    index=-1;
    chance=3*100/(1+length);
    if(length<3) {
      chance=100;
    }
    return;
}

int find_newline()
{
   index++;
   while(index<length) {
     if(random(100)<chance) {
       return 1;
     } else index++;
   }
   return 0;
}

string enscript(string arg)
{    string result;
     string *color=({BLK,RED,GRN,YEL,BLU,MAG,CYN,WHT,
                     HIR,HIG,HIY,HIB,HBRED,HBGRN,HBYEL,
                     HBBLU,HBMAG,BBLK,BRED,BGRN});
     int len,i;

     len=sizeof(color);
     result="";
     i=sizeof(arg);
     while(i>2) {
       if(random(2)==0) {
         result=color[random(len)]+NOR+arg[i-2..i-1]+result;
       } else {
         result=arg[i-2..i-1]+result;
       }
       i-=2;
     }
     result=NOR+arg[0..1]+result;

     return result;
}


