// Room: /d/kunlun/jiuqulang3.c 
 
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
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"guanhuat.c",
  "northeast" : __DIR__"jiuqulang4.c",
]));

	setup();
	replace_program(ROOM);
}
