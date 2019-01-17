// /u/china/workroom.c
// 残阳轩
#include <ansi.h>
inherit ROOM;
void create()
{
     set("short",GRN"鹿鼎记玩家村"NOR);
     set("long","这里就是著名的"GRN"鹿鼎记玩家村"NOR"，很多人都在这里买了自己的房子！\n"
                "看着一幢幢的新房，真是让人心动，自己也想买一套新房住！\n"
);
//        set("valid_startroom",);
        set("no_fight",1);
        set("no_yun",1);
        set("no_steal",1);
     set("exits", ([
           "east" : "/d/city2/road20",
                  ]));
        set("objects", ([
	"/d/city/npc/cunzhang":1,
                   ]));     set("coor/x",-110);
	set("coor/y",150);
	set("coor/z",0);
	setup();
}
void init()
{add_action("do_enter","enter");}

int do_enter(string arg)
{ object room;
  if (!arg)
  {   write("你要进入哪间房？\n");
      return 1;
  }
  if (arg==this_player()->query("id"))
  {     if (undefinedp(this_player()->query("myroom")))
        {   write("你还没有自己的房间!\n"); 
            return 1;
        }
        room=new("/d/xinfang/xinfang");
        message("vision",
            this_player()->name() + "进入了自己的房间。\n",
            environment(this_player()), ({this_player()}) 
              );
        
        this_player()->move(room);
        return 1;
  }
  else 
  {     if (arg!=this_player()->query_temp("invited"))
        {    write("你并没有受到主人的邀请！\n");
             return 1;
        }
        else if (!find_player(arg)||undefinedp(environment(find_player(arg))->query("owner"))||environment(find_player(arg))->query("owner")!=find_player(arg)->query("id"))
        {    write("可惜主人不在家，没有人给你开门！\n" );
             return 1;
        }
        else 
        {  message("vision",
            this_player()->name() + "应邀走进了"+find_player(arg)->query("name")+"的房间。\n",
            environment(this_player()), ({this_player()}) 
          );
         
           this_player()->move(environment(find_player(arg)));

           tell_room(environment(this_player()),this_player()->query("name")+"走了进来！\n",({this_player()}));        
           return 1;
        }
  }
}

             
        
         
