inherit ROOM;

void create()
{
	set("short", "�߿����");
	set("long", @LONG
�������߿ߵ���ڣ��������һ���ڰ��Ķ�Ѩ��ڣ�һ����������ﴵ
���������˲������������ǻ�ȥ�ɡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"sheku",
  "south" : __DIR__"xdao2",
]));
	set("no_clean_up", 0);

	set("coor/x",-90);
	set("coor/y",80);
	set("coor/z",110);
	set("coor/x",-90);
	set("coor/y",80);
	set("coor/z",110);
	set("coor/x",-90);
	set("coor/y",80);
	set("coor/z",110);
	setup();

}

int valid_leave(object me,string dir)
{object ob,obj,ob1,ob2,ob3,ob4;
 if(dir == "north" && me->query_temp("xia1") == 1)
    {message_vision("�Ӻڰ����߳�һ���ϸ��˶�$N˵�����ܺã��㾭�����ŵ�ͬ�⣬���Խ��߿��ˡ���\n",me);
     ob = find_object(__DIR__"sheku");
     for(;;)
       {if(obj = present("snake",ob))
           destruct(obj);
        else break;
       }
     ob1=new(__DIR__"npc/snake");
     ob2=new(__DIR__"npc/snake");
     ob3=new(__DIR__"npc/snake");
     ob4=new(__DIR__"npc/snake");
     ob1->move(__DIR__"sheku");
     ob2->move(__DIR__"sheku");
     ob3->move(__DIR__"sheku");
     ob4->move(__DIR__"sheku");
     
     return ::valid_leave(me,dir);
    }
 else if(dir == "north")
    
     return notify_fail("�Ӻڰ����߳�һ���ϸ��˵�ס�㣬˵������û�о������ŵ�ͬ�⣬���ܽ��߿ߡ���\n");
 else
  return ::valid_leave(me,dir);  
}