// Room: liangongfang2.c

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
����һ�����򵥵����������������ҵ������������ţ�����
���е�������������������ɣ�Ϊ����Ӱ��������������û��������
��̸��������ֻ������Щϸ΢�ĺ�������

LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"xiuxishi",
]));
        set("no_clean_up", 0);

        set("coor/x",-100);
	set("coor/y",110);
	set("coor/z",0);
	set("coor/x",-100);
	set("coor/y",110);
	set("coor/z",0);
	set("coor/x",-100);
	set("coor/y",110);
	set("coor/z",0);
	set("coor/x",-100);
	set("coor/y",110);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

