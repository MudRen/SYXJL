inherit ROOM;

void create()
{
    set("short", "���Ϸ�");
    set("long", @LONG
�˴�������ʯ������࿿��ʯ�����϶�����������Ĳ������Ʈ����
���������ϡ����λ�����������һ�㡣����Զ�����̣����･�࣬��
ǰ����һ�Ժ�Ⱥ��houqun���������¡�
LONG
    );
        set("exits",([
            "west" : __DIR__"lianhua",
            "east" : __DIR__"ziyun",
            "north" : __DIR__"yiping",
            "south" : __DIR__"rusheng",
            "down" : __DIR__"wulaoqiao",
        ]));
        set("objects", ([
                __DIR__"npc/houzi": 2,
                __DIR__"npc/xiaohou": 2,
                __DIR__"npc/wolf": 2,

]) );
	set("item_desc", ([
		"houqun" : "��Ⱥ�����������֣�һ�����·�ڣ�һ���ִ��Ϸ嶥��\n",
	]));
	setup();
}
int valid_leave(object me, string dir)
{
        if (dir == "down" && this_player()->query("age")>12)
                return notify_fail("�±��Ӳݴ���������������·��С��һʧ���ǧ�źޡ�\n");
        return ::valid_leave(me, dir);
}
