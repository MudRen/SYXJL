
inherit ROOM;

void create()
{
	set("short", "�͵�");
	set("long", @LONG
����һ�Ҽ�Ǯ�����Ŀ�ջ������ǳ���¡����˵ȫ������
���������ķֵ꣬�������еĿ�ջ����һ�������С���������
����¶�棬˭Ҳ��֪��������������һ���ˡ�
LONG
	);

	set("no_fight", 1);
	set("no_study", 1);
	set("no_yun", 1);
	set("no_beg", 1);
	set("no_steal", 1);
	set("valid_startroom", 1);

	set("objects", ([
		"/d/city/npc/xiaoer" : 1,
             "/d/huanhua/npc/yiren" :1,
	]));

	set("exits", ([
		"west" : __DIR__"nandaj1",
	]));
	set("coor/x",-40);
	set("coor/y",140);
	set("coor/z",0);
	setup();
	"/clone/board/kedian2_b"->foo();
}

