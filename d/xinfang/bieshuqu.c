// /u/china/workroom.c
// ������
#include <ansi.h>
inherit ROOM;
void create()
{
     set("short",GRN"¹������Ҵ�"NOR);
     set("long","�������������"GRN"¹������Ҵ�"NOR"���ܶ��˶������������Լ��ķ��ӣ�\n"
                "����һ�������·������������Ķ����Լ�Ҳ����һ���·�ס��\n"
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
  {   write("��Ҫ�����ļ䷿��\n");
      return 1;
  }
  if (arg==this_player()->query("id"))
  {     if (undefinedp(this_player()->query("myroom")))
        {   write("�㻹û���Լ��ķ���!\n"); 
            return 1;
        }
        room=new("/d/xinfang/xinfang");
        message("vision",
            this_player()->name() + "�������Լ��ķ��䡣\n",
            environment(this_player()), ({this_player()}) 
              );
        
        this_player()->move(room);
        return 1;
  }
  else 
  {     if (arg!=this_player()->query_temp("invited"))
        {    write("�㲢û���ܵ����˵����룡\n");
             return 1;
        }
        else if (!find_player(arg)||undefinedp(environment(find_player(arg))->query("owner"))||environment(find_player(arg))->query("owner")!=find_player(arg)->query("id"))
        {    write("��ϧ���˲��ڼң�û���˸��㿪�ţ�\n" );
             return 1;
        }
        else 
        {  message("vision",
            this_player()->name() + "Ӧ���߽���"+find_player(arg)->query("name")+"�ķ��䡣\n",
            environment(this_player()), ({this_player()}) 
          );
         
           this_player()->move(environment(find_player(arg)));

           tell_room(environment(this_player()),this_player()->query("name")+"���˽�����\n",({this_player()}));        
           return 1;
        }
  }
}

             
        
         
