#include <room.h>

inherit ROOM;

void create()
{
    set("short", "����ׯ����");
    set("long",@LONG
�����ǹ���ɽׯ�����š�ׯ���Եú�ΰ�ߴ�װ�λ�������
�ߵ�Ժǽ���Ѷ�ȥ����Ȼ��������ͷ��ׯ��ǰ���ż�����������
���һ���Ѥ�õ������š�
LONG);

	set("exits", ([
        "south" : __DIR__"qianyuan1",
        "east"  : __DIR__"shiqiao" ,       
	]));
        
            set("objects", ([
                __DIR__"npc/puren1" : 1,
                __DIR__"npc/puren3" : 1,
        ]));
    set("outdoors", "taohua");
    set("coor/x",10);
	set("coor/y",-30);
	set("coor/z",0);
	set("coor/x",10);
	set("coor/y",-30);
	set("coor/z",0);
	set("coor/x",10);
	set("coor/y",-30);
	set("coor/z",0);
	set("coor/x",10);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
    
}

