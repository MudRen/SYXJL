// Room: houyuan.c

inherit ROOM;

void create()
{
        set("short", "��Ժ");
        set("long", @LONG
�����Ǹ�Ժ�ӣ�Ժ�л��ܰ��㸡�����������᷿�Ĵ�����
͸���ƻ�֮�⣬������˸���ѣ��ƺ�����Ӱ�ζ������������
�Ӵ��߹���
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"xiaoting",
  "west" : __DIR__"xxiangfang",
  "north" : __DIR__"beixiangfang.c",
]));
        set("no_clean_up", 0);
        set("outdoors", "none");

        set("coor/x",-140);
	set("coor/y",130);
	set("coor/z",0);
	set("coor/x",-140);
	set("coor/y",130);
	set("coor/z",0);
	set("coor/x",-140);
	set("coor/y",130);
	set("coor/z",0);
	set("coor/x",-140);
	set("coor/y",130);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

