// Room: /u/cuer/emei/beilang2.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������ǧ���ֱ��ߵĻ��ȣ��Ƕ��Ⱥͱ��ȵĽ��㴦��������������������
������ǧ���ֵ��ŷ��������Ϳ��Ե���Ƹ��ˡ�      
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"dlang1",
  "west" : __DIR__"beilang1",
  "east" : __DIR__"shanfang",
]));
	set("no_clean_up", 0);

	set("coor/x",-20);
	set("coor/y",70);
	set("coor/z",110);
	set("coor/x",-20);
	set("coor/y",70);
	set("coor/z",110);
	set("coor/x",-20);
	set("coor/y",70);
	set("coor/z",110);
	setup();
	replace_program(ROOM);
}
