
inherit ROOM;

void create()
{
    set("short", "����ׯǰԺ");
    set("long", @LONG
�����ǹ���ׯ��ǰ�������軪�����������������˼��
����������۴��ׯ԰����һ�������ɴ������ǲ�������
ʮ�ֹ����ׯ�ڵ�·������һ������ͻ���ʧ������ֵĵ�·
�С�������һ��ͷ����Ǻÿ͵�����Ϊ���õĿ���׼���ġ�
LONG
);
    set("exits", ([
    "north" : __DIR__"zhangqian",
    "south" : __DIR__"gui-in",
    "west" : __DIR__"kefang",
]));

    set("objects", ([
                "/kungfu/class/taohua/luguanying" : 1,
                __DIR__"npc/puren3" : 2,
        ]));

    set("outdoors", "taohua");

    set("coor/x",10);
	set("coor/y",-40);
	set("coor/z",0);
	set("coor/x",10);
	set("coor/y",-40);
	set("coor/z",0);
	set("coor/x",10);
	set("coor/y",-40);
	set("coor/z",0);
	set("coor/x",10);
	set("coor/y",-40);
	set("coor/z",0);
	setup();
   
}

int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ((!myfam || myfam["family_name"] != "�һ���") && dir == "south" &&
		objectp(present("lu guanying", environment(me))))
	   return notify_fail("½��Ӣ��ס��˵���������Ǳ����صأ�����·���࣬�㲻���һ������ӣ�\n��ȥ���в��㣬��������\n");
		
        return ::valid_leave(me, dir);
}
