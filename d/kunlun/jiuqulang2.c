// Room: /d/kunlun/jiuqulang2.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "������");
	set("long", @LONG
������ǰ���оŽ����������۵�������ˮ�档һ·������������ʯ��  
Ȫ���仨������ˮɫ���ܡ����ߴ����������ӣ�������������ʯΪ������¥  
��գ�ת�۴�����Сͤ��ӡ�  
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"shanlin1.c",
  "southeast" : __DIR__"jiuqulang1.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
