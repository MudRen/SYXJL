// room: /d/xingxiu/cave.c
// Jay 3/18/96

inherit ROOM;

int do_use(string arg);
int do_zuan(string arg);

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
���ɽ�������ֲ�����ָ��ֻ�г��ڴ�͸��һ˿���ߡ�
LONG
        );
        set("exits", ([
            "out" : __DIR__"tianroad5",
]));
        set_temp("times" , 1);

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        setup();
        //replace_program(ROOM);
}

void init()
{
        add_action("do_use", "use");
        add_action("do_chu", "chu");
}

int do_use(string arg)
{
        object me;
        me = this_player();

        if( !arg || arg=="" ) return 0;
        if (!present("fire", me))  return 0;
        if( arg=="fire" ) {
        if ( random(100) > 50)
{
        message_vision("��Ȼ����֪�������ﴵ����һ��磡��\n",me);
        message_vision("���ţ�������û����Ӹ���Ϩ�ˣ�\n",me);
        return ;
}

             write(
             "���ȼ�˻��ۣ�����ʯ�ڵĽ������Ȼ����һ��ѩ������\n"
             );
             return 1;
       }
}

int do_chu(string arg)
{
 object me=this_player();
 object ob;
 if (!arg||arg!="ѩ����")
  return notify_fail("��Ҫ��ʲô��\n");
 if (!present("yaochu",me))
  return notify_fail("û��ҩ����ô���ó�ѩ������\n");
 if (query_temp("times")==0)
  return notify_fail("����ϸһ����ȴ������ֻ���������һ���þ���\n");
 ob=new("/d/honghua/xuelian");
 ob->move(environment(me));
 add_temp("times",-1);
 message_vision("$NС�ĵذ����ѩ�������������˳�����\n" , me);
 return 1;
}

