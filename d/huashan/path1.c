// path1.c

inherit ROOM;

void create()
{
	set("short", "��ɽ����");
	set("long", @LONG
�����ǻ�ɽ���£�����������С�������µ�һɽ����������ɽ����
ɽ����Զ������һ��������������������ʱ���������롸����ͨ������
���и�С��ׯ�������м��䷿�ݡ�
LONG
	);

	set("exits", ([ /* sizeof() == 3 */
	"west" : "/d/village/eexit",
	"south" : __DIR__"yuquan",
	"northeast" : __DIR__"shaluo",
	]));

	set("no_clean_up", 0);
        set("outdoors", "��ɽ");

	set("coor/x",40);
	set("coor/y",120);
	set("coor/z",0);
	set("coor/x",40);
	set("coor/y",120);
	set("coor/z",0);
	set("coor/x",40);
	set("coor/y",120);
	set("coor/z",0);
	set("coor/x",40);
	set("coor/y",120);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
 
