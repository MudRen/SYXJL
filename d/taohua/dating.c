#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "�һ�ɽׯ����");
    set("long", 
"�������һ�ɽׯ����������������ʮ�ֿ��������й����˸���\n"
"���ҵ��鷨�漣���������۵��������йҵ�һ��������\n\n"
   
HIB "            �һ�Ӱ�����\n"
    "            �̺�����������\n\n"
NOR

"�����پ�ͦ�Σ����ƺ�ΰ��\n"
);
set("exits", ([
    "north" : __DIR__"qianyuan",
    "south" : __DIR__"houyuan",
    "east"  : __DIR__"shufang",
    "west"  : __DIR__"wofang" ,
]));
set("objects", ([
        "/kungfu/class/taohua/huang" : 1,
    ]) );    

	set("valid_startroom", 1);
	set("coor/x",50);
	set("coor/y",-230);
	set("coor/z",0);
	setup();
	 "/clone/board/taohua_b"->foo();	
	replace_program(ROOM);
}
