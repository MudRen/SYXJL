// chexiangtan.c ����̶ 

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "����̶");
        set("long", @LONG
����λ�ڸ߹��ٲ������Σ����ܾ�ʯͻأ�����ƶ���һ̶���Ƴ���̶��
̶����ף�ϸʯ���ۣ�����������ΪѰ��̽��֮�ѵء����Ͽɵ�����̨��
LONG
        );
        set("outdoors", "quanzhen");

        set("exits", ([
                "southdown" : __DIR__"gaoguanpubu",
                "westup" : __DIR__"sheshentai",
        ]));
        set("objects", ([
                __DIR__"npc/ji" : 1, 
   ]));

        set("coor/x",-70);
	set("coor/y",170);
	set("coor/z",130);
	set("coor/x",-70);
	set("coor/y",170);
	set("coor/z",130);
	set("coor/x",-70);
	set("coor/y",170);
	set("coor/z",130);
	set("coor/x",-70);
	set("coor/y",170);
	set("coor/z",130);
	setup();
        replace_program(ROOM);
}


