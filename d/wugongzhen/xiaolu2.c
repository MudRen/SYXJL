 // Room: /u/xdd/gumu/xiaolu2
// Modify By csy 98/12
inherit ROOM;
#include <ansi.h>

void create()
{
     set("short",HIG"���С��"NOR);
     set("long", @LONG
����ɽ�µ�С��������ȫ���ƽ�����������ɽ��ȫ���ɵ������������죬
����һ�����������ٰ��ճ��������Ҳ����������ʿ������䡣
LONG        );

     set("outdoors","��Ĺ");

     set("exits", ([
         "northup" : "/d/gumu/xiaolu3",
         "southdown" : __DIR__"xiaolu1",
     ]));

     set("coor/x",-90);
	set("coor/y",150);
	set("coor/z",40);
	set("coor/x",-90);
	set("coor/y",150);
	set("coor/z",40);
	set("coor/x",-90);
	set("coor/y",150);
	set("coor/z",40);
	set("coor/x",-90);
	set("coor/y",150);
	set("coor/z",40);
	setup();
}

