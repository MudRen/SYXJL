// Room: /u/cuer/emei/dcmen.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������ǧ���ֵĶ������ˣ�����һ�������ţ���ʱ�ж��ҵ�����������
�����������ź�һ��ʯ��չ��������ǰ����ʯ�������߾͵��˹��Ƹ�				
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"dlang3",
  "eastup" : __DIR__"guiyun",
]));
	set("no_clean_up", 0);

	set("coor/x",-10);
	set("coor/y",40);
	set("coor/z",110);
	set("coor/x",-10);
	set("coor/y",40);
	set("coor/z",110);
	set("coor/x",-10);
	set("coor/y",40);
	set("coor/z",110);
	setup();
	replace_program(ROOM);
}
