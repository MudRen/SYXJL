inherit ROOM;

void create()
{
        set("short", "���Ϸ��ͱ�");
        set("long", @LONG
�������Ϸ��ͱڣ�ɽ�硰�������ش������ߣ��˵ز��˾�����
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
"down" : __DIR__"wulaoshan",
]));
        set("objects", ([
                __DIR__"npc/houzi2": 1,
                __DIR__"npc/xiaohou": 1,
]) );
        setup();
}
int valid_leave(object me, string dir)
{
        if (dir == "down" && this_player()->query("dex")<30)
                return notify_fail("�±��Ӳݴ���������������·��С��һʧ���ǧ�źޡ�\n");
        return ::valid_leave(me, dir);
}
void init()
{
        add_action("do_climb", "hua");
}
int do_climb(string arg)
{
        object me;
        me = this_player();

        if( !arg || arg=="" ) return 0;
        if( arg=="yeteng") {
                message("vision",
                me->name() + "˫��ץסҰ�٣���������ȥ��\n",
                environment(me), ({me}) );
                me->move(__DIR__"wulao");
                message("vision",
                me->name() + "������˳��Ұ������������\n",
                environment(me), me );
                return 1;
        }
}
