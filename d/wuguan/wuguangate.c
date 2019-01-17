// Room: /d/wuguan/wuguangate.c
// Date: 99/05/30 by Byt

inherit ROOM;
void create()
{
        set("short", "��ݴ���");
        set("long", @LONG
������һ����լ�ӣ��ſڸ���һ�����ҡ�������ݡ�����������ʯʨ��
��Ӵ��ſ��ƽ�ȥ�����������������������ܷ�æ�����ӣ��ſ�վ������
�������������ϡ�
LONG );
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("exits", ([
                 "north" : __DIR__"wuguandayuan",
                    "south" : __DIR__"wuguangate1",      
        ]));
        set("objects", ([
		__DIR__"npc/menwei" : 1,
        ]));
        setup();
}

int valid_leave(object me, string dir)
{
        if (me->query("combat_exp") >= 10000 
           && present("men wei", environment(me)) 
           && dir =="north")
             return notify_fail("�������洫����һ����������������ֻ���ɳ��뽭�������֡�\n");
	if (present("men wei", environment(me)) && dir =="south" && me->query("combat_exp") >= 10000)
  	{
      message_vision("��������˵������$N����������������С���ˣ���ȥ�����ϴ����ˡ�\n",me);
             	me->delete("enter_wuguan");
             	message_vision("$N�����񣬲�������ݡ��Ӵ���Ȼ�����ն�Ҳ���ܱӻ��ڴ��ˣ�\n", me);
	}
        return ::valid_leave(me, dir);
        
}
