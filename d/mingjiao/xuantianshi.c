// Room: /d/mingjiao/xuantianshi.c
// Date: XXL 97/05/9

inherit ROOM;

void create()
{
	set("short", "����ʯ");
	set("long", @LONG
��ʯ��Զ����ֻ���ƺ���ã�����վ�������������һ��������
ǧ���һ�ɴ�ý�ɽ����������ʯ��������ഫ˵���ഫ���̵�
��ʮ��������������Ӱ�����ȣ�Doll)Ϊ������֮�ѣ������ڴ�,��
��һ����ѧ�����Ӵ�ʧ����������֮���ڴ�ƾ����Ī�����ᣬ��
������ǴӴ�ʯ��(tiao)�£���Ѱ�ҡ����ؼ���ȴ��û�����ܰ�Ȼ
���顣
LONG
	);

	set("exits", ([
		"down" : __DIR__"shanlu3",
	]));

	set("outdoors", "mingjiao");
	set("coor/x",-150);
	set("coor/y",-60);
	set("coor/z",40);
	setup();
	replace_program(ROOM);
}



