// Room: shanlu3.c

inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
һ��������ɽ·չ���������ǰ������ͨ��ʲô�ط����㲻֪���ٵ���
�ţ�·�ϲ�ʱ��Ұ�ôܳ�����������Ĳݴ��У���һ�²����ˡ����ϼ�ֻ��
������ö���質��һ�ж����������͡�
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"shanlu4",
  "northwest" : __DIR__"hongshuiqi",
]));
        set("no_clean_up", 0);
        set("outdoors", "none");

        set("coor/x",-100);
	set("coor/y",70);
	set("coor/z",0);
	set("coor/x",-100);
	set("coor/y",70);
	set("coor/z",0);
	set("coor/x",-100);
	set("coor/y",70);
	set("coor/z",0);
	set("coor/x",-100);
	set("coor/y",70);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
