//Room: /d/dali/feilihusouth.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
        set("short","С�����ϰ�");
        set("long",@LONG
���������Բ����洬��ͷ��������̨�Ĵ������������񷤣�һЩ
���������º����㣬���ʵ��������ڸ�����ϲ�ݡ����ڵȳ���
�����ü�Ǯ��
LONG);
        set("objects", ([
           __DIR__"npc/yufu": 1,
        ]));
        set("outdoors", "dali");
        set("exits",([ /* sizeof() == 1 */
            "south"      : __DIR__"hexi",
        ]));
        set("coor/x",-10);
	set("coor/y",-200);
	set("coor/z",10);
	set("coor/x",-10);
	set("coor/y",-200);
	set("coor/z",10);
	set("coor/x",-10);
	set("coor/y",-200);
	set("coor/z",10);
	set("coor/x",-10);
	set("coor/y",-200);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}
