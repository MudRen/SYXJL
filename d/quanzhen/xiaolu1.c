//xiaolu1.c  

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "�ּ�С��");
        set("long", @LONG
������һ��С���ϣ��������������ӣ�����ɭɭ���������أ�������Ҷ
��������������������Ķ�����
LONG
        );

        set("exits", ([
                "north" : __DIR__"xiaolu2",
                "south" : __DIR__"houyuan",
                "west" : __DIR__"xiaolu3",
        ]));

	set("outdoors", "quanzhen");
	set("objects", ([
"/d/quanzhen/npc/liuchuxuan" : 1]));

        set("coor/x",-90);
	set("coor/y",290);
	set("coor/z",190);
	set("coor/x",-90);
	set("coor/y",290);
	set("coor/z",190);
	set("coor/x",-90);
	set("coor/y",290);
	set("coor/z",190);
	set("coor/x",-90);
	set("coor/y",290);
	set("coor/z",190);
	setup();
        
}
int valid_leave(object me, string dir)
{
	mapping fam;

	if (dir == "north")
	{
		if( mapp(fam = me->query("family")) 
		&&  fam["family_name"] == "ȫ���" 
		&&  fam["generation"] == 2  ) 
			return ::valid_leave(me, dir);
		
          if (present("liu chuxuan",environment(me))) {
		
		if( me->query("guilty") == 0 
		&&  !wizardp(me) )
		{
			return notify_fail("������˵��������ɽ���أ����ڽ���֮�У������˵Ȳ������ڣ�����������ȥ����\n");
		}
         }
	}

	return ::valid_leave(me, dir);
}


