//Room: /d/dali/shuangheqiao.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
        set("short","˫����");
        set("long",@LONG
����һ����·�ڣ�����������ʯ��������˫���ţ����ſ�������
Ϫ�ϣ��ű����Ǵ���ǣ��ɴ���ȥ��ͨ���Ϸ���ϲ�ݡ����ڵȳ����
�ٵ���
LONG);
        set("outdoors", "dali");
        set("exits",([ /* sizeof() == 3 */
            "north"     : __DIR__"southgate",
            "west"      : __DIR__"luyuxi",
            "south"     : __DIR__"road4",
        ]));
        set("no_clean_up", 0);
        set("coor/x",-10);
	set("coor/y",-150);
	set("coor/z",10);
	set("coor/x",-10);
	set("coor/y",-150);
	set("coor/z",10);
	set("coor/x",-10);
	set("coor/y",-150);
	set("coor/z",10);
	set("coor/x",-10);
	set("coor/y",-150);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}
