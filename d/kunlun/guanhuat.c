// Room: /d/kunlun/guanhuat.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "�ۻ�ͤ");
	set("long", @LONG
����һ��С�ɵ�ͤ��, ���ͻ�ʱ��Ϣ֮�á�ͤ��ʯ��ʯ�ʾ�ȫ��ʯ���ϻ� 
�ڷ��ż��̵��ġ������, ��������Ҳ���ڴ�����˶���, ���Ѿ��Ǿ�Զ���� 
���ˡ�ͤ���Ǿ����ȣ����������Ĳ�֪��ͨ��η���������С�������� 
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"jiuqulang3.c",
  "north" : __DIR__"jingsish",
  "northwest" : __DIR__"jiuqulang1.c",
  "south" : __DIR__"xlgf_1",
]));

	setup();
	replace_program(ROOM);
}
