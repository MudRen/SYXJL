// Room: /d/city2/ximenwai.c



inherit ROOM;



void create()

{

	set("short", "������");

	set("long", @LONG

�����Ǳ�������������Ҳ���Ǳ��ʽ�ʿ�Ǿ۾ӵĺ������ˡ�

���������ݽ����ܲ���ס�Ͼ��Ǳ���������������ˡ�

LONG

	);

	set("exits", ([ /* sizeof() == 2 */

  "north" : __DIR__"Sino-CO",

  "east" : __DIR__"ximen",

  "south" : __DIR__"jifang",

]));

	set("no_clean_up", 0);



	setup();

	replace_program(ROOM);

}

