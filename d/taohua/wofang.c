
#include <room.h>
inherit ROOM;

void create()
{
    set("short", "�Է�");
	set("long", @LONG
���߽���һ���Է���һ���������޵������˱Ƕ������ٽ��黭��
����ǽ�ϡ�����ɴ�֣������⡣С������Ҥ����ƿ�ڵ��һ�����ʢ
��������һ�Ŵ�����ͷ���������Ʊ���
LONG
	);
    set("exits", ([
     "east" :__DIR__"dating",

]));

    set("objects", ([
        "/kungfu/class/taohua/rong" : 1,
        __DIR__"npc/binu" : 2,
    ]) );
	set("coor/x",40);
	set("coor/y",-230);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
