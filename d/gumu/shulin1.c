// Room: /u/xdd/gumu/shulin1.c
// Modify By csy 98/12
#include <ansi.h>
inherit ROOM;

void create()
{
     set("short", HIB"����"NOR);
     set("long", @LONG
��ѹѹ��һ�������֣�һ��С������ͨ�ġ�����һƬ�ž������ް����Ϣ��
�����м���������һ��ʯ��(bei)��
LONG        );

     set("exits", ([
         "east" : __DIR__"sl1",
         "west" : __DIR__"lyy",
     ]));    

     set("outdoors","��Ĺ");

     set("item_desc", ([
         "bei" :HIR"\t\t��������������������������������������
\t\t����������                    ��������
\t\t��������    ��  Ĺ  ��  ��    ��������
\t\t��������                      ��������
\t\t��������������������������������������\n"NOR,
                       ]));
     set("coor/x",-80);
	set("coor/y",140);
	set("coor/z",90);
	set("coor/x",-80);
	set("coor/y",140);
	set("coor/z",90);
	set("coor/x",-80);
	set("coor/y",140);
	set("coor/z",90);
	set("coor/x",-80);
	set("coor/y",140);
	set("coor/z",90);
	setup();
}

