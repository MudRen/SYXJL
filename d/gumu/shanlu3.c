// Room: /u/xdd/gumu/shanlu3.c
// Modify By csy 98/12
#include <ansi.h>

inherit ROOM;

void create()
{
     set("short", YEL"ɽ·"NOR);
     set("long", @LONG
�������ϣ��˴���ɽ·�Ե����ж��ͣ�·����������һ��ʯ��(shibei)��
Զ����ȥ���ɼ�������������������ȫ������֮�������𴦻��ив����Ϳ���
��ʾ䡣
LONG        );

     set("outdoors","��Ĺ");

     set("exits", ([
         "eastup" : __DIR__"ztm",
         "southdown" : "/d/gumu/xiaolu3",
     ]));

     set("item_desc", ([
             "shibei" : HIG"\t\t��Բ�������������Ϊ��������ࣿ \n
\t\t������ҹ����٣�������������� \n
\t\t�������첻Ӧ��һ��ϸ�������Ρ� \n
\t\t���ô�ǧ�����磬������������顣 \n"NOR,
     ]));

     set("coor/x",-90);
	set("coor/y",170);
	set("coor/z",60);
	set("coor/x",-90);
	set("coor/y",170);
	set("coor/z",60);
	set("coor/x",-90);
	set("coor/y",170);
	set("coor/z",60);
	set("coor/x",-90);
	set("coor/y",170);
	set("coor/z",60);
	setup();
}

