#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long",
"����ʯ���ݴ����Ϲ����������ģ�ʯ���Ϻ���"GRN"���𵩵�һ��"NOR"�ĸ��֣�\n"
"���䲻��ȴ�������ƣ�ʹ�˲���Ϊ֮һ�ݣ��˴�ɽ���䶸��ȴʹ������\n"
"��Ȼ���������߾�����Ů���ˡ�\n"
        );

        set("exits", ([
		"northup" : __DIR__"yunvchi",
		"southdown" : __DIR__"jietuo",
               ]));

        set("coor/x",-40);
	set("coor/y",-40);
	set("coor/z",40);
	set("coor/x",-40);
	set("coor/y",-40);
	set("coor/z",40);
	set("coor/x",-40);
	set("coor/y",-40);
	set("coor/z",40);
	setup();
        replace_program(ROOM);
}