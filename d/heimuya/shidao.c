inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
һ·�����У��м����һ����Լ��ߵ�ʯ��������ʯ��
��ǽ��һ·�϶������½�ͽģ�����������߶�����������·
�˶����ܼ��ӡ�
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"shidao3",
  "north" : __DIR__"shidao2",
]));

        set("coor/x",20);
	set("coor/y",-90);
	set("coor/z",0);
	set("coor/x",20);
	set("coor/y",-90);
	set("coor/z",0);
	set("coor/x",20);
	set("coor/y",-90);
	set("coor/z",0);
	set("coor/x",20);
	set("coor/y",-90);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
