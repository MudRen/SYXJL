// liangong.c
// shilling 97.2

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
���������е�һ��ʯ�ݣ������Ե�ʲô�徻�ͼ��ӣ������в�û��ʲô
�ر�İ�������������ܵ��κζ�����ɧ�ţ��Ǹ������ڹ��ĺõط���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
                "south" : __DIR__"xiaodao4",
]));
	set("coor/x",10);
	set("coor/y",-70);
	set("coor/z",0);
	set("coor/x",10);
	set("coor/y",-70);
	set("coor/z",0);
	set("coor/x",10);
	set("coor/y",-70);
	set("coor/z",0);
	set("coor/x",10);
	set("coor/y",-70);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
