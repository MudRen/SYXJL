// Room: /d/emei/qianfoqiandian.c ������ ��¬��
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "��¬��");
        set("long",
"ǧ���������鴻ƺ����������һ��鴻����������������Ƕ�ü��������\n"
"֮������ǰ���������Ķ��Ƕ�ü�ɵ�Ů���ӣ��˴������羰��ÿ��ʢ�ĳ�\n"
"������ϸ��Ʈ��ͥԺ�����Ƕ�üʮ���澰֮һ��������"MAG"�鴻����"NOR"����\n"
        );

        set("exits", ([
                "southdown" : __DIR__"gate",
		"north" : __DIR__"dian2",
               ]));    
        set("objects", ([
            __DIR__"npc/jingdao" : 1,
              ]));

        set("coor/x",-40);
	set("coor/y",20);
	set("coor/z",110);
	set("coor/x",-40);
	set("coor/y",20);
	set("coor/z",110);
	set("coor/x",-40);
	set("coor/y",20);
	set("coor/z",110);
	setup();
        replace_program(ROOM);
}