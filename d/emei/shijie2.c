inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
����ɽ�ź�ɽ�ŵ�����������˶������ˡ�һ�����ѵ�ʯ��С��
��ɽ�����죬������ľ���֣���ʱ��Ѳɽ���������������������ö�����
�������������ܵ�������ɫ����ϣ������·һֱ����ȥ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"shmdian",
  "northup" : __DIR__"shenshui",
]));
	
        set("objects",([
           __DIR__"npc/xunshan" : 2,
           ]));

	set("coor/x",-30);
	set("coor/y",-10);
	set("coor/z",70);
	set("coor/x",-30);
	set("coor/y",-10);
	set("coor/z",70);
	set("coor/x",-30);
	set("coor/y",-10);
	set("coor/z",70);
	setup();
	replace_program(ROOM);
}
