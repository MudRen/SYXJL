// Room: /u/xdd/gumu/ztm.c
// Modify By csy 98/12
inherit ROOM;
#include <ansi.h>
void create()
{
     set("short",HIG"������"NOR);
     set("long", @LONG
�˵�����ȫ��������ţ�һ��ߴ���Ʒ������ڰ�ɽ�Ŀ������ϣ�ȫ���
�����µ�ʿ�ڴ˷����������ʴ˴�����������ƣ�����������Ů���Ĺ����
�����ġ�
LONG        );

     set("outdoors","��Ĺ");

     set("exits", ([
         "southdown" : __DIR__"jlg",
         "westdown" : __DIR__"shanlu3",
     ]));
        set("objects", ([
                "/d/wudang/npc/guest" : 2, 
   ]));

     set("coor/x",-80);
	set("coor/y",170);
	set("coor/z",70);
	set("coor/x",-80);
	set("coor/y",170);
	set("coor/z",70);
	set("coor/x",-80);
	set("coor/y",170);
	set("coor/z",70);
	set("coor/x",-80);
	set("coor/y",170);
	set("coor/z",70);
	setup();
}


