// Room: cjlou.c

inherit ROOM;

void create()
{
	set("short", "�ؾ���һ¥");
	set("long", @LONG
����Ϊ�𷨵���Դ���˴��ؾ�֮�������º�����
ƥ�����ﶼ���������飬�߼��������ܣ���ܼ��������һ��
ͨ�еĿ�϶�����Ŵ�����м䣬����ط������ɳ���������Ŀ��
�������㿴�����Ϸ��˼����𾭡�
LONG
	);

	set("exits", ([
		"out" : __DIR__"zoulang3",
		"up" : __DIR__"cjlou1",
	]));

	set("objects",([
		__DIR__"obj/fojing1" : 1,
		__DIR__"obj/fojing2" : 1,
	]));
	setup();
}

