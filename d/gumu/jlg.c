// Room: /u/xdd/gumu/jlg.c
// Modify By csy 98/12
inherit ROOM;
#include <ansi.h>
void create()
{
     set("short",HIC"������"NOR);
     set("long", @LONG
��������ȫ���Ϊ������ʿ�ͽ������׼����ˮ����ʳ�ĵط����ɹ���ɽ
�����������˸��ڱ��γ��꣬���ڽ���ȫ��Ķ�ʢ���������һ�£���
��һ���߲ʽ�����׿Ȼ���ԡ�
LONG        );

     set("outdoors","��Ĺ");

     set("exits", ([
         "northup" : __DIR__"ztm",
         "southup" : __DIR__"ryy",
     ]));

        set("coor/x",-80);
	set("coor/y",160);
	set("coor/z",60);
	set("coor/x",-80);
	set("coor/y",160);
	set("coor/z",60);
	set("coor/x",-80);
	set("coor/y",160);
	set("coor/z",60);
	set("coor/x",-80);
	set("coor/y",160);
	set("coor/z",60);
	setup();
}

