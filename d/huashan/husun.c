// husun.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
ǰ������һ��ʮ�ֶ��͵�ɽ�룬��������ֻ��Գ���̾�̨�ϣ���˵��
ǰ�ӻ�ɽˮ����������Գ�ÿ�������Ҫ����ȥ��������Ҳ�е����ڳ�
Խ���������������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"northdown" : __DIR__"laojun",
		"southup" : __DIR__"zhenyue",
	]));
	set("no_clean_up", 0);
        set("outdoors", "��ɽ");

	set("coor/x",70);
	set("coor/y",100);
	set("coor/z",50);
	set("coor/x",70);
	set("coor/y",100);
	set("coor/z",50);
	set("coor/x",70);
	set("coor/y",100);
	set("coor/z",50);
	set("coor/x",70);
	set("coor/y",100);
	set("coor/z",50);
	setup();
	replace_program(ROOM);
}
